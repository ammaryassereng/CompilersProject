
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "yacc.y"

    #include <stdio.h> 
    #include <stdlib.h> 
    #include <stdarg.h> 
    #include <string.h> 
    FILE *yyin;
    extern int yylex(void);
    extern void yyerror(char *);
    int tokenValId = 0; 
    int tokensVal [10];


/* Line 189 of yacc.c  */
#line 86 "yacc.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SCOPE_OPEN = 258,
     SCOPE_CLOSE = 259,
     CONST = 260,
     BOOL = 261,
     TRUE = 262,
     FALSE = 263,
     INT = 264,
     FLOAT = 265,
     CHAR = 266,
     MULTIPLY = 267,
     DIVISIDE = 268,
     PLUS = 269,
     MINUS = 270,
     EQUAL = 271,
     IF_STATMENT = 272,
     THEN = 273,
     ELSE = 274,
     ELSE_IF = 275,
     WHILE = 276,
     FOR = 277,
     SWITCH_STATEMENT = 278,
     CASE = 279,
     REPEAT_STATEMENT = 280,
     UNTILL = 281,
     VAR = 282,
     END_EXPR = 283,
     BREAK = 284,
     DEFAULT = 285,
     COLON = 286,
     COMMA = 287,
     RETURN = 288,
     IS = 289,
     MATCH = 290,
     GreaterThanOrEqual = 291,
     LessThanOrEqual = 292,
     EqualEqual = 293,
     NotEqual = 294,
     LessThan = 295,
     GreaterThan = 296,
     OR = 297,
     AND = 298,
     NOT = 299,
     INT_VALUE = 300,
     DECIMAL_VALUE = 301,
     CHAR_VALUE = 302,
     IFX = 303
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 13 "yacc.y"

    int intVal;    
    char charVal;               
	float floatVal; 

    struct info{
    int typeId; //0-int, 1-float, 2-char
    int ival;
    float fval;
  }info;                           



