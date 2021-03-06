/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "uncool.y"

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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 37 "uncool.y"
{
    int intVal;                         /* integer value */
    char *charVal;                      /* string value */
    struct symbol* st_ptr;              
    struct nodeTypeTag *nPtr;           /* node pointer */
}
/* Line 193 of yacc.c.  */
#line 207 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 220 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   307

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNRULES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    46,    39,    37,    50,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    45,
      36,     2,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,    51,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    13,    14,    24,    33,    37,    43,
      49,    55,    57,    59,    61,    63,    65,    67,    71,    73,
      77,    83,    87,    94,    98,   102,   107,   112,   117,   119,
     124,   132,   138,   142,   148,   154,   158,   162,   166,   170,
     173,   176,   180,   184,   188,   192,   196,   200,   204,   206,
     208,   210,   212,   216,   218,   222
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,     3,     4,    43,    54,    44,    -1,    54,
      55,    45,    -1,    -1,    32,    41,    58,    46,    47,    56,
      43,    62,    44,    -1,    32,    41,    46,    47,    56,    43,
      62,    44,    -1,    32,    47,    56,    -1,    32,    47,    56,
       9,    57,    -1,    32,    47,     8,     9,    31,    -1,    32,
      47,     6,    48,    49,    -1,     6,    -1,     7,    -1,     8,
      -1,    30,    -1,    33,    -1,    34,    -1,    58,    50,    59,
      -1,    59,    -1,    32,    47,    56,    -1,    32,    47,     6,
      48,    49,    -1,    32,     9,    60,    -1,    32,    48,    60,
      49,     9,    60,    -1,    32,    41,    46,    -1,    21,    41,
      46,    -1,    23,    41,    60,    46,    -1,    22,    41,    60,
      46,    -1,    32,    41,    61,    46,    -1,    32,    -1,    32,
      48,    60,    49,    -1,    11,    60,    12,    60,    13,    60,
      14,    -1,    15,    60,    16,    60,    17,    -1,    43,    62,
      44,    -1,    18,    58,    19,    60,    20,    -1,     5,     6,
      48,    60,    49,    -1,    60,    37,    60,    -1,    60,    38,
      60,    -1,    60,    39,    60,    -1,    60,    40,    60,    -1,
      51,    60,    -1,    10,    60,    -1,    60,    24,    60,    -1,
      60,    25,    60,    -1,    60,    26,    60,    -1,    60,    27,
      60,    -1,    60,    28,    60,    -1,    60,    29,    60,    -1,
      41,    60,    46,    -1,    33,    -1,    34,    -1,    30,    -1,
      31,    -1,    61,    50,    60,    -1,    60,    -1,    62,    45,
      60,    -1,    60,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    68,    68,    76,    77,    80,    81,    82,    83,    84,
      85,    88,    89,    90,    93,    94,    95,    98,    99,   102,
     103,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   139,   140,   143,   144
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS_T", "TYPE", "NEW_T", "INT_T",
  "BOOL_T", "STRING_T", "ASSIGN", "NOT_T", "IF_T", "THEN_T", "ELSE_T",
  "FI_T", "WHILE_T", "LOOP_T", "POOL_T", "LET_T", "IN_T", "TEL_T",
  "IN_INT", "OUT_INT", "OUT_STRING", "LT", "LE", "EQ", "GT", "GE", "NE",
  "INT_CONST", "STRING_CONST", "ID", "TRUE_T", "FALSE_T", "'>'", "'<'",
  "'+'", "'-'", "'*'", "'/'", "'('", "UMINUS", "'{'", "'}'", "';'", "')'",
  "':'", "'['", "']'", "','", "'~'", "$accept", "class", "feature_list",
  "feature", "typename", "simple_constant", "formal_list", "formal",
  "expr", "actual_list", "expr_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    62,    60,    43,    45,    42,
      47,    40,   290,   123,   125,    59,    41,    58,    91,    93,
      44,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    57,    57,    57,    58,    58,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     0,     9,     8,     3,     5,     5,
       5,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       5,     3,     6,     3,     3,     4,     4,     4,     1,     4,
       7,     5,     3,     5,     5,     3,     3,     3,     3,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     3,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,     2,     0,
       0,     0,     3,     0,     0,     0,    18,    11,    12,    13,
       7,     0,     0,     0,     0,     0,     0,     0,    11,    13,
      19,    11,     0,     0,    17,    10,     9,    14,    15,    16,
       8,     0,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    28,    48,    49,     0,     0,
       0,    55,     0,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,    24,     0,     0,    21,    23,
      53,     0,     0,    47,    32,    41,    42,    43,    44,    45,
      46,    35,    36,    37,    38,    54,     5,     0,     0,     0,
       0,    26,    25,    27,     0,    29,    34,     0,    31,    33,
      52,     0,     0,    22,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     6,     9,    20,    40,    15,    16,    61,   101,
      62
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -47
static const yytype_int16 yypact[] =
{
       8,    19,    51,   -12,   -47,   -47,   -29,    33,   -47,    58,
     -16,   124,   -47,    13,    28,    15,   -47,    48,   -47,    99,
     100,   133,   137,    64,    83,    65,    92,    56,    76,   -47,
     -47,   -47,    90,   137,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,    85,    95,    94,   -47,   153,    95,    95,    95,    83,
     130,   131,   132,   -47,   -47,     1,   -47,   -47,    95,    95,
      95,   267,   -23,    95,   117,   267,   123,   175,    -6,   140,
      95,    95,    95,    61,    95,   198,    18,   -47,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,   -47,    95,
      43,    95,    95,    95,    95,   -47,   221,   244,   267,   -47,
     267,    27,   -20,   -47,   -47,    82,    82,    82,    82,    82,
      82,    59,    59,   -47,   -47,   267,   -47,   156,   129,   192,
      30,   -47,   -47,   -47,    95,   161,   -47,    95,   -47,   -47,
     267,    95,   150,   267,   -47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,   -47,   -47,   -47,    31,   -47,   143,   173,   -46,   -47,
      38
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      65,    66,    67,     7,    78,    79,    80,    81,    82,    83,
      72,     1,    75,    94,    77,     8,    13,    84,    85,    86,
      87,    88,    89,     3,    96,    97,    98,   100,   102,   125,
      14,     5,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    73,   115,    24,   117,   118,   119,   120,    74,
     129,     4,    30,    32,    78,    79,    80,    81,    82,    83,
      21,    23,   104,    89,    43,    24,    45,    84,    85,    86,
      87,    46,    47,   123,    10,    22,    48,   124,   130,    49,
      11,   132,    50,    51,    52,   133,    37,   116,    89,    38,
      39,    53,    54,    55,    56,    57,    25,    76,    86,    87,
      45,    90,    58,    12,    59,    46,    47,    99,    26,    27,
      48,    33,    60,    49,    35,    13,    50,    51,    52,    84,
      85,    86,    87,    36,    41,    53,    54,    55,    56,    57,
      17,    18,    19,    42,    44,    92,    58,    63,    59,    28,
      18,    29,   127,    31,    18,    29,    60,    78,    79,    80,
      81,    82,    83,    78,    79,    80,    81,    82,    83,    64,
      84,    85,    86,    87,   134,    91,    84,    85,    86,    87,
     131,    69,    70,    71,    78,    79,    80,    81,    82,    83,
      78,    79,    80,    81,    82,    83,    95,    84,    85,    86,
      87,    93,    68,    84,    85,    86,    87,    34,     0,    78,
      79,    80,    81,    82,    83,   126,     0,     0,     0,   128,
       0,     0,    84,    85,    86,    87,    78,    79,    80,    81,
      82,    83,    78,    79,    80,    81,    82,    83,     0,    84,
      85,    86,    87,     0,     0,    84,    85,    86,    87,     0,
       0,     0,     0,     0,   103,    78,    79,    80,    81,    82,
      83,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,    87,     0,     0,     0,     0,     0,   121,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
       0,    84,    85,    86,    87,     0,     0,     0,     0,     0,
     122,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,     0,     0,     0,    84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
      46,    47,    48,    32,    24,    25,    26,    27,    28,    29,
       9,     3,    58,    19,    60,    44,    32,    37,    38,    39,
      40,    44,    45,     4,    70,    71,    72,    73,    74,    49,
      46,    43,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    41,    89,    50,    91,    92,    93,    94,    48,
      20,     0,    21,    22,    24,    25,    26,    27,    28,    29,
      47,    46,    44,    45,    33,    50,     5,    37,    38,    39,
      40,    10,    11,    46,    41,    47,    15,    50,   124,    18,
      47,   127,    21,    22,    23,   131,    30,    44,    45,    33,
      34,    30,    31,    32,    33,    34,    48,    59,    39,    40,
       5,    63,    41,    45,    43,    10,    11,    46,     9,     9,
      15,    47,    51,    18,    49,    32,    21,    22,    23,    37,
      38,    39,    40,    31,    48,    30,    31,    32,    33,    34,
       6,     7,     8,    43,    49,    12,    41,    43,    43,     6,
       7,     8,    13,     6,     7,     8,    51,    24,    25,    26,
      27,    28,    29,    24,    25,    26,    27,    28,    29,     6,
      37,    38,    39,    40,    14,    48,    37,    38,    39,    40,
       9,    41,    41,    41,    24,    25,    26,    27,    28,    29,
      24,    25,    26,    27,    28,    29,    46,    37,    38,    39,
      40,    16,    49,    37,    38,    39,    40,    24,    -1,    24,
      25,    26,    27,    28,    29,    49,    -1,    -1,    -1,    17,
      -1,    -1,    37,    38,    39,    40,    24,    25,    26,    27,
      28,    29,    24,    25,    26,    27,    28,    29,    -1,    37,
      38,    39,    40,    -1,    -1,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    46,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    46,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      46,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    53,     4,     0,    43,    54,    32,    44,    55,
      41,    47,    45,    32,    46,    58,    59,     6,     7,     8,
      56,    47,    47,    46,    50,    48,     9,     9,     6,     8,
      56,     6,    56,    47,    59,    49,    31,    30,    33,    34,
      57,    48,    43,    56,    49,     5,    10,    11,    15,    18,
      21,    22,    23,    30,    31,    32,    33,    34,    41,    43,
      51,    60,    62,    43,     6,    60,    60,    60,    58,    41,
      41,    41,     9,    41,    48,    60,    62,    60,    24,    25,
      26,    27,    28,    29,    37,    38,    39,    40,    44,    45,
      62,    48,    12,    16,    19,    46,    60,    60,    60,    46,
      60,    61,    60,    46,    44,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    44,    60,    60,    60,
      60,    46,    46,    46,    50,    49,    49,    13,    17,    20,
      60,     9,    60,    60,    14
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 68 "uncool.y"
    { 
                                                                                    (yyval.nPtr) = clazz((yyvsp[(2) - (5)].charVal), (yyvsp[(4) - (5)].nPtr)); 
                                                                                    ex((yyval.nPtr)); 
                                                                                    freeNode((yyval.nPtr));  
                                                                                    exit(0); 
                                                                                }
    break;

  case 3:
#line 76 "uncool.y"
    { (yyval.nPtr) = opr(';', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(2) - (3)].nPtr)); }
    break;

  case 4:
