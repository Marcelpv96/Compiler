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
    DO = 265,
    ELSE = 266,
    FOR = 267,
    IF = 268,
    RETURN = 269,
    WHILE = 270,
    PA = 271,
    NA = 272,
    TA = 273,
    DA = 274,
    MA = 275,
    AA = 276,
    XA = 277,
    OA = 278,
    LA = 279,
    RA = 280,
    OR = 281,
    AN = 282,
    EQ = 283,
    NE = 284,
    LE = 285,
    GE = 286,
    LS = 287,
    RS = 288,
    AR = 289,
    PP = 290,
    NN = 291
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
#define DO 265
#define ELSE 266
#define FOR 267
#define IF 268
#define RETURN 269
#define WHILE 270
#define PA 271
#define NA 272
#define TA 273
#define DA 274
#define MA 275
#define AA 276
#define XA 277
#define OA 278
#define LA 279
#define RA 280
#define OR 281
#define AN 282
#define EQ 283
#define NE 284
#define LE 285
#define GE 286
#define LS 287
#define RS 288
#define AR 289
#define PP 290
#define NN 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 13 "mycc.y" /* yacc.c:1909  */
 Symbol *sym;  /* token value yylval.sym is the symbol table entry of an ID */
  unsigned num; /* token value yylval.num is the value of an int constant */
  float flt;    /* token value yylval.flt is the value of a float constant */
  char *str;    /* token value yylval.str is the value of a string constant */
  unsigned loc; /* location of instruction to backpatch */

#line 133 "mycc.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MYCC_H_INCLUDED  */
