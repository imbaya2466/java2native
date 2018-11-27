#ifndef TREE_H
#define TREE_H

#define NODENUM_MAX 10

//属性结构体大量用于赋值拷贝，不要有指针
typedef struct _Attributes{
	
}Attributes;


typedef struct _Node{
	int nodenum;//子节点数量
	struct _Node *node[NODENUM_MAX];//子节点
	int type;//结点类型值
	Attributes attributes;//属性
	
	char *leafstring;//用于保存终结符的字串，构建树时用于显示，构建符号表时用于分配空间填写其内容
	
}Node;
typedef Node* pNode;


pNode MakeNode(int nodenum,pNode node[],int type,Attributes attributes,char *leafstring);
pNode MakeNodeNoAtt(int nodenum,pNode node[],int type,char *leafstring);
pNode MakeNodeNoAttSub(int type,char *leafstring);
pNode MakeNodeNoAttSubString(int type);

#endif