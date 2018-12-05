#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "main.h"





pNode makenode(int nodenum,pNode node[],int type,Attributes attributes,char *leafstring){
	if(nodenum>NODENUM_MAX)
		return NULL;
	
	
	pNode pnew=(pNode)malloc(sizeof(Node));
	pnew->nodenum=nodenum;
	int i=0;
	for(i=0;i<nodenum;i++)
	{
		pnew->node[i]=node[i];
	}
	pnew->type=type;
	pnew->attributes=attributes;
	pnew->leafstring=leafstring;
	return pnew;
	
}

pNode MakeNodeNoAtt(int nodenum,pNode node[],int type,char *leafstring)
{
	Attributes attributes;
	return makenode(nodenum,node,type,attributes,leafstring);
	
}
pNode MakeNodeNoAttSub(int type,char *leafstring)
{
	pNode ls=MakeNodeNoAtt(0,NULL,type,leafstring);

	return ls;
}

pNode MakeNodeNoAttSubString(int type)
{
	return MakeNodeNoAttSub(type,NULL);
}



void showtree(pNode node ,int dp)
{
	int i=0;
	if(node==NULL)
		return;
	for(i=0;i<dp;i++)
		printf("  ");
	
	shownode(node);
	
	if(node->nodenum==0)
		return;
	
	int nextdp=++dp;
	for(i=0;i<node->nodenum;i++)
	{
		showtree(node->node[i],nextdp);
	}
	
	
}
void shownode(pNode node)
{
//	printf ("add:%p  val:%d  str:%s  sub:(%d):",node ,node->type,node->leafstring,node->nodenum);
	printf ("%s",node->leafstring);

	printf("\n");
}

void showtreeback(pNode node,int dp)
{
	int i=0;
	if(node==NULL)
		return;

	
	int nextdp=++dp;
	for(i=0;i<node->nodenum;i++)
	{
		showtreeback(node->node[i],nextdp);
	}
	
	for(i=0;i<dp;i++)
		printf("  ");
	
	shownode(node);
}


pNode funnodes[20];
//递归找出函数节点
void findFunNode(pNode node )
{
	int i=0;
	if(node==NULL)
		return;

	if(node->type==method_declaration&&node->node[node->nodenum-1]->type==statement_block)
	{
		funnodes[funnum]=node;
		funnum++;
	}


	if(node->nodenum==0)
		return;
	
	for(i=0;i<node->nodenum;i++)
	{
		
		findFunNode(node->node[i]);
	}
	
	
}

//构造AST
pS_method_declaration lspAST;
void Node_AST(pNode node)
{
	int i=0;
	if(node==NULL)
		return ;

	
	for(i=0;i<node->nodenum;i++)
	{
		Node_AST(node->node[i]);
	}
	
	switch(node->type)
	{
		case method_declaration :
		{
			//lspAST=制造fun结点
			break;
		}
		default :
		{
			return;
		}
	}
	
}


void changeNodeToAST(pNode funnode,pS_method_declaration* ppfunAST)
{
	lspAST=NULL;	
	Node_AST(funnode);
	if(lspAST==NULL)
	{
		printf("error:change Node to AST error\n");
		exit(1);
	}
	*ppfunAST=lspAST;
}



//为root创建AST
void makeFunAST(pNode root)
{
	int i=0;
	findFunNode(root);
	for(i=0;i<funnum;i++)
	{
		showtreeback(funnodes[i],0);
		changeNodeToAST(funnodes[i],&functionASTs[i]);
	}




}









