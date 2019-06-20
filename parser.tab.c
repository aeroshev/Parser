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
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     VARIABLE = 259,
     BOOL = 260,
     FINDEXIT = 261,
     TASK = 262,
     DO = 263,
     GET = 264,
     RESULT = 265,
     MXCOMP = 266,
     ELCOMP = 267,
     MXFALSE = 268,
     MXTRUE = 269,
     NOT = 270,
     AND = 271,
     LOGITIZE = 272,
     DIGITIZE = 273,
     SIZE = 274,
     REDUCE = 275,
     EXTENED = 276,
     R_LEFT = 277,
     R_RIGHT = 278,
     MOVE = 279,
     GET_E = 280,
     VAR = 281,
     ENDLINE = 282,
     FOR = 283,
     BOUNDARY = 284,
     STEP = 285,
     SWITCH = 286,
     PRINT = 287,
     PLEASE = 288,
     THANKS = 289,
     UMINUS = 290
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define VARIABLE 259
#define BOOL 260
#define FINDEXIT 261
#define TASK 262
#define DO 263
#define GET 264
#define RESULT 265
#define MXCOMP 266
#define ELCOMP 267
#define MXFALSE 268
#define MXTRUE 269
#define NOT 270
#define AND 271
#define LOGITIZE 272
#define DIGITIZE 273
#define SIZE 274
#define REDUCE 275
#define EXTENED 276
#define R_LEFT 277
#define R_RIGHT 278
#define MOVE 279
#define GET_E 280
#define VAR 281
#define ENDLINE 282
#define FOR 283
#define BOUNDARY 284
#define STEP 285
#define SWITCH 286
#define PRINT 287
#define PLEASE 288
#define THANKS 289
#define UMINUS 290




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

    #define YYDEBUG 0
    #define YYERROR_VERBOSE 0
    #include "Prog.h"

    extern FILE * yyin;
    extern int yylineno;
    extern int yy_flex_debug;

    int yylex(void);
    void yyerror(char *s);
    void COMP_ERROR(const char*);
    Vertex* ERROR(const std::string&, int);

    bool errorFlag = false;

    std::vector<std::vector<uint64_t> > map = { {1, 1, 1, 1, 1, 1, 1},
                                                {1, 0, 0, 0, 1, 0, 1},
                                                {1, 1, 1, 0, 1, 0, 1},
                                                {1, 0, 0, 0, 0, 0, 1},
                                                {1, 1, 1, 0, 1, 1, 1},
                                                {1, 0, 0, 0, 0, 0, 1},
                                                {1, 1, 1, 1, 1, 2, 1} };

    std::pair<uint64_t, uint64_t> start = std::make_pair(1, 1);
    std::pair<uint64_t, uint64_t> vision = std::make_pair(1, 0);


    MAIN_CLASS machine(start, vision, map);

    void freeNode(Vertex *);



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
#line 36 "parser.y"
{
    Vertex *nPtr;
    int iValue;
    bool iBool;
    char* iName;  
}
/* Line 193 of yacc.c.  */
#line 207 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 232 "parser.tab.c"

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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   921

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNRULES -- Number of states.  */
#define YYNSTATES  275

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,    37,    35,    44,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
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
      41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    19,
      31,    39,    45,    57,    61,    73,    81,    92,    99,   104,
     107,   115,   119,   123,   131,   135,   138,   140,   144,   146,
     150,   152,   154,   156,   158,   160,   162,   167,   172,   176,
     180,   184,   188,   192,   196,   200,   204,   206,   208,   210,
     212,   214,   217,   220,   223,   228,   233,   237,   242,   245,
     248,   251,   254,   257,   260,   263,   266,   270,   275,   279,
     281,   283,   285,   287,   289,   291,   293,   295,   297,   300,
     303,   307,   311,   315,   319,   328,   337,   344,   351,   355,
     358,   363,   368,   372,   377,   380,   391,   394,   404,   414,
     424,   432,   443,   446,   450,   452,   455,   463,   471,   476,
     481,   489,   494,   501,   509,   517,   525,   533,   537,   545,
     553,   556,   559,   562,   568,   574,   580,   586,   591,   595,
     598,   604,   610,   615,   619
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    49,    -1,    48,    49,    -1,
      51,    -1,    27,    -1,    60,    -1,    50,    60,    -1,     7,
       4,     4,    44,    42,    53,    43,    27,    50,    10,     4,
      -1,     7,     4,     4,    27,    50,    10,     4,    -1,     7,
       6,    27,    50,    10,    -1,     7,     4,     4,     1,    42,
      53,    43,    27,    50,    10,     4,    -1,     7,     4,     1,
      -1,     7,     1,     4,    44,    42,    53,    43,    27,    50,
      10,     4,    -1,     7,     1,     4,    27,    50,    10,     4,
      -1,     7,     4,     4,    44,    42,    53,    43,    27,    50,
       1,    -1,     7,     4,     4,    27,    50,     1,    -1,     7,
       6,    27,    50,    -1,     7,     1,    -1,     8,     4,     4,
      44,    42,    53,    43,    -1,     8,     4,     4,    -1,     8,
       1,     4,    -1,     8,     1,     4,    44,    42,    53,    43,
      -1,     8,     4,     1,    -1,     8,     1,    -1,     4,    -1,
      53,    44,     4,    -1,    55,    -1,    54,    44,    55,    -1,
       5,    -1,     3,    -1,     4,    -1,    56,    -1,    57,    -1,
      58,    -1,     4,    42,    54,    43,    -1,     4,    42,     1,
      43,    -1,     4,    42,    54,    -1,    39,    55,    40,    -1,
      39,     1,    40,    -1,    55,    35,    55,    -1,    55,    37,
      55,    -1,    55,    36,    55,    -1,    55,    38,    55,    -1,
      55,    16,    55,    -1,    24,    -1,    22,    -1,    23,    -1,
      25,    -1,    59,    -1,    36,    55,    -1,    15,    55,    -1,
      15,     1,    -1,    19,    39,     4,    40,    -1,    19,    39,
       4,     1,    -1,    19,    39,    40,    -1,    19,    39,     1,
      40,    -1,    19,     1,    -1,     9,     4,    -1,    11,    55,
      -1,    12,    55,    -1,    14,    55,    -1,    13,    55,    -1,
      61,    27,    -1,     1,    27,    -1,    33,    61,    27,    -1,
      33,    61,    34,    27,    -1,    61,    34,    27,    -1,    27,
      -1,    65,    -1,    67,    -1,    68,    -1,    51,    -1,    52,
      -1,    57,    -1,    64,    -1,    62,    -1,    32,     4,    -1,
      32,     1,    -1,     4,    45,    55,    -1,     4,     1,    55,
      -1,    63,    45,    55,    -1,    63,     1,    55,    -1,    31,
      55,     5,    50,    42,     5,    50,    43,    -1,    31,    55,
       5,    50,    42,     5,    50,     1,    -1,    31,    55,     5,
      50,    42,     1,    -1,    31,    55,     5,    50,     1,     5,
      -1,    31,    55,     1,    -1,    31,     1,    -1,     4,    42,
      54,    43,    -1,     4,    42,     1,    43,    -1,     4,    42,
      43,    -1,     4,    42,    54,     1,    -1,     4,     1,    -1,
      28,     4,    29,     4,    30,     4,    27,    39,    50,    40,
      -1,    28,     1,    -1,    28,    29,     4,    30,     4,    27,
      39,    50,    40,    -1,    28,     4,    29,    30,     4,    27,
      39,    50,    40,    -1,    28,     4,    29,     4,    30,    27,
      39,    50,    40,    -1,    28,     4,    29,     4,    30,     4,
       1,    -1,    28,     4,    29,     4,    30,     4,    27,    39,
      50,     1,    -1,    39,    40,    -1,    39,    66,    40,    -1,
      60,    -1,    66,    60,    -1,    26,     4,    42,    54,    43,
      45,     3,    -1,    26,     4,    42,    54,    43,    45,     5,
      -1,    26,     4,    45,     3,    -1,    26,     4,    45,     5,
      -1,    26,     4,    42,    54,    43,    45,     1,    -1,    26,
       4,    45,     1,    -1,    26,     4,    42,    54,    43,     1,
      -1,    26,     4,    42,    54,     1,    45,     3,    -1,    26,
       4,    42,    54,     1,    45,     5,    -1,    26,     4,    42,
       1,    43,    45,     3,    -1,    26,     4,    42,     1,    43,
      45,     5,    -1,    26,     4,     1,    -1,    26,     1,    42,
      54,    43,    45,     3,    -1,    26,     1,    42,    54,    43,
      45,     5,    -1,    26,     1,    -1,    17,     4,    -1,    18,
       4,    -1,    20,     4,    42,     3,    43,    -1,    21,     4,
      42,     3,    43,    -1,    20,     4,    42,     3,     1,    -1,
      20,     4,    42,     1,    43,    -1,    20,     4,    42,     1,
      -1,    20,     4,     1,    -1,    20,     1,    -1,    21,     4,
      42,     3,     1,    -1,    21,     4,    42,     1,    43,    -1,
      21,     4,    42,     1,    -1,    21,     4,     1,    -1,    21,
       1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    82,    83,    87,    88,    92,    93,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     111,   112,   113,   114,   115,   116,   120,   121,   125,   126,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   144,   145,   146,   147,   148,   152,   153,   154,   155,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     172,   173,   174,   175,   179,   180,   181,   182,   183,   184,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   206,   207,   208,   209,   210,   211,
     215,   216,   217,   218,   219,   223,   224,   225,   226,   227,
     228,   229,   233,   234,   238,   239,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "VARIABLE", "BOOL",
  "FINDEXIT", "TASK", "DO", "GET", "RESULT", "MXCOMP", "ELCOMP", "MXFALSE",
  "MXTRUE", "NOT", "AND", "LOGITIZE", "DIGITIZE", "SIZE", "REDUCE",
  "EXTENED", "R_LEFT", "R_RIGHT", "MOVE", "GET_E", "VAR", "ENDLINE", "FOR",
  "BOUNDARY", "STEP", "SWITCH", "PRINT", "PLEASE", "THANKS", "'+'", "'-'",
  "'*'", "'/'", "'('", "')'", "UMINUS", "'['", "']'", "','", "'='",
  "$accept", "program", "function_list", "function_s", "statement_list",
  "function_definition", "call_definition", "declaration_list",
  "expression_list", "expression", "binary_operation", "robot_operation",
  "unary_operation", "compare_operation", "statement", "statement_s",
  "switch_state", "appeal_state", "for_loop", "compound_statement",
  "block_item", "definition", "unary_statement", 0
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
     285,   286,   287,   288,   289,    43,    45,    42,    47,    40,
      41,   290,    91,    93,    44,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      52,    52,    52,    52,    52,    52,    53,    53,    54,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    56,    56,    57,    57,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    62,    62,    62,    62,    62,
      63,    63,    63,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    65,    65,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     2,    11,
       7,     5,    11,     3,    11,     7,    10,     6,     4,     2,
       7,     3,     3,     7,     3,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     4,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     2,     2,     2,     4,     4,     3,     4,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     3,     3,     3,     8,     8,     6,     6,     3,     2,
       4,     4,     3,     4,     2,    10,     2,     9,     9,     9,
       7,    10,     2,     3,     1,     2,     7,     7,     4,     4,
       7,     4,     6,     7,     7,     7,     7,     3,     7,     7,
       2,     2,     2,     5,     5,     5,     5,     4,     3,     2,
       5,     5,     4,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     6,     0,     2,     3,     5,    19,     0,     0,
       1,     4,     0,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    48,
      46,    49,     0,    69,     0,     0,     0,     0,     0,     0,
      73,    74,    75,     7,     0,    77,     0,    76,    70,    71,
      72,     0,     0,     0,     0,     0,    65,    94,     0,     0,
      25,     0,   121,   122,   129,     0,   134,     0,   120,     0,
      96,     0,     0,    89,    31,    32,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      50,    79,    78,     0,   102,   104,     0,    11,     8,    64,
       0,     0,     0,     0,    26,     0,     0,    17,     0,     0,
      81,     0,    92,     0,    28,    80,    22,    24,    21,   128,
       0,   133,     0,     0,   117,     0,     0,     0,     0,     0,
      59,    60,    61,    63,    62,    53,    52,    58,     0,    51,
       0,     0,    88,     0,     0,     0,     0,     0,     0,    66,
       0,   103,   105,    68,    83,    82,    15,     0,     0,     0,
      10,     0,    91,    93,    90,     0,     0,     0,   127,     0,
     132,     0,     0,     0,     0,   111,   108,   109,     0,     0,
       0,     0,    38,     0,     0,    56,    40,    39,     0,    45,
      41,    43,    42,    44,    67,     0,    27,     0,     0,    29,
       0,     0,   126,   125,   123,   131,   130,   124,     0,     0,
       0,     0,     0,     0,     0,    37,    36,    57,    55,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,     0,     0,     0,     0,     0,    87,    86,     0,     0,
       0,    16,     0,    23,    20,   118,   119,   115,   116,   113,
     114,   110,   106,   107,   100,     0,     0,     0,     0,     0,
      14,    12,     9,     0,     0,     0,     0,    85,    84,     0,
      99,    98,    97,   101,    95
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    39,    40,    41,   105,   113,   114,
      87,    42,    89,    90,    43,    44,    45,    46,    47,    48,
      96,    49,    50
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -46
static const yytype_int16 yypact[] =
{
     119,   132,   -46,     7,   119,   -46,   -46,    39,    87,    -9,
     -46,   -46,   113,   -46,     0,   681,   681,   -11,    -5,   681,
     118,    98,     8,   143,   130,   139,   174,   196,   -46,   -46,
     -46,   -46,   206,   -46,    80,   714,   207,   882,   312,   278,
     -46,   -46,   -46,   -46,   -21,   -46,    14,   -46,   -46,   -46,
     -46,   516,   188,   188,   549,   188,   -46,   859,   190,   859,
     202,   215,   -46,   -46,   -46,    22,   -46,    37,   144,    21,
     -46,   209,   213,   -46,   -46,   214,   -46,   220,   859,   859,
     859,   859,   743,    28,   859,   772,    81,   -46,   -46,   -46,
     -46,   -46,   -46,   -15,   -46,   -46,   346,   -46,   -46,   -46,
     221,   859,   859,   251,   -46,    57,   127,    98,   253,   133,
     115,   228,   -46,    27,   115,   115,   232,   -46,   233,   -46,
     195,   -46,   217,   859,   -46,   801,   134,    10,   250,   830,
     -46,   115,   115,   115,   115,   -46,   115,   -46,    35,   -46,
     243,    67,   -46,   681,   859,   859,   859,   859,   859,   -46,
     245,   -46,   -46,   -46,   115,   115,   -46,   260,   254,   262,
     -46,   263,   -46,   -46,   -46,   859,   219,   249,   264,    31,
     265,    33,   184,   271,    29,   -46,   -46,   -46,   267,   288,
     289,   272,   201,   281,    40,   -46,   -46,   -46,   242,   -46,
      92,    92,   -46,   -46,   -46,   681,   -46,   681,   681,   115,
     188,   188,   -46,   -46,   -46,   -46,   -46,   -46,   273,   277,
     279,    20,    83,   296,   298,   -46,   -46,   -46,   -46,   -46,
     101,    84,   582,   615,   648,   208,   210,   218,   231,   234,
     -46,   182,    15,   255,   287,   292,   -46,   -46,   681,   323,
     324,    98,   337,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   303,   681,   681,   681,   141,
     -46,   -46,   -46,   681,   380,   414,   448,    98,   -46,   482,
     -46,   -46,   -46,    98,   -46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   -46,   342,   -16,    94,   -46,   -45,   -30,   -24,
     -46,   -33,   -46,   -46,   -34,   311,   -46,   -46,   -46,   -46,
     -46,   -46,   -46
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -19
static const yytype_int16 yytable[] =
{
      51,    18,    88,    54,    95,    98,    99,    10,   106,    57,
     109,    86,   149,   100,   178,   101,   254,    98,    15,   150,
      98,   230,   124,   119,    88,    88,    88,    19,   163,   137,
     210,    52,   203,   110,   206,   115,   183,    53,   121,   184,
     179,   218,   255,    12,    20,    88,    88,    88,    88,    88,
      58,    88,    88,    59,   131,   132,   133,   134,   136,   102,
     139,   141,   152,   125,   120,   231,   126,   138,    88,    88,
     164,   165,   211,   165,   204,   185,   207,   154,   155,   122,
     219,    70,   142,   144,    71,   237,   143,   232,    13,   238,
      88,    14,    88,   172,     6,   174,    88,   144,     6,   182,
     157,   158,   145,   146,   147,   148,   236,   187,   144,    72,
     233,    88,    88,    88,    88,    88,   145,   146,   147,   148,
     189,   190,   191,   192,   193,    56,     1,   188,    56,   147,
     148,   144,    88,     7,    62,   175,     8,   176,     9,   177,
      16,   199,   267,    63,    60,    22,     2,    61,     1,    23,
     145,   146,   147,   148,    98,   225,   226,    17,    24,    25,
      55,    26,    27,    28,    29,    30,    31,    32,    33,    34,
     159,   158,    35,    36,    37,    64,   161,   158,    65,   222,
      38,   223,   224,   251,   268,   252,   123,   253,    98,    98,
      98,   111,   104,    74,    75,    76,   168,    66,   169,    77,
      67,    78,    79,    80,    81,    82,   116,    68,    91,    83,
      69,    92,    28,    29,    30,    31,   117,   128,   170,   118,
     171,   245,   259,   246,   130,    98,    84,   208,   165,    85,
      98,    98,    98,   112,   247,    98,   248,   249,   127,   250,
     264,   265,   266,   220,   -19,   165,    22,   269,   153,     1,
      23,   243,   158,   244,   158,   156,   129,   160,   196,    24,
      25,   200,    26,    27,    28,    29,    30,    31,    32,    33,
      34,   162,   194,    35,    36,    37,   166,   167,   -18,    21,
     180,    38,    22,   186,   221,     1,    23,   195,    97,   197,
     198,   201,   213,   214,   256,    24,    25,   212,    26,    27,
      28,    29,    30,    31,    32,    33,    34,   202,   205,    35,
      36,    37,   -18,    21,   209,   215,    22,    38,   227,     1,
      23,   217,   228,   234,   229,   235,   257,   260,   261,    24,
      25,   258,    26,    27,    28,    29,    30,    31,    32,    33,
      34,   262,   263,    35,    36,    37,    11,    21,    93,     0,
      22,    38,    94,     1,    23,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,     0,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
       0,    21,     0,     0,    22,    38,   151,     1,    23,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,     0,    21,     0,     0,    22,    38,
     270,     1,    23,     0,     0,     0,     0,     0,     0,     0,
       0,    24,    25,     0,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,     0,    35,    36,    37,     0,    21,
       0,     0,    22,    38,   271,     1,    23,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,     0,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,    35,
      36,    37,     0,   273,     0,     0,    22,    38,   272,     1,
      23,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,     0,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,     0,    35,    36,    37,     0,    21,     0,     0,
      22,    38,   274,     1,    23,     0,   103,     0,     0,     0,
       0,     0,     0,    24,    25,     0,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
     107,     0,     0,    22,     0,    38,     1,    23,     0,   108,
       0,     0,     0,     0,     0,     0,    24,    25,     0,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,     0,
      35,    36,    37,    21,     0,     0,    22,     0,    38,     1,
      23,     0,   239,     0,     0,     0,     0,     0,     0,    24,
      25,     0,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,     0,    35,    36,    37,    21,     0,     0,    22,
       0,    38,     1,    23,     0,   240,     0,     0,     0,     0,
       0,     0,    24,    25,     0,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,   241,
       0,     0,    22,     0,    38,     1,    23,     0,   242,     0,
       0,     0,     0,     0,     0,    24,    25,     0,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,    35,
      36,    37,    21,     0,     0,    22,     0,    38,     1,    23,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    25,
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,    35,    36,    37,    73,     0,    74,    75,    76,
      38,     0,     0,    77,     0,    78,    79,    80,    81,    82,
       0,     0,     0,    83,     0,     0,    28,    29,    30,    31,
       0,     0,     0,     0,   135,     0,    74,    75,    76,     0,
      84,     0,    77,    85,    78,    79,    80,    81,    82,     0,
       0,     0,    83,     0,     0,    28,    29,    30,    31,     0,
       0,     0,     0,   140,     0,    74,    75,    76,     0,    84,
       0,    77,    85,    78,    79,    80,    81,    82,     0,     0,
       0,    83,     0,     0,    28,    29,    30,    31,     0,     0,
       0,     0,   173,     0,    74,    75,    76,     0,    84,     0,
      77,    85,    78,    79,    80,    81,    82,     0,     0,     0,
      83,     0,     0,    28,    29,    30,    31,     0,     0,     0,
       0,   181,     0,    74,    75,    76,     0,    84,     0,    77,
      85,    78,    79,    80,    81,    82,     0,     0,     0,    83,
       0,     0,    28,    29,    30,    31,     0,     0,     0,     0,
       0,     0,    74,    75,    76,     0,    84,     0,    77,    85,
      78,    79,    80,    81,    82,     0,     0,     0,    83,     0,
       0,    28,    29,    30,    31,     0,    22,     0,     0,     1,
      23,     0,     0,     0,     0,    84,     0,     0,    85,    24,
      25,     0,    26,    27,    28,    29,    30,    31,    32,     0,
      34,     0,     0,    35,    36,     0,     0,     0,     0,     0,
       0,    38
};

static const yytype_int16 yycheck[] =
{
      16,     1,    35,    19,    38,    39,    27,     0,    53,     1,
      55,    35,    27,    34,     4,     1,     1,    51,    27,    34,
      54,     1,     1,     1,    57,    58,    59,    27,     1,     1,
       1,    42,     1,    57,     1,    59,     1,    42,     1,     4,
      30,     1,    27,     4,    44,    78,    79,    80,    81,    82,
      42,    84,    85,    45,    78,    79,    80,    81,    82,    45,
      84,    85,    96,    42,    42,    45,    45,    39,   101,   102,
      43,    44,    43,    44,    43,    40,    43,   101,   102,    42,
      40,     1,     1,    16,     4,     1,     5,     4,     1,     5,
     123,     4,   125,   123,     0,   125,   129,    16,     4,   129,
      43,    44,    35,    36,    37,    38,     5,    40,    16,    29,
      27,   144,   145,   146,   147,   148,    35,    36,    37,    38,
     144,   145,   146,   147,   148,    27,     7,   143,    27,    37,
      38,    16,   165,     1,     4,     1,     4,     3,     6,     5,
      27,   165,     1,     4,     1,     4,    27,     4,     7,     8,
      35,    36,    37,    38,   188,   200,   201,    44,    17,    18,
      42,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      43,    44,    31,    32,    33,     1,    43,    44,     4,   195,
      39,   197,   198,     1,    43,     3,    42,     5,   222,   223,
     224,     1,     4,     3,     4,     5,     1,     1,     3,     9,
       4,    11,    12,    13,    14,    15,     4,     1,     1,    19,
       4,     4,    22,    23,    24,    25,     1,     4,     1,     4,
       3,     3,   238,     5,     4,   259,    36,    43,    44,    39,
     264,   265,   266,    43,     3,   269,     5,     3,    29,     5,
     256,   257,   258,     1,    43,    44,     4,   263,    27,     7,
       8,    43,    44,    43,    44,     4,    42,     4,     4,    17,
      18,    42,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    43,    27,    31,    32,    33,    44,    44,     0,     1,
      30,    39,     4,    40,    42,     7,     8,    27,    10,    27,
      27,    42,     4,     4,    39,    17,    18,    30,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    43,    43,    31,
      32,    33,    34,     1,    43,    43,     4,    39,    45,     7,
       8,    40,    45,    27,    45,    27,    39,     4,     4,    17,
      18,    39,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     4,    39,    31,    32,    33,     4,     1,    37,    -1,
       4,    39,    40,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    32,    33,
      -1,     1,    -1,    -1,     4,    39,    40,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    32,    33,    -1,     1,    -1,    -1,     4,    39,
      40,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    -1,     1,
      -1,    -1,     4,    39,    40,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      32,    33,    -1,     1,    -1,    -1,     4,    39,    40,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    32,    33,    -1,     1,    -1,    -1,
       4,    39,    40,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    32,    33,
       1,    -1,    -1,     4,    -1,    39,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,    32,    33,     1,    -1,    -1,     4,    -1,    39,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    32,    33,     1,    -1,    -1,     4,
      -1,    39,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    31,    32,    33,     1,
      -1,    -1,     4,    -1,    39,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      32,    33,     1,    -1,    -1,     4,    -1,    39,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    31,    32,    33,     1,    -1,     3,     4,     5,
      39,    -1,    -1,     9,    -1,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    -1,    -1,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,    -1,
      36,    -1,     9,    39,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    -1,    -1,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,    -1,    36,
      -1,     9,    39,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    19,    -1,    -1,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,    -1,    36,    -1,
       9,    39,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,    -1,    36,    -1,     9,
      39,    11,    12,    13,    14,    15,    -1,    -1,    -1,    19,
      -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    36,    -1,     9,    39,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    -1,
      -1,    22,    23,    24,    25,    -1,     4,    -1,    -1,     7,
       8,    -1,    -1,    -1,    -1,    36,    -1,    -1,    39,    17,
      18,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    27,    47,    48,    49,    51,     1,     4,     6,
       0,    49,     4,     1,     4,    27,    27,    44,     1,    27,
      44,     1,     4,     8,    17,    18,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    31,    32,    33,    39,    50,
      51,    52,    57,    60,    61,    62,    63,    64,    65,    67,
      68,    50,    42,    42,    50,    42,    27,     1,    42,    45,
       1,     4,     4,     4,     1,     4,     1,     4,     1,     4,
       1,     4,    29,     1,     3,     4,     5,     9,    11,    12,
      13,    14,    15,    19,    36,    39,    55,    56,    57,    58,
      59,     1,     4,    61,    40,    60,    66,    10,    60,    27,
      34,     1,    45,    10,     4,    53,    53,     1,    10,    53,
      55,     1,    43,    54,    55,    55,     4,     1,     4,     1,
      42,     1,    42,    42,     1,    42,    45,    29,     4,    42,
       4,    55,    55,    55,    55,     1,    55,     1,    39,    55,
       1,    55,     1,     5,    16,    35,    36,    37,    38,    27,
      34,    40,    60,    27,    55,    55,     4,    43,    44,    43,
       4,    43,    43,     1,    43,    44,    44,    44,     1,     3,
       1,     3,    54,     1,    54,     1,     3,     5,     4,    30,
      30,     1,    54,     1,     4,    40,    40,    40,    50,    55,
      55,    55,    55,    55,    27,    27,     4,    27,    27,    55,
      42,    42,    43,     1,    43,    43,     1,    43,    43,    43,
       1,    43,    30,     4,     4,    43,    43,    40,     1,    40,
       1,    42,    50,    50,    50,    53,    53,    45,    45,    45,
       1,    45,     4,    27,    27,    27,     5,     1,     5,    10,
      10,     1,    10,    43,    43,     3,     5,     3,     5,     3,
       5,     1,     3,     5,     1,    27,    39,    39,    39,    50,
       4,     4,     4,    39,    50,    50,    50,     1,    43,    50,
      40,    40,    40,     1,    40
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



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

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

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
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 71 "parser.y"
    { 
                                                    if (!errorFlag)
                                                    {
                                                        machine.check_main((yyvsp[(1) - (1)].nPtr)); 
                                                    }
                                                    freeNode((yyvsp[(1) - (1)].nPtr));
                                                    exit(0);    
                                                ;}
    break;

  case 3:
#line 82 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 4:
#line 83 "parser.y"
    { (yyval.nPtr) = machine.create("ENDLINE", 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 5:
#line 87 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 6:
#line 88 "parser.y"
    { (yyval.nPtr) = nullptr; ;}
    break;

  case 7:
#line 92 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 8:
#line 93 "parser.y"
    { (yyval.nPtr) = machine.create("ENDLINE", 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 9:
#line 97 "parser.y"
    { (yyval.nPtr) = nullptr; machine.putFunc((yyvsp[(2) - (11)].iName), (yyvsp[(3) - (11)].iName), (yyvsp[(9) - (11)].nPtr), (yyvsp[(11) - (11)].iName)); delete (yyvsp[(2) - (11)].iName); delete (yyvsp[(3) - (11)].iName); delete (yyvsp[(11) - (11)].iName); ;}
    break;

  case 10:
#line 98 "parser.y"
    { (yyval.nPtr) = nullptr; machine.putFunc((yyvsp[(2) - (7)].iName), (yyvsp[(3) - (7)].iName), (yyvsp[(5) - (7)].nPtr), (yyvsp[(7) - (7)].iName)); delete (yyvsp[(2) - (7)].iName); delete (yyvsp[(3) - (7)].iName); delete (yyvsp[(7) - (7)].iName); ;}
    break;

  case 11:
#line 99 "parser.y"
    { (yyval.nPtr) = (yyvsp[(4) - (5)].nPtr); machine.putFunc((yyvsp[(4) - (5)].nPtr)); ;}
    break;

  case 12:
#line 100 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ','", (yylsp[(4) - (11)]).first_line); yyerrok; ;}
    break;

  case 13:
#line 101 "parser.y"
    { (yyval.nPtr) = ERROR("Missed variable", (yylsp[(2) - (3)]).first_line); yyerrok; ;}
    break;

  case 14:
#line 102 "parser.y"
    { (yyval.nPtr) = ERROR("Missed name function", (yylsp[(2) - (11)]).first_line); yyerrok ; delete (yyvsp[(3) - (11)].iName); delete (yyvsp[(11) - (11)].iName); ;}
    break;

  case 15:
#line 103 "parser.y"
    { (yyval.nPtr) = ERROR("Missed name function", (yylsp[(2) - (7)]).first_line); yyerrok ; delete (yyvsp[(3) - (7)].iName); delete (yyvsp[(7) - (7)].iName); ;}
    break;

  case 16:
#line 104 "parser.y"
    { (yyval.nPtr) = ERROR("Function must end RESULT", (yylsp[(1) - (10)]).first_line); yyerrok; ;}
    break;

  case 17:
#line 105 "parser.y"
    { (yyval.nPtr) = ERROR("Function must end RESULT", (yylsp[(1) - (6)]).first_line); yyerrok; ;}
    break;

  case 18:
#line 106 "parser.y"
    { (yyval.nPtr) = ERROR("Function must end RESULT", (yylsp[(1) - (4)]).first_line); yyerrok; ;}
    break;

  case 19:
#line 107 "parser.y"
    { (yyval.nPtr) = ERROR("Somthening wrong in body function", (yylsp[(2) - (2)]).first_line); yyerrok; ;}
    break;

  case 20:
#line 111 "parser.y"
    { (yyval.nPtr) = machine.funcall("DO", (yyvsp[(2) - (7)].iName), (yyvsp[(3) - (7)].iName), machine.args); delete (yyvsp[(2) - (7)].iName); delete (yyvsp[(3) - (7)].iName); ;}
    break;

  case 21:
#line 112 "parser.y"
    { (yyval.nPtr) = machine.funcall("DO", (yyvsp[(2) - (3)].iName), (yyvsp[(3) - (3)].iName)); delete (yyvsp[(2) - (3)].iName); delete (yyvsp[(3) - (3)].iName); ;}
    break;

  case 22:
#line 113 "parser.y"
    { (yyval.nPtr) = ERROR("Missed name function", (yylsp[(2) - (3)]).first_line); yyerrok; delete (yyvsp[(3) - (3)].iName); ;}
    break;

  case 23:
#line 114 "parser.y"
    { (yyval.nPtr) = ERROR("Missed name function", (yylsp[(2) - (7)]).first_line); yyerrok; delete (yyvsp[(3) - (7)].iName); ;}
    break;

  case 24:
#line 115 "parser.y"
    { (yyval.nPtr) = ERROR("Missed argument function", (yylsp[(3) - (3)]).first_line); yyerrok; delete (yyvsp[(2) - (3)].iName); ;}
    break;

  case 25:
#line 116 "parser.y"
    { (yyval.nPtr) = ERROR("Not atribute for call function", (yylsp[(1) - (2)]).first_line); yyerrok; ;}
    break;

  case 26:
#line 120 "parser.y"
    { (yyval.nPtr) = nullptr; machine.args.push_back((yyvsp[(1) - (1)].iName)); delete (yyvsp[(1) - (1)].iName); ;}
    break;

  case 27:
#line 121 "parser.y"
    { (yyval.nPtr) = nullptr; machine.args.push_back((yyvsp[(3) - (3)].iName)); delete (yyvsp[(3) - (3)].iName); ;}
    break;

  case 28:
#line 125 "parser.y"
    { (yyval.nPtr) = nullptr; machine.exprl.push_back((yyvsp[(1) - (1)].nPtr)); ;}
    break;

  case 29:
#line 126 "parser.y"
    { (yyval.nPtr) = nullptr; machine.exprl.push_back((yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 30:
#line 130 "parser.y"
    { (yyval.nPtr) = machine.constant((yyvsp[(1) - (1)].iBool), "BOOL"); ;}
    break;

  case 31:
#line 131 "parser.y"
    { (yyval.nPtr) = machine.constant((yyvsp[(1) - (1)].iValue), "INT"); ;}
    break;

  case 32:
#line 132 "parser.y"
    { (yyval.nPtr) = machine.id((yyvsp[(1) - (1)].iName)); delete (yyvsp[(1) - (1)].iName); ;}
    break;

  case 33:
#line 133 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 34:
#line 134 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 35:
#line 135 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 36:
#line 136 "parser.y"
    { (yyval.nPtr) = machine.appeal("APPEAL", (yyvsp[(1) - (4)].iName)); delete (yyvsp[(1) - (4)].iName); ;}
    break;

  case 37:
#line 137 "parser.y"
    { (yyval.nPtr) = ERROR("Missed enumeration", (yylsp[(3) - (4)]).first_line); yyerrok; delete (yyvsp[(1) - (4)].iName); ;}
    break;

  case 38:
#line 138 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ']'", (yylsp[(3) - (3)]).first_line); yyerrok; delete (yyvsp[(1) - (3)].iName); ;}
    break;

  case 39:
#line 139 "parser.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); ;}
    break;

  case 40:
#line 140 "parser.y"
    { (yyval.nPtr) = ERROR("Error in ()", (yylsp[(1) - (3)]).first_line); yyerrok; ;}
    break;

  case 41:
#line 144 "parser.y"
    { (yyval.nPtr) = machine.create("+", 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 42:
#line 145 "parser.y"
    { (yyval.nPtr) = machine.create("*", 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 43:
#line 146 "parser.y"
    { (yyval.nPtr) = machine.create("-", 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 44:
#line 147 "parser.y"
    { (yyval.nPtr) = machine.create("/", 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 45:
#line 148 "parser.y"
    { (yyval.nPtr) = machine.create("AND", 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 46:
#line 152 "parser.y"
    { (yyval.nPtr) = machine.robot("MOVE"); ;}
    break;

  case 47:
#line 153 "parser.y"
    { (yyval.nPtr) = machine.robot("ROTATE_LEFT"); ;}
    break;

  case 48:
#line 154 "parser.y"
    { (yyval.nPtr) = machine.robot("ROTATE_RIGHT"); ;}
    break;

  case 49:
#line 155 "parser.y"
    { (yyval.nPtr) = machine.robot("GET_E"); ;}
    break;

  case 50:
#line 159 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 51:
#line 160 "parser.y"
    { (yyval.nPtr) = machine.create("UMINUS",1, (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 52:
#line 161 "parser.y"
    { (yyval.nPtr) = machine.create("NOT", 1, (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 53:
#line 162 "parser.y"
    { (yyval.nPtr) = ERROR("It's not a expression", (yylsp[(1) - (2)]).first_line); yyerrok; ;}
    break;

  case 54:
#line 163 "parser.y"
    { (yyval.nPtr) = machine.create("SIZE", 1, machine.id((yyvsp[(3) - (4)].iName))); delete (yyvsp[(3) - (4)].iName); ;}
    break;

  case 55:
#line 164 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ')'", (yylsp[(4) - (4)]).first_line);;}
    break;

  case 56:
#line 165 "parser.y"
    { (yyval.nPtr) = ERROR("Missed name variable", (yylsp[(1) - (3)]).first_line); ;}
    break;

  case 57:
#line 166 "parser.y"
    { (yyval.nPtr) = ERROR("Wrong atribute", (yylsp[(3) - (4)]).first_line); yyerrok; ;}
    break;

  case 58:
#line 167 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '('", (yylsp[(2) - (2)]).first_line); yyerrok; ;}
    break;

  case 59:
#line 168 "parser.y"
    { (yyval.nPtr) = machine.create("GET", 1, machine.id_func((yyvsp[(2) - (2)].iName))); delete (yyvsp[(2) - (2)].iName); ;}
    break;

  case 60:
#line 172 "parser.y"
    { (yyval.nPtr) = machine.create("MXCOMP", 1, (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 61:
#line 173 "parser.y"
    { (yyval.nPtr) = machine.create("ELCOMP", 1, (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 62:
#line 174 "parser.y"
    { (yyval.nPtr) = machine.create("MXTRUE", 1, (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 63:
#line 175 "parser.y"
    { (yyval.nPtr) = machine.create("MXFALSE", 1, (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 64:
#line 179 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (2)].nPtr); ;}
    break;

  case 65:
#line 180 "parser.y"
    { (yyval.nPtr) = nullptr; ;}
    break;

  case 66:
#line 181 "parser.y"
    { (yyval.nPtr) = machine.courtesy(1, (yyvsp[(2) - (3)].nPtr)); ;}
    break;

  case 67:
#line 182 "parser.y"
    { (yyval.nPtr) = machine.courtesy(2, (yyvsp[(2) - (4)].nPtr)); ;}
    break;

  case 68:
#line 183 "parser.y"
    { (yyval.nPtr) = machine.courtesy(1, (yyvsp[(1) - (3)].nPtr)); ;}
    break;

  case 69:
#line 184 "parser.y"
    { (yyval.nPtr) = nullptr; ;}
    break;

  case 70:
#line 188 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 71:
#line 189 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 72:
#line 190 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 73:
#line 191 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 74:
#line 192 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 75:
#line 193 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 76:
#line 194 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 77:
#line 195 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 78:
#line 196 "parser.y"
    { (yyval.nPtr) = machine.create("PRINT", 1, machine.id((yyvsp[(2) - (2)].iName))); delete (yyvsp[(2) - (2)].iName); ;}
    break;

  case 79:
#line 197 "parser.y"
    { (yyval.nPtr) = ERROR("Missed variable", (yylsp[(1) - (2)]).first_line); yyerrok; ;}
    break;

  case 80:
#line 198 "parser.y"
    { (yyval.nPtr) = machine.create("ASSIGN", 2, machine.id((yyvsp[(1) - (3)].iName)), (yyvsp[(3) - (3)].nPtr)); delete (yyvsp[(1) - (3)].iName); ;}
    break;

  case 81:
#line 199 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '='", (yylsp[(1) - (3)]).first_line); yyerrok; delete (yyvsp[(1) - (3)].iName); ;}
    break;

  case 82:
#line 200 "parser.y"
    { (yyval.nPtr) = machine.create("ASSIGN_A", 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 83:
#line 201 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '='", (yylsp[(2) - (3)]).first_line); ;}
    break;

  case 84:
#line 206 "parser.y"
    { (yyval.nPtr) = machine.create("SWITCH", 5, (yyvsp[(2) - (8)].nPtr), machine.constant((yyvsp[(3) - (8)].iBool), "BOOL"), (yyvsp[(4) - (8)].nPtr), machine.constant((yyvsp[(6) - (8)].iBool), "BOOL"), (yyvsp[(7) - (8)].nPtr));;}
    break;

  case 85:
#line 207 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ']'", (yylsp[(8) - (8)]).first_line); yyerrok; ;}
    break;

  case 86:
#line 208 "parser.y"
    { (yyval.nPtr) = ERROR("Missed second flag", (yylsp[(6) - (6)]).first_line); yyerrok; ;}
    break;

  case 87:
#line 209 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '['", (yylsp[(5) - (6)]).first_line); yyerrok; ;}
    break;

  case 88:
#line 210 "parser.y"
    { (yyval.nPtr) = ERROR("Missed first flag", (yylsp[(3) - (3)]).first_line); yyerrok; ;}
    break;

  case 89:
#line 211 "parser.y"
    { (yyval.nPtr) = ERROR("Invalid define SWITCH", (yylsp[(2) - (2)]).first_line); yyerrok; ;}
    break;

  case 90:
#line 215 "parser.y"
    { (yyval.nPtr) = machine.appeal("APPEAL_A", (yyvsp[(1) - (4)].iName)); delete (yyvsp[(1) - (4)].iName); ;}
    break;

  case 91:
#line 216 "parser.y"
    { (yyval.nPtr) = ERROR("Invalid enumeration",(yylsp[(3) - (4)]).first_line); yyerrok;  delete (yyvsp[(1) - (4)].iName); ;}
    break;

  case 92:
#line 217 "parser.y"
    { (yyval.nPtr) = ERROR("Missed enumeration",(yylsp[(3) - (3)]).first_line); yyerrok;  delete (yyvsp[(1) - (3)].iName); ;}
    break;

  case 93:
#line 218 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '['", (yylsp[(4) - (4)]).first_line); yyerrok; delete (yyvsp[(1) - (4)].iName); ;}
    break;

  case 94:
#line 219 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '['", (yylsp[(2) - (2)]).first_line); yyerrok; delete (yyvsp[(1) - (2)].iName); ;}
    break;

  case 95:
#line 223 "parser.y"
    { (yyval.nPtr) = machine.create("FOR", 4, machine.id((yyvsp[(2) - (10)].iName)), machine.id((yyvsp[(4) - (10)].iName)), machine.id((yyvsp[(6) - (10)].iName)), (yyvsp[(9) - (10)].nPtr)); delete (yyvsp[(2) - (10)].iName); delete (yyvsp[(4) - (10)].iName); delete (yyvsp[(6) - (10)].iName); ;}
    break;

  case 96:
#line 224 "parser.y"
    { (yyval.nPtr) = ERROR("Invalid define loop", (yylsp[(2) - (2)]).first_line); yyerrok; ;}
    break;

  case 97:
#line 225 "parser.y"
    { (yyval.nPtr) = ERROR("Missed counter", (yylsp[(1) - (9)]).first_line); yyerrok; delete (yyvsp[(3) - (9)].iName); delete (yyvsp[(5) - (9)].iName); ;}
    break;

  case 98:
#line 226 "parser.y"
    { (yyval.nPtr) = ERROR("Missed edge", (yylsp[(3) - (9)]).first_line); yyerrok; delete (yyvsp[(2) - (9)].iName); delete (yyvsp[(5) - (9)].iName); ;}
    break;

  case 99:
#line 227 "parser.y"
    { (yyval.nPtr) = ERROR("Missed step", (yylsp[(5) - (9)]).first_line); yyerrok; delete (yyvsp[(2) - (9)].iName); delete (yyvsp[(4) - (9)].iName); ;}
    break;

  case 100:
#line 228 "parser.y"
    { (yyval.nPtr) = ERROR("Invalid body", (yylsp[(7) - (7)]).first_line); yyerrok; delete (yyvsp[(2) - (7)].iName); delete (yyvsp[(4) - (7)].iName); delete (yyvsp[(6) - (7)].iName); ;}
    break;

  case 101:
#line 229 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ')' for loop block", (yylsp[(10) - (10)]).first_line); yyerrok; ;}
    break;

  case 102:
#line 233 "parser.y"
    { (yyval.nPtr) = nullptr; ;}
    break;

  case 103:
#line 234 "parser.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); ;}
    break;

  case 104:
#line 238 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 105:
#line 239 "parser.y"
    { (yyval.nPtr) = machine.create("ENDLINE", 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 106:
#line 243 "parser.y"
    { (yyval.nPtr) = machine.putId((yyvsp[(2) - (7)].iName), (yyvsp[(7) - (7)].iValue), "INT"); delete (yyvsp[(2) - (7)].iName); ;}
    break;

  case 107:
#line 244 "parser.y"
    { (yyval.nPtr) = machine.putId((yyvsp[(2) - (7)].iName), (yyvsp[(7) - (7)].iBool), "BOOL"); delete (yyvsp[(2) - (7)].iName); ;}
    break;

  case 108:
#line 245 "parser.y"
    { (yyval.nPtr) = machine.putId((yyvsp[(2) - (4)].iName), (yyvsp[(4) - (4)].iValue), "INT"); delete (yyvsp[(2) - (4)].iName); ;}
    break;

  case 109:
#line 246 "parser.y"
    { (yyval.nPtr) = machine.putId((yyvsp[(2) - (4)].iName), (yyvsp[(4) - (4)].iBool), "BOOL"); delete (yyvsp[(2) - (4)].iName); ;}
    break;

  case 110:
#line 247 "parser.y"
    { (yyval.nPtr) = ERROR("Missed literal", (yylsp[(7) - (7)]).first_line); yyerrok; delete (yyvsp[(2) - (7)].iName); ;}
    break;

  case 111:
#line 248 "parser.y"
    { (yyval.nPtr) = ERROR("Missed literal", (yylsp[(4) - (4)]).first_line); yyerrok; delete (yyvsp[(2) - (4)].iName); ;}
    break;

  case 112:
#line 249 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '='", (yylsp[(6) - (6)]).first_line); yyerrok; delete (yyvsp[(2) - (6)].iName); ;}
    break;

  case 113:
#line 250 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ']' or ','", (yylsp[(5) - (7)]).first_line); yyerrok; delete (yyvsp[(2) - (7)].iName); ;}
    break;

  case 114:
#line 251 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ']' or ','", (yylsp[(5) - (7)]).first_line); yyerrok; delete (yyvsp[(2) - (7)].iName); ;}
    break;

  case 115:
#line 252 "parser.y"
    { (yyval.nPtr) = ERROR("Wrong enumeration size", (yylsp[(4) - (7)]).first_line); yyerrok; delete (yyvsp[(2) - (7)].iName); ;}
    break;

  case 116:
#line 253 "parser.y"
    { (yyval.nPtr) = ERROR("Wrong enumeration size", (yylsp[(4) - (7)]).first_line); yyerrok; delete (yyvsp[(2) - (7)].iName); ;}
    break;

  case 117:
#line 254 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '[' or '='", (yylsp[(3) - (3)]).first_line); yyerrok; delete (yyvsp[(2) - (3)].iName); ;}
    break;

  case 118:
#line 255 "parser.y"
    { (yyval.nPtr) = ERROR("Missed name", (yylsp[(2) - (7)]).first_line); yyerrok;;}
    break;

  case 119:
#line 256 "parser.y"
    { (yyval.nPtr) = ERROR("Missed name", (yylsp[(2) - (7)]).first_line); yyerrok;;}
    break;

  case 120:
#line 257 "parser.y"
    { (yyval.nPtr) = ERROR("Undefine variable", (yylsp[(2) - (2)]).first_line); yyerrok; ;}
    break;

  case 121:
#line 261 "parser.y"
    { (yyval.nPtr) = machine.create("LOGITIZE", 1, machine.id((yyvsp[(2) - (2)].iName))); delete (yyvsp[(2) - (2)].iName); ;}
    break;

  case 122:
#line 262 "parser.y"
    { (yyval.nPtr) = machine.create("DIGITIZE", 1, machine.id((yyvsp[(2) - (2)].iName))); delete (yyvsp[(2) - (2)].iName); ;}
    break;

  case 123:
#line 263 "parser.y"
    { (yyval.nPtr) = machine.create("REDUCE", 2, machine.id((yyvsp[(2) - (5)].iName)), machine.constant((yyvsp[(4) - (5)].iValue), "INT")); delete (yyvsp[(2) - (5)].iName); ;}
    break;

  case 124:
#line 264 "parser.y"
    { (yyval.nPtr) = machine.create("EXTENED", 2 , machine.id((yyvsp[(2) - (5)].iName)), machine.constant((yyvsp[(4) - (5)].iValue), "INT")); delete (yyvsp[(2) - (5)].iName); ;}
    break;

  case 125:
#line 265 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ']'", (yylsp[(5) - (5)]).first_line); yyerrok;  delete (yyvsp[(2) - (5)].iName);;}
    break;

  case 126:
#line 266 "parser.y"
    { (yyval.nPtr) = ERROR("Missed number", (yylsp[(4) - (5)]).first_line); yyerrok; delete (yyvsp[(2) - (5)].iName); ;}
    break;

  case 127:
#line 267 "parser.y"
    { (yyval.nPtr) = ERROR("Invalid argunemt", (yylsp[(4) - (4)]).first_line); yyerrok; delete (yyvsp[(2) - (4)].iName); ;}
    break;

  case 128:
#line 268 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '['", (yylsp[(3) - (3)]).first_line); yyerrok; delete (yyvsp[(2) - (3)].iName); ;}
    break;

  case 129:
#line 269 "parser.y"
    { (yyval.nPtr) = ERROR("Missed variable", (yylsp[(2) - (2)]).first_line); yyerrok;;}
    break;

  case 130:
#line 270 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ']'", (yylsp[(5) - (5)]).first_line); yyerrok; delete (yyvsp[(2) - (5)].iName); ;}
    break;

  case 131:
#line 271 "parser.y"
    { (yyval.nPtr) = ERROR("Missed number", (yylsp[(4) - (5)]).first_line); yyerrok; delete (yyvsp[(2) - (5)].iName); ;}
    break;

  case 132:
#line 272 "parser.y"
    { (yyval.nPtr) = ERROR("Invalid argunemt", (yylsp[(4) - (4)]).first_line); yyerrok; delete (yyvsp[(2) - (4)].iName); ;}
    break;

  case 133:
#line 273 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '['", (yylsp[(3) - (3)]).first_line); yyerrok; delete (yyvsp[(2) - (3)].iName); ;}
    break;

  case 134:
#line 274 "parser.y"
    { (yyval.nPtr) = ERROR("Missed variable", (yylsp[(2) - (2)]).first_line); yyerrok;;}
    break;


/* Line 1267 of yacc.c.  */
#line 2508 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


#line 276 "parser.y"



void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}

void COMP_ERROR(const char* exept)
{
    std::cout << "Crash: " << exept << '\n';
    machine.clear_sys();
    exit(1);
}

Vertex* ERROR(const std::string& type, int line)
{
    std::cerr << "Error syntax at line -> " << line << ": " << type << '\n';
    errorFlag = true;
    return nullptr;
}


void freeNode(Vertex *node)
{   
    if (node == nullptr) 
        return;

    Node *ptr = nullptr;
 

    if((ptr = dynamic_cast<Node*>(node)))
    {
        if (ptr == nullptr)
            return;

        for(int i = 0; i < ptr->leafs.size(); ++i)
        {
                freeNode(ptr->leafs[i]);
        }
    }
    if (node) 
        delete node;
}


//algorithm
int main(void) {
    #if YYDEBUG
    yydebug = 1;
    yy_flex_debug = 1;
    #endif
    yyin = fopen ("./test2.txt", "r");
    yyparse();
    fclose (yyin);
    return 0;
}

