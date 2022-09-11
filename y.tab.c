/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    WORD = 258,
    NOTOKEN = 259,
    LPARENT = 260,
    RPARENT = 261,
    LBRACE = 262,
    RBRACE = 263,
    LCURLY = 264,
    RCURLY = 265,
    COMA = 266,
    SEMICOLON = 267,
    EQUAL = 268,
    STRING_CONST = 269,
    LONG = 270,
    LONGSTAR = 271,
    VOID = 272,
    CHARSTAR = 273,
    CHARSTARSTAR = 274,
    INTEGER_CONST = 275,
    AMPERSAND = 276,
    OROR = 277,
    ANDAND = 278,
    EQUALEQUAL = 279,
    NOTEQUAL = 280,
    LESS = 281,
    GREAT = 282,
    LESSEQUAL = 283,
    GREATEQUAL = 284,
    PLUS = 285,
    MINUS = 286,
    TIMES = 287,
    DIVIDE = 288,
    PERCENT = 289,
    IF = 290,
    ELSE = 291,
    WHILE = 292,
    DO = 293,
    FOR = 294,
    CONTINUE = 295,
    BREAK = 296,
    RETURN = 297
  };
#endif
/* Tokens.  */
#define WORD 258
#define NOTOKEN 259
#define LPARENT 260
#define RPARENT 261
#define LBRACE 262
#define RBRACE 263
#define LCURLY 264
#define RCURLY 265
#define COMA 266
#define SEMICOLON 267
#define EQUAL 268
#define STRING_CONST 269
#define LONG 270
#define LONGSTAR 271
#define VOID 272
#define CHARSTAR 273
#define CHARSTARSTAR 274
#define INTEGER_CONST 275
#define AMPERSAND 276
#define OROR 277
#define ANDAND 278
#define EQUALEQUAL 279
#define NOTEQUAL 280
#define LESS 281
#define GREAT 282
#define LESSEQUAL 283
#define GREATEQUAL 284
#define PLUS 285
#define MINUS 286
#define TIMES 287
#define DIVIDE 288
#define PERCENT 289
#define IF 290
#define ELSE 291
#define WHILE 292
#define DO 293
#define FOR 294
#define CONTINUE 295
#define BREAK 296
#define RETURN 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "simple.y"

		char *string_val;
		int nargs;
		int my_nlabel;
	

#line 211 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Second part of user prologue.  */
#line 21 "simple.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
int yyerror(const char * s);

extern int line_number;
const char * input_file;
char * asm_file;
FILE * fasm;

#define MAX_ARGS 5
int nargs;
char * args_table[MAX_ARGS];

#define MAX_LOCALS 16
int nlocals = 0;
char * local_vars_table[MAX_LOCALS];

int local_vars_type[MAX_LOCALS];


#define MAX_GLOBALS 100
int nglobals = 0;
char * global_vars_table[MAX_GLOBALS];

int global_vars_type[MAX_GLOBALS];

#define MAX_STRINGS 100
int nstrings = 0;
char * string_table[MAX_STRINGS];

char *regStk[]={ "rbx", "r10", "r13", "r14", "r15"};
char *regStkByte[] = { "bl", "r10b", "r13b", "r14b", "r15b"};
char nregStk = sizeof(regStk)/sizeof(char*);

char *regArgs[]={ "rdi", "rsi", "rdx", "rcx", "r8", "r9"};
char nregArgs = sizeof(regArgs)/sizeof(char*);

#define MAX_NESTED_LOOPS 10
int loopStack[MAX_NESTED_LOOPS];
int loopTop = 0;

int top = 0;

int nargs =0;
 
int nlabel = 0;

int currentVarType;

int jumpLabelCounter = 0; 

int ifLabelCounter = 0;

void creatLocalVar(int var_type, char *word) {  // record the created local varible and its type
	local_vars_table[nlocals]=word;
  	local_vars_type[nlocals]=var_type;

  	nlocals++;
}

int getLocalVarIndex(char *word) {	//find the index of the input local variable (which can be use to push and pop in regStk)
	 for (int i=0; i<nlocals;i++) {
		 if (strcmp(local_vars_table[i], word) == 0) {
			 return i;
		 }
	 }
	 return -1;  // ret -1 for not found
}

void creatGlobalVar(int var_type, char *word) {  // record the created global varible and its type
  	global_vars_table[nglobals]=word;
  	global_vars_type[nglobals]=var_type;

  	nglobals++;
}

int getGlobalVarIndex(char *word) {  //find the index of the input global variable (which can be use to push and pop in regStk)
	 for (int i=0; i<nglobals;i++) {
		 if (strcmp(global_vars_table[i], word) == 0) {
			 return i;
		 }
	 }
	 return -1; // ret -1 for not found
}


#line 318 "y.tab.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   141

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

