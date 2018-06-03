/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 3 "mycc.y"


#include "lex.yy.h"
#include "global.h"

#define MAXFUN 100
#define MAXFLD 100

static Type return_type;
static struct ClassFile cf;

/* stacks of symbol tables and offsets, depth is just 2 in C (global/local) */
static Table *tblptr[2];
static int offset[2];

/* stack pointers (index into tblptr[] and offset[]) */
static int tblsp = -1;
static int offsp = -1;

/* stack operations */
#define top_tblptr	(tblptr[tblsp])
#define top_offset	(offset[offsp])
#define push_tblptr(t)	(tblptr[++tblsp] = t)
#define push_offset(n)	(offset[++offsp] = n)
#define pop_tblptr	(tblsp--)
#define pop_offset	(offsp--)

/* flag to indicate we are compiling main's body (to differentiate 'return') */
static int is_in_main = 0;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 219 "mycc.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 232 "mycc.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   401

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,     2,    62,    49,    36,     2,
      56,    57,    47,    45,    61,    46,    54,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    60,
      37,    21,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    34,    59,    51,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    39,    40,
      41,    42,    43,    44,    52,    53,    55
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    13,    14,    20,    26,
      27,    31,    32,    37,    40,    41,    44,    46,    48,    50,
      52,    58,    62,    67,    71,    72,    74,    77,    78,    80,
      83,    90,   101,   110,   121,   138,   142,   145,   149,   152,
     156,   158,   162,   164,   168,   172,   176,   180,   184,   188,
     192,   196,   200,   204,   208,   212,   216,   219,   223,   226,
     229,   232,   235,   238,   240,   242,   244,   246,   248,   250,
     255,   256,   257
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,    65,    66,    -1,    -1,    66,    67,    -1,
      66,    73,    -1,    -1,    17,    56,    57,    68,    71,    -1,
      69,    70,    75,    57,    71,    -1,    -1,    74,     3,    56,
      -1,    -1,    58,    72,    78,    59,    -1,    72,    73,    -1,
      -1,    76,    60,    -1,    19,    -1,    16,    -1,    13,    -1,
      10,    -1,    75,    61,    74,    77,     3,    -1,    74,    77,
       3,    -1,    76,    61,    77,     3,    -1,    74,    77,     3,
      -1,    -1,    47,    -1,    78,    79,    -1,    -1,    60,    -1,
      81,    60,    -1,    15,    56,    81,    57,    83,    79,    -1,
      15,    56,    81,    57,    83,    79,    12,    84,    82,    79,
      -1,    20,    56,    82,    81,    57,    83,    79,    84,    -1,
      11,    82,    79,    20,    56,    81,    57,    83,    84,    60,
      -1,    14,    56,    81,    60,    82,    81,    83,    84,    60,
      82,    81,    84,    57,    82,    79,    84,    -1,    18,    81,
      60,    -1,     9,    60,    -1,    58,    78,    59,    -1,     1,
      60,    -1,    80,    61,    81,    -1,    81,    -1,     3,    21,
      81,    -1,     3,    -1,    81,    32,    81,    -1,    81,    33,
      81,    -1,    81,    42,    81,    -1,    81,    41,    81,    -1,
      81,    37,    81,    -1,    81,    38,    81,    -1,    81,    40,
      81,    -1,    81,    39,    81,    -1,    81,    45,    81,    -1,
      81,    46,    81,    -1,    81,    47,    81,    -1,    81,    48,
      81,    -1,    81,    49,    81,    -1,    50,    81,    -1,    56,
      81,    57,    -1,    62,     4,    -1,    53,     3,    -1,    52,
       3,    -1,     3,    53,    -1,     3,    52,    -1,     3,    -1,
       4,    -1,     5,    -1,     6,    -1,     7,    -1,     8,    -1,
       3,    56,    80,    57,    -1,    -1,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,    97,   102,   103,   104,   108,   148,   183,
     221,   223,   233,   236,   237,   240,   243,   244,   245,   246,
     249,   256,   264,   276,   291,   292,   295,   296,   300,   301,
     302,   304,   306,   308,   310,   312,   330,   333,   334,   337,
     338,   342,   386,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   418,   419,   420,   421,   422,   423,   424,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     449,   452,   457
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INT8", "INT16", "INT32", "FLT",
  "STR", "BREAK", "CHAR", "DO", "ELSE", "FLOAT", "FOR", "IF", "INT",
  "MAIN", "RETURN", "VOID", "WHILE", "'='", "RA", "LA", "OA", "XA", "AA",
  "MA", "DA", "TA", "NA", "PA", "OR", "AN", "'|'", "'^'", "'&'", "'<'",
  "'>'", "GE", "LE", "NE", "EQ", "RS", "LS", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'!'", "'~'", "NN", "PP", "'.'", "AR", "'('", "')'", "'{'", "'}'",
  "';'", "','", "'$'", "$accept", "prog", "Mprog", "exts", "func", "Mmain",
  "ftype", "Margs", "block", "decls", "decl", "type", "args", "list",
  "ptr", "stmts", "stmt", "exprs", "expr", "L", "M", "N", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    61,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   124,    94,    38,    60,    62,   288,
     289,   290,   291,   292,   293,    43,    45,    42,    47,    37,
      33,   126,   294,   295,    46,   296,    40,    41,   123,   125,
      59,    44,    36
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    66,    66,    66,    67,    67,    68,
      69,    70,    71,    72,    72,    73,    74,    74,    74,    74,
      75,    75,    76,    76,    77,    77,    78,    78,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      82,    83,    84
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     0,     5,     5,     0,
       3,     0,     4,     2,     0,     2,     1,     1,     1,     1,
       5,     3,     4,     3,     0,     1,     2,     0,     1,     2,
       6,    10,     8,    10,    16,     3,     2,     3,     2,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     4,
       0,     0,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     6,     1,     2,    19,    18,    17,     0,    16,
       4,    11,     5,     0,     0,     0,     0,     0,    25,     0,
      15,    24,     9,    24,     0,    10,    23,     0,     0,     0,
       0,     0,    22,    14,     7,    21,     8,    24,    27,     0,
      13,    24,     0,    20,     0,    42,    64,    65,    66,    67,
      68,     0,    70,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    12,    28,     0,    26,     0,    38,     0,    62,
      61,     0,    36,     0,     0,     0,     0,    70,    56,    60,
      59,     0,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    41,     0,
      40,     0,     0,     0,    35,     0,    57,    37,    43,    44,
      47,    48,    50,    49,    46,    45,    51,    52,    53,    54,
      55,    69,     0,     0,    70,    71,     0,    39,     0,     0,
       0,    71,     0,    71,    30,     0,    71,    72,    72,    72,
      72,     0,    70,    32,     0,    70,     0,    33,     0,    31,
      72,     0,    70,     0,    72,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,    10,    28,    11,    16,    34,    38,
      12,    13,    24,    14,    19,    42,    65,    99,    66,    73,
     130,   141
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -133
static const yytype_int16 yypact[] =
{
    -133,     9,  -133,  -133,    39,  -133,  -133,  -133,   -32,  -133,
    -133,  -133,  -133,    -2,   -46,   -30,   102,    -9,  -133,    45,
    -133,     7,  -133,     7,   -40,  -133,  -133,    61,    10,    67,
      10,   102,  -133,  -133,  -133,  -133,  -133,     7,   102,    68,
    -133,     7,    81,  -133,    15,   -10,  -133,  -133,  -133,  -133,
    -133,    17,  -133,    22,    24,   119,    25,   119,    88,    91,
     119,  -133,  -133,  -133,    93,  -133,   150,  -133,   119,  -133,
    -133,   119,  -133,   159,   119,   119,   190,  -133,  -133,  -133,
    -133,   238,    99,  -133,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,  -133,   322,    -4,
     322,    78,   214,   259,  -133,   119,  -133,  -133,   339,   352,
     155,   155,   155,   155,   155,   155,    14,    14,  -133,  -133,
    -133,  -133,   119,    53,  -133,  -133,   280,   322,   119,   119,
     159,  -133,   301,   322,   104,   159,  -133,  -133,  -133,  -133,
    -133,    51,  -133,  -133,    60,  -133,   159,  -133,   119,  -133,
     322,    71,  -133,   159,  -133,  -133
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,   100,  -133,
      94,    28,  -133,  -133,   -11,    74,   -70,  -133,   -55,   -73,
    -108,  -132
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      76,    17,    78,   101,   105,    81,   142,   143,   144,     3,
      27,    68,    29,    98,    20,    21,   100,    30,   151,   102,
     103,    31,   155,   135,    15,   137,    39,    22,   140,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    69,    70,    23,    18,    71,    25,    26,     5,
     126,   129,     6,   121,    18,     7,     8,   122,     9,    37,
     134,    94,    95,    96,    32,   139,    41,   127,    33,   146,
      35,    43,   148,   132,   133,    67,   149,    72,    74,   153,
      75,    77,    44,   154,    45,    46,    47,    48,    49,    50,
      51,    79,    52,   150,    80,    53,    54,    83,   123,    55,
      44,    56,    45,    46,    47,    48,    49,    50,    51,   128,
      52,   145,     5,    53,    54,     6,   138,    55,     7,    56,
     147,     9,    45,    46,    47,    48,    49,    50,   152,     0,
      36,    57,    40,    58,    59,    82,     0,    60,     0,    61,
      62,    63,     0,    64,     0,     0,     0,     0,     0,    57,
       0,    58,    59,     0,     0,    60,     0,    61,   107,    63,
      44,    64,    45,    46,    47,    48,    49,    50,    51,    57,
      52,    58,    59,    53,    54,    60,     0,    55,     0,    56,
       0,    64,    84,    85,     0,     0,     0,    86,    87,    88,
      89,    90,    91,     0,     0,    92,    93,    94,    95,    96,
      92,    93,    94,    95,    96,     0,     0,     0,     0,    57,
      97,    58,    59,     0,     0,    60,     0,    61,     0,    63,
       0,    64,    84,    85,     0,     0,     0,    86,    87,    88,
      89,    90,    91,     0,     0,    92,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,    84,    85,     0,     0,
     104,    86,    87,    88,    89,    90,    91,     0,     0,    92,
      93,    94,    95,    96,     0,     0,     0,     0,     0,     0,
      84,    85,     0,     0,   124,    86,    87,    88,    89,    90,
      91,     0,     0,    92,    93,    94,    95,    96,     0,     0,
       0,    84,    85,     0,     0,   106,    86,    87,    88,    89,
      90,    91,     0,     0,    92,    93,    94,    95,    96,     0,
       0,     0,    84,    85,     0,     0,   125,    86,    87,    88,
      89,    90,    91,     0,     0,    92,    93,    94,    95,    96,
       0,     0,     0,    84,    85,     0,     0,   131,    86,    87,
      88,    89,    90,    91,     0,     0,    92,    93,    94,    95,
      96,     0,     0,     0,    84,    85,     0,     0,   136,    86,
      87,    88,    89,    90,    91,     0,     0,    92,    93,    94,
      95,    96,    85,     0,     0,     0,    86,    87,    88,    89,
      90,    91,     0,     0,    92,    93,    94,    95,    96,    86,
      87,    88,    89,    90,    91,     0,     0,    92,    93,    94,
      95,    96
};

