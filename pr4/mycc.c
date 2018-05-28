/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "mycc.y" /* yacc.c:339  */


#include "lex.yy.h"
#include "global.h"

#define MAXFUN 100
#define MAXFLD 100

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


#line 97 "mycc.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "mycc.h".  */
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

union YYSTYPE
{
#line 36 "mycc.y" /* yacc.c:355  */
 Symbol *sym;  /* token value yylval.sym is the symbol table entry of an ID */
  unsigned num; /* token value yylval.num is the value of an int constant */
  float flt;    /* token value yylval.flt is the value of a float constant */
  char *str;    /* token value yylval.str is the value of a string constant */
  unsigned loc; /* location of instruction to backpatch */
  Type typ;	/* type descriptor */

#line 227 "mycc.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MYCC_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 244 "mycc.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   400

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,     2,    62,    49,    36,     2,
      56,    57,    47,    45,    61,    46,    54,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    60,
      40,    21,    42,     2,     2,     2,     2,     2,     2,     2,
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
      26,    27,    28,    29,    30,    31,    32,    33,    37,    38,
      39,    41,    43,    44,    52,    53,    55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    91,    96,    97,    98,   101,   112,   152,
     188,   226,   236,   239,   240,   243,   246,   247,   248,   249,
     252,   259,   267,   274,   281,   282,   285,   286,   290,   291,
     292,   294,   296,   298,   300,   302,   308,   311,   312,   315,
     316,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   364,
     367,   372
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INT8", "INT16", "INT32", "FLT",
  "STR", "BREAK", "CHAR", "DO", "ELSE", "FLOAT", "FOR", "IF", "INT",
  "MAIN", "RETURN", "VOID", "WHILE", "'='", "PA", "NA", "TA", "DA", "MA",
  "AA", "XA", "OA", "LA", "RA", "OR", "AN", "'|'", "'^'", "'&'", "EQ",
  "NE", "LE", "'<'", "GE", "'>'", "LS", "RS", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'!'", "'~'", "PP", "NN", "'.'", "AR", "'('", "')'", "'{'", "'}'",
  "';'", "','", "'$'", "$accept", "prog", "Mprog", "exts", "func", "Mmain",
  "Margs", "block", "decls", "decl", "type", "args", "list", "ptr",
  "stmts", "stmt", "exprs", "expr", "L", "M", "N", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    61,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   124,    94,    38,   288,   289,   290,
      60,   291,    62,   292,   293,    43,    45,    42,    47,    37,
      33,   126,   294,   295,    46,   296,    40,    41,   123,   125,
      59,    44,    36
};
# endif

