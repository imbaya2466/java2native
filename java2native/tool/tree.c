#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "main.h"
#include "front/AST.h"
#include "front/java.tab.h"



//语法树提出fun
pNode funnodes[MAX_FUNNUM];
//changeNodeToAST使用
pS_method_declaration lspAST;
//导出fun的AST
pS_method_declaration functionASTs[MAX_FUNNUM];
int funnum=0;

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
	if(nodenum!=0)
		attributes.line=node[0]->attributes.line;
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
	
	int nextdp=++dp;//因为子同层多个，防止重复加
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
		return;//不支持嵌套函数，就不向下搜索了，因为是前序遍历
	}


	if(node->nodenum==0)
		return;
	
	for(i=0;i<node->nodenum;i++)
	{
		
		findFunNode(node->node[i]);
	}
	
	
}

//计算数组维度
int  howDeepInNodeBrackets(pNode node,int deep)
{
	if(node->nodenum==0)
	{
		return deep;
	}

	return howDeepInNodeBrackets(node->node[0],++deep);

}
//转化类型名--未完成
char* makeClassNameFromNode(pNode node)
{
	//先只做一层
	return node->node[0]->leafstring;

}

//构造AST，这一便构造只做最基本的属性处理。不做语义分析！
//只做简单的抽象语法树提出，不要加任何语义分析的工作。保证抽象语法树的简洁。不做其它输出
//后序遍历，因为当子节点都生成好了才可以生成父,后序遍历保证了先子后父。子节点暂寄于语法树下
//这里传入的实际上只是一个函数的node
void Node_AST(pNode node)
{
	int i=0;
	if(node==NULL)
		return ;

	
	for(i=0;i<node->nodenum;i++)
	{
		Node_AST(node->node[i]);
	}
	
	


	//结点处理.这里每个case只做生成AST的动作，非制造节点动作一律放置于外
	switch(node->type)
	{
		case method_declaration : //lspAST=制造的S_method_declaration，注意参数可能为空
		{
			Att att;
			pS_symbol name;
			pS_fieldList fies;
			pS_type retype;
			pS_statement_block body;

			att.line=node->attributes.line;
			name=(pS_symbol)node->node[2]->attributes.ASTnode;
			retype=(pS_type)node->node[1]->attributes.ASTnode;
			if(node->nodenum==7)
			{
				fies=(pS_fieldList)node->node[4]->attributes.ASTnode;
				body=(pS_statement_block)node->node[6]->attributes.ASTnode;
			}
			else
			{
				fies=NULL;
				body=(pS_statement_block)node->node[5]->attributes.ASTnode;
			}
			lspAST=MK_pS_method_declaration(att,name,fies,retype,body);
			node->attributes.ASTnode=(void*)lspAST;

			break;
		}
		case type ://产生S_type AST节点
		{
			Att att;
			int nodetype=0;
			int brackets=0;
			
			switch(node->node[0]->node[0]->type)
			{
				case _BOOLEAN :
				{
					nodetype=type_boolean;
					break;
				}
				case _BYTE :
				{
					nodetype=type_byte;
					break;
				}
				case _CHAR :
				{
					nodetype=type_char;
					break;
				}
				case _DOUBLE :
				{
					nodetype=type_double;
					break;
				}
				case _FLOAT :
				{
					nodetype=type_float;
					break;
				}
				case _INT :
				{
					nodetype=type_int;
					break;
				}
				case _LONG :
				{
					nodetype=type_long;
					break;
				}
				case _SHORT :
				{
					nodetype=type_short;
					break;
				}
				case _VOID :
				{
					nodetype=type_void;
					break;
				}
				case _STRING :
				{
					nodetype=type_String;
					break;
				}
				case class_name :
				{
					nodetype=type_class;
					break;
				}
			}
			att.line=node->node[0]->node[0]->attributes.line;
			att.name=node->node[0]->node[0]->leafstring;
			if(nodetype==type_class)
			{
				att.name=makeClassNameFromNode(node->node[0]->node[0]);
			}
			brackets=howDeepInNodeBrackets(node->node[1],0);
			node->attributes.ASTnode=(void*)MK_pS_type(att,nodetype,brackets);
			
			break;
		}
		case _SYMBOL : //标识符生成 S_symbol AST
		{
			Att att;
			char *sym;
			att.line=node->attributes.line;
			sym=node->leafstring;

			node->attributes.ASTnode=(void*)MK_pS_symbol(att,sym);
			break;
		}
		case parameter_list : //生成S_fieldList AST
		{
			Att att;
			pS_field field;
			pS_fieldList next;
			if(node->nodenum==1)
			{
				next=NULL;
				field=(pS_field)node->node[0]->attributes.ASTnode;
			}
			else
			{
				next=(pS_fieldList)node->node[0]->attributes.ASTnode;
				field=(pS_field)node->node[2]->attributes.ASTnode;
			}
			att.line=node->attributes.line;

			node->attributes.ASTnode=(void*)MK_pS_fieldList(att,field,next);

			break;
		}
		case parameter : //生成S_field AST
		{
			Att att;
			pS_type type;
			pS_symbol sym;
			type=(pS_type)node->node[0]->attributes.ASTnode;
			sym=(pS_symbol)node->node[1]->attributes.ASTnode;
			int addbrackets=howDeepInNodeBrackets(node->node[2],0);
			type->u.brackets+=addbrackets; //总数组维度为俩个写法之和
			att.line=node->attributes.line;

			node->attributes.ASTnode=(void*)MK_pS_field(att,type,sym);
			break;
		}
		case statement_block :
		{

			break;
		}
	
		default :
		{
			return;
		}
	}
	
}

//为一个函数节点创建AST
pS_method_declaration changeNodeToAST(pNode funnode)
{
	lspAST=NULL;	
	Node_AST(funnode);
	if(lspAST==NULL)
	{
		printf("error:change Node to AST error\n");
//		exit(1);
	}
	return lspAST;
}


void testfun(pNode node,int dp)
{
	int i=0;
	if(node==NULL)
		return;

	if(node->type==type)//node的类型
	{
		//展示其属性中寄存的ASTnode
		show_pS_type((pS_type)node->attributes.ASTnode);
		printf("\n");
	//----
	}
	
	
	if(node->nodenum==0)
		return;
	
	int nextdp=++dp;//因为子同层多个，防止重复加
	for(i=0;i<node->nodenum;i++)
	{
		testfun(node->node[i],nextdp);
	}
}


//为root创建AST，导出functionASTs表
void makeFunAST(pNode root)
{
	int i=0;
	findFunNode(root);
	for(i=0;i<funnum;i++)
	{
		showtreeback(funnodes[i],0);
		functionASTs[i]=changeNodeToAST(funnodes[i]);
	}

	testfun(funnodes[0],0);



}









