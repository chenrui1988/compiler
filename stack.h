#ifndef stack_h_included
#define stack_h_included

#include "uclib.h"

void push(sym_table *ptr);
struct sym_table* pop();
struct sym_table* top();
void clear();


#endif