#define YYPACT_NINF -87

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-87)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -87,     4,   -87,   -87,   136,   -87,   -87,   -87,   -50,   -87,
     -87,   -87,   -16,   -32,   -10,   -87,    57,   -87,   -16,   -87,
       6,    60,     7,     8,   -87,   -87,   -87,     8,   -16,     9,
       8,    19,    65,     7,     8,   -87,   -16,    80,     7,   -87,
     -87,   -16,    70,    14,    -7,   -87,   -87,   -87,   -87,   -87,
      30,   -87,    37,    52,     5,    54,     5,   108,   111,     5,
     -87,   -87,   -87,   113,   -87,   142,   -87,   112,   -87,   -87,
       5,   -87,   -87,     5,   -87,   158,     5,     5,   189,   -87,
     -87,   -87,   -87,   237,    98,   -87,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,   -87,
     -87,   321,    35,   321,   107,   213,   258,   -87,     5,   -87,
     -87,   338,   351,    77,    77,    77,    77,    77,    77,    96,
      96,   -87,   -87,   -87,   -87,     5,    72,   -87,   -87,   279,
     321,     5,     5,   158,   -87,   300,   321,   117,   158,   -87,
     -87,   -87,   -87,   -87,    74,   -87,   -87,    81,   -87,   158,
     -87,     5,   -87,   321,    90,   -87,   158,   -87,   -87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     6,     1,     2,    19,    18,    17,     0,    16,
       4,     5,    24,     0,     0,    25,     0,    15,    24,    10,
      23,     0,     0,     0,    22,    14,     8,     0,    24,     0,
      27,     0,     0,     0,     0,    13,    24,     0,     0,    21,
       7,    24,     0,     0,    62,    63,    64,    65,    66,    67,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    12,    28,     0,    26,     0,     9,     0,    23,    38,
       0,    60,    61,     0,    36,     0,     0,     0,     0,    69,
      55,    58,    59,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      20,    41,     0,    40,     0,     0,     0,    35,     0,    56,
      37,    42,    43,    44,    45,    48,    46,    49,    47,    50,
      51,    52,    53,    54,    68,     0,     0,    69,    70,     0,
      39,     0,     0,     0,    70,     0,    70,    30,     0,    70,
      71,    71,    71,    71,     0,    69,    32,     0,    69,     0,
      33,     0,    31,    71,     0,    69,     0,    71,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -18,   -87,   138,
      22,   110,   -87,   -11,   125,   -74,   -87,   -54,   -76,   -86,
     -22
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,    10,    22,    27,    26,    30,    11,
      28,    29,    13,    16,    37,    64,   102,    65,    75,   133,
     144
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      78,   104,    80,   108,     3,    83,    14,    21,    44,    45,
      46,    47,    48,    49,    70,    40,   101,    32,     5,   103,
      66,     6,   105,   106,     7,    42,    12,     9,    17,    18,
      67,    15,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    71,    72,    19,   138,    73,
     140,   132,    36,   143,   129,    56,    41,    57,    58,   137,
      20,    59,    23,    24,   142,    25,    33,    63,    39,   149,
      34,   130,   151,    68,    69,   152,    38,   135,   136,   156,
      34,    43,   157,    44,    45,    46,    47,    48,    49,    50,
      74,    51,   124,    76,    52,    53,   125,   153,    54,    43,
      55,    44,    45,    46,    47,    48,    49,    50,    77,    51,
      79,    81,    52,    53,    82,   100,    54,    85,    55,   145,
     146,   147,    94,    95,    96,    97,    98,   126,   131,   141,
      56,   154,    57,    58,   148,   158,    59,    31,    60,    61,
      62,   150,    63,    96,    97,    98,     5,   155,    56,     6,
      57,    58,     7,     8,    59,     9,    60,   110,    62,    43,
      63,    44,    45,    46,    47,    48,    49,    50,    35,    51,
       0,     0,    52,    53,    86,    87,    54,     0,    55,    88,
      89,    90,    91,    92,    93,    84,     0,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,     0,     0,     0,     0,     0,    56,     0,
      57,    58,     0,     0,    59,     0,    60,     0,    62,     0,
      63,    86,    87,     0,     0,     0,    88,    89,    90,    91,
      92,    93,     0,     0,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    86,    87,     0,     0,   107,
      88,    89,    90,    91,    92,    93,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    86,
      87,     0,     0,   127,    88,    89,    90,    91,    92,    93,
       0,     0,    94,    95,    96,    97,    98,     0,     0,     0,
      86,    87,     0,     0,   109,    88,    89,    90,    91,    92,
      93,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,    86,    87,     0,     0,   128,    88,    89,    90,    91,
      92,    93,     0,     0,    94,    95,    96,    97,    98,     0,
       0,     0,    86,    87,     0,     0,   134,    88,    89,    90,
      91,    92,    93,     0,     0,    94,    95,    96,    97,    98,
       0,     0,     0,    86,    87,     0,     0,   139,    88,    89,
      90,    91,    92,    93,     0,     0,    94,    95,    96,    97,
      98,    87,     0,     0,     0,    88,    89,    90,    91,    92,
      93,     0,     0,    94,    95,    96,    97,    98,    88,    89,
      90,    91,    92,    93,     0,     0,    94,    95,    96,    97,
      98
};

