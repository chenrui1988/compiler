#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "uclib.h"
#include "stack.h"
#include "symbol_table.h"

extern int main();
struct sym_table *symarray[100];

int header = 0;
void push(struct sym_table *ptr)
{
	if(header == 100)
	{
		printf("stack full cannot insert\n");
		exit(0);
	} 
	else
	{
		symarray[header] = ptr;
		header = header + 1;
	}
}

struct sym_table* pop()
{
	if (header > 0)
	{
		sym_table* ptr;
		ptr = (sym_table*)malloc(sizeof(sym_table));
		ptr = symarray[header-1];
		header = header - 1;
		return ptr;
	}
	else 
	{
		printf("stack empty cannot pop");
		return NULL;
	}
}

struct sym_table* top() 
{
	if(header == 0) {
		return NULL;
	}
	sym_table* ptr;
	ptr = (sym_table*)malloc(sizeof(sym_table));
	ptr = symarray[header-1];
	return ptr;
}

void clear() 
{
	for(int i = 0; i < header; i++) 
	{
		free(symarray[header]);
	}
}

