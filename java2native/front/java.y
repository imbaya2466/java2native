

//  语法分析yacc程序。
//  一个分析栈和一个内容栈。分析栈中保存着终结符和非终结符， 并且代表当前剖析状态。内容栈是一个 YYSTYPE 元素的数组，对于分析栈中的每一个元素都保存着一个对应的值。
//  lex return的类型进入分析栈--lex返回终结符一步步语法分析。yylval进入内容栈。$$访问的是内容栈,其类型为YYSTYPE。正是属性文法的属性（需要看一下第6章再定义）
// 分析栈就是编译原理中LR用的符号栈，做出语法动作也是依据这个栈。状态栈由yacc自动维护
%{
	
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
	
	
%}
// --------------------------------------------------------------------------------------
// 定义YYSTYPE内容的属性
// 每个YYSTYPE代表一个节点
%union{
	pNode pnode;
}



// 定义开始符号
%start compilation_unit


// 定义token终结符,这里定义的就是二元式<种编码，内码值>的种编码，lex中返回该类型，其在yacc中最后的表示是宏定义编码
// 因为大多名字比较敏感因此采用_开头  省略了@

// 类相关
%token <pnode> _PRIVATE _PROTECTED _PUBLIC _ABSTRACT _EXTENDS _FINAL _IMPLEMENTS _NATIVE _NEW _STATIC _STRICTFP _TRANSIENT  _VOLATILE
// 程序控制
%token <pnode> 	_BREAK _CONTINUE _RETURN _DO _WHILE _IF _ELSE _FOR _INSTANCEOF _SWITCH _CASE _DEFAULT _TRY _CATCH _FINALLY _THROW _THROWS _ASSERT _SYNCHRONIZED
// 包
%token <pnode> 	_IMPORT _PACKAGE 
// 类型 String不是关键字，但java有其语法糖于是提出
%token <pnode>  _BOOLEAN _BYTE _CHAR _DOUBLE _FLOAT _INT _LONG _SHORT _VOID _STRING _ENUM _CLASS _INTERFACE
// 特殊值
%token <pnode> 	_TRUE _FALSE _NUL _SUPER _THIS
// 运算符 界符 
// + - * / % ++ --
%token <pnode>	_ADD _SUB _MUL _DIV _MOD _ADD2 _SUB2
// == != > < >= <=
%token <pnode>	_CMP _NCMP _MORE _LESS _MCMP _LCMP
// & | ^ ~ << >> >>>
%token <pnode>	_AND _OR _XOR _NOT _SHL _SHR _SAR
// && || !
%token <pnode>	_BAND _BOR _BNOT
// = += -= *= /= %= <<= >>= &= ^= |=
%token <pnode>	_MOV _ADDMOV _SUBMOV _MULMOV _DIVMOV _MODMOV _SHLMOV _SHRMOV _ANDMOV _XORMOV _ORMOV
// 界符   {} [] ()  ;  ,  .
%token <pnode>	_LBRACE _RBRACE _LBRACKET _RBRACKET _LPARENTHESE _RPARENTHESE _SEMICOLON _COMMA _POINT
// 其它  ?  :
%token <pnode>  _DOUBT _COLON
// 标识符  内码值指向符号表
%token <pnode>  _SYMBOL
// 常数类型  分别归表   不判断数字大小，全部按4位整形处理  浮点全部按float处理
%token <pnode>  _CUSTCHAR  // ' '
%token <pnode>	_CUSTSTRING// 字符串
%token <pnode>	_CUSTINT   // 整形
%token <pnode>	_CUSTFLOAT // 浮点型
// lex不会返回的，用于负数优先级指定
%token UMINUS


//  非终结符定义

%type <pnode>  compilation_unit  
%type <pnode>  import_statements 
%type <pnode>  type_declarations 
%type <pnode>  package_statement  
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
%type <pnode>  parameter_list 
%type <pnode>  parameter 
%type <pnode>  statement_block 
%type <pnode>  statements 
%type <pnode>  statement 
%type <pnode>  variable_declaration 
%type <pnode>  variable_declarators 
%type <pnode>  variable_declarator 
%type <pnode>  variable_initializer 
%type <pnode>  variable_initializers 
%type <pnode>  expression 
%type <pnode>  numeric_expression 
%type <pnode>  testing_expression 
%type <pnode>  logical_expression 
%type <pnode>  bit_expression     
//  %type <pnode>  string_expression  
//  %type <pnode>  casting_expression 
%type <pnode>  creating_expression 
%type <pnode>  bracketnums
%type <pnode>  arglist 
%type <pnode>  literal_expression 
%type <pnode>  if_statement 
%type <pnode>  do_statement 
%type <pnode>  while_statement 
%type <pnode>  for_statement 
%type <pnode>  expression01 
%type <pnode>  try_statement 
%type <pnode>  catchs 
%type <pnode>  switch_statement 
%type <pnode>  cases 
%type <pnode>  constructor_declaration 
%type <pnode>  static_initializer 
%type <pnode>  interface_declaration 









