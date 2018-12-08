%{
    #include <string.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include "tool/tree.h"//因为下部分依赖此，因此置于前
	#include "java.tab.h"//这里的yylval类型定义很不稳定...在java.y中未定义时这里就可能先定义成int了。因此直接定义为union
	
	
    int line = 1;//lex其实有自己的行号。需要时改用

	

	int symbolnum=0;
	int floatnum=0;
	int intnum=0;
	int stringnum=0;
	int charnum=0;
	
	pNode savesymbol();
	pNode savechars();
	pNode saveIntegers();
	pNode savefloats();
	pNode savestrings();
	pNode doyylval(int type);
	
%}

/*正则优先级：()[] >  *+?  个数 >  字符连接  >  |
转义有俩种方式："xxx"或者\x  ""内的内容作为字符匹配*/
/*数字的正负不能在这里匹配，最长匹配原则会使 3-2匹配为 3  -2   一元还是二元的分析在语法分析*/
/*嵌套的注释java语法中也是不允许的,况且嵌套在这里会因为最长匹配而匹配到头,因此处理行数问题其它没事*/
letter                      [a-zA-Z]
digit                       [0-9]
anychar                     {letter}|{digit}|"_"
space                       [ \t\r]+
enter						\n
paragraphComments           "/*"(.|\n)*"*/"
lineComments                "//".*\n


symbol						({letter}|"_"){anychar}*

Integers					{digit}+				
floats						{digit}+"."{digit}*|"."{digit}+
chars						\'.\'
string						\".*\"






%%
{paragraphComments} {/* skip */}
{lineComments}      {/* skip */line++;}
{space}             {/* skip */}
{enter}				{line++;}
"private"			{yylval.pnode = doyylval(_PRIVATE);  return _PRIVATE;}
"protected"			{yylval.pnode = doyylval(_PROTECTED);  return _PROTECTED;}
"public"			{yylval.pnode = doyylval(_PUBLIC);  return _PUBLIC;}
"abstract"			{yylval.pnode = doyylval(_ABSTRACT);  return _ABSTRACT;}
"extends"			{yylval.pnode = doyylval(_EXTENDS);  return _EXTENDS;}
"final"				{yylval.pnode = doyylval(_FINAL);  return _FINAL;}
"implements"		{yylval.pnode = doyylval(_IMPLEMENTS);  return _IMPLEMENTS;}
"native"			{yylval.pnode = doyylval(_NATIVE);  return _NATIVE;}
"new"				{yylval.pnode = doyylval(_NEW);  return _NEW;}
"static"			{yylval.pnode = doyylval(_STATIC);  return _STATIC;}
"strictfp"			{yylval.pnode = doyylval(_STRICTFP);  return _STRICTFP;}
"transient"			{yylval.pnode = doyylval(_TRANSIENT);  return _TRANSIENT;}
"volatile"			{yylval.pnode = doyylval(_VOLATILE);  return _VOLATILE;}

"break"				{yylval.pnode = doyylval(_BREAK);  return _BREAK;}
"continue"			{yylval.pnode = doyylval(_CONTINUE);  return _CONTINUE;}
"return"			{yylval.pnode = doyylval(_RETURN);  return _RETURN;}
"do"				{yylval.pnode = doyylval(_DO);  return _DO;}
"while"				{yylval.pnode = doyylval(_WHILE);  return _WHILE;}
"if"				{yylval.pnode = doyylval(_IF);  return _IF;}
"else"				{yylval.pnode = doyylval(_ELSE);  return _ELSE;}
"for"				{yylval.pnode = doyylval(_FOR);  return _FOR;}
"instanceof"		{yylval.pnode = doyylval(_INSTANCEOF);  return _INSTANCEOF;}
"switch"			{yylval.pnode = doyylval(_SWITCH);  return _SWITCH;}
"case"				{yylval.pnode = doyylval(_CASE);  return _CASE;}
"default"			{yylval.pnode = doyylval(_DEFAULT);  return _DEFAULT;}
"try"				{yylval.pnode = doyylval(_TRY);  return _TRY;}
"catch"				{yylval.pnode = doyylval(_CATCH);  return _CATCH;}
"finally"			{yylval.pnode = doyylval(_FINALLY);  return _FINALLY;}
"throw"				{yylval.pnode = doyylval(_THROW);  return _THROW;}
"throws"			{yylval.pnode = doyylval(_THROWS);  return _THROWS;}
"assert"			{yylval.pnode = doyylval(_ASSERT);  return _ASSERT;}
"synchronized"		{yylval.pnode = doyylval(_SYNCHRONIZED);  return _SYNCHRONIZED;}

