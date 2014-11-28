%{
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>  
#include "symbol_table.h" 
#include "stack.h" 
#include "uclib.h" 


extern FILE *yyin,*yyout;
extern int lineno;
extern char *yytext;

/* prototypes */
nodeType *intCon(int value);
nodeType *boolCon(int value);
nodeType *charCon(char *value);
nodeType *type(typeEnum _type);
nodeType *id(char *name, nodeType *node, nodeType *intValue);
nodeType *opr(int oper, int nops, ...);
nodeType *func(char *name, nodeType *type, nodeType *param, nodeType *subNode);
nodeType *clazz(char *name, nodeType *node);

symbol* build_table(sym_table *curr_st, char *sym_name);
void freeNode(nodeType *p);
int ex(nodeType *p);

int yylex(void);
int yyparse();
void yyerror(char *s);

%}


%union 
{
    int intVal;                         /* integer value */
    char *charVal;                      /* string value */
    struct symbol* st_ptr;              
    struct nodeTypeTag *nPtr;           /* node pointer */
};


%token CLASS_T TYPE NEW_T INT_T BOOL_T STRING_T ASSIGN
%token NOT_T IF_T THEN_T ELSE_T FI_T WHILE_T LOOP_T POOL_T LET_T IN_T TEL_T
%token IN_INT OUT_INT OUT_STRING
%token LT LE EQ GT GE NE

%token <intVal> INT_CONST 
%token <charVal> STRING_CONST TYPE ID
%token <intVal> TRUE_T FALSE_T

%nonassoc IF_T
%nonassoc ELSE_T
%nonassoc THEN_T
%left LT LE EQ GT GE NE '>' '<' 
%left '+' '-' 
%left '*' '/' 
%left '('
%right UMINUS

%type <nPtr> class feature_list feature formal_list typename
%type <nPtr> simple_constant formal expr actual_list  expr_list


%%
class           :       CLASS_T TYPE '{' feature_list '}'                       { 
                                                                                    $$ = clazz($2, $4); 
                                                                                    ex($$); 
                                                                                    freeNode($$);  
                                                                                    exit(0); 
                                                                                }
                ;

feature_list    :       feature_list  feature ';'                               { $$ = opr(';', 2, $1, $2); }         
                |                                                               {}
                ;

feature         :       ID '(' formal_list ')' ':' typename '{' expr_list  '}'  { $$ = func($1, $6, $3, $8); }               
                |       ID '(' ')' ':' typename '{' expr_list  '}'              { $$ = func($1, $5, NULL, $7); }
                |       ID ':' typename                                         { $$ = id($1, $3, NULL); } 
                |       ID ':' typename ASSIGN simple_constant                  { $$ = id($1, $3, $5); } 
                |       ID ':' STRING_T ASSIGN STRING_CONST                     { $$ = id($1, type(tCHAR), charCon($5)); }  
                |       ID ':' INT_T '[' ']'                                    { $$ = id($1, type(tINTARRAY), NULL); } 
                ;

typename        :       INT_T                                           { $$ = type(tINT); }   
                |       BOOL_T                                          { $$ = type(tBOOLEAN); }  
                |       STRING_T                                        { $$ = type(tCHAR); }  
                ;

simple_constant :       INT_CONST                                       { $$ = intCon($1); }                           
                |       TRUE_T                                          { $$ = boolCon($1); }    
                |       FALSE_T                                         { $$ = boolCon($1); }    
                ;

formal_list     :       formal_list ',' formal                          { $$ = opr(',', 2, $1, $3); }    
                |       formal                                          { $$ = $1; }
                ;       

formal          :       ID ':' typename                                 { $$ = id($1, $3, NULL); } 
                |       ID ':' INT_T '[' ']'                            { $$ = id($1, type(tINTARRAY), NULL); }
                ;

