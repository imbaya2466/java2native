

//�﷨����yacc����
//һ������ջ��һ������ջ������ջ�б������ս���ͷ��ս���� ���Ҵ���ǰ����״̬������ջ��һ�� YYSTYPE Ԫ�ص����飬���ڷ���ջ�е�ÿһ��Ԫ�ض�������һ����Ӧ��ֵ��
//lex return�����ͽ������ջ--lex�����ս��һ�����﷨������yylval��������ջ��$$���ʵ�������ջ,������ΪYYSTYPE�����������ķ������ԣ���Ҫ��һ�µ�6���ٶ��壩
//����ջ���Ǳ���ԭ����LR�õķ���ջ�������﷨����Ҳ���������ջ��״̬ջ��yacc�Զ�ά��
%{
	
    #include <stdio.h>
    #include <string.h>
	#include "tool/tree.h"	
	//�﷨�������ú�  #Ϊ�ַ�����
	#define MNNA(i,x) MakeNodeNoAtt(i,ls,x,#x)
	
	//extern��ָ����(����ռ�)�������ط������������붨���Ƿֿ���ͨ������ʹ����˶����ü�extren������Ϊ�������������Ҫ�ӡ�
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
//--------------------------------------------------------------------------------------
//����YYSTYPE���ݵ�����
//ÿ��YYSTYPE����һ���ڵ�
%union{
	pNode pnode;
}



//���忪ʼ����
%start compilation_unit


//����token�ս��,���ﶨ��ľ��Ƕ�Ԫʽ<�ֱ��룬����ֵ>���ֱ��룬lex�з��ظ����ͣ�����yacc�����ı�ʾ�Ǻ궨�����
//��Ϊ������ֱȽ�������˲���_��ͷ  ʡ����@

//�����
%token <pnode> _PRIVATE _PROTECTED _PUBLIC _ABSTRACT _EXTENDS _FINAL _IMPLEMENTS _NATIVE _NEW _STATIC _STRICTFP _TRANSIENT  _VOLATILE
//�������
%token <pnode> 	_BREAK _CONTINUE _RETURN _DO _WHILE _IF _ELSE _FOR _INSTANCEOF _SWITCH _CASE _DEFAULT _TRY _CATCH _FINALLY _THROW _THROWS _ASSERT _SYNCHRONIZED
//��
%token <pnode> 	_IMPORT _PACKAGE 
//���� String���ǹؼ��֣���java�����﷨���������
%token <pnode>  _BOOLEAN _BYTE _CHAR _DOUBLE _FLOAT _INT _LONG _SHORT _VOID _STRING _ENUM _CLASS _INTERFACE
//����ֵ
%token <pnode> 	_TRUE _FALSE _NUL _SUPER _THIS
//����� ��� 
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
//���   {} [] ()  ;  ,  .
%token <pnode>	_LBRACE _RBRACE _LBRACKET _RBRACKET _LPARENTHESE _RPARENTHESE _SEMICOLON _COMMA _POINT
//����  ?  :
%token <pnode>  _DOUBT _COLON
//��ʶ��  ����ֵָ����ű�
%token <pnode>  _SYMBOL
//��������  �ֱ���   ���ж����ִ�С��ȫ����4λ���δ���  ����ȫ����float����
%token <pnode>  _CUSTCHAR  //' '
%token <pnode>	_CUSTSTRING//�ַ���
%token <pnode>	_CUSTINT   //����
%token <pnode>	_CUSTFLOAT //������
//lex���᷵�صģ����ڸ������ȼ�ָ��
%token UMINUS


//���ս������

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
//%type <pnode>  string_expression  
%type <pnode>  casting_expression 
%type <pnode>  creating_expression 
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









//�������ȼ����壬�˴����������������  һԪ��+-���﷨����ʱ�ж�  ����Ϊ�͵���
//���ȼ��ı�ʾ�������﷨Ҳ��������������ʾ����������ʡȥ�ܶ��﷨˵��
//ע�⣬��bison�����﷨����ʱ������ͻʱ��������ȼ����������ͻ��
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
%left	_POINT _RBRACE _LBRACKET _RBRACKET _LPARENTHESE


//--------------------------------------------------------------------------------------

%%
//bnf�ķ����� �ⲿ���ظ�����϶���ʵ�궨��ʡ�£�����Ϊ�˷�������﷨���ÿ����������������ɹ�����ú꣡�������ظ���̫����
//���˽�LR������Ĺ���  �Ȳ���������﷨�����ٷ������������ֵĳ����﷨����Ϊ����������native�������ֿ��Զ�������
//�Խ���Լ��ͻĬ���Խ�����Լ��Լ��ͻ���ȳ��ֵ�   �ı�Ĭ�Ϸ�ʽΪ�����ȼ���(ͬ���ȼ�������)���ȹ�Լ
//0: { pNode ls=NULL;  $<pnode>$=MNNA(0,compilation_unit);}
//1: { pNode ls[1]={$<pnode>1};  $<pnode>$=MNNA(1,compilation_unit);}
//2: { pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,compilation_unit);}
//3: { pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,compilation_unit);}
//4: { pNode ls[4]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4};  $<pnode>$=MNNA(4,compilation_unit);}
//5: { pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MNNA(5,compilation_unit);}
//6: { pNode ls[6]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6};  $<pnode>$=MNNA(6,compilation_unit);}
//7: { pNode ls[7]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7};  $<pnode>$=MNNA(7,compilation_unit);}
//8: { pNode ls[8]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7,$<pnode>8};  $<pnode>$=MNNA(8,compilation_unit);}
//9: { pNode ls[9]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7,$<pnode>8,$<pnode>9};  $<pnode>$=MNNA(9,compilation_unit);}
//10: { pNode ls[10]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7,$<pnode>8,$<pnode>9,$<pnode>10};  $<pnode>$=MNNA(10,compilation_unit);}


// ��  ����  �������� | ���� ��������
//native����ע����ʵ����Ҫ��������...�������ð�
compilation_unit 	
			: package_statement import_statements type_declarations  
				{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  root=MNNA(3,compilation_unit);}
			| import_statements type_declarations 
				{ pNode ls[2]={$<pnode>1,$<pnode>2};  root=MNNA(2,compilation_unit);}
			;
//��������0-n
import_statements
			: import_statements import_statement
				{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,import_statements);}
			| 
				{ pNode *ls=NULL;  $<pnode>$=MNNA(0,import_statements);}
			;