#define YYUNDEFTOK  2
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   115,   115,   118,   121,   122,   123,   128,   149,   127,
     173,   174,   178,   179,   182,   189,   191,   197,   203,   204,
     205,   206,   207,   210,   225,   272,   295,   298,   305,   306,
     310,   314,   316,   324,   326,   334,   335,   352,   371,   372,
     387,   402,   417,   435,   436,   443,   453,   454,   460,   469,
     481,   497,   498,   514,   572,   588,   596,   600,   604,   605,
     609,   612,   615,   621,   622,   625,   626,   627,   654,   627,
     661,   672,   661,   686,   694,   686,   703,   709,   718,   703,
     727,   731,   732,   736,   740,   744
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WORD", "NOTOKEN", "LPARENT", "RPARENT",
  "LBRACE", "RBRACE", "LCURLY", "RCURLY", "COMA", "SEMICOLON", "EQUAL",
  "STRING_CONST", "LONG", "LONGSTAR", "VOID", "CHARSTAR", "CHARSTARSTAR",
  "INTEGER_CONST", "AMPERSAND", "OROR", "ANDAND", "EQUALEQUAL", "NOTEQUAL",
  "LESS", "GREAT", "LESSEQUAL", "GREATEQUAL", "PLUS", "MINUS", "TIMES",
  "DIVIDE", "PERCENT", "IF", "ELSE", "WHILE", "DO", "FOR", "CONTINUE",
  "BREAK", "RETURN", "$accept", "goal", "program", "function_or_var_list",
  "function", "$@1", "$@2", "arg_list", "arguments", "arg", "global_var",
  "global_var_list", "var_type", "assignment", "call", "call_arg_list",
  "call_arguments", "expression", "logical_or_expr", "logical_and_expr",
  "equality_expr", "relational_expr", "additive_expr",
  "multiplicative_expr", "primary_expr", "compound_statement",
  "statement_list", "local_var", "local_var_list", "statement", "$@3",
  "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11",
  "else_optional", "jump_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-8)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -61,     9,   -61,    36,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,    13,    24,    56,    39,    32,   -61,    36,   -61,
       1,    74,   -61,    78,    36,   -61,   -61,   -61,    73,   -61,
     -61,     8,    -3,   -61,    81,    82,   -61,    83,    71,    80,
      16,    87,    84,    85,   -61,   -61,   -61,   -61,    16,    16,
      16,    16,   -61,    98,    90,   -61,   -61,    55,    16,   -61,
     -61,    97,   -61,    91,    86,    79,    45,    30,    41,    -1,
     -61,   -61,    62,   -61,   -61,    93,   100,   -61,   101,   -61,
     104,    16,   -61,     7,    99,    16,   112,   -61,   -61,    16,
      16,    16,    16,    16,    16,    16,    16,    16,    16,    16,
      16,    16,   116,   -61,    16,   -61,   108,   -61,   117,    88,
     -61,   114,   -61,    79,    45,    30,    30,    41,    41,    41,
      41,    -1,    -1,   -61,   -61,   -61,   -61,   -61,    16,    98,
     -61,   119,    16,   -61,   -61,   -61,    98,    16,   115,    92,
     -61,   120,   -61,    98,   -61,   118,    90,   -61,   -61,   123,
     -61,    98,   -61
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     2,     3,     1,    20,    21,    22,    18,    19,
       4,     5,     0,    16,     0,     0,     0,    15,    13,    17,
      12,     0,    10,     0,     0,     8,    14,    11,     0,    59,
       9,     0,     0,    57,     0,     0,    73,     0,     0,     0,
       0,     0,     0,     0,    66,    65,    58,    80,    29,     0,
       0,     0,    70,     0,     0,    83,    84,    52,     0,    50,
      55,     0,    51,     0,    30,    31,    33,    35,    38,    43,
      46,    61,     0,    63,    64,    28,     0,    26,     0,    23,
       0,     0,    74,     0,     0,     0,     0,    54,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,     0,    25,     0,    67,     0,     0,
      76,     0,    56,    32,    34,    36,    37,    39,    40,    41,
      42,    44,    45,    47,    48,    49,    62,    27,     0,     0,
      71,     0,     0,    53,    24,    68,     0,     0,     0,    82,
      72,     0,    77,     0,    69,     0,     0,    81,    75,     0,
      78,     0,    79
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   107,
     -61,   -61,    10,   -51,   -31,   -61,   -61,   -43,   -61,    43,
      44,   -16,   -30,   -19,   -60,   113,   -61,   -61,   -61,   -52,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
     -61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     3,    10,    15,    28,    20,    21,    22,
      11,    14,    41,    42,    62,    75,    76,    63,    64,    65,
      66,    67,    68,    69,    70,    44,    31,    45,    72,    46,
     129,   139,    81,   136,    53,   109,   132,   146,   151,   144,
      47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    82,    48,    84,    49,    77,    78,    79,    80,     4,
      50,    32,    24,    12,    49,    86,    13,    29,    33,    57,
      50,    58,    43,     5,     6,     7,     8,     9,    23,    -7,
      59,    99,   100,   101,    23,    19,    60,    61,   108,   123,
     124,   125,   111,    34,    18,    35,    36,    37,    38,    39,
      40,     5,     6,     7,     8,     9,    93,    94,    95,    96,
      48,   127,    85,   117,   118,   119,   120,    16,    17,    91,
      92,    97,    98,   102,   103,   115,   116,   135,   121,   122,
      25,    26,    29,    55,   140,   134,    51,    52,    54,   138,
      71,   147,    56,    83,   141,   149,    73,    74,    43,   152,
      87,    32,    90,    88,   104,    43,   105,    29,    89,   106,
     107,   110,    43,     5,     6,     7,     8,     9,   112,   126,
      43,   128,   133,   130,   137,   131,   145,   142,   143,   150,
     148,    27,   113,    34,   114,    35,    36,    37,    38,    39,
      40,    30
};

