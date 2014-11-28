#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h" 
#include "symbol_table.h" 
#include "register.h" 
#include "uclib.h" 

symbol* build_table(char *sym_name);

void processClass(nodeType *node);
void processFunc(nodeType *node);
void processArg(nodeType *param, int *postion);
void processLocalVal(nodeType *param, int *postion);
void processIF(nodeType *node);
void processWihile(nodeType *node);
void processLet(nodeType *node);
void processCmpl(nodeType *node);
void processCall(nodeType *node);
void processCallArg(nodeType *node, int *point);

void transTestl(regiserEnum reg);
void transMovl(regiserEnum from, regiserEnum to);
void transCmpl(regiserEnum from, regiserEnum to);

static int lbl; 

struct sym_table *curr_st;
struct nodeTypeTag *node;
symbol *sym;
symbol *lastSym;
int charCount = 3;
int ifCount = 0;
int whileCount = 0;
int letCount = 0;

regiserEnum tmpRegister;

int ex(nodeType *p) {
	int lbl1, lbl2; 
	
	if (!p) return 0; 

	switch(p->type) {
		case intCons: 
			p->_register = getUnUseRegister();
			printf("\tmovl\t$%d,\t%s\n", p->intNode.value, getRegisterName(p->_register)); 
		 	break; 
		case boolCons:
		 	break; 
		case charCons:
			printf("\t.data\n");
			printf(".LC%d:\n", charCount); 
			printf("\t.string\t%s\n",  p->charNode.value);
			printf("\t.text\n");
			p->_register = getUnUseRegister();
			printf("\tmovl\t$.LC%d,\t%s\n", charCount, getRegisterName(p->_register));
		 	break; 
	 	case typeNode : 
	 		break;
	 	case idNode : 
	 		curr_st = get_cru_table();
	 		sym = build_table(p->idNode.name);
	 		switch(p->idNode.abs_type){
	 			case tINTARRAY:
	 			case tINT:
	 				printf("\t.data\n");
	 				printf("\t.align\t4\n");
 					printf("\t.type\t%s,\t@object\n", sym->rel_name);
					printf("\t.size\t%s,\t4\n", sym->rel_name);
	 				printf("%s:\n", sym->rel_name);
	 				if(p->idNode.op != NULL) 
	 				{
	 					printf("\t.long\t%d\n", p->idNode.op->intNode.value);
	 				} else 
	 				{
	 					printf("\t.long\t0\n");
	 				}
					printf("\t.align\t4\n");
					break;
	 			case tCHAR:
	 				printf("\t.data\n");
	 				printf(".LC%d:\n", charCount); 
					printf("\t.string\t%s\n",  p->idNode.op->charNode.value);
					printf("\t.align 4\n");

	 				printf("\t.type\t%s,\t@object\n", sym->rel_name);
					printf("\t.size\t%s,\t4\n", sym->rel_name);
					printf("%s:\n", sym->rel_name);
					printf("\t.long\t.LC%d\n", charCount++);
					break;
 				case tBOOLEAN:
	 				break;
 				case tVOID:
	 				break;
	 		}
	 		break;
 		case classNode : 
			processClass(p);
	 		break;
 		case funcNode : 
	 		processFunc(p);
	 		break;
	 	case oprNode: 
	 		switch(p->oprNode.oper) {
 			case WhileOpr: 
	 			processWihile(p);
	 			break; 
		 	case IfOpr: 
 				processIF(p);
				break; 
			case LetOpr: 
 				processLet(p);
				break; 
			case OutIntOpr: 
				switch(p->oprNode.op[0]->type) {
					case intCons: 
						p->_register = getUnUseRegister();
						printf("\tmovl\t$%d,\t%s\n", p->oprNode.op[0]->intNode.value, getRegisterName(p->_register));
						break;
					case oprNode:
						ex(p->oprNode.op[0]);
						p->_register = p->oprNode.op[0]->_register;
						break;
					default :
						break;
				}
				initRegister(edx, 12);
				initRegister(ecx, 8);
				printf("\tmovl\t%s,\t4(%%esp)\n", getRegisterName(p->_register));
				printf("\tmovl\t$.LC1,\t(%%esp)\n");
				printf("\tcall\tprintf\n");
				unLockRegister(p->oprNode.op[0]->_register);
				unLockRegister(p->_register);
				releaseRegister(edx);
				releaseRegister(ecx);
				break;
			case OutStrOpr:
				ex(p->oprNode.op[0]); 
				p->_register = p->oprNode.op[0]->_register;
				charCount++;
				initRegister(edx, 12);
				initRegister(ecx, 8);
				printf("\tmovl\t%s,\t4(%%esp)\n", getRegisterName(p->oprNode.op[0]->_register));
				printf("\tmovl\t$.LC2,\t(%%esp)\n");
				printf("\tcall\tprintf\n");
				unLockRegister(p->_register);
				releaseRegister(edx);
				releaseRegister(ecx);
				break;
			case InOpr: 
				initRegister(edx, 12);
				initRegister(ecx, 8);
				printf("\tmovl\t$_uncool_input,\t4(%%esp)\n");
				printf("\tmovl\t$.LC0,\t(%%esp)\n");
				printf("\tcall\tscanf\n");
				releaseRegister(edx);
				releaseRegister(ecx);
				p->_register = getUnUseRegister();
				printf("\tmovl\t%s,\t%s\n", "_uncool_input", getRegisterName(p->_register));
				break;
			case IdOpr: 
				if(p->oprNode.nops > 1) {
						ex(p->oprNode.op[1]);
						sym = find_sym(p->oprNode.op[0]->idNode.name);
						printf("\timull\t$4,\t%s\n", getRegisterName(p->oprNode.op[1]->_register));
						printf("\taddl\t%s,\t%s\n", sym->rel_name, getRegisterName(p->oprNode.op[1]->_register));
						printf("\tmovl\t(%s),\t%s\n", getRegisterName(p->oprNode.op[1]->_register), getRegisterName(p->oprNode.op[1]->_register));
						p->_register = p->oprNode.op[1]->_register;
				} else {
					sym = find_sym(p->oprNode.op[0]->idNode.name);
					p->_register = getUnUseRegister();
					printf("\tmovl\t%s,\t%s\n", sym->rel_name, getRegisterName(p->_register));
				}
				break;
			case NewOpr:
				ex(p->oprNode.op[0]);
				initRegister(edx, 12);
				initRegister(ecx, 8);
				printf("\timull\t$4,\t%s\n", getRegisterName(p->oprNode.op[0]->_register));
				printf("\tmovl\t%s,\t(%%esp)\n", getRegisterName(p->oprNode.op[0]->_register));
				printf("\tcall\tmalloc\n");
				releaseRegister(edx);
				releaseRegister(ecx);
				unLockRegister(p->oprNode.op[0]->_register);
				p->_register = getUnUseRegister();
				printf("\tmovl\t%%eax,\t%s\n", getRegisterName(p->_register));
				break;
			case FuncOpr:
				processCall(p);
				break;
			case AssignOpr: 
				if(p->oprNode.nops > 2) {
					ex(p->oprNode.op[2]);
					ex(p->oprNode.op[1]);
					sym = find_sym(p->oprNode.op[0]->idNode.name);
					printf("\timull\t$4,\t%s\n", getRegisterName(p->oprNode.op[1]->_register));
					printf("\taddl\t%s,\t%s\n", sym->rel_name, getRegisterName(p->oprNode.op[1]->_register));
					printf("\tmovl\t%s,\t(%s)\n", getRegisterName(p->oprNode.op[2]->_register), getRegisterName(p->oprNode.op[1]->_register));
					unLockRegister(p->oprNode.op[2]->_register);
				} else {
					switch (p->oprNode.op[1]->type) {
					case intCons: 
						ex(p->oprNode.op[1]);
						sym = find_sym(p->oprNode.op[0]->idNode.name);
						printf("\tmovl\t%s,\t%s\n", getRegisterName(p->oprNode.op[1]->_register), sym->rel_name);
						unLockRegister(p->oprNode.op[1]->_register);
					 	break; 
					case boolCons: 
					 	break; 
					case charCons: 
						sym = find_sym(p->oprNode.op[0]->idNode.name);
						printf("\tmovl\t%s,\t%s\n", p->oprNode.op[1]->charNode.value, sym->rel_name);
					 	break;
					case idNode:
						if(p->oprNode.nops > 2) {
							ex(p->oprNode.op[2]);
							ex(p->oprNode.op[1]);
							sym = find_sym(p->oprNode.op[0]->idNode.name);
							printf("\timull\t$4,\t%s\n", getRegisterName(p->oprNode.op[1]->_register));
							printf("\taddl\t%s,\t%s\n", sym->rel_name, getRegisterName(p->oprNode.op[1]->_register));
							printf("\tmovl\t%s,\t(%s)\n", getRegisterName(p->oprNode.op[2]->_register), getRegisterName(p->oprNode.op[1]->_register));
							unLockRegister(p->oprNode.op[2]->_register);
						} else {
							sym = find_sym(p->oprNode.op[0]->idNode.name);
							lastSym = find_sym(p->oprNode.op[1]->idNode.name);
							p->oprNode.op[1]->_register = getUnUseRegister();
							printf("\tmovl\t%s,\t%s\n", lastSym->rel_name, getRegisterName(p->oprNode.op[1]->_register));
							printf("\tmovl\t%s,\t%s\n", getRegisterName(p->oprNode.op[1]->_register), lastSym->rel_name);
							unLockRegister(p->oprNode.op[1]->_register);
						}
					 	break;
					 case oprNode:
						ex(p->oprNode.op[1]);
						sym = find_sym(p->oprNode.op[0]->idNode.name);
						printf("\tmovl\t%s,\t%s\n", getRegisterName(p->oprNode.op[1]->_register), sym->rel_name);
						unLockRegister(p->oprNode.op[1]->_register);
						break;
					default :
						break;
					}
				}
				break; 
			case UminusOpr: 
				ex(p->oprNode.op[0]); 
				printf("\tnegl\t%s\n", getRegisterName(p->oprNode.op[0]->_register));
				p->_register = p->oprNode.op[0]->_register;
				break; 
			case AddOpr: 
				ex(p->oprNode.op[0]); 
				ex(p->oprNode.op[1]);
				printf("\taddl\t%s,\t%s\n", getRegisterName(p->oprNode.op[0]->_register), getRegisterName(p->oprNode.op[1]->_register)); 
				p->_register = p->oprNode.op[1]->_register;
				unLockRegister(p->oprNode.op[0]->_register);
				break; 
			case SubOpr: 
				ex(p->oprNode.op[0]); 
				ex(p->oprNode.op[1]);
				printf("\tsubl\t%s,\t%s\n", getRegisterName(p->oprNode.op[1]->_register), getRegisterName(p->oprNode.op[0]->_register)); 
				p->_register = p->oprNode.op[0]->_register;
				unLockRegister(p->oprNode.op[1]->_register);
				break; 
			case DivOpr: 
				ex(p->oprNode.op[0]); 
				ex(p->oprNode.op[1]);
				printf("\tidiv\t%s,\t%s\n", getRegisterName(p->oprNode.op[0]->_register), getRegisterName(p->oprNode.op[1]->_register)); 
				p->_register = p->oprNode.op[1]->_register;
				unLockRegister(p->oprNode.op[0]->_register);
				break; 
			case ImuOpr: 
				ex(p->oprNode.op[0]); 
				ex(p->oprNode.op[1]);
				printf("\timull\t%s,\t%s\n", getRegisterName(p->oprNode.op[0]->_register), getRegisterName(p->oprNode.op[1]->_register)); 
				p->_register = p->oprNode.op[1]->_register;
				unLockRegister(p->oprNode.op[0]->_register);
				break; 
			case LtOpr:
				processCmpl(p); 
				break;
			case LeOpr: 
				processCmpl(p);
				break;
			case EqOpr: 
				processCmpl(p);
				break;
			case GtOpr: 
				processCmpl(p);
				break;
			case GeOpr: 
				processCmpl(p);
				break;
			case NeOpr: 
				processCmpl(p);
				break;
			default:
 				switch(p->oprNode.oper) {
				case ';': 
					for (int i = 0; i < p->oprNode.nops; ++i)
					{
						ex(p->oprNode.op[i]);
					}
					p->_register = p->oprNode.op[1]->_register;
					break;
				}
			}
 	}
 	return 0; 
}

