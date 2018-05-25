/* TO BE COMPLETED */

%option noyywrap
%option yylineno
%option nounistd

%x incl
%x comment

%{
#include <unistd.h>
#include "global.h"
#include "mycc.h"


static int localvar = 3;

static int install_id();
static int install_int();
static int install_oct();
static int install_hex();
static int install_chr();
static int install_fp();
static int install_str();

static int line_num = 1; // current line to jump commentsgedi

%}

digit           [0-9]
alpha           [a-zA-Z_]
id              {alpha}({alpha}|{digit})*
int             {digit}+
oct             0[0-7]+
hex             0[xX][0-9a-fA-F]+
chr             '(\\'|[^'\n])*'
fp              {int}(\.{int}([Ee][+-]?{int})?|(\.{int})?[Ee][+-]?{int})
str             \"(\\\"|\\\n|[^"])*\"

%%


"/*"                BEGIN(comment);
<comment>[^*\n]*        /* eat anything that's not a '*' */
<comment>"*"+[^*/\n]*   /* eat up '*'s not followed by '/'s */
<comment>\n             ++line_num;
<comment>"*"+"/"        BEGIN(INITIAL);

#include            BEGIN(incl);
<incl>[ \t]*      /* eat the whitespace */
<incl>[^ \t\n]+   { /* got the include file name */
     yyin = fopen( yytext, "r" );
	 yypush_buffer_state(yy_create_buffer( yyin, YY_BUF_SIZE ));
     BEGIN(INITIAL);
     }

<<EOF>> {
	yypop_buffer_state();

     if ( !YY_CURRENT_BUFFER )
         {
         yyterminate();
         }
     }

[ \t\v\n\f\r]                  /* skip white space */
___                            /* TO BE COMPLETED: ignore inline and multiline comments */
{id}                           { return install_id(); }
{oct}                          { return install_oct(); }
{hex}                          { return install_hex(); }
{int}                          { return install_int(); }
{chr}                          { return install_chr(); }
{fp}                           { return install_fp(); }
{str}                          { return install_str(); }
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

/* install_id - add identifier to symbol table if not already there */
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

/* install_int - convert decimal yytext[] to INT8, INT16, or INT32 */
static int install_int()
{
	sscanf(yytext, "%u", &yylval.num);

	if (yylval.num < 128)
		return INT8;

	if (yylval.num < 32368)
		return INT16;

	return INT32;
}

/* install_oct - convert octal yytext[] to INT8, INT16, or INT32 */
static int install_oct()
{
	sscanf(yytext, "%o", &yylval.num);

  	if (yylval.num < 128)
		return INT8;

	if (yylval.num < 32368)
		return INT16;

	return INT32;
}

/* install_hex - convert hexadecimal yytext[] to INT8, INT16, or INT32 */
static int install_hex()
{
	sscanf(yytext, "%x", &yylval.num);

	if (yylval.num < 128)
		return INT8;

	if (yylval.num < 32368)
		return INT16;

	return INT32;
}

/* install_chr - convert ASCII character yytext[1] to INT8 */
static int install_chr()
{
	char c;

	sscanf(yytext + 1, "%c", &c);
	yylval.num = (int)c;

	return INT8;
}

/* install_fp - convert float yytext[] into float FLT */
static int install_fp()
{
	sscanf(yytext, "%g", &yylval.flt);

	return FLT;
}

/* install_str - duplicate yytext[] string without the quotes */
static int install_str()
{
	yylval.str = (char*)malloc(yyleng - 1);

	if (yylval.str)
	{
		strcpy(yylval.str, yytext + 1);
		yylval.str[yyleng - 2] = '\0';
	}

	return STR;
}
