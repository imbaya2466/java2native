#include <stdio.h>
#include <string.h>
#include "tool/tree.h"	

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
   
   
   
   
   
   yyparse();
  
  
  showtree(root,0);
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