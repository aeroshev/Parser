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

    #define YYDEBUG 1
    #define YYERROR_VERBOSE 1
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


/*
compound_statement:
        '{' '}'             { $$ = nullptr; }
        | '{' statement_list '}'            { $$ = $2; }
        ;

statement_list:
        statement           { $$ = machine.create("ENDLINE", 2, $1, nullptr); }
        | statement_list statement           { $$ = machine.create("ENDLINE", 2, $1, $2); }
        ;

   | MXCOMP         { $$ = ERROR("Don't get expression", @1.first_line); }
    | ELCOMP          { $$ = ERROR("Don't get expression", @1.first_line); }
    | MXTRUE          { $$ = ERROR("Don't get expression", @1.first_line); }
    | MXFALSE         { $$ = ERROR("Don't get expression", @1.first_line); }

    enumeration_list:
        INTEGER          { $$ = nullptr; machine.enumeration.push_back($1); }
        | enumeration_list ',' INTEGER           { $$ = nullptr; machine.enumeration.push_back($3); }
        ;

       | SWITCH expression BOOL statement_list '[' BOOL statement_list error       { $$ = ERROR("Missed ']'", @1.first_line); yyerrok; }
    | SWITCH expression BOOL statement_list '[' error statement_list ']'        { $$ = ERROR("Missed second flag", @1.first_line); yyerrok; }
    | SWITCH expression BOOL statement_list error BOOL statement_list ']'       { $$ = ERROR("Missed '['", @1.first_line); yyerrok; }
    | SWITCH expression error statement_list '[' BOOL statement_list ']'        { $$ = ERROR("Missed first flag", @1.first_line); yyerrok; }


    program:
        statement_list { check_main(); }
        ;

    statement_list:
        function_defintion
        | statemnt_list function_definition
        | ENDLINE
        ;


*/
//стартовый символ список функций
//findexit типа main


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
#line 78 "parser.y"
{
    Vertex *nPtr;
    int iValue;
    bool iBool;
    char* iName;  
}
/* Line 193 of yacc.c.  */
#line 249 "parser.tab.c"
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
#line 274 "parser.tab.c"

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
#define YYLAST   992

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNRULES -- Number of states.  */
#define YYNSTATES  206

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
      31,    39,    45,    48,    56,    60,    63,    65,    69,    71,
      75,    77,    79,    81,    83,    85,    87,    92,    97,   101,
     104,   108,   112,   116,   120,   124,   128,   132,   134,   136,
     138,   140,   142,   145,   148,   151,   156,   161,   165,   168,
     171,   174,   177,   180,   183,   186,   189,   193,   198,   202,
     204,   206,   208,   210,   212,   214,   216,   218,   220,   223,
     226,   230,   234,   238,   242,   251,   260,   267,   274,   278,
     283,   288,   292,   295,   306,   318,   321,   325,   327,   330,
     338,   346,   351,   356,   364,   371,   377,   382,   386,   391,
     394,   397,   400,   406,   412,   418,   423,   427,   430,   436,
     441,   445
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    49,    -1,    48,    49,    -1,
      51,    -1,    27,    -1,    60,    -1,    50,    60,    -1,     7,
       4,     4,    44,    42,    53,    43,    27,    50,    10,     4,
      -1,     7,     4,     4,    27,    50,    10,     4,    -1,     7,
       6,    27,    50,    10,    -1,     7,     1,    -1,     8,     4,
       4,    44,    42,    53,    43,    -1,     8,     4,     4,    -1,
       8,     1,    -1,     4,    -1,    53,    44,     4,    -1,    55,
      -1,    54,    44,    55,    -1,     5,    -1,     3,    -1,     4,
      -1,    56,    -1,    57,    -1,    58,    -1,     4,    42,    54,
      43,    -1,     4,    42,    54,     1,    -1,     4,    42,     1,
      -1,     4,     1,    -1,    39,    55,    40,    -1,    55,    35,
      55,    -1,    55,    37,    55,    -1,    55,    36,    55,    -1,
      55,    38,    55,    -1,    55,    16,    55,    -1,    55,     1,
      55,    -1,    24,    -1,    22,    -1,    23,    -1,    25,    -1,
      59,    -1,    36,    55,    -1,    15,    55,    -1,    15,     1,
      -1,    19,    39,     4,    40,    -1,    19,    39,     4,     1,
      -1,    19,    39,    40,    -1,    19,     1,    -1,     9,     4,
      -1,     9,     1,    -1,    11,    55,    -1,    12,    55,    -1,
      14,    55,    -1,    13,    55,    -1,    61,    27,    -1,    33,
      61,    27,    -1,    33,    61,    34,    27,    -1,    61,    34,
      27,    -1,    27,    -1,    65,    -1,    67,    -1,    68,    -1,
      51,    -1,    52,    -1,    57,    -1,    64,    -1,    62,    -1,
      32,     4,    -1,    32,     1,    -1,     4,    45,    55,    -1,
       4,     1,    55,    -1,    63,    45,    55,    -1,    63,     1,
      55,    -1,    31,    55,     5,    50,    42,     5,    50,    43,
      -1,    31,    55,     5,    50,    42,     5,    50,     1,    -1,
      31,    55,     5,    50,    42,     1,    -1,    31,    55,     5,
      50,     1,     5,    -1,    31,    55,     1,    -1,     4,    42,
      54,    43,    -1,     4,    42,    54,     1,    -1,     4,    42,
       1,    -1,     4,     1,    -1,    28,     4,    29,     4,    30,
       4,    27,    39,    50,    40,    -1,    28,     4,    29,     4,
      30,     4,    27,    39,    50,     1,    27,    -1,    39,    40,
      -1,    39,    66,    40,    -1,    60,    -1,    66,    60,    -1,
      26,     4,    42,    54,    43,    45,     3,    -1,    26,     4,
      42,    54,    43,    45,     5,    -1,    26,     4,    45,     3,
      -1,    26,     4,    45,     5,    -1,    26,     4,    42,    54,
      43,    45,     1,    -1,    26,     4,    42,    54,    43,     1,
      -1,    26,     4,    42,    54,     1,    -1,    26,     4,    42,
       1,    -1,    26,     4,     1,    -1,    26,     4,    45,     1,
      -1,    26,     1,    -1,    17,     4,    -1,    18,     4,    -1,
      20,     4,    42,     3,    43,    -1,    21,     4,    42,     3,
      43,    -1,    20,     4,    42,     3,     1,    -1,    20,     4,
      42,     1,    -1,    20,     4,     1,    -1,    20,     1,    -1,
      21,     4,    42,     3,     1,    -1,    21,     4,    42,     1,
      -1,    21,     4,     1,    -1,    21,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   113,   113,   124,   125,   129,   130,   134,   135,   139,
     140,   141,   142,   146,   147,   148,   152,   153,   157,   158,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   176,   177,   178,   179,   180,   181,   185,   186,   187,
     188,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   205,   206,   207,   208,   212,   213,   214,   215,   216,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   238,   239,   240,   241,   242,   246,
     247,   248,   249,   253,   254,   258,   259,   263,   264,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293
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
      51,    51,    51,    52,    52,    52,    53,    53,    54,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    57,    57,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    59,    59,    59,    59,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    62,    62,    62,    62,    63,
      63,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     2,    11,
       7,     5,     2,     7,     3,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     4,     4,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     2,     2,     2,     4,     4,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     3,     3,     3,     8,     8,     6,     6,     3,     4,
       4,     3,     2,    10,    11,     2,     3,     1,     2,     7,
       7,     4,     4,     7,     6,     5,     4,     3,     4,     2,
       2,     2,     5,     5,     5,     4,     3,     2,     5,     4,
       3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     6,     0,     2,     3,     5,    12,     0,     0,
       1,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    37,    40,     0,    59,     0,     0,
       0,     0,     0,     0,    63,    64,    65,     7,     0,    67,
       0,    66,    60,    61,    62,     0,     0,    82,     0,     0,
      15,     0,   100,   101,   107,     0,   111,     0,    99,     0,
       0,    21,     0,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    41,    69,    68,
       0,    85,    87,     0,    11,     8,    55,     0,     0,     0,
       0,    16,     0,     0,    81,     0,     0,     0,    14,   106,
       0,   110,     0,    97,     0,     0,     0,    29,     0,    50,
      49,     0,     0,     0,     0,    44,     0,    48,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,    56,     0,
      86,    88,    58,     0,     0,    10,     0,     0,     0,    80,
      79,     0,     0,   105,     0,   109,     0,    96,     0,    98,
      91,    92,     0,    28,     0,     0,    47,    30,     0,     0,
       0,     0,     0,     0,     0,    57,     0,    17,     0,     0,
     104,   102,   108,   103,    95,     0,     0,    27,    26,    46,
      45,     0,     0,     0,     0,    94,     0,     0,    77,    76,
       0,     0,    13,    93,    89,    90,     0,     0,     9,     0,
      75,    74,     0,     0,    83,    84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    33,    34,    35,    92,    95,    96,
      74,    75,    76,    77,    37,    38,    39,    40,    41,    42,
      83,    43,    44
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -30
static const yytype_int16 yypact[] =
{
      54,    82,   -30,    60,    54,   -30,   -30,   -30,    92,    -2,
     -30,   -30,   -16,   923,   923,    63,     5,    12,   129,   137,
      26,    78,   -30,   -30,   -30,   -30,   113,   -30,   140,   810,
     115,   953,   748,   833,   -30,   -30,   -30,   -30,    50,   -30,
       7,   -30,   -30,   -30,   -30,   863,   146,   810,   593,   810,
     -30,   147,   -30,   -30,   -30,    32,   -30,    33,   -30,     6,
     119,   -30,    86,   -30,   131,   810,   810,   810,   810,   622,
      37,   810,   810,   144,   -30,   -30,   -30,   -30,   -30,   -30,
      51,   -30,   -30,   778,   -30,   -30,   -30,   125,   810,   810,
     152,   -30,   -29,   695,   -30,    23,    21,   707,   114,   -30,
     124,   -30,   133,   -30,   651,    89,   155,   -30,   680,   -30,
     -30,   156,   196,   208,   248,   -30,   260,   -30,    40,   300,
     102,   810,   923,   810,   810,   810,   810,   810,   -30,   135,
     -30,   -30,   -30,   712,   724,   -30,   136,   160,   810,   -30,
     -30,   810,   123,   -30,    11,   -30,    30,   -30,    25,   -30,
     -30,   -30,   138,   -30,    28,     9,   -30,   -30,   312,   527,
     352,   364,   404,   416,   456,   -30,   923,   -30,   433,   146,
     -30,   -30,   -30,   -30,   -30,     8,   162,   -30,   -30,   -30,
     -30,   166,    88,   893,    -8,   -30,   103,   148,   -30,   -30,
     923,   163,   -30,   -30,   -30,   -30,   134,   494,   -30,   923,
     -30,   -30,   560,   149,   -30,   -30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -30,   -30,   -30,   181,   -12,   107,   -30,    19,    39,   -26,
     -30,   -13,   -30,   -30,   -28,   164,   -30,   -30,   -30,   -30,
     -30,   -30,   -30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -74
static const yytype_int16 yytable[] =
{
      36,    36,    45,    73,    82,    85,    47,   103,    88,   185,
     179,    14,   170,    50,   136,   137,    51,    85,    36,    36,
      36,    93,   138,    97,   139,    13,   174,    54,    15,   177,
      55,   172,    36,    99,   101,   192,   137,   123,   117,   111,
     112,   113,   114,   116,   155,   119,   120,    48,   104,   180,
      49,   105,    89,   186,   171,   131,   124,   125,   126,   127,
      10,     1,   133,   134,   -18,   -18,   140,   141,   175,   141,
      36,   178,   141,   173,   100,   102,   118,    86,   128,    56,
     156,     2,    57,     7,    87,   129,     8,   107,     9,   189,
     149,   -22,   150,   190,   151,   158,    12,   160,   161,   162,
     163,   164,   -22,   138,   193,    46,   194,     6,   195,    36,
     159,     6,   158,   -22,    58,   168,    78,    59,   123,    79,
     -22,   -22,   -22,   -22,   -22,   143,   -22,   144,   108,   -22,
     -22,    85,   109,    52,   145,   110,   146,   124,   125,   126,
     127,    53,   157,   148,    60,   121,    36,   154,   106,   122,
      91,    98,   132,    36,   183,    85,   135,   138,   142,   152,
     123,   -51,   165,   166,   167,   169,   187,   198,   176,    85,
      36,   188,   123,   199,    85,   196,   205,    36,   197,   124,
     125,   126,   127,   -51,    36,    11,    36,   202,   184,    36,
     -51,   124,   125,   126,   127,    80,   -51,   138,     0,   -51,
     -51,   -52,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,   123,   -54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -52,   123,     0,     0,     0,     0,     0,
     -52,   124,   125,   126,   127,   -54,   -52,     0,     0,   -52,
     -52,     0,   -54,   124,   125,   126,   127,     0,   -54,   138,
       0,   -54,   -54,   -53,     0,     0,     0,     0,     0,     0,
       0,   138,     0,     0,   123,   -43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -53,   123,     0,     0,     0,
       0,     0,   -53,   124,   125,   126,   127,   -43,   -53,     0,
       0,   -53,   -53,     0,   -43,   124,   125,   126,   127,     0,
     -43,   138,     0,   -43,   -43,   -42,     0,     0,     0,     0,
       0,     0,     0,   138,     0,     0,   123,   -36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -42,   123,     0,
       0,     0,     0,     0,   -42,   -42,   -42,   -42,   -42,   -36,
     -42,     0,     0,   -42,   -42,     0,   -36,   124,   125,   126,
     127,     0,   -36,   138,     0,   -36,   -36,   -35,     0,     0,
       0,     0,     0,     0,     0,   138,     0,     0,   123,   -31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -35,
     123,     0,     0,     0,     0,     0,   -35,   124,   125,   126,
     127,   -31,   -35,     0,     0,   -35,   -35,     0,   -31,   -31,
     -31,   126,   127,     0,   -31,   138,     0,   -31,   -31,   -33,
       0,     0,     0,     0,     0,     0,     0,   138,     0,     0,
     123,   -32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -33,   123,     0,   138,     0,     0,     0,   -33,   -33,
     -33,   126,   127,   -32,   -33,     0,     0,   -33,   -33,   123,
     -32,   -32,   -32,   -32,   -32,     0,   -32,   138,     0,   -32,
     -32,   -34,     0,     0,     0,     0,     0,     0,   124,   125,
     126,   127,   123,     0,     0,     0,   -19,   -19,     0,     0,
       0,     0,     0,   -34,     0,     0,     0,     0,     0,     0,
     -34,   -34,   -34,   -34,   -34,   200,   -34,     0,    16,   -34,
     -34,     1,    17,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    19,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,    29,    30,    31,   181,     0,
       0,    16,     0,    32,     1,    17,     0,   201,     0,     0,
       0,     0,     0,     0,    18,    19,     0,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,    29,    30,
      31,   203,     0,     0,    16,     0,    32,     1,    17,   182,
       0,     0,     0,     0,     0,     0,     0,    18,    19,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,    29,    30,    31,    94,     0,    61,    62,    63,    32,
     204,     0,    64,     0,    65,    66,    67,    68,    69,     0,
       0,     0,    70,     0,     0,    22,    23,    24,    25,     0,
       0,     0,     0,   115,     0,    61,    62,    63,     0,    71,
       0,    64,    72,    65,    66,    67,    68,    69,     0,     0,
       0,    70,     0,     0,    22,    23,    24,    25,     0,     0,
       0,     0,   147,     0,    61,    62,    63,     0,    71,     0,
      64,    72,    65,    66,    67,    68,    69,     0,     0,     0,
      70,     0,     0,    22,    23,    24,    25,     0,     0,     0,
       0,   153,     0,    61,    62,    63,     0,    71,     0,    64,
      72,    65,    66,    67,    68,    69,   138,     0,     0,    70,
       0,     0,    22,    23,    24,    25,     0,     0,   138,     0,
       0,   123,     0,   138,     0,     0,    71,     0,     0,    72,
       0,     0,   -71,   123,     0,   138,     0,     0,   123,   -71,
     124,   125,   126,   127,   -70,     0,     0,     0,     0,   -73,
     123,   -70,   124,   125,   126,   127,   -73,   124,   125,   126,
     127,   -72,    16,     0,     0,     1,    17,     0,   -72,   124,
     125,   126,   127,     0,     0,    18,    19,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,    29,
      30,    31,    16,     0,     0,     1,    17,    32,    81,     0,
       0,     0,     0,     0,     0,    18,    19,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,    29,
      30,    31,     0,    61,    62,    63,     0,    32,   130,    64,
       0,    65,    66,    67,    68,    69,     0,     0,     0,    70,
       0,     0,    22,    23,    24,    25,     0,    16,     0,     0,
       1,    17,     0,    84,     0,     0,    71,     0,     0,    72,
      18,    19,     0,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,    29,    30,    31,    16,     0,     0,
       1,    17,    32,    90,     0,     0,     0,     0,     0,     0,
      18,    19,     0,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,    29,    30,    31,    16,     0,     0,
       1,    17,    32,   191,     0,     0,     0,     0,     0,     0,
      18,    19,     0,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,    29,    30,    31,    16,     0,     0,
       1,    17,    32,     0,     0,     0,     0,     0,     0,     0,
      18,    19,     0,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,    29,    30,    31,    16,     0,     0,
       1,    17,    32,     0,     0,     0,     0,     0,     0,     0,
      18,    19,     0,    20,    21,    22,    23,    24,    25,    26,
       0,    28,     0,     0,    29,    30,     0,     0,     0,     0,
       0,     0,    32
};

static const yytype_int16 yycheck[] =
{
      13,    14,    14,    29,    32,    33,     1,     1,     1,     1,
       1,    27,     1,     1,    43,    44,     4,    45,    31,    32,
      33,    47,     1,    49,     1,    27,     1,     1,    44,     1,
       4,     1,    45,     1,     1,    43,    44,    16,     1,    65,
      66,    67,    68,    69,     4,    71,    72,    42,    42,    40,
      45,    45,    45,    45,    43,    83,    35,    36,    37,    38,
       0,     7,    88,    89,    43,    44,    43,    44,    43,    44,
      83,    43,    44,    43,    42,    42,    39,    27,    27,     1,
      40,    27,     4,     1,    34,    34,     4,     1,     6,     1,
       1,     5,     3,     5,     5,   121,     4,   123,   124,   125,
     126,   127,    16,     1,     1,    42,     3,     0,     5,   122,
     122,     4,   138,    27,     1,   141,     1,     4,    16,     4,
      34,    35,    36,    37,    38,     1,    40,     3,    42,    43,
      44,   159,     1,     4,     1,     4,     3,    35,    36,    37,
      38,     4,    40,   104,     4,     1,   159,   108,    29,     5,
       4,     4,    27,   166,   166,   183,     4,     1,    44,     4,
      16,     5,    27,    27,     4,    42,     4,     4,    30,   197,
     183,     5,    16,    39,   202,    27,    27,   190,   190,    35,
      36,    37,    38,    27,   197,     4,   199,   199,   169,   202,
      34,    35,    36,    37,    38,    31,    40,     1,    -1,    43,
      44,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    16,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    16,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    27,    40,    -1,    -1,    43,
      44,    -1,    34,    35,    36,    37,    38,    -1,    40,     1,
      -1,    43,    44,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    16,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    16,    -1,    -1,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    27,    40,    -1,
      -1,    43,    44,    -1,    34,    35,    36,    37,    38,    -1,
      40,     1,    -1,    43,    44,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    16,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    16,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    27,
      40,    -1,    -1,    43,    44,    -1,    34,    35,    36,    37,
      38,    -1,    40,     1,    -1,    43,    44,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    16,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      16,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    27,    40,    -1,    -1,    43,    44,    -1,    34,    35,
      36,    37,    38,    -1,    40,     1,    -1,    43,    44,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,
      16,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    16,    -1,     1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    27,    40,    -1,    -1,    43,    44,    16,
      34,    35,    36,    37,    38,    -1,    40,     1,    -1,    43,
      44,     5,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    16,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,     1,    40,    -1,     4,    43,
      44,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,     1,    -1,
      -1,     4,    -1,    39,     7,     8,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    31,    32,
      33,     1,    -1,    -1,     4,    -1,    39,     7,     8,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    32,    33,     1,    -1,     3,     4,     5,    39,
      40,    -1,     9,    -1,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    -1,    -1,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,    -1,    36,
      -1,     9,    39,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    19,    -1,    -1,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,    -1,    36,    -1,
       9,    39,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,    -1,    36,    -1,     9,
      39,    11,    12,    13,    14,    15,     1,    -1,    -1,    19,
      -1,    -1,    22,    23,    24,    25,    -1,    -1,     1,    -1,
      -1,    16,    -1,     1,    -1,    -1,    36,    -1,    -1,    39,
      -1,    -1,    27,    16,    -1,     1,    -1,    -1,    16,    34,
      35,    36,    37,    38,    27,    -1,    -1,    -1,    -1,    27,
      16,    34,    35,    36,    37,    38,    34,    35,    36,    37,
      38,    27,     4,    -1,    -1,     7,     8,    -1,    34,    35,
      36,    37,    38,    -1,    -1,    17,    18,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      32,    33,     4,    -1,    -1,     7,     8,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      32,    33,    -1,     3,     4,     5,    -1,    39,    40,     9,
      -1,    11,    12,    13,    14,    15,    -1,    -1,    -1,    19,
      -1,    -1,    22,    23,    24,    25,    -1,     4,    -1,    -1,
       7,     8,    -1,    10,    -1,    -1,    36,    -1,    -1,    39,
      17,    18,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    32,    33,     4,    -1,    -1,
       7,     8,    39,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    32,    33,     4,    -1,    -1,
       7,     8,    39,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    32,    33,     4,    -1,    -1,
       7,     8,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    32,    33,     4,    -1,    -1,
       7,     8,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    22,    23,    24,    25,    26,
      -1,    28,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    27,    47,    48,    49,    51,     1,     4,     6,
       0,    49,     4,    27,    27,    44,     4,     8,    17,    18,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    31,
      32,    33,    39,    50,    51,    52,    57,    60,    61,    62,
      63,    64,    65,    67,    68,    50,    42,     1,    42,    45,
       1,     4,     4,     4,     1,     4,     1,     4,     1,     4,
       4,     3,     4,     5,     9,    11,    12,    13,    14,    15,
      19,    36,    39,    55,    56,    57,    58,    59,     1,     4,
      61,    40,    60,    66,    10,    60,    27,    34,     1,    45,
      10,     4,    53,    55,     1,    54,    55,    55,     4,     1,
      42,     1,    42,     1,    42,    45,    29,     1,    42,     1,
       4,    55,    55,    55,    55,     1,    55,     1,    39,    55,
      55,     1,     5,    16,    35,    36,    37,    38,    27,    34,
      40,    60,    27,    55,    55,     4,    43,    44,     1,     1,
      43,    44,    44,     1,     3,     1,     3,     1,    54,     1,
       3,     5,     4,     1,    54,     4,    40,    40,    55,    50,
      55,    55,    55,    55,    55,    27,    27,     4,    55,    42,
       1,    43,     1,    43,     1,    43,    30,     1,    43,     1,
      40,     1,    42,    50,    53,     1,    45,     4,     5,     1,
       5,    10,    43,     1,     3,     5,    27,    50,     4,    39,
       1,    43,    50,     1,    40,    27
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
#line 113 "parser.y"
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
#line 124 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 4:
#line 125 "parser.y"
    { (yyval.nPtr) = machine.create("ENDLINE", 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 5:
#line 129 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 6:
#line 130 "parser.y"
    { (yyval.nPtr) = nullptr; ;}
    break;

  case 7:
#line 134 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 8:
#line 135 "parser.y"
    { (yyval.nPtr) = machine.create("ENDLINE", 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 9:
#line 139 "parser.y"
    { (yyval.nPtr) = nullptr; machine.putFunc((yyvsp[(2) - (11)].iName), (yyvsp[(3) - (11)].iName), (yyvsp[(9) - (11)].nPtr), (yyvsp[(11) - (11)].iName)); delete (yyvsp[(2) - (11)].iName); delete (yyvsp[(3) - (11)].iName); delete (yyvsp[(11) - (11)].iName); ;}
    break;

  case 10:
#line 140 "parser.y"
    { (yyval.nPtr) = nullptr; machine.putFunc((yyvsp[(2) - (7)].iName), (yyvsp[(3) - (7)].iName), (yyvsp[(5) - (7)].nPtr), (yyvsp[(7) - (7)].iName)); delete (yyvsp[(2) - (7)].iName); delete (yyvsp[(3) - (7)].iName); delete (yyvsp[(7) - (7)].iName); ;}
    break;

  case 11:
#line 141 "parser.y"
    { (yyval.nPtr) = (yyvsp[(4) - (5)].nPtr); machine.putFunc((yyvsp[(4) - (5)].nPtr)); ;}
    break;

  case 12:
#line 142 "parser.y"
    { (yyval.nPtr) = ERROR("Missed name function", (yylsp[(1) - (2)]).first_line); yyerrok; ;}
    break;

  case 13:
#line 146 "parser.y"
    { (yyval.nPtr) = machine.funcall("DO", (yyvsp[(2) - (7)].iName), (yyvsp[(3) - (7)].iName), machine.args); delete (yyvsp[(2) - (7)].iName); delete (yyvsp[(3) - (7)].iName); ;}
    break;

  case 14:
#line 147 "parser.y"
    { (yyval.nPtr) = machine.funcall("DO", (yyvsp[(2) - (3)].iName), (yyvsp[(3) - (3)].iName)); delete (yyvsp[(2) - (3)].iName); delete (yyvsp[(3) - (3)].iName); ;}
    break;

  case 15:
#line 148 "parser.y"
    { (yyval.nPtr) = ERROR("Missed name function", (yylsp[(1) - (2)]).first_line); yyerrok; ;}
    break;

  case 16:
#line 152 "parser.y"
    { (yyval.nPtr) = nullptr; machine.args.push_back((yyvsp[(1) - (1)].iName)); delete (yyvsp[(1) - (1)].iName); ;}
    break;

  case 17:
#line 153 "parser.y"
    { (yyval.nPtr) = nullptr; machine.args.push_back((yyvsp[(3) - (3)].iName)); delete (yyvsp[(3) - (3)].iName); ;}
    break;

  case 18:
#line 157 "parser.y"
    { (yyval.nPtr) = nullptr; machine.exprl.push_back((yyvsp[(1) - (1)].nPtr)); ;}
    break;

  case 19:
#line 158 "parser.y"
    { (yyval.nPtr) = nullptr; machine.exprl.push_back((yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 20:
#line 162 "parser.y"
    { (yyval.nPtr) = machine.constant((yyvsp[(1) - (1)].iBool), "BOOL"); ;}
    break;

  case 21:
#line 163 "parser.y"
    { (yyval.nPtr) = machine.constant((yyvsp[(1) - (1)].iValue), "INT"); ;}
    break;

  case 22:
#line 164 "parser.y"
    { (yyval.nPtr) = machine.id((yyvsp[(1) - (1)].iName)); delete (yyvsp[(1) - (1)].iName); ;}
    break;

  case 23:
#line 165 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 24:
#line 166 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 25:
#line 167 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 26:
#line 168 "parser.y"
    { (yyval.nPtr) = machine.appeal("APPEAL", (yyvsp[(1) - (4)].iName)); delete (yyvsp[(1) - (4)].iName); ;}
    break;

  case 27:
#line 169 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ']'", (yylsp[(1) - (4)]).first_line); yyerrok; delete (yyvsp[(1) - (4)].iName); ;}
    break;

  case 28:
#line 170 "parser.y"
    { (yyval.nPtr) = ERROR("Missed enumeration",(yylsp[(1) - (3)]).first_line); yyerrok; delete (yyvsp[(1) - (3)].iName); ;}
    break;

  case 29:
#line 171 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '['", (yylsp[(1) - (2)]).first_line); yyerrok; delete (yyvsp[(1) - (2)].iName); ;}
    break;

  case 30:
#line 172 "parser.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); ;}
    break;

  case 31:
#line 176 "parser.y"
    { (yyval.nPtr) = machine.create("+", 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 32:
#line 177 "parser.y"
    { (yyval.nPtr) = machine.create("*", 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 33:
#line 178 "parser.y"
    { (yyval.nPtr) = machine.create("-", 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 34:
#line 179 "parser.y"
    { (yyval.nPtr) = machine.create("/", 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 35:
#line 180 "parser.y"
    { (yyval.nPtr) = machine.create("AND", 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 36:
#line 181 "parser.y"
    { (yyval.nPtr) = ERROR("Missed operator", (yylsp[(1) - (3)]).first_line); yyerrok; ;}
    break;

  case 37:
#line 185 "parser.y"
    { (yyval.nPtr) = machine.robot("MOVE"); ;}
    break;

  case 38:
#line 186 "parser.y"
    { (yyval.nPtr) = machine.robot("ROTATE_LEFT"); ;}
    break;

  case 39:
#line 187 "parser.y"
    { (yyval.nPtr) = machine.robot("ROTATE_RIGHT"); ;}
    break;

  case 40:
#line 188 "parser.y"
    { (yyval.nPtr) = machine.robot("GET_E"); ;}
    break;

  case 41:
#line 192 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 42:
#line 193 "parser.y"
    { (yyval.nPtr) = machine.create("UMINUS",1, (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 43:
#line 194 "parser.y"
    { (yyval.nPtr) = machine.create("NOT", 1, (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 44:
#line 195 "parser.y"
    { (yyval.nPtr) = ERROR("It's not a expression", (yylsp[(1) - (2)]).first_line); yyerrok; ;}
    break;

  case 45:
#line 196 "parser.y"
    { (yyval.nPtr) = machine.create("SIZE", 1, machine.id((yyvsp[(3) - (4)].iName))); delete (yyvsp[(3) - (4)].iName); ;}
    break;

  case 46:
#line 197 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ')'", (yylsp[(1) - (4)]).first_line);;}
    break;

  case 47:
#line 198 "parser.y"
    { (yyval.nPtr) = ERROR("Missed name variable", (yylsp[(1) - (3)]).first_line); ;}
    break;

  case 48:
#line 199 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '('", (yylsp[(1) - (2)]).first_line); yyerrok; ;}
    break;

  case 49:
#line 200 "parser.y"
    { (yyval.nPtr) = machine.create("GET", 1, machine.id_func((yyvsp[(2) - (2)].iName))); delete (yyvsp[(2) - (2)].iName); ;}
    break;

  case 50:
#line 201 "parser.y"
    { (yyval.nPtr) = ERROR("Don't get variable", (yylsp[(1) - (2)]).first_line); yyerrok; ;}
    break;

  case 51:
#line 205 "parser.y"
    { (yyval.nPtr) = machine.create("MXCOMP", 1, (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 52:
#line 206 "parser.y"
    { (yyval.nPtr) = machine.create("ELCOMP", 1, (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 53:
#line 207 "parser.y"
    { (yyval.nPtr) = machine.create("MXTRUE", 1, (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 54:
#line 208 "parser.y"
    { (yyval.nPtr) = machine.create("MXFALSE", 1, (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 55:
#line 212 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (2)].nPtr); ;}
    break;

  case 56:
#line 213 "parser.y"
    { (yyval.nPtr) = machine.courtesy(1, (yyvsp[(2) - (3)].nPtr)); ;}
    break;

  case 57:
#line 214 "parser.y"
    { (yyval.nPtr) = machine.courtesy(2, (yyvsp[(2) - (4)].nPtr)); ;}
    break;

  case 58:
#line 215 "parser.y"
    { (yyval.nPtr) = machine.courtesy(1, (yyvsp[(1) - (3)].nPtr)); ;}
    break;

  case 59:
#line 216 "parser.y"
    { (yyval.nPtr) = nullptr; ;}
    break;

  case 60:
#line 220 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 61:
#line 221 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 62:
#line 222 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 63:
#line 223 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 64:
#line 224 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 65:
#line 225 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 66:
#line 226 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 67:
#line 227 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 68:
#line 228 "parser.y"
    { (yyval.nPtr) = machine.create("PRINT", 1, machine.id((yyvsp[(2) - (2)].iName))); delete (yyvsp[(2) - (2)].iName); ;}
    break;

  case 69:
#line 229 "parser.y"
    { (yyval.nPtr) = ERROR("Missed variable", (yylsp[(1) - (2)]).first_line); yyerrok; ;}
    break;

  case 70:
#line 230 "parser.y"
    { (yyval.nPtr) = machine.create("ASSIGN", 2, machine.id((yyvsp[(1) - (3)].iName)), (yyvsp[(3) - (3)].nPtr)); delete (yyvsp[(1) - (3)].iName); ;}
    break;

  case 71:
#line 231 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '='", (yylsp[(1) - (3)]).first_line); yyerrok; delete (yyvsp[(1) - (3)].iName); ;}
    break;

  case 72:
#line 232 "parser.y"
    { (yyval.nPtr) = machine.create("ASSIGN_A", 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 73:
#line 233 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '='", (yylsp[(1) - (3)]).first_line); ;}
    break;

  case 74:
#line 238 "parser.y"
    { (yyval.nPtr) = machine.create("SWITCH", 5, (yyvsp[(2) - (8)].nPtr), machine.constant((yyvsp[(3) - (8)].iBool), "BOOL"), (yyvsp[(4) - (8)].nPtr), machine.constant((yyvsp[(6) - (8)].iBool), "BOOL"), (yyvsp[(7) - (8)].nPtr));;}
    break;

  case 75:
#line 239 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ']'", (yylsp[(1) - (8)]).first_line); yyerrok; ;}
    break;

  case 76:
#line 240 "parser.y"
    { (yyval.nPtr) = ERROR("Missed second flag", (yylsp[(1) - (6)]).first_line); yyerrok; ;}
    break;

  case 77:
#line 241 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '['", (yylsp[(6) - (6)]).first_line); yyerrok; ;}
    break;

  case 78:
#line 242 "parser.y"
    { (yyval.nPtr) = ERROR("Missed first flag", (yylsp[(1) - (3)]).first_line); yyerrok; ;}
    break;

  case 79:
#line 246 "parser.y"
    { (yyval.nPtr) = machine.appeal("APPEAL_A", (yyvsp[(1) - (4)].iName)); delete (yyvsp[(1) - (4)].iName); ;}
    break;

  case 80:
#line 247 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ']'", (yylsp[(1) - (4)]).first_line); yyerrok; delete (yyvsp[(1) - (4)].iName); ;}
    break;

  case 81:
#line 248 "parser.y"
    { (yyval.nPtr) = ERROR("Missed enumeration",(yylsp[(1) - (3)]).first_line); yyerrok;  delete (yyvsp[(1) - (3)].iName); ;}
    break;

  case 82:
#line 249 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '['", (yylsp[(1) - (2)]).first_line); yyerrok; delete (yyvsp[(1) - (2)].iName); ;}
    break;

  case 83:
#line 253 "parser.y"
    { (yyval.nPtr) = machine.create("FOR", 4, machine.id((yyvsp[(2) - (10)].iName)), machine.id((yyvsp[(4) - (10)].iName)), machine.id((yyvsp[(6) - (10)].iName)), (yyvsp[(9) - (10)].nPtr)); delete (yyvsp[(2) - (10)].iName); delete (yyvsp[(4) - (10)].iName); delete (yyvsp[(6) - (10)].iName); ;}
    break;

  case 84:
#line 254 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ')' for loop block", (yylsp[(1) - (11)]).first_line); yyerrok; ;}
    break;

  case 85:
#line 258 "parser.y"
    { (yyval.nPtr) = nullptr; ;}
    break;

  case 86:
#line 259 "parser.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); ;}
    break;

  case 87:
#line 263 "parser.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 88:
#line 264 "parser.y"
    { (yyval.nPtr) = machine.create("ENDLINE", 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 89:
#line 268 "parser.y"
    { (yyval.nPtr) = machine.putId((yyvsp[(2) - (7)].iName), (yyvsp[(7) - (7)].iValue), "INT"); delete (yyvsp[(2) - (7)].iName); ;}
    break;

  case 90:
#line 269 "parser.y"
    { (yyval.nPtr) = machine.putId((yyvsp[(2) - (7)].iName), (yyvsp[(7) - (7)].iBool), "BOOL"); delete (yyvsp[(2) - (7)].iName); ;}
    break;

  case 91:
#line 270 "parser.y"
    { (yyval.nPtr) = machine.putId((yyvsp[(2) - (4)].iName), (yyvsp[(4) - (4)].iValue), "INT"); delete (yyvsp[(2) - (4)].iName); ;}
    break;

  case 92:
#line 271 "parser.y"
    { (yyval.nPtr) = machine.putId((yyvsp[(2) - (4)].iName), (yyvsp[(4) - (4)].iBool), "BOOL"); delete (yyvsp[(2) - (4)].iName); ;}
    break;

  case 93:
#line 272 "parser.y"
    { (yyval.nPtr) = ERROR("Missed literal", (yylsp[(7) - (7)]).first_line); yyerrok; delete (yyvsp[(2) - (7)].iName); ;}
    break;

  case 94:
#line 273 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '='", (yylsp[(6) - (6)]).first_line); yyerrok; delete (yyvsp[(2) - (6)].iName); ;}
    break;

  case 95:
#line 274 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ']'", (yylsp[(5) - (5)]).first_line); yyerrok; delete (yyvsp[(2) - (5)].iName); ;}
    break;

  case 96:
#line 275 "parser.y"
    { (yyval.nPtr) = ERROR("Missed enumeration size", (yylsp[(4) - (4)]).first_line); yyerrok; delete (yyvsp[(2) - (4)].iName); ;}
    break;

  case 97:
#line 276 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '[' or '='", (yylsp[(3) - (3)]).first_line); yyerrok; delete (yyvsp[(2) - (3)].iName); ;}
    break;

  case 98:
#line 277 "parser.y"
    { (yyval.nPtr) = ERROR("Missed literal", (yylsp[(4) - (4)]).first_line); yyerrok; delete (yyvsp[(2) - (4)].iName); ;}
    break;

  case 99:
#line 278 "parser.y"
    { (yyval.nPtr) = ERROR("Missed name", (yylsp[(2) - (2)]).first_line); yyerrok;;}
    break;

  case 100:
#line 282 "parser.y"
    { (yyval.nPtr) = machine.create("LOGITIZE", 1, machine.id((yyvsp[(2) - (2)].iName))); delete (yyvsp[(2) - (2)].iName); ;}
    break;

  case 101:
#line 283 "parser.y"
    { (yyval.nPtr) = machine.create("DIGITIZE", 1, machine.id((yyvsp[(2) - (2)].iName))); delete (yyvsp[(2) - (2)].iName); ;}
    break;

  case 102:
#line 284 "parser.y"
    { (yyval.nPtr) = machine.create("REDUCE", 2, machine.id((yyvsp[(2) - (5)].iName)), machine.constant((yyvsp[(4) - (5)].iValue), "INT")); delete (yyvsp[(2) - (5)].iName); ;}
    break;

  case 103:
#line 285 "parser.y"
    { (yyval.nPtr) = machine.create("EXTENED", 2 , machine.id((yyvsp[(2) - (5)].iName)), machine.constant((yyvsp[(4) - (5)].iValue), "INT")); delete (yyvsp[(2) - (5)].iName); ;}
    break;

  case 104:
#line 286 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ']'", (yylsp[(1) - (5)]).first_line); yyerrok;  delete (yyvsp[(2) - (5)].iName);;}
    break;

  case 105:
#line 287 "parser.y"
    { (yyval.nPtr) = ERROR("Missed number", (yylsp[(1) - (4)]).first_line); yyerrok; delete (yyvsp[(2) - (4)].iName); ;}
    break;

  case 106:
#line 288 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '['", (yylsp[(1) - (3)]).first_line); yyerrok; delete (yyvsp[(2) - (3)].iName); ;}
    break;

  case 107:
#line 289 "parser.y"
    { (yyval.nPtr) = ERROR("Missed variable", (yylsp[(1) - (2)]).first_line); yyerrok;;}
    break;

  case 108:
#line 290 "parser.y"
    { (yyval.nPtr) = ERROR("Missed ']'", (yylsp[(1) - (5)]).first_line); yyerrok; delete (yyvsp[(2) - (5)].iName); ;}
    break;

  case 109:
#line 291 "parser.y"
    { (yyval.nPtr) = ERROR("Missed number", (yylsp[(1) - (4)]).first_line); yyerrok; delete (yyvsp[(2) - (4)].iName); ;}
    break;

  case 110:
#line 292 "parser.y"
    { (yyval.nPtr) = ERROR("Missed '['", (yylsp[(1) - (3)]).first_line); yyerrok; delete (yyvsp[(2) - (3)].iName); ;}
    break;

  case 111:
#line 293 "parser.y"
    { (yyval.nPtr) = ERROR("Missed variable", (yylsp[(1) - (2)]).first_line); yyerrok;;}
    break;


/* Line 1267 of yacc.c.  */
#line 2402 "parser.tab.c"
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


#line 295 "parser.y"


//setting
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

    // std::cout << "FREENODE" << '\n'; 
    if (node == nullptr) 
        return;
    // std::cout << node->type << '\n';
    Node *ptr = nullptr;
 

    if((ptr = dynamic_cast<Node*>(node)))
    {
        if (ptr == nullptr)
            return;
        // std::cout << "QUANTITY LEAFS " << ptr->leafs.size() << '\n';
        for(int i = 0; i < ptr->leafs.size(); ++i)
        {
                freeNode(ptr->leafs[i]);
        }
    }
    // std::cout << "tick" << '\n';
    if (node) 
        delete node;
    // std::cout << "tack" << '\n';
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

