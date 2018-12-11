#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	Attributes attributes={0};
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

int NodeenumToASTenum(int i)
{
	int re=0;
	switch(i)
	{
		case _BOOLEAN:
			re=type_boolean ;break;
		case _BYTE:
			re=type_byte ;break;
		case _CHAR:
			re=type_char ;break;
		case _DOUBLE:
			re=type_double ;break;
		case _FLOAT:
			re=type_float ;break;
		case _INT:
			re=type_int ;break;
		case _LONG:
			re=type_long ;break;
		case _SHORT:
			re=type_short ;break;
		case _VOID:
			re=type_void ;break;
		case _STRING:
			re=type_String ;break;
		case class_name:
			re=type_class ;break;


		case _ADD:
			re=S_ADD ;break;
		case _SUB:
			re=S_SUB ;break;
		case _MUL:
			re=S_MUL ;break;
		case _DIV:
			re=S_DIV ;break;
		case _MOD:
			re=S_MOD ;break;
		case _CMP:
			re=S_CMP ;break;
		case _NCMP:
			re=S_NCMP ;break;
		case _MORE:
			re=S_MORE ;break;
		case _LESS:
			re=S_LESS ;break;
		case _MCMP:
			re=S_MCMP ;break;
		case _LCMP:
			re=S_LCMP ;break;
		case _AND:
			re=S_AND ;break;
		case _OR:
			re=S_OR ;break;
		case _XOR:
			re=S_XOR ;break;
		case _SHL:
			re=S_SHL ;break;
		case _SHR:
			re=S_SHR ;break;
		case _SAR:
			re=S_SAR ;break;
		case _BAND:
			re=S_BAND ;break;
		case _BOR:
			re=S_BOR ;break;
		case _MOV:
			re=S_MOV ;break;
		case _ADDMOV:
			re=S_ADDMOV ;break;
		case _SUBMOV:
			re=S_SUBMOV ;break;
		case _MULMOV:
			re=S_MULMOV ;break;
		case _DIVMOV:
			re=S_DIVMOV ;break;
		case _MODMOV:
			re=S_MODMOV ;break;
		case _SHLMOV:
			re=S_SHLMOV ;break;
		case _SHRMOV:
			re=S_SHRMOV ;break;
		case _ANDMOV:
			re=S_ANDMOV ;break;
		case _XORMOV:
			re=S_XORMOV ;break;
		case _ORMOV:
			re=S_ORMOV ;break;
		case _COMMA:
			re=S_COMMA ;break;
		case _ADD2:
			re=S_ADD2 ;break;
		case _SUB2:
			re=S_SUB2 ;break;
		case _NOT:
			re=S_NOT ;break;
		case S_SUB1:
			re=S_SUB1 ;break;
		case _BNOT:
			re=S_BNOT ;break;

		default:
			break;
		
	}
	return re;
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
			nodetype=NodeenumToASTenum(node->node[0]->node[0]->type);
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
			att.line=type->att.line;

			node->attributes.ASTnode=(void*)MK_pS_field(att,type,sym);
			break;
		}
		case statement_block ://生成pS_statement_block AST
		{
			Att att;
			pS_statements states;
			att.line=node->attributes.line;
			states=(pS_statements)node->node[1]->attributes.ASTnode;

			node->attributes.ASTnode=(void*)MK_pS_statementblock(att,states);
			break;
		}
		case statements ://生成pS_statements AST
		{
			Att att;
			pS_statement state;
			pS_statements next;
			att.line=node->attributes.line;
			if(node->nodenum==0)
			{
				node->attributes.ASTnode=NULL;
				break;
			}
			else
			{
				att.line=node->node[1]->attributes.line;
				state=(pS_statement)node->node[1]->attributes.ASTnode;
				next=(pS_statements)node->node[0]->attributes.ASTnode;
			}
			

			node->attributes.ASTnode=(void*)MK_pS_statements(att,state,next);
			break;
		}
		case statement ://生成pS_statement AST   根据不同种还要细分继续case注意保证树的简洁
		{
			//目前只处理声明语句，表达式语句，语句块，if，while，for，return，break，continue
			Att att;
			att.line=node->attributes.line;
			switch(node->node[0]->type)
			{
				case variable_declaration:
				{
					node->attributes.ASTnode=node->node[0]->attributes.ASTnode;
					break;
				}
				case expression:
				{
					node->attributes.ASTnode=(void*)MK_pS_statement_exp(att,node->node[0]->attributes.ASTnode);
					break;
				}
				case statement_block:
				{
					node->attributes.ASTnode=(void*)MK_pS_statement_block(att,node->node[0]->attributes.ASTnode);
					break;
				}
				case if_statement:
				{
					node->attributes.ASTnode=node->node[0]->attributes.ASTnode;
					break;
				}
				case while_statement:
				{
					node->attributes.ASTnode=node->node[0]->attributes.ASTnode;
					break;
				}
				case for_statement:
				{
					node->attributes.ASTnode=node->node[0]->attributes.ASTnode;
					break;
				}
				case _RETURN:
				{
					if(node->nodenum==3)
					{
						pS_exp lsret=(pS_exp)node->node[1]->attributes.ASTnode;
						node->attributes.ASTnode=(void*)MK_pS_statement_return(att,lsret);
					}
					else
					{
						node->attributes.ASTnode=(void*)MK_pS_statement_return(att,NULL);
					}
					
					break;
				}
				case _BREAK:
				{
					node->attributes.ASTnode=(void*)MK_pS_statement_break(att);
					break;
				}
				case _CONTINUE:
				{
					node->attributes.ASTnode=(void*)MK_pS_statement_continue(att);
					break;
				}
				default :
				{
					break;
				}
			}
			break;
		}
		case variable_declaration ://生成pS_statement AST  
		{
			Att att;
			pS_field field;
			pS_exp exp;
			pS_statements next;
			att.line=node->attributes.line;
			//得到第一个变量声明式,并确定类型
			pNode firstsym=node->node[2]->node[0];
			field=MK_pS_field(att,(pS_type)node->node[1]->attributes.ASTnode,(pS_symbol)firstsym->node[0]->attributes.ASTnode);
			int addbrackets=howDeepInNodeBrackets(firstsym->node[1],0);
			field->u.field.type->u.brackets+=addbrackets;
			//第一个变量的初始化
			exp=NULL;
			if(firstsym->nodenum==4)
			{
				exp=firstsym->node[3]->node[0]->attributes.ASTnode;//这里只支持exp类型的初始化，暂不支持{}式，这个格式通过exp来支持
			}
			next=NULL;
			//next=MakeVariable_declarations(field->u.field.type,node->[2]);处理多条语句声明
			//目前多个声明时被识别为exp了
			node->attributes.ASTnode=(void*)MK_pS_statement_field(att,field,exp,next);
			break;
		}
		case if_statement ://生成pS_statement AST  
		{
			Att att;
			pS_exp exp ;
			pS_statement trueblock;
			pS_statement falseblock;
			att.line=node->attributes.line;
			exp=(pS_exp)node->node[2]->attributes.ASTnode;
			//处理trueblock
			trueblock=(pS_statement)node->node[4]->attributes.ASTnode;
			//处理falseblock
			if(node->nodenum==5)
			{
				falseblock=NULL;
			}
			else
			{
				falseblock=(pS_statement)node->node[6]->attributes.ASTnode;
			}
			node->attributes.ASTnode=(void*)MK_pS_statement_if(att,exp,trueblock,falseblock);
			break;
		}
		case while_statement ://生成pS_statement AST 
		{
			Att att;
			pS_exp exp ;
			pS_statement block;
			att.line=node->attributes.line;
			exp=(pS_exp)node->node[2]->attributes.ASTnode;
			block=(pS_statement)node->node[4]->attributes.ASTnode;

			node->attributes.ASTnode=(void*)MK_pS_statement_while(att,exp,block);
			break;
		}
		case for_statement ://生成pS_statement AST  
		{
			Att att;
			pS_exp exp1 ;
			pS_exp exp2 ;
			pS_exp exp3 ;
			pS_statement block;
			att.line=node->attributes.line;
			if(node->nodenum==8)
			{
				//不支持for头声明变量
				node->attributes.ASTnode=NULL;
				break;
			}
			pNode lsnode;
			lsnode=node->node[2];
			exp1=lsnode->nodenum==1?lsnode->node[0]->attributes.ASTnode:NULL;
			lsnode=node->node[4];
			exp2=lsnode->nodenum==1?lsnode->node[0]->attributes.ASTnode:NULL;
			lsnode=node->node[6];
			exp3=lsnode->nodenum==1?lsnode->node[0]->attributes.ASTnode:NULL;
			block=(pS_statement)node->node[8]->attributes.ASTnode;

			node->attributes.ASTnode=(void*)MK_pS_statement_for(att,exp1,exp2,exp3,block);
			break;
		}
		case expression ://生成pS_exp AST  根据不同种还要细分
		{
			Att att;
			att.line=node->attributes.line;
			int op=0;
			pS_exp exp1;
			pS_exp exp2;
			pNode firstsonNode=node->node[0];
			switch(firstsonNode->type)
			{
				case numeric_expression:
				{
					if(firstsonNode->nodenum==2)
					{
						if(firstsonNode->node[0]->type==expression)
						{
							exp1=(pS_exp)firstsonNode->node[0]->attributes.ASTnode;
							op=NodeenumToASTenum(firstsonNode->node[1]->type);
						}
						else
						{							
							op=NodeenumToASTenum(firstsonNode->node[0]->type);
							op=op==S_SUB?S_SUB1:op;//处理负数，注意负号是可以加在表达式前的，因此不可以在语法分析时算出，应作为输出
							exp1=(pS_exp)firstsonNode->node[1]->attributes.ASTnode;
						}
						node->attributes.ASTnode=(void*)MK_pS_exp_op1(att,exp1,op);
					}
					else
					{
						exp1=(pS_exp)firstsonNode->node[0]->attributes.ASTnode;
						op=NodeenumToASTenum(firstsonNode->node[1]->type);
						exp2=(pS_exp)firstsonNode->node[2]->attributes.ASTnode;
						node->attributes.ASTnode=(void*)MK_pS_exp_op2(att,exp1,op,exp2);
					}
					break;
				}
				case testing_expression:
				{
						exp1=(pS_exp)firstsonNode->node[0]->attributes.ASTnode;
						op=NodeenumToASTenum(firstsonNode->node[1]->type);
						exp2=(pS_exp)firstsonNode->node[2]->attributes.ASTnode;
						node->attributes.ASTnode=(void*)MK_pS_exp_op2(att,exp1,op,exp2);
					break;
				}
				case logical_expression:
				{
					if(firstsonNode->nodenum==2)
					{
						op=NodeenumToASTenum(firstsonNode->node[0]->type);
						exp1=(pS_exp)firstsonNode->node[1]->attributes.ASTnode;
										
						node->attributes.ASTnode=(void*)MK_pS_exp_op1(att,exp1,op);
					}
					else if(firstsonNode->nodenum==3)
					{
						exp1=(pS_exp)firstsonNode->node[0]->attributes.ASTnode;
						op=NodeenumToASTenum(firstsonNode->node[1]->type);
						exp2=(pS_exp)firstsonNode->node[2]->attributes.ASTnode;
						node->attributes.ASTnode=(void*)MK_pS_exp_op2(att,exp1,op,exp2);
					}
					else
					{
						if(firstsonNode->node[0]->type==_TRUE)
						{
							node->attributes.ASTnode=(void*)MK_pS_exp_true(att);
						}
						else
						{
							node->attributes.ASTnode=(void*)MK_pS_exp_false(att);
						}
					}
					break;
				}
				case bit_expression:
				{
					if(firstsonNode->nodenum==2)
					{
						op=NodeenumToASTenum(firstsonNode->node[0]->type);
						exp1=(pS_exp)firstsonNode->node[1]->attributes.ASTnode;
										
						node->attributes.ASTnode=(void*)MK_pS_exp_op1(att,exp1,op);
					}
					else
					{
						exp1=(pS_exp)firstsonNode->node[0]->attributes.ASTnode;
						op=NodeenumToASTenum(firstsonNode->node[1]->type);
						exp2=(pS_exp)firstsonNode->node[2]->attributes.ASTnode;
						node->attributes.ASTnode=(void*)MK_pS_exp_op2(att,exp1,op,exp2);					
					}
					break;
				}
				case creating_expression:
				{
					node->attributes.ASTnode=firstsonNode->attributes.ASTnode;
					break;
				}
				case literal_expression:
				{
					switch(firstsonNode->node[0]->type)
					{
						case _CUSTCHAR:
						{
							node->attributes.ASTnode=(void*)MK_pS_exp_char(att,firstsonNode->node[0]->leafstring[1]);
							break;
						}
						case _CUSTSTRING:
						{
							node->attributes.ASTnode=(void*)MK_pS_exp_str(att,firstsonNode->node[0]->leafstring);
							break;
						}
						case _CUSTINT:
						{
							int value=atoi(firstsonNode->node[0]->leafstring);
							node->attributes.ASTnode=(void*)MK_pS_exp_int(att,value);
							break;
						}
						case _CUSTFLOAT:
						{
							double  value=atof(firstsonNode->node[0]->leafstring);
							node->attributes.ASTnode=(void*)MK_pS_exp_float(att,value);
							break;
						}
					}

					break;
				}
				case _NUL:
				{
					node->attributes.ASTnode=(void*)MK_pS_exp_null(att);
					break;
				}
				case _SUPER:
				{
					node->attributes.ASTnode=(void*)MK_pS_exp_super(att);
					break;
				}
				case _THIS:
				{
					node->attributes.ASTnode=(void*)MK_pS_exp_this(att);
					break;
				}
				case _SYMBOL:
				{
					pS_symbol sym=node->node[0]->attributes.ASTnode;
					node->attributes.ASTnode=(void*)MK_pS_exp_sym(att,sym);
					break;
				}
				case _LPARENTHESE:
				{
					node->attributes.ASTnode=node->node[1]->attributes.ASTnode;
					break;
				}
				case expression:
				{
					switch(node->node[1]->type)
					{
						case _LPARENTHESE:
						{
							pS_exp exp;
							pS_args args;
							if(node->nodenum==4)
							{
								exp=(pS_exp)node->node[0]->attributes.ASTnode;
								args=(pS_args)node->node[2]->attributes.ASTnode;
							}
							else
							{
								exp=(pS_exp)node->node[0]->attributes.ASTnode;
								args=NULL;
							}
							node->attributes.ASTnode=(void*)MK_pS_exp_call(att,exp,args);
							break;
						}
						case _LBRACKET://数组exp
						{
							pS_exp exp;
							pS_exp arry;
							exp=(pS_exp)node->node[0]->attributes.ASTnode;
							arry=(pS_exp)node->node[2]->attributes.ASTnode;

							node->attributes.ASTnode=(void*)MK_pS_exp_arry(att,exp,arry);
							break;
						}
						case _POINT://对象exp
						{

							exp1=(pS_exp)node->node[0]->attributes.ASTnode;
							exp2=(pS_exp)node->node[2]->attributes.ASTnode;

							node->attributes.ASTnode=(void*)MK_pS_exp_object(att,exp1,exp2);
							break;
						}
						case _COMMA://逗号exp
						{
							op=NodeenumToASTenum(_COMMA);
							exp1=(pS_exp)node->node[0]->attributes.ASTnode;
							exp2=(pS_exp)node->node[2]->attributes.ASTnode;
							
							node->attributes.ASTnode=(void*)MK_pS_exp_op2(att,exp1,op,exp2);
							break;
						}
						default:
						{
							break;
						}
					}
				}
				default :
				{
					break;
				}
			}
			
			break;
		}
		case creating_expression:  //new-exp
		{
			Att att;
			pS_type type;
			pS_args args;
			att.line=node->attributes.line;
			if(node->node[1]->type==class_name)
			{
				//非数组
				att.name=makeClassNameFromNode(node->node[1]);
				type=MK_pS_type(att,type_class,0);
				if(node->nodenum==4)
				{
					args=NULL;
				}
				else
				{
					args=(pS_args)node->node[3]->attributes.ASTnode;
				}
			}
			else
			{
				//数组
				int type_ls;
				int brackets;
				type_ls=NodeenumToASTenum(node->node[1]->node[0]->type);
				att.name=node->node[1]->node[0]->leafstring;
				if(type_ls==type_class){att.name=makeClassNameFromNode(node->node[1]->node[0]);}
				brackets=howDeepInNodeBrackets(node->node[2],0);
				type=MK_pS_type(att,type_ls,brackets);
				args=node->node[2]->attributes.ASTnode;
			}

			node->attributes.ASTnode=(void*)MK_pS_exp_new(att,type,args);
			break;
		}
		case arglist ://生成pS_args AST用于函数调用的参数表
		{
			Att att;
			pS_exp exp;
			pS_args next;
			att.line=node->attributes.line;
			if(node->nodenum==1)
			{
				exp=(pS_exp)node->node[0]->attributes.ASTnode;
				next=NULL;
			}
			else
			{
				exp=(pS_exp)node->node[2]->attributes.ASTnode;
				next=(pS_args)node->node[0]->attributes.ASTnode;
			}

			node->attributes.ASTnode=(void*)MK_pS_args(att,exp,next);
			break;
		}
		case bracketnums://生成pS_args AST用于数组的参数表
		{
			Att att;
			pS_exp exp;
			pS_args next;
			att.line=node->attributes.line;
			if(node->nodenum==0)
			{
				node->attributes.ASTnode=NULL;
			}
			else
			{
				exp=(pS_exp)node->node[2]->attributes.ASTnode;
				next=(pS_args)node->node[0]->attributes.ASTnode;
				node->attributes.ASTnode=(void*)MK_pS_args(att,exp,next);
			}

			
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
//		showtree(funnodes[i],0);
		functionASTs[i]=changeNodeToAST(funnodes[i]);
	}

	printf("AST:---------------------\n");
	for(i=0;i<funnum;i++)
	{
		show_pS_method_declaration(functionASTs[i],0);
	}
	



}