// 符号优先级定义，此处帮助动作表的生成  一元的+-在语法分析时判断  排序为低到高
// 优先级的表示可以用语法也可以用在这里显示，这样可以省去很多语法说明
// 注意，当bison分析语法规则时遇到冲突时，会查优先级表来解决冲突。
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
%right	_ADD2 _SUB2 _BNOT _NOT  UMINUS
%left	_POINT _LBRACKET _RBRACKET _LPARENTHESE _RPARENTHESE


// --------------------------------------------------------------------------------------

%%
// bnf文法定义 这部分重复代码较多其实宏定义省事，但是为了方便调试语法树好看还是先这样，最后成功后改用宏！！！！重复量太大了
// 需了解LR分析表的构造  先产出整体的语法树，再分析出函数部分的抽象语法树，为了做函数的native其它部分可以都不考虑
// 以进归约冲突默认以进，归约归约冲突按先出现的   改变默认方式为按优先级高(同优先级看方向)的先归约
// 0: { pNode ls=NULL;  $<pnode>$=MNNA(0,compilation_unit);}
// 1: { pNode ls[1]={$<pnode>1};  $<pnode>$=MNNA(1,compilation_unit);}
// 2: { pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,compilation_unit);}
// 3: { pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,compilation_unit);}
// 4: { pNode ls[4]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4};  $<pnode>$=MNNA(4,compilation_unit);}
// 5: { pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MNNA(5,compilation_unit);}
// 6: { pNode ls[6]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6};  $<pnode>$=MNNA(6,compilation_unit);}
// 7: { pNode ls[7]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7};  $<pnode>$=MNNA(7,compilation_unit);}
// 8: { pNode ls[8]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7,$<pnode>8};  $<pnode>$=MNNA(8,compilation_unit);}
// 9: { pNode ls[9]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7,$<pnode>8,$<pnode>9};  $<pnode>$=MNNA(9,compilation_unit);}
// 10: { pNode ls[10]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7,$<pnode>8,$<pnode>9,$<pnode>10};  $<pnode>$=MNNA(10,compilation_unit);}


//  包  导入  类型声明 | 导入 类型声明
// native代码注册其实不需要类名包名...留做后用吧
compilation_unit 	
			: package_statement import_statements type_declarations  
				{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  root=MNNA(3,compilation_unit);}
			| import_statements type_declarations 
				{ pNode ls[2]={$<pnode>1,$<pnode>2};  root=MNNA(2,compilation_unit);}
			;
// 导入声明0-n
import_statements
			: import_statements import_statement
				{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,import_statements);}
			| 
				{ pNode *ls=NULL;  $<pnode>$=MNNA(0,import_statements);}
			;
// 类型声明0-n
type_declarations
			: type_declarations type_declaration
				{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,type_declarations);}
			|
				{ pNode *ls=NULL;  $<pnode>$=MNNA(0,type_declarations);}
			;
// 包: package 包名 ;
package_statement 
			: _PACKAGE class_name _SEMICOLON
				{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,package_statement);}
			;

// 导入声明 : import 包名 . * ; | import 类名 ; | import 接口名 ;			
import_statement
			: _IMPORT class_name _POINT _MUL _SEMICOLON
			{ pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MNNA(5,import_statement);}
			| _IMPORT class_name _SEMICOLON
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,import_statement);}
			;
// 类名 : 标识符 | 包名.标识符
class_name 		
			: _SYMBOL
			{ pNode ls[1]={$<pnode>1};  $<pnode>$=MNNA(1,class_name);}
			| class_name _POINT _SYMBOL
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,class_name);}
			;

			
			
// -----------------------------------------以上为文件头解析部分			
			
// 类型声明定义  
type_declaration
			: class_declaration
			{ pNode ls[1]={$<pnode>1};  $<pnode>$=MNNA(1,type_declaration);}
			| interface_declaration
			{ pNode ls[1]={$<pnode>1};  $<pnode>$=MNNA(1,type_declaration);}
			;
