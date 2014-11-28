%{
#include "y.tab.h"
int yylex();
int lineno = 1;
%}

ws        		[\r\t\f\v ]+
comment   		(--)[^\n]*
string   		\"[^\"\n]*\"
int  	  		[0-9]+
id        		[a-zA-Z][a-zA-Z0-9_]*
assigin  		\<\-
nl        		\n


%%
{ws}      		;
{comment} 		;
"class"     	{
					return CLASS_T; 
				}
"Main" 			{ 
					yylval.charVal=strdup(yytext);
					return TYPE; 
				}
"Int"     		{ 
					
					return INT_T; 
				}
"Bool"      	{ return BOOL_T; }
"String"      	{ return STRING_T; }
{assigin}		{ return ASSIGN; }
{int}			{ 
					yylval.intVal = atoi(yytext);
					return INT_CONST;
				}
{string}		{ 
					yylval.charVal=strdup(yytext);
					return STRING_CONST; 
				}
"true"		 	{ return TRUE_T; }
"false"			{ return FALSE_T; }
"new" 			{ return NEW_T; }

"if" 			{ return IF_T; } 
"then" 			{ return THEN_T; } 
"else" 			{ return ELSE_T; } 
"fi" 			{ return FI_T; }

"while" 		{ return WHILE_T; } 
"loop"			{ return LOOP_T; }
"pool"			{ return POOL_T; }

"let" 			{ return LET_T; } 
"in" 			{ return IN_T; } 
"tel" 			{ return TEL_T; } 

"in_int" 		{ return IN_INT; }
"out_int" 		{ return OUT_INT; }
"out_string" 	{ return OUT_STRING; }

"not" 			{ return NOT_T; }

"<"				{ return LT; }
"<="			{ return LE; }
">"				{ return GT; }
">="			{ return GE; }
"=="			{ return EQ; }
"!="			{ return NE; }

{id}			{ 
					yylval.charVal=strdup(yytext);
					return ID; 
				}
{nl}      		{ lineno++; }
.         		{ return yytext[0]; }
%%