/*build_table builds symbol table by inserting the token symbols into the list if not found on searching at first*/ 
symbol* build_table(char *sym_name)                  
{ 
    symbol * s;
    s = insert_sym(sym_name);
    return s;
}

void processArg(nodeType *param, int *postion) {
	if(param != NULL) {
		if(param->type == idNode) {
			symbol *argSym = build_table(param->idNode.name);
			char *name = (char *)malloc(80);
			sprintf(name, "%d(%%ebp)", *postion*4);
			(*postion)++;
			argSym->rel_name = name;
		} else {
			if(param->oprNode.nops>0) 
			{
				for (int i = 0; i < param->oprNode.nops; i++)
				{
					processArg(param->oprNode.op[i], postion);
				}
			}
		}
	}
}

void processLocalVal(nodeType *param, int *postion) {
	if(param != NULL) {
		if(param->type == idNode) {
			symbol *argSym = build_table(param->idNode.name);
			char *name = (char *)malloc(80);
			sprintf(name, "%d(%%ebp)", *postion*4);
			(*postion)--;
			argSym->rel_name = name;
		} else {
			if(param->oprNode.nops>0) 
			{
				for (int i = 0; i < param->oprNode.nops; i++)
				{
					processLocalVal(param->oprNode.op[i], postion);
				}
			}
		}
	}
}


