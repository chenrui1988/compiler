# make and run all the example programs for
# lex & yacc, Second Edition
CC = gcc -g -std=c99
LIBS = -ly -ll
LEX = lex
YACC = bison 
CFLAGS = -DYYDEBUG=1

uncool.pgm: uncool.l uncool.y symbol_table.h stack.h register.h uclib.h 
	${LEX} uncool.l
	${YACC} -d -y -v uncool.y
	${CC} ${CFLAGS} -o uncool.pgm y.tab.c lex.yy.c uccompiler.c register.c symbol_table.c stack.c ${LIBS} -lm 