#line 77 "uncool.y"
    {}
    break;

  case 5:
#line 80 "uncool.y"
    { (yyval.nPtr) = func((yyvsp[(1) - (9)].charVal), (yyvsp[(6) - (9)].nPtr), (yyvsp[(3) - (9)].nPtr), (yyvsp[(8) - (9)].nPtr)); }
    break;

  case 6:
#line 81 "uncool.y"
    { (yyval.nPtr) = func((yyvsp[(1) - (8)].charVal), (yyvsp[(5) - (8)].nPtr), NULL, (yyvsp[(7) - (8)].nPtr)); }
    break;

  case 7:
#line 82 "uncool.y"
    { (yyval.nPtr) = id((yyvsp[(1) - (3)].charVal), (yyvsp[(3) - (3)].nPtr), NULL); }
    break;

  case 8:
#line 83 "uncool.y"
    { (yyval.nPtr) = id((yyvsp[(1) - (5)].charVal), (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); }
    break;

  case 9:
#line 84 "uncool.y"
    { (yyval.nPtr) = id((yyvsp[(1) - (5)].charVal), type(tCHAR), charCon((yyvsp[(5) - (5)].charVal))); }
    break;

  case 10:
#line 85 "uncool.y"
    { (yyval.nPtr) = id((yyvsp[(1) - (5)].charVal), type(tINTARRAY), NULL); }
    break;

  case 11:
#line 88 "uncool.y"
    { (yyval.nPtr) = type(tINT); }
    break;

  case 12:
#line 89 "uncool.y"
    { (yyval.nPtr) = type(tBOOLEAN); }
    break;

  case 13:
#line 90 "uncool.y"
    { (yyval.nPtr) = type(tCHAR); }
    break;

  case 14:
#line 93 "uncool.y"
    { (yyval.nPtr) = intCon((yyvsp[(1) - (1)].intVal)); }
    break;

  case 15:
#line 94 "uncool.y"
    { (yyval.nPtr) = boolCon((yyvsp[(1) - (1)].intVal)); }
    break;

  case 16:
#line 95 "uncool.y"
    { (yyval.nPtr) = boolCon((yyvsp[(1) - (1)].intVal)); }
    break;

  case 17:
#line 98 "uncool.y"
    { (yyval.nPtr) = opr(',', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 18:
#line 99 "uncool.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 19:
#line 102 "uncool.y"
    { (yyval.nPtr) = id((yyvsp[(1) - (3)].charVal), (yyvsp[(3) - (3)].nPtr), NULL); }
    break;

  case 20:
#line 103 "uncool.y"
    { (yyval.nPtr) = id((yyvsp[(1) - (5)].charVal), type(tINTARRAY), NULL); }
    break;

  case 21:
#line 106 "uncool.y"
    { (yyval.nPtr) = opr(AssignOpr, 2, id((yyvsp[(1) - (3)].charVal), NULL, NULL), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 22:
#line 107 "uncool.y"
    { (yyval.nPtr) = opr(AssignOpr, 3, id((yyvsp[(1) - (6)].charVal), NULL, NULL), (yyvsp[(3) - (6)].nPtr), (yyvsp[(6) - (6)].nPtr)); }
    break;

  case 23:
#line 108 "uncool.y"
    { (yyval.nPtr) = opr(FuncOpr, 1, id((yyvsp[(1) - (3)].charVal), NULL, NULL)); }
    break;

  case 24:
#line 109 "uncool.y"
    { (yyval.nPtr) = opr(InOpr, 0); }
    break;

  case 25:
#line 110 "uncool.y"
    { (yyval.nPtr) = opr(OutStrOpr, 1, (yyvsp[(3) - (4)].nPtr)); }
    break;

  case 26:
#line 111 "uncool.y"
    { (yyval.nPtr) = opr(OutIntOpr, 1, (yyvsp[(3) - (4)].nPtr)); }
    break;

  case 27:
#line 112 "uncool.y"
    { (yyval.nPtr) = opr(FuncOpr, 2, id((yyvsp[(1) - (4)].charVal), NULL, NULL), (yyvsp[(3) - (4)].nPtr)); }
    break;

  case 28:
#line 113 "uncool.y"
    { (yyval.nPtr) = opr(IdOpr, 1, id((yyvsp[(1) - (1)].charVal), NULL, NULL)); }
    break;

  case 29:
#line 114 "uncool.y"
    { (yyval.nPtr) = opr(IdOpr, 2, id((yyvsp[(1) - (4)].charVal), NULL, NULL), (yyvsp[(3) - (4)].nPtr)); }
    break;

  case 30:
#line 115 "uncool.y"
    { (yyval.nPtr) = opr(IfOpr, 3, (yyvsp[(2) - (7)].nPtr), (yyvsp[(4) - (7)].nPtr), (yyvsp[(6) - (7)].nPtr)); }
    break;

  case 31:
#line 116 "uncool.y"
    { (yyval.nPtr) = opr(WhileOpr, 2, (yyvsp[(2) - (5)].nPtr), (yyvsp[(4) - (5)].nPtr)); }
    break;

  case 32:
#line 117 "uncool.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); }
    break;

  case 33:
#line 118 "uncool.y"
    { (yyval.nPtr) = opr(LetOpr, 2, (yyvsp[(2) - (5)].nPtr), (yyvsp[(4) - (5)].nPtr)); }
    break;

  case 34:
#line 119 "uncool.y"
    { (yyval.nPtr) = opr(NewOpr, 1, (yyvsp[(4) - (5)].nPtr)); }
    break;

  case 35:
#line 120 "uncool.y"
    { (yyval.nPtr) = opr(AddOpr, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 36:
#line 121 "uncool.y"
    { (yyval.nPtr) = opr(SubOpr, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 37:
#line 122 "uncool.y"
    { (yyval.nPtr) = opr(ImuOpr, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 38:
#line 123 "uncool.y"
    { (yyval.nPtr) = opr(DivOpr, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 39:
#line 124 "uncool.y"
    { (yyval.nPtr) = opr(UminusOpr, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 40:
#line 125 "uncool.y"
    { (yyval.nPtr) = opr(NotOpr, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 41:
#line 126 "uncool.y"
    { (yyval.nPtr) = opr(LtOpr, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 42:
#line 127 "uncool.y"
    { (yyval.nPtr) = opr(LeOpr, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 43:
#line 128 "uncool.y"
    { (yyval.nPtr) = opr(EqOpr, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 44:
#line 129 "uncool.y"
    { (yyval.nPtr) = opr(GtOpr, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 45:
#line 130 "uncool.y"
    { (yyval.nPtr) = opr(GeOpr, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 46:
#line 131 "uncool.y"
    { (yyval.nPtr) = opr(NeOpr, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 47:
#line 132 "uncool.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); }
    break;

  case 48:
#line 133 "uncool.y"
    { (yyval.nPtr) = boolCon((yyvsp[(1) - (1)].intVal)); }
    break;

  case 49:
#line 134 "uncool.y"
    { (yyval.nPtr) = boolCon((yyvsp[(1) - (1)].intVal)); }
    break;

  case 50:
#line 135 "uncool.y"
    { (yyval.nPtr) = intCon((yyvsp[(1) - (1)].intVal)); }
    break;

  case 51:
#line 136 "uncool.y"
    { (yyval.nPtr) = charCon((yyvsp[(1) - (1)].charVal)); }
    break;

  case 52:
#line 139 "uncool.y"
    { (yyval.nPtr) = opr(',', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 53:
#line 140 "uncool.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 54:
#line 143 "uncool.y"
    { (yyval.nPtr) = opr(';', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 55:
#line 144 "uncool.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;


/* Line 1267 of yacc.c.  */
#line 1833 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 146 "uncool.y"




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

