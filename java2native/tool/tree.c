#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


/*

struct _Node{
	int nodenum;//子节点数量
	struct _Node *node[NODENUM_MAX];//子节点
	int type;//结点类型值
	Attributes attributes;//属性
	
	char *leafstring;//用于保存终结符的字串，构建树时用于显示，构建符号表时用于分配空间填写其内容
	
};
typedef struct _Node * pNode;
typedef struct _Node Node;

*/

//######注意一下，n叉树现在还没有一个满意的处理方案，有可能会白白浪费了语法分析的结果。目前能想到比较有效的遍历方式就是后序遍历。。。
//目前先以n叉形式存储，用于输出查看。中间代码生成看完后再想办法决定树还是语法分析来生成三地址代码！！！！再实在不行还有多叉树转二叉树
//先不要过多的处理这个n叉........想清楚再用！！！！！！！！！！！！！！！
pNode makenode(int nodenum,pNode node[],int type,Attributes attributes,char *leafstring){
	if(nodenum>NODENUM_MAX)
		return NULL;
	
	
	pNode new=(pNode)malloc(sizeof(Node));
	new->nodenum=nodenum;
	int i=0;
	for(i=0;i<nodenum;i++)
	{
		new->node[i]=node[i];
	}
	new->type=type;
	new->attributes=attributes;
	new->leafstring=leafstring;
	return new;
	
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



void showtree(pNode node)
{
	if(node==NULL)
		return;
	
	shownode(node);
	
	if(node->nodenum==0)
		return;
	
	int i=0;
	for(i=0;i<node->nodenum;i++)
	{
		showtree(node->node[i]);
	}
	
	
}
void shownode(pNode node)
{
	printf ("add:%p  val:%d  str:%s  sub:(%d):",node ,node->type,node->leafstring,node->nodenum);
	int i=0;
	for(i=0;i<node->nodenum;i++)
	{
		printf(" %p",node->node[i]);
	}
	printf("\n");
}













