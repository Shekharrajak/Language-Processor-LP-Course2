/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "c.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int linecount=0;
char table[MAX][200];
char replacement[MAX][4];
int v[MAX]={0},vcount=0;

#line 76 "y.tab.c" /* yacc.c:339  */

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
    INT = 258,
    UNSIGNED = 259,
    BOOL = 260,
    VOID = 261,
    WHILE = 262,
    COMMA = 263,
    IF = 264,
    ELSE = 265,
    PRINTF = 266,
    SWITCH = 267,
    CASE = 268,
    BREAK = 269,
    ADD = 270,
    SUB = 271,
    MUL = 272,
    DIV = 273,
    DEFAULT = 274,
    NUM = 275,
    ID = 276,
    INCLUDE = 277,
    MAIN = 278,
    DOT = 279,
    NOT = 280,
    ASSIGN = 281,
    AND = 282,
    OR = 283,
    LE = 284,
    GE = 285,
    EQ = 286,
    NE = 287,
    LT = 288,
    GT = 289
  };
#endif
/* Tokens.  */
#define INT 258
#define UNSIGNED 259
#define BOOL 260
#define VOID 261
#define WHILE 262
#define COMMA 263
#define IF 264
#define ELSE 265
#define PRINTF 266
#define SWITCH 267
#define CASE 268
#define BREAK 269
#define ADD 270
#define SUB 271
#define MUL 272
#define DIV 273
#define DEFAULT 274
#define NUM 275
#define ID 276
#define INCLUDE 277
#define MAIN 278
#define DOT 279
#define NOT 280
#define ASSIGN 281
#define AND 282
#define OR 283
#define LE 284
#define GE 285
#define EQ 286
#define NE 287
#define LT 288
#define GT 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 25 "c.y" /* yacc.c:355  */

	char *str;

#line 185 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 200 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,     2,
      37,    38,    49,    47,    42,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    41,
      29,     2,    30,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,    43,    40,    46,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    31,    32,    33,    34,    35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    34,    34,    35,    36,    40,    44,    48,    52,    53,
      54,    55,    60,    60,    61,    62,    63,    67,    67,    70,
      70,    74,    74,    75,    75,    76,    76,    77,    77,    81,
      82,    86,    87,    88,    89,    90,    91,    94,    94,    95,
      95,    96,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   106,   106,   107,   107,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   115,   115,   116,   116,   117,   120,
     120,   121,   121,   122,   125,   125,   126,   129,   130,   131,
     135,   135,   135,   138,   139,   143,   143,   147,   148,   148,
     152,   152,   156,   157,   160,   161,   164,   164,   164,   168,
     172,   172,   173,   173
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "UNSIGNED", "BOOL", "VOID",
  "WHILE", "COMMA", "IF", "ELSE", "PRINTF", "SWITCH", "CASE", "BREAK",
  "ADD", "SUB", "MUL", "DIV", "DEFAULT", "NUM", "ID", "INCLUDE", "MAIN",
  "DOT", "NOT", "ASSIGN", "AND", "OR", "'<'", "'>'", "LE", "GE", "EQ",
  "NE", "LT", "GT", "'('", "')'", "'{'", "'}'", "';'", "','", "'|'", "'^'",
  "'&'", "'~'", "'+'", "'-'", "'*'", "'/'", "'@'", "':'", "$accept",
  "start", "main", "block", "declaration", "type", "declarations", "$@1",
  "assignment_declr", "$@2", "assignment", "$@3", "shorthand", "$@4",
  "$@5", "$@6", "$@7", "stmts", "stmt", "expr", "$@8", "$@9", "E", "$@10",
  "$@11", "$@12", "$@13", "F", "$@14", "$@15", "$@16", "$@17", "$@18",
  "$@19", "G", "$@20", "$@21", "H", "$@22", "$@23", "I", "$@24", "J",
  "while", "$@25", "$@26", "whilefactor", "if", "$@27", "factor", "$@28",
  "switch", "$@29", "switchfactor", "cases", "case", "$@30", "$@31",
  "default", "break", "$@32", "$@33", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    60,
      62,   284,   285,   286,   287,   288,   289,    40,    41,   123,
     125,    59,    44,   124,    94,    38,   126,    43,    45,    42,
      47,    64,    58
};
# endif

