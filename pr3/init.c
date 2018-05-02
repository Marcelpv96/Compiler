#include "global.h"
#include "mycc.h"

struct Keyword
{	const char *lexptr;
	int token;
};

static struct Keyword keywords[] =
{
	{ "break",	BREAK },
	{ "do",		DO },
	{ "else",	ELSE },
	{ "for",	FOR },
	{ "if",		IF },
	{ "return",	RETURN },
	{ "while",	WHILE },
	{ NULL,         0 }
};

/* init - populates global symbol table with keywords */
void init()
{
	struct Keyword *k;

	for (k = keywords; k->lexptr; k++)
		insert(k->lexptr, k->token);
}

