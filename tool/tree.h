#ifndef TREE_H
#define TREE_H

#define NODENUM_MAX 10

//���Խṹ��������ڸ�ֵ��������Ҫ��ָ��
typedef struct _Attributes{
	
}Attributes;


typedef struct _Node{
	int nodenum;//�ӽڵ�����
	struct _Node *node[NODENUM_MAX];//�ӽڵ�
	int type;//�������ֵ
	Attributes attributes;//����
	
	char *leafstring;//���ڱ����ս�����ִ���������ʱ������ʾ���������ű�ʱ���ڷ���ռ���д������
	
}Node;
typedef Node* pNode;


pNode MakeNode(int nodenum,pNode node[],int type,Attributes attributes,char *leafstring);
pNode MakeNodeNoAtt(int nodenum,pNode node[],int type,char *leafstring);
pNode MakeNodeNoAttSub(int type,char *leafstring);
pNode MakeNodeNoAttSubString(int type);

#endif