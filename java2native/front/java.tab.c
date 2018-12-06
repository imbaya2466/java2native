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
	#include "AST.h"
	#include "main.h"
	// 语法树构造用宏  #为字符串化
	#define MNNA(i,x) MakeNodeNoAtt(i,ls,x,#x)
	
	// extern是指定义(分配空间)在其它地方，函数声明与定义是分开的通过声明使用因此都不用加extren，变量为声明并定义因此要加。
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
	
	

#line 96 "front/java.tab.c" /* yacc.c:339  */

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
    _CUSTFLOAT = 359,
    UMINUS = 360
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "front/java.y" /* yacc.c:355  */

	pNode pnode;

#line 246 "front/java.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_FRONT_JAVA_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 263 "front/java.tab.c" /* yacc.c:358  */

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
#define YYLAST   1799

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  106
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  181
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  350

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   360

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
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   190,   190,   192,   197,   200,   204,   207,   211,   217,
     219,   224,   226,   236,   238,   243,   245,   247,   252,   255,
     258,   260,   262,   264,   266,   268,   270,   272,   274,   279,
     281,   286,   289,   293,   295,   297,   299,   301,   307,   309,
     311,   313,   318,   323,   326,   330,   332,   334,   336,   338,
     340,   342,   344,   346,   348,   350,   355,   357,   363,   368,
     372,   375,   380,   382,   384,   386,   388,   390,   392,   394,
     396,   398,   400,   402,   404,   406,   408,   410,   412,   414,
     416,   421,   426,   428,   433,   435,   440,   442,   444,   446,
     451,   453,   460,   462,   464,   468,   472,   474,   476,   478,
     480,   482,   484,   486,   488,   490,   492,   494,   496,   498,
     503,   505,   507,   509,   511,   513,   515,   517,   519,   521,
     523,   525,   527,   529,   531,   533,   539,   541,   543,   545,
     547,   549,   555,   557,   559,   561,   563,   569,   571,   573,
     575,   577,   579,   581,   583,   585,   587,   589,   591,   613,
     615,   617,   621,   624,   628,   630,   635,   637,   639,   641,
     646,   648,   653,   658,   663,   665,   669,   672,   676,   678,
     683,   686,   690,   694,   696,   698,   701,   705,   707,   712,
     717,   719
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
  "_CUSTCHAR", "_CUSTSTRING", "_CUSTINT", "_CUSTFLOAT", "UMINUS",
  "$accept", "compilation_unit", "import_statements", "type_declarations",
  "package_statement", "import_statement", "class_name",
  "type_declaration", "class_declaration", "modifiers", "modifier",
  "implements", "field_declarations", "field_declaration",
  "method_declaration", "type", "brackets", "type_specifier",
  "parameter_list", "parameter", "statement_block", "statements",
  "statement", "variable_declaration", "variable_declarators",
  "variable_declarator", "variable_initializer", "variable_initializers",
  "expression", "numeric_expression", "testing_expression",
  "logical_expression", "bit_expression", "creating_expression",
  "bracketnums", "arglist", "literal_expression", "if_statement",
  "do_statement", "while_statement", "for_statement", "expression01",
  "try_statement", "catchs", "switch_statement", "cases",
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
     355,   356,   357,   358,   359,   360
};
# endif

#define YYPACT_NINF -269

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-269)))

