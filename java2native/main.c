#include <stdio.h>
#include <string.h>
#include "tool/tree.h"	
#include "front/AST.h"	
#include "main.h"


int yyparse (void);
extern FILE * yyin;
extern int line;
extern pNode root;
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
   //第一遍遍历，建立完整语法树
   yyparse();
   //showtree(root,0);
   //第二遍遍历语法树，提出我感兴趣的抽象函数
   //注意保证产生AST的部分和处理AST的部分完全解耦合。AST的定义与辅助文件不要依赖任何其它模块
   makeFunAST(root);




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