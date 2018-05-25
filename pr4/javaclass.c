/*
 *  javaclass.c
 *
 *  Operations on Java ClassFile struct
 *  
 *
 *  Created by Robert van Engelen on 1/2/05, updated 11/22/13.
 *  Copyright 2005 Robert van Engelen. All rights reserved.
 *
 */

#include "javaclass.h"

static int save_constant_pool(FILE *fd, struct ClassFile *cf);
static int save_interfaces(FILE *fd, struct ClassFile *cf);
static int save_fields(FILE *fd, struct ClassFile *cf);
static int save_methods(FILE *fd, struct ClassFile *cf);
static int save_attributes(FILE *fd, struct ClassFile *cf);

static int save_Utf8_info(FILE *fd, const char *name);
static int save_Integer_info(FILE *fd, u4 i);
static int save_Float_info(FILE *fd, float f);
static int save_String_info(FILE *fd, u2 i);
static int save_Class_info(FILE *fd, u2 name_index);
static int save_Fieldref_info(FILE *fd, struct Pair p);
static int save_Methodref_info(FILE *fd, struct Pair p);
static int save_NameAndType_info(FILE *fd, struct Pair p);

static int save_u1(FILE *fd, unsigned int n);
static int save_u2(FILE *fd, unsigned int n);
static int save_u4(FILE *fd, unsigned int n);

// Set up a class file structure
int init_ClassFile(struct ClassFile *cf)
{
	cf->access = ACC_PUBLIC;
	cf->name = NULL;

	cf->constant_pool_count = 0;
	cf->constant_pool = NULL;

	cf->field_count = 0;
	cf->fields = NULL;
	
	cf->method_count = 0;
	cf->methods = NULL;
	
	return 0;
}

// Add a regular C string to the constant pool encoded in UTF8 format
int constant_pool_add_Utf8(struct ClassFile *cf, const char *name)
{
	struct ConstantPool **p = &cf->constant_pool;
	int index = 1;

	while (*p != NULL)
	{
		if ((*p)->tag == CONSTANT_Utf8 && !strcmp((*p)->data.u, name))
			return index;
		p = &(*p)->next;
		index++;
	}

	*p = (struct ConstantPool*)malloc(sizeof(struct ConstantPool));

	if (*p)
	{
		(*p)->tag = CONSTANT_Utf8;
		(*p)->data.u = strdup(name);
		(*p)->next = NULL;
	}
	
	return ++cf->constant_pool_count;
}

// Add a 32-bit integer to the constant pool
int constant_pool_add_Integer(struct ClassFile *cf, u4 i)
{
	struct ConstantPool **p = &cf->constant_pool;
	int index = 1;

	while (*p != NULL)
	{
		if ((*p)->tag == CONSTANT_Integer && (*p)->data.i == i)
			return index;
		p = &(*p)->next;
		index++;
	}

	*p = (struct ConstantPool*)malloc(sizeof(struct ConstantPool));

	if (*p)
	{
		(*p)->tag = CONSTANT_Integer;
		(*p)->data.i = i;
		(*p)->next = NULL;
	}
	
	return ++cf->constant_pool_count;
}

// Add a 32-bit float to the constant pool
int constant_pool_add_Float(struct ClassFile *cf, float f)
{
	struct ConstantPool **p = &cf->constant_pool;
	int index = 1;

	while (*p != NULL)
	{
		if ((*p)->tag == CONSTANT_Float && (*p)->data.f == f)
			return index;
		p = &(*p)->next;
		index++;
	}

	*p = (struct ConstantPool*)malloc(sizeof(struct ConstantPool));

	if (*p)
	{
		(*p)->tag = CONSTANT_Float;
		(*p)->data.f = f;
		(*p)->next = NULL;
	}
	
	return ++cf->constant_pool_count;
}