static const yytype_int16 yycheck[] =
{
      54,    75,    56,    79,     0,    59,    56,    18,     3,     4,
       5,     6,     7,     8,    21,    33,    70,    28,    10,    73,
      38,    13,    76,    77,    16,    36,     4,    19,    60,    61,
      41,    47,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    52,    53,    57,   134,    56,
     136,   127,    30,   139,   108,    50,    34,    52,    53,   133,
       3,    56,    56,     3,   138,    58,    57,    62,     3,   145,
      61,   125,   148,     3,    60,   149,    57,   131,   132,   155,
      61,     1,   156,     3,     4,     5,     6,     7,     8,     9,
      60,    11,    57,    56,    14,    15,    61,   151,    18,     1,
      20,     3,     4,     5,     6,     7,     8,     9,    56,    11,
      56,     3,    14,    15,     3,     3,    18,     4,    20,   141,
     142,   143,    45,    46,    47,    48,    49,    20,    56,    12,
      50,   153,    52,    53,    60,   157,    56,    27,    58,    59,
      60,    60,    62,    47,    48,    49,    10,    57,    50,    13,
      52,    53,    16,    17,    56,    19,    58,    59,    60,     1,
      62,     3,     4,     5,     6,     7,     8,     9,    30,    11,
      -1,    -1,    14,    15,    32,    33,    18,    -1,    20,    37,
      38,    39,    40,    41,    42,    60,    -1,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    -1,    -1,    56,    -1,    58,    -1,    60,    -1,
      62,    32,    33,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    -1,    -1,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    -1,    -1,    60,
      37,    38,    39,    40,    41,    42,    -1,    -1,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    -1,    -1,    60,    37,    38,    39,    40,    41,    42,
      -1,    -1,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      32,    33,    -1,    -1,    57,    37,    38,    39,    40,    41,
      42,    -1,    -1,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    32,    33,    -1,    -1,    57,    37,    38,    39,    40,
      41,    42,    -1,    -1,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    32,    33,    -1,    -1,    57,    37,    38,    39,
      40,    41,    42,    -1,    -1,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    32,    33,    -1,    -1,    57,    37,    38,
      39,    40,    41,    42,    -1,    -1,    45,    46,    47,    48,
      49,    33,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    -1,    -1,    45,    46,    47,    48,    49,    37,    38,
      39,    40,    41,    42,    -1,    -1,    45,    46,    47,    48,
      49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    64,    65,     0,    66,    10,    13,    16,    17,    19,
      67,    72,    73,    75,    56,    47,    76,    60,    61,    57,
       3,    76,    68,    56,     3,    58,    70,    69,    73,    74,
      71,    74,    76,    57,    61,    72,    73,    77,    57,     3,
      70,    73,    76,     1,     3,     4,     5,     6,     7,     8,
       9,    11,    14,    15,    18,    20,    50,    52,    53,    56,
      58,    59,    60,    62,    78,    80,    70,    76,     3,    60,
      21,    52,    53,    56,    60,    81,    56,    56,    80,    56,
      80,     3,     3,    80,    77,     4,    32,    33,    37,    38,
      39,    40,    41,    42,    45,    46,    47,    48,    49,    60,
       3,    80,    79,    80,    78,    80,    80,    60,    81,    57,
      59,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    57,    61,    20,    60,    57,    80,
      80,    56,    81,    82,    57,    80,    80,    78,    82,    57,
      82,    12,    78,    82,    83,    83,    83,    83,    60,    81,
      60,    81,    78,    80,    83,    57,    81,    78,    83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    66,    66,    66,    67,    67,    67,
      68,    69,    70,    71,    71,    72,    73,    73,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      79,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    81,
      82,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     0,     7,     5,     8,
       0,     0,     4,     2,     0,     2,     1,     1,     1,     1,
       5,     3,     4,     3,     0,     1,     2,     0,     1,     2,
       6,    10,     8,    10,    16,     3,     2,     3,     2,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     4,     0,
       0,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 85 "mycc.y" /* yacc.c:1646  */
    { addwidth(top_tblptr, top_offset);
			  pop_tblptr;
			  pop_offset;
			}
#line 1479 "mycc.c" /* yacc.c:1646  */
    break;

  case 3:
#line 91 "mycc.y" /* yacc.c:1646  */
    { push_tblptr(mktable(NULL));
			  push_offset(0);
			}
#line 1487 "mycc.c" /* yacc.c:1646  */
    break;

  case 7:
#line 101 "mycc.y" /* yacc.c:1646  */
    {

			Table *table;
			table = mktable(top_tblptr);
			push_tblptr(table);
			//push_offset(0);
			init_code(); // to store statements

			is_in_main = 0;
		}
#line 1502 "mycc.c" /* yacc.c:1646  */
    break;

  case 8:
#line 113 "mycc.y" /* yacc.c:1646  */
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
			  enterproc(top_tblptr, (yyvsp[-4].sym), type, table);
			}
#line 1546 "mycc.c" /* yacc.c:1646  */
    break;

  case 9:
#line 153 "mycc.y" /* yacc.c:1646  */
    { /* TASK 3: TO BE COMPLETED */
                Table *table;
  			  // the type of function is gived by $1, args by $6
                Type type = mkfun((yyvsp[-7].typ), (yyvsp[-2].typ));
                // method has public access and is static
                cf.methods[cf.method_count].access = (enum access_flags)(ACC_PUBLIC | ACC_STATIC);
                // method name is "test"
                cf.methods[cf.method_count].name = "test";
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
                enterproc(top_tblptr, (yyvsp[-5].sym), type, table);
			}
