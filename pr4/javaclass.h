/*
 *  javaclass.h
 *  
 *  Java ClassFile struct
 *  
 *
 *  Created by Robert van Engelen on 1/2/05, updated 11/22/13.
 *  Copyright 2005 Robert van Engelen. All rights reserved.
 *
 */

#ifndef JAVACLASS_H
#define JAVACLASS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// The value of the access_flags item is a mask of flags used to denote access permissions to and properties of a class, interface, field, or method. 
enum access_flags
{
	ACC_PUBLIC	= 0x0001,	// Declared public; may be accessed from outside its package.
	ACC_PRIVATE	= 0x0002,	// Declared private; usable only within the defining class.
	ACC_PROTECTED	= 0x0004,	// Declared protected; may be accessed within subclasses.
	ACC_STATIC	= 0x0008,	// Declared static.
	ACC_FINAL	= 0x0010,	// Declared final; no subclasses allowed or no further assignment after initialization.
	ACC_SUPER	= 0x0020,	// Treat superclass methods specially when invoked by the invokespecial instruction.
	ACC_VOLATILE	= 0x0040,	// Declared volatile; cannot be cached.
	ACC_TRANSIENT	= 0x0080,	// Declared transient; not written or read by a persistent object manager.
	ACC_INTERFACE	= 0x0200,	// Is an interface, not a class
	ACC_ABSTRACT	= 0x0400,	// Declared abstract; may not be instantiated.
};

// Each item in the constant_pool table must begin with a 1-byte tag constant_type indicating the kind of cp_info entry.
enum constant_type
{
	CONSTANT_Utf8			= 1,
	CONSTANT_Integer		= 3,
	CONSTANT_Float			= 4,
	CONSTANT_Long			= 5,
	CONSTANT_Double			= 6,
	CONSTANT_Class			= 7,
	CONSTANT_String			= 8,
	CONSTANT_Fieldref		= 9,
	CONSTANT_Methodref		= 10,
	CONSTANT_InterfaceMethodref	= 11,
	CONSTANT_NameAndType		= 12,
};

typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;

// The Java Class File (in simplified form)
struct ClassFile
{
	enum access_flags	access;
	const char		*name;
	u2			constant_pool_count;
	struct ConstantPool	*constant_pool;
	u2			field_count;
	struct FieldInfo	*fields;
	u2			method_count;
	struct MethodInfo	*methods;
};

// The constant pool may contain pairs of references
struct Pair
{
	u2			i, j;
};

// The Java class constant pool (in simplified form)
struct ConstantPool
{
	u1			tag;
	union
	{
		const char	*u;		// utf8 string
		u4		i;		// unsigned int
		float		f;
		// long long			// for future extensions
		// double			// for future extensions
		u2		r;		// reference (pool index)
		struct Pair	t;		// tuple of references
	}			data;
	struct ConstantPool	*next;
};

// Java class field information
struct FieldInfo
{
	enum access_flags	access;
	const char		*name;
	const char		*descriptor;
};

// Java class method information
struct MethodInfo
{
	enum access_flags	access;
	const char		*name;
	const char		*descriptor;
	u2			max_stack;
	u2			max_locals;
	u4			code_length;
	u1			*code;
};

// Bytecode emitter's global pc
extern int pc;

void init_code();
u1 *copy_code();
int emit(u1 opcode);
int emit2(u1 opcode, u1 operand);
int emit3(u1 opcode, u2 operand);
int emit32(u1 opcode, u1 operand1, u1 operand2);
int backpatch(u2 loc, int offset);

int init_ClassFile(struct ClassFile *cf);
int save_classFile(struct ClassFile *cf);

int constant_pool_add_Utf8(struct ClassFile *cf, const char *name);
int constant_pool_add_Integer(struct ClassFile *cf, u4 i);
int constant_pool_add_Float(struct ClassFile *cf, float f);
int constant_pool_add_String(struct ClassFile *cf, u2 i);
int constant_pool_add_Class(struct ClassFile *cf, const char *name);
int constant_pool_add_Fieldref(struct ClassFile *cf, const char *class_name, const char *field_name, const char *descriptor);
int constant_pool_add_Methodref(struct ClassFile *cf, const char *class_name, const char *method_name, const char *descriptor);
int constant_pool_add_NameAndType(struct ClassFile *cf, const char *name, const char *descriptor);

#endif
