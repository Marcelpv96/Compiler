/* TODO: TO BE COMPLETED */

%option noyywrap
%option yylineno
%option nounistd

%{

#include "global.h"
#include "mycc.h"

static int localvar = 3;	/* JVM first local var index */

static int install_id();
static int install_int();
static int install_oct();
static int install_hex();
static int install_chr();

%}

digit           [0-9]
alpha           [a-zA-Z_]
id              {alpha}({alpha}|{digit})*
int             {digit}+

%%

[ \t\v\n\f\r]                  /* skip white space */
___                            /* TODO: TO BE COMPLETED: ignore inline and multiline comments */
{id}                           { return install_id(); }
___                            { /* TODO: TO BE COMPLETED */ return install_oct(); }
___                            { /* TODO: TO BE COMPLETED */ return install_hex(); }
___                            { /* TODO: TO BE COMPLETED */ return install_chr(); }
{int}                          { return install_int(); }
"+="                           { return PA; }
"-="                           { return NA; }
"*="                           { return TA; }
"/="                           { return DA; }
"%="                           { return MA; }
"&="                           { return AA; }
"^="                           { return XA; }
"|="                           { return OA; }
"<<="                          { return LA; }
">>="                          { return RA; }
"||"                           { return OR; }
"&&"                           { return AN; }
"=="                           { return EQ; }
"!="                           { return NE; }
"<="                           { return LE; }
">="                           { return GE; }
"<<"                           { return LS; }
">>"                           { return RS; }
"++"                           { return PP; }
"--"                           { return NN; }
"->"                           { return AR; }
"<%"                           { return '{'; }
"%>"                           { return '}'; }
"<:"                           { return '['; }
":>"                           { return ']'; }
[!$%&()*+,\-./:;<=>?\[\]^{|}~] { return yytext[0]; }
.                              { yyerror("Unknown character ignored"); }

%%

/* install_id - add identifier to symbol table if not already there and assign it a JVM local var index */
static int install_id()
{
	yylval.sym = lookup(yytext);

	if (!yylval.sym)
	{
		yylval.sym = insert(yytext, ID);
		yylval.sym->localvar = localvar++;
	}

	return yylval.sym->token;
}

/* install_int - convert decimal yytext[] to yylval.num and return INT8, INT16, or INT32 */
static int install_int()
{
	sscanf(yytext, "%u", &yylval.num);

	if (yylval.num < 128)
		return INT8;

	if (yylval.num < 32368)
		return INT16;

	return INT32;
}

/* install_oct - convert octal yytext[] to yylval.num and return INT8, INT16, or INT32 */
static int install_oct()
{
	sscanf(yytext, "%o", &yylval.num);

	if (yylval.num < 128)
		return INT8;

	if (yylval.num < 32368)
		return INT16;

	return INT32;
}

/* install_hex - convert hexadecimal yytext[] to yylval.num and return INT8, INT16, or INT32 */
static int install_hex()
{
	sscanf(yytext, "%x", &yylval.num);

	if (yylval.num < 128)
		return INT8;

	if (yylval.num < 32368)
		return INT16;

	return INT32;
}

/* install_chr - convert ASCII character yytext[1] to yylval.num and return INT8 */
static int install_chr()
{
	/* TODO: TO BE COMPLETED */

	return INT8;
}
