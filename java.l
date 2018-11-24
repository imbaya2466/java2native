%{
    #include <string.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include "java.tab.h"
	
    int line = 1;

	
	char SymbolTable[10000][100];//符号表
	int symbolnum=0;
	
	float FloatTable[10000];			//float 4byte
	int IntTable[10000];				//int 4byte
	char StringTable[10000][100];	//string常量
	int CharTable[10000];			//char 2byteUnicode
	int floatnum=0;
	int intnum=0;
	int stringnum=0;
	int charnum=0;
	
	int savesymbol();

	int savechars();
	int saveIntegers();
	int savefloats();
	int savestrings();
	
	
%}

/*正则优先级：()[] >  *+?  个数 >  字符连接  >  |
转义有俩种方式："xxx"或者\x  ""内的内容作为字符匹配*/

letter                      [a-zA-Z]
digit                       [0-9]
anychar                     {letter}|{digit}|"_"
space                       [ \t\r]+
enter						\n
paragraphComments           "/*"(.|\n)*"*/"
lineComments                "//".*\n
negativeint					"-"{digit}+


symbol						({letter}|"_"){anychar}*

Integers					{negativeint}|{digit}+				
floats						{digit}+"."{digit}*|"."{digit}+
chars						\'.\'
string						\".*\"






%%
{paragraphComments} {/* skip */}
{lineComments}      {/* skip */}
{space}             {/* skip */}
{enter}				{line++;}
"private"			{yylval = 0;  return _PRIVATE;}
"protected"			{yylval = 0;  return _PROTECTED;}
"public"			{yylval = 0;  return _PUBLIC;}
"abstract"			{yylval = 0;  return _ABSTRACT;}
"extends"			{yylval = 0;  return _EXTENDS;}
"final"				{yylval = 0;  return _FINAL;}
"implements"		{yylval = 0;  return _IMPLEMENTS;}
"native"			{yylval = 0;  return _NATIVE;}
"new"				{yylval = 0;  return _NEW;}
"static"			{yylval = 0;  return _STATIC;}
"strictfp"			{yylval = 0;  return _STRICTFP;}
"transient"			{yylval = 0;  return _TRANSIENT;}
"volatile"			{yylval = 0;  return _VOLATILE;}

"break"				{yylval = 0;  return _BREAK;}
"continue"			{yylval = 0;  return _CONTINUE;}
"return"			{yylval = 0;  return _RETURN;}
"do"				{yylval = 0;  return _DO;}
"while"				{yylval = 0;  return _WHILE;}
"if"				{yylval = 0;  return _IF;}
"else"				{yylval = 0;  return _ELSE;}
"for"				{yylval = 0;  return _FOR;}
"instanceof"		{yylval = 0;  return _INSTANCEOF;}
"switch"			{yylval = 0;  return _SWITCH;}
"case"				{yylval = 0;  return _CASE;}
"default"			{yylval = 0;  return _DEFAULT;}
"try"				{yylval = 0;  return _TRY;}
"catch"				{yylval = 0;  return _CATCH;}
"finally"			{yylval = 0;  return _FINALLY;}
"throw"				{yylval = 0;  return _THROW;}
"throws"			{yylval = 0;  return _THROWS;}
"assert"			{yylval = 0;  return _ASSERT;}
"synchronized"		{yylval = 0;  return _SYNCHRONIZED;}

"import"			{yylval = 0;  return _IMPORT;}
"package"			{yylval = 0;  return _PACKAGE;}

"boolean"			{yylval = 0;  return _BOOLEAN;}
"byte"				{yylval = 0;  return _BYTE;}
"char"				{yylval = 0;  return _CHAR;}
"double"			{yylval = 0;  return _DOUBLE;}
"float"				{yylval = 0;  return _FLOAT;}
"int"				{yylval = 0;  return _INT;}
"long"				{yylval = 0;  return _LONG;}
"short"				{yylval = 0;  return _SHORT;}
"void"				{yylval = 0;  return _VOID;}
"String"			{yylval = 0;  return _STRING;}
"enum"				{yylval = 0;  return _ENUM;}
"class"				{yylval = 0;  return _CLASS;}
"interface"			{yylval = 0;  return _INTERFACE;}

