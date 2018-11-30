/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_FRONT_JAVA_TAB_H_INCLUDED
# define YY_YY_FRONT_JAVA_TAB_H_INCLUDED
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
    _PRIVATE = 258,
    _PROTECTED = 259,
    _PUBLIC = 260,
    _ABSTRACT = 261,
    _EXTENDS = 262,
    _FINAL = 263,
    _IMPLEMENTS = 264,
    _NATIVE = 265,
    _NEW = 266,
    _STATIC = 267,
    _STRICTFP = 268,
    _TRANSIENT = 269,
    _VOLATILE = 270,
    _BREAK = 271,
    _CONTINUE = 272,
    _RETURN = 273,
    _DO = 274,
    _WHILE = 275,
    _IF = 276,
    _ELSE = 277,
    _FOR = 278,
    _INSTANCEOF = 279,
    _SWITCH = 280,
    _CASE = 281,
    _DEFAULT = 282,
    _TRY = 283,
    _CATCH = 284,
    _FINALLY = 285,
    _THROW = 286,
    _THROWS = 287,
    _ASSERT = 288,
    _SYNCHRONIZED = 289,
    _IMPORT = 290,
    _PACKAGE = 291,
    _BOOLEAN = 292,
    _BYTE = 293,
    _CHAR = 294,
    _DOUBLE = 295,
    _FLOAT = 296,
    _INT = 297,
    _LONG = 298,
    _SHORT = 299,
    _VOID = 300,
    _STRING = 301,
    _ENUM = 302,
    _CLASS = 303,
    _INTERFACE = 304,
    _TRUE = 305,
    _FALSE = 306,
    _NUL = 307,
    _SUPER = 308,
    _THIS = 309,
    _ADD = 310,
    _SUB = 311,
    _MUL = 312,
    _DIV = 313,
    _MOD = 314,
    _ADD2 = 315,
    _SUB2 = 316,
    _CMP = 317,
    _NCMP = 318,
    _MORE = 319,
    _LESS = 320,
    _MCMP = 321,
    _LCMP = 322,
    _AND = 323,
    _OR = 324,
    _XOR = 325,
    _NOT = 326,
    _SHL = 327,
    _SHR = 328,
    _SAR = 329,
    _BAND = 330,
    _BOR = 331,
    _BNOT = 332,
    _MOV = 333,
    _ADDMOV = 334,
    _SUBMOV = 335,
    _MULMOV = 336,
    _DIVMOV = 337,
    _MODMOV = 338,
    _SHLMOV = 339,
    _SHRMOV = 340,
    _ANDMOV = 341,
    _XORMOV = 342,
    _ORMOV = 343,
    _LBRACE = 344,
    _RBRACE = 345,
    _LBRACKET = 346,
    _RBRACKET = 347,
    _LPARENTHESE = 348,
    _RPARENTHESE = 349,
    _SEMICOLON = 350,
    _COMMA = 351,
    _POINT = 352,
    _DOUBT = 353,
    _COLON = 354,
    _SYMBOL = 355,
    _CUSTCHAR = 356,
    _CUSTSTRING = 357,
    _CUSTINT = 358,
    _CUSTFLOAT = 359
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 37 "front/java.y" /* yacc.c:1909  */

	pNode pnode;

#line 163 "front/java.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_FRONT_JAVA_TAB_H_INCLUDED  */