static const yytype_uint8 yycheck[] =
{
      31,    53,     5,    54,     7,    48,    49,    50,    51,     0,
      13,     3,    11,     3,     7,    58,     3,     9,    10,     3,
      13,     5,    53,    15,    16,    17,    18,    19,    18,     5,
      14,    32,    33,    34,    24,     3,    20,    21,    81,    99,
     100,   101,    85,    35,     5,    37,    38,    39,    40,    41,
      42,    15,    16,    17,    18,    19,    26,    27,    28,    29,
       5,   104,     7,    93,    94,    95,    96,    11,    12,    24,
      25,    30,    31,    11,    12,    91,    92,   129,    97,    98,
       6,     3,     9,    12,   136,   128,     5,     5,     5,   132,
       3,   143,    12,     3,   137,   146,    12,    12,   129,   151,
       3,     3,    23,    12,    11,   136,     6,     9,    22,     8,
       6,    12,   143,    15,    16,    17,    18,    19,     6,     3,
     151,    13,     8,     6,     5,    37,     6,    12,    36,     6,
      12,    24,    89,    35,    90,    37,    38,    39,    40,    41,
      42,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    45,    46,     0,    15,    16,    17,    18,    19,
      47,    53,    55,     3,    54,    48,    11,    12,     5,     3,
      50,    51,    52,    55,    11,     6,     3,    52,    49,     9,
      68,    69,     3,    10,    35,    37,    38,    39,    40,    41,
      42,    55,    56,    57,    68,    70,    72,    83,     5,     7,
      13,     5,     5,    77,     5,    12,    12,     3,     5,    14,
      20,    21,    57,    60,    61,    62,    63,    64,    65,    66,
      67,     3,    71,    12,    12,    58,    59,    60,    60,    60,
      60,    75,    72,     3,    56,     7,    60,     3,    12,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    11,    12,    11,     6,     8,     6,    60,    78,
      12,    60,     6,    62,    63,    64,    64,    65,    65,    65,
      65,    66,    66,    67,    67,    67,     3,    60,    13,    73,
       6,    37,    79,     8,    60,    72,    76,     5,    60,    74,
      72,    60,    12,    36,    82,     6,    80,    72,    12,    56,
       6,    81,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    46,    46,    46,    48,    49,    47,
      50,    50,    51,    51,    52,    53,    54,    54,    55,    55,
      55,    55,    55,    56,    56,    57,    58,    58,    59,    59,
      60,    61,    61,    62,    62,    63,    63,    63,    64,    64,
      64,    64,    64,    65,    65,    65,    66,    66,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    68,    69,    69,
      70,    71,    71,    72,    72,    72,    72,    73,    74,    72,
      75,    76,    72,    77,    78,    72,    79,    80,    81,    72,
      72,    82,    82,    83,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     0,     0,     0,     8,
       1,     3,     1,     0,     2,     3,     1,     3,     1,     1,
       1,     1,     1,     3,     6,     4,     1,     3,     1,     0,
       1,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     1,     1,     4,     2,     1,     3,     3,     2,     0,
       3,     1,     3,     2,     2,     1,     1,     0,     0,     8,
       0,     0,     7,     0,     0,     9,     0,     0,     0,    12,
       1,     2,     0,     2,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 7:
#line 128 "simple.y"
         {
		 fprintf(fasm, "\t.text\n");
		 fprintf(fasm, ".globl %s\n", (yyvsp[0].string_val));
		 fprintf(fasm, "%s:\n", (yyvsp[0].string_val));

		 fprintf(fasm, "# Save registers\n");
		 fprintf(fasm, "\tpushq %%rbp\n");
		 fprintf(fasm, "\tmovq %%rsp, %%rbp\n");
		 fprintf(fasm, "\tsubq $%d,%%rsp\n", 8*MAX_LOCALS); // Reserve space for args locals

		 fprintf(fasm, "\tpushq %%rbx\n");
		 fprintf(fasm, "\tpushq %%r10\n");
		 fprintf(fasm, "\tpushq %%r13\n");
		 fprintf(fasm, "\tpushq %%r14\n");
		 fprintf(fasm, "\tpushq %%r15\n");

		 nlocals = 0;
		 top = 0; 
		 // set local counter 0 in this func call, then pass arg as loc after LPARENT arguments RPARENT
	 }
#line 1611 "y.tab.c"
    break;

  case 8:
#line 149 "simple.y"
         {

		 for (int i=0; i<nlocals; i++) {
		     fprintf(fasm, "\tmovq %%%s,-%d(%%rbp)\n", regArgs[i], (i+1)*8 );
		 }

         }
#line 1623 "y.tab.c"
    break;

  case 9:
#line 157 "simple.y"
         {
		  // Restore space in stack for local vars
		 fprintf(fasm, "# Restore registers\n");
		 fprintf(fasm, "\tpopq %%r15\n");
		 fprintf(fasm, "\tpopq %%r14\n");
		 fprintf(fasm, "\tpopq %%r13\n");
		 fprintf(fasm, "\tpopq %%r10\n");
		 fprintf(fasm, "\tpopq %%rbx\n");
		 fprintf(fasm, "\tleave\n");
		 fprintf(fasm, "\tret\n");
         }
#line 1639 "y.tab.c"
    break;

  case 14:
#line 182 "simple.y"
                  {
	
	creatLocalVar(currentVarType, (yyvsp[0].string_val));
	
}
#line 1649 "y.tab.c"
    break;

  case 16:
#line 191 "simple.y"
                      {									
	fprintf(fasm,".data\n");
	fprintf(fasm, ".comm %s, 8\n", (yyvsp[0].string_val));
	creatGlobalVar(currentVarType, (yyvsp[0].string_val));
    }
#line 1659 "y.tab.c"
    break;

  case 17:
#line 197 "simple.y"
                                    {
	fprintf(fasm, ".comm %s, 8\n", (yyvsp[0].string_val));
	creatGlobalVar(currentVarType, (yyvsp[0].string_val));
	}
#line 1668 "y.tab.c"
    break;

  case 18:
#line 203 "simple.y"
                         {currentVarType = 0;}
#line 1674 "y.tab.c"
    break;

  case 19:
#line 204 "simple.y"
                               {currentVarType = 1;}
#line 1680 "y.tab.c"
    break;

  case 20:
#line 205 "simple.y"
                       {currentVarType = 2;}
#line 1686 "y.tab.c"
    break;

  case 21:
#line 206 "simple.y"
                           {currentVarType = 3;}
#line 1692 "y.tab.c"
    break;

  case 22:
#line 207 "simple.y"
                       {currentVarType = 4;}
#line 1698 "y.tab.c"
    break;

  case 23:
#line 210 "simple.y"
                          {				// [A-Za-z][A-Za-z0-9]* = some expression  (global/local variable assiginment)
        char * id = (yyvsp[-2].string_val);
        int i = getLocalVarIndex(id);
                 
        if (i == -1) { // not found  (its glob)

            fprintf(fasm, "\tmovq %%%s, %s\n", regStk[top-1], id);

        }else {

            fprintf(fasm, "\tmovq %%%s, -%d(%%rbp)\n", regStk[top-1], (i+1)*8 ); //  adress of this element
        }
        top--;
	}
#line 1717 "y.tab.c"
    break;

  case 24:
#line 225 "simple.y"
                                                         {	// [A-Za-z][A-Za-z0-9]* [some expression] (array)
 	    char * id = (yyvsp[-5].string_val);
		int i = getLocalVarIndex(id);
		int j = getGlobalVarIndex(id);
		int type;
		
		if (i == -1) { // it is not local var  (its glob)

			type = global_vars_type[j];

        }else {

            type = local_vars_type[i];

        }
		 
		if(type == 0) { // it is character array, which has 1 byte length each

			fprintf(fasm, "\timulq $1, %%%s\n", regStk[top-2]);

		} else {  // it is not character array(others), which has 8 byte length each

			fprintf(fasm, "\timulq $8, %%%s\n", regStk[top-2]);

		}
		 
		if (i == -1) { // push global var location to word

			top++; // we use another reg to store base address
			fprintf(fasm, "\tmovq %s, %%%s\n", id, regStk[top-1]);
			
		}

		else { // push local var location to word

			top++;
			fprintf(fasm, "\tmovq -%d(%%rbp), %%%s\n", (i+1)*8, regStk[top-1]);
			
		}

		fprintf(fasm, "\taddq %%%s, %%%s\n", regStk[top-1], regStk[top-3]);
		fprintf(fasm, "\tmovq %%%s, (%%%s)\n", regStk[top-2], regStk[top-3]);
		top-=3;

	}
#line 1767 "y.tab.c"
    break;

  case 25:
#line 272 "simple.y"
                                              {
		 char * funcName = (yyvsp[-3].string_val);
		 int nargs = (yyvsp[-1].nargs);
		 int i;
		 fprintf(fasm,"     # func=%s nargs=%d\n", funcName, nargs);
     		 fprintf(fasm,"     # Move values from reg stack to reg args\n");
		 for (i=nargs-1; i>=0; i--) {
			top--;
			fprintf(fasm, "\tmovq %%%s, %%%s\n",
			  regStk[top], regArgs[i]);
		 }
		 if (!strcmp(funcName, "printf")) {
			 // printf has a variable number of arguments
			 // and it need the following
			 fprintf(fasm, "\tmovl    $0, %%eax\n");
		 }
		 fprintf(fasm, "\tcall %s\n", funcName);
		 fprintf(fasm, "\tmovq %%rax, %%%s\n", regStk[top]);
		 top++;
         }
#line 1792 "y.tab.c"
    break;

  case 26:
#line 295 "simple.y"
                    {
		(yyval.nargs)=1;
	 }
#line 1800 "y.tab.c"
    break;

  case 27:
#line 298 "simple.y"
                                         {
		(yyval.nargs)++;
	 }
#line 1808 "y.tab.c"
    break;

  case 28:
#line 305 "simple.y"
                       { (yyval.nargs)=(yyvsp[0].nargs); }
#line 1814 "y.tab.c"
    break;

  case 29:
#line 306 "simple.y"
                     { (yyval.nargs)=0;}
#line 1820 "y.tab.c"
    break;

  case 32:
#line 316 "simple.y"
                                                {  // stand for "||" computation
		fprintf(fasm, "\torq %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		//comput the result and push result in the second slot, and pop 1st one
		top--;
	 }
#line 1830 "y.tab.c"
    break;

  case 34:
#line 326 "simple.y"
                                                {  // stand for "&&" compute
		fprintf(fasm, "\tandq %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		//similar to the OROR above
		top--;
	 }
#line 1840 "y.tab.c"
    break;

  case 36:
#line 335 "simple.y"
                                                    {
	 
		// a == b
		// capare two expr, if true mov 1 to the 1st reg as result "TRUE" or mov 0 as result "FALSE"
		fprintf(fasm, "\tcmp %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		fprintf(fasm, "\tjne nequal_%d\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $1, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tjmp end_%d\n", jumpLabelCounter);

		fprintf(fasm, "\tnequal_%d:\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $0, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tend_%d:\n", jumpLabelCounter);
		
		jumpLabelCounter++;
		top--;
		
	 }
#line 1862 "y.tab.c"
    break;

  case 37:
#line 352 "simple.y"
                                                  {
	 
		// a != b
		fprintf(fasm, "\tcmp %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		fprintf(fasm, "\tje equal_%d\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $1, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tjmp end_%d\n", jumpLabelCounter);

		fprintf(fasm, "\tequal_%d:\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $0, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tend_%d:\n", jumpLabelCounter);
		
		jumpLabelCounter++;
		top--;
		
	 }
#line 1883 "y.tab.c"
    break;

  case 39:
#line 372 "simple.y"
                                              {

		// a < b
		fprintf(fasm, "\tcmp %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		fprintf(fasm, "\tjge greatequal_%d\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $1, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tjmp end_%d\n", jumpLabelCounter);

		fprintf(fasm, "\tgreatequal_%d:\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $0, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tend_%d:\n", jumpLabelCounter);
		
		jumpLabelCounter++;
		top--;
	}
#line 1903 "y.tab.c"
    break;

  case 40:
#line 387 "simple.y"
                                               {
		
		// a > b
		fprintf(fasm, "\tcmp %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		fprintf(fasm, "\tjle lessequal_%d\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $1, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tjmp end_%d\n", jumpLabelCounter);

		fprintf(fasm, "\tlessequal_%d:\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $0, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tend_%d:\n", jumpLabelCounter);
		
		jumpLabelCounter++;
		top--;
	}
#line 1923 "y.tab.c"
    break;

  case 41:
#line 402 "simple.y"
                                                   {
		
		// a <= b
		fprintf(fasm, "\tcmp %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		fprintf(fasm, "\tjg great_%d\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $1, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tjmp end_%d\n", jumpLabelCounter);

		fprintf(fasm, "\tgreat_%d:\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $0, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tend_%d:\n", jumpLabelCounter);
		
		jumpLabelCounter++;
		top--;
	}
#line 1943 "y.tab.c"
    break;

  case 42:
#line 417 "simple.y"
                                                    {
		
		// a >= b
		fprintf(fasm, "\tcmp %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		fprintf(fasm, "\tjl less_%d\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $1, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tjmp end_%d\n", jumpLabelCounter);

		fprintf(fasm, "\tless_%d:\n", jumpLabelCounter);
		fprintf(fasm, "\tmovq $0, %%%s\n", regStk[top-2]);
		fprintf(fasm, "\tend_%d:\n", jumpLabelCounter);
		
		jumpLabelCounter++;
		top--;
	}
#line 1963 "y.tab.c"
    break;

  case 44:
#line 436 "simple.y"
                                                   { // add two expressions and save results to the second reg in stk

		if (top<nregStk) {
			fprintf(fasm, "\taddq %%%s,%%%s\n", regStk[top-1], regStk[top-2]);
			top--;
		}
	  }
#line 1975 "y.tab.c"
    break;

  case 45:
#line 443 "simple.y"
                                                    { // similar to the one above

		if (top<nregStk) {
			fprintf(fasm, "\tsubq %%%s,%%%s\n", regStk[top-1], regStk[top-2]);
			top--;
		}
	  }
#line 1987 "y.tab.c"
    break;

  case 47:
#line 454 "simple.y"
                                                   {
		if (top<nregStk) {
			fprintf(fasm, "\timulq %%%s,%%%s\n", regStk[top-1], regStk[top-2]);
			top--;
		}
      }
#line 1998 "y.tab.c"
    break;

  case 48:
#line 460 "simple.y"
                                                    { // similar to the one above divide
		if (top<nregStk) {
			fprintf(fasm, "\tmovq $0, %%rdx\n");
			fprintf(fasm, "\tmovq %%%s, %%rax\n", regStk[top-2]);
			fprintf(fasm, "\tdivq %%%s\n", regStk[top-1]);
			fprintf(fasm, "\tmovq %%rax, %%%s\n", regStk[top-2]);
			top--;
		}
      }
#line 2012 "y.tab.c"
    break;

  case 49:
#line 469 "simple.y"
                                                     { // the remainder from percent results saved to rdx
		if (top<nregStk) {
			fprintf(fasm, "\tmovq $0, %%rdx\n");
			fprintf(fasm, "\tmovq %%%s, %%rax\n", regStk[top-2]);
			fprintf(fasm, "\tdivq %%%s\n", regStk[top-1]);
			fprintf(fasm, "\tmovq %%rdx, %%%s\n", regStk[top-2]);
			top--;
		}
      }
#line 2026 "y.tab.c"
    break;

  case 50:
#line 481 "simple.y"
                       {
		  // Add string to string table.
		  // String table will be produced later
		  string_table[nstrings]=(yyvsp[0].string_val);
		  fprintf(fasm, "\t#top=%d\n", top);
		  fprintf(fasm, "\n\t# push string %s top=%d\n",
			  (yyvsp[0].string_val), top);
		  if (top<nregStk) {
		  	fprintf(fasm, "\tmovq $string%d, %%%s\n", 
				nstrings, regStk[top]);
			//fprintf(fasm, "\tmovq $%s,%%%s\n", 
				//$<string_val>1, regStk[top]);
			top++;
		  }
		  nstrings++;
	  }
#line 2047 "y.tab.c"
    break;

  case 52:
#line 498 "simple.y"
                 {
		 
 	     char * id = (yyvsp[0].string_val);
		 int i = getLocalVarIndex(id);
		 top++;
		 if (i>=0) { // local found

			 fprintf(fasm, "\tmovq -%d(%%rbp), %%%s\n", (i+1)*8, regStk[top-1] );
			 
		 }
		 else {  // Global var

			 fprintf(fasm, "\tmovq %s, %%%s\n", id, regStk[top-1]);
		
		 }
	  }
#line 2068 "y.tab.c"
    break;

  case 53:
#line 514 "simple.y"
                                          {
  		 // Lookup local var
 	     char * id = (yyvsp[-3].string_val);
		 int i = getLocalVarIndex(id);
		 int j = getGlobalVarIndex(id);
		 int type;

		 if (i == -1) { // it is not local var  (its glob)

			type = global_vars_type[j];

        }else {

            type = local_vars_type[i];

        }

		//multiply and add stack for adresss
		 
		if(type == 0) { // it is character array, which has 1 byte length each

			fprintf(fasm, "\timulq $1, %%%s\n", regStk[top-1]);

		} else {  // it is not character array(others), which has 8 byte length each

			fprintf(fasm, "\timulq $8, %%%s\n", regStk[top-1]);

		}
 
		 	 
		 if (i == -1) { // global
			 
			 top++;
			 fprintf(fasm, "\tmovq %s, %%%s\n", id, regStk[top-1]);

		 }else { // local
			 
			 top++;
			 fprintf(fasm, "\tmovq -%d(%%rbp), %%%s\n", (i+1)*8, regStk[top-1]);

		 }
		 
		 fprintf(fasm, "\taddq %%%s, %%%s\n", regStk[top-1], regStk[top-2]);
		 
		 fprintf(fasm, "\tmovq %%%s, %%%s\n", regStk[top-2], regStk[top-1]); //dereferencing
		 fprintf(fasm, "\tmovq (%%%s), %%%s\n", regStk[top-1], regStk[top-2]);
		 top--;
		 
		 if(type == 0) // take only first byte (bc its char arr)
		 {

		 	fprintf(fasm, "\tmovb %%%s, %%r9b\n", regStkByte[top-1]);
		 	fprintf(fasm, "\tmovq $0, %%%s\n", regStk[top-1]);
		 	fprintf(fasm, "\tmovb %%r9b, %%%s\n", regStkByte[top-1]);

		 }
	  }
#line 2130 "y.tab.c"
    break;

  case 54:
#line 572 "simple.y"
                           {
 	     char * id = (yyvsp[0].string_val);
		 int i = getLocalVarIndex(id);
		 top++;
		 if (i>=0) { //local

			 fprintf(fasm, "\tleaq -%d(%%rbp), %%%s\n", (i+1)*8, regStk[top-1]);
			
		 }
		 else { //global

			 fprintf(fasm, "\tleaq %s, %%%s\n", id, regStk[top-1]);

		 }
		 
	  }
#line 2151 "y.tab.c"
    break;

  case 55:
#line 588 "simple.y"
                          {
		  fprintf(fasm, "\n\t# push %s\n", (yyvsp[0].string_val));
		  if (top<nregStk) {
			fprintf(fasm, "\tmovq $%s,%%%s\n", 
				(yyvsp[0].string_val), regStk[top]);
			top++;
		  }
	  }
#line 2164 "y.tab.c"
    break;

  case 61:
#line 612 "simple.y"
             {
			creatLocalVar(currentVarType, (yyvsp[0].string_val));
    }
#line 2172 "y.tab.c"
    break;

  case 62:
#line 615 "simple.y"
                               {
		creatLocalVar(currentVarType, (yyvsp[0].string_val));
	}
#line 2180 "y.tab.c"
    break;

  case 64:
#line 622 "simple.y"
                          {
		top = 0;
	 }
#line 2188 "y.tab.c"
    break;

  case 67:
#line 627 "simple.y"
                                         {
			/*

			if (xxx) {

				statements
				jmp: ifEnd_#:

			}
			lbl: else_#:
			else {

				statements

			}

			lbl: ifEnd_#: (skip else)

			*/

			ifLabelCounter++;
			fprintf(fasm, "\tcmpq $0, %%%s\n", regStk[top-1]);
			fprintf(fasm, "\tje else_%d\n", ifLabelCounter);
			
			top--;
			
		}
#line 2220 "y.tab.c"
    break;

  case 68:
#line 654 "simple.y"
                          {
			fprintf(fasm, "\tjmp ifEnd_%d\n", ifLabelCounter);
			fprintf(fasm, "\telse_%d:\n", ifLabelCounter);
		}
#line 2229 "y.tab.c"
    break;

  case 69:
#line 658 "simple.y"
                              {
			fprintf(fasm, "\tifEnd_%d:\n", ifLabelCounter);
		 }
#line 2237 "y.tab.c"
    break;

  case 70:
#line 661 "simple.y"
                         {
		// act 1
		loopStack[loopTop] = nlabel;         // use loopstk to save every index of loop, make sure loop
											// oprations correct when in nested loops conditions
		loopTop++;							// pass this loop as a new loop
		nlabel++;
		fprintf(fasm, "\n\t# Begin WHILE loop\n");
		fprintf(fasm, "loop_start_%d:\n", loopStack[loopTop-1]);       		
		fprintf(fasm, "loop_continue_%d:\n", loopStack[loopTop-1]);	
		// when continue happend, skip some statment and start a new iteation
	    }
#line 2253 "y.tab.c"
    break;

  case 71:
#line 672 "simple.y"
                           {
		// act2
		fprintf(fasm, "\tcmpq $0, %%%s\n", regStk[top-1]);		
		// check if the statment is true or false, if false end while
		fprintf(fasm, "\tje loop_end_%d\n", loopStack[loopTop-1]);
		top--;
         }
#line 2265 "y.tab.c"
    break;

  case 72:
#line 679 "simple.y"
                   {
		// act3
		fprintf(fasm, "\tjmp loop_start_%d\n", loopStack[loopTop-1]);
		// after statment ends, jmp back to while condition expression to check
		fprintf(fasm, "loop_end_%d:\n", loopStack[loopTop-1]);
		loopTop--;
	 }
#line 2277 "y.tab.c"
    break;

  case 73:
#line 686 "simple.y"
              {
		loopStack[loopTop] = nlabel;
		loopTop++;
		nlabel++;
		fprintf(fasm, "loop_start_%d:\n", loopStack[loopTop-1]);
		fprintf(fasm, "loop_continue_%d:\n", loopStack[loopTop-1]);
	 }
#line 2289 "y.tab.c"
    break;

  case 74:
#line 694 "simple.y"
                   {}
#line 2295 "y.tab.c"
    break;

  case 75:
#line 696 "simple.y"
                                                   {
		fprintf(fasm, "\tcmpq $0, %%%s\n", regStk[top-1]);
		fprintf(fasm, "\tjne loop_start_%d\n", loopStack[loopTop-1]);
		top--;
		fprintf(fasm, "loop_end_%d:\n", loopStack[loopTop-1]);
		loopTop--;
	 }
#line 2307 "y.tab.c"
    break;

  case 76:
#line 703 "simple.y"
                                            {
		loopStack[loopTop] = nlabel;
		loopTop++;
		nlabel++;
		fprintf(fasm, "loop_start_%d:\n", loopStack[loopTop-1]);
	 }
#line 2318 "y.tab.c"
    break;

  case 77:
#line 709 "simple.y"
                              {
		fprintf(fasm, "\tcmpq $0, %%%s\n", regStk[top-1]);
		fprintf(fasm, "\tjne loop_body_start_%d\n", loopStack[loopTop-1]);
		fprintf(fasm, "\tje loop_end_%d\n", loopStack[loopTop-1]);
		top--;

		fprintf(fasm, "loop_assignment_%d:\n", loopStack[loopTop-1]);
		fprintf(fasm, "loop_continue_%d:\n", loopStack[loopTop-1]);
	 }
#line 2332 "y.tab.c"
    break;

  case 78:
#line 718 "simple.y"
                           {
		fprintf(fasm, "\tjmp loop_start_%d\n", loopStack[loopTop-1]); 
		fprintf(fasm, "\tloop_body_start_%d:\n", loopStack[loopTop-1]);
	 }
#line 2341 "y.tab.c"
    break;

  case 79:
#line 722 "simple.y"
                   {
		fprintf(fasm, "\tjmp loop_assignment_%d\n", loopStack[loopTop-1]);
		fprintf(fasm, "loop_end_%d:\n", loopStack[loopTop-1]);
		loopTop--;
	}
#line 2351 "y.tab.c"
    break;

  case 83:
#line 736 "simple.y"
                        {
		//CONTINUE in lopps, back to judge expression
		fprintf(fasm, "\tjmp loop_continue_%d\n", loopStack[loopTop-1]);
	 }
#line 2360 "y.tab.c"
    break;

  case 84:
#line 740 "simple.y"
                           {
		//BREAK in loops, end current loop
		fprintf(fasm, "\tjmp loop_end_%d\n", loopStack[loopTop-1]);
	 }
#line 2369 "y.tab.c"
    break;

  case 85:
#line 744 "simple.y"
                                       {
		 fprintf(fasm, "\tmovq %%rbx, %%rax\n");
		 top = 0;
		 
		  // Restore space in stack for local vars
		 fprintf(fasm, "# Restore registers\n");
		 fprintf(fasm, "\tpopq %%r15\n");
		 fprintf(fasm, "\tpopq %%r14\n");
		 fprintf(fasm, "\tpopq %%r13\n");
		 fprintf(fasm, "\tpopq %%r10\n");
		 fprintf(fasm, "\tpopq %%rbx\n");
		 fprintf(fasm, "\tleave\n");
		 fprintf(fasm, "\tret\n");
	 }
#line 2388 "y.tab.c"
    break;


#line 2392 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 760 "simple.y"


void yyset_in (FILE *  in_str );

int
yyerror(const char * s)
{
	fprintf(stderr,"%s:%d: %s\n", input_file, line_number, s);
}


int
main(int argc, char **argv)
{
	printf("-------------WARNING: You need to implement global and local vars ------\n");
	printf("------------- or you may get problems with top------\n");
	
	// Make sure there are enough arguments
	if (argc <2) {
		fprintf(stderr, "Usage: simple file\n");
		exit(1);
	}

	// Get file name
	input_file = strdup(argv[1]);

	int len = strlen(input_file);
	if (len < 2 || input_file[len-2]!='.' || input_file[len-1]!='c') {
		fprintf(stderr, "Error: file extension is not .c\n");
		exit(1);
	}

	// Get assembly file name
	asm_file = strdup(input_file);
	asm_file[len-1]='s';

	// Open file to compile
	FILE * f = fopen(input_file, "r");
	if (f==NULL) {
		fprintf(stderr, "Cannot open file %s\n", input_file);
		perror("fopen");
		exit(1);
	}

	// Create assembly file
	fasm = fopen(asm_file, "w");
	if (fasm==NULL) {
		fprintf(stderr, "Cannot open file %s\n", asm_file);
		perror("fopen");
		exit(1);
	}

	// Uncomment for debugging
	//fasm = stderr;

	// Create compilation file
	// 
	yyset_in(f);
	yyparse();

	// Generate string table
	int i;
	for (i = 0; i<nstrings; i++) {
		fprintf(fasm, "string%d:\n", i);
		fprintf(fasm, "\t.string %s\n\n", string_table[i]);
	}

	fclose(f);
	fclose(fasm);

	return 0;
}