void processClass(nodeType *node)
{
	ct_sym_table(node->classNode.name);
	//sym = build_table(p->classNode.name);
	printf("\t.section\t.rodata.str1.1,\"aMS\",@progbits,1\n");
	printf("\t.data\n");
	printf(".LC0:\n");
	printf("\t.string \"%%d\"\n");
	printf(".LC1:\n");
	printf("\t.string \"%%d \"\n");
	printf(".LC2:\n");
	printf("\t.string \"%%s \"\n");
	printf("\t.align\t4\n");
	printf("\t.type\t%s,\t@object\n", "_uncool_input");
	printf("\t.size\t%s,\t4\n", "_uncool_input");
	printf("_uncool_input:\n");
	printf("\t.long 0\n");
	//printf("\t.text\n");
	ex(node->classNode.op);
	printf("\t.section\t.note.GNU-stack,\"\",@progbits\n");	
	pop_sym_table();
}

void processFunc(nodeType *node) 
{
	sym = build_table(node->funcNode.name);
	printf("\t.text\n");
	printf("\t.globl\t%s\n", sym->rel_name);
	printf("\t.type\t%s,\t@function\n", sym->rel_name);
	curr_st = ct_sym_table(node->funcNode.name);
	printf("%s:\n", sym->rel_name);
	if(strcmp(node->funcNode.name, "main") == 0) {
		printf("\tleal\t4(%%esp),\t%%ecx\n");
		printf("\tandl\t$-16,\t%%esp\n");
		printf("\tpushl\t-4(%%ecx)\n");
	}
	
	printf("\tpushl\t%%ebp\n");
	printf("\tmovl\t%%esp,\t%%ebp\n");
	if(strcmp(node->funcNode.name, "main") == 0) {
		printf("\tpushl\t%%ecx\n");
	}
	printf("\tsubl\t$128,\t%%esp\n");
	initRegister(ebx, 16);
	initRegister(esi, 20);
	initRegister(edi, 24); 
	//ex(node->funcNode.returnType);
	int point = 2;
	processArg(node->funcNode.param, &point);
	ex(node->funcNode.op);
	if(strcmp(node->funcNode.name, "main") != 0)
	{
		transMovl(node->funcNode.op->_register, eax);
	}
	releaseRegister(ebx);
	releaseRegister(esi);
	releaseRegister(edi);
	printf("\taddl\t$128,\t%%esp\n");
	if(strcmp(node->funcNode.name, "main") == 0) {
		printf("\tpopl\t%%ecx\n");
	}
	printf("\tpopl\t%%ebp\n");
	if(strcmp(node->funcNode.name, "main") == 0) {
		printf("\tleal\t-4(%%ecx),\t%%esp\n");
	}
	pop_sym_table();
	curr_st = get_cru_table();
	sym = curr_st->head;
	printf("\tret\n");
	printf("\t.size\t%s,\t.-%s\n", sym->rel_name, sym->rel_name);
}

