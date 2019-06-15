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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 78 "parser.y"
{
    Vertex *nPtr;
    int iValue;
    bool iBool;
    char* iName;  
}
/* Line 1529 of yacc.c.  */
#line 126 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;