// 类声明: 	{modifier}	class 标识符 [extends 类名] [implements 接口名] {领域}
class_declaration
			: modifiers _CLASS _SYMBOL _EXTENDS class_name _IMPLEMENTS implements _LBRACE field_declarations _RBRACE
			{ pNode ls[10]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7,$<pnode>8,$<pnode>9,$<pnode>10};  $<pnode>$=MNNA(10,class_declaration);}
			| modifiers _CLASS _SYMBOL  _IMPLEMENTS implements _LBRACE field_declarations _RBRACE
			{ pNode ls[8]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7,$<pnode>8};  $<pnode>$=MNNA(8,class_declaration);}
			| modifiers _CLASS _SYMBOL  _LBRACE field_declarations _RBRACE
			{ pNode ls[6]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6};  $<pnode>$=MNNA(6,class_declaration);}
			;
// 前缀0-多个
modifiers
			: modifiers modifier
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,modifiers);}
			|
			 { pNode *ls=NULL;  $<pnode>$=MNNA(0,modifiers);}
			;
modifier
			: _PRIVATE 
			{ pNode ls[1]= {$<pnode>1};  $<pnode>$=MNNA(1,modifier);}
			| _PROTECTED 
			{ pNode ls[1]= {$<pnode>1};  $<pnode>$=MNNA(1,modifier);}
			| _PUBLIC 
			{ pNode ls[1]= {$<pnode>1};  $<pnode>$=MNNA(1,modifier);}
			| _ABSTRACT 
			{ pNode ls[1]= {$<pnode>1};  $<pnode>$=MNNA(1,modifier);}
			| _FINAL 
			{ pNode ls[1]= {$<pnode>1};  $<pnode>$=MNNA(1,modifier);}
			| _NATIVE
			{ pNode ls[1]= {$<pnode>1};  $<pnode>$=MNNA(1,modifier);}
			| _STATIC
			{ pNode ls[1]= {$<pnode>1};  $<pnode>$=MNNA(1,modifier);}
			| _TRANSIENT 
			{ pNode ls[1]= {$<pnode>1};  $<pnode>$=MNNA(1,modifier);}
			| _SYNCHRONIZED
			{ pNode ls[1]= {$<pnode>1};  $<pnode>$=MNNA(1,modifier);}
			;
//  接口多个
implements	
			:  implements _COMMA class_name
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,implements);}
			| class_name
			{ pNode ls[1]= {$<pnode>1};  $<pnode>$=MNNA(1,implements);}
			;
//  领域声明多个			
field_declarations
			: field_declarations field_declaration
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,field_declarations);}
			|
			 { pNode *ls=NULL;  $<pnode>$=MNNA(0,field_declarations);}
			;
//  领域: 	方法 |构造函数
field_declaration		
			: method_declaration
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,field_declaration);}
			| constructor_declaration
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,field_declaration);}
			| variable_declaration
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,field_declaration);}
			| static_initializer 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,field_declaration);}
			| _SEMICOLON
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,field_declaration);}
			;
//  方法声明		虽然java可以 int a()[] {}写返回数组...但是基本没人这么用就按正常写法	这个写法就和int[] a;与int a[];一样，是c的写法之一，总维度为前后和
//  前缀 类型 标识符 ( [参数] )  ;或者 定义块
method_declaration			
			: modifiers type _SYMBOL _LPARENTHESE parameter_list _RPARENTHESE statement_block 
			{ pNode ls[7]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7};  $<pnode>$=MNNA(7,method_declaration);}
			| modifiers type _SYMBOL _LPARENTHESE  _RPARENTHESE statement_block 
			{ pNode ls[6]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6};  $<pnode>$=MNNA(6,method_declaration);}
			| modifiers type _SYMBOL _LPARENTHESE parameter_list _RPARENTHESE _SEMICOLON
			{ pNode ls[7]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7};  $<pnode>$=MNNA(7,method_declaration);}
			| modifiers type _SYMBOL _LPARENTHESE  _RPARENTHESE _SEMICOLON 
			{ pNode ls[6]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6};  $<pnode>$=MNNA(6,method_declaration);}
			;
// 类型 含数组			
type
			: type_specifier brackets
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,type);}
			;
// []多个  java的数组声明为 arrayRefVar[] = new dataType[arraySize];
brackets   
			: brackets _LBRACKET _RBRACKET
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,brackets);}
			| 
			 { pNode *ls=NULL;  $<pnode>$=MNNA(0,brackets);}
			;