void processIF(nodeType *node)
{
	ex(node->oprNode.op[0]); 

	node->_register = getUnUseRegister();
	transTestl(node->oprNode.op[0]->_register);
	ifCount = ifCount + 2;
	printf("\tje\tIF%d\n", ifCount-2);
	ex(node->oprNode.op[1]);
	transMovl(node->oprNode.op[1]->_register, node->_register);
	unLockRegister(node->oprNode.op[1]->_register);
	printf("\tjmp\tIF%d\n", ifCount-1);
	
	printf("IF%d:\n", ifCount-2);
	ex(node->oprNode.op[2]);
	transMovl(node->oprNode.op[2]->_register, node->_register);
	printf("IF%d:\n", ifCount-1);
}

void processWihile(nodeType *node) 
{
	whileCount = whileCount + 2;
	printf("WH%d:\n", whileCount-2);
	ex(node->oprNode.op[0]); 
	transTestl(node->oprNode.op[0]->_register);
	printf("\tje\tWH%d\n", whileCount-1);
	
	ex(node->oprNode.op[1]);
	printf("\tjmp\tWH%d\n", whileCount-2);

	printf("WH%d:\n", whileCount-1);
}

void processLet(nodeType *node)
{
	char *name = (char *)malloc(80);
	sprintf(name, "LET%d", letCount++);
	curr_st = ct_sym_table(name);
	int point = -8;
	processLocalVal(node->oprNode.op[0], &point);
	ex(node->oprNode.op[1]);
	node->_register = node->oprNode.op[1]->_register;
	pop_sym_table();
	curr_st = get_cru_table();
}