#define YYPACT_NINF -112

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-112)))

#define YYTABLE_NINF -89

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      43,    -4,  -112,  -112,  -112,    27,    43,    43,     8,    -6,
    -112,  -112,  -112,    -9,    56,    57,    60,    58,    75,  -112,
       8,    63,     8,   -11,  -112,     9,  -112,  -112,  -112,  -112,
     -11,    44,    35,    23,    42,   -13,  -112,    52,  -112,  -112,
      67,    68,    51,  -112,    65,    66,    69,     9,  -112,  -112,
    -112,     6,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,    73,
     -11,    90,    87,    99,   100,    98,   101,  -112,  -112,  -112,
    -112,  -112,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
      12,    79,   -11,   -11,   -11,   -11,   -11,    35,    35,    23,
      23,    23,    23,    42,    42,    42,    42,    42,    42,   -13,
     -13,  -112,  -112,  -112,    15,  -112,  -112,    44,    44,    44,
      44,    44,  -112,    63,    81,    -1,   108,   109,  -112,  -112,
    -112,  -112,   111,   103,   -12,   109,    63,  -112,    72,  -112,
    -112,    86,  -112,  -112,  -112,     9,  -112,    76,  -112,     9,
     113,    84,  -112,  -112,  -112,  -112
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     8,     9,    10,    11,     0,     4,     4,     0,     0,
       1,     3,     2,    12,     0,    16,     0,     0,     0,     7,
       0,     0,     0,     0,    14,    30,     5,    13,    79,    78,
       0,    18,    41,    50,    63,    68,    73,    76,     8,    80,
       0,     0,    19,    32,     0,     0,     0,    30,    34,    35,
      36,     0,    37,    39,    42,    44,    46,    48,    51,    53,
      55,    57,    59,    61,    64,    66,    69,    71,    74,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    33,     6,
      29,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    40,    43,
      45,    47,    49,    52,    54,    56,    58,    60,    62,    65,
      67,    70,    72,    75,     0,    85,    90,    20,    22,    24,
      26,    28,    81,     0,     0,     0,    87,    95,    83,    84,
      82,    86,     0,     0,     0,    95,     0,    96,     0,    92,
      91,     0,    94,    89,    97,    30,    93,     0,    99,    30,
     102,     0,    98,   103,   100,   101
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -112,    85,  -112,  -111,    45,  -112,     3,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,   -47,    -5,   -29,
    -112,  -112,    11,  -112,  -112,  -112,  -112,    -2,  -112,  -112,
    -112,  -112,  -112,  -112,   -28,  -112,  -112,     1,  -112,  -112,
     -10,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,   -16,  -112,  -112,  -112,  -112,  -112,
    -112,  -112
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    26,    43,     8,    14,    17,    15,    18,
      44,    72,    45,    73,    74,    75,    76,    46,    47,    31,
      82,    83,    32,    84,    85,    86,    87,    33,    88,    89,
      90,    91,    92,    93,    34,    94,    95,    35,    96,    97,
      36,    98,    37,    48,    69,   135,   140,    49,   133,   141,
     142,    50,   134,   150,   144,   145,   154,   157,   151,   162,
     165,   163
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      80,    51,    38,     2,     3,     4,    39,   148,    40,    28,
      29,    41,    38,     2,     3,     4,    39,   -17,    40,     9,
      42,    41,   136,    24,   138,    27,    30,    10,   149,    13,
      42,    16,   -15,    52,    53,   153,    66,    67,    25,    52,
      53,   100,    52,    53,    81,     7,     1,     2,     3,     4,
     125,     7,     7,   132,    58,    59,    60,    61,    62,    63,
     113,   114,   115,   116,   117,   118,   -21,   -23,   -25,   -27,
     124,    52,    53,   127,   128,   129,   130,   131,    54,    55,
      56,    57,   109,   110,   111,   112,   121,   122,   123,    64,
      65,    11,    12,   107,   108,   119,   120,    19,    21,    20,
      22,    23,    25,    68,    70,    71,    77,    78,   158,    79,
      99,   101,   160,   102,   103,   105,   104,   126,   -88,   106,
     137,   146,   143,   147,   155,   164,   156,   161,   159,   152,
     139
};