// 类型
type_specifier
			: _BOOLEAN 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,type_specifier);}
			| _BYTE 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,type_specifier);}
			| _CHAR 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,type_specifier);}
			| _DOUBLE 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,type_specifier);}
			| _FLOAT 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,type_specifier);}
			| _INT 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,type_specifier);}
			| _LONG 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,type_specifier);}
			| _SHORT 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,type_specifier);}
			| _VOID 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,type_specifier);}
			| _STRING
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,type_specifier);}
			| class_name 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,type_specifier);}
			;
// 参数列表	:参数 	{,参数}	
parameter_list
			: parameter
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,parameter_list);}
			| parameter_list _COMMA parameter
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,parameter_list);}
			;

// 参数		: 类型 标识符  | 类型 标识符 []	
parameter
			: type _SYMBOL brackets
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,parameter);}
			;
// 声明块   :  { 声明多个 }			
statement_block
			: _LBRACE statements _RBRACE
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,statement_block);}
			;
// 声明 0-n			
statements	: statements statement
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,statements);}
			|
			 { pNode *ls=NULL;  $<pnode>$=MNNA(0,statements);}
			;
// 声明	这个词在这里叫陈述好点	
// 	变量声明|表达式|声明块|if句|do句|while句|for句|try句|switch句|synchronized块|return|throw|标记|break|continue|;
statement
			: variable_declaration 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,statement);}
			| expression _SEMICOLON
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,statement);}
			| statement_block
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,statement);}
			| if_statement
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,statement);}
			| do_statement 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,statement);}
			| while_statement
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,statement);}
			| for_statement
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,statement);}
			| try_statement
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,statement);}
			| switch_statement
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,statement);}
			| _SYNCHRONIZED _LPARENTHESE expression _RPARENTHESE statement_block
			{ pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MNNA(5,statement);}
			| _RETURN expression _SEMICOLON
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,statement);}
			| _RETURN  _SEMICOLON
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,statement);}
			| _THROW expression _SEMICOLON
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,statement);}
			| _SYMBOL _COLON statement
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,statement);}
			| _BREAK _SYMBOL _SEMICOLON
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,statement);}
			| _BREAK  _SEMICOLON
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,statement);}
			| _CONTINUE _SEMICOLON
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,statement);}
			| _CONTINUE _SYMBOL _SEMICOLON
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,statement);}
			| _SEMICOLON
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,statement);}
			;
// 变量声明	: 前缀 种类 变量式1-n	;	
variable_declaration
			: modifiers type variable_declarators _SEMICOLON
			{ pNode ls[4]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4};  $<pnode>$=MNNA(4,variable_declaration);}
			;
// 变量式 1-n以,分割			
variable_declarators
			: variable_declarator 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,variable_declarators);}
			| variable_declarator _COMMA variable_declarators
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,variable_declarators);}
			;
// 变量式	符号 []0-n | 符号 []0-n = 变量初始化器
variable_declarator
			: _SYMBOL brackets _MOV variable_initializer
			{ pNode ls[4]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4};  $<pnode>$=MNNA(4,variable_declarator);}
			| _SYMBOL brackets
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,variable_declarator);}
			;
// 变量初始化器
variable_initializer
			: expression 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,variable_initializer);}
			| _LBRACE  _RBRACE
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,variable_initializer);}
			| _LBRACE variable_initializers _COMMA _RBRACE
			{ pNode ls[4]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4};  $<pnode>$=MNNA(4,variable_initializer);}
			| _LBRACE variable_initializers  _RBRACE
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,variable_initializer);}
			;
// 变量初始化器 1-n ,分割
variable_initializers
			: variable_initializer
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,variable_initializers);}
			| variable_initializers _COMMA variable_initializer
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,variable_initializers);}
			;
// 表达式 :数字表达式 |判断表达式| 逻辑表达式|位表达式|转化式|new式|常量式| null super this 标识符 (表达式)
//  	函数调用 | 数组 | 对象使用 |,|三元式    前面的什么什么式只是为了细分表达式而写的，也可以写在表达式里不过会显得太长
//  目前建议是按返回类型分组且不可以操作重复。具体的类型推断是在语义分析时
expression 
			: numeric_expression 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
			| testing_expression 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
			| logical_expression 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
// 			| string_expression 
//  			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
			| bit_expression 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