//��������0-n
type_declarations
			: type_declarations type_declaration
				{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,type_declarations);}
			|
				{ pNode *ls=NULL;  $<pnode>$=MNNA(0,type_declarations);}
			;
//��: package ���� ;
package_statement 
			: _PACKAGE class_name _SEMICOLON
				{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,package_statement);}
			;

//�������� : import ���� . * ; | import ���� ; | import �ӿ��� ;			
import_statement
			: _IMPORT class_name _POINT _MUL _SEMICOLON
			{ pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MNNA(5,import_statement);}
			| _IMPORT class_name _SEMICOLON
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,import_statement);}
			;
//���� : ��ʶ�� | ����.��ʶ��
class_name 		
			: _SYMBOL
			{ pNode ls[1]={$<pnode>1};  $<pnode>$=MNNA(1,class_name);}
			| class_name _POINT _SYMBOL
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,class_name);}
			;

			
			
//-----------------------------------------����Ϊ�ļ�ͷ��������			
			
//������������  
type_declaration
			: class_declaration
			{ pNode ls[1]={$<pnode>1};  $<pnode>$=MNNA(1,type_declaration);}
			| interface_declaration
			{ pNode ls[1]={$<pnode>1};  $<pnode>$=MNNA(1,type_declaration);}
			;