#line 1584 "mycc.c" /* yacc.c:1646  */
    break;

  case 10:
#line 188 "mycc.y" /* yacc.c:1646  */
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
#line 1625 "mycc.c" /* yacc.c:1646  */
    break;

  case 11:
#line 226 "mycc.y" /* yacc.c:1646  */
    { /* TASK 3: TO BE COMPLETED */
    // add code to create new table and push on tblptr and push offset 0
        Table * table = mktable(top_tblptr);
        push_tblptr(table);
        push_offset(0);
			  init_code();
			  is_in_main = 0;
			}
#line 1638 "mycc.c" /* yacc.c:1646  */
    break;

  case 16:
#line 246 "mycc.y" /* yacc.c:1646  */
    { (yyval.typ) = mkvoid(); }
#line 1644 "mycc.c" /* yacc.c:1646  */
    break;

  case 17:
#line 247 "mycc.y" /* yacc.c:1646  */
    { (yyval.typ) = mkint(); }
#line 1650 "mycc.c" /* yacc.c:1646  */
    break;

  case 18:
#line 248 "mycc.y" /* yacc.c:1646  */
    { (yyval.typ) = mkfloat(); }
#line 1656 "mycc.c" /* yacc.c:1646  */
    break;

  case 19:
#line 249 "mycc.y" /* yacc.c:1646  */
    { (yyval.typ) = mkchar(); }
#line 1662 "mycc.c" /* yacc.c:1646  */
    break;

  case 20:
#line 253 "mycc.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].num) && ischar((yyvsp[-2].typ)))
				enter(top_tblptr, (yyvsp[0].sym), mkstr(), top_offset++);
			  else
				enter(top_tblptr, (yyvsp[0].sym), (yyvsp[-2].typ), top_offset++);
			  (yyval.typ) = mkpair((yyvsp[-4].typ), (yyvsp[-2].typ));
			}
#line 1673 "mycc.c" /* yacc.c:1646  */
    break;

  case 21:
#line 259 "mycc.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].num) && ischar((yyvsp[-2].typ)))
				enter(top_tblptr, (yyvsp[0].sym), mkstr(), top_offset++);
			  else
				enter(top_tblptr, (yyvsp[0].sym), (yyvsp[-2].typ), top_offset++);
			  (yyval.typ) = (yyvsp[-2].typ);
			}
#line 1684 "mycc.c" /* yacc.c:1646  */
    break;

  case 22:
#line 268 "mycc.y" /* yacc.c:1646  */
    { /* TASK 1 and 4: TO BE COMPLETED */
			  /* $1 is the type */
			  /* $3 == 1 means pointer type for ID, e.g. char* so use mkstr() */
			  enter(top_tblptr, (yyvsp[0].sym), (yyvsp[-3].typ), top_offset++);
			  (yyval.typ) = (yyvsp[-3].typ);
			}
#line 1695 "mycc.c" /* yacc.c:1646  */
    break;

  case 23:
#line 274 "mycc.y" /* yacc.c:1646  */
    { /* TASK 1 and 4: TO BE COMPLETED */
			  /* $2 == 1 means pointer type for ID, e.g. char* so use mkstr() */
			  enter(top_tblptr, (yyvsp[0].sym), (yyvsp[-2].typ), top_offset++);
			  (yyval.typ) = (yyvsp[-2].typ);
			}
#line 1705 "mycc.c" /* yacc.c:1646  */
    break;

  case 24:
#line 281 "mycc.y" /* yacc.c:1646  */
    { (yyval.num) = 0; }
#line 1711 "mycc.c" /* yacc.c:1646  */
    break;

  case 25:
#line 282 "mycc.y" /* yacc.c:1646  */
    { (yyval.num) = 1; }
#line 1717 "mycc.c" /* yacc.c:1646  */
    break;

  case 29:
#line 291 "mycc.y" /* yacc.c:1646  */
    { emit(pop); }
#line 1723 "mycc.c" /* yacc.c:1646  */
    break;

  case 30:
#line 293 "mycc.y" /* yacc.c:1646  */
    { backpatch((yyvsp[-1].loc), pc - (yyvsp[-1].loc)); emit3(goto_, 3); }
#line 1729 "mycc.c" /* yacc.c:1646  */
    break;

  case 31:
#line 295 "mycc.y" /* yacc.c:1646  */
    { backpatch((yyvsp[-5].loc), (yyvsp[-1].loc) - (yyvsp[-5].loc)); emit3(goto_, 3); backpatch((yyvsp[-2].loc), pc - (yyvsp[-2].loc));}
