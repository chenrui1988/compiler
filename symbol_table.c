#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h" 
#include "stack.h" 

extern int main();

sym_table * ct_sym_table(char *name)
{
	sym_table *new_st;
	new_st = (sym_table *)malloc(sizeof(sym_table));

	sym_table *cru_st = top();
	new_st->name = strdup(name);
	new_st->parent = cru_st;
	new_st->head = NULL;
	
	push(new_st);
	return new_st;
}

sym_table * get_cru_table() 
{
	sym_table *cru_st;
	cru_st = (sym_table *)malloc(sizeof(sym_table));
	cru_st = top();
	return cru_st;
}

void pop_sym_table()
{
	pop();
}

symbol * insert_sym(char *sym_name)
{
	sym_table *cru_st = top();
	
	symbol * ptr;
	ptr = (symbol*)malloc(sizeof(symbol));

	char *name = (char *)malloc(80);
	if(strcmp(sym_name, "main") == 0) 
	{	
		strcat(name, sym_name);
	} 
	else
	{
		strcat(name, "_");
		strcat(name, cru_st->name);
		strcat(name, "_");
		strcat(name, sym_name);
	}
	ptr->name = sym_name;
	ptr->rel_name = name;
	ptr->next = cru_st->head;
	cru_st->head = ptr;
	return ptr;
}

symbol * find_sym(char *sym_name)
{
	sym_table *cru_st = top();
	symbol *ptr;
	while(cru_st != NULL) 
	{
		ptr = cru_st->head;
		while(ptr!=NULL)
		{
			if(!strcmp(ptr->name, sym_name)) 
			{
				return ptr;
			}
			ptr= ptr->next;
		}
		cru_st=cru_st->parent;
	}
	return NULL;
}