//������: 	{modifier}	class ��ʶ�� [extends ����] [implements �ӿ���] {����}
class_declaration
			: modifiers _CLASS _SYMBOL _EXTENDS class_name _IMPLEMENTS implements _LBRACE field_declarations _RBRACE
			{ pNode ls[10]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7,$<pnode>8,$<pnode>9,$<pnode>10};  $<pnode>$=MNNA(10,class_declaration);}
			| modifiers _CLASS _SYMBOL  _IMPLEMENTS implements _LBRACE field_declarations _RBRACE
			{ pNode ls[8]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7,$<pnode>8};  $<pnode>$=MNNA(8,class_declaration);}
			| modifiers _CLASS _SYMBOL  _LBRACE field_declarations _RBRACE
			{ pNode ls[6]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6};  $<pnode>$=MNNA(6,class_declaration);}
			;
//ǰ׺0-���
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
//�ӿڶ��
implements	
			:  implements _COMMA class_name
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,implements);}
			| class_name
			{ pNode ls[1]= {$<pnode>1};  $<pnode>$=MNNA(1,implements);}
			;
//�����������			
field_declarations
			: field_declarations field_declaration
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,field_declarations);}
			|
			 { pNode *ls=NULL;  $<pnode>$=MNNA(0,field_declarations);}
			;
//����: 	���� |���캯��
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
//��������		��Ȼjava���� int a()[] {}д��������...���ǻ���û����ô�þͰ�����д��	
// ǰ׺ ���� ��ʶ�� ( [����] )  ;���� �����
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
//���� ������			
type
			: type_specifier brackets
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,type);}
			;
//[]���
brackets   
			: brackets _LBRACKET _RBRACKET
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,brackets);}
			| 
			 { pNode *ls=NULL;  $<pnode>$=MNNA(0,brackets);}
			;
//����
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
//�����б�	:���� 	{,����}	
parameter_list
			: parameter
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,parameter_list);}
			| parameter_list _COMMA parameter
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,parameter_list);}
			;

//����		: ���� ��ʶ��  | ���� ��ʶ�� []	
parameter
			: type _SYMBOL brackets
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,parameter);}
			;
//������   :  { ������� }			
statement_block
			: _LBRACE statements _RBRACE
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,statement_block);}
			;
//���� 0-n			
statements	: statements statement
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,statements);}
			|
			 { pNode *ls=NULL;  $<pnode>$=MNNA(0,statements);}
			;
//����	�����������г����õ�	
//	��������|���ʽ|������|if��|do��|while��|for��|try��|switch��|synchronized��|return|throw|���|break|continue|;
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
//��������	: ǰ׺ ���� ����ʽ1-n	;	
variable_declaration
			: modifiers type variable_declarators _SEMICOLON
			{ pNode ls[4]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4};  $<pnode>$=MNNA(4,variable_declaration);}
			;
//����ʽ 1-n��,�ָ�			
variable_declarators
			: variable_declarator 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,variable_declarators);}
			| variable_declarators _COMMA variable_declarator
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,variable_declarators);}
			;
//����ʽ	���� []0-n | ���� []0-n = ������ʼ����
variable_declarator
			: _SYMBOL brackets _MOV variable_initializer
			{ pNode ls[4]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4};  $<pnode>$=MNNA(4,variable_declarator);}
			| _SYMBOL brackets
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,variable_declarator);}
			;
//������ʼ����
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
//������ʼ���� 1-n ,�ָ�
variable_initializers
			: variable_initializer
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,variable_initializers);}
			| variable_initializers _COMMA variable_initializer
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,variable_initializers);}
			;
//���ʽ :���ֱ��ʽ |�жϱ��ʽ| �߼����ʽ|λ���ʽ|ת��ʽ|newʽ|����ʽ| null super this ��ʶ�� (���ʽ)
// 	�������� | ���� | ����ʹ�� |,|��Ԫʽ    ǰ���ʲôʲôʽֻ��Ϊ��ϸ�ֱ��ʽ��д�ģ�Ҳ����д�ڱ��ʽ�ﲻ�����Ե�̫��
// Ŀǰ�����ǰ��������ͷ����Ҳ����Բ����ظ�������������ƶ������������ʱ
expression 
			: numeric_expression 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
			| testing_expression 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
			| logical_expression 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