"ture"				{yylval = 0;  return _TRUE;}
"false"				{yylval = 0;  return _FALSE;}
"null"				{yylval = 0;  return _NUL;}
"super"				{yylval = 0;  return _SUPER;}
"this"				{yylval = 0;  return _THIS;}

"+"					{yylval = 0;  return _ADD;}
"-"					{yylval = 0;  return _SUB;}
"*"					{yylval = 0;  return _MUL;}
"/"					{yylval = 0;  return _DIV;}
"%"					{yylval = 0;  return _MOD;}
"++"				{yylval = 0;  return _ADD2;}
"--"				{yylval = 0;  return _SUB2;}

"=="				{yylval = 0;  return _CMP;}
"!="				{yylval = 0;  return _NCMP;}
">"					{yylval = 0;  return _MORE;}
"<"					{yylval = 0;  return _LESS;}
">="				{yylval = 0;  return _MCMP;}
"<="				{yylval = 0;  return _LCMP;}

"&"					{yylval = 0;  return _AND;}
"|"					{yylval = 0;  return _OR;}
"^"					{yylval = 0;  return _XOR;}
"~"					{yylval = 0;  return _NOT;}
"<<"				{yylval = 0;  return _SHL;}
">>"				{yylval = 0;  return _SHR;}
">>>"				{yylval = 0;  return _SAR;}

"&&"				{yylval = 0;  return _BAND;}
"||"				{yylval = 0;  return _BOR;}
"!"					{yylval = 0;  return _BNOT;}

"="					{yylval = 0;  return _MOV;}
"+="				{yylval = 0;  return _ADDMOV;}
"-="				{yylval = 0;  return _SUBMOV;}
"*="				{yylval = 0;  return _MULMOV;}
"/="				{yylval = 0;  return _DIVMOV;}
"%="				{yylval = 0;  return _MODMOV;}
"<<="				{yylval = 0;  return _SHLMOV;}
">>="				{yylval = 0;  return _SHRMOV;}
"&="				{yylval = 0;  return _ANDMOV;}
"^="				{yylval = 0;  return _XORMOV;}
"|="				{yylval = 0;  return _ORMOV;}

"{"					{yylval = 0;  return _LBRACE;}
"}"					{yylval = 0;  return _RBRACE;}
"["					{yylval = 0;  return _LBRACKET;}
"]"					{yylval = 0;  return _RBRACKET;}
"("					{yylval = 0;  return _LPARENTHESE;}
")"					{yylval = 0;  return _RPARENTHESE;}
";"					{yylval = 0;  return _SEMICOLON;}
","					{yylval = 0;  return _COMMA;}
"."					{yylval = 0;  return _POINT;}

{chars}				{yylval = savechars();  return _CUSTCHAR;}
{string}			{yylval = savestrings();  return _CUSTSTRING;}
{Integers}			{yylval = saveIntegers();  return _CUSTINT;}
{floats}			{yylval = savefloats();  return _CUSTFLOAT;}


{symbol}			{yylval = savesymbol();  return _SYMBOL;}


.					{printf("Unrecognized symbol:%s in %d \n",yytext,line);}


%%

int savesymbol()
{
	
	strcpy(SymbolTable[symbolnum],yytext);
	symbolnum++;
	return symbolnum-1;
}

int savechars()
{
	
	CharTable[charnum]=yytext[yyleng];
	charnum++;
	return charnum-1;
	
}
int savestrings()
{
	
	strcpy(StringTable[stringnum],yytext);
	stringnum++;
	return stringnum-1;
}

int saveIntegers()
{
	
	IntTable[intnum]=atoi(yytext);
	intnum++;
	return intnum-1;

}
int savefloats()
{
	
	FloatTable[floatnum]=atof(yytext);
	floatnum++;
	return floatnum-1;
}

int yywrap() {
    printf("_!WOW!\n");
    return 1;
}










