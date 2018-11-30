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
#line 7 "front/java.y" /* yacc.c:339  */

	
    #include <stdio.h>
    #include <string.h>
	#include "tool/tree.h"	
	//语法树构造用宏  #为字符串化
	#define MNNA(i,x) MakeNodeNoAtt(i,ls,x,#x)
	
	//extern是指定义(分配空间)在其它地方，函数声明与定义是分开的通过声明使用因此都不用加extren，变量为声明并定义因此要加。
	int yylex(void);
	extern FILE * yyin;
	extern char * yytext;
	extern int line;

	extern int symbolnum;
	extern int floatnum;
	extern int intnum;
	extern int stringnum;
	extern int charnum;
	
	pNode root;
	
	
	int yyerror(char *s);
	
	

#line 94 "front/java.tab.c" /* yacc.c:339  */

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
   by #include "java.tab.h".  */
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
#line 37 "front/java.y" /* yacc.c:355  */

	pNode pnode;

#line 243 "front/java.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_FRONT_JAVA_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 260 "front/java.tab.c" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2002

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  186
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  367

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   359

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   187,   192,   195,   199,   202,   206,   211,
     213,   218,   220,   225,   227,   237,   239,   244,   246,   248,
     253,   256,   259,   261,   263,   265,   267,   269,   271,   273,
     275,   280,   282,   287,   290,   294,   296,   298,   300,   302,
     308,   310,   312,   314,   319,   324,   327,   331,   333,   335,
     337,   339,   341,   343,   345,   347,   349,   351,   356,   358,
     364,   369,   373,   376,   381,   383,   385,   387,   389,   391,
     393,   395,   397,   399,   401,   403,   405,   407,   409,   411,
     413,   415,   417,   422,   427,   429,   434,   436,   441,   443,
     445,   447,   452,   454,   460,   462,   464,   468,   470,   472,
     474,   476,   478,   480,   482,   484,   486,   488,   490,   492,
     494,   496,   498,   503,   505,   507,   509,   511,   513,   515,
     517,   519,   521,   523,   525,   527,   529,   531,   533,   539,
     541,   543,   545,   547,   549,   555,   557,   559,   561,   563,
     569,   571,   573,   575,   577,   579,   581,   583,   585,   587,
     589,   591,   606,   611,   613,   615,   617,   622,   624,   629,
     631,   633,   635,   640,   642,   647,   650,   654,   659,   664,
     666,   670,   673,   677,   679,   684,   687,   691,   695,   697,
     699,   702,   706,   708,   713,   718,   720
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_PRIVATE", "_PROTECTED", "_PUBLIC",
  "_ABSTRACT", "_EXTENDS", "_FINAL", "_IMPLEMENTS", "_NATIVE", "_NEW",
  "_STATIC", "_STRICTFP", "_TRANSIENT", "_VOLATILE", "_BREAK", "_CONTINUE",
  "_RETURN", "_DO", "_WHILE", "_IF", "_ELSE", "_FOR", "_INSTANCEOF",
  "_SWITCH", "_CASE", "_DEFAULT", "_TRY", "_CATCH", "_FINALLY", "_THROW",
  "_THROWS", "_ASSERT", "_SYNCHRONIZED", "_IMPORT", "_PACKAGE", "_BOOLEAN",
  "_BYTE", "_CHAR", "_DOUBLE", "_FLOAT", "_INT", "_LONG", "_SHORT",
  "_VOID", "_STRING", "_ENUM", "_CLASS", "_INTERFACE", "_TRUE", "_FALSE",
  "_NUL", "_SUPER", "_THIS", "_ADD", "_SUB", "_MUL", "_DIV", "_MOD",
  "_ADD2", "_SUB2", "_CMP", "_NCMP", "_MORE", "_LESS", "_MCMP", "_LCMP",
  "_AND", "_OR", "_XOR", "_NOT", "_SHL", "_SHR", "_SAR", "_BAND", "_BOR",
  "_BNOT", "_MOV", "_ADDMOV", "_SUBMOV", "_MULMOV", "_DIVMOV", "_MODMOV",
  "_SHLMOV", "_SHRMOV", "_ANDMOV", "_XORMOV", "_ORMOV", "_LBRACE",
  "_RBRACE", "_LBRACKET", "_RBRACKET", "_LPARENTHESE", "_RPARENTHESE",
  "_SEMICOLON", "_COMMA", "_POINT", "_DOUBT", "_COLON", "_SYMBOL",
  "_CUSTCHAR", "_CUSTSTRING", "_CUSTINT", "_CUSTFLOAT", "$accept",
  "compilation_unit", "import_statements", "type_declarations",
  "package_statement", "package_name", "import_statement", "class_name",
  "type_declaration", "class_declaration", "modifiers", "modifier",
  "implements", "field_declarations", "field_declaration",
  "method_declaration", "type", "brackets", "type_specifier",
  "parameter_list", "parameter", "statement_block", "statements",
  "statement", "variable_declaration", "variable_declarators",
  "variable_declarator", "variable_initializer", "variable_initializers",
  "expression", "numeric_expression", "testing_expression",
  "logical_expression", "bit_expression", "casting_expression",
  "creating_expression", "arglist", "literal_expression", "if_statement",
  "elseifs", "do_statement", "while_statement", "for_statement",
  "expression01", "try_statement", "catchs", "switch_statement", "cases",
  "constructor_declaration", "static_initializer", "interface_declaration", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359
};
# endif

#define YYPACT_NINF -296

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-296)))

