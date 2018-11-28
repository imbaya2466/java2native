

//语法分析yacc程序。
//一个分析栈和一个内容栈。分析栈中保存着终结符和非终结符， 并且代表当前剖析状态。内容栈是一个 YYSTYPE 元素的数组，对于分析栈中的每一个元素都保存着一个对应的值。
//lex return的类型进入分析栈--lex返回终结符一步步语法分析。yylval进入内容栈。$$访问的是内容栈,其类型为YYSTYPE。正是属性文法的属性（需要看一下第6章再定义）
//分析栈就是编译原理中LR用的符号栈，做出语法动作也是依据这个栈。状态栈由yacc自动维护
%{
	
    #include <stdio.h>
    #include <string.h>
	#include "tool/tree.h"	
	
	//extern是指定义(分配空间)在其它地方，函数声明与定义是分开的通过声明使用因此都不用加extren，变量为声明并定义因此要加。
	int yylex(void);
	extern FILE * yyin;
	extern int line;

	extern int symbolnum;
	extern int floatnum;
	extern int intnum;
	extern int stringnum;
	extern int charnum;
	
	pNode root;
	
	
	int yyerror(char *s);
	
	
%}
//--------------------------------------------------------------------------------------
//定义YYSTYPE内容的属性
//每个YYSTYPE代表一个节点
%union{
	pNode pnode;
}



//定义开始符号
%start compilation_unit


//定义token终结符,这里定义的就是二元式<种编码，内码值>的种编码，lex中返回该类型，其在yacc中最后的表示是宏定义编码
//因为大多名字比较敏感因此采用_开头  省略了三元与@

//类相关
%token <pnode> _PRIVATE _PROTECTED _PUBLIC _ABSTRACT _EXTENDS _FINAL _IMPLEMENTS _NATIVE _NEW _STATIC _STRICTFP _TRANSIENT  _VOLATILE
//程序控制
%token <pnode> 	_BREAK _CONTINUE _RETURN _DO _WHILE _IF _ELSE _FOR _INSTANCEOF _SWITCH _CASE _DEFAULT _TRY _CATCH _FINALLY _THROW _THROWS _ASSERT _SYNCHRONIZED
//包
%token <pnode> 	_IMPORT _PACKAGE 
//类型 String不是关键字，但java有其语法糖于是提出
%token <pnode>  _BOOLEAN _BYTE _CHAR _DOUBLE _FLOAT _INT _LONG _SHORT _VOID _STRING _ENUM _CLASS _INTERFACE
//特殊值
%token <pnode> 	_TRUE _FALSE _NUL _SUPER _THIS
//运算符 界符 
//+ - * / % ++ --
%token <pnode>	_ADD _SUB _MUL _DIV _MOD _ADD2 _SUB2
//== != > < >= <=
%token <pnode>	_CMP _NCMP _MORE _LESS _MCMP _LCMP
//& | ^ ~ << >> >>>
%token <pnode>	_AND _OR _XOR _NOT _SHL _SHR _SAR
//&& || !
%token <pnode>	_BAND _BOR _BNOT
//= += -= *= /= %= <<= >>= &= ^= |=
%token <pnode>	_MOV _ADDMOV _SUBMOV _MULMOV _DIVMOV _MODMOV _SHLMOV _SHRMOV _ANDMOV _XORMOV _ORMOV
//界符   {} [] ()  ;  ,  .
%token <pnode>	_LBRACE _RBRACE _LBRACKET _RBRACKET _LPARENTHESE _RPARENTHESE _SEMICOLON _COMMA _POINT
//其它  ?  :
%token <pnode>  _DOUBT _COLON
//标识符  内码值指向符号表
%token <pnode>  _SYMBOL
//常数类型  分别归表   不判断数字大小，全部按4位整形处理  浮点全部按float处理
%token <pnode>  _CUSTCHAR  //' '
%token <pnode>	_CUSTSTRING//字符串
%token <pnode>	_CUSTINT   //整形
%token <pnode>	_CUSTFLOAT //浮点型


//非终结符定义

%type <pnode>  compilation_unit  
%type <pnode>  package_statement  
%type <pnode>  package_name  
%type <pnode>  import_statement  
%type <pnode>  class_name  
%type <pnode>  type_declaration  
%type <pnode>  class_declaration  
%type <pnode>  modifiers  
%type <pnode>  modifier  
%type <pnode>  implements  
%type <pnode>  field_declarations  
%type <pnode>  field_declaration  
%type <pnode>  method_declaration  
%type <pnode>  type  
%type <pnode>  type_specifier  
%type <pnode>  brackets  
//---------2018.11.27其上以进enum










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
//bnf文法定义 这部分重复代码较多其实宏定义省事，但是为了方便调试语法树好看还是先这样，最后成功后改用宏！！！！重复量太大了
//需了解LR分析表的构造
// 包  导入  类型声明 | 导入 类型声明
//native代码注册其实不需要类名包名...留做后用吧
compilation_unit 	
			: package_statement import_statement type_declaration 
				{  pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  root=MakeNodeNoAtt(3,ls,compilation_unit,"compilation_unit"); }
			| import_statement type_declaration 
				{  pNode ls[2]={$<pnode>1,$<pnode>2};  root=MakeNodeNoAtt(2,ls,compilation_unit,"compilation_unit"); }
			;