/* Line 214 of yacc.c  */
#line 184 "yacc.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 196 "yacc.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   503

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNRULES -- Number of states.  */
#define YYNSTATES  242

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      49,    50,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    14,    17,    20,
      23,    26,    28,    30,    32,    34,    36,    39,    41,    43,
      46,    49,    52,    55,    58,    61,    66,    71,    76,    81,
      86,    91,    96,   101,   107,   113,   119,   125,   131,   137,
     143,   149,   153,   157,   159,   163,   167,   169,   171,   173,
     175,   179,   183,   187,   191,   194,   198,   202,   206,   210,
     214,   218,   222,   226,   230,   232,   234,   238,   242,   246,
     250,   254,   259,   266,   272,   282,   288,   296,   304,   312,
     320,   328,   333,   338,   341,   347,   353,   359,   365,   370,
     375,   380,   385,   388,   391,   394,   397,   402,   406,   408,
     410,   412,   414,   416,   418,   421,   424,   427,   430,   433
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    -1,    -1,    53,    54,    -1,    54,
      -1,    55,    28,    -1,    56,    28,    -1,    57,    28,    -1,
      60,    28,    -1,    61,    28,    -1,    62,    -1,    63,    -1,
      64,    -1,    65,    -1,    66,    -1,    29,    28,    -1,    68,
      -1,    69,    -1,    72,    28,    -1,    75,    28,    -1,     9,
      27,    -1,    10,    27,    -1,     6,    27,    -1,    11,    27,
      -1,     9,    27,    16,    57,    -1,    10,    27,    16,    57,
      -1,     6,    27,    16,    60,    -1,    11,    27,    16,    47,
      -1,     9,    27,    16,    72,    -1,    10,    27,    16,    72,
      -1,     6,    27,    16,    72,    -1,    11,    27,    16,    72,
      -1,     5,     9,    27,    16,    57,    -1,     5,    10,    27,
      16,    57,    -1,     5,     6,    27,    16,    60,    -1,     5,
      11,    27,    16,    47,    -1,     5,     9,    27,    16,    72,
      -1,     5,    10,    27,    16,    72,    -1,     5,     6,    27,
      16,    72,    -1,     5,    11,    27,    16,    72,    -1,    57,
      14,    58,    -1,    57,    15,    58,    -1,    58,    -1,    58,
      12,    59,    -1,    58,    13,    59,    -1,    59,    -1,    27,
      -1,    45,    -1,    46,    -1,    49,    57,    50,    -1,    49,
      60,    50,    -1,    60,    42,    60,    -1,    60,    43,    60,
      -1,    44,    60,    -1,    57,    36,    57,    -1,    57,    41,
      57,    -1,    57,    38,    57,    -1,    57,    37,    57,    -1,
      57,    40,    57,    -1,    57,    39,    57,    -1,    27,    34,
       7,    -1,    27,    34,     8,    -1,    27,    35,    47,    -1,
       7,    -1,     8,    -1,    27,    16,    57,    -1,    27,    16,
      60,    -1,    27,    16,    47,    -1,    27,    16,    72,    -1,
       3,    53,     4,    -1,    17,    60,    18,    54,    -1,    17,
      60,    18,    54,    19,    54,    -1,    21,    49,    60,    50,
      62,    -1,    22,    49,    61,    28,    60,    28,    61,    50,
      62,    -1,    23,    49,    27,    50,    67,    -1,    24,    45,
      31,    53,    29,    28,    67,    -1,    24,     7,    31,    53,
      29,    28,    67,    -1,    24,     8,    31,    53,    29,    28,
      67,    -1,    24,    46,    31,    53,    29,    28,    67,    -1,
      24,    47,    31,    53,    29,    28,    67,    -1,    30,    31,
      53,    29,    -1,    25,    62,    26,    60,    -1,    70,    62,
      -1,     9,    27,    49,    71,    50,    -1,    10,    27,    49,
      71,    50,    -1,     6,    27,    49,    71,    50,    -1,    11,
      27,    49,    71,    50,    -1,    71,    32,     9,    27,    -1,
      71,    32,    10,    27,    -1,    71,    32,     6,    27,    -1,
      71,    32,    11,    27,    -1,     9,    27,    -1,    10,    27,
      -1,     6,    27,    -1,    11,    27,    -1,    27,    49,    73,
      50,    -1,    73,    32,    74,    -1,    74,    -1,    27,    -1,
      45,    -1,    46,    -1,    47,    -1,    60,    -1,    33,    27,
      -1,    33,    45,    -1,    33,    46,    -1,    33,    47,    -1,
      33,    60,    -1,    33,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    49,    51,    52,    55,    56,    57,    58,
      59,    60,    61,    64,    65,    66,    67,    68,    69,    70,
      71,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    89,    90,    91,    92,    93,    94,    95,
      96,    99,   119,   122,   136,   137,   138,   152,   155,   161,
     166,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   189,   190,   191,   192,
     195,   198,   199,   212,   214,   216,   218,   219,   220,   221,
     222,   223,   226,   229,   231,   232,   233,   234,   237,   238,
     239,   240,   241,   242,   243,   244,   247,   250,   250,   252,
     253,   254,   255,   256,   259,   260,   261,   262,   263,   264
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SCOPE_OPEN", "SCOPE_CLOSE", "CONST",
  "BOOL", "TRUE", "FALSE", "INT", "FLOAT", "CHAR", "MULTIPLY", "DIVISIDE",
  "PLUS", "MINUS", "EQUAL", "IF_STATMENT", "THEN", "ELSE", "ELSE_IF",
  "WHILE", "FOR", "SWITCH_STATEMENT", "CASE", "REPEAT_STATEMENT", "UNTILL",
  "VAR", "END_EXPR", "BREAK", "DEFAULT", "COLON", "COMMA", "RETURN", "IS",
  "MATCH", "GreaterThanOrEqual", "LessThanOrEqual", "EqualEqual",
  "NotEqual", "LessThan", "GreaterThan", "OR", "AND", "NOT", "INT_VALUE",
  "DECIMAL_VALUE", "CHAR_VALUE", "IFX", "'('", "')'", "$accept", "program",
  "statements", "statement", "var_declaration", "const_declaration",
  "math_expr", "term", "factor", "logic_expr", "assignment", "scope",
  "if_clause", "while_loop", "for_loop", "switch_case", "switch_body",
  "REPEATUNTILL", "FUNCTION_STATEMENT", "FUNCTION_DEFINITION",
  "PARAMETERS", "FUNCTION_CALL", "CALL_PARAMETERS", "DATA",
  "RETURN_STATEMENT", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    40,
      41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    57,    58,    58,    58,    59,    59,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    61,    61,    61,
      62,    63,    63,    64,    65,    66,    67,    67,    67,    67,
      67,    67,    68,    69,    70,    70,    70,    70,    71,    71,
      71,    71,    71,    71,    71,    71,    72,    73,    73,    74,
      74,    74,    74,    74,    75,    75,    75,    75,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     2,     1,     1,     2,
       2,     2,     2,     2,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     5,     5,     5,     5,     5,     5,     5,
       5,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     3,     3,     3,     3,
       3,     4,     6,     5,     9,     5,     7,     7,     7,     7,
       7,     4,     4,     2,     5,     5,     5,     5,     4,     4,
       4,     4,     2,     2,     2,     2,     4,     3,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,    64,    65,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,   109,     0,    48,    49,
       0,     0,     2,     5,     0,     0,     0,    43,    46,     0,
       0,    11,    12,    13,    14,    15,    17,    18,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    21,    22,    24,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    47,    48,    49,   107,   108,    54,     0,     0,
       1,     4,     6,     7,     0,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     9,     0,     0,    10,    83,
      19,    20,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,    68,    66,    67,    69,    61,    62,    63,    47,
      48,    49,   102,   103,     0,    98,    50,    51,    47,     0,
      41,    42,    55,    58,    57,    60,    59,    56,    44,    45,
      52,    53,     0,     0,     0,     0,    27,    31,     0,     0,
       0,     0,     0,    47,    25,    29,     0,    26,    30,     0,
       0,    28,    32,     0,    71,     0,     0,     0,    82,     0,
      96,     0,    35,    39,    33,    37,    34,    38,    36,    40,
      94,    92,    93,    95,     0,    86,    84,    85,    87,     0,
      73,     0,     0,     0,    75,    97,     0,     0,     0,     0,
      72,     0,     0,     0,     0,     0,     0,     0,    90,    88,
      89,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    74,     0,     0,     0,
       0,     0,    16,    16,    16,    16,    16,    77,    78,    76,
      79,    80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,   194,    36,    37,    38,
     152,    39,   124,   125,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -51