"import"			{yylval.pnode = doyylval(_IMPORT);  return _IMPORT;}
"package"			{yylval.pnode = doyylval(_PACKAGE);  return _PACKAGE;}

"boolean"			{yylval.pnode = doyylval(_BOOLEAN);  return _BOOLEAN;}
"byte"				{yylval.pnode = doyylval(_BYTE);  return _BYTE;}
"char"				{yylval.pnode = doyylval(_CHAR);  return _CHAR;}
"double"			{yylval.pnode = doyylval(_DOUBLE);  return _DOUBLE;}
"float"				{yylval.pnode = doyylval(_FLOAT);  return _FLOAT;}
"int"				{yylval.pnode = doyylval(_INT);  return _INT;}
"long"				{yylval.pnode = doyylval(_LONG);  return _LONG;}
"short"				{yylval.pnode = doyylval(_SHORT);  return _SHORT;}
"void"				{yylval.pnode = doyylval(_VOID);  return _VOID;}
"String"			{yylval.pnode = doyylval(_STRING);  return _STRING;}
"enum"				{yylval.pnode = doyylval(_ENUM);  return _ENUM;}
"class"				{yylval.pnode = doyylval(_CLASS);  return _CLASS;}
"interface"			{yylval.pnode = doyylval(_INTERFACE);  return _INTERFACE;}

"true"				{yylval.pnode = doyylval(_TRUE);  return _TRUE;}
"false"				{yylval.pnode = doyylval(_FALSE);  return _FALSE;}
"null"				{yylval.pnode = doyylval(_NUL);  return _NUL;}
"super"				{yylval.pnode = doyylval(_SUPER);  return _SUPER;}
"this"				{yylval.pnode = doyylval(_THIS);  return _THIS;}

"+"					{yylval.pnode = doyylval(_ADD);  return _ADD;}
"-"					{yylval.pnode = doyylval(_SUB);  return _SUB;}
"*"					{yylval.pnode = doyylval(_MUL);  return _MUL;}
"/"					{yylval.pnode = doyylval(_DIV);  return _DIV;}
"%"					{yylval.pnode = doyylval(_MOD);  return _MOD;}
"++"				{yylval.pnode = doyylval(_ADD2);  return _ADD2;}
"--"				{yylval.pnode = doyylval(_SUB2);  return _SUB2;}

"=="				{yylval.pnode = doyylval(_CMP);  return _CMP;}
"!="				{yylval.pnode = doyylval(_NCMP);  return _NCMP;}
">"					{yylval.pnode = doyylval(_MORE);  return _MORE;}
"<"					{yylval.pnode = doyylval(_LESS);  return _LESS;}
">="				{yylval.pnode = doyylval(_MCMP);  return _MCMP;}
"<="				{yylval.pnode = doyylval(_LCMP);  return _LCMP;}

"&"					{yylval.pnode = doyylval(_AND);  return _AND;}
"|"					{yylval.pnode = doyylval(_OR);  return _OR;}
"^"					{yylval.pnode = doyylval(_XOR);  return _XOR;}
"~"					{yylval.pnode = doyylval(_NOT);  return _NOT;}
"<<"				{yylval.pnode = doyylval(_SHL);  return _SHL;}
">>"				{yylval.pnode = doyylval(_SHR);  return _SHR;}
">>>"				{yylval.pnode = doyylval(_SAR);  return _SAR;}

