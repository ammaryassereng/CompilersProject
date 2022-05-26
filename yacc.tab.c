
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
    #include "header.h"
    FILE *yyin;
    extern int yylex(void);
    extern void yyerror(char *);
    int tokenValId = 0; 
    int tokensVal [10];

    int scopeId = 0;
    
    void DecAndInit(char* VarName, int scopeID, int* type, int* isconst)
    {
        int isset;
        if(strcmp (GetInfo(VarName,scopeId,type,isconst,&isset), (char*)"1") != 0)
        {   printf("VAR %s :not declared scopeId:%d",VarName,scopeId);
            exit(0);
        }else if(isset != 1){
        printf("VAR %s :not initialized scopeId:%d",VarName,scopeId);
            exit(0);
        }
    }


/* Line 189 of yacc.c  */
#line 101 "yacc.tab.c"

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
#line 28 "yacc.y"

    int intVal;    
    char charVal;               
	float floatVal; 
	char* varName; 

    struct mathinfo{
    int typeId; //0-int, 1-float, 2-char, 3-bool
    int ival;
    float fval;
    int bval;
  }mathinfo;    

  struct logicinfo{
    int bval; //0-false, 1-true
  }logicinfo;  
  struct varinfo{
    int typeId; //0-int, 1-float, 2-char, 3-bool
    int ival;
    float fval;
    int bval; //0-false, 1-true
    char cval;
    char* lexeme;
  }varinfo;                           



/* Line 214 of yacc.c  */
#line 213 "yacc.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 225 "yacc.tab.c"

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
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   529

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNRULES -- Number of states.  */
#define YYNSTATES  245

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
     175,   179,   183,   187,   191,   194,   197,   201,   205,   209,
     213,   217,   221,   225,   229,   233,   235,   237,   241,   245,
     249,   253,   255,   257,   261,   266,   273,   279,   289,   295,
     303,   311,   319,   327,   335,   340,   345,   348,   354,   360,
     366,   372,   377,   382,   387,   392,   395,   398,   401,   404,
     409,   413,   415,   417,   419,   421,   423,   425,   428,   431,
     434,   437,   440
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    -1,    -1,    53,    54,    -1,    54,
      -1,    55,    28,    -1,    56,    28,    -1,    57,    28,    -1,
      60,    28,    -1,    61,    28,    -1,    64,    -1,    65,    -1,
      66,    -1,    67,    -1,    68,    -1,    29,    28,    -1,    70,
      -1,    71,    -1,    74,    28,    -1,    77,    28,    -1,     9,
      27,    -1,    10,    27,    -1,     6,    27,    -1,    11,    27,
      -1,     9,    27,    16,    57,    -1,    10,    27,    16,    57,
      -1,     6,    27,    16,    60,    -1,    11,    27,    16,    47,
      -1,     9,    27,    16,    74,    -1,    10,    27,    16,    74,
      -1,     6,    27,    16,    74,    -1,    11,    27,    16,    74,
      -1,     5,     9,    27,    16,    57,    -1,     5,    10,    27,
      16,    57,    -1,     5,     6,    27,    16,    60,    -1,     5,
      11,    27,    16,    47,    -1,     5,     9,    27,    16,    74,
      -1,     5,    10,    27,    16,    74,    -1,     5,     6,    27,
      16,    74,    -1,     5,    11,    27,    16,    74,    -1,    57,
      14,    58,    -1,    57,    15,    58,    -1,    58,    -1,    58,
      12,    59,    -1,    58,    13,    59,    -1,    59,    -1,    27,
      -1,    45,    -1,    46,    -1,    49,    57,    50,    -1,    49,
      60,    50,    -1,    60,    42,    60,    -1,    60,    43,    60,
      -1,    44,    60,    -1,    44,    27,    -1,    57,    36,    57,
      -1,    57,    41,    57,    -1,    57,    38,    57,    -1,    57,
      37,    57,    -1,    57,    40,    57,    -1,    57,    39,    57,
      -1,    27,    34,     7,    -1,    27,    34,     8,    -1,    27,
      35,    47,    -1,     7,    -1,     8,    -1,    27,    16,    57,
      -1,    27,    16,    60,    -1,    27,    16,    47,    -1,    27,
      16,    74,    -1,     3,    -1,     4,    -1,    62,    53,    63,
      -1,    17,    60,    18,    54,    -1,    17,    60,    18,    54,
      19,    54,    -1,    21,    49,    60,    50,    64,    -1,    22,
      49,    61,    28,    60,    28,    61,    50,    64,    -1,    23,
      49,    27,    50,    69,    -1,    24,    45,    31,    53,    29,
      28,    69,    -1,    24,     7,    31,    53,    29,    28,    69,
      -1,    24,     8,    31,    53,    29,    28,    69,    -1,    24,
      46,    31,    53,    29,    28,    69,    -1,    24,    47,    31,
      53,    29,    28,    69,    -1,    30,    31,    53,    29,    -1,
      25,    64,    26,    60,    -1,    72,    64,    -1,     9,    27,
      49,    73,    50,    -1,    10,    27,    49,    73,    50,    -1,
       6,    27,    49,    73,    50,    -1,    11,    27,    49,    73,
      50,    -1,    73,    32,     9,    27,    -1,    73,    32,    10,
      27,    -1,    73,    32,     6,    27,    -1,    73,    32,    11,
      27,    -1,     9,    27,    -1,    10,    27,    -1,     6,    27,
      -1,    11,    27,    -1,    27,    49,    75,    50,    -1,    75,
      32,    76,    -1,    76,    -1,    27,    -1,    45,    -1,    46,
      -1,    47,    -1,    60,    -1,    33,    27,    -1,    33,    45,
      -1,    33,    46,    -1,    33,    47,    -1,    33,    60,    -1,
      33,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    79,    79,    80,    82,    83,    86,    87,    88,    89,
      90,    91,    92,    95,    96,    97,    98,    99,   100,   101,
     102,   106,   113,   120,   127,   134,   151,   168,   178,   188,
     189,   190,   191,   194,   211,   228,   238,   248,   249,   250,
     251,   254,   276,   299,   313,   336,   357,   371,   395,   400,
     405,   421,   425,   428,   431,   434,   442,   446,   450,   454,
     458,   462,   466,   478,   486,   497,   501,   508,   533,   551,
     569,   572,   573,   575,   578,   579,   592,   594,   596,   598,
     599,   600,   601,   602,   603,   606,   609,   611,   612,   613,
     614,   617,   618,   619,   620,   621,   622,   623,   624,   627,
     630,   630,   632,   633,   634,   635,   636,   639,   640,   641,
     642,   643,   644
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
  "math_expr", "term", "factor", "logic_expr", "assignment", "StartScope",
  "EndScope", "scope", "if_clause", "while_loop", "for_loop",
  "switch_case", "switch_body", "REPEATUNTILL", "FUNCTION_STATEMENT",
  "FUNCTION_DEFINITION", "PARAMETERS", "FUNCTION_CALL", "CALL_PARAMETERS",
  "DATA", "RETURN_STATEMENT", 0
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
      60,    60,    60,    60,    60,    60,    60,    61,    61,    61,
      61,    62,    63,    64,    65,    65,    66,    67,    68,    69,
      69,    69,    69,    69,    69,    70,    71,    72,    72,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    73,    74,
      75,    75,    76,    76,    76,    76,    76,    77,    77,    77,
      77,    77,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     2,     1,     1,     2,
       2,     2,     2,     2,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     5,     5,     5,     5,     5,     5,     5,
       5,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       3,     3,     3,     3,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     3,
       3,     1,     1,     3,     4,     6,     5,     9,     5,     7,
       7,     7,     7,     7,     4,     4,     2,     5,     5,     5,
       5,     4,     4,     4,     4,     2,     2,     2,     2,     4,
       3,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    71,     0,     0,    65,    66,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,   112,     0,    48,    49,
       0,     0,     2,     5,     0,     0,     0,    43,    46,     0,
       0,     0,    11,    12,    13,    14,    15,    17,    18,     0,
       0,     0,     0,     0,     0,     0,    23,    21,    22,    24,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    47,    48,    49,   110,   111,    55,    54,     0,
       0,     1,     4,     6,     7,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     9,     0,     0,    10,
       0,    86,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,    69,    67,    68,    70,    62,    63,    64,
      47,    48,    49,   105,   106,     0,   101,    50,    51,    47,
       0,    41,    42,    56,    59,    58,    61,    60,    57,    44,
      45,    52,    53,    72,    73,     0,     0,     0,     0,    27,
      31,     0,     0,     0,     0,     0,    47,    25,    29,     0,
      26,    30,     0,     0,    28,    32,     0,    74,     0,     0,
       0,    85,     0,    99,     0,    35,    39,    33,    37,    34,
      38,    36,    40,    97,    95,    96,    98,     0,    89,    87,
      88,    90,     0,    76,     0,     0,     0,    78,   100,     0,
       0,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,    93,    91,    92,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    77,
       0,     0,     0,     0,     0,    16,    16,    16,    16,    16,
      80,    81,    79,    82,    83
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,   144,    32,    33,    34,    35,    36,   197,    37,
      38,    39,   155,    40,   125,   126,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -51