static const yytype_int16 yypact[] =
{
     260,   260,   471,   -22,   -51,   -51,     3,    33,    55,     0,
     -31,    35,    37,   108,    96,    85,    21,     0,   -51,   -51,
       0,   118,   260,   -51,    94,   116,   151,   171,   -51,   105,
     128,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   108,   140,
     150,   215,    81,   101,   112,   114,     4,    20,    34,    40,
     146,   213,    -9,     0,   170,   178,   183,    70,   222,   188,
      80,   -51,   211,   189,   219,   -51,   214,   -51,     2,   191,
     -51,   -51,   -51,   -51,   -14,   -14,   -51,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -51,     0,     0,   -51,   -51,
     -51,   -51,   -51,   246,   258,   268,   270,   113,   477,   125,
     477,   125,   477,    52,   477,   260,   230,   272,   264,   193,
       0,   159,   -51,   213,   214,   -51,   -51,   -51,   -51,   100,
     -13,   111,   -51,   214,   122,   -51,   -51,   -51,   -51,   -14,
     171,   171,   261,   261,   261,   261,   261,   261,   -51,   -51,
     236,   252,   113,   125,   125,    63,   214,   -51,   276,   280,
     288,   290,   123,   273,   261,   -51,   132,   261,   -51,   135,
     273,   -51,   -51,   145,   300,   108,     0,   -18,   214,    80,
     -51,     8,   214,   -51,   261,   -51,   261,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   487,   -51,   -51,   -51,   -51,   260,
     -51,   168,    17,   292,   -51,   -51,   294,   299,   307,   311,
     -51,   170,   310,   315,   317,   319,   321,   260,   -51,   -51,
     -51,   -51,   303,   260,   260,   260,   260,   260,   291,   108,
     322,   353,   384,   415,   446,    85,   -51,   314,   326,   329,
     337,   341,   -18,   -18,   -18,   -18,   -18,   -51,   -51,   -51,
     -51,   -51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -51,   -51,    -1,   -20,   -51,   -51,    -6,   216,   227,    89,
     -50,   -12,   -51,   -51,   -51,   -51,   267,   -51,   -51,   -51,
      -8,   -42,   -51,   203,   -51
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -107
static const yytype_int16 yytable[] =
{
      41,    56,    71,    51,   108,    46,   192,     4,     5,   105,
      51,    51,   193,   128,    68,   115,    74,    75,    53,  -100,
      97,    71,    74,    75,   202,   203,    89,    50,     4,     5,
      47,    18,    19,    86,    87,   129,    99,  -100,    77,    78,
      79,    80,    81,    82,    17,    18,    19,    51,    62,    20,
     101,   113,   126,    98,    51,   147,   103,   155,   126,   158,
      48,   162,   204,   205,   206,    17,    63,    64,    65,   100,
      20,   132,   133,   134,   135,   136,   137,     4,     5,   160,
      51,    51,    49,   102,    54,   164,    55,     4,     5,   104,
     160,    51,   156,   154,   159,   157,   163,   111,    52,   161,
     173,   175,   177,   179,    51,    66,    67,   119,    93,    69,
     178,     1,    57,    61,    17,    18,    19,   112,    70,    20,
       4,     5,    72,   171,    17,   120,   121,   122,    94,    20,
      58,    59,   -99,    85,    58,    59,    51,   174,   176,    95,
     111,    96,   106,  -101,    73,    60,   114,    86,    87,   123,
     -99,   212,   153,   190,   169,   184,    88,    17,    18,    19,
      51,  -101,    20,    51,   184,    74,    75,   184,    90,   200,
      18,    19,   170,   185,   129,   140,   141,   184,    91,    76,
      58,    59,   186,    83,    84,   187,   146,    77,    78,    79,
      80,    81,    82,    58,    59,   188,   201,   107,    71,   168,
      71,    71,    71,    71,    71,   109,   218,   226,    60,   110,
      86,    87,   220,   221,   222,   223,   224,  -105,     1,    92,
       2,     3,     4,     5,     6,     7,     8,    74,    75,   116,
     117,   172,     9,    86,    87,   118,    10,    11,    12,  -104,
      13,   127,    14,   167,    15,    58,    59,  -106,    16,    77,
      78,    79,    80,    81,    82,   191,    86,    87,   123,    17,
      18,    19,   142,     1,    20,     2,     3,     4,     5,     6,
       7,     8,    86,    87,   143,    74,    75,     9,  -107,    87,
     165,    10,    11,    12,   144,    13,   145,    14,    57,    15,
     130,   131,   166,    16,     1,  -107,     2,     3,     4,     5,
       6,     7,     8,   180,    17,    18,    19,   181,     9,    20,
     138,   139,    10,    11,    12,   182,    13,   183,    14,   189,
     225,   208,    60,   207,    16,     1,   209,     2,     3,     4,
       5,     6,     7,     8,   210,    17,    18,    19,   211,     9,
      20,   213,   232,    10,    11,    12,   214,    13,   215,    14,
     216,   227,   217,   219,   233,    16,     1,   234,     2,     3,
       4,     5,     6,     7,     8,   235,    17,    18,    19,   236,
       9,    20,   195,     0,    10,    11,    12,     0,    13,     0,
      14,     0,   228,     0,     0,     0,    16,     1,     0,     2,
       3,     4,     5,     6,     7,     8,     0,    17,    18,    19,
       0,     9,    20,     0,     0,    10,    11,    12,     0,    13,
       0,    14,     0,   229,     0,     0,     0,    16,     1,     0,
       2,     3,     4,     5,     6,     7,     8,     0,    17,    18,
      19,     0,     9,    20,     0,     0,    10,    11,    12,     0,
      13,     0,    14,     0,   230,     0,     0,     0,    16,     1,
       0,     2,     3,     4,     5,     6,     7,     8,     0,    17,
      18,    19,     0,     9,    20,     0,     0,    10,    11,    12,
       0,    13,     0,    14,     0,   231,     0,    42,     0,    16,
      43,    44,    45,   148,     0,     0,   149,   150,   151,     0,
      17,    18,    19,   196,     0,    20,   197,   198,   199,   237,
     238,   239,   240,   241
};

static const yytype_int16 yycheck[] =
{
       1,    13,    22,     9,    54,    27,    24,     7,     8,    18,
      16,    17,    30,    27,    20,    57,    14,    15,    49,    32,
      16,    41,    14,    15,     7,     8,    38,    27,     7,     8,
      27,    45,    46,    42,    43,    49,    16,    50,    36,    37,
      38,    39,    40,    41,    44,    45,    46,    53,    27,    49,
      16,    57,    50,    49,    60,    97,    16,    99,    50,   101,
      27,   103,    45,    46,    47,    44,    45,    46,    47,    49,
      49,    77,    78,    79,    80,    81,    82,     7,     8,    27,
      86,    87,    27,    49,    49,   105,    49,     7,     8,    49,
      27,    97,   100,    99,   102,   101,   104,    27,     9,    47,
     142,   143,   144,   145,   110,    16,    17,    27,    27,    20,
      47,     3,    16,    28,    44,    45,    46,    47,     0,    49,
       7,     8,    28,   129,    44,    45,    46,    47,    27,    49,
      34,    35,    32,    28,    34,    35,   142,   143,   144,    27,
      27,    27,    53,    32,    28,    49,    57,    42,    43,    60,
      50,   201,    27,   165,    32,    32,    28,    44,    45,    46,
     166,    50,    49,   169,    32,    14,    15,    32,    28,   189,
      45,    46,    50,    50,    49,    86,    87,    32,    28,    28,
      34,    35,    50,    12,    13,    50,    97,    36,    37,    38,
      39,    40,    41,    34,    35,    50,    28,    27,   218,   110,
     220,   221,   222,   223,   224,    27,   207,   219,    49,    26,
      42,    43,   213,   214,   215,   216,   217,    28,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    14,    15,     7,
       8,   142,    17,    42,    43,    47,    21,    22,    23,    28,
      25,    50,    27,    50,    29,    34,    35,    28,    33,    36,
      37,    38,    39,    40,    41,   166,    42,    43,   169,    44,
      45,    46,    16,     3,    49,     5,     6,     7,     8,     9,
      10,    11,    42,    43,    16,    14,    15,    17,    42,    43,
      50,    21,    22,    23,    16,    25,    16,    27,    16,    29,
      74,    75,    28,    33,     3,    43,     5,     6,     7,     8,
       9,    10,    11,    27,    44,    45,    46,    27,    17,    49,
      83,    84,    21,    22,    23,    27,    25,    27,    27,    19,
      29,    27,    49,    31,    33,     3,    27,     5,     6,     7,
       8,     9,    10,    11,    27,    44,    45,    46,    27,    17,
      49,    31,    28,    21,    22,    23,    31,    25,    31,    27,
      31,    29,    31,    50,    28,    33,     3,    28,     5,     6,
       7,     8,     9,    10,    11,    28,    44,    45,    46,    28,
      17,    49,   169,    -1,    21,    22,    23,    -1,    25,    -1,
      27,    -1,    29,    -1,    -1,    -1,    33,     3,    -1,     5,
       6,     7,     8,     9,    10,    11,    -1,    44,    45,    46,
      -1,    17,    49,    -1,    -1,    21,    22,    23,    -1,    25,
      -1,    27,    -1,    29,    -1,    -1,    -1,    33,     3,    -1,
       5,     6,     7,     8,     9,    10,    11,    -1,    44,    45,
      46,    -1,    17,    49,    -1,    -1,    21,    22,    23,    -1,
      25,    -1,    27,    -1,    29,    -1,    -1,    -1,    33,     3,
      -1,     5,     6,     7,     8,     9,    10,    11,    -1,    44,
      45,    46,    -1,    17,    49,    -1,    -1,    21,    22,    23,
      -1,    25,    -1,    27,    -1,    29,    -1,     6,    -1,    33,
       9,    10,    11,     6,    -1,    -1,     9,    10,    11,    -1,
      44,    45,    46,     6,    -1,    49,     9,    10,    11,   232,
     233,   234,   235,   236
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    11,    17,
      21,    22,    23,    25,    27,    29,    33,    44,    45,    46,
      49,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    68,    69,    70,    72,
      75,    53,     6,     9,    10,    11,    27,    27,    27,    27,
      27,    57,    60,    49,    49,    49,    62,    16,    34,    35,
      49,    28,    27,    45,    46,    47,    60,    60,    57,    60,
       0,    54,    28,    28,    14,    15,    28,    36,    37,    38,
      39,    40,    41,    12,    13,    28,    42,    43,    28,    62,
      28,    28,     4,    27,    27,    27,    27,    16,    49,    16,
      49,    16,    49,    16,    49,    18,    60,    27,    61,    27,
      26,    27,    47,    57,    60,    72,     7,     8,    47,    27,
      45,    46,    47,    60,    73,    74,    50,    50,    27,    49,
      58,    58,    57,    57,    57,    57,    57,    57,    59,    59,
      60,    60,    16,    16,    16,    16,    60,    72,     6,     9,
      10,    11,    71,    27,    57,    72,    71,    57,    72,    71,
      27,    47,    72,    71,    54,    50,    28,    50,    60,    32,
      50,    57,    60,    72,    57,    72,    57,    72,    47,    72,
      27,    27,    27,    27,    32,    50,    50,    50,    50,    19,
      62,    60,    24,    30,    67,    74,     6,     9,    10,    11,
      54,    28,     7,     8,    45,    46,    47,    31,    27,    27,
      27,    27,    61,    31,    31,    31,    31,    31,    53,    50,
      53,    53,    53,    53,    53,    29,    62,    29,    29,    29,
      29,    29,    28,    28,    28,    28,    28,    67,    67,    67,
      67,    67
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 48 "yacc.y"
    {printf("program: program statements\n\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 49 "yacc.y"
    {printf("program: Epsilon\n\n");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 57 "yacc.y"
    {printf("statement: expr()\n");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 61 "yacc.y"
    {printf("statement: IF()\n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 99 "yacc.y"
    {   
                                        //check if the type of the expression is the same as the type of the variable
                                        if((yyvsp[(1) - (3)].info).typeId != (yyvsp[(3) - (3)].info).typeId)
                                            {
                                                printf("Error: Type mismatch in math expression\n");
                                                exit(1);
                                            }
                                        if((yyvsp[(1) - (3)].info).typeId == 0)
                                        {
                                            (yyval.info).typeId = 0;
                                            (yyval.info).ival = (yyvsp[(1) - (3)].info).ival + (yyvsp[(3) - (3)].info).ival;
                                            printf("int => math_expr: PLUS term() = %d\n", (yyval.info).ival);
                                        }
                                        else if((yyvsp[(1) - (3)].info).typeId == 1)
                                        {
                                            (yyval.info).typeId = 1;
                                            (yyval.info).fval = (yyvsp[(1) - (3)].info).fval + (yyvsp[(3) - (3)].info).fval;
                                            printf("float => math_expr: PLUS term() = %f\n", (yyval.info).fval);
                                        }
                                    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 119 "yacc.y"
    {   
                                        printf("math_expr: MINUS term()\n");
                                    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 122 "yacc.y"
    { 
                                        (yyval.info).typeId = (yyvsp[(1) - (1)].info).typeId;
                                        if((yyvsp[(1) - (1)].info).typeId == 0)
                                        {   
                                            (yyval.info).ival = (yyvsp[(1) - (1)].info).ival;
                                            printf("int => term = %d and typeId:%d \n" , (yyvsp[(1) - (1)].info).ival , (yyvsp[(1) - (1)].info).typeId );
                                        }
                                        else {
                                            (yyval.info).fval = (yyvsp[(1) - (1)].info).fval;
                                            printf("float => term = %f and typeId:%d \n" , (yyvsp[(1) - (1)].info).fval , (yyvsp[(1) - (1)].info).typeId );
                                        }
                                    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 136 "yacc.y"
    {printf("term: * factor()\n");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 137 "yacc.y"
    {printf("term: / factor()\n");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 138 "yacc.y"
    { 
                                        (yyval.info).typeId = (yyvsp[(1) - (1)].info).typeId;
                                        if((yyvsp[(1) - (1)].info).typeId == 0)
                                        {   
                                            (yyval.info).ival = (yyvsp[(1) - (1)].info).ival;
                                            printf("int => factor = %d and typeId:%d \n" , (yyvsp[(1) - (1)].info).ival , (yyvsp[(1) - (1)].info).typeId );
                                        }
                                        else {
                                            (yyval.info).fval = (yyvsp[(1) - (1)].info).fval;
                                            printf("float => factor = %f and typeId:%d \n" , (yyvsp[(1) - (1)].info).fval , (yyvsp[(1) - (1)].info).typeId );
                                        }
                                    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 152 "yacc.y"
    {   
                                        printf("factor: VARs\n");
                                    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 155 "yacc.y"
    { 
                                        (yyval.info).typeId = 0; // int type
                                        tokensVal[tokenValId++] = (yyvsp[(1) - (1)].intVal);
                                        (yyval.info).ival = (yyvsp[(1) - (1)].intVal);
                                        printf("factor: INT_VALUE = %d\n",(yyvsp[(1) - (1)].intVal));
                                    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 161 "yacc.y"
    {
                                        (yyval.info).typeId = 1; // float type
                                        (yyval.info).fval = (yyvsp[(1) - (1)].floatVal); // float type
                                        printf("factor: DECIMAL_VALUE = %f\n",(yyvsp[(1) - (1)].floatVal));
                                    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 166 "yacc.y"
    {printf("factor: (math_expr))\n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 171 "yacc.y"
    {printf("(logic_expr)\n");}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 172 "yacc.y"
    {printf("logic_expr || logic_expr\n");}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 173 "yacc.y"
    {printf("logic_expr && logic_expr\n");}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 174 "yacc.y"
    {printf("!logic_expr\n");}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 175 "yacc.y"
    {printf("statement >= statement\n");}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 176 "yacc.y"
    {printf("statement > statement\n");}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 177 "yacc.y"
    {printf("statement == statement\n");}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 178 "yacc.y"
    {printf("statement <= statement\n");}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 179 "yacc.y"
    {printf("statement < statement\n");}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 180 "yacc.y"
    {printf("statement != statement\n");}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 184 "yacc.y"
    {printf("True\n");}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 185 "yacc.y"
    {printf("False\n");}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 189 "yacc.y"
    {printf("assignment: VAR = math_expr\n");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 190 "yacc.y"
    {printf("assignment: VAR = logic_expr\n");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 191 "yacc.y"
    {printf("assignment: VAR = CHAR_VALUE\n");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 192 "yacc.y"
    {printf("assignment: VAR = Function call\n");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 195 "yacc.y"
    {printf("this is a scope\n");}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 198 "yacc.y"
    {printf("if-then");}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 199 "yacc.y"
    {printf("if-else");}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 247 "yacc.y"
    {printf("function_call \n");;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 250 "yacc.y"
    {printf("call parameters\n");;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 252 "yacc.y"
    {printf("Data Var \n");;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 253 "yacc.y"
    {printf("Data int \n");;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 254 "yacc.y"
    {printf("Data floa \nt");;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 255 "yacc.y"
    {printf("Data char \n");;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 256 "yacc.y"
    {printf("Data bool \n");;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 259 "yacc.y"
    {printf("return Var \n");;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 260 "yacc.y"
    {printf("return int \n");;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 261 "yacc.y"
    {printf("return float \n");;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 262 "yacc.y"
    {printf("return char \n");;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 263 "yacc.y"
    {printf("return bool \n");;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 264 "yacc.y"
    {printf("return \n");;}
    break;



/* Line 1455 of yacc.c  */
#line 2030 "yacc.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 267 "yacc.y"


int main (void) {
    /*yyin = fopen("testfile.txt","r+");
    if(yyin ==NULL){
        printf("File Not Found\n");
    }
    else
    {
        printf(">>>> Parsing the File <<<<\n\n"); 
        yyparse();
    }
    fclose(yyin);*/
    yyparse();
    return 0;
}
