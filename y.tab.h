/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CLASS_T = 258,
     TYPE = 259,
     NEW_T = 260,
     INT_T = 261,
     BOOL_T = 262,
     STRING_T = 263,
     ASSIGN = 264,
     NOT_T = 265,
     IF_T = 266,
     THEN_T = 267,
     ELSE_T = 268,
     FI_T = 269,
     WHILE_T = 270,
     LOOP_T = 271,
     POOL_T = 272,
     LET_T = 273,
     IN_T = 274,
     TEL_T = 275,
     IN_INT = 276,
     OUT_INT = 277,
     OUT_STRING = 278,
     LT = 279,
     LE = 280,
     EQ = 281,
     GT = 282,
     GE = 283,
     NE = 284,
     INT_CONST = 285,
     STRING_CONST = 286,
     ID = 287,
     TRUE_T = 288,
     FALSE_T = 289,
     UMINUS = 290
   };
#endif
/* Tokens.  */
#define CLASS_T 258
#define TYPE 259
#define NEW_T 260
#define INT_T 261
#define BOOL_T 262
#define STRING_T 263
#define ASSIGN 264
#define NOT_T 265
#define IF_T 266
#define THEN_T 267
#define ELSE_T 268
#define FI_T 269
#define WHILE_T 270
#define LOOP_T 271
#define POOL_T 272
#define LET_T 273
#define IN_T 274
#define TEL_T 275
#define IN_INT 276
#define OUT_INT 277
#define OUT_STRING 278
#define LT 279
#define LE 280
#define EQ 281
#define GT 282
#define GE 283
#define NE 284
#define INT_CONST 285
#define STRING_CONST 286
#define ID 287
#define TRUE_T 288
#define FALSE_T 289
#define UMINUS 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 37 "uncool.y"
{
    int intVal;                         /* integer value */
    char *charVal;                      /* string value */
    struct symbol* st_ptr;              
    struct nodeTypeTag *nPtr;           /* node pointer */
}
/* Line 1529 of yacc.c.  */
#line 126 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