static const yytype_int16 yypact[] =
{
     238,   -51,   493,    11,   -51,   -51,    23,    57,    62,    22,
     -37,    44,    48,    97,    -3,    84,    72,   107,   -51,   -51,
      22,   126,   238,   -51,    92,   105,   477,    12,   -51,   142,
     118,   238,   -51,   -51,   -51,   -51,   -51,   -51,   -51,    97,
     145,   154,   121,   131,   151,   159,    -9,    -8,    -1,     3,
     223,   457,    60,    22,   167,   170,   166,    83,    26,   175,
     115,   -51,   203,   173,   198,   -51,   226,   448,   -51,   440,
     -15,   -51,   -51,   -51,   -51,    98,    98,   -51,    98,    98,
      98,    98,    98,    98,    98,    98,   -51,    22,    22,   -51,
     207,   -51,   -51,   -51,   217,   219,   234,   248,   130,   500,
     150,   500,   150,   500,     9,   500,   238,   177,   250,   211,
     192,    22,   101,   -51,   457,   226,   -51,   -51,   -51,   -51,
     133,   -11,     5,   -51,   226,    51,   -51,   -51,   -51,   -51,
      98,    12,    12,   274,   274,   274,   274,   274,   274,   -51,
     -51,   257,   227,   -51,   -51,   130,   150,   150,    15,   226,
     -51,   235,   254,   258,   266,    54,   205,   274,   -51,    63,
     274,   -51,    99,   205,   -51,   -51,   148,   276,    97,    22,
      40,   226,   115,   -51,     8,   226,   -51,   274,   -51,   274,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   513,   -51,   -51,
     -51,   -51,   238,   -51,   165,    -2,   242,   -51,   -51,   270,
     277,   285,   289,   -51,   167,   293,   295,   297,   301,   304,
     238,   -51,   -51,   -51,   -51,   251,   238,   238,   238,   238,
     238,   269,    97,   300,   331,   362,   393,   424,    84,   -51,
     315,   319,   322,   323,   327,    40,    40,    40,    40,    40,
     -51,   -51,   -51,   -51,   -51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -51,   -51,   -29,   -21,   -51,   -51,    -6,   244,   246,     0,
     -50,   -51,   -51,   -13,   -51,   -51,   -51,   -51,   290,   -51,
     -51,   -51,   120,   -39,   -51,   185,   -51
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -110
static const yytype_int16 yytable[] =
{
      56,    72,    90,    51,   109,   205,   206,    98,   100,    52,
      51,    51,    53,    57,    69,   102,    66,    68,   116,   104,
      70,  -103,    75,    76,    84,    85,    91,    87,    88,     4,
       5,    58,    59,   117,   118,   128,   163,  -104,    46,  -103,
      99,   101,   163,   207,   208,   209,    60,    51,   103,    50,
      47,   114,   105,   107,    51,  -104,   164,   115,   127,   150,
     124,   158,   181,   161,   195,   165,    17,    18,    19,    72,
     196,    20,   133,   134,   135,   136,   137,   138,   106,     4,
       5,    51,    51,   172,    48,   167,   187,   141,   142,    49,
       4,     5,    51,    54,   157,   187,   160,    55,   149,    62,
       1,   173,    87,    88,   188,    51,   176,   178,   180,   182,
     112,   171,    61,   189,     4,     5,    17,    63,    64,    65,
      73,    20,     4,     5,   174,   129,    71,    17,    18,    19,
     113,   187,    20,    74,    67,    58,    59,     4,     5,    51,
     177,   179,   120,    18,    19,   175,    89,   130,    94,   190,
      60,    17,    18,    19,   215,   193,    20,   112,    95,    17,
     121,   122,   123,    51,    20,  -102,    51,    58,    59,   194,
      86,   203,   124,    92,    17,    18,    19,   156,    96,    20,
     187,   221,    93,  -102,    87,    88,    97,   223,   224,   225,
     226,   227,   111,   204,   108,    18,    19,   110,   191,   130,
      72,  -108,    72,    72,    72,    72,    72,    87,    88,   229,
       1,   143,     2,     3,     4,     5,     6,     7,     8,    87,
      88,   159,   119,   162,     9,   166,  -109,   168,    10,    11,
      12,  -107,    13,   145,    14,   146,    15,    58,    59,   169,
      16,     1,   170,     2,     3,     4,     5,     6,     7,     8,
     147,    17,    18,    19,    60,     9,    20,    58,    59,    10,
      11,    12,   183,    13,   148,    14,    57,    15,    87,    88,
    -110,    16,     1,   210,     2,     3,     4,     5,     6,     7,
       8,   184,    17,    18,    19,   185,     9,    20,    75,    76,
      10,    11,    12,   186,    13,   192,    14,   211,   228,  -110,
      88,   222,    16,     1,   212,     2,     3,     4,     5,     6,
       7,     8,   213,    17,    18,    19,   214,     9,    20,   131,
     132,    10,    11,    12,   216,    13,   217,    14,   218,   230,
     139,   140,   219,    16,     1,   220,     2,     3,     4,     5,
       6,     7,     8,   235,    17,    18,    19,   236,     9,    20,
     237,   238,    10,    11,    12,   239,    13,   198,    14,     0,
     231,     0,     0,     0,    16,     1,     0,     2,     3,     4,
       5,     6,     7,     8,     0,    17,    18,    19,     0,     9,
      20,     0,     0,    10,    11,    12,     0,    13,     0,    14,
       0,   232,     0,     0,     0,    16,     1,     0,     2,     3,
       4,     5,     6,     7,     8,     0,    17,    18,    19,     0,
       9,    20,     0,     0,    10,    11,    12,     0,    13,     0,
      14,     0,   233,     0,     0,     0,    16,     1,     0,     2,
       3,     4,     5,     6,     7,     8,     0,    17,    18,    19,
       0,     9,    20,     0,     0,    10,    11,    12,     0,    13,
       0,    14,     0,   234,    75,    76,     0,    16,     0,     0,
     -47,   -47,   -47,   -47,     0,     0,     0,     0,    17,    18,
      19,    75,    76,    20,     0,     0,    78,    79,    80,    81,
      82,    83,    58,    59,   -47,   -47,   -47,   -47,   -47,   -47,
     127,    75,    76,    78,    79,    80,    81,    82,    83,    42,
       0,     0,    43,    44,    45,    77,   151,     0,     0,   152,
     153,   154,     0,    78,    79,    80,    81,    82,    83,   199,
       0,     0,   200,   201,   202,   240,   241,   242,   243,   244
};

static const yytype_int16 yycheck[] =
{
      13,    22,    31,     9,    54,     7,     8,    16,    16,     9,
      16,    17,    49,    16,    20,    16,    16,    17,    57,    16,
      20,    32,    14,    15,    12,    13,    39,    42,    43,     7,
       8,    34,    35,     7,     8,    50,    27,    32,    27,    50,
      49,    49,    27,    45,    46,    47,    49,    53,    49,    27,
      27,    57,    49,    53,    60,    50,    47,    57,    50,    98,
      60,   100,    47,   102,    24,   104,    44,    45,    46,    90,
      30,    49,    78,    79,    80,    81,    82,    83,    18,     7,
       8,    87,    88,    32,    27,   106,    32,    87,    88,    27,
       7,     8,    98,    49,   100,    32,   102,    49,    98,    27,
       3,    50,    42,    43,    50,   111,   145,   146,   147,   148,
      27,   111,    28,    50,     7,     8,    44,    45,    46,    47,
      28,    49,     7,     8,   130,    27,     0,    44,    45,    46,
      47,    32,    49,    28,    27,    34,    35,     7,     8,   145,
     146,   147,    27,    45,    46,   145,    28,    49,    27,    50,
      49,    44,    45,    46,   204,   168,    49,    27,    27,    44,
      45,    46,    47,   169,    49,    32,   172,    34,    35,   169,
      28,   192,   172,    28,    44,    45,    46,    27,    27,    49,
      32,   210,    28,    50,    42,    43,    27,   216,   217,   218,
     219,   220,    26,    28,    27,    45,    46,    27,    50,    49,
     221,    28,   223,   224,   225,   226,   227,    42,    43,   222,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    42,
      43,   101,    47,   103,    17,   105,    28,    50,    21,    22,
      23,    28,    25,    16,    27,    16,    29,    34,    35,    28,
      33,     3,    50,     5,     6,     7,     8,     9,    10,    11,
      16,    44,    45,    46,    49,    17,    49,    34,    35,    21,
      22,    23,    27,    25,    16,    27,    16,    29,    42,    43,
      43,    33,     3,    31,     5,     6,     7,     8,     9,    10,
      11,    27,    44,    45,    46,    27,    17,    49,    14,    15,
      21,    22,    23,    27,    25,    19,    27,    27,    29,    42,
      43,    50,    33,     3,    27,     5,     6,     7,     8,     9,
      10,    11,    27,    44,    45,    46,    27,    17,    49,    75,
      76,    21,    22,    23,    31,    25,    31,    27,    31,    29,
      84,    85,    31,    33,     3,    31,     5,     6,     7,     8,
       9,    10,    11,    28,    44,    45,    46,    28,    17,    49,
      28,    28,    21,    22,    23,    28,    25,   172,    27,    -1,
      29,    -1,    -1,    -1,    33,     3,    -1,     5,     6,     7,
       8,     9,    10,    11,    -1,    44,    45,    46,    -1,    17,
      49,    -1,    -1,    21,    22,    23,    -1,    25,    -1,    27,
      -1,    29,    -1,    -1,    -1,    33,     3,    -1,     5,     6,
       7,     8,     9,    10,    11,    -1,    44,    45,    46,    -1,
      17,    49,    -1,    -1,    21,    22,    23,    -1,    25,    -1,
      27,    -1,    29,    -1,    -1,    -1,    33,     3,    -1,     5,
       6,     7,     8,     9,    10,    11,    -1,    44,    45,    46,
      -1,    17,    49,    -1,    -1,    21,    22,    23,    -1,    25,
      -1,    27,    -1,    29,    14,    15,    -1,    33,    -1,    -1,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    44,    45,
      46,    14,    15,    49,    -1,    -1,    36,    37,    38,    39,
      40,    41,    34,    35,    36,    37,    38,    39,    40,    41,
      50,    14,    15,    36,    37,    38,    39,    40,    41,     6,
      -1,    -1,     9,    10,    11,    28,     6,    -1,    -1,     9,
      10,    11,    -1,    36,    37,    38,    39,    40,    41,     6,
      -1,    -1,     9,    10,    11,   235,   236,   237,   238,   239
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    11,    17,
      21,    22,    23,    25,    27,    29,    33,    44,    45,    46,
      49,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    64,    65,    66,    67,    68,    70,    71,    72,
      74,    77,     6,     9,    10,    11,    27,    27,    27,    27,
      27,    57,    60,    49,    49,    49,    64,    16,    34,    35,
      49,    28,    27,    45,    46,    47,    60,    27,    60,    57,
      60,     0,    54,    28,    28,    14,    15,    28,    36,    37,
      38,    39,    40,    41,    12,    13,    28,    42,    43,    28,
      53,    64,    28,    28,    27,    27,    27,    27,    16,    49,
      16,    49,    16,    49,    16,    49,    18,    60,    27,    61,
      27,    26,    27,    47,    57,    60,    74,     7,     8,    47,
      27,    45,    46,    47,    60,    75,    76,    50,    50,    27,
      49,    58,    58,    57,    57,    57,    57,    57,    57,    59,
      59,    60,    60,     4,    63,    16,    16,    16,    16,    60,
      74,     6,     9,    10,    11,    73,    27,    57,    74,    73,
      57,    74,    73,    27,    47,    74,    73,    54,    50,    28,
      50,    60,    32,    50,    57,    60,    74,    57,    74,    57,
      74,    47,    74,    27,    27,    27,    27,    32,    50,    50,
      50,    50,    19,    64,    60,    24,    30,    69,    76,     6,
       9,    10,    11,    54,    28,     7,     8,    45,    46,    47,
      31,    27,    27,    27,    27,    61,    31,    31,    31,    31,
      31,    53,    50,    53,    53,    53,    53,    53,    29,    64,
      29,    29,    29,    29,    29,    28,    28,    28,    28,    28,
      69,    69,    69,    69,    69
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
#line 79 "yacc.y"
    {printf("program: program statements\n\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 80 "yacc.y"
    {printf("program: Epsilon\n\n");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 88 "yacc.y"
    {printf("statement: expr()\n");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 92 "yacc.y"
    {printf("statement: IF()\n");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 106 "yacc.y"
    {
                                                        char* res = InserNewElementInitial(0,0,(yyvsp[(2) - (2)].varinfo).lexeme,scopeId);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                        }
                                                    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 113 "yacc.y"
    {
                                                        char* res = InserNewElementInitial(1,0,(yyvsp[(2) - (2)].varinfo).lexeme,scopeId);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                        }
                                                    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 120 "yacc.y"
    {
                                                        char* res = InserNewElementInitial(3,0,(yyvsp[(2) - (2)].varinfo).lexeme,scopeId);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                        }
                                                    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 127 "yacc.y"
    {
                                                        char* res = InserNewElementInitial(2,0,(yyvsp[(2) - (2)].varinfo).lexeme,scopeId);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                        }
                                                    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 134 "yacc.y"
    {
                                                        //check math_expr type
                                                        if((yyvsp[(4) - (4)].mathinfo).typeId != 0 && (yyvsp[(4) - (4)].mathinfo).typeId != 1)
                                                            yyerror("ERROR: Invalid variable assignment");
                                                        char  cval[10];
                                                        if((yyvsp[(4) - (4)].mathinfo).typeId == 0)
                                                        {
                                                            sprintf(cval, "%d", (yyvsp[(4) - (4)].mathinfo).ival);
                                                        } 
                                                        else sprintf(cval, "%f", (yyvsp[(4) - (4)].mathinfo).fval);
                                                        char* res = InserNewElement(0,0,(yyvsp[(2) - (4)].varinfo).lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 151 "yacc.y"
    {
                                                        //check math_expr type
                                                        if((yyvsp[(4) - (4)].mathinfo).typeId != 0 && (yyvsp[(4) - (4)].mathinfo).typeId != 1)
                                                            yyerror("ERROR: Invalid variable assignment type mismatch");
                                                        char  cval[15];
                                                        if((yyvsp[(4) - (4)].mathinfo).typeId == 0)
                                                        {
                                                            sprintf(cval, "%d", (yyvsp[(4) - (4)].mathinfo).ival);
                                                        } 
                                                        else sprintf(cval, "%f", (yyvsp[(4) - (4)].mathinfo).fval);
                                                        char* res = InserNewElement(1,0,(yyvsp[(2) - (4)].varinfo).lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 168 "yacc.y"
    {
                                                        char  cval[1];
                                                        sprintf(cval, "%d", (yyvsp[(4) - (4)].logicinfo).bval);
                                                        char* res = InserNewElement(3,0,(yyvsp[(2) - (4)].varinfo).lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 178 "yacc.y"
    {
                                                        char  cval[1];
                                                        cval[0] = (yyvsp[(4) - (4)].charVal);
                                                        char* res = InserNewElement(2,0,(yyvsp[(2) - (4)].varinfo).lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 194 "yacc.y"
    {
                                                        //check math_expr type
                                                        if((yyvsp[(5) - (5)].mathinfo).typeId != 0 && (yyvsp[(5) - (5)].mathinfo).typeId != 1)
                                                            yyerror("ERROR: Invalid CONST assignment");
                                                        char  cval[10];
                                                        if((yyvsp[(5) - (5)].mathinfo).typeId == 0)
                                                        {
                                                            sprintf(cval, "%d", (yyvsp[(5) - (5)].mathinfo).ival);
                                                        } 
                                                        else sprintf(cval, "%f", (yyvsp[(5) - (5)].mathinfo).fval);
                                                        char* res = InserNewElement(0,1,(yyvsp[(3) - (5)].varinfo).lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 211 "yacc.y"
    {
                                                        //check math_expr type
                                                        if((yyvsp[(5) - (5)].mathinfo).typeId != 0 && (yyvsp[(5) - (5)].mathinfo).typeId != 1)
                                                            yyerror("ERROR: Invalid CONST assignment");
                                                        char  cval[10];
                                                        if((yyvsp[(5) - (5)].mathinfo).typeId == 0)
                                                        {
                                                            sprintf(cval, "%d", (yyvsp[(5) - (5)].mathinfo).ival);
                                                        } 
                                                        else sprintf(cval, "%f", (yyvsp[(5) - (5)].mathinfo).fval);
                                                        char* res = InserNewElement(1,1,(yyvsp[(3) - (5)].varinfo).lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 228 "yacc.y"
    {
                                                        char  cval[1];
                                                        sprintf(cval, "%d", (yyvsp[(5) - (5)].logicinfo).bval);
                                                        char* res = InserNewElement(3,1,(yyvsp[(3) - (5)].varinfo).lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 238 "yacc.y"
    {
                                                        char  cval[1];
                                                        cval[0] = (yyvsp[(5) - (5)].charVal);
                                                        char* res = InserNewElement(2,1,(yyvsp[(3) - (5)].varinfo).lexeme,scopeId,cval);
                                                        if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 254 "yacc.y"
    {   
                                        //check if the type of the expression is the same as the type of the variable
                                        if((yyvsp[(1) - (3)].mathinfo).typeId != (yyvsp[(3) - (3)].mathinfo).typeId)
                                            {
                                                yyerror("WARNING: Type mismatch would cause up casting\n");
                                                (yyval.mathinfo).typeId = 1;
                                                if((yyvsp[(1) - (3)].mathinfo).typeId == 1) (yyval.mathinfo).fval = (yyvsp[(1) - (3)].mathinfo).fval + (yyvsp[(3) - (3)].mathinfo).ival;
                                                else (yyval.mathinfo).fval = (yyvsp[(1) - (3)].mathinfo).ival + (yyvsp[(3) - (3)].mathinfo).fval;
                                            }
                                        else if((yyvsp[(1) - (3)].mathinfo).typeId == 0)
                                        {
                                            (yyval.mathinfo).typeId = 0;
                                            (yyval.mathinfo).ival = (yyvsp[(1) - (3)].mathinfo).ival + (yyvsp[(3) - (3)].mathinfo).ival;
                                            printf("int => math_expr: PLUS term() = %d\n", (yyval.mathinfo).ival);
                                        }
                                        else if((yyvsp[(1) - (3)].mathinfo).typeId == 1)
                                        {
                                            (yyval.mathinfo).typeId = 1;
                                            (yyval.mathinfo).fval = (yyvsp[(1) - (3)].mathinfo).fval + (yyvsp[(3) - (3)].mathinfo).fval;
                                            printf("float => math_expr: PLUS term() = %f\n", (yyval.mathinfo).fval);
                                        }
                                    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 276 "yacc.y"
    {   
                                        //check if the type of the expression is the same as the type of the variable
                                        if((yyvsp[(1) - (3)].mathinfo).typeId != (yyvsp[(3) - (3)].mathinfo).typeId)
                                            {
                                                yyerror("WARNING: Type mismatch would cause up casting\n");
                                                (yyval.mathinfo).typeId = 1;
                                                if((yyvsp[(1) - (3)].mathinfo).typeId == 1) (yyval.mathinfo).fval = (yyvsp[(1) - (3)].mathinfo).fval - (yyvsp[(3) - (3)].mathinfo).ival;
                                                else (yyval.mathinfo).fval = (yyvsp[(1) - (3)].mathinfo).ival - (yyvsp[(3) - (3)].mathinfo).fval;
                                                printf("float => math_expr: MINUS term() = %f\n", (yyval.mathinfo).fval);
                                            }
                                        else if((yyvsp[(1) - (3)].mathinfo).typeId == 0)
                                        {
                                            (yyval.mathinfo).typeId = 0;
                                            (yyval.mathinfo).ival = (yyvsp[(1) - (3)].mathinfo).ival - (yyvsp[(3) - (3)].mathinfo).ival;
                                            printf("int => math_expr: MINUS term() = %d\n", (yyval.mathinfo).ival);
                                        }
                                        else if((yyvsp[(1) - (3)].mathinfo).typeId == 1)
                                        {
                                            (yyval.mathinfo).typeId = 1;
                                            (yyval.mathinfo).fval = (yyvsp[(1) - (3)].mathinfo).fval - (yyvsp[(3) - (3)].mathinfo).fval;
                                            printf("float => math_expr: MINUS term() = %f\n", (yyval.mathinfo).fval);
                                        }
                                    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 299 "yacc.y"
    { 
                                        (yyval.mathinfo).typeId = (yyvsp[(1) - (1)].mathinfo).typeId;
                                        if((yyvsp[(1) - (1)].mathinfo).typeId == 0)
                                        {   
                                            (yyval.mathinfo).ival = (yyvsp[(1) - (1)].mathinfo).ival;
                                            printf("int => term = %d and typeId:%d \n" , (yyvsp[(1) - (1)].mathinfo).ival , (yyvsp[(1) - (1)].mathinfo).typeId );
                                        }
                                        else {
                                            (yyval.mathinfo).fval = (yyvsp[(1) - (1)].mathinfo).fval;
                                            printf("float => term = %f and typeId:%d \n" , (yyvsp[(1) - (1)].mathinfo).fval , (yyvsp[(1) - (1)].mathinfo).typeId );
                                        }
                                    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 313 "yacc.y"
    { 
                                        //check if the type of the expression is the same as the type of the variable
                                        if((yyvsp[(1) - (3)].mathinfo).typeId != (yyvsp[(3) - (3)].mathinfo).typeId)
                                            {
                                                yyerror("WARNING: Type mismatch would cause up casting\n");
                                                (yyval.mathinfo).typeId = 1;
                                                if((yyvsp[(1) - (3)].mathinfo).typeId == 1) (yyval.mathinfo).fval = (yyvsp[(1) - (3)].mathinfo).fval * (yyvsp[(3) - (3)].mathinfo).ival;
                                                else (yyval.mathinfo).fval = (yyvsp[(1) - (3)].mathinfo).ival * (yyvsp[(3) - (3)].mathinfo).fval;
                                                printf("float => term MULTIPLY factor() = %f\n", (yyval.mathinfo).fval);
                                            }
                                        else if((yyvsp[(1) - (3)].mathinfo).typeId == 0)
                                        {
                                            (yyval.mathinfo).typeId = 0;
                                            (yyval.mathinfo).ival = (yyvsp[(1) - (3)].mathinfo).ival * (yyvsp[(3) - (3)].mathinfo).ival;
                                            printf("int => term MULTIPLY factor() = %d\n", (yyval.mathinfo).ival);
                                        }
                                        else if((yyvsp[(1) - (3)].mathinfo).typeId == 1)
                                        {
                                            (yyval.mathinfo).typeId = 1;
                                            (yyval.mathinfo).fval = (yyvsp[(1) - (3)].mathinfo).fval * (yyvsp[(3) - (3)].mathinfo).fval;
                                            printf("float => term MULTIPLY factor() = %f\n", (yyval.mathinfo).fval);
                                        }
                                    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 336 "yacc.y"
    {
                                        //check if the type of the expression is the same as the type of the variable
                                        if((yyvsp[(1) - (3)].mathinfo).typeId != (yyvsp[(3) - (3)].mathinfo).typeId)
                                            {
                                                yyerror("WARNING: Type mismatch would cause up casting\n");
                                                (yyval.mathinfo).typeId = 1;
                                                if((yyvsp[(1) - (3)].mathinfo).typeId == 1) (yyval.mathinfo).fval = (yyvsp[(1) - (3)].mathinfo).fval / (yyvsp[(3) - (3)].mathinfo).ival;
                                                else (yyval.mathinfo).fval = (yyvsp[(1) - (3)].mathinfo).ival / (yyvsp[(3) - (3)].mathinfo).fval;
                                                printf("float => term / factor() = %f\n", (yyval.mathinfo).fval);
                                            }
                                        else if((yyvsp[(1) - (3)].mathinfo).typeId == 0)
                                        {
                                            (yyval.mathinfo).typeId = 0;
                                            (yyval.mathinfo).ival = (yyvsp[(1) - (3)].mathinfo).ival / (yyvsp[(3) - (3)].mathinfo).ival;
                                        }
                                        else if((yyvsp[(1) - (3)].mathinfo).typeId == 1)
                                        {
                                            (yyval.mathinfo).typeId = 1;
                                            (yyval.mathinfo).fval = (yyvsp[(1) - (3)].mathinfo).fval / (yyvsp[(3) - (3)].mathinfo).fval;
                                        }
                                    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 357 "yacc.y"
    { 
                                        (yyval.mathinfo).typeId = (yyvsp[(1) - (1)].mathinfo).typeId;
                                        if((yyvsp[(1) - (1)].mathinfo).typeId == 0)
                                        {   
                                            (yyval.mathinfo).ival = (yyvsp[(1) - (1)].mathinfo).ival;
                                            printf("int => factor = %d and typeId:%d \n" , (yyvsp[(1) - (1)].mathinfo).ival , (yyvsp[(1) - (1)].mathinfo).typeId );
                                        }
                                        else if((yyvsp[(1) - (1)].mathinfo).typeId == 1) {
                                            (yyval.mathinfo).fval = (yyvsp[(1) - (1)].mathinfo).fval;
                                            printf("float => factor = %f and typeId:%d \n" , (yyvsp[(1) - (1)].mathinfo).fval , (yyvsp[(1) - (1)].mathinfo).typeId );
                                        }
                                    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 371 "yacc.y"
    {   
                                        //check if the variable is defined in the symbol table
                                        int type, isconst, isset;
                                        if(strcmp (GetInfo((yyvsp[(1) - (1)].varinfo).lexeme,scopeId,&type,&isconst,&isset), (char*)"1") != 0)
                                        {   char var[4] = "VAR "; char ms[30] = " :not declared";
                                            yyerror(strcat(var,strcat((yyvsp[(1) - (1)].varinfo).lexeme,ms)));
                                        }else if(isset != 1){
                                            char var[4] = "VAR "; char ms[30] = " :not initialized";
                                            yyerror(strcat(var,strcat((yyvsp[(1) - (1)].varinfo).lexeme,ms)));
                                        }
                                        else if (type != 2 ){//not char
                                            (yyval.mathinfo).typeId = type;
                                            if (type == 0)
                                            {
                                                (yyval.mathinfo).ival = GetIntVal((yyvsp[(1) - (1)].varinfo).lexeme,scopeId);
                                            }else if(type == 1) 
                                            {
                                                (yyval.mathinfo).fval = GetFloatVal((yyvsp[(1) - (1)].varinfo).lexeme,scopeId);
                                            } else {
                                                (yyval.mathinfo).bval = GetBoolVal((yyvsp[(1) - (1)].varinfo).lexeme,scopeId);
                                            }
                                        }else   
                                            yyerror("can't use CHAR in math_expr");
                                    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 395 "yacc.y"
    { 
                                        (yyval.mathinfo).typeId = 0; // int type
                                        (yyval.mathinfo).ival = (yyvsp[(1) - (1)].intVal);
                                        printf("factor: INT_VALUE = %d\n",(yyvsp[(1) - (1)].intVal));
                                    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 400 "yacc.y"
    {
                                        (yyval.mathinfo).typeId = 1; // float type
                                        (yyval.mathinfo).fval = (yyvsp[(1) - (1)].floatVal); // float type
                                        printf("factor: DECIMAL_VALUE = %f\n",(yyvsp[(1) - (1)].floatVal));
                                    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 405 "yacc.y"
    {
                                        (yyval.mathinfo).typeId = (yyvsp[(2) - (3)].mathinfo).typeId;
                                        if((yyvsp[(2) - (3)].mathinfo).typeId == 0)
                                        {   
                                            (yyval.mathinfo).ival = (yyvsp[(2) - (3)].mathinfo).ival;
                                            printf("int => factor: (math_expr) = %d and typeId:%d \n" , (yyvsp[(2) - (3)].mathinfo).ival , (yyvsp[(2) - (3)].mathinfo).typeId );
                                        }
                                        else {
                                            (yyval.mathinfo).fval = (yyvsp[(2) - (3)].mathinfo).fval;
                                            printf("float => factor: (math_expr) = %f and typeId:%d \n" , (yyvsp[(2) - (3)].mathinfo).fval , (yyvsp[(2) - (3)].mathinfo).typeId );
                                        }
                                    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 421 "yacc.y"
    {
                                                        (yyval.logicinfo).bval = (yyvsp[(2) - (3)].logicinfo).bval;
                                                        printf("(logic_expr) => %s\n", (yyval.logicinfo).bval ? "true" : "false");
                                                    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 425 "yacc.y"
    {
                                                        (yyval.logicinfo).bval = (yyvsp[(1) - (3)].logicinfo).bval || (yyvsp[(3) - (3)].logicinfo).bval; 
                                                    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 428 "yacc.y"
    { 
                                                        (yyval.logicinfo).bval = (yyvsp[(1) - (3)].logicinfo).bval && (yyvsp[(3) - (3)].logicinfo).bval;
                                                    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 431 "yacc.y"
    {
                                                        (yyval.logicinfo).bval = !(yyvsp[(2) - (2)].logicinfo).bval;
                                                    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 434 "yacc.y"
    {
                                                        int type,isconst;
                                                        DecAndInit((yyvsp[(2) - (2)].varinfo).lexeme,scopeId,&type,&isconst);
                                                        if (type == 3 ){//type bool
                                                            (yyval.logicinfo).bval = !GetBoolVal((yyvsp[(2) - (2)].varinfo).lexeme,scopeId);
                                                        }else   
                                                            yyerror("Type mismatch logic_expr");
                                                    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 442 "yacc.y"
    { 
                                                        (yyval.logicinfo).bval = (((yyvsp[(1) - (3)].mathinfo).typeId == 0) ? (yyvsp[(1) - (3)].mathinfo).ival :(yyvsp[(1) - (3)].mathinfo).fval) >= (((yyvsp[(3) - (3)].mathinfo).typeId == 0) ? (yyvsp[(3) - (3)].mathinfo).ival :(yyvsp[(3) - (3)].mathinfo).fval);
                                                        printf("statement >= statement\n")
                                                    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 446 "yacc.y"
    {   
                                                        (yyval.logicinfo).bval = (((yyvsp[(1) - (3)].mathinfo).typeId == 0) ? (yyvsp[(1) - (3)].mathinfo).ival :(yyvsp[(1) - (3)].mathinfo).fval) > (((yyvsp[(3) - (3)].mathinfo).typeId == 0) ? (yyvsp[(3) - (3)].mathinfo).ival :(yyvsp[(3) - (3)].mathinfo).fval);
                                                        printf("statement > statement\n")
                                                    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 450 "yacc.y"
    {   
                                                        (yyval.logicinfo).bval = (((yyvsp[(1) - (3)].mathinfo).typeId == 0) ? (yyvsp[(1) - (3)].mathinfo).ival :(yyvsp[(1) - (3)].mathinfo).fval) == (((yyvsp[(3) - (3)].mathinfo).typeId == 0) ? (yyvsp[(3) - (3)].mathinfo).ival :(yyvsp[(3) - (3)].mathinfo).fval);
                                                        printf("statement == statement\n")
                                                    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 454 "yacc.y"
    {   
                                                        (yyval.logicinfo).bval = (((yyvsp[(1) - (3)].mathinfo).typeId == 0) ? (yyvsp[(1) - (3)].mathinfo).ival :(yyvsp[(1) - (3)].mathinfo).fval) <= (((yyvsp[(3) - (3)].mathinfo).typeId == 0) ? (yyvsp[(3) - (3)].mathinfo).ival :(yyvsp[(3) - (3)].mathinfo).fval);
                                                        printf("statement <= statement\n")
                                                    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 458 "yacc.y"
    {
                                                        (yyval.logicinfo).bval = (((yyvsp[(1) - (3)].mathinfo).typeId == 0) ? (yyvsp[(1) - (3)].mathinfo).ival :(yyvsp[(1) - (3)].mathinfo).fval) < (((yyvsp[(3) - (3)].mathinfo).typeId == 0) ? (yyvsp[(3) - (3)].mathinfo).ival :(yyvsp[(3) - (3)].mathinfo).fval);   
                                                        printf("statement < statement\n")
                                                    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 462 "yacc.y"
    {  
                                                        (yyval.logicinfo).bval = (((yyvsp[(1) - (3)].mathinfo).typeId == 0) ? (yyvsp[(1) - (3)].mathinfo).ival :(yyvsp[(1) - (3)].mathinfo).fval) != (((yyvsp[(3) - (3)].mathinfo).typeId == 0) ? (yyvsp[(3) - (3)].mathinfo).ival :(yyvsp[(3) - (3)].mathinfo).fval); 
                                                        printf("statement != statement\n")
                                                    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 466 "yacc.y"
    {
                                                        int type,isconst;
                                                        DecAndInit((yyvsp[(1) - (3)].varinfo).lexeme,scopeId,&type,&isconst);
                                                        if (type == 3 ){//type bool
                                                            //$$.bval = !GetBoolVal($1.lexeme,scopeId);
                                                            if(GetBoolVal((yyvsp[(1) - (3)].varinfo).lexeme,scopeId) == 1)
                                                                (yyval.logicinfo).bval = 1;
                                                            else
                                                                (yyval.logicinfo).bval = 0;
                                                        }else   
                                                            yyerror("Type mismatch logic_expr");   
                                                    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 478 "yacc.y"
    {
                                                        int type,isconst;
                                                        DecAndInit((yyvsp[(1) - (3)].varinfo).lexeme,scopeId,&type,&isconst);
                                                        if (type == 3 ){//type bool
                                                            (yyval.logicinfo).bval = !GetBoolVal((yyvsp[(1) - (3)].varinfo).lexeme,scopeId) ? 1 : 0;
                                                        }else   
                                                            yyerror("Type mismatch logic_expr");
                                                    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 486 "yacc.y"
    {
                                                        int type,isconst;
                                                        DecAndInit((yyvsp[(1) - (3)].varinfo).lexeme,scopeId,&type,&isconst);
                                                        if (type == 2 ){//type char
                                                            if(GetCharVal((yyvsp[(1) - (3)].varinfo).lexeme,scopeId) == (yyvsp[(3) - (3)].charVal)) 
                                                                (yyval.logicinfo).bval = 1;
                                                            else 
                                                                (yyval.logicinfo).bval = 0;
                                                        }else   
                                                            yyerror("Type mismatch logic_expr");
                                                    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 497 "yacc.y"
    { 
                                                        (yyval.logicinfo).bval = 1;
                                                        printf("%s\n", (yyval.logicinfo).bval ? "true" : "false");
                                                    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 501 "yacc.y"
    {   
                                                        (yyval.logicinfo).bval = 0;
                                                        printf("%s\n", (yyval.logicinfo).bval ? "true" : "false");
                                                    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 508 "yacc.y"
    {
                                                        int type, isconst, isset;
                                                        if(strcmp (GetInfo((yyvsp[(1) - (3)].varinfo).lexeme,scopeId,&type,&isconst,&isset), (char*)"1") != 0)
                                                        {   printf("VAR %s :not declared scopeId:%d",(yyvsp[(1) - (3)].varinfo).lexeme,scopeId);
                                                            exit(0);
                                                        }
                                                    if ((type == 3 && (yyvsp[(3) - (3)].mathinfo).typeId != 3) || (type != 3 && (yyvsp[(3) - (3)].mathinfo).typeId == 3 ))
                                                        yyerror("ERROR: Invalid variable assignment");     
                                                    if (type != 0 && type != 1) 
                                                        yyerror("ERROR: Invalid variable assignment");   
                                                    char cval[10];
                                                    if ((yyvsp[(3) - (3)].mathinfo).typeId == 0)
                                                        sprintf(cval, "%d", (yyvsp[(3) - (3)].mathinfo).ival);
                                                    else if ((yyvsp[(3) - (3)].mathinfo).typeId == 1)
                                                        sprintf(cval, "%d", (yyvsp[(3) - (3)].mathinfo).fval);
                                                    else if ((yyvsp[(3) - (3)].mathinfo).typeId == 3)
                                                        sprintf(cval, "%d", (yyvsp[(3) - (3)].mathinfo).bval);
                                                    char *res = UpdateVal(type, (yyvsp[(1) - (3)].varinfo).lexeme, scopeId, cval);
                                                    if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }
                                                    printf("assignment: VAR = math_expr\n");
                                                    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 533 "yacc.y"
    {
                                                     int type, isconst, isset;
                                                    if(strcmp (GetInfo((yyvsp[(1) - (3)].varinfo).lexeme,scopeId,&type,&isconst,&isset), (char*)"1") != 0)
                                                        {   printf("VAR %s :not declared scopeId:%d",(yyvsp[(1) - (3)].varinfo).lexeme,scopeId);
                                                            exit(0);
                                                        }
                                                     if (type != 3)
                                                        yyerror("ERROR: Invalid variable assignment");
                                                    char cval[10];
                                                    sprintf(cval, "%d", (yyvsp[(3) - (3)].logicinfo).bval);
                                                    char *res = UpdateVal(type, (yyvsp[(1) - (3)].varinfo).lexeme, scopeId, cval);
                                                    if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }  
                                                        printf("assignment: VAR = logic_expr\n");
                                                    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 551 "yacc.y"
    {
                                                    int type, isconst, isset;
                                                    if(strcmp (GetInfo((yyvsp[(1) - (3)].varinfo).lexeme,scopeId,&type,&isconst,&isset), (char*)"1") != 0)
                                                        {   printf("VAR %s :not declared scopeId:%d",(yyvsp[(1) - (3)].varinfo).lexeme,scopeId);
                                                            exit(0);
                                                        }
                                                     if (type != 2)
                                                        yyerror("ERROR: Invalid variable assignment");
                                                    char cval[1];
                                                    cval[0] = (yyvsp[(3) - (3)].charVal);
                                                    char *res = UpdateVal(type, (yyvsp[(1) - (3)].varinfo).lexeme, scopeId, cval);
                                                    if(strcmp (res, (char *)"1") != 0)
                                                        {
                                                            yyerror(res);
                                                            exit(0);
                                                        }  
                                                        printf("assignment: VAR = CHAR_VALUE\n");
                                                    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 569 "yacc.y"
    {printf("assignment: VAR = Function call\n");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 572 "yacc.y"
    {scopeId++; NewLevel();;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 573 "yacc.y"
    {scopeId--; removeLevel();;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 575 "yacc.y"
    {printf("this is a scope\n");}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 578 "yacc.y"
    {printf("if-then");}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 579 "yacc.y"
    {printf("if-else");}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 627 "yacc.y"
    {printf("function_call \n");;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 630 "yacc.y"
    {printf("call parameters\n");;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 632 "yacc.y"
    {printf("Data Var \n");;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 633 "yacc.y"
    {printf("Data int \n");;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 634 "yacc.y"
    {printf("Data floa \nt");;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 635 "yacc.y"
    {printf("Data char \n");;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 636 "yacc.y"
    {printf("Data bool \n");;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 639 "yacc.y"
    {printf("return Var \n");;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 640 "yacc.y"
    {printf("return int \n");;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 641 "yacc.y"
    {printf("return float \n");;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 642 "yacc.y"
    {printf("return char \n");;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 643 "yacc.y"
    {printf("return bool \n");;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 644 "yacc.y"
    {printf("return \n");;}
    break;



/* Line 1455 of yacc.c  */
#line 2539 "yacc.tab.c"
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
#line 647 "yacc.y"


int main (void) {
    
    NewLevel();
    FILE* ftrans = fopen("transcript.txt","w");
    fprintf(ftrans,"------------- transcript ----------\n");
    fclose(ftrans);
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
    removeLevel();
    return 0;
}