//包: package 包名 ;
package_statement 
			: _PACKAGE package_name _SEMICOLON
				{  pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MakeNodeNoAtt(3,ls,package_statement,"package_statement"); }
			;
//包名: 标识符 | 包名 . 标识符
package_name
			: _SYMBOL
				{  pNode ls[1]={$<pnode>1};  $<pnode>$=MakeNodeNoAtt(1,ls,package_name,"package_name"); }
			| package_name _POINT _SYMBOL
				{  pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MakeNodeNoAtt(3,ls,package_name,"package_name"); }
			;
//导入声明 : import 包名 . * ; | import 类名 ; | import 接口名 ;			
import_statement
			: _IMPORT package_name _POINT _MUL _SEMICOLON
				{  pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MakeNodeNoAtt(5,ls,import_statement,"import_statement"); }
			| _IMPORT class_name _SEMICOLON
				{  pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MakeNodeNoAtt(3,ls,import_statement,"import_statement"); }
			;
//类名 : 标识符 | 包名.标识符
class_name 		
			: _SYMBOL
				{  pNode ls[1]={$<pnode>1};  $<pnode>$=MakeNodeNoAtt(1,ls,class_name,"class_name"); }
			| package_name _POINT _SYMBOL
				{  pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MakeNodeNoAtt(3,ls,class_name,"class_name"); }
			;

//---------------------以上头部分解析完成
			
//类型声明定义  这里一个文件中只定义一个类或接口
type_declaration
			: class_declaration
				{  pNode ls[1]={$<pnode>1};  $<pnode>$=MakeNodeNoAtt(1,ls,type_declaration,"type_declaration"); }
			| interface_declaration 
			;
//类声明: 	{modifier}	class 标识符 [extends 类名] [implements 接口名] {领域}
class_declaration
			: modifiers _CLASS _SYMBOL _EXTENDS class_name _IMPLEMENTS implements _LBRACE field_declarations _RBRACE
			| modifiers _CLASS _SYMBOL  _IMPLEMENTS implements _LBRACE field_declarations _RBRACE
			| modifiers _CLASS _SYMBOL  _LBRACE field_declarations _RBRACE
			;
//前缀可多个
modifiers
			: modifiers modifier
			|
			;
modifier
			: _PRIVATE 
			| _PROTECTED 
			| _PUBLIC 
			| _ABSTRACT 
			| _FINAL 
			| _NATIVE
			| _STATIC
			| _TRANSIENT 
			| _SYNCHRONIZED
			;
//接口多个
implements	
			:  implements _COMMA class_name
			| class_name
			;
			
//----------------类内领域
//领域声明多个			
field_declarations
			: field_declarations field_declaration
			|
			;
//领域: 	--------------------这里未完成		
field_declaration		
			: method_declaration
			| //constructor_declaration
			| //variable_declaration
			| //static_initializer 
			| //_SEMICOLON
			;
//方法声明		虽然java可以 int a()[] {}写返回数组...但是基本没人这么用就按正常写法	
// 前缀 类型 标识符 ( [参数] )  ;或者 定义块
method_declaration			
			: modifiers type _SYMBOL _LPARENTHESE parameter_list _RPARENTHESE statement_block 
			| modifiers type _SYMBOL _LPARENTHESE  _RPARENTHESE statement_block 
			| modifiers type _SYMBOL _LPARENTHESE parameter_list _RPARENTHESE _SEMICOLON
			| modifiers type _SYMBOL _LPARENTHESE  _RPARENTHESE _SEMICOLON 
			;
//类型 含数组			
type
			: type_specifier 
			| type_specifier  brackets
			;
//[]多个
brackets   
			: brackets _LBRACKET _RBRACKET
			| _LBRACKET _RBRACKET
			;
//类型
type_specifier
			: _BOOLEAN 
			| _BYTE 
			| _CHAR 
			| _DOUBLE 
			| _FLOAT 
			| _INT 
			| _LONG 
			| _SHORT 
			| _VOID 
			| _STRING
			| class_name 
			;			

//临时测试用：
parameter_list : ;
statement_block : ;
interface_declaration : ;






%%

int yyerror(char *s) {
	printf("Gramma analysis error %s  on %d\n",s,line);
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
   
   
   
   
   
   yyparse();
  
  
  showtree(root);
  /*
  int a;
  int sum=0;
   while(1)
   {
	   a=yylex();
	 
	   
	   if(a==0)
		   break;
	   
	   printf("%d  %s\n",a,yylval.pnode->leafstring);
	   sum++;
   }
   printf("sum:%d   \n",sum);

   */
   return 0;

}






