expr            :       ID ASSIGN  expr                                 { $$ = opr(AssignOpr, 2, id($1, NULL, NULL), $3); }
                |       ID '[' expr ']'  ASSIGN  expr                   { $$ = opr(AssignOpr, 3, id($1, NULL, NULL), $3, $6); }
                |       ID '(' ')'                                      { $$ = opr(FuncOpr, 1, id($1, NULL, NULL)); }
                |       IN_INT '(' ')'                                  { $$ = opr(InOpr, 0); }
                |       OUT_STRING '(' expr ')'                         { $$ = opr(OutStrOpr, 1, $3); }
                |       OUT_INT '(' expr ')'                            { $$ = opr(OutIntOpr, 1, $3); }
                |       ID '(' actual_list ')'                          { $$ = opr(FuncOpr, 2, id($1, NULL, NULL), $3); }
                |       ID                                              { $$ = opr(IdOpr, 1, id($1, NULL, NULL)); }
                |       ID '[' expr ']'                                 { $$ = opr(IdOpr, 2, id($1, NULL, NULL), $3); }
                |       IF_T expr THEN_T expr ELSE_T expr FI_T          { $$ = opr(IfOpr, 3, $2, $4, $6); }
                |       WHILE_T expr  LOOP_T expr POOL_T                { $$ = opr(WhileOpr, 2, $2, $4); }
                |       '{'    expr_list '}'                            { $$ = $2; }
                |       LET_T  formal_list    IN_T expr TEL_T           { $$ = opr(LetOpr, 2, $2, $4); }
                |       NEW_T INT_T '[' expr ']'                        { $$ = opr(NewOpr, 1, $4); }  
                |       expr  '+' expr                                  { $$ = opr(AddOpr, 2, $1, $3); }
                |       expr  '-' expr                                  { $$ = opr(SubOpr, 2, $1, $3); }
                |       expr  '*' expr                                  { $$ = opr(ImuOpr, 2, $1, $3); }
                |       expr  '/' expr                                  { $$ = opr(DivOpr, 2, $1, $3); }
                |       '~' expr %prec UMINUS                           { $$ = opr(UminusOpr, 1, $2); }
                |       NOT_T expr                                      { $$ = opr(NotOpr, 1, $2); } 
                |       expr LT expr                                    { $$ = opr(LtOpr, 2, $1, $3); } 
                |       expr LE expr                                    { $$ = opr(LeOpr, 2, $1, $3); } 
                |       expr EQ expr                                    { $$ = opr(EqOpr, 2, $1, $3); } 
                |       expr GT expr                                    { $$ = opr(GtOpr, 2, $1, $3); } 
                |       expr GE expr                                    { $$ = opr(GeOpr, 2, $1, $3); } 
                |       expr NE expr                                    { $$ = opr(NeOpr, 2, $1, $3); }  
                |       '(' expr ')'                                    { $$ = $2; }  
                |       TRUE_T                                          { $$ = boolCon($1); }  
                |       FALSE_T                                         { $$ = boolCon($1); }  
                |       INT_CONST                                       { $$ = intCon($1); }  
                |       STRING_CONST                                    { $$ = charCon($1); } 
                ;

actual_list     :       actual_list ',' expr                            { $$ = opr(',', 2, $1, $3); }
                |       expr                                            { $$ = $1; } 
                ;

expr_list       :       expr_list  ';' expr                             { $$ = opr(';', 2, $1, $3); }     
                |       expr                                            { $$ = $1; }    
                ;
%%



#define SIZEOF_NODETYPE 1000

nodeType *intCon(int value) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(intNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = intCons;
    p->intNode.value = value;

    return p;
}

nodeType *charCon(char *value) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(charNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = charCons;
    p->charNode.value = strdup(value);;

    return p;
}

nodeType *boolCon(int value) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(boolNodeType) + sizeof(boolNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = boolCons;
    p->boolNode.value = value;

    return p;
}

nodeType *type(typeEnum _type) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(typeNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeNode;
    p->typeNode.abs_type = _type;

    return p;
}

nodeType *id(char *name, nodeType *node, nodeType *intValue) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(idNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = idNode;
    if(node != NULL) {
         p->idNode.abs_type = node->typeNode.abs_type;
    }
    p->idNode.name = name;
    p->idNode.op = intValue;
    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    size_t nodeSize;
    int i;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(oprNodeType) + 10 * sizeof(nodeType*);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = oprNode;
    p->oprNode.oper = oper;
    p->oprNode.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++) {
        p->oprNode.op[i] = va_arg(ap, nodeType*);
    }
    va_end(ap);
    return p;
}

nodeType *func(char *name, nodeType *type, nodeType *param, nodeType *subNode) {
    nodeType *p;
    size_t nodeSize;
    int i;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(funcNodeType) + 3 * sizeof(nodeType*);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = funcNode;
    p->funcNode.name = name;
    p->funcNode.returnType = type;
    p->funcNode.param = param;
    p->funcNode.op = subNode;
   
    return p;
}

nodeType *clazz(char *name, nodeType *node) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(classNodeType) + sizeof(nodeType*);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = classNode;
    p->classNode.name = name;
    p->classNode.op = node;

    return p;
}

void freeNode(nodeType *p) 
{
    int i;

    if (!p) return;
    if (p->type == oprNode) 
    {
        for (i = 0; i < p->oprNode.nops; i++)
            freeNode(p->oprNode.op[i]);
    }
    free (p);
}

int main(int argc, char **argv)
{
        FILE *fp ;
        ++argv;
        --argc;
        if(argc > 0)
                yyin = fopen(argv[0], "r");
        else
                yyin = stdin;
        yyout  = stdout;
        //yyout  = fopen(strcat(filiname， ".s"), "w");
        yyparse();
        return 0;
}

void yyerror(char *s) 
{
    fprintf(stdout, "%s\n", s);
}
