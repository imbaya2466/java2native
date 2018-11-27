#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


/*

struct _Node{
	int nodenum;//�ӽڵ�����
	struct _Node *node[NODENUM_MAX];//�ӽڵ�
	int type;//�������ֵ
	Attributes attributes;//����
	
	char *leafstring;//���ڱ����ս�����ִ���������ʱ������ʾ���������ű�ʱ���ڷ���ռ���д������
	
};
typedef struct _Node * pNode;
typedef struct _Node Node;

*/



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