static const yytype_int16 yycheck[] =
{
      55,     3,    57,    73,    77,    60,   138,   139,   140,     0,
      21,    21,    23,    68,    60,    61,    71,    57,   150,    74,
      75,    61,   154,   131,    56,   133,    37,    57,   136,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    52,    53,    16,    47,    56,    56,     3,    10,
     105,   124,    13,    57,    47,    16,    17,    61,    19,    31,
     130,    47,    48,    49,     3,   135,    38,   122,    58,   142,
       3,     3,   145,   128,   129,    60,   146,    60,    56,   152,
      56,    56,     1,   153,     3,     4,     5,     6,     7,     8,
       9,     3,    11,   148,     3,    14,    15,     4,    20,    18,
       1,    20,     3,     4,     5,     6,     7,     8,     9,    56,
      11,    60,    10,    14,    15,    13,    12,    18,    16,    20,
      60,    19,     3,     4,     5,     6,     7,     8,    57,    -1,
      30,    50,    38,    52,    53,    61,    -1,    56,    -1,    58,
      59,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    52,    53,    -1,    -1,    56,    -1,    58,    59,    60,
       1,    62,     3,     4,     5,     6,     7,     8,     9,    50,
      11,    52,    53,    14,    15,    56,    -1,    18,    -1,    20,
      -1,    62,    32,    33,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    42,    -1,    -1,    45,    46,    47,    48,    49,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    50,
      60,    52,    53,    -1,    -1,    56,    -1,    58,    -1,    60,
      -1,    62,    32,    33,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    42,    -1,    -1,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    -1,    -1,
      60,    37,    38,    39,    40,    41,    42,    -1,    -1,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    -1,    -1,    60,    37,    38,    39,    40,    41,
      42,    -1,    -1,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    32,    33,    -1,    -1,    57,    37,    38,    39,    40,
      41,    42,    -1,    -1,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    32,    33,    -1,    -1,    57,    37,    38,    39,
      40,    41,    42,    -1,    -1,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    32,    33,    -1,    -1,    57,    37,    38,
      39,    40,    41,    42,    -1,    -1,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    32,    33,    -1,    -1,    57,    37,
      38,    39,    40,    41,    42,    -1,    -1,    45,    46,    47,
      48,    49,    33,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    -1,    -1,    45,    46,    47,    48,    49,    37,
      38,    39,    40,    41,    42,    -1,    -1,    45,    46,    47,
      48,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    64,    65,     0,    66,    10,    13,    16,    17,    19,
      67,    69,    73,    74,    76,    56,    70,     3,    47,    77,
      60,    61,    57,    74,    75,    56,     3,    77,    68,    77,
      57,    61,     3,    58,    71,     3,    71,    74,    72,    77,
      73,    74,    78,     3,     1,     3,     4,     5,     6,     7,
       8,     9,    11,    14,    15,    18,    20,    50,    52,    53,
      56,    58,    59,    60,    62,    79,    81,    60,    21,    52,
      53,    56,    60,    82,    56,    56,    81,    56,    81,     3,
       3,    81,    78,     4,    32,    33,    37,    38,    39,    40,
      41,    42,    45,    46,    47,    48,    49,    60,    81,    80,
      81,    79,    81,    81,    60,    82,    57,    59,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    57,    61,    20,    60,    57,    81,    81,    56,    82,
      83,    57,    81,    81,    79,    83,    57,    83,    12,    79,
      83,    84,    84,    84,    84,    60,    82,    60,    82,    79,
      81,    84,    57,    82,    79,    84
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 91 "mycc.y"
    { addwidth(top_tblptr, top_offset);
			  pop_tblptr;
			  pop_offset;
			}
    break;

  case 3:
#line 97 "mycc.y"
    { push_tblptr(mktable(NULL));
			  push_offset(0);
			}
    break;

  case 7:
#line 109 "mycc.y"
    { // need a temporary table pointer
			  Table *table;
			  // the type of main is a JVM type descriptor
			  Type type = mkfun("[Ljava/lang/String;", "V");
			  // emit the epilogue part of main()
			  emit3(getstatic, constant_pool_add_Fieldref(&cf, "java/lang/System", "out", "Ljava/io/PrintStream;"));
			  emit(iload_2);
			  emit3(invokevirtual, constant_pool_add_Methodref(&cf, "java/io/PrintStream", "println", "(I)V"));
			  emit(return_);
			  // method has public access and is static
			  cf.methods[cf.method_count].access = (enum access_flags)(ACC_PUBLIC | ACC_STATIC);
			  // method name is "main"
			  cf.methods[cf.method_count].name = "main";
			  // method descriptor of "void main(String[] arg)"
			  cf.methods[cf.method_count].descriptor = type;
			  // local variables
			  cf.methods[cf.method_count].max_locals = top_offset;
			  // max operand stack size of this method
			  cf.methods[cf.method_count].max_stack = 100;
			  // length of bytecode is in the emitter's pc variable
			  cf.methods[cf.method_count].code_length = pc;
			  // must copy code to make it persistent
			  cf.methods[cf.method_count].code = copy_code();
			  if (!cf.methods[cf.method_count].code)
				error("Out of memory");
			  // advance to next method to store in method array
			  cf.method_count++;
			  if (cf.method_count > MAXFUN)
			  	error("Max number of functions exceeded");
			  // add width information to table
			  addwidth(top_tblptr, top_offset);
			  // need this table of locals for enterproc
			  table = top_tblptr;
			  // exit the local scope by popping
			  pop_tblptr;
			  pop_offset;
			  // enter the function in the global table
			  enterproc(top_tblptr, (yyvsp[(1) - (5)].sym), type, table);
			}
    break;

  case 8:
#line 149 "mycc.y"
    {
               Table *table;
  			  // the type of function is gived by $1, args by $6
                Type type = mkfun((yyvsp[(3) - (5)].typ), return_type);
                // method has public access and is static
                cf.methods[cf.method_count].access = (enum access_flags)(ACC_PUBLIC | ACC_STATIC);
                cf.methods[cf.method_count].name = (yyvsp[(1) - (5)].sym)->lexptr;
                cf.methods[cf.method_count].descriptor = type;
                // local variables
                cf.methods[cf.method_count].max_locals = top_offset;
                // max operand stack size of this method
                cf.methods[cf.method_count].max_stack = 100;
                // length of bytecode is in the emitter's pc variable
                cf.methods[cf.method_count].code_length = pc;
                // must copy code to make it persistent
                cf.methods[cf.method_count].code = copy_code();
                if (!cf.methods[cf.method_count].code)
                  error("Out of memory");
                // advance to next method to store in method array
                cf.method_count++;
                if (cf.method_count > MAXFUN)
                  error("Max number of functions exceeded");
                // add width information to table
                addwidth(top_tblptr, top_offset);
                // need this table of locals for enterproc
                table = top_tblptr;
                // exit the local scope by popping
                pop_tblptr;
                pop_offset;
                // enter the function in the global table
                enterproc(top_tblptr, (yyvsp[(1) - (5)].sym), type, table);
			}
    break;

  case 9:
#line 183 "mycc.y"
    { int label1, label2;
			  Table *table;
			  // create new table for local scope of main()
			  table = mktable(top_tblptr);
			  // push it to create new scope
			  push_tblptr(table);
			  // for main(), we must start with offset 3 in the local variables of the frame
			  push_offset(3);
			  // init code block to store stmts
			  init_code();
			  // emit the prologue part of main()
			  emit(aload_0);
			  emit(arraylength);
			  emit2(newarray, T_INT);
			  emit(astore_1);
			  emit(iconst_0);
			  emit(istore_2);
			  label1 = pc;
			  emit(iload_2);
			  emit(aload_0);
			  emit(arraylength);
			  label2 = pc;
			  emit3(if_icmpge, PAD);
			  emit(aload_1);
			  emit(iload_2);
			  emit(aload_0);
			  emit(iload_2);
			  emit(aaload);
			  emit3(invokestatic, constant_pool_add_Methodref(&cf, "java/lang/Integer", "parseInt", "(Ljava/lang/String;)I"));
			  emit(iastore);
			  emit32(iinc, 2, 1);
			  emit3(goto_, label1 - pc);
			  backpatch(label2, pc - label2);
			  // global flag to indicate we're in main()
			  is_in_main = 1;
			}
    break;

  case 10:
#line 221 "mycc.y"
    { return_type = (yyvsp[(1) - (3)].typ); (yyval.sym) = (yyvsp[(2) - (3)].sym);}
    break;

  case 11:
#line 223 "mycc.y"
    { /* TASK 3: TO BE COMPLETED */
    // add code to create new table and push on tblptr and push offset 0
        Table * table = mktable(top_tblptr);
        push_tblptr(table);
        push_offset(0);
			  init_code();
			  is_in_main = 0;
			}
    break;

  case 16:
#line 243 "mycc.y"
    { (yyval.typ) = mkvoid(); }
    break;

  case 17:
#line 244 "mycc.y"
    { (yyval.typ) = mkint(); }
    break;

  case 18:
#line 245 "mycc.y"
    { (yyval.typ) = mkfloat(); }
    break;

  case 19:
#line 246 "mycc.y"
    { (yyval.typ) = mkchar(); }
    break;

  case 20:
#line 250 "mycc.y"
    { if ((yyvsp[(4) - (5)].num) && ischar((yyvsp[(3) - (5)].typ)))
				enter(top_tblptr, (yyvsp[(5) - (5)].sym), mkstr(), top_offset++);
			  else
				enter(top_tblptr, (yyvsp[(5) - (5)].sym), (yyvsp[(3) - (5)].typ), top_offset++);
			  (yyval.typ) = mkpair((yyvsp[(1) - (5)].typ), (yyvsp[(3) - (5)].typ));
			}
    break;

  case 21:
#line 256 "mycc.y"
    { if ((yyvsp[(2) - (3)].num) && ischar((yyvsp[(1) - (3)].typ)))
				    enter(top_tblptr, (yyvsp[(3) - (3)].sym), mkstr(), top_offset++);
			 else
				enter(top_tblptr, (yyvsp[(3) - (3)].sym), (yyvsp[(1) - (3)].typ), top_offset++);
			  (yyval.typ) = (yyvsp[(1) - (3)].typ);
			}
    break;

  case 22:
#line 265 "mycc.y"
    { if (top_tblptr->level == 0){
                    cf.fields[cf.field_count].access = ACC_STATIC;
                    cf.fields[cf.field_count].name = (yyvsp[(4) - (4)].sym)->lexptr;
                    cf.fields[cf.field_count].descriptor = (yyvsp[(1) - (4)].typ);
                    cf.field_count++;
                    enter(top_tblptr, (yyvsp[(4) - (4)].sym), (yyvsp[(1) - (4)].typ), constant_pool_add_Fieldref(&cf, cf.name, (yyvsp[(4) - (4)].sym)->lexptr, (yyvsp[(1) - (4)].typ)));
              }else{
                  enter(top_tblptr, (yyvsp[(4) - (4)].sym), (yyvsp[(1) - (4)].typ), top_offset++);
			      (yyval.typ) = (yyvsp[(1) - (4)].typ);
              }
			}
    break;

  case 23:
#line 276 "mycc.y"
    {
        if (top_tblptr->level == 0){
            cf.fields[cf.field_count].access = ACC_STATIC;
            cf.fields[cf.field_count].name = (yyvsp[(3) - (3)].sym)->lexptr;
            cf.fields[cf.field_count].descriptor = (yyvsp[(1) - (3)].typ);
            cf.field_count++;
            enter(top_tblptr, (yyvsp[(3) - (3)].sym), (yyvsp[(1) - (3)].typ), constant_pool_add_Fieldref(&cf, cf.name, (yyvsp[(3) - (3)].sym)->lexptr, (yyvsp[(1) - (3)].typ)));
        }
	    else{
            enter(top_tblptr, (yyvsp[(3) - (3)].sym), (yyvsp[(1) - (3)].typ), top_offset++);
            (yyval.typ) = (yyvsp[(1) - (3)].typ);
        }
	}
    break;

  case 24:
#line 291 "mycc.y"
    { (yyval.num) = 0; }
    break;

  case 25:
#line 292 "mycc.y"
    { (yyval.num) = 1; }
    break;

  case 29:
#line 301 "mycc.y"
    { emit(pop); }
    break;

  case 30:
#line 303 "mycc.y"
    { backpatch((yyvsp[(5) - (6)].loc), pc - (yyvsp[(5) - (6)].loc)); emit3(goto_, 3); }
    break;

  case 31:
#line 305 "mycc.y"
    { backpatch((yyvsp[(5) - (10)].loc), (yyvsp[(9) - (10)].loc) - (yyvsp[(5) - (10)].loc)); emit3(goto_, 3); backpatch((yyvsp[(8) - (10)].loc), pc - (yyvsp[(8) - (10)].loc));}
    break;

  case 32:
#line 307 "mycc.y"
    { backpatch((yyvsp[(6) - (8)].loc), pc - (yyvsp[(6) - (8)].loc)); backpatch((yyvsp[(8) - (8)].loc), (yyvsp[(3) - (8)].loc)-(yyvsp[(8) - (8)].loc)); }
    break;

  case 33:
#line 309 "mycc.y"
    { backpatch((yyvsp[(8) - (10)].loc), pc - (yyvsp[(8) - (10)].loc));  backpatch((yyvsp[(9) - (10)].loc), (yyvsp[(2) - (10)].loc)-(yyvsp[(9) - (10)].loc));}
    break;

  case 34:
#line 311 "mycc.y"
    { backpatch((yyvsp[(8) - (16)].loc), pc - (yyvsp[(8) - (16)].loc)); backpatch((yyvsp[(8) - (16)].loc), (yyvsp[(14) - (16)].loc) - (yyvsp[(8) - (16)].loc)); backpatch((yyvsp[(16) - (16)].loc), (yyvsp[(10) - (16)].loc)-(yyvsp[(16) - (16)].loc)); backpatch((yyvsp[(12) - (16)].loc), (yyvsp[(5) - (16)].loc)-(yyvsp[(12) - (16)].loc)  ); }
    break;

  case 35:
#line 313 "mycc.y"
    {
                            if (is_in_main)
                            {
                                emit(dup);
                                emit(istore_2);
                                emit3(goto_, 0);
                            }
                            else if (isint(return_type) && isint((yyvsp[(2) - (3)].exp).type)){
                                emit(ireturn);
                            }else if (isfloat(return_type) && isfloat((yyvsp[(2) - (3)].exp).type)){
                                emit(freturn);
                            }else if (isstr(return_type) && isstr((yyvsp[(2) - (3)].exp).type)){
                                emit(areturn);
                            }else{
                                error("Type error");
                            }
                        }
    break;

  case 36:
#line 330 "mycc.y"
    { /* BREAK is optional to implement (see Pr3) */
			  error("break not implemented");
			}
    break;

  case 38:
#line 334 "mycc.y"
    { yyerrok; }
    break;

  case 41:
#line 342 "mycc.y"
    {   int place;
                            Type type;
                            place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                            if (isint(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                            {
                                if (isfloat((yyvsp[(3) - (3)].exp).type)){
                                    emit(f2i);
                                }
                                if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 0){
                                    emit(dup);
                                    emit3(putstatic, place);
                                }else{
                                    emit(dup);
                                    emit2(istore, place);
                                }
                            }
                            else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                            {
                                if (isint((yyvsp[(3) - (3)].exp).type)){
                                    emit(i2f);
                                }if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 0){
                                    emit(dup);
                                    emit3(putstatic, place);
                                }else{
                                    emit(dup);
                                    emit2(fstore, place);
                                }
                            }
                            else if (isstr(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))) && isstr((yyvsp[(3) - (3)].exp).type))
                            {
                                if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 0){
                                    emit(dup);
                                    emit3(putstatic, place);
                                }else{
                                    emit(dup);
                                    emit2(astore, place);
                                }
                            }
                            else
                                error("Type error");
                            (yyval.exp).type = (yyvsp[(3) - (3)].exp).type;


                        }
    break;

  case 42:
#line 386 "mycc.y"
    {int place;
              Type type;
              if (getlevel(top_tblptr, (yyvsp[(1) - (1)].sym)) == 0){
                  emit3(getstatic, getplace(top_tblptr, (yyvsp[(1) - (1)].sym)));
              }
              if(getlevel(top_tblptr, (yyvsp[(1) - (1)].sym)) == 1){
                  place = getplace(top_tblptr, (yyvsp[(1) - (1)].sym));
                  type = gettype(top_tblptr, (yyvsp[(1) - (1)].sym));
                  if(isint(type)){emit2(iload, place);}
                  if(isfloat(type)){emit2(fload, place);}
              }
        }
    break;

  case 43:
#line 398 "mycc.y"
    { emit(ior);  }
    break;

  case 44:
#line 399 "mycc.y"
    { emit(iand);  }
    break;

  case 45:
#line 400 "mycc.y"
    { emit3(if_icmpeq, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
    break;

  case 46:
#line 401 "mycc.y"
    { emit3(if_icmpne, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
    break;

  case 47:
#line 402 "mycc.y"
    { emit3(if_icmplt, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
    break;

  case 48:
#line 403 "mycc.y"
    { emit3(if_icmpgt, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
    break;

  case 49:
#line 404 "mycc.y"
    { emit3(if_icmple, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
    break;

  case 50:
#line 405 "mycc.y"
    { emit3(if_icmpge, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
    break;

  case 51:
#line 406 "mycc.y"
    {
            if (iseq((yyvsp[(1) - (3)].exp).type, (yyvsp[(3) - (3)].exp).type))
            {
                if (isint((yyvsp[(1) - (3)].exp).type))
                    emit(iadd);
                else
                    emit(fadd);
            }
            else
                error("Type error");
            (yyval.exp).type = (yyvsp[(1) - (3)].exp).type;
        }
    break;

  case 52:
#line 418 "mycc.y"
    { emit(isub); }
    break;

  case 53:
#line 419 "mycc.y"
    { emit(imul); }
    break;

  case 54:
#line 420 "mycc.y"
    { emit(idiv); }
    break;

  case 55:
#line 421 "mycc.y"
    { /* TODO: TO BE COMPLETED */ error("% operator not implemented"); }
    break;

  case 56:
#line 422 "mycc.y"
    { emit(ineg); }
    break;

  case 58:
#line 424 "mycc.y"
    { // check that we are in main()
			  if (is_in_main)
			  {	emit(aload_1);
			  	emit2(bipush, (yyvsp[(2) - (2)].num));
			  	emit(iaload);
			  }
			  else
			  	error("invalid use of $# in function");
			}
    break;

  case 59:
#line 433 "mycc.y"
    {  emit(iadd); emit(iconst_1); }
    break;

  case 60:
#line 434 "mycc.y"
    { emit(isub); emit(iconst_1); }
    break;

  case 61:
#line 435 "mycc.y"
    { emit(iadd); emit(iconst_1); }
    break;

  case 62:
#line 436 "mycc.y"
    { emit(isub); emit(iconst_1);}
    break;

  case 63:
#line 437 "mycc.y"
    { emit2(iload,  getplace(top_tblptr, (yyvsp[(1) - (1)].sym))); }
    break;

  case 64:
#line 438 "mycc.y"
    { emit2(bipush, (yyvsp[(1) - (1)].num)); }
    break;

  case 65:
#line 439 "mycc.y"
    { emit3(sipush, (yyvsp[(1) - (1)].num)); }
    break;

  case 66:
#line 440 "mycc.y"
    { emit2(ldc, constant_pool_add_Integer(&cf, (yyvsp[(1) - (1)].num))); }
    break;

  case 67:
#line 441 "mycc.y"
    { emit2(ldc, constant_pool_add_Float(&cf, (yyvsp[(1) - (1)].flt))); }
    break;

  case 68:
#line 442 "mycc.y"
    { emit2(ldc, constant_pool_add_String(&cf, constant_pool_add_Utf8(&cf, (yyvsp[(1) - (1)].str)))); }
    break;

  case 69:
#line 443 "mycc.y"
    {(yyval.exp).type = mkret(gettype(top_tblptr, (yyvsp[(1) - (4)].sym))); emit3(invokestatic, constant_pool_add_Methodref(&cf, cf.name, (yyvsp[(1) - (4)].sym)->lexptr, gettype(top_tblptr, (yyvsp[(1) - (4)].sym)))); }
    break;

  case 70:
#line 449 "mycc.y"
    { (yyval.loc) = pc; }
    break;

  case 71:
#line 452 "mycc.y"
    { (yyval.loc) = pc;	/* location of inst. to backpatch */
			  emit3(ifeq, 0);
			}
    break;

  case 72:
#line 457 "mycc.y"
    { (yyval.loc) = pc;	/* location of inst. to backpatch */
			  emit3(goto_, 0);
			}
    break;


/* Line 1267 of yacc.c.  */
#line 2138 "mycc.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 465 "mycc.y"


int main(int argc, char **argv)
{
	// init the compiler
	init();

	// set up a new class file structure
	init_ClassFile(&cf);

	// class has public access
	cf.access = ACC_PUBLIC;

	// class name is "Code"
	cf.name = "Code";

	// field counter (incremented for each field we add)
	cf.field_count = 0;

	// method counter (incremented for each method we add)
	cf.method_count = 0;

	// allocate an array of MAXFLD fields
	cf.fields = (struct FieldInfo*)malloc(MAXFLD * sizeof(struct FieldInfo));

	// allocate an array of MAXFUN methods
	cf.methods = (struct MethodInfo*)malloc(MAXFUN * sizeof(struct MethodInfo));

	if (!cf.methods)
		error("Out of memory");

	if (argc > 1)
		if (!(yyin = fopen(argv[1], "r")))
			error("Cannot open file for reading");

	if (yyparse() || errnum > 0)
		error("Compilation errors: class file not saved");

	fprintf(stderr, "Compilation successful: saving %s.class\n", cf.name);

	// save class file
	save_classFile(&cf);

	return 0;
}

