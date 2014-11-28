#ifndef uclib_h_included
#define uclib_h_included

#include "register.h"
#include "symbol_table.h"

typedef enum { intCons, boolCons, charCons, typeNode, idNode, oprNode, funcNode, classNode} nodeEnum;

typedef enum { 
    IdOpr, FuncOpr, WhileOpr, IfOpr, AssignOpr, InOpr, 
    OutIntOpr, OutStrOpr, UminusOpr, NewOpr, NotOpr, LtOpr,
    LeOpr, EqOpr, GtOpr, GeOpr, NeOpr, LetOpr, AddOpr, SubOpr, DivOpr, ImuOpr
} operateEnum;

/* int constants */
typedef struct 
{
    int value;                      /* value of int constant */
    regiserEnum _register;
} intNodeType;


/* int constants */
typedef struct 
{
    char *value;                    /* value of int constant */
    regiserEnum _register;
} charNodeType;

/* bool constants */
typedef struct 
{
    int value;                      /* value of int bool constant*/
    regiserEnum _register;
} boolNodeType;

/* operators */
typedef struct
{
    regiserEnum _register;
    typeEnum abs_type;                   /* type */
} typeNodeType;


/* identifiers */
typedef struct 
{
    char *name;
    struct symbol* ptr;
    struct nodeTypeTag *op; 
    regiserEnum _register;
    typeEnum abs_type;
} idNodeType;

/* operators */
typedef struct
{
    int oper;                       /* operator */
    int nops;                       /* number of operands */
    struct nodeTypeTag *op[10];     /* operands (expandable) */
    regiserEnum _register;
    typeEnum abs_type;
} oprNodeType;

/* operators */
typedef struct
{
    int oper;                       /* operator */
    char *name;
    struct symbol* ptr;
    struct nodeTypeTag *returnType;
    struct nodeTypeTag *param;
    struct nodeTypeTag *op;
    regiserEnum _register;
    typeEnum abs_type;
} funcNodeType;


/* operators */
typedef struct
{
    char *name;
    struct symbol* ptr;
    struct nodeTypeTag *op;
    regiserEnum _register;
} classNodeType;


typedef struct nodeTypeTag 
{
    nodeEnum type;                   /* type of node */
    typeEnum abs_type;
    regiserEnum _register;
    /* union must be last entry in nodeType */
    /* because operNodeType may dynamically increase */
    union 
    {
        intNodeType intNode;
        charNodeType charNode;
        boolNodeType boolNode;
        typeNodeType typeNode;
        funcNodeType funcNode;
        classNodeType classNode;
        idNodeType idNode;          /* identifiers */
        oprNodeType oprNode;        /* operators */
    };
} nodeType;

#endif