//  			| casting_expression 类型转化推到语义分析时做
//  			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
			| creating_expression 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
			| literal_expression 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
			| _NUL
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
			| _SUPER
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
			| _THIS
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
			| _SYMBOL  
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
			| _LPARENTHESE expression _RPARENTHESE
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,expression);}
			| expression _LPARENTHESE arglist _RPARENTHESE
			{ pNode ls[4]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4};  $<pnode>$=MNNA(4,expression);}
			| expression _LPARENTHESE  _RPARENTHESE
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,expression);}
			| expression _LBRACKET expression _RBRACKET
			{ pNode ls[4]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4};  $<pnode>$=MNNA(4,expression);}
			| expression _POINT expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,expression);}
			| expression _COMMA expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,expression);}
			| expression _INSTANCEOF class_name
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,expression);}
			| expression _DOUBT expression _COLON expression
			{ pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MNNA(5,expression);}
			;
//  数字表达式	一元-在此单独指定优先级
numeric_expression
			: _SUB expression %prec UMINUS
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,numeric_expression);}
			| _ADD2 expression
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,numeric_expression);}
			| _SUB2 expression
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,numeric_expression);}
			| expression _ADD2
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,numeric_expression);}
			| expression _SUB2
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,numeric_expression);}
			| expression _ADD expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,numeric_expression);}
			| expression _SUB expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,numeric_expression);}
			| expression _MUL expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,numeric_expression);}
			| expression _DIV expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,numeric_expression);}
			| expression _MOD expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,numeric_expression);}
			| expression _ADDMOV expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,numeric_expression);}
			| expression _SUBMOV expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,numeric_expression);}
			| expression _MULMOV expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,numeric_expression);}
			| expression _DIVMOV expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,numeric_expression);}
			| expression _MODMOV expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,numeric_expression);}
			| expression _MOV expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,numeric_expression);}
			;
			
// 判断表达式	_CMP _NCMP _MORE _LESS _MCMP _LCMP		
testing_expression
			: expression _CMP expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,testing_expression);}
			| expression _NCMP expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,testing_expression);}
			| expression _MORE expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,testing_expression);}
			| expression _LESS expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,testing_expression);}
			| expression _MCMP expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,testing_expression);}
			| expression _LCMP expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,testing_expression);}
			;
// 逻辑表达式	一般的位操作符也可以作用于逻辑操作  文档中对此描述不是很好
// 这里我将常见作用于逻辑操作的识别出  其它的在位操作时判断
logical_expression		
			: _BNOT expression
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,logical_expression);}
			| expression _BAND  expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,logical_expression);}
			| expression _BOR expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,logical_expression);}
			| _TRUE 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,logical_expression);}
			| _FALSE
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,logical_expression);}
			;
// 位表达式   & | ^ ~ << >> >>>
//  _SHLMOV _SHRMOV _ANDMOV _XORMOV _ORMOV
bit_expression
			: _NOT expression 
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,bit_expression);}
			| expression _AND expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,bit_expression);}
			| expression _OR expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,bit_expression);}
			| expression _XOR expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,bit_expression);}
			| expression _SHL expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,bit_expression);}
			| expression _SHR expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,bit_expression);}
			| expression _SAR expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,bit_expression);}
			| expression _SHLMOV expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,bit_expression);}
			| expression _SHRMOV expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,bit_expression);}
			| expression _ANDMOV expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,bit_expression);}
			| expression _XORMOV expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,bit_expression);}
			| expression _ORMOV expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,bit_expression);}
			;

// 字串表达式 归于数字表达式中，否则会产生冲突
/*  
string_expression
			: expression _ADD expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,string_expression);}
			| expression _ADDMOV expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,string_expression);}
			;
*/
/*
// 类型转化			// 这里存在一个归约错误...因为无法区分单个的classname和标识符
casting_expression
			: _LPARENTHESE type _RPARENTHESE expression 
			{ pNode ls[4]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4};  $<pnode>$=MNNA(4,casting_expression);}
			;
*/
// new 表达式  java数组大小的确定是在这里....
creating_expression	
			: _NEW class_name _LPARENTHESE _RPARENTHESE
			{ pNode ls[4]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4};  $<pnode>$=MNNA(4,creating_expression);}
			| _NEW class_name _LPARENTHESE arglist _RPARENTHESE
			{ pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MNNA(5,creating_expression);}
			| _NEW type_specifier bracketnums
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,creating_expression);}
			;
