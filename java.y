

//语法分析yacc程序。
//一个分析栈和一个内容栈。分析栈中保存着终结符和非终结符， 并且代表当前剖析状态。内容栈是一个 YYSTYPE 元素的数组，对于分析栈中的每一个元素都保存着一个对应的值。
//lex return的类型进入分析栈--lex返回终结符一步步语法分析。yylval进入内容栈。$$访问的是内容栈,其类型为YYSTYPE。正是属性文法的属性（需要看一下第6章再定义）
//分析栈就是编译原理中LR用的符号栈，做出语法动作也是依据这个栈。状态栈由yacc自动维护
%{
    #include <stdio.h>
    #include <string.h>
	
	
	
	
	//extern是指定义(分配空间)在其它地方，函数声明与定义是分开的通过声明使用因此都不用加extren，变量为声明并定义因此要加。
	int yylex(void);
	extern FILE * yyin;
	extern int line;
	extern char SymbolTable[10000][100];//符号表	
	extern float FloatTable[10000];			//float 4byte
	extern int IntTable[10000];				//int 4byte
	extern char StringTable[10000][100];	//string常量
	extern int CharTable[10000];			//char 2byteUnicode
	
	int yyerror(char *s);
	
	
%}
//--------------------------------------------------------------------------------------
//定义YYSTYPE内容的属性





//定义开始符号
%start CLASSFILE


//定义token终结符,这里定义的就是二元式<种编码，内码值>的种编码，lex中返回该类型，其在yacc中最后的表示是宏定义编码
//因为大多名字比较敏感因此采用_开头

//类相关
%token  _PRIVATE _PROTECTED _PUBLIC _ABSTRACT _EXTENDS _FINAL _IMPLEMENTS _NATIVE _NEW _STATIC _STRICTFP _TRANSIENT  _VOLATILE
//程序控制
%token 	_BREAK _CONTINUE _RETURN _DO _WHILE _IF _ELSE _FOR _INSTANCEOF _SWITCH _CASE _DEFAULT _TRY _CATCH _FINALLY _THROW _THROWS _ASSERT _SYNCHRONIZED
//包
%token 	_IMPORT _PACKAGE 
//类型 String不是关键字，但java有其语法糖于是提出
%token  _BOOLEAN _BYTE _CHAR _DOUBLE _FLOAT _INT _LONG _SHORT _VOID _STRING _ENUM _CLASS _INTERFACE
//特殊值
%token 	_TRUE _FALSE _NUL _SUPER _THIS
//运算符 界符 放弃三元
//+ - * / % ++ --
%token	_ADD _SUB _MUL _DIV _MOD _ADD2 _SUB2
//== != > < >= <=
%token	_CMP _NCMP _MORE _LESS _MCMP _LCMP
//& | ^ ~ << >> >>>
%token	_AND _OR _XOR _NOT _SHL _SHR _SAR
//&& || !
%token	_BAND _BOR _BNOT
//= += -= *= /= %= <<= >>= &= ^= |=
%token	_MOV _ADDMOV _SUBMOV _MULMOV _DIVMOV _MODMOV _SHLMOV _SHRMOV _ANDMOV _XORMOV _ORMOV
//界符   {} [] ()  ;  ,  .
%token	_LBRACE _RBRACE _LBRACKET _RBRACKET _LPARENTHESE _RPARENTHESE _SEMICOLON _COMMA _POINT

//标识符  内码值指向符号表
%token  _SYMBOL
//常数类型  分别归表   不判断数字大小，全部按4位整形处理  浮点全部按float处理
%token  _CUSTCHAR  //' '
%token	_CUSTSTRING//字符串
%token	_CUSTINT   //整形
%token	_CUSTFLOAT //浮点型



//符号优先级定义，此处帮助动作表的生成  一元的+-被归于值中，优先级高
%left 	_COMMA
%right 	_MOV _ADDMOV _SUBMOV _MULMOV _DIVMOV _MODMOV _SHLMOV _SHRMOV _ANDMOV _XORMOV _ORMOV
%left	_BOR
%left	_BAND
%left	_OR
%left	_XOR
%left	_AND
%left	_CMP _NCMP
%left	_MORE _LESS _MCMP _LCMP
%left	_SHL _SHR _SAR
%left	_ADD _SUB
%left	_MUL _DIV _MOD
%right	_ADD2 _SUB2 _BNOT _NOT  
%left	_POINT _RBRACE _LBRACKET _RBRACKET _LPARENTHESE

//--------------------------------------------------------------------------------------

%%
CLASSFILE
	: _NUL{}










%%

int yyerror(char *s) {
    return 0;
}

int main(int argc, char** argv) 
{
   if (argc > 1) {
       if (!(yyin = fopen(argv[1], "r"))) {   
           perror(argv[1]);
           return 1;
       }
   }
   else
   {
	   printf("filename!\n");
	   return 0;
   }
  // yyparse();
  int a;
  int sum=0;
   while(1)
   {
	   a=yylex();
	 
	   
	   if(a==0)
		   break;
	   
	   printf("%d %d \n",a,yylval);
	   sum++;
   }
   printf("sum:%d\n",sum);

   
   return 0;

}






















