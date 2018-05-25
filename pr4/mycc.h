/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_MYCC_H_INCLUDED
# define YY_YY_MYCC_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    PA = 276,
    NA = 277,
    TA = 278,
    DA = 279,
    MA = 280,
    AA = 281,
    XA = 282,
    OA = 283,
    LA = 284,
    RA = 285,
    OR = 286,
    AN = 287,
    EQ = 288,
    NE = 289,
    LE = 290,
    GE = 291,
    LS = 292,
    RS = 293,
    PP = 294,
    NN = 295,
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
#define PA 276
#define NA 277
#define TA 278
#define DA 279
#define MA 280
#define AA 281
#define XA 282
#define OA 283
#define LA 284
#define RA 285
#define OR 286
#define AN 287
#define EQ 288
#define NE 289
#define LE 290
#define GE 291
#define LS 292
#define RS 293
#define PP 294
#define NN 295
#define AR 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 36 "mycc.y" /* yacc.c:1909  */
 Symbol *sym;  /* token value yylval.sym is the symbol table entry of an ID */
  unsigned num; /* token value yylval.num is the value of an int constant */
  float flt;    /* token value yylval.flt is the value of a float constant */
  char *str;    /* token value yylval.str is the value of a string constant */
  unsigned loc; /* location of instruction to backpatch */
  Type typ;	/* type descriptor */

#line 144 "mycc.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MYCC_H_INCLUDED  */