//			| string_expression 
//			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
			| bit_expression 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
			| casting_expression 
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,expression);}
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
//���ֱ��ʽ	һԪ-�ڴ˵���ָ�����ȼ�
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
			
//�жϱ��ʽ	_CMP _NCMP _MORE _LESS _MCMP _LCMP		
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
//�߼����ʽ	һ���λ������Ҳ�����������߼�����  �ĵ��жԴ��������Ǻܺ�
//�����ҽ������������߼�������ʶ���  ��������λ����ʱ�ж�
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
//λ���ʽ   & | ^ ~ << >> >>>
// _SHLMOV _SHRMOV _ANDMOV _XORMOV _ORMOV
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

//�ִ����ʽ �������ֱ��ʽ�У�����������ͻ
/*  
string_expression
			: expression _ADD expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,string_expression);}
			| expression _ADDMOV expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,string_expression);}
			;
*/
//����ת��			//�������һ����Լ����...��Ϊ�޷����ֵ�����classname�ͱ�ʶ��
casting_expression
			: _LPARENTHESE type _RPARENTHESE expression 
			{ pNode ls[4]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4};  $<pnode>$=MNNA(4,casting_expression);}
			;
//new ���ʽ
creating_expression	
			: _NEW class_name _LPARENTHESE _RPARENTHESE
			{ pNode ls[4]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4};  $<pnode>$=MNNA(4,creating_expression);}
			| _NEW class_name _LPARENTHESE arglist _RPARENTHESE
			{ pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MNNA(5,creating_expression);}
			| _NEW type_specifier _LBRACKET expression _RBRACKET brackets
			{ pNode ls[6]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6};  $<pnode>$=MNNA(6,creating_expression);}
			| _NEW type_specifier brackets
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,creating_expression);}
			;
//����1-n��
arglist
			: expression
			{ pNode ls[1]=  {$<pnode>1};  $<pnode>$=MNNA(1,arglist);}
			| arglist _COMMA expression
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,arglist);}
			;
//�������ʽ  �ַ� �ַ��� ���� ������
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
//if��  �������ôд����Ϊstatement����ֱ��Ϊif_statement�����else���ֱ��ʶ���if�γ�else if
if_statement
			: _IF _LPARENTHESE expression _RPARENTHESE statement 
			{ pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MNNA(5,if_statement);}
			| _IF _LPARENTHESE expression _RPARENTHESE statement _ELSE statement
			{ pNode ls[7]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7};  $<pnode>$=MNNA(7,if_statement);}
			;
//do while ��
do_statement
			: _DO statement _WHILE _LPARENTHESE expression _RPARENTHESE _SEMICOLON
			{ pNode ls[7]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6,$<pnode>7};  $<pnode>$=MNNA(7,do_statement);}
			;
//while��
while_statement
			: _WHILE _LPARENTHESE expression _RPARENTHESE statement
			{ pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MNNA(5,while_statement);}
			;
//for���  �������Ͳ�ʵ����...
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
//try���
try_statement
			: _TRY statement catchs _FINALLY statement
			{ pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MNNA(5,try_statement);}
			| _TRY statement catchs
			{ pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MNNA(3,try_statement);}
			;
//catch0-n
catchs
			: catchs _CATCH _LPARENTHESE parameter _RPARENTHESE statement
			{ pNode ls[6]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6};  $<pnode>$=MNNA(6,catchs);}
			|
			 { pNode *ls=NULL;  $<pnode>$=MNNA(0,catchs);}
			;
//switch���
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
//���캯��
constructor_declaration
			: modifiers _SYMBOL _LPARENTHESE parameter_list _RPARENTHESE statement_block 
			{ pNode ls[6]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5,$<pnode>6};  $<pnode>$=MNNA(6,constructor_declaration);}
			| modifiers _SYMBOL _LPARENTHESE _RPARENTHESE statement_block 
			{ pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MNNA(5,constructor_declaration);}
			;
//��̬��ʼ����
static_initializer
			: _STATIC statement_block 
			{ pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MNNA(2,static_initializer);}
			;
//�ӿ�����  ����ûд������extends
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
