#define YYTABLE_NINF -173

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -23,   -69,    33,     7,  -296,  -296,   -65,  -296,   -45,   127,
    -296,     7,  -296,    30,    56,    68,    71,  -296,  -296,   614,
    -296,   159,  -296,   -47,  -296,  -296,  -296,  -296,  -296,  -296,
    -296,  -296,  -296,  -296,    67,    69,  -296,    73,    74,    57,
      40,  -296,   -45,   -45,  -296,   -45,  -296,    76,   165,  -296,
     -48,    38,   -31,    44,    77,   -45,  -296,   -45,    86,  -296,
    -296,   181,  -296,  -296,  -296,  -296,  -296,  -296,  -296,   -28,
      47,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,
    -296,  -296,  -296,  -296,   -30,  -296,    79,  -296,    50,  -296,
    -296,   360,   295,    83,   -10,  -296,    89,  -296,    62,  1693,
     -66,    61,   662,   423,    88,    90,    95,    97,   423,   852,
     103,  -296,  -296,  -296,  -296,  -296,   852,   852,   852,   852,
     852,  -296,   554,  -296,    98,  -296,  -296,  -296,  -296,   261,
    -296,  -296,  -296,   996,  -296,  -296,  -296,  -296,  -296,  -296,
    -296,  -296,  -296,  -296,  -296,  -296,  -296,    86,    82,   -80,
    -296,   897,   -63,  -296,    99,   110,  -296,   112,   116,  -296,
     108,  -296,   115,  -296,  -296,  1043,   192,   852,   852,   717,
     852,  -296,  1090,   852,   471,   185,   185,   185,   185,   -13,
     119,  1137,   423,    99,   -45,   852,   852,   852,   852,   852,
    -296,  -296,   852,   852,   852,   852,   852,   852,   852,   852,
     852,   852,   852,   852,   852,   852,   852,   852,   852,   852,
     852,   852,   852,   852,   852,   852,   852,   852,   729,  -296,
     852,   852,   852,  -296,  -296,    86,  1693,   -43,   -51,   784,
    -296,  -296,  -296,   797,   852,    89,  -296,  -296,  -296,   121,
    1184,  1231,   852,  1560,   135,  1278,   134,  -296,  1325,   852,
    -296,  -296,  -296,   471,   471,   185,   185,   185,  1882,  1882,
    1904,  1904,  1904,  1904,  1838,  1748,  1793,   578,   578,   578,
    1701,  1654,  1607,  1607,  1607,  1607,  1607,  1607,  1607,  1607,
    1607,  1607,  1607,  1372,  -296,  1560,    53,  1607,   -16,   902,
      89,  -296,  -296,  -296,  -296,    43,   590,  -296,  1560,  -296,
      64,  1419,   852,   423,   423,   136,   852,   143,   140,   423,
      86,  1560,  -296,  -296,   852,   852,  -296,  -296,  -296,  -296,
      58,  -296,  -296,  1466,  -296,  -296,   852,   139,  -296,  1693,
    -296,  -296,  1607,  1560,  -296,   648,  -296,   152,   213,   142,
     852,   297,   154,  -296,  -296,  -296,   486,   423,   155,   852,
     153,  -296,  -296,   423,   160,  -296,  -296,   423,   949,  -296,
    -296,   852,  -296,  -296,  1513,   423,  -296
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     7,     5,     9,     0,     1,     0,    21,
       4,     7,     8,     0,    13,     0,     0,     6,    15,     0,
      16,    21,    10,     0,    12,    22,    23,    24,    25,    26,
      27,    28,    29,    30,     0,     0,    20,     0,    14,     0,
       0,    11,     0,     0,    34,     0,    34,     0,     0,    32,
       0,    21,     0,    21,     0,     0,    34,     0,     0,    19,
      39,     0,    33,    35,    37,    36,    38,    34,   186,     0,
      21,    31,    63,   184,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    13,    57,     0,    46,    21,    34,
      18,    21,     0,    46,     0,    84,    44,   185,    21,     0,
       0,     0,     0,    21,     0,     0,     0,     0,    21,     0,
       0,   138,   139,   101,   102,   103,     0,     0,     0,     0,
       0,    61,     0,    82,   104,   159,   160,   161,   162,     0,
      66,    62,    64,     0,    94,    95,    96,    97,    98,    99,
     100,    67,    68,    69,    70,    71,    72,     0,     0,     0,
      58,     0,    87,    83,     0,     0,    17,    57,    46,    79,
       0,    80,     0,    75,   104,     0,     0,     0,     0,    21,
       0,   176,     0,     0,   113,   114,   115,   140,   135,   104,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
     116,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,     0,     0,   183,    46,     0,     0,     0,     0,     0,
      46,    85,    45,     0,     0,   156,    78,    81,    74,     0,
       0,     0,   172,   171,     0,     0,   174,    76,     0,     0,
     105,    77,   111,   118,   119,   120,   121,   122,   129,   130,
     131,   132,   133,   134,   141,   142,   143,   144,   145,   146,
     136,   137,   128,   123,   124,   125,   126,   127,   147,   148,
     149,   150,   151,     0,   107,   157,     0,   110,   109,     0,
      60,   182,    59,    43,    41,     0,     0,    86,    88,   153,
       0,     0,     0,    21,    21,     0,   172,     0,     0,    21,
       0,   152,   108,   106,     0,     0,    42,    40,    89,    92,
       0,   154,    46,     0,   168,   166,   172,     0,   181,     0,
     173,    73,   158,   112,    91,     0,   155,     0,   163,     0,
     172,    21,     0,    90,    93,   167,    21,    21,     0,     0,
       0,   177,   180,    21,     0,   164,   170,    21,     0,   179,
     175,     0,   169,   178,     0,    21,   165
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -296,  -296,   252,   246,  -296,    75,  -296,    -6,  -296,  -296,
     141,  -296,   -20,   -29,  -296,  -296,   -49,   -81,   161,   107,
    -203,   -55,  -296,  -103,   -44,  -296,   105,  -295,  -296,   -98,
    -296,  -296,  -296,  -296,  -296,  -296,    28,  -296,  -296,  -296,
    -296,  -296,  -296,  -185,  -296,  -296,  -296,  -296,  -296,  -296,
    -296
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,     4,    47,    10,    85,    17,    18,
     129,    36,    50,    51,    62,    63,   148,   152,    87,   149,
     150,   130,    91,   131,   132,    94,    95,   297,   320,   133,
     134,   135,   136,   137,   138,   139,   286,   140,   141,   338,
     142,   143,   144,   244,   145,   246,   146,   341,    65,    66,
      20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     166,   319,    16,    73,   165,   171,    96,    64,   184,    64,
      37,   172,    86,     1,   225,   229,   226,    53,   174,   175,
     176,   177,   178,   292,   181,    52,    64,    70,   155,   159,
      12,     5,    13,     7,   160,    69,    48,    49,    88,    49,
     344,    56,     8,   295,    64,   226,    72,    45,    57,    49,
      58,    71,   293,    38,    64,    14,    58,   305,    67,    58,
      98,    89,    58,    92,    42,    57,    43,    -9,    57,   240,
     241,   243,   245,   180,    58,   248,     6,   235,   -13,   251,
     183,   -13,   222,    15,    -9,   153,   154,   253,   254,   255,
     256,   257,   223,   157,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     285,   327,   287,   288,   289,   242,   342,    -3,    59,    46,
      22,   298,    72,    60,    68,   285,   301,    90,   316,    60,
      97,   339,    60,   290,   243,    60,    44,   313,   334,   314,
      19,   311,   156,    -9,   335,   348,   161,    60,   321,    -2,
     314,   162,    19,   308,   309,    23,    24,    39,    41,    40,
     291,   -10,   294,    54,    55,    72,   151,    38,   252,    93,
     155,   167,   224,   168,    25,    26,    27,    28,   169,    29,
     170,    30,    61,    31,    61,    32,   173,   182,   298,   230,
     324,   325,   232,   236,   323,   233,   330,   234,   243,   184,
     237,    61,   239,   249,   302,    33,   332,   333,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,   243,    61,
     306,   326,   328,   329,   340,   346,   347,   298,   352,    61,
     317,   336,   243,   355,   356,   190,   191,   345,   353,   357,
     360,   358,   359,   361,   362,   331,    11,    21,   228,   231,
     158,   300,   366,   364,    25,    26,    27,    28,     0,    29,
       0,    30,     0,    31,     0,    32,   217,     0,   218,     0,
       0,    84,   221,   222,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    99,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,     0,
     106,     0,   107,   349,   350,   108,     0,     0,   109,     0,
       0,   110,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,     0,     0,     0,     0,   111,   112,   113,
     114,   115,     0,   116,     0,     0,     0,   117,   118,     0,
       0,    14,     0,     0,     0,     0,     0,     0,   119,     0,
       0,    99,     0,     0,   120,     0,   100,   101,   102,   103,
     104,   105,     0,   106,     0,   107,    72,   351,   108,   147,
     122,   109,   123,     0,   110,    14,     0,   124,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
     111,   112,   113,   114,   115,     0,   116,     0,     0,     0,
     117,   118,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,     0,     0,    99,     0,     0,   120,     0,   100,
     101,   102,   103,   104,   105,     0,   106,     0,   107,    72,
     121,   108,     0,   122,   109,   123,     0,   110,     0,     0,
     124,   125,   126,   127,   128,     0,     0,     0,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,     0,   116,
       0,     0,     0,   117,   118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   184,     0,    99,     0,     0,
     120,     0,   100,   101,   102,   103,   104,   354,     0,   106,
       0,   107,    72,     0,   108,     0,   122,   109,   123,     0,
     110,     0,     0,   124,   125,   126,   127,   128,   187,   188,
     189,   190,   191,     0,     0,     0,   111,   112,   113,   114,
     115,     0,   116,     0,     0,     0,   117,   118,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   119,     0,     0,
       0,     0,   217,   120,   218,    99,     0,     0,   221,   222,
       0,     0,     0,     0,     0,    72,     0,     0,     0,   122,
       0,   123,     0,     0,     0,     0,   124,   125,   126,   127,
     128,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    99,   184,     0,   111,   112,   113,   114,   115,     0,
     116,     0,     0,     0,   117,   118,     0,    25,    26,    27,
      28,     0,    29,     0,    30,   119,    31,     0,    32,     0,
       0,   120,     0,   185,   186,   187,   188,   189,   190,   191,
     111,   112,   113,   114,   115,     0,   116,   122,    33,     0,
     117,   118,     0,     0,   179,   125,   126,   127,   128,    99,
       0,   119,    34,    35,     0,     0,     0,   120,     0,   217,
       0,   218,     0,    99,     0,   221,   222,     0,     0,   296,
     318,     0,     0,   122,     0,     0,     0,     0,     0,     0,
     164,   125,   126,   127,   128,     0,     0,     0,   111,   112,
     113,   114,   115,     0,   116,     0,     0,     0,   117,   118,
       0,     0,   111,   112,   113,   114,   115,     0,   116,   119,
       0,     0,   117,   118,     0,   120,     0,     0,    99,     0,
       0,     0,     0,   119,     0,     0,     0,   296,   343,   120,
      99,   122,     0,     0,     0,     0,     0,     0,   164,   125,
     126,   127,   128,     0,     0,   122,     0,   163,     0,     0,
       0,     0,   164,   125,   126,   127,   128,   111,   112,   113,
     114,   115,     0,   116,     0,     0,     0,   117,   118,   111,
     112,   113,   114,   115,     0,   116,     0,     0,   119,   117,
     118,     0,     0,     0,   120,    99,     0,     0,     0,     0,
     119,     0,     0,     0,     0,     0,   120,     0,    99,     0,
     122,     0,  -172,     0,     0,     0,     0,   164,   125,   126,
     127,   128,   122,   284,     0,     0,     0,     0,     0,   164,
     125,   126,   127,   128,   111,   112,   113,   114,   115,     0,
     116,     0,     0,     0,   117,   118,     0,   111,   112,   113,
     114,   115,     0,   116,     0,   119,     0,   117,   118,     0,
       0,   120,     0,    99,     0,     0,     0,     0,   119,     0,
       0,     0,     0,   296,   120,     0,     0,   122,     0,     0,
       0,     0,     0,     0,   164,   125,   126,   127,   128,     0,
     122,   299,     0,     0,     0,     0,     0,   164,   125,   126,
     127,   128,   111,   112,   113,   114,   115,     0,   116,     0,
       0,     0,   117,   118,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,     0,     0,   184,     0,     0,   120,
       0,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     0,   122,     0,     0,     0,     0,
       0,     0,   164,   125,   126,   127,   128,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   184,   201,   202,   203,   204,   205,     0,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   227,     0,   217,     0,   218,     0,    14,   220,   221,
     222,   315,     0,     0,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     184,   201,   202,   203,   204,   205,     0,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,     0,     0,
     217,     0,   218,     0,     0,   220,   221,   222,   363,     0,
       0,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   184,   201,   202,
     203,   204,   205,     0,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,     0,     0,   217,     0,   218,
       0,   219,   220,   221,   222,     0,     0,     0,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   184,   201,   202,   203,   204,   205,
       0,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,     0,   217,     0,   218,     0,   238,   220,
     221,   222,     0,     0,     0,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   184,   201,   202,   203,   204,   205,     0,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,     0,
       0,   217,     0,   218,     0,   247,   220,   221,   222,     0,
       0,     0,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   184,   201,
     202,   203,   204,   205,     0,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,     0,     0,   217,     0,
     218,   250,     0,   220,   221,   222,     0,     0,     0,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   184,   201,   202,   203,   204,
     205,     0,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,     0,     0,   217,     0,   218,   303,     0,
     220,   221,   222,     0,     0,     0,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   184,   201,   202,   203,   204,   205,     0,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
       0,     0,   217,     0,   218,   304,     0,   220,   221,   222,
       0,     0,     0,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   184,
     201,   202,   203,   204,   205,     0,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,     0,     0,   217,
       0,   218,   307,     0,   220,   221,   222,     0,     0,     0,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   184,   201,   202,   203,
     204,   205,     0,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,     0,     0,   217,     0,   218,   310,
       0,   220,   221,   222,     0,     0,     0,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   184,   201,   202,   203,   204,   205,     0,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,     0,     0,   217,   312,   218,     0,     0,   220,   221,
     222,     0,     0,     0,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     184,   201,   202,   203,   204,   205,     0,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,     0,     0,
     217,   322,   218,     0,     0,   220,   221,   222,     0,     0,
       0,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   184,   201,   202,
     203,   204,   205,     0,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,     0,     0,   217,     0,   218,
     337,     0,   220,   221,   222,     0,     0,     0,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   184,   201,   202,   203,   204,   205,
       0,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,     0,   217,     0,   218,   365,     0,   220,
     221,   222,     0,     0,     0,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   184,   201,   202,   203,   204,   205,     0,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,     0,
       0,   217,     0,   218,     0,     0,   220,   221,   222,     0,
       0,     0,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   184,   201,
     202,   203,   204,   205,     0,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,     0,     0,   217,     0,
     218,     0,     0,     0,   221,   222,     0,     0,     0,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   184,   201,   202,   203,   204,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,   217,     0,   218,     0,     0,
       0,   221,   222,     0,     0,     0,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   184,   201,   202,   203,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   217,    14,   218,     0,     0,     0,   221,   222,
       0,     0,     0,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   184,   200,     0,
     201,   202,   203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   217,
       0,   218,     0,     0,     0,   221,   222,     0,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   184,     0,     0,   201,   202,   203,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   217,     0,   218,     0,     0,     0,
     221,   222,     0,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   184,     0,     0,     0,
     201,   202,   203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   184,   217,
       0,   218,     0,     0,     0,   221,   222,   185,   186,   187,
     188,   189,   190,   191,     0,     0,   194,   195,   196,   197,
       0,     0,     0,     0,   201,   202,   203,     0,     0,   185,
     186,   187,   188,   189,   190,   191,     0,     0,     0,     0,
       0,     0,     0,   217,     0,   218,   201,   202,   203,   221,
     222,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   217,     0,   218,     0,     0,
       0,   221,   222
};