#line 1735 "mycc.c" /* yacc.c:1646  */
    break;

  case 32:
#line 297 "mycc.y" /* yacc.c:1646  */
    { backpatch((yyvsp[-2].loc), pc - (yyvsp[-2].loc)); backpatch((yyvsp[0].loc), (yyvsp[-5].loc)-(yyvsp[0].loc)); }
#line 1741 "mycc.c" /* yacc.c:1646  */
    break;

  case 33:
#line 299 "mycc.y" /* yacc.c:1646  */
    { backpatch((yyvsp[-2].loc), pc - (yyvsp[-2].loc));  backpatch((yyvsp[-1].loc), (yyvsp[-8].loc)-(yyvsp[-1].loc));}
#line 1747 "mycc.c" /* yacc.c:1646  */
    break;

  case 34:
#line 301 "mycc.y" /* yacc.c:1646  */
    { backpatch((yyvsp[-8].loc), pc - (yyvsp[-8].loc)); backpatch((yyvsp[-8].loc), (yyvsp[-2].loc) - (yyvsp[-8].loc)); backpatch((yyvsp[0].loc), (yyvsp[-6].loc)-(yyvsp[0].loc)); backpatch((yyvsp[-4].loc), (yyvsp[-11].loc)-(yyvsp[-4].loc)  ); }
#line 1753 "mycc.c" /* yacc.c:1646  */
    break;

  case 35:
#line 303 "mycc.y" /* yacc.c:1646  */
    { if (is_in_main)
			  	emit(istore_2); /* TO BE COMPLETED */
			  else
			  	emit(ireturn);
			}
#line 1763 "mycc.c" /* yacc.c:1646  */
    break;

  case 36:
#line 308 "mycc.y" /* yacc.c:1646  */
    { /* BREAK is optional to implement (see Pr3) */
			  error("break not implemented");
			}
#line 1771 "mycc.c" /* yacc.c:1646  */
    break;

  case 38:
#line 312 "mycc.y" /* yacc.c:1646  */
    { yyerrok; }
#line 1777 "mycc.c" /* yacc.c:1646  */
    break;

  case 41:
#line 320 "mycc.y" /* yacc.c:1646  */
    { emit(dup); emit2(istore, (yyvsp[-2].sym)->localvar); }
#line 1783 "mycc.c" /* yacc.c:1646  */
    break;

  case 42:
#line 321 "mycc.y" /* yacc.c:1646  */
    { emit(ior);  }
#line 1789 "mycc.c" /* yacc.c:1646  */
    break;

  case 43:
#line 322 "mycc.y" /* yacc.c:1646  */
    { emit(iand);  }
#line 1795 "mycc.c" /* yacc.c:1646  */
    break;

  case 44:
