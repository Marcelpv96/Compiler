#include "global.h"

Table *mktable(Table *prev)
{
	Table *table = (Table*)malloc(sizeof(Table));
	table->prev = prev;
	table->list = NULL;
	if (prev)
		table->level = prev->level + 1;
	else
		table->level = 0;
	return table;
}

void dumptable(Table *table)
{
	Entry *entry;

	printf("Symbol\t\t   level\t    type   place\n");
	while (table)
	{
		entry = table->list;
		while (entry)
		{
			printf("%-16s%8d %15s %7d\n", entry->sym->lexptr, table->level, entry->type, entry->place);
			entry = entry->next;
		}	
		
		table = table->prev;
	}
}

void addwidth(Table *table, int width)
{
	table->width = width;
}

Entry *enter(Table *table, Symbol *sym, Type type, int place)
{
	Entry **entry = &table->list;
	while (*entry)
		entry = &(*entry)->next;
	*entry = (Entry*)malloc(sizeof(Entry));
	(*entry)->next = NULL;
	(*entry)->sym = sym;
	(*entry)->type = type;
	(*entry)->place = place;
	(*entry)->table = NULL;
	return *entry;
}

Entry *enterproc(Table *table, Symbol *sym, Type type, Table *newtable)
{
	Entry *entry = enter(table, sym, type, 0);
	entry->table = newtable;
	return entry;
}  

int getlevel(Table *table, Symbol *sym)
{
	Entry *entry;

	while (table)
	{
		entry = table->list;
		while (entry)
		{
			if (entry->sym == sym)
				return table->level;
			entry = entry->next;
		}	
		table = table->prev;
	}
	return -1;
}

Type gettype(Table *table, Symbol *sym)
{
	Entry *entry;

	while (table)
	{
		entry = table->list;
		while (entry)
		{
			if (entry->sym == sym)
				return entry->type;
			entry = entry->next;
		}	
		table = table->prev;
	}
	return NULL;
}

int getplace(Table *table, Symbol *sym)
{
	Entry *entry;

	while (table)
	{
		entry = table->list;
		while (entry)
		{
			if (entry->sym == sym)
				return entry->place;
			entry = entry->next;
		}	
		table = table->prev;
	}
	return -1;
}
