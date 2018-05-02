/*
 *  bytecode.c
 *  
 *  Emitter of Java bytecode
 *  
 *
 *  Created by Robert van Engelen on 1/2/05.
 *  Copyright 2005 Robert van Engelen. All rights reserved.
 *
 */

#include "javaclass.h"
#include "bytecode.h"

static u1 codebuf[65536];	// a static buffer to store code

int pc = -1;			// global counter and index to codebuf[]

// Initialize the emitter
void init_code()
{
	pc = 0;
}

// Copy the emitted code to a persistent region and return pointer to that region
u1 *copy_code()
{
	u1 *code = (u1*)malloc(pc);

	if (code)
		memcpy(code, codebuf, pc);

	return code;
}

// Emit byte
int emit(u1 opcode)
{
	if (pc < 0 || pc >= 65536)
		return 1;

	codebuf[pc++] = opcode;

	return 0;
}

// Emit 2 bytes
int emit2(u1 opcode, u1 operand)
{
	if (pc < 0 || pc >= 65535)
		return 1;

	codebuf[pc++] = opcode;
	codebuf[pc++] = operand;

	return 0;
}

// Emit 3 bytes, one short operand
int emit3(u1 opcode, u2 operand)
{
	return emit32(opcode, HI(operand), LO(operand));
}

// Emit 3 bytes, double operand
int emit32(u1 opcode, u1 operand1, u1 operand2)
{
	if (pc < 0 || pc >= 65534)
		return 1;
		
	codebuf[pc++] = opcode;
	codebuf[pc++] = operand1;
	codebuf[pc++] = operand2;

	return 0;
}

// Backpatch the location loc with the value of offset for branch instructions
int backpatch(u2 loc, int offset)
{
	if (loc + offset < 0 || loc + offset >= 65534)
		return 1;

	codebuf[loc + 1] = HI(offset);
	codebuf[loc + 2] = LO(offset);

	return 0;
}

