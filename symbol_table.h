#ifndef symbol_table_h_included
#define symbol_table_h_included

typedef enum 
{
	tINT, tCHAR, tBOOLEAN, tVOID, tINTARRAY
} typeEnum;


struct sym_table
{
	char *name;
	struct sym_table *parent;		// pointer to the parent symbol table
	struct symbol *head;			// pointer to the head sym of the curr symbol table
	int depth;						// function calling depth
};

typedef struct sym_table sym_table;

struct symbol
{
	char *name;						//token value field to be made
	char *rel_name;
	typeEnum nd_type; 
	struct symbol *next;
};
typedef struct symbol symbol;

sym_table* ct_sym_table();
sym_table * get_cru_table();
void pop_sym_table();
symbol * insert_sym(char *sym_name);
symbol * find_sym(char *sym_name);

#endif