// Add a string to the constant pool referenced by constant pool index (to UTF8)
int constant_pool_add_String(struct ClassFile *cf, u2 i)
{
	struct ConstantPool **p = &cf->constant_pool;
	int index = 1;

	while (*p != NULL)
	{
		if ((*p)->tag == CONSTANT_String && (*p)->data.i != i)
			return index;
		p = &(*p)->next;
		index++;
	}

	*p = (struct ConstantPool*)malloc(sizeof(struct ConstantPool));

	if (*p)
	{
		(*p)->tag = CONSTANT_String;
		(*p)->data.i = i;
		(*p)->next = NULL;
	}
	
	return ++cf->constant_pool_count;
}

// Add a class name to the constant pool
int constant_pool_add_Class(struct ClassFile *cf, const char *name)
{
	int r = constant_pool_add_Utf8(cf, name);
	struct ConstantPool **p = &cf->constant_pool;
	int index = 1;

	while (*p != NULL)
	{
		if ((*p)->tag == CONSTANT_Class && (*p)->data.r == r)
			return index;
		p = &(*p)->next;
		index++;
	}

	*p = (struct ConstantPool*)malloc(sizeof(struct ConstantPool));

	if (*p)
	{	
		(*p)->tag = CONSTANT_Class;
		(*p)->data.r = r;
		(*p)->next = NULL;
	}
	
	return ++cf->constant_pool_count;
}

// Add a field reference to the constant pool
int constant_pool_add_Fieldref(struct ClassFile *cf, const char *class_name, const char *field_name, const char *descriptor)
{
	struct Pair t;
	struct ConstantPool **p = &cf->constant_pool;
	int index = 1;

	t.i = constant_pool_add_Class(cf, class_name);
	t.j = constant_pool_add_NameAndType(cf, field_name, descriptor);

	while (*p != NULL)
	{
		if ((*p)->tag == CONSTANT_Fieldref && (*p)->data.t.i == t.i && (*p)->data.t.j == t.j)
			return index;
		p = &(*p)->next;
		index++;
	}

	*p = (struct ConstantPool*)malloc(sizeof(struct ConstantPool));

	if (*p)
	{
		(*p)->tag = CONSTANT_Fieldref;
		(*p)->data.t = t;
		(*p)->next = NULL;
	}
	
	return ++cf->constant_pool_count;
}

// Add a method reference to the constant pool
int constant_pool_add_Methodref(struct ClassFile *cf, const char *class_name, const char *method_name, const char *descriptor)
{
	struct Pair t;
	struct ConstantPool **p = &cf->constant_pool;
	int index = 1;

	t.i = constant_pool_add_Class(cf, class_name);
	t.j = constant_pool_add_NameAndType(cf, method_name, descriptor);

	while (*p != NULL)
	{
		if ((*p)->tag == CONSTANT_Methodref && (*p)->data.t.i == t.i && (*p)->data.t.j == t.j)
			return index;
		p = &(*p)->next;
		index++;
	}

	*p = (struct ConstantPool*)malloc(sizeof(struct ConstantPool));

	if (*p)
	{
		(*p)->tag = CONSTANT_Methodref;
		(*p)->data.t = t;
		(*p)->next = NULL;
	}
	
	return ++cf->constant_pool_count;
}

// Add a (name,descriptor) pair to the constant pool
int constant_pool_add_NameAndType(struct ClassFile *cf, const char *name, const char *descriptor)
{
	struct Pair t;
	struct ConstantPool **p = &cf->constant_pool;
	int index = 1;

	t.i = constant_pool_add_Utf8(cf, name);
	t.j = constant_pool_add_Utf8(cf, descriptor);

	while (*p != NULL)
	{
		if ((*p)->tag == CONSTANT_NameAndType && (*p)->data.t.i == t.i && (*p)->data.t.j == t.j)
			return index;
		p = &(*p)->next;
		index++;
	}

	*p = (struct ConstantPool*)malloc(sizeof(struct ConstantPool));
	
	if (*p)
	{
		(*p)->tag = CONSTANT_NameAndType;
		(*p)->data.t = t;
		(*p)->next = NULL;
	}
	
	return ++cf->constant_pool_count;
}