"&&"				{yylval.pnode = doyylval(_BAND);  return _BAND;}
"||"				{yylval.pnode = doyylval(_BOR);  return _BOR;}
"!"					{yylval.pnode = doyylval(_BNOT);  return _BNOT;}

"="					{yylval.pnode = doyylval(_MOV);  return _MOV;}
"+="				{yylval.pnode = doyylval(_ADDMOV);  return _ADDMOV;}
"-="				{yylval.pnode = doyylval(_SUBMOV);  return _SUBMOV;}
"*="				{yylval.pnode = doyylval(_MULMOV);  return _MULMOV;}
"/="				{yylval.pnode = doyylval(_DIVMOV);  return _DIVMOV;}
"%="				{yylval.pnode = doyylval(_MODMOV);  return _MODMOV;}
"<<="				{yylval.pnode = doyylval(_SHLMOV);  return _SHLMOV;}
">>="				{yylval.pnode = doyylval(_SHRMOV);  return _SHRMOV;}
"&="				{yylval.pnode = doyylval(_ANDMOV);  return _ANDMOV;}
"^="				{yylval.pnode = doyylval(_XORMOV);  return _XORMOV;}
"|="				{yylval.pnode = doyylval(_ORMOV);  return _ORMOV;}

"{"					{yylval.pnode = doyylval(_LBRACE);  return _LBRACE;}
"}"					{yylval.pnode = doyylval(_RBRACE);  return _RBRACE;}
"["					{yylval.pnode = doyylval(_LBRACKET);  return _LBRACKET;}
"]"					{yylval.pnode = doyylval(_RBRACKET);  return _RBRACKET;}
"("					{yylval.pnode = doyylval(_LPARENTHESE);  return _LPARENTHESE;}
")"					{yylval.pnode = doyylval(_RPARENTHESE);  return _RPARENTHESE;}
";"					{yylval.pnode = doyylval(_SEMICOLON);  return _SEMICOLON;}
","					{yylval.pnode = doyylval(_COMMA);  return _COMMA;}
"."					{yylval.pnode = doyylval(_POINT);  return _POINT;}
"?"					{yylval.pnode = doyylval(_DOUBT);  return _DOUBT;}
":"					{yylval.pnode = doyylval(_COLON);  return _COLON;}

{chars}				{yylval.pnode = savechars();  return _CUSTCHAR;}
{string}			{yylval.pnode = savestrings();  return _CUSTSTRING;}
{Integers}			{yylval.pnode = saveIntegers();  return _CUSTINT;}
{floats}			{yylval.pnode = savefloats();  return _CUSTFLOAT;}


{symbol}			{yylval.pnode = savesymbol();  return _SYMBOL;}


.					{printf("Unrecognized symbol:%s in %d \n",yytext,line);}


%%

pNode doyylval(int type){
	
	pNode ls=MakeNodeNoAttSub(type,strdup(yytext));
	ls->attributes.line=line;
	return ls;
	
}


pNode savesymbol()
{
	
	symbolnum++;
	pNode ls=MakeNodeNoAttSub(_SYMBOL,strdup(yytext));
	ls->attributes.line=line;
	return ls;
}

pNode savechars()
{
	
	charnum++;
	pNode ls= MakeNodeNoAttSub(_CUSTCHAR,strdup(yytext));
	ls->attributes.line=line;
	return ls;	
}
pNode savestrings()
{

	stringnum++;
	pNode ls= MakeNodeNoAttSub(_CUSTSTRING,strdup(yytext));
	ls->attributes.line=line;
	return ls;
}

pNode saveIntegers()
{
	
	intnum++;
	pNode ls= MakeNodeNoAttSub(_CUSTINT,strdup(yytext));
	ls->attributes.line=line;
	return ls;
}
pNode savefloats()
{

	floatnum++;
	pNode ls=  MakeNodeNoAttSub(_CUSTFLOAT,strdup(yytext));
	ls->attributes.line=line;
	return ls;
}

//返回1停止lex解析，这里只解析一个文件，针对class
int yywrap() {
    printf("lex-Over-------------\n");
    return 1;
}