bracketnums
			: bracketnums _LBRACKET expression _RBRACKET
			{ pNode ls[4]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4};  $<pnode>$=MNNA(4,bracketnums);}
			|
			 { pNode *ls=NULL;  $<pnode>$=MNNA(0,bracketnums);}
			;
// 参数1-n个
arglist
			: expression
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,arglist);}
			| arglist _COMMA expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,arglist);}
			;
// 常量表达式  字符 字符串 整数 浮点数
literal_expression
			: _CUSTCHAR
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,literal_expression);}
			| _CUSTSTRING
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,literal_expression);}
			| _CUSTINT
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,literal_expression);}
			| _CUSTFLOAT
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,literal_expression);}
			;
// if句  这里就这么写，因为statement可以直接为if_statement，因此else后可直接识别出if形成else if
if_statement
			: _IF _LPARENTHESE expression _RPARENTHESE statement 
			{ pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MNNA(5,if_statement);}
			| _IF _LPARENTHESE expression _RPARENTHESE statement _ELSE statement
			{ pNode ls[7]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7};  $<pnode>$=MNNA(7,if_statement);}
			;
// do while 句
do_statement
			: _DO statement _WHILE _LPARENTHESE expression _RPARENTHESE _SEMICOLON
			{ pNode ls[7]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7};  $<pnode>$=MNNA(7,do_statement);}
			;
// while句
while_statement
			: _WHILE _LPARENTHESE expression _RPARENTHESE statement
			{ pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MNNA(5,while_statement);}
			;
// for语句  迭代器就不实现了...
for_statement
			: _FOR _LPARENTHESE expression01 _SEMICOLON expression01 _SEMICOLON expression01 _RPARENTHESE statement
			{ pNode ls[9]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7,$<pnode>8,$<pnode>9};  $<pnode>$=MNNA(9,for_statement);}
			| _FOR _LPARENTHESE variable_declaration expression01 _SEMICOLON expression01 _RPARENTHESE statement
			{ pNode ls[8]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7,$<pnode>8};  $<pnode>$=MNNA(8,for_statement);}
			;
expression01
			: expression
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression01);}
			|
			 { pNode *ls=NULL;  $<pnode>$=MNNA(0,expression01);}
			;
// try语句
try_statement
			: _TRY statement catchs _FINALLY statement
			{ pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MNNA(5,try_statement);}
			| _TRY statement catchs
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,try_statement);}
			;
// catch0-n
catchs
			: catchs _CATCH _LPARENTHESE parameter _RPARENTHESE statement
			{ pNode ls[6]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6};  $<pnode>$=MNNA(6,catchs);}
			|
			 { pNode *ls=NULL;  $<pnode>$=MNNA(0,catchs);}
			;
// switch语句
switch_statement
			: _SWITCH _LPARENTHESE expression _RPARENTHESE _LBRACE cases _RBRACE
			{ pNode ls[7]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7};  $<pnode>$=MNNA(7,switch_statement);}
			;
cases
			: cases _CASE expression _COLON
			{ pNode ls[4]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4};  $<pnode>$=MNNA(4,cases);}
			| cases _DEFAULT _COLON
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,cases);}
			| cases statement
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,cases);}
			| 
			 { pNode *ls=NULL;  $<pnode>$=MNNA(0,cases);}
			;
// 构造函数
constructor_declaration
			: modifiers _SYMBOL _LPARENTHESE parameter_list _RPARENTHESE statement_block 
			{ pNode ls[6]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6};  $<pnode>$=MNNA(6,constructor_declaration);}
			| modifiers _SYMBOL _LPARENTHESE _RPARENTHESE statement_block 
			{ pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MNNA(5,constructor_declaration);}
			;
// 静态初始化器
static_initializer
			: _STATIC statement_block 
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,static_initializer);}
			;
// 接口声明  这里没写错，就用extends
interface_declaration
			: modifiers _INTERFACE _SYMBOL _EXTENDS implements _LBRACE field_declarations _RBRACE
			{ pNode ls[8]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7,$<pnode>8};  $<pnode>$=MNNA(8,interface_declaration);}
			| modifiers _INTERFACE _SYMBOL _LBRACE field_declarations _RBRACE
			{ pNode ls[6]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6};  $<pnode>$=MNNA(6,interface_declaration);}
			;






%%

int yyerror(char *s) {
	printf("Gramma analysis error %s  on %d :%s\n",s,line,yytext);
    return 0;
}
























