
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 13 "yacc.y"

    int intVal;    
    char charVal;               
	float floatVal; 

    struct info{
    int typeId; //0-int, 1-float, 2-char
    int ival;
    float fval;
  }info;                           



/* Line 1676 of yacc.c  */
#line 114 "yacc.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


