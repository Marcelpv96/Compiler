/* TODO: TO BE COMPLETED */

#include "global.h"
#include <string.h>

 
static Symbol list[100];
int size = 0;
Symbol *lookup(const char *s) {	

	int i;

	for(i = 0; i < size; i++) {
		if (strcmp(s, list[i].lexptr) == 0) {
			return &list[i];		
		}
	}
	return NULL;
}

Symbol *insert(const char *s, int token) {
	int i;
	Symbol sym;
	sym.lexptr = strdup(s);
	sym.token = token;	
	
	list[size] = sym;
	size++;

	return &list[size-1];
}