// Save the class file to file "name.class", where "name" is the name of the class
int save_classFile(struct ClassFile *cf)
{
	FILE *fd;
	char filename[256];
	int this_class_index, super_class_index;

	strcpy(filename, cf->name);
	strcat(filename, ".class");

	fd = fopen(filename, "w");

	this_class_index = constant_pool_add_Class(cf, cf->name);
	super_class_index = constant_pool_add_Class(cf, "java/lang/Object");

	save_u4(fd, 0xCAFEBABE);	// magic number
	save_u2(fd, 0x0000);		// minor_version
	save_u2(fd, 0x002E);		// major_version
	save_constant_pool(fd, cf);
	save_u2(fd, cf->access);	// access_flags
	save_u2(fd, this_class_index);	// this_class (index in pool refers to CONSTANT_Class_info)
	save_u2(fd, super_class_index);	// super_class (index in pool refers to CONSTANT_Class_info)
	save_interfaces(fd, cf);
	save_fields(fd, cf);
	save_methods(fd, cf);
	save_attributes(fd, cf);

	fclose(fd);

	return 0;
}

// Static functions

static int save_constant_pool(FILE *fd, struct ClassFile *cf)
{
	struct ConstantPool *p;
	int i;
	
	// pool contains this class, super class, field names, field descriptors, method names, method descriptors, method code

	save_u2(fd, cf->constant_pool_count + 2 + 2 * cf->field_count + 2 * cf->method_count);	// constant_pool_count

	for (p = cf->constant_pool; p; p = p->next)
	{
		switch (p->tag)
		{
			case CONSTANT_Utf8:
				save_Utf8_info(fd, p->data.u);
				break;
			case CONSTANT_Integer:
				save_Integer_info(fd, p->data.i);
				break;
			case CONSTANT_Float:
				save_Float_info(fd, p->data.f);
				break;
			// case CONSTANT_Long:
			// case CONSTANT_Double:
			case CONSTANT_Class:
				save_Class_info(fd, p->data.r);
				break;
			case CONSTANT_String:
				save_String_info(fd, p->data.i);
				break;
			case CONSTANT_Fieldref:
				save_Fieldref_info(fd, p->data.t);
				break;
			case CONSTANT_Methodref:
				save_Methodref_info(fd, p->data.t);
				break;
			// case CONSTANT_InterfaceMethodref:
			case CONSTANT_NameAndType:
				save_NameAndType_info(fd, p->data.t);
				break;
		}
	}

	// save standard stuff, indexed from cf->constant_pool_count + 1
	save_Utf8_info(fd, "Code");
	
	// field name index = cf->constant_pool_count + 2 + 2 * i
	for (i = 0; i < cf->field_count; i++)
	{
		save_Utf8_info(fd, cf->fields[i].name);
		save_Utf8_info(fd, cf->fields[i].descriptor);
	}
	
	// method name index = cf->constant_pool_count + 2 + 2 * field_count + 2 * i
	for (i = 0; i < cf->method_count; i++)
	{
		save_Utf8_info(fd, cf->methods[i].name);
		save_Utf8_info(fd, cf->methods[i].descriptor);
	}
	
	return 0;
}

static int save_interfaces(FILE *fd, struct ClassFile *cf)
{
	(void)cf; // appease -Wall -Wextra
	// Not used at this time
	save_u2(fd, 0);				// interfaces_count
	// Each (u2) value in the interfaces array must be a valid index into the constant_pool table.
	// u2(...)

	return 0;
}

static int save_fields(FILE *fd, struct ClassFile *cf)
{
	int i;
	
	save_u2(fd, cf->field_count);				// field_count
	
	for (i = 0; i < cf->field_count; i++)
	{
		save_u2(fd, cf->fields[i].access);
		save_u2(fd, cf->constant_pool_count + 2 + 2 * i);
		save_u2(fd, cf->constant_pool_count + 3 + 2 * i);
		save_u2(fd, 0);						// no attributes
	}

	return 0;
}