static const yytype_uint8 yycheck[] =
{
      47,    30,     3,     4,     5,     6,     7,    19,     9,    20,
      21,    12,     3,     4,     5,     6,     7,    26,     9,    23,
      21,    12,   133,    20,   135,    22,    37,     0,    40,    21,
      21,    37,    41,    27,    28,   146,    49,    50,    39,    27,
      28,    70,    27,    28,    38,     0,     3,     4,     5,     6,
      38,     6,     7,    38,    31,    32,    33,    34,    35,    36,
      88,    89,    90,    91,    92,    93,    15,    16,    17,    18,
      99,    27,    28,   102,   103,   104,   105,   106,    43,    44,
      45,    46,    84,    85,    86,    87,    96,    97,    98,    47,
      48,     6,     7,    82,    83,    94,    95,    41,    38,    42,
      42,    26,    39,    51,    37,    37,    41,    41,   155,    40,
      37,    21,   159,    26,    15,    17,    16,    38,    10,    18,
      39,    10,    13,    20,    52,    41,    40,    14,    52,   145,
     135
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    54,    55,    57,    58,    23,
       0,    54,    54,    21,    59,    61,    37,    60,    62,    41,
      42,    38,    42,    26,    59,    39,    56,    59,    20,    21,
      37,    72,    75,    80,    87,    90,    93,    95,     3,     7,
       9,    12,    21,    57,    63,    65,    70,    71,    96,   100,
     104,    72,    27,    28,    43,    44,    45,    46,    31,    32,
      33,    34,    35,    36,    47,    48,    49,    50,    51,    97,
      37,    37,    64,    66,    67,    68,    69,    41,    41,    40,
      70,    38,    73,    74,    76,    77,    78,    79,    81,    82,
      83,    84,    85,    86,    88,    89,    91,    92,    94,    37,
      72,    21,    26,    15,    16,    17,    18,    75,    75,    80,
      80,    80,    80,    87,    87,    87,    87,    87,    87,    90,
      90,    93,    93,    93,    72,    38,    38,    72,    72,    72,
      72,    72,    38,   101,   105,    98,    56,    39,    56,    71,
      99,   102,   103,    13,   107,   108,    10,    20,    19,    40,
     106,   111,   107,    56,   109,    52,    40,   110,    70,    52,
      70,    14,   112,   114,    41,   113
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    54,    55,    56,    57,    58,    58,
      58,    58,    60,    59,    59,    59,    59,    62,    61,    64,
      63,    66,    65,    67,    65,    68,    65,    69,    65,    70,
      70,    71,    71,    71,    71,    71,    71,    73,    72,    74,
      72,    72,    76,    75,    77,    75,    78,    75,    79,    75,
      75,    81,    80,    82,    80,    83,    80,    84,    80,    85,
      80,    86,    80,    80,    88,    87,    89,    87,    87,    91,
      90,    92,    90,    90,    94,    93,    93,    95,    95,    95,
      97,    98,    96,    99,    99,   101,   100,   102,   103,   102,
     105,   104,   106,   106,   107,   107,   109,   110,   108,   111,
     113,   112,   114,   112
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     5,     3,     3,     1,     1,
       1,     1,     0,     4,     3,     1,     1,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     2,
       0,     2,     1,     2,     1,     1,     1,     0,     4,     0,
       4,     1,     0,     4,     0,     4,     0,     4,     0,     4,
       1,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     1,     0,     4,     0,     4,     1,     0,
       4,     0,     4,     1,     0,     4,     1,     3,     1,     1,
       0,     0,     7,     1,     1,     0,     7,     0,     0,     3,
       0,     8,     1,     2,     2,     0,     0,     0,     7,     3,
       0,     3,     0,     1
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
        case 12:
#line 60 "c.y" /* yacc.c:1646  */
    {insert_into_symbol_table((yyvsp[0].str));check_if_declared((yyvsp[0].str));}
#line 1401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 62 "c.y" /* yacc.c:1646  */
    {insert_into_symbol_table((yyvsp[0].str));check_if_declared((yyvsp[0].str));}
#line 1407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 67 "c.y" /* yacc.c:1646  */
    {insert_into_symbol_table((yyvsp[0].str)),check_if_declared((yyvsp[0].str));IDpush((yyvsp[0].str));}
#line 1413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 67 "c.y" /* yacc.c:1646  */
    {assignment();}
#line 1419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 70 "c.y" /* yacc.c:1646  */
    {IDpush((yyvsp[0].str));check_if_declared((yyvsp[0].str));}
#line 1425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 70 "c.y" /* yacc.c:1646  */
    {assignment();}
#line 1431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 74 "c.y" /* yacc.c:1646  */
    {IDpush((yyvsp[0].str));check_if_declared((yyvsp[0].str));}
#line 1437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 74 "c.y" /* yacc.c:1646  */
    {shorthand1();}
#line 1443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 75 "c.y" /* yacc.c:1646  */
    {IDpush((yyvsp[0].str));check_if_declared((yyvsp[0].str));}
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 75 "c.y" /* yacc.c:1646  */
    {shorthand2();}
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 76 "c.y" /* yacc.c:1646  */
    {IDpush((yyvsp[0].str));check_if_declared((yyvsp[0].str));}
#line 1461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 76 "c.y" /* yacc.c:1646  */
    {shorthand3();}
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 77 "c.y" /* yacc.c:1646  */
    {IDpush((yyvsp[0].str));check_if_declared((yyvsp[0].str));}
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 77 "c.y" /* yacc.c:1646  */
    {shorthand4();}
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 94 "c.y" /* yacc.c:1646  */
    {push();}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 94 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 95 "c.y" /* yacc.c:1646  */
    {push();}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 95 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 99 "c.y" /* yacc.c:1646  */
    {push();}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 99 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 100 "c.y" /* yacc.c:1646  */
    {push();}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 100 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 101 "c.y" /* yacc.c:1646  */
    {push();}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 101 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 102 "c.y" /* yacc.c:1646  */
    {push();}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 102 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 106 "c.y" /* yacc.c:1646  */
    {push();}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 106 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 107 "c.y" /* yacc.c:1646  */
    {push();}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 107 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 108 "c.y" /* yacc.c:1646  */
    {push();}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 108 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 109 "c.y" /* yacc.c:1646  */
    {push();}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 109 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 110 "c.y" /* yacc.c:1646  */
    {push();}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 110 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 111 "c.y" /* yacc.c:1646  */
    {push();}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 111 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 115 "c.y" /* yacc.c:1646  */
    {push();}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 115 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 116 "c.y" /* yacc.c:1646  */
    {push();}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 116 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 120 "c.y" /* yacc.c:1646  */
    {push();}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 120 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 121 "c.y" /* yacc.c:1646  */
    {push();}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 121 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 125 "c.y" /* yacc.c:1646  */
    {push();}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 125 "c.y" /* yacc.c:1646  */
    {expressions();}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 130 "c.y" /* yacc.c:1646  */
    {IDpush();check_if_declared((yyvsp[0].str));}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 131 "c.y" /* yacc.c:1646  */
    {push();}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 135 "c.y" /* yacc.c:1646  */
    {while_label1();}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 135 "c.y" /* yacc.c:1646  */
    {while_label2();}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 138 "c.y" /* yacc.c:1646  */
    {while_label3();}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 139 "c.y" /* yacc.c:1646  */
    {while_label3();}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 143 "c.y" /* yacc.c:1646  */
    {if_label1();}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 147 "c.y" /* yacc.c:1646  */
    {if_label3();}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 148 "c.y" /* yacc.c:1646  */
    {if_label2();}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 148 "c.y" /* yacc.c:1646  */
    {if_label3();}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 152 "c.y" /* yacc.c:1646  */
    {switch_push();}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 156 "c.y" /* yacc.c:1646  */
    {exit_switch();}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 157 "c.y" /* yacc.c:1646  */
    {exit_switch();}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 164 "c.y" /* yacc.c:1646  */
    {label_switch2();}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 164 "c.y" /* yacc.c:1646  */
    {extra_label_switch();}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 172 "c.y" /* yacc.c:1646  */
    {switch_break();}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 172 "c.y" /* yacc.c:1646  */
    {label_switch1();}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 173 "c.y" /* yacc.c:1646  */
    {without_break();}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 173 "c.y" /* yacc.c:1646  */
    {label_switch1();}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1801 "y.tab.c" /* yacc.c:1646  */
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
#line 176 "c.y" /* yacc.c:1906  */

//...........................................................................................................................................

#include"lex.yy.c"
#include <ctype.h>
int count=0;

char st[100][10];
int top=0;
int i=0;
char temp[2]="t";

int label[20];
int lnum=0;
int ltop=0;

int eslnum = 0;
int prev_break = 1;
char switch_stack[10][10];
int switch_stack_top = 0;

char symbolTable[100][20];
int size = 0;
int line=0;

int main(int argc, char *argv[])
{
   char ch;
   yyin = fopen(argv[1], "r");
   if(!yyparse())
   {
	    printf("\nParsing completed successfully\n");
		printf("\nEnter any key to generate intermediate code....\n");
		scanf("%c",&ch);
		printf("\nIntermediate code :\n");
		backpatch();
	}
	else
		printf("\nParsing failed\n");

	fclose(yyin);
    return 0;
}

//for printing error messages        
yyerror(char *s) 
{
	printf("%d : %s %s\n", yylineno, s, yytext );
}  

//insert each declared variable in the table,and give error if already declared
insert_into_symbol_table(char *str)
{
	int i=0;
	for(;i<size;i++)
	{
		if(strcmp(symbolTable[i],str)==0)
		{
			printf("Error line(%d): %s is redeclared\n",yylineno, str);
			exit(0);
		}
	}
	printf("%s added to symbol table\n",str);
	strcpy(symbolTable[size++],str);
}

//checks whether an identifier is declared or not by scanning the symbol table
check_if_declared(char *str)
{
	int i=0;
	for(;i<size;i++)
	{
		if(strcmp(symbolTable[i],str)==0)
			break;
	}
	if(i==size)
	{
		printf("Error line(%d): %s not declared \n",yylineno, str);
		exit(0);
	}
}

//to generate target line no for goto statements and place them appropriately
backpatch()
{
	int i;
	for(i=0;i<linecount;i++)
	{
		if((table[i][0]=='L')||(table[i][0]=='E'))
		{
			int num=0,index=1;
			if(table[i][index]=='L')
				index++;
			while(isdigit(table[i][index]))
			{
				num=10*num+table[i][index++]-'0';
			}
			v[i]=1;
			char str[10];
			sprintf(str,"%d",line);
			strcpy(replacement[num],str);
		}
		else
			line++;
	}
    line=0;
	for(i=0;i<linecount;i++)
	{
		if(!v[i])
		{
			int j;
			for(j=0;j<strlen(table[i]);j++)
			{
				if((table[i][j]=='L')||(table[i][j]=='E'))
				{
					int num=0,index=j+1;
					if(table[i][index]=='L')
						index++;
					while(isdigit(table[i][index]))
					{
						num=10*num+table[i][index++]-'0';
					}
					sprintf(table[i]+j,"%s",replacement[num]);

				}
			}
			printf("%d\t%s\n",line++,table[i]);
		}
	}
}  

//push current literal on the stack   
push()
{
  	strcpy(st[++top],yytext);
  	yytext[0]='\0';
}

//push identifier
IDpush(char *str)
{
  	strcpy(st[++top],str);
  	yytext[0]='\0';
}

//for expressions of the for ID = ID1 operator ID2 ie. 2 operands on right side
expressions()
{
 	sprintf(temp,"t%d",i);
  	sprintf(table[linecount],"%s = %s %s %s",temp,st[top-2],st[top-1],st[top]);
  	linecount++;
  	top-=2;
 	strcpy(st[top],temp);
 	i++;
}

//single operand on right hand side
assignment()
{
 	sprintf(table[linecount],"%s = %s",st[top-1],st[top]);
 	linecount++;
 	top-=1;
}

//to generate intermediate for shorthand statements
//for +=
shorthand1()
{
	sprintf(table[linecount],"%s = %s + %s",st[top-1],st[top-1],st[top]);
 	linecount++;
 	top-=1;
}

//for -=
shorthand2()
{
	sprintf(table[linecount],"%s = %s - %s",st[top-1],st[top-1],st[top]);
 	linecount++;
 	top-=1;
}

//for *=
shorthand3()
{
	sprintf(table[linecount],"%s = %s * %s",st[top-1],st[top-1],st[top]);
 	linecount++;
 	top-=1;
}

//for /=
shorthand4()
{
	sprintf(table[linecount],"%s = %s / %s",st[top-1],st[top-1],st[top]);
 	linecount++;
 	top-=1;
}

//will generate label at the start of the loop,where jump has to be made after each iteration.	  
while_label1()
{
	lnum++;
	sprintf(table[linecount],"L%d:",lnum);
	linecount++;
	label[ltop++] = lnum++;
}

//while_label2() will generate jump using goto based on condition inside a pair of parentheses.
while_label2()
{
 	sprintf(temp,"t%d",i);
 	sprintf(table[linecount],"%s = not %s",temp,st[top]);
 	linecount++;
 	sprintf(table[linecount],"if %s goto L%d",temp,lnum);
 	linecount++;
 	label[ltop++] = lnum;
 	i++;
}

//while_label3() will generate label at the end of loop where control needs to be transferred when condition becomes false.
while_label3()
{
	sprintf(table[linecount],"goto L%d",label[ltop-2]);
	linecount++;
	sprintf(table[linecount],"L%d:",label[ltop-1]);
	linecount++;
	ltop = ltop-2;
}
if_label1()
{
 	lnum++;
 	sprintf(temp,"t%d",i);
 	sprintf(table[linecount],"%s = not %s",temp,st[top]);
 	linecount++;
 	sprintf(table[linecount],"if %s goto L%d",temp,lnum);
 	linecount++;
 	i++;
 	label[++ltop]=lnum;
}
if_label2()
{
	int x;
	lnum++;
	x=label[ltop--];
	sprintf(table[linecount],"goto L%d",lnum);
	linecount++;
	sprintf(table[linecount],"L%d: ",x); 
	linecount++;
	label[++ltop]=lnum;
}
if_label3()
{
	int y;
	y=label[ltop--];
	sprintf(table[linecount],"L%d: ",y);
	linecount++;
}
switch_push()
{
	strcpy(switch_stack[switch_stack_top++],st[top]);
}
label_switch1()
{
	sprintf(table[linecount],"L%d :",lnum++);
	linecount++;
}
label_switch2()
{
	lnum++;
 	sprintf(temp,"t%d",i);
 	sprintf(table[linecount],"if %s != %s goto L%d ",switch_stack[switch_stack_top-1],yytext,lnum);
 	linecount++;
 	i++;
}
extra_label_switch()
{
	if(prev_break==0)
	sprintf(table[linecount],"L%d:",lnum-1);
	linecount++;
}
without_break()
{
	sprintf(table[linecount],"goto L%d ",lnum+1);
	linecount++;
	prev_break = 0;
}
switch_break()
{
	sprintf(table[linecount],"goto EL%d ",eslnum);
	linecount++;
	prev_break = 1;
}
exit_switch()
{
	sprintf(table[linecount],"EL%d",eslnum++);
	linecount++;
}