void processCmpl(nodeType *node) 
{
	ex(node->oprNode.op[0]); 
	ex(node->oprNode.op[1]);
	transCmpl(node->oprNode.op[1]->_register, node->oprNode.op[0]->_register);
	printf("\tsetl\t%%al\n");
	printf("\tmovzbl\t%%al,\t%%eax\n");
	node->_register = getUnUseRegister();
	printf("\tmovl\t%%eax,\t%s\n", getRegisterName(node->_register));
}

void processCall(nodeType *node) 
{
	if(node->oprNode.nops > 0) {
		int point = 0;
		processCallArg(node->oprNode.op[1], &point);
	}
	initRegister(edx, 12);
	initRegister(ecx, 8);
	sym = find_sym(node->oprNode.op[0]->idNode.name);
	printf("\tcall\t%s\n", sym->rel_name);
	releaseRegister(edx);
	releaseRegister(ecx);
	unLockRegister(node->oprNode._register);
	node->_register = getUnUseRegister();
	printf("\tmovl\t%%eax,\t%s\n", getRegisterName(node->_register));
} 

void processCallArg(nodeType *node, int *point) {
	if(node != NULL) {
		switch(node->type) {
			case idNode:
				printf("\tmovl\t%s,\t%d(%%esp)\n", lastSym->rel_name, *point*4);
				(*point)++;
				break;
			case charCons:
				printf("\t.data\n");
				printf(".LC%d:\n", charCount); 
				printf("\t.string\t%s\n",  node->charNode.value);
				printf("\t.text\n");
				printf("\tmovl\t$.LC%d,\t%d(%%esp)\n", charCount, *point*4);
				(*point)++;
				charCount++;
				break;
			case intCons:
				printf("\tmovl\t$%d,\t%d(%%esp)\n", node->intNode.value, *point*4);
				(*point)++;
				break;
			case oprNode : 
				switch(node->oprNode.oper) {
				case IdOpr: 
					lastSym = find_sym(node->oprNode.op[0]->idNode.name);
					node->_register = getUnUseRegister();
					printf("\tmovl\t%s,\t%s\n", lastSym->rel_name, getRegisterName(node->_register));
					printf("\tmovl\t%s,\t%d(%%esp)\n", getRegisterName(node->_register), *point*4);
					(*point)++;
					unLockRegister(node->_register);
					break;
				case UminusOpr: 
				case AddOpr: 
				case SubOpr: 
				case DivOpr: 
				case ImuOpr: 
					ex(node);
					printf("\tmovl\t%s,\t%d(%%esp)\n", getRegisterName(node->_register), *point*4);
					(*point)++;
					unLockRegister(node->_register);
					break;
				default:
					switch(node->oprNode.oper) {
						case ',': 
							for (int i = 0; i < node->oprNode.nops; ++i)
							{
								processCallArg(node->oprNode.op[i], point);
							}
							break;
					}
				}
		}
	}
}

void transTestl(regiserEnum reg) {
	printf("\ttestl\t%s,\t%s\n", getRegisterName(reg), getRegisterName(reg));
	unLockRegister(reg);
}

void transMovl(regiserEnum from, regiserEnum to) {
	printf("\tmovl\t%s,\t%s\n", getRegisterName(from), getRegisterName(to));
	unLockRegister(from);
}

void transCmpl(regiserEnum from, regiserEnum to) {
	printf("\tcmpl\t%s,\t%s\n", getRegisterName(from), getRegisterName(to)); 
	unLockRegister(from);
	unLockRegister(to);
}