#define YYTABLE_NINF -168

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -24,   -78,    47,    20,  -269,  -269,   -74,  -269,   -78,    68,
    -269,    20,  -269,    43,   -28,  -269,  -269,   446,  -269,    72,
    -269,  -269,   -51,  -269,  -269,  -269,  -269,  -269,  -269,  -269,
    -269,  -269,    63,    65,  -269,    74,    44,     6,  -269,   -78,
     -78,  -269,   -78,  -269,    -1,    80,   -55,    -9,   -54,    -8,
     -78,  -269,   -78,    82,  -269,  -269,   145,  -269,  -269,  -269,
    -269,  -269,  -269,  -269,   -50,    42,    80,  -269,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,    88,
      80,    94,  -269,    50,  -269,  -269,   319,   741,   102,   -11,
    -269,   105,  -269,   112,  1537,   -36,   -29,   506,   382,   107,
     108,   117,   118,   382,   696,   121,  -269,  -269,  -269,  -269,
    -269,   696,   696,   696,   696,   696,  -269,   696,  -269,   116,
    -269,  -269,  -269,  -269,   215,  -269,  -269,  -269,   840,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,
    -269,    82,   124,    48,  -269,  1490,   -58,  -269,   130,   141,
    -269,   -57,  -269,  -269,   140,  -269,   143,  -269,  -269,   887,
     216,   696,   696,   561,   696,  -269,   934,   696,   202,   202,
     202,   202,   202,   981,   382,   130,   -78,   696,   696,   696,
     696,   696,  -269,  -269,   696,   696,   696,   696,   696,   696,
     696,   696,   696,   696,   696,   696,   696,   696,   696,   696,
     696,   696,   696,   696,   696,   696,   696,   696,   696,   696,
     573,  -269,   696,   696,   696,  -269,  -269,    82,  1537,   -37,
      58,   628,  -269,  -269,  -269,   641,   148,  -269,  -269,  -269,
     150,  1028,  1075,   696,  1357,   146,  1122,   163,  -269,  1169,
    -269,  -269,    80,   115,   115,   202,   202,   202,  1679,  1679,
    1701,  1701,  1701,  1701,  1635,  1545,  1590,   370,   370,   370,
    1498,  1451,  1404,  1404,  1404,  1404,  1404,  1404,  1404,  1404,
    1404,  1404,  1404,  1216,  -269,  1357,    62,  1404,   -15,   746,
     105,  -269,  -269,  -269,  -269,   -32,   437,  -269,  1357,  -269,
      66,   696,   696,   382,   382,   149,   696,   161,   171,   382,
      82,  -269,  -269,   696,   696,  -269,  -269,  -269,  -269,   -52,
    -269,  1263,  1310,  -269,   243,   696,   173,  -269,  1537,  -269,
    -269,  1404,  1357,  -269,   492,  -269,   174,   382,   172,   696,
     256,   176,  -269,  -269,  -269,  -269,   382,   177,   696,   179,
    -269,  -269,   382,  -269,   382,   793,  -269,  -269,  -269,  -269
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     7,     5,    11,     0,     1,     0,    19,
       4,     7,     8,     0,     0,     6,    13,     0,    14,    19,
      12,    10,     0,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,    18,     0,     0,     0,     9,     0,
       0,    32,     0,    32,     0,    30,     0,    19,     0,    19,
       0,    32,     0,     0,    17,    37,     0,    31,    33,    35,
      34,    36,    32,   181,     0,    19,    29,    61,   179,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    11,
      55,     0,    44,    19,    32,    16,    19,     0,    44,     0,
      82,    42,   180,    19,     0,     0,     0,     0,    19,     0,
       0,     0,     0,    19,     0,     0,   135,   136,    98,    99,
     100,     0,     0,     0,     0,     0,    59,     0,    80,   101,
     156,   157,   158,   159,     0,    64,    60,    62,     0,    92,
      93,    94,    95,    96,    97,    65,    66,    67,    68,    69,
      70,     0,     0,     0,    56,     0,    85,    81,     0,     0,
      15,    55,   153,    77,     0,    78,     0,    73,   101,     0,
       0,     0,     0,    19,     0,   171,     0,     0,   110,   111,
     112,   137,   132,     0,    19,     0,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,     0,     0,     0,   178,    44,     0,     0,     0,
       0,     0,    44,    83,    43,     0,   151,    76,    79,    72,
       0,     0,     0,   167,   166,     0,     0,   169,    74,     0,
     102,    75,   108,   115,   116,   117,   118,   119,   126,   127,
     128,   129,   130,   131,   138,   139,   140,   141,   142,   143,
     133,   134,   125,   120,   121,   122,   123,   124,   144,   145,
     146,   147,   148,     0,   104,   154,     0,   107,   106,     0,
      58,   177,    57,    41,    39,     0,     0,    84,    86,   149,
       0,     0,     0,    19,    19,     0,   167,     0,     0,    19,
       0,   105,   103,     0,     0,    40,    38,    87,    90,     0,
     150,     0,     0,   163,   160,   167,     0,   176,     0,   168,
      71,   155,   109,    89,     0,   152,     0,    19,     0,   167,
      19,     0,    88,    91,   162,   161,    19,     0,     0,     0,
     172,   175,    19,   165,    19,     0,   174,   170,   164,   173
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -269,  -269,   276,   274,  -269,  -269,   128,  -269,  -269,    -4,
    -269,   -31,   -14,  -269,  -269,    17,   -81,   192,   144,  -187,
     -53,  -269,   -96,   -33,  -269,   153,  -268,  -269,   -87,  -269,
    -269,  -269,  -269,  -269,  -269,    67,  -269,  -269,  -269,  -269,
    -269,  -168,  -269,  -269,  -269,  -269,  -269,  -269,  -269
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,     4,    10,    80,    15,    16,   124,
      34,    46,    47,    57,    58,   142,   146,    82,   143,   144,
     125,    86,   126,   127,    89,    90,   287,   309,   128,   129,
     130,   131,   132,   133,   226,   276,   134,   135,   136,   137,
     138,   235,   139,   237,   140,   330,    60,    61,    18
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    91,   160,    53,    53,    17,    35,   165,    50,   176,
     159,    48,     1,    42,    59,    17,    59,   166,   308,    64,
     221,    12,     5,    13,   168,   169,   170,   171,   172,    49,
     173,   282,    59,   149,    51,    62,   225,    65,   323,    84,
      13,    52,    52,    56,   324,    56,    52,     7,    83,    20,
      59,    39,    67,    40,    53,     8,   333,    67,   283,   153,
      59,    56,    53,   305,   154,   295,   155,    21,    -3,    22,
      93,   156,    -2,    81,   231,   232,   234,   236,   241,    56,
     239,    54,    63,   214,   147,   148,    55,    55,   215,    56,
     243,   244,   245,   246,   247,    43,    13,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   275,    53,   277,   278,   279,   316,     6,
     233,   331,    85,    41,   288,   280,    14,    55,   275,   176,
      92,   175,   217,    20,   218,    55,   234,   328,    23,    24,
      25,    26,   285,    27,   218,    28,   302,    29,   303,    30,
     310,   337,   303,    36,   281,    37,   284,    44,    45,    38,
      45,    67,   179,   180,   181,   182,   183,    13,    45,    31,
      66,    87,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,   298,   299,    88,   145,   149,   313,   314,   288,
     161,   162,   150,   319,   311,   312,   209,    55,   210,   234,
     163,   164,   213,   214,   167,   174,   321,   322,    23,    24,
      25,    26,   151,    27,   216,    28,   176,    29,   234,    30,
     222,   335,   306,   224,   341,   227,   230,   288,   228,   291,
     343,   296,   234,   292,   315,    79,   347,   320,   348,    31,
     317,   345,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,   182,   183,   318,   327,   336,    94,   329,   334,
     342,   344,    95,    96,    97,    98,    99,   100,   346,   101,
      11,   102,   338,   339,   103,    19,   152,   104,     0,   220,
     105,     0,   290,   209,     0,   210,     0,     0,     0,   213,
     214,   223,     0,     0,   242,     0,   106,   107,   108,   109,
     110,     0,   111,     0,     0,     5,   112,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,     0,     0,
      94,     0,     0,   115,     0,    95,    96,    97,    98,    99,
     100,     0,   101,     0,   102,    67,   340,   103,     0,   117,
     104,   118,     0,   105,     0,     0,   119,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,     0,   111,     0,     0,     0,   112,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,     0,     0,    94,   176,     0,   115,     0,    95,    96,
      97,    98,    99,   100,     0,   101,     0,   102,    67,   116,
     103,     0,   117,   104,   118,     0,   105,     0,     0,   119,
     120,   121,   122,   123,     0,   177,   178,   179,   180,   181,
     182,   183,   106,   107,   108,   109,   110,     0,   111,     0,
       0,     0,   112,   113,     0,     0,     0,     0,    94,    23,
      24,    25,    26,   114,    27,     0,    28,     0,    29,   115,
      30,   209,     0,   210,     0,     0,     0,   213,   214,     0,
       0,    67,     0,     0,     0,   117,     0,   118,     0,     0,
      31,     0,   119,   120,   121,   122,   123,   106,   107,   108,
     109,   110,     0,   111,    32,    33,     0,   112,   113,     0,
       0,     0,     0,    94,     0,     0,     0,     0,   114,     0,
       0,     0,     0,     0,   115,     0,     0,    94,     0,     0,
       0,     0,     0,     0,     0,     0,   286,   307,     0,     0,
     117,     0,     0,     0,     0,     0,     0,   158,   120,   121,
     122,   123,   106,   107,   108,   109,   110,     0,   111,     0,
       0,     0,   112,   113,     0,     0,   106,   107,   108,   109,
     110,     0,   111,   114,     0,     0,   112,   113,     0,   115,
       0,     0,    94,     0,     0,     0,     0,   114,     0,     0,
       0,   286,   332,   115,    94,   117,     0,     0,     0,     0,
       0,     0,   158,   120,   121,   122,   123,     0,     0,   117,
       0,   157,     0,     0,     0,     0,   158,   120,   121,   122,
     123,   106,   107,   108,   109,   110,     0,   111,     0,     0,
       0,   112,   113,   106,   107,   108,   109,   110,     0,   111,
       0,     0,   114,   112,   113,     0,     0,     0,   115,    94,
       0,     0,     0,     0,   114,     0,     0,     0,     0,     0,
     115,     0,    94,     0,   117,     0,  -167,     0,     0,     0,
       0,   158,   120,   121,   122,   123,   117,   274,     0,     0,
       0,     0,     0,   158,   120,   121,   122,   123,   106,   107,
     108,   109,   110,     0,   111,     0,     0,     0,   112,   113,
       0,   106,   107,   108,   109,   110,     0,   111,     0,   114,
       0,   112,   113,     0,     0,   115,     0,    94,     0,     0,
       0,     0,   114,     0,     0,     0,     0,   286,   115,     0,
       0,   117,     0,     0,     0,     0,     0,     0,   158,   120,
     121,   122,   123,     0,   117,   289,     0,     0,     0,     0,
       0,   158,   120,   121,   122,   123,   106,   107,   108,   109,
     110,     0,   111,     0,     0,     0,   112,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,     0,     0,
     176,     0,     0,   115,     0,     0,     0,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,     0,   117,
       0,     0,     0,     0,     0,     0,   158,   120,   121,   122,
     123,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   176,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   141,     0,   209,     0,   210,
       0,     5,   212,   213,   214,   304,     0,     0,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   176,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,     0,     0,   209,     0,   210,     0,     0,   212,
     213,   214,   349,     0,     0,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   176,   193,   194,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,     0,
       0,   209,     0,   210,     0,   211,   212,   213,   214,     0,
       0,     0,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   176,   193,
     194,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,     0,     0,   209,     0,
     210,     0,   229,   212,   213,   214,     0,     0,     0,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   176,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,     0,     0,   209,     0,   210,     0,   238,
     212,   213,   214,     0,     0,     0,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   176,   193,   194,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       0,     0,   209,     0,   210,   240,     0,   212,   213,   214,
       0,     0,     0,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   176,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,     0,     0,   209,
       0,   210,   293,     0,   212,   213,   214,     0,     0,     0,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   176,   193,   194,   195,
     196,   197,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,     0,   209,     0,   210,   294,
       0,   212,   213,   214,     0,     0,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   176,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,     0,     0,   209,     0,   210,   297,     0,   212,   213,
     214,     0,     0,     0,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     176,   193,   194,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,     0,     0,
     209,     0,   210,   300,     0,   212,   213,   214,     0,     0,
       0,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   176,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,     0,     0,   209,   301,   210,
       0,     0,   212,   213,   214,     0,     0,     0,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   176,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,     0,     0,   209,   325,   210,     0,     0,   212,
     213,   214,     0,     0,     0,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   176,   193,   194,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,     0,
       0,   209,     0,   210,   326,     0,   212,   213,   214,     0,
       0,     0,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   176,   193,
     194,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,     0,     0,   209,     0,
     210,     0,     0,   212,   213,   214,     0,     0,     0,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   176,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,     0,     0,   209,     0,   210,     0,     0,
       0,   213,   214,     0,     0,     0,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   176,   193,   194,   195,   196,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,     0,     0,
       0,     0,   209,     0,   210,     0,     0,     0,   213,   214,
       0,     0,     0,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   176,
     193,   194,   195,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,   219,     0,     0,     0,     0,   209,
       5,   210,     0,     0,     0,   213,   214,     0,     0,     0,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   176,   192,     0,   193,   194,   195,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   209,     5,   210,     0,
       0,     0,   213,   214,     0,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   176,
       0,     0,   193,   194,   195,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   209,     0,   210,     0,     0,     0,   213,   214,     0,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   176,     0,     0,     0,   193,   194,   195,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   176,   209,     0,   210,     0,
       0,     0,   213,   214,   177,   178,   179,   180,   181,   182,
     183,     0,     0,   186,   187,   188,   189,     0,     0,     0,
       0,   193,   194,   195,     0,     0,   177,   178,   179,   180,
     181,   182,   183,     0,     0,     0,     0,     0,     0,     0,
     209,     0,   210,   193,   194,   195,   213,   214,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   209,     0,   210,     0,     0,     0,   213,   214
};

