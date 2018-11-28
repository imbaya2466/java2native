

//�﷨����yacc����
//һ������ջ��һ������ջ������ջ�б������ս���ͷ��ս���� ���Ҵ���ǰ����״̬������ջ��һ�� YYSTYPE Ԫ�ص����飬���ڷ���ջ�е�ÿһ��Ԫ�ض�������һ����Ӧ��ֵ��
//lex return�����ͽ������ջ--lex�����ս��һ�����﷨������yylval��������ջ��$$���ʵ�������ջ,������ΪYYSTYPE�����������ķ������ԣ���Ҫ��һ�µ�6���ٶ��壩
//����ջ���Ǳ���ԭ����LR�õķ���ջ�������﷨����Ҳ���������ջ��״̬ջ��yacc�Զ�ά��
%{
	
    #include <stdio.h>
    #include <string.h>
	#include "tool/tree.h"	
	
	//extern��ָ����(����ռ�)�������ط������������붨���Ƿֿ���ͨ������ʹ����˶����ü�extren������Ϊ�������������Ҫ�ӡ�
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
//����YYSTYPE���ݵ�����
//ÿ��YYSTYPE����һ���ڵ�
%union{
	pNode pnode;
}



//���忪ʼ����
%start compilation_unit


//����token�ս��,���ﶨ��ľ��Ƕ�Ԫʽ<�ֱ��룬����ֵ>���ֱ��룬lex�з��ظ����ͣ�����yacc�����ı�ʾ�Ǻ궨�����
//��Ϊ������ֱȽ�������˲���_��ͷ  ʡ������Ԫ��@

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


//���ս������

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
//---------2018.11.27�����Խ�enum










//�������ȼ����壬�˴����������������  һԪ��+-������ֵ�У����ȼ���
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
//bnf�ķ����� �ⲿ���ظ�����϶���ʵ�궨��ʡ�£�����Ϊ�˷�������﷨���ÿ����������������ɹ�����ú꣡�������ظ���̫����
//���˽�LR������Ĺ���
// ��  ����  �������� | ���� ��������
//native����ע����ʵ����Ҫ��������...�������ð�
compilation_unit 	
			: package_statement import_statement type_declaration 
				{  pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  root=MakeNodeNoAtt(3,ls,compilation_unit,"compilation_unit"); }
			| import_statement type_declaration 
				{  pNode ls[2]={$<pnode>1,$<pnode>2};  root=MakeNodeNoAtt(2,ls,compilation_unit,"compilation_unit"); }
			;
//��: package ���� ;
package_statement 
			: _PACKAGE package_name _SEMICOLON
				{  pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MakeNodeNoAtt(3,ls,package_statement,"package_statement"); }
			;
//����: ��ʶ�� | ���� . ��ʶ��
package_name
			: _SYMBOL
				{  pNode ls[1]={$<pnode>1};  $<pnode>$=MakeNodeNoAtt(1,ls,package_name,"package_name"); }
			| package_name _POINT _SYMBOL
				{  pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MakeNodeNoAtt(3,ls,package_name,"package_name"); }
			;
//�������� : import ���� . * ; | import ���� ; | import �ӿ��� ;			
import_statement
			: _IMPORT package_name _POINT _MUL _SEMICOLON
				{  pNode ls[5]={$<pnode>1,$<pnode>2,$<pnode>3,$<pnode>4,$<pnode>5};  $<pnode>$=MakeNodeNoAtt(5,ls,import_statement,"import_statement"); }
			| _IMPORT class_name _SEMICOLON
				{  pNode ls[3]={$<pnode>1,$<pnode>2,$<pnode>3};  $<pnode>$=MakeNodeNoAtt(3,ls,import_statement,"import_statement"); }
			;
//���� : ��ʶ�� | ����.��ʶ��
class_name 		
			: _SYMBOL
				{  pNode ls[1]={$<pnode>1};  $<pnode>$=MakeNodeNoAtt(1,ls,class_name,"class_name"); }
			| package_name _POINT _SYMBOL
				{  pNode ls[2]={$<pnode>1,$<pnode>2};  $<pnode>$=MakeNodeNoAtt(3,ls,class_name,"class_name"); }
			;

//---------------------����ͷ���ֽ������
			
//������������  ����һ���ļ���ֻ����һ�����ӿ�
type_declaration
			: class_declaration
				{  pNode ls[1]={$<pnode>1};  $<pnode>$=MakeNodeNoAtt(1,ls,type_declaration,"type_declaration"); }
			| interface_declaration 
			;
//������: 	{modifier}	class ��ʶ�� [extends ����] [implements �ӿ���] {����}
class_declaration
			: modifiers _CLASS _SYMBOL _EXTENDS class_name _IMPLEMENTS implements _LBRACE field_declarations _RBRACE
			| modifiers _CLASS _SYMBOL  _IMPLEMENTS implements _LBRACE field_declarations _RBRACE
			| modifiers _CLASS _SYMBOL  _LBRACE field_declarations _RBRACE
			;
//ǰ׺�ɶ��
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
//�ӿڶ��
implements	
			:  implements _COMMA class_name
			| class_name
			;
			
//----------------��������
//�����������			
field_declarations
			: field_declarations field_declaration
			|
			;
//����: 	--------------------����δ���		
field_declaration		
			: method_declaration
			| //constructor_declaration
			| //variable_declaration
			| //static_initializer 
			| //_SEMICOLON
			;
//��������		��Ȼjava���� int a()[] {}д��������...���ǻ���û����ô�þͰ�����д��	
// ǰ׺ ���� ��ʶ�� ( [����] )  ;���� �����
method_declaration			
			: modifiers type _SYMBOL _LPARENTHESE parameter_list _RPARENTHESE statement_block 
			| modifiers type _SYMBOL _LPARENTHESE  _RPARENTHESE statement_block 
			| modifiers type _SYMBOL _LPARENTHESE parameter_list _RPARENTHESE _SEMICOLON
			| modifiers type _SYMBOL _LPARENTHESE  _RPARENTHESE _SEMICOLON 
			;
//���� ������			
type
			: type_specifier 
			| type_specifier  brackets
			;
//[]���
brackets   
			: brackets _LBRACKET _RBRACKET
			| _LBRACKET _RBRACKET
			;
//����
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

//��ʱ�����ã�
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






