static int save_methods(FILE *fd, struct ClassFile *cf)
{
	int i;
	
	save_u2(fd, cf->method_count);				// method_count
	
	for (i = 0; i < cf->method_count; i++)
	{
		save_u2(fd, cf->methods[i].access);
		save_u2(fd, cf->constant_pool_count + 2 + 2 * cf->field_count + 2 * i);
		save_u2(fd, cf->constant_pool_count + 3 + 2 * cf->field_count + 2 * i);

		if (cf->methods[i].code_length != 0)
		{
			u4 j;
			
			save_u2(fd, 1);								// one attribute
			save_u2(fd, cf->constant_pool_count + 1);	// attribute_name_index
			save_u4(fd, cf->methods[i].code_length + 12);	// attribute_length
			save_u2(fd, cf->methods[i].max_stack);
			save_u2(fd, cf->methods[i].max_locals);
			save_u4(fd, cf->methods[i].code_length);			
			for (j = 0; j < cf->methods[i].code_length; j++)
				save_u1(fd, cf->methods[i].code[j]);
			save_u2(fd, 0);					// no exceptions
			save_u2(fd, 0);					// no attributes
		}
		else
			save_u2(fd, 0);
	}
	
	return 0;
}

static int save_attributes(FILE *fd, struct ClassFile *cf)
{
	(void)cf; // appease -Wall -Wextra
	save_u2(fd, 0);				// attributes_count
	// Each value of the attributes table must be an attribute structure.

	return 0;
}

static int save_Utf8_info(FILE *fd, const char *name)
{
	save_u1(fd, CONSTANT_Utf8);
	save_u2(fd, strlen(name));
	fprintf(fd, "%s", name);
	
	return 0;
}

static int save_Integer_info(FILE *fd, u4 i)
{
	save_u1(fd, CONSTANT_Integer);
	save_u4(fd, i);

	return 0;
}

static int save_Float_info(FILE *fd, float f)
{	int i;
	*(float*)&i = f;
	save_u1(fd, CONSTANT_Float);
	save_u4(fd, i);

	return 0;
}

static int save_String_info(FILE *fd, u2 i)
{
	save_u1(fd, CONSTANT_String);
	save_u2(fd, i);
	
	return 0;
}

static int save_Class_info(FILE *fd, u2 name_index)
{
	save_u1(fd, CONSTANT_Class);
	save_u2(fd, name_index);

	return 0;
}

static int save_Fieldref_info(FILE *fd, struct Pair p)
{
	save_u1(fd, CONSTANT_Fieldref);
	save_u2(fd, p.i);
	save_u2(fd, p.j);
	
	return 0;	
}

static int save_Methodref_info(FILE *fd, struct Pair p)
{
	save_u1(fd, CONSTANT_Methodref);
	save_u2(fd, p.i);
	save_u2(fd, p.j);
	
	return 0;	
}

static int save_NameAndType_info(FILE *fd, struct Pair p)
{
	save_u1(fd, CONSTANT_NameAndType);
	save_u2(fd, p.i);
	save_u2(fd, p.j);

	return 0;	
}

static int save_u1(FILE *fd, unsigned int n)
{
	fprintf(fd, "%c", (int)(n&0xFF));
	
	return 0;
}

static int save_u2(FILE *fd, unsigned int n)
{
	fprintf(fd, "%c%c", (int)((n>>8)&0xFF), (int)(n&0xFF));
	
	return 0;
}

static int save_u4(FILE *fd, unsigned int n)
{
	fprintf(fd, "%c%c%c%c", (int)((n>>24)&0xFF), (int)((n>>16)&0xFF), (int)((n>>8)&0xFF), (int)(n&0xFF));
	
	return 0;
}