static const yytype_int16 yycheck[] =
{
      53,    82,    98,    12,    12,     9,    57,   103,     9,    24,
      97,    42,    36,     7,    47,    19,    49,   104,   286,    50,
      78,    95,   100,    97,   111,   112,   113,   114,   115,    43,
     117,   218,    65,    91,    89,    89,    93,    51,    90,    89,
      97,    96,    96,    47,    96,    49,    96,     0,    62,   100,
      83,     7,    89,     9,    12,    35,   324,    89,    95,    95,
      93,    65,    12,    95,   100,   233,    95,    95,     0,    97,
      84,   100,     0,    56,   161,   162,   163,   164,   174,    83,
     167,    90,    90,    98,    95,    96,    95,    95,   141,    93,
     177,   178,   179,   180,   181,    89,    97,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    12,   212,   213,   214,   296,     1,
     163,   318,    90,    89,   221,   216,     8,    95,   225,    24,
      90,   124,    94,   100,    96,    95,   233,   315,     3,     4,
       5,     6,    94,     8,    96,    10,    94,    12,    96,    14,
      94,   329,    96,   100,   217,   100,   219,    39,    40,    95,
      42,    89,    57,    58,    59,    60,    61,    97,    50,    34,
      52,    93,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    29,    30,   100,    93,    91,   293,   294,   286,
      93,    93,    90,   299,   291,   292,    91,    95,    93,   296,
      93,    93,    97,    98,    93,    99,   303,   304,     3,     4,
       5,     6,    94,     8,   100,    10,    24,    12,   315,    14,
     100,   327,   285,    92,   330,    95,    20,   324,    95,    91,
     336,    95,   329,    93,    95,   100,   342,   300,   344,    34,
      89,   338,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    60,    61,    93,    22,    94,    11,    95,    95,
      94,    94,    16,    17,    18,    19,    20,    21,    99,    23,
       4,    25,    26,    27,    28,    11,    94,    31,    -1,   145,
      34,    -1,   225,    91,    -1,    93,    -1,    -1,    -1,    97,
      98,   148,    -1,    -1,   176,    -1,    50,    51,    52,    53,
      54,    -1,    56,    -1,    -1,   100,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      11,    -1,    -1,    77,    -1,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    25,    89,    90,    28,    -1,    93,
      31,    95,    -1,    34,    -1,    -1,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    -1,    56,    -1,    -1,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    11,    24,    -1,    77,    -1,    16,    17,
      18,    19,    20,    21,    -1,    23,    -1,    25,    89,    90,
      28,    -1,    93,    31,    95,    -1,    34,    -1,    -1,   100,
     101,   102,   103,   104,    -1,    55,    56,    57,    58,    59,
      60,    61,    50,    51,    52,    53,    54,    -1,    56,    -1,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    11,     3,
       4,     5,     6,    71,     8,    -1,    10,    -1,    12,    77,
      14,    91,    -1,    93,    -1,    -1,    -1,    97,    98,    -1,
      -1,    89,    -1,    -1,    -1,    93,    -1,    95,    -1,    -1,
      34,    -1,   100,   101,   102,   103,   104,    50,    51,    52,
      53,    54,    -1,    56,    48,    49,    -1,    60,    61,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,
     103,   104,    50,    51,    52,    53,    54,    -1,    56,    -1,
      -1,    -1,    60,    61,    -1,    -1,    50,    51,    52,    53,
      54,    -1,    56,    71,    -1,    -1,    60,    61,    -1,    77,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      -1,    89,    90,    77,    11,    93,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   101,   102,   103,   104,    -1,    -1,    93,
      -1,    95,    -1,    -1,    -1,    -1,   100,   101,   102,   103,
     104,    50,    51,    52,    53,    54,    -1,    56,    -1,    -1,
      -1,    60,    61,    50,    51,    52,    53,    54,    -1,    56,
      -1,    -1,    71,    60,    61,    -1,    -1,    -1,    77,    11,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    11,    -1,    93,    -1,    95,    -1,    -1,    -1,
      -1,   100,   101,   102,   103,   104,    93,    94,    -1,    -1,
      -1,    -1,    -1,   100,   101,   102,   103,   104,    50,    51,
      52,    53,    54,    -1,    56,    -1,    -1,    -1,    60,    61,
      -1,    50,    51,    52,    53,    54,    -1,    56,    -1,    71,
      -1,    60,    61,    -1,    -1,    77,    -1,    11,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    89,    77,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
     102,   103,   104,    -1,    93,    94,    -1,    -1,    -1,    -1,
      -1,   100,   101,   102,   103,   104,    50,    51,    52,    53,
      54,    -1,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      24,    -1,    -1,    77,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,   103,
     104,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    24,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    94,    -1,    91,    -1,    93,
      -1,   100,    96,    97,    98,    99,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    24,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    91,    -1,    93,    -1,    -1,    96,
      97,    98,    99,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    24,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    93,    -1,    95,    96,    97,    98,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    24,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    -1,    91,    -1,
      93,    -1,    95,    96,    97,    98,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    24,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    -1,    91,    -1,    93,    -1,    95,
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
      88,    -1,    -1,    91,    -1,    93,    94,    -1,    96,    97,
      98,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      24,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    -1,
      91,    -1,    93,    94,    -1,    96,    97,    98,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    24,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    91,    92,    93,
      -1,    -1,    96,    97,    98,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    24,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    91,    92,    93,    -1,    -1,    96,
      97,    98,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    24,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    93,    94,    -1,    96,    97,    98,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    24,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    -1,    91,    -1,
      93,    -1,    -1,    96,    97,    98,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    24,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    -1,    91,    -1,    93,    -1,    -1,
      -1,    97,    98,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    24,    72,    73,    74,    75,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    93,    -1,    -1,    -1,    97,    98,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    24,
      72,    73,    74,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    94,    -1,    -1,    -1,    -1,    91,
     100,    93,    -1,    -1,    -1,    97,    98,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    24,    70,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,   100,    93,    -1,
      -1,    -1,    97,    98,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    24,
      -1,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    93,    -1,    -1,    -1,    97,    98,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    24,    -1,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    91,    -1,    93,    -1,
      -1,    -1,    97,    98,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    64,    65,    66,    67,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    93,    72,    73,    74,    97,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    93,    -1,    -1,    -1,    97,    98
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,   107,   108,   110,   100,   112,     0,    35,   109,
     111,   108,    95,    97,   112,   113,   114,   115,   154,   109,
     100,    95,    97,     3,     4,     5,     6,     8,    10,    12,
      14,    34,    48,    49,   116,    57,   100,   100,    95,     7,
       9,    89,     7,    89,   112,   112,   117,   118,   117,   118,
       9,    89,    96,    12,    90,    95,   115,   119,   120,   129,
     152,   153,    89,    90,   117,   118,   112,    89,   126,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   100,
     112,   121,   123,   118,    89,    90,   127,    93,   100,   130,
     131,   122,    90,   118,    11,    16,    17,    18,    19,    20,
      21,    23,    25,    28,    31,    34,    50,    51,    52,    53,
      54,    56,    60,    61,    71,    77,    90,    93,    95,   100,
     101,   102,   103,   104,   115,   126,   128,   129,   134,   135,
     136,   137,   138,   139,   142,   143,   144,   145,   146,   148,
     150,    94,   121,   124,   125,    93,   122,    95,    96,    91,
      90,   112,   123,    95,   100,    95,   100,    95,   100,   134,
     128,    93,    93,    93,    93,   128,   134,    93,   134,   134,
     134,   134,   134,   134,    99,   121,    24,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    72,    73,    74,    75,    76,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    91,
      93,    95,    96,    97,    98,   126,   100,    94,    96,    94,
     124,    78,   100,   131,    92,    93,   140,    95,    95,    95,
      20,   134,   134,   129,   134,   147,   134,   149,    95,   134,
      94,   128,   112,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,    94,   134,   141,   134,   134,   134,
     122,   126,   125,    95,   126,    94,    89,   132,   134,    94,
     141,    91,    93,    94,    94,   147,    95,    94,    29,    30,
      94,    92,    94,    96,    99,    95,   126,    90,   132,   133,
      94,   134,   134,   128,   128,    95,   147,    89,    93,   128,
     126,   134,   134,    90,    96,    92,    94,    22,   147,    95,
     151,   125,    90,   132,    95,   128,    94,   147,    26,    27,
      90,   128,    94,   128,    94,   134,    99,   128,   128,    99
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   106,   107,   107,   108,   108,   109,   109,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   114,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   117,
     117,   118,   118,   119,   119,   119,   119,   119,   120,   120,
     120,   120,   121,   122,   122,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   124,   124,   125,   126,
     127,   127,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   129,   130,   130,   131,   131,   132,   132,   132,   132,
     133,   133,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   136,   136,   136,   136,
     136,   136,   137,   137,   137,   137,   137,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   139,
     139,   139,   140,   140,   141,   141,   142,   142,   142,   142,
     143,   143,   144,   145,   146,   146,   147,   147,   148,   148,
     149,   149,   150,   151,   151,   151,   151,   152,   152,   153,
     154,   154
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     2,     0,     2,     0,     3,     5,
       3,     1,     3,     1,     1,    10,     8,     6,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     0,     1,     1,     1,     1,     1,     7,     6,
       7,     6,     2,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       2,     0,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     5,     3,     2,     3,     3,     3,     2,     2,     3,
       1,     4,     1,     3,     4,     2,     1,     2,     4,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     3,     4,     3,     3,     3,     5,
       2,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     1,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       5,     3,     4,     0,     1,     3,     1,     1,     1,     1,
       5,     7,     7,     5,     9,     8,     1,     0,     5,     3,
       6,     0,     7,     4,     3,     2,     0,     6,     5,     2,
       8,     6
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
#line 191 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  root=MNNA(3,compilation_unit);}
#line 1899 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 193 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  root=MNNA(2,compilation_unit);}
#line 1905 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 198 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,import_statements);}
#line 1911 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 200 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,import_statements);}
#line 1917 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 205 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,type_declarations);}
#line 1923 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 207 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,type_declarations);}
#line 1929 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 212 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,package_statement);}
#line 1935 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 218 "front/java.y" /* yacc.c:1646  */
    { pNode ls[5]={(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(5,import_statement);}
#line 1941 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 220 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,import_statement);}
#line 1947 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 225 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]={(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,class_name);}
#line 1953 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 227 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,class_name);}
#line 1959 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 237 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]={(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_declaration);}
#line 1965 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 239 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]={(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_declaration);}
#line 1971 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 244 "front/java.y" /* yacc.c:1646  */
    { pNode ls[10]={(yyvsp[-9].pnode),(yyvsp[-8].pnode),(yyvsp[-7].pnode),(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(10,class_declaration);}
#line 1977 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 246 "front/java.y" /* yacc.c:1646  */
    { pNode ls[8]={(yyvsp[-7].pnode),(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(8,class_declaration);}
#line 1983 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 248 "front/java.y" /* yacc.c:1646  */
    { pNode ls[6]={(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(6,class_declaration);}
#line 1989 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 253 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,modifiers);}
#line 1995 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 255 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,modifiers);}
#line 2001 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 259 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2007 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 261 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2013 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 263 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2019 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 265 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2025 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 267 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2031 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 269 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2037 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 271 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2043 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 273 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2049 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 275 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,modifier);}
#line 2055 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 280 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,implements);}
#line 2061 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 282 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]= {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,implements);}
#line 2067 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 287 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,field_declarations);}
#line 2073 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 289 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,field_declarations);}
#line 2079 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 294 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,field_declaration);}
#line 2085 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 296 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,field_declaration);}
#line 2091 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 298 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,field_declaration);}
#line 2097 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 300 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,field_declaration);}
#line 2103 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 302 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,field_declaration);}
#line 2109 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 308 "front/java.y" /* yacc.c:1646  */
    { pNode ls[7]={(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(7,method_declaration);}
#line 2115 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 310 "front/java.y" /* yacc.c:1646  */
    { pNode ls[6]={(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(6,method_declaration);}
#line 2121 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 312 "front/java.y" /* yacc.c:1646  */
    { pNode ls[7]={(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(7,method_declaration);}
#line 2127 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 314 "front/java.y" /* yacc.c:1646  */
    { pNode ls[6]={(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(6,method_declaration);}
#line 2133 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 319 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,type);}
#line 2139 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 324 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,brackets);}
#line 2145 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 326 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,brackets);}
#line 2151 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 331 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2157 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 333 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2163 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 335 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2169 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 337 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2175 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 339 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2181 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 341 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2187 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 343 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2193 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 345 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2199 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 347 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2205 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 349 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2211 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 351 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,type_specifier);}
#line 2217 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 356 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,parameter_list);}
#line 2223 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 358 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,parameter_list);}
#line 2229 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 364 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,parameter);}
#line 2235 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 369 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,statement_block);}
#line 2241 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 373 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,statements);}
#line 2247 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 375 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,statements);}
#line 2253 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 381 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2259 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 383 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,statement);}
#line 2265 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 385 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2271 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 387 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2277 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 389 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2283 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 391 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2289 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 393 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2295 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 395 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2301 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 397 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2307 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 399 "front/java.y" /* yacc.c:1646  */
    { pNode ls[5]={(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(5,statement);}
#line 2313 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 401 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,statement);}
#line 2319 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 403 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,statement);}
#line 2325 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 405 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,statement);}
#line 2331 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 407 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,statement);}
#line 2337 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 409 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,statement);}
#line 2343 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 411 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,statement);}
#line 2349 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 413 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,statement);}
#line 2355 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 415 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,statement);}
#line 2361 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 417 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,statement);}
#line 2367 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 422 "front/java.y" /* yacc.c:1646  */
    { pNode ls[4]={(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(4,variable_declaration);}
#line 2373 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 427 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,variable_declarators);}
#line 2379 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 429 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,variable_declarators);}
#line 2385 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 434 "front/java.y" /* yacc.c:1646  */
    { pNode ls[4]={(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(4,variable_declarator);}
#line 2391 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 436 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,variable_declarator);}
#line 2397 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 441 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,variable_initializer);}
#line 2403 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 443 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,variable_initializer);}
#line 2409 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 445 "front/java.y" /* yacc.c:1646  */
    { pNode ls[4]={(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(4,variable_initializer);}
#line 2415 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 447 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,variable_initializer);}
#line 2421 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 452 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,variable_initializers);}
#line 2427 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 454 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,variable_initializers);}
#line 2433 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 461 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2439 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 463 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2445 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 465 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2451 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 469 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2457 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 473 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2463 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 475 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2469 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 477 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2475 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 479 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2481 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 481 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2487 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 483 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression);}
#line 2493 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 485 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,expression);}
#line 2499 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 487 "front/java.y" /* yacc.c:1646  */
    { pNode ls[4]={(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(4,expression);}
#line 2505 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 489 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,expression);}
#line 2511 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 491 "front/java.y" /* yacc.c:1646  */
    { pNode ls[4]={(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(4,expression);}
#line 2517 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 493 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,expression);}
#line 2523 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 495 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,expression);}
#line 2529 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 497 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,expression);}
#line 2535 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 499 "front/java.y" /* yacc.c:1646  */
    { pNode ls[5]={(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(5,expression);}
#line 2541 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 504 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,numeric_expression);}
#line 2547 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 506 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,numeric_expression);}
#line 2553 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 508 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,numeric_expression);}
#line 2559 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 510 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,numeric_expression);}
#line 2565 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 512 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,numeric_expression);}
#line 2571 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 514 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2577 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 516 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2583 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 518 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2589 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 520 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2595 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 522 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2601 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 524 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2607 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 526 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2613 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 528 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2619 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 530 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2625 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 532 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2631 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 534 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,numeric_expression);}
#line 2637 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 540 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,testing_expression);}
#line 2643 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 542 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,testing_expression);}
#line 2649 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 544 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,testing_expression);}
#line 2655 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 546 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,testing_expression);}
#line 2661 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 548 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,testing_expression);}
#line 2667 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 550 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,testing_expression);}
#line 2673 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 556 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,logical_expression);}
#line 2679 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 558 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,logical_expression);}
#line 2685 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 560 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,logical_expression);}
#line 2691 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 562 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,logical_expression);}
#line 2697 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 564 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,logical_expression);}
#line 2703 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 570 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,bit_expression);}
#line 2709 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 572 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2715 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 574 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2721 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 576 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2727 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 578 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2733 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 580 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2739 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 582 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2745 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 584 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2751 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 586 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2757 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 588 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2763 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 590 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2769 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 592 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,bit_expression);}
#line 2775 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 614 "front/java.y" /* yacc.c:1646  */
    { pNode ls[4]={(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(4,creating_expression);}
#line 2781 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 616 "front/java.y" /* yacc.c:1646  */
    { pNode ls[5]={(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(5,creating_expression);}
#line 2787 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 618 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,creating_expression);}
#line 2793 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 622 "front/java.y" /* yacc.c:1646  */
    { pNode ls[4]={(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(4,bracketnums);}
#line 2799 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 624 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,bracketnums);}
#line 2805 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 629 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,arglist);}
#line 2811 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 631 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,arglist);}
#line 2817 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 636 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,literal_expression);}
#line 2823 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 638 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,literal_expression);}
#line 2829 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 640 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,literal_expression);}
#line 2835 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 642 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,literal_expression);}
#line 2841 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 647 "front/java.y" /* yacc.c:1646  */
    { pNode ls[5]={(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(5,if_statement);}
#line 2847 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 649 "front/java.y" /* yacc.c:1646  */
    { pNode ls[7]={(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(7,if_statement);}
#line 2853 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 654 "front/java.y" /* yacc.c:1646  */
    { pNode ls[7]={(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(7,do_statement);}
#line 2859 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 659 "front/java.y" /* yacc.c:1646  */
    { pNode ls[5]={(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(5,while_statement);}
#line 2865 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 664 "front/java.y" /* yacc.c:1646  */
    { pNode ls[9]={(yyvsp[-8].pnode),(yyvsp[-7].pnode),(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(9,for_statement);}
#line 2871 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 666 "front/java.y" /* yacc.c:1646  */
    { pNode ls[8]={(yyvsp[-7].pnode),(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(8,for_statement);}
#line 2877 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 670 "front/java.y" /* yacc.c:1646  */
    { pNode ls[1]=  {(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(1,expression01);}
#line 2883 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 672 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,expression01);}
#line 2889 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 677 "front/java.y" /* yacc.c:1646  */
    { pNode ls[5]={(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(5,try_statement);}
#line 2895 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 679 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,try_statement);}
#line 2901 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 684 "front/java.y" /* yacc.c:1646  */
    { pNode ls[6]={(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(6,catchs);}
#line 2907 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 686 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,catchs);}
#line 2913 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 691 "front/java.y" /* yacc.c:1646  */
    { pNode ls[7]={(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(7,switch_statement);}
#line 2919 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 695 "front/java.y" /* yacc.c:1646  */
    { pNode ls[4]={(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(4,cases);}
#line 2925 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 697 "front/java.y" /* yacc.c:1646  */
    { pNode ls[3]={(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(3,cases);}
#line 2931 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 699 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,cases);}
#line 2937 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 701 "front/java.y" /* yacc.c:1646  */
    { pNode *ls=NULL;  (yyval.pnode)=MNNA(0,cases);}
#line 2943 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 706 "front/java.y" /* yacc.c:1646  */
    { pNode ls[6]={(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(6,constructor_declaration);}
#line 2949 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 708 "front/java.y" /* yacc.c:1646  */
    { pNode ls[5]={(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(5,constructor_declaration);}
#line 2955 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 713 "front/java.y" /* yacc.c:1646  */
    { pNode ls[2]={(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(2,static_initializer);}
#line 2961 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 718 "front/java.y" /* yacc.c:1646  */
    { pNode ls[8]={(yyvsp[-7].pnode),(yyvsp[-6].pnode),(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(8,interface_declaration);}
#line 2967 "front/java.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 720 "front/java.y" /* yacc.c:1646  */
    { pNode ls[6]={(yyvsp[-5].pnode),(yyvsp[-4].pnode),(yyvsp[-3].pnode),(yyvsp[-2].pnode),(yyvsp[-1].pnode),(yyvsp[0].pnode)};  (yyval.pnode)=MNNA(6,interface_declaration);}
#line 2973 "front/java.tab.c" /* yacc.c:1646  */
    break;


#line 2977 "front/java.tab.c" /* yacc.c:1646  */
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
#line 728 "front/java.y" /* yacc.c:1906  */


int yyerror(char *s) {
	printf("Gramma analysis error %s  on %d :%s\n",s,line,yytext);
    return 0;
}
























