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
void showtree(pNode node,int dp);
void shownode(pNode node);


typedef enum id_
{
   compilation_unit  
,  import_statements 
,  type_declarations 
,  package_statement  
,  package_name  
,  import_statement  
,  class_name  
,  type_declaration  
,  class_declaration  
,  modifiers  
,  modifier  
,  implements  
,  field_declarations  
,  field_declaration  
,  method_declaration  
,  type  
,  type_specifier  
,  brackets  
,  parameter_list 
,  parameter 
,  statement_block 
,  statements 
,  statement 
,  variable_declaration 
,  variable_declarators 
,  variable_declarator 
,  variable_initializer 
,  variable_initializers 
,  expression 
,  numeric_expression 
,  testing_expression 
,  logical_expression 
,  bit_expression     
,  string_expression  
,  casting_expression 
,  creating_expression 
,  arglist 
,  literal_expression 
,  if_statement 
,  elseifs 
,  do_statement 
,  while_statement 
,  for_statement 
,  expression01 
,  try_statement 
,  catchs 
,  switch_statement 
,  cases 
,  constructor_declaration 
,  static_initializer 
,  interface_declaration 
}id;






#endif