#line 323 "mycc.y" /* yacc.c:1646  */
    { emit3(if_icmpeq, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
#line 1801 "mycc.c" /* yacc.c:1646  */
    break;

  case 45:
#line 324 "mycc.y" /* yacc.c:1646  */
    { emit3(if_icmpne, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
#line 1807 "mycc.c" /* yacc.c:1646  */
    break;

  case 46:
#line 325 "mycc.y" /* yacc.c:1646  */
    { emit3(if_icmplt, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
#line 1813 "mycc.c" /* yacc.c:1646  */
    break;

  case 47:
#line 326 "mycc.y" /* yacc.c:1646  */
    { emit3(if_icmpgt, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
#line 1819 "mycc.c" /* yacc.c:1646  */
    break;

  case 48:
#line 327 "mycc.y" /* yacc.c:1646  */
    { emit3(if_icmple, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
#line 1825 "mycc.c" /* yacc.c:1646  */
    break;

  case 49:
#line 328 "mycc.y" /* yacc.c:1646  */
    { emit3(if_icmpge, 7); emit(iconst_0); emit3(goto_, 4); emit(iconst_1); }
#line 1831 "mycc.c" /* yacc.c:1646  */
    break;

  case 50:
#line 329 "mycc.y" /* yacc.c:1646  */
    { emit(iadd); }
#line 1837 "mycc.c" /* yacc.c:1646  */
    break;

  case 51:
#line 330 "mycc.y" /* yacc.c:1646  */
    { emit(isub); }
#line 1843 "mycc.c" /* yacc.c:1646  */
    break;

  case 52:
#line 331 "mycc.y" /* yacc.c:1646  */
    { emit(imul); }
#line 1849 "mycc.c" /* yacc.c:1646  */
    break;

  case 53:
#line 332 "mycc.y" /* yacc.c:1646  */
    { emit(idiv); }
#line 1855 "mycc.c" /* yacc.c:1646  */
    break;

  case 54:
#line 333 "mycc.y" /* yacc.c:1646  */
    { /* TODO: TO BE COMPLETED */ error("% operator not implemented"); }
#line 1861 "mycc.c" /* yacc.c:1646  */
    break;

  case 55:
#line 334 "mycc.y" /* yacc.c:1646  */
    { emit(ineg); }
#line 1867 "mycc.c" /* yacc.c:1646  */
    break;

  case 57:
#line 336 "mycc.y" /* yacc.c:1646  */
    { // check that we are in main()
			  if (is_in_main)
			  {	emit(aload_1);
			  	emit2(bipush, (yyvsp[0].num));
			  	emit(iaload);
			  }
			  else
			  	error("invalid use of $# in function");
			}
#line 1881 "mycc.c" /* yacc.c:1646  */
    break;

  case 58:
#line 345 "mycc.y" /* yacc.c:1646  */
    {  emit(iadd); emit(iconst_1); }
#line 1887 "mycc.c" /* yacc.c:1646  */
    break;

  case 59:
#line 346 "mycc.y" /* yacc.c:1646  */
    { emit(isub); emit(iconst_1); }
#line 1893 "mycc.c" /* yacc.c:1646  */
    break;

  case 60:
#line 347 "mycc.y" /* yacc.c:1646  */
    { emit(iadd); emit(iconst_1); }
#line 1899 "mycc.c" /* yacc.c:1646  */
    break;

  case 61:
#line 348 "mycc.y" /* yacc.c:1646  */
    { emit(isub); emit(iconst_1);}
#line 1905 "mycc.c" /* yacc.c:1646  */
    break;

  case 62:
#line 349 "mycc.y" /* yacc.c:1646  */
    { emit2(iload,  getplace(top_tblptr, (yyvsp[0].sym))); }
#line 1911 "mycc.c" /* yacc.c:1646  */
    break;

  case 63:
#line 350 "mycc.y" /* yacc.c:1646  */
    { emit2(bipush, (yyvsp[0].num)); }
#line 1917 "mycc.c" /* yacc.c:1646  */
    break;

  case 64:
#line 351 "mycc.y" /* yacc.c:1646  */
    { emit3(sipush, (yyvsp[0].num)); }
#line 1923 "mycc.c" /* yacc.c:1646  */
    break;

  case 65:
#line 352 "mycc.y" /* yacc.c:1646  */
    { emit2(ldc, constant_pool_add_Integer(&cf, (yyvsp[0].num))); }
#line 1929 "mycc.c" /* yacc.c:1646  */
    break;

  case 66:
#line 353 "mycc.y" /* yacc.c:1646  */
    { emit2(ldc, constant_pool_add_Float(&cf, (yyvsp[0].flt))); }
#line 1935 "mycc.c" /* yacc.c:1646  */
    break;

  case 67:
#line 354 "mycc.y" /* yacc.c:1646  */
    { emit2(ldc, constant_pool_add_String(&cf, constant_pool_add_Utf8(&cf, (yyvsp[0].str)))); }
#line 1941 "mycc.c" /* yacc.c:1646  */
    break;

  case 68:
#line 356 "mycc.y" /* yacc.c:1646  */
    { /* TASK 3: TO BE COMPLETED */
			  error("function call not implemented");
			}
#line 1949 "mycc.c" /* yacc.c:1646  */
    break;

  case 69:
#line 364 "mycc.y" /* yacc.c:1646  */
    { (yyval.loc) = pc; }
#line 1955 "mycc.c" /* yacc.c:1646  */
    break;

  case 70:
#line 367 "mycc.y" /* yacc.c:1646  */
    { (yyval.loc) = pc;	/* location of inst. to backpatch */
			  emit3(ifeq, 0);
			}
#line 1963 "mycc.c" /* yacc.c:1646  */
    break;

  case 71:
#line 372 "mycc.y" /* yacc.c:1646  */
    { (yyval.loc) = pc;	/* location of inst. to backpatch */
			  emit3(goto_, 0);
			}
#line 1971 "mycc.c" /* yacc.c:1646  */
    break;


#line 1975 "mycc.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 380 "mycc.y" /* yacc.c:1906  */


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