static const yytype_int16 yycheck[] =
{
     103,   296,     8,    58,   102,   108,    87,    51,    24,    53,
      57,   109,    61,    36,    94,    78,    96,    46,   116,   117,
     118,   119,   120,   226,   122,    45,    70,    56,    91,    95,
      95,   100,    97,     0,   100,    55,    42,    43,    67,    45,
     335,    89,    35,    94,    88,    96,    89,     7,    96,    55,
      12,    57,    95,   100,    98,   100,    12,   242,    89,    12,
      89,    89,    12,    93,     7,    96,     9,    97,    96,   167,
     168,   169,   170,   122,    12,   173,     1,   158,    91,   182,
     129,    94,    98,     8,    97,    95,    96,   185,   186,   187,
     188,   189,   147,    99,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   306,   220,   221,   222,   169,   329,     0,    90,    89,
     100,   229,    89,    95,    90,   233,   234,    90,    95,    95,
      90,   326,    95,   224,   242,    95,    89,    94,    90,    96,
       9,   249,    90,    97,    96,   340,    95,    95,    94,     0,
      96,   100,    21,    29,    30,    97,    95,   100,    95,   100,
     225,    97,   227,    97,     9,    89,    93,   100,   184,   100,
      91,    93,   100,    93,     3,     4,     5,     6,    93,     8,
      93,    10,    51,    12,    53,    14,    93,    99,   296,   100,
     303,   304,    92,    95,   302,    93,   309,    91,   306,    24,
      95,    70,    20,    94,    93,    34,   314,   315,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,   326,    88,
      95,    95,    89,    93,    95,    22,    94,   335,   341,    98,
     295,   322,   340,   346,   347,    60,    61,    95,    94,    94,
     353,   349,    99,    93,   357,   310,     4,    11,   151,   154,
      99,   233,   365,   361,     3,     4,     5,     6,    -1,     8,
      -1,    10,    -1,    12,    -1,    14,    91,    -1,    93,    -1,
      -1,   100,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    11,    -1,
      -1,    -1,    -1,    16,    17,    18,    19,    20,    21,    -1,
      23,    -1,    25,    26,    27,    28,    -1,    -1,    31,    -1,
      -1,    34,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    -1,    56,    -1,    -1,    -1,    60,    61,    -1,
      -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    11,    -1,    -1,    77,    -1,    16,    17,    18,    19,
      20,    21,    -1,    23,    -1,    25,    89,    90,    28,    94,
      93,    31,    95,    -1,    34,   100,    -1,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    -1,    56,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    11,    -1,    -1,    77,    -1,    16,
      17,    18,    19,    20,    21,    -1,    23,    -1,    25,    89,
      90,    28,    -1,    93,    31,    95,    -1,    34,    -1,    -1,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    -1,    56,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    24,    -1,    11,    -1,    -1,
      77,    -1,    16,    17,    18,    19,    20,    21,    -1,    23,
      -1,    25,    89,    -1,    28,    -1,    93,    31,    95,    -1,
      34,    -1,    -1,   100,   101,   102,   103,   104,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    -1,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      -1,    -1,    91,    77,    93,    11,    -1,    -1,    97,    98,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    93,
      -1,    95,    -1,    -1,    -1,    -1,   100,   101,   102,   103,
     104,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    11,    24,    -1,    50,    51,    52,    53,    54,    -1,
      56,    -1,    -1,    -1,    60,    61,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    10,    71,    12,    -1,    14,    -1,
      -1,    77,    -1,    55,    56,    57,    58,    59,    60,    61,
      50,    51,    52,    53,    54,    -1,    56,    93,    34,    -1,
      60,    61,    -1,    -1,   100,   101,   102,   103,   104,    11,
      -1,    71,    48,    49,    -1,    -1,    -1,    77,    -1,    91,
      -1,    93,    -1,    11,    -1,    97,    98,    -1,    -1,    89,
      90,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    -1,    56,    -1,    -1,    -1,    60,    61,
      -1,    -1,    50,    51,    52,    53,    54,    -1,    56,    71,
      -1,    -1,    60,    61,    -1,    77,    -1,    -1,    11,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    89,    90,    77,
      11,    93,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
     102,   103,   104,    -1,    -1,    93,    -1,    95,    -1,    -1,
      -1,    -1,   100,   101,   102,   103,   104,    50,    51,    52,
      53,    54,    -1,    56,    -1,    -1,    -1,    60,    61,    50,
      51,    52,    53,    54,    -1,    56,    -1,    -1,    71,    60,
      61,    -1,    -1,    -1,    77,    11,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,    -1,    77,    -1,    11,    -1,
      93,    -1,    95,    -1,    -1,    -1,    -1,   100,   101,   102,
     103,   104,    93,    94,    -1,    -1,    -1,    -1,    -1,   100,
     101,   102,   103,   104,    50,    51,    52,    53,    54,    -1,
      56,    -1,    -1,    -1,    60,    61,    -1,    50,    51,    52,
      53,    54,    -1,    56,    -1,    71,    -1,    60,    61,    -1,
      -1,    77,    -1,    11,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    89,    77,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,    -1,
      93,    94,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,
     103,   104,    50,    51,    52,    53,    54,    -1,    56,    -1,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    24,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   101,   102,   103,   104,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    24,    72,    73,    74,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    94,    -1,    91,    -1,    93,    -1,   100,    96,    97,
      98,    99,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      24,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    -1,
      91,    -1,    93,    -1,    -1,    96,    97,    98,    99,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    24,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    91,    -1,    93,
      -1,    95,    96,    97,    98,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    24,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    91,    -1,    93,    -1,    95,    96,
      97,    98,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    24,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    93,    -1,    95,    96,    97,    98,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    24,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    -1,    91,    -1,
      93,    94,    -1,    96,    97,    98,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    24,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    -1,    91,    -1,    93,    94,    -1,
      96,    97,    98,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    24,    72,    73,    74,    75,    76,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    -1,    91,    -1,    93,    94,    -1,    96,    97,    98,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    24,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    -1,    91,
      -1,    93,    94,    -1,    96,    97,    98,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    24,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    91,    -1,    93,    94,
      -1,    96,    97,    98,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    24,    72,    73,    74,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    91,    92,    93,    -1,    -1,    96,    97,
      98,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      24,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    -1,
      91,    92,    93,    -1,    -1,    96,    97,    98,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    24,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    91,    -1,    93,
      94,    -1,    96,    97,    98,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    24,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    91,    -1,    93,    94,    -1,    96,
      97,    98,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    24,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    93,    -1,    -1,    96,    97,    98,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    24,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    -1,    91,    -1,
      93,    -1,    -1,    -1,    97,    98,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    24,    72,    73,    74,    75,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    93,    -1,    -1,
      -1,    97,    98,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    24,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,   100,    93,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    24,    70,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    93,    -1,    -1,    -1,    97,    98,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    24,    -1,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    93,    -1,    -1,    -1,
      97,    98,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    24,    -1,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    91,
      -1,    93,    -1,    -1,    -1,    97,    98,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    64,    65,    66,    67,
      -1,    -1,    -1,    -1,    72,    73,    74,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    93,    72,    73,    74,    97,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    93,    -1,    -1,
      -1,    97,    98
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,   106,   107,   109,   100,   110,     0,    35,   108,
     111,   107,    95,    97,   100,   110,   112,   113,   114,   115,
     155,   108,   100,    97,    95,     3,     4,     5,     6,     8,
      10,    12,    14,    34,    48,    49,   116,    57,   100,   100,
     100,    95,     7,     9,    89,     7,    89,   110,   112,   112,
     117,   118,   117,   118,    97,     9,    89,    96,    12,    90,
      95,   115,   119,   120,   129,   153,   154,    89,    90,   117,
     118,   112,    89,   126,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   100,   112,   121,   123,   118,    89,
      90,   127,    93,   100,   130,   131,   122,    90,   118,    11,
      16,    17,    18,    19,    20,    21,    23,    25,    28,    31,
      34,    50,    51,    52,    53,    54,    56,    60,    61,    71,
      77,    90,    93,    95,   100,   101,   102,   103,   104,   115,
     126,   128,   129,   134,   135,   136,   137,   138,   139,   140,
     142,   143,   145,   146,   147,   149,   151,    94,   121,   124,
     125,    93,   122,    95,    96,    91,    90,   112,   123,    95,
     100,    95,   100,    95,   100,   134,   128,    93,    93,    93,
      93,   128,   134,    93,   134,   134,   134,   134,   134,   100,
     121,   134,    99,   121,    24,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    72,    73,    74,    75,    76,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    91,    93,    95,
      96,    97,    98,   126,   100,    94,    96,    94,   124,    78,
     100,   131,    92,    93,    91,   122,    95,    95,    95,    20,
     134,   134,   129,   134,   148,   134,   150,    95,   134,    94,
      94,   128,   112,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,    94,   134,   141,   134,   134,   134,
     122,   126,   125,    95,   126,    94,    89,   132,   134,    94,
     141,   134,    93,    94,    94,   148,    95,    94,    29,    30,
      94,   134,    92,    94,    96,    99,    95,   126,    90,   132,
     133,    94,    92,   134,   128,   128,    95,   148,    89,    93,
     128,   126,   134,   134,    90,    96,   122,    94,   144,   148,
      95,   152,   125,    90,   132,    95,    22,    94,   148,    26,
      27,    90,   128,    94,    21,   128,   128,    94,   134,    99,
     128,    93,   128,    99,   134,    94,   128
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   106,   107,   107,   108,   108,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   114,   114,
     115,   115,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   117,   117,   118,   118,   119,   119,   119,   119,   119,
     120,   120,   120,   120,   121,   122,   122,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   124,   124,
     125,   126,   127,   127,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   129,   130,   130,   131,   131,   132,   132,
     132,   132,   133,   133,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   136,
     136,   136,   136,   136,   136,   137,   137,   137,   137,   137,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   139,   140,   140,   140,   140,   141,   141,   142,
     142,   142,   142,   143,   143,   144,   144,   145,   146,   147,
     147,   148,   148,   149,   149,   150,   150,   151,   152,   152,
     152,   152,   153,   153,   154,   155,   155
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     2,     0,     2,     0,     3,     1,
       3,     5,     3,     1,     3,     1,     1,    10,     8,     6,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     2,     0,     1,     1,     1,     1,     1,
       7,     6,     7,     6,     2,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     2,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     5,     3,     2,     3,     3,     3,     2,
       2,     3,     1,     4,     1,     3,     4,     2,     1,     2,
       4,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     4,     3,
       3,     3,     5,     2,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     1,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     4,     5,     6,     3,     1,     3,     1,
       1,     1,     1,     6,     8,     7,     0,     7,     5,     9,
       8,     1,     0,     5,     3,     6,     0,     7,     4,     3,
       2,     0,     6,     5,     2,     8,     6
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
#line 186 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  root=MNNA(3,compilation_unit);}
#line 1945 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 188 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  root=MNNA(2,compilation_unit);}
#line 1951 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 193 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,import_statements);}
#line 1957 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 195 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,import_statements);}
#line 1963 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 200 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,type_declarations);}
#line 1969 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 202 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,type_declarations);}
#line 1975 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 207 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,package_statement);}
#line 1981 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 212 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]={(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,package_name);}
#line 1987 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 214 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,package_name);}
#line 1993 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 219 "front/java.y" /* yacc.c:1646  */
    { pNode ls[5]={(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(5,import_statement);}
#line 1999 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 221 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,import_statement);}
#line 2005 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 226 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]={(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,class_name);}
#line 2011 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 228 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,class_name);}
#line 2017 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 238 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]={(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_declaration);}
#line 2023 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 240 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]={(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_declaration);}
#line 2029 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 245 "front/java.y" /* yacc.c:1646  */
    { pNode ls[10]={(yyvsp[-9].pnode),(yyvsp[-8].pnode),(yyvsp[-7].pnode),(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(10,class_declaration);}
#line 2035 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 247 "front/java.y" /* yacc.c:1646  */
    { pNode ls[8]={(yyvsp[-7].pnode),(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(8,class_declaration);}
#line 2041 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 249 "front/java.y" /* yacc.c:1646  */
    { pNode ls[6]={(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(6,class_declaration);}
#line 2047 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 254 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,modifiers);}
#line 2053 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 256 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,modifiers);}
#line 2059 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 260 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2065 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 262 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2071 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 264 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2077 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 266 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2083 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 268 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2089 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 270 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2095 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 272 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2101 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 274 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2107 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 276 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2113 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 281 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,implements);}
#line 2119 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 283 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,implements);}
#line 2125 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 288 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,field_declarations);}
#line 2131 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 290 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,field_declarations);}
#line 2137 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 295 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,field_declaration);}
#line 2143 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 297 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,field_declaration);}
#line 2149 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 299 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,field_declaration);}
#line 2155 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 301 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,field_declaration);}
#line 2161 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 303 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,field_declaration);}
#line 2167 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 309 "front/java.y" /* yacc.c:1646  */
    { pNode ls[7]={(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(7,method_declaration);}
#line 2173 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 311 "front/java.y" /* yacc.c:1646  */
    { pNode ls[6]={(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(6,method_declaration);}
#line 2179 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 313 "front/java.y" /* yacc.c:1646  */
    { pNode ls[7]={(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(7,method_declaration);}
#line 2185 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 315 "front/java.y" /* yacc.c:1646  */
    { pNode ls[6]={(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(6,method_declaration);}
#line 2191 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 320 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,type);}
#line 2197 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 325 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,brackets);}
#line 2203 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 327 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,brackets);}
#line 2209 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 332 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2215 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 334 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2221 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 336 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2227 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 338 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2233 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 340 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2239 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 342 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2245 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 344 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2251 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 346 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2257 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 348 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2263 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 350 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2269 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 352 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2275 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 357 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,parameter_list);}
#line 2281 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 359 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,parameter_list);}
#line 2287 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 365 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,parameter);}
#line 2293 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 370 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,statement_block);}
#line 2299 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 374 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,statements);}
#line 2305 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 376 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,statements);}
#line 2311 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 382 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2317 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 384 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,statement);}
#line 2323 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 386 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2329 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 388 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2335 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 390 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2341 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 392 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2347 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 394 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2353 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 396 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2359 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 398 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2365 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 400 "front/java.y" /* yacc.c:1646  */
    { pNode ls[5]={(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(5,statement);}
#line 2371 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 402 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,statement);}
#line 2377 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 404 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,statement);}
#line 2383 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 406 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,statement);}
#line 2389 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 408 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,statement);}
#line 2395 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 410 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,statement);}
#line 2401 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 412 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,statement);}
#line 2407 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 414 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,statement);}
#line 2413 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 416 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,statement);}
#line 2419 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 418 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2425 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 423 "front/java.y" /* yacc.c:1646  */
    { pNode ls[4]={(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(4,variable_declaration);}
#line 2431 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 428 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,variable_declarators);}
#line 2437 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 430 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,variable_declarators);}
#line 2443 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 435 "front/java.y" /* yacc.c:1646  */
    { pNode ls[4]={(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(4,variable_declarator);}
#line 2449 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 437 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,variable_declarator);}
#line 2455 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 442 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,variable_initializer);}
#line 2461 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 444 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,variable_initializer);}
#line 2467 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 446 "front/java.y" /* yacc.c:1646  */
    { pNode ls[4]={(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(4,variable_initializer);}
#line 2473 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 448 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,variable_initializer);}
#line 2479 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 453 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,variable_initializers);}
#line 2485 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 455 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,variable_initializers);}
#line 2491 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 461 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2497 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 463 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2503 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 465 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2509 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 469 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2515 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 471 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2521 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 473 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2527 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 475 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2533 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 477 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2539 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 479 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2545 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 481 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2551 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 483 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2557 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 485 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,expression);}
#line 2563 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 487 "front/java.y" /* yacc.c:1646  */
    { pNode ls[4]={(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(4,expression);}
#line 2569 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 489 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,expression);}
#line 2575 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 491 "front/java.y" /* yacc.c:1646  */
    { pNode ls[4]={(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(4,expression);}
#line 2581 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 493 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,expression);}
#line 2587 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 495 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,expression);}
#line 2593 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 497 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,expression);}
#line 2599 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 499 "front/java.y" /* yacc.c:1646  */
    { pNode ls[5]={(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(5,expression);}
#line 2605 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 504 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,numeric_expression);}
#line 2611 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 506 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,numeric_expression);}
#line 2617 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 508 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,numeric_expression);}
#line 2623 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 510 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,numeric_expression);}
#line 2629 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 512 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,numeric_expression);}
#line 2635 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 514 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2641 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 516 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2647 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 518 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2653 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 520 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2659 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 522 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2665 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 524 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2671 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 526 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2677 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 528 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2683 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 530 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2689 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 532 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2695 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 534 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2701 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 540 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,testing_expression);}
#line 2707 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 542 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,testing_expression);}
#line 2713 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 544 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,testing_expression);}
#line 2719 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 546 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,testing_expression);}
#line 2725 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 548 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,testing_expression);}
#line 2731 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 550 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,testing_expression);}
#line 2737 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 556 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,logical_expression);}
#line 2743 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 558 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,logical_expression);}
#line 2749 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 560 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,logical_expression);}
#line 2755 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 562 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,logical_expression);}
#line 2761 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 564 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,logical_expression);}
#line 2767 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 570 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,bit_expression);}
#line 2773 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 572 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2779 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 574 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2785 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 576 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2791 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 578 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2797 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 580 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2803 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 582 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2809 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 584 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2815 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 586 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2821 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 588 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2827 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 590 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2833 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 592 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2839 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 607 "front/java.y" /* yacc.c:1646  */
    { pNode ls[4]={(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(4,casting_expression);}
#line 2845 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 612 "front/java.y" /* yacc.c:1646  */
    { pNode ls[4]={(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(4,creating_expression);}
#line 2851 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 614 "front/java.y" /* yacc.c:1646  */
    { pNode ls[5]={(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(5,creating_expression);}
#line 2857 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 616 "front/java.y" /* yacc.c:1646  */
    { pNode ls[6]={(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(6,creating_expression);}
#line 2863 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 618 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,creating_expression);}
#line 2869 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 623 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,arglist);}
#line 2875 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 625 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,arglist);}
#line 2881 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 630 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,literal_expression);}
#line 2887 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 632 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,literal_expression);}
#line 2893 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 634 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,literal_expression);}
#line 2899 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 636 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,literal_expression);}
#line 2905 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 641 "front/java.y" /* yacc.c:1646  */
    { pNode ls[6]={(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(6,if_statement);}
#line 2911 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 643 "front/java.y" /* yacc.c:1646  */
    { pNode ls[8]={(yyvsp[-7].pnode),(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(8,if_statement);}
#line 2917 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 648 "front/java.y" /* yacc.c:1646  */
    { pNode ls[7]={(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(7,elseifs);}
#line 2923 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 650 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,elseifs);}
#line 2929 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 655 "front/java.y" /* yacc.c:1646  */
    { pNode ls[7]={(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(7,do_statement);}
#line 2935 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 660 "front/java.y" /* yacc.c:1646  */
    { pNode ls[5]={(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(5,while_statement);}
#line 2941 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 665 "front/java.y" /* yacc.c:1646  */
    { pNode ls[9]={(yyvsp[-8].pnode),(yyvsp[-7].pnode),(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(9,for_statement);}
#line 2947 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 667 "front/java.y" /* yacc.c:1646  */
    { pNode ls[8]={(yyvsp[-7].pnode),(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(8,for_statement);}
#line 2953 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 671 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression01);}
#line 2959 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 673 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,expression01);}
#line 2965 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 678 "front/java.y" /* yacc.c:1646  */
    { pNode ls[5]={(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(5,try_statement);}
#line 2971 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 680 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,try_statement);}
#line 2977 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 685 "front/java.y" /* yacc.c:1646  */
    { pNode ls[6]={(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(6,catchs);}
#line 2983 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 687 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,catchs);}
#line 2989 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 692 "front/java.y" /* yacc.c:1646  */
    { pNode ls[7]={(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(7,switch_statement);}
#line 2995 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 696 "front/java.y" /* yacc.c:1646  */
    { pNode ls[4]={(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(4,cases);}
#line 3001 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 698 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,cases);}
#line 3007 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 700 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,cases);}
#line 3013 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 702 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,cases);}
#line 3019 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 707 "front/java.y" /* yacc.c:1646  */
    { pNode ls[6]={(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(6,constructor_declaration);}
#line 3025 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 709 "front/java.y" /* yacc.c:1646  */
    { pNode ls[5]={(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(5,constructor_declaration);}
#line 3031 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 714 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,static_initializer);}
#line 3037 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 719 "front/java.y" /* yacc.c:1646  */
    { pNode ls[8]={(yyvsp[-7].pnode),(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(8,interface_declaration);}
#line 3043 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 721 "front/java.y" /* yacc.c:1646  */
    { pNode ls[6]={(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(6,interface_declaration);}
#line 3049 "front/java.tab.c" /* yacc.c:1646  */
    break;


#line 3053 "front/java.tab.c" /* yacc.c:1646  */
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
#line 729 "front/java.y" /* yacc.c:1906  */


int yyerror(char *s) {
	printf("Gramma analysis error %s  on %d :%s\n",s,line,yytext);
    return 0;
}
























