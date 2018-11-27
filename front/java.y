

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
	
	
	
	int yyerror(char *s);
	
	
%}
//--------------------------------------------------------------------------------------
//����YYSTYPE���ݵ�����
//ÿ��YYSTYPE����һ���ڵ�
%union{
	pNode pnode;
}



//���忪ʼ����
%start CLASSFILE


//����token�ս��,���ﶨ��ľ��Ƕ�Ԫʽ<�ֱ��룬����ֵ>���ֱ��룬lex�з��ظ����ͣ�����yacc�����ı�ʾ�Ǻ궨�����
//��Ϊ������ֱȽ�������˲���_��ͷ

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
//����� ��� ������Ԫ
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

//��ʶ��  ����ֵָ����ű�
%token <pnode>  _SYMBOL
//��������  �ֱ���   ���ж����ִ�С��ȫ����4λ���δ���  ����ȫ����float����
%token <pnode>  _CUSTCHAR  //' '
%token <pnode>	_CUSTSTRING//�ַ���
%token <pnode>	_CUSTINT   //����
%token <pnode>	_CUSTFLOAT //������


//���ս������
%type <pnode>  CLASSFILE












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
//bnf�ķ�����
CLASSFILE
	: _CUSTINT {printf("%s\n",$<pnode>1->leafstring);}










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






















