# Lex/Yacc Compiler

> This is a simple example to show how to use Lex/Yacc  to generate IA32 code

## Overview
* [Operating Environment](#user-content-operating-environment)
* [Program Grammar](#user-content-program-grammar)
* [Using Help](#user-content-using-help)
* [Code Files](#user-content-code-files)
* [Compilation Sequence](#user-content-compilation-sequence)

####Operating Environment
- OS X 10.9.2
- Lex, Bison, Gcc

#### Program Grammar

##### Variable Type
```  java
s : String <- "abcd";
x : Int;
x : Int []; 
```
##### Variable Declaration
```  java
y : Int ;
x : Int -> 1;
```
##### Assignment Statement
```  java
x -> 1;
```
##### If Statement
```  java
if 
    a < 2 
then 
    1 
else 
    factorial(a-1) + factorial(a-2)
fi
```
##### While Statement
```  java
while i < size loop {

} pool
```
##### Let Statement
```  java
let i : Int, small : Int in {

} tel
```
##### System Declaration 
```  java
out_string("> ");
x <- in_int();
out_int(x*2+(y-4));
```
##### Function Declaration 
```  java
factorial(a: Int) : Int {

}
```
##### Class Declaration 
```  java
class Main {

}
```
##### A Program sample
```  java
class Main {
    s : String <- "abcd";
    x : Int;
    y : Int <- 10;
    main () : Int {
      x <- in_int();
      out_string("test");
      out_string(s);
      out_int(x*2+(y-4))
    };
}
```
It's also has a main class in a file and a main function in a class, When compiler success, the program will run start by main function. The compiler can check the symbol scope, support function call, but now it can't support type check and It's not an object-oriented design

#### Using Help
1. build Lex/Yacc, Will Generate uncool.pgm program
```  bash
    make
```
2. parse the uc  to IA32 code, execute the command
```  bash
 	./uncool.pgm uncool.uc >uncool.s 
```
3. Assembly the IA32 code to executable program,execute the command
```  bash
    gcc –m32 uncool.s –o uncool
```
4. execute the program you will see the result of this program result.
```  bash
    ./uncool
```

#### Code Files
1. Uncool.l，Uncool.y, Uclib.h  
    Lex/Yacc code common function and structure
2. symbol_table.h symbol_table.c  
    symbol_table implement storage symbol in the LinkList
3. stack.h stack.c  
    symbol_table stack implement store symbol_table in stack
4. uccompiler.c  
    the main parse program, transition the Uc code to IA32 code

#### Compilation Sequence

![Alt text](http://pan.baidu.com/s/1kTJvmYV)

1. Uclib.c / Uncool.y syntax analyzer program scan the uncool code to generate syntax tree. The tree data is store in the nodeType strut. The nodeType strut is a tree data strut, It contains all syntax nodes and those relationship.
2. Then we will call ex function in the Uncool.y, when complete scan code, you can see the call function code in the Uncool.y , lineno 70, It will be executed when complete scan.
3. The ex function is in the uccompiler.c file, It was used transition the Uc code to IA32 code, It read all node in the syntax tree and transition the operation to IA32 code.
4. The symbol_table and stack is used to record the program variables
Stack.h, Stack.c has define a linked list data structure， It was used to store symbol_table. When The code run into the class , function or let code, we will generate a symbol_table data and put it into Stack, The head of Stack is the current scope of the symbol table, when run out the class, function or let code, we wil let symbol table out the stack and remove the class, function or let’s variable. symbol_table is a linked list data structure too, It is used to store current scope’s symbol variable, when we use a variable , or a function, we will find from here



