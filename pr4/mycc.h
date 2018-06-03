/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     INT8 = 259,
     INT16 = 260,
     INT32 = 261,
     FLT = 262,
     STR = 263,
     BREAK = 264,
     CHAR = 265,
     DO = 266,
     ELSE = 267,
     FLOAT = 268,
     FOR = 269,
     IF = 270,
     INT = 271,
     MAIN = 272,
     RETURN = 273,
     VOID = 274,
     WHILE = 275,
     RA = 276,
     LA = 277,
     OA = 278,
     XA = 279,
     AA = 280,
     MA = 281,
     DA = 282,
     TA = 283,
     NA = 284,
     PA = 285,
     OR = 286,
     AN = 287,
     GE = 288,
     LE = 289,
     NE = 290,
     EQ = 291,
     RS = 292,
     LS = 293,
     NN = 294,
     PP = 295,
     AR = 296
   };
#endif
/* Tokens.  */
#define ID 258
#define INT8 259
#define INT16 260
#define INT32 261
#define FLT 262
#define STR 263
#define BREAK 264
#define CHAR 265
#define DO 266
#define ELSE 267
#define FLOAT 268
#define FOR 269
#define IF 270
#define INT 271
#define MAIN 272
#define RETURN 273
#define VOID 274
#define WHILE 275
#define RA 276
#define LA 277
#define OA 278
#define XA 279
#define AA 280
#define MA 281
#define DA 282
#define TA 283
#define NA 284
#define PA 285
#define OR 286
#define AN 287
#define GE 288
#define LE 289
#define NE 290
#define EQ 291
#define RS 292
#define LS 293
#define NN 294
#define PP 295
#define AR 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 37 "mycc.y"
{ Symbol *sym;  /* token value yylval.sym is the symbol table entry of an ID */
  unsigned num; /* token value yylval.num is the value of an int constant */
  float flt;    /* token value yylval.flt is the value of a float constant */
  char *str;    /* token value yylval.str is the value of a string constant */
  unsigned loc; /* location of instruction to backpatch */
  Type typ;	/* type descriptor */
  Expr exp;
}
/* Line 1529 of yacc.c.  */
#line 140 "mycc.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

