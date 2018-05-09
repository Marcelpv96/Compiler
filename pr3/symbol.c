/* TODO: TO BE COMPLETED */

#include "global.h"
#include <string.h>

 
static int size = 1;

static Symbol list[100];

Symbol *lookup(const char *s) {	

	int i;

	if (size == 1) {
		size++;
		Symbol sym;
		sym.lexptr = "";
		sym.token = -1;
		for(i = 0; i < 100; i++) {
			list[i] = sym;
		}
	}

	for(i = 0; i < size; i++) {
		if (list[i].token == -1) {
			return NULL; 
		}		

		if (strcmp(s, list[i].lexptr) == 0) {
			return &list[i];		
		}
	}
	return NULL;
}

Symbol *insert(const char *s, int token) {
	int i;
	Symbol sym;
	sym.lexptr = s;
	sym.token = token;	
	for(i = 0; i < size; i++) {
		if (list[i].token == -1) {	
			list[i] = sym;
			size++;
			return &list[i];
		}
	}
	return NULL;
}
