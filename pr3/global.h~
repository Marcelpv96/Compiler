#ifndef GLOBAL_H
#define GLOBAL_H

#include "javaclass.h"
#include "bytecode.h"

struct Symbol
{
	const char *lexptr;
	int  token;
	int  localvar;
};

typedef struct Symbol Symbol;

extern Symbol *lookup(const char*);
extern Symbol *insert(const char*, int);

extern void init(void);
extern void error(const char*);

extern char *yytext;
extern int yylineno;
extern int yylex();
extern int yyparse();
extern int yyerror(const char*);

extern int errnum;

#endif
