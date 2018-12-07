#include "AST.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//保证AST的独立性，保证AST的部分不依赖于其它模块。使生成AST与处理AST的部分低耦合

void * ckmalloc(int size)
{
	void *p=malloc(size);

		assert(p);
	return p;
}

//用于节约空间的AST节点类型字串....node节点类型非终已经存于常量区了，终结每个都拷贝-这是必须的。因为yytext并不保存。所以内存字串部分已经优化的可以了
char *S_str_psmd="method_declaration";
char *S_str_pssym="symbol";
char *S_str_psfl="fieldList";
char *S_str_psfie="field";
char *S_str_pstype="type";
char *S_str_pssb="statement_block";
char *S_str_psstates="statements";
char *S_str_psstate="statement";
char *S_str_psexp="exp";
char *S_str_psarg="args";


pS_method_declaration MK_pS_method_declaration(Att att,pS_symbol name,pS_fieldList fies,pS_type retype,pS_statement_block body)
{
	pS_method_declaration p = ckmalloc(sizeof(*p));
	p->kind=S_fun;
	p->att=att;
	p->u.decfun.name=name;
	p->u.decfun.fies=fies;
	p->u.decfun.retype=retype;
	p->u.decfun.body=body;
	p->att.name=S_str_psmd;
	
	return p;
}
pS_symbol MK_pS_symbol(Att att,char *symbol)
{
	pS_symbol p = ckmalloc(sizeof(*p));
	p->kind=S_sym;
	p->att=att;
	p->u.symbol=symbol;//符号名
	p->att.name=S_str_pssym;
	return p;
}

pS_fieldList MK_pS_fieldList(Att att,pS_field field,pS_fieldList next)
{
	pS_fieldList p = ckmalloc(sizeof(*p));
	p->kind=S_fiedlist;
	p->att=att;
	p->u.fieldlist.field=field;
	p->u.fieldlist.next=next;
	p->att.name=S_str_psfl;
	
	return p;
}

pS_field MK_pS_field(Att att,pS_type type,pS_symbol name)
{
	pS_field p = ckmalloc(sizeof(*p));
	p->kind=S_fied;
	p->att=att;
	p->u.field.type=type;
	p->u.field.name=name;
	p->att.name=S_str_psfie;
	
	return p;
}
//这个比较特殊，全是标识类型，因此传enum,type_class的字串内容放在属性里。且java的数组只用存层数即可，具体大小由new运行时确定
pS_type MK_pS_type(Att att,enum enStype type,int brackets)
{
	pS_type p = ckmalloc(sizeof(*p));
	p->kind=type;
	p->att=att;
	p->u.brackets=brackets;
	
	return p;
}

pS_statement_block MK_pS_statementblock(Att att,pS_statements states)
{
	pS_statement_block p = ckmalloc(sizeof(*p));
	p->kind=S_statement_block;
	p->att=att;
	p->u.states.states=states;
	p->att.name=S_str_pssb;
	
	return p;
}

pS_statements MK_pS_statements(Att att,pS_statement state,pS_statements next)
{
	pS_statements p = ckmalloc(sizeof(*p));
	p->kind=S_statements;
	p->att=att;
	p->u.states.state=state;
	p->u.states.next=next;
	p->att.name=S_str_psstates;
	
	return p;
}


//语句
pS_statement MK_pS_statement_field(Att att,pS_field field,pS_exp exp,pS_statements next)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_field;
	p->att=att;
	p->u.stafield.field=field;
	p->u.stafield.exp=exp;
	p->u.stafield.next=next;
	p->att.name=S_str_psstate;
	
	return p;
}
pS_statement MK_pS_statement_exp(Att att,pS_exp exp)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_exp;
	p->att=att;
	p->u.staexp.exp=exp;
	p->att.name=S_str_psstate;
	
	return p;
}
pS_statement MK_pS_statement_block(Att att,pS_statement_block block)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_block;
	p->att=att;
	p->u.stablock.block=block;
	p->att.name=S_str_psstate;
	
	return p;
}
pS_statement MK_pS_statement_if(Att att,pS_exp exp ,pS_statement trueblock,pS_statement falseblock)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_if;
	p->att=att;
	p->u.staif.exp=exp;
	p->u.staif.trueblock=trueblock;
	p->u.staif.falseblock=falseblock;
	p->att.name=S_str_psstate;
	
	return p;
}
pS_statement MK_pS_statement_while(Att att,pS_exp exp ,pS_statement block)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_while;
	p->att=att;
	p->u.stawhile.exp=exp;
	p->u.stawhile.block=block;
	p->att.name=S_str_psstate;
	
	return p;
}
pS_statement MK_pS_statement_for(Att att,pS_exp exp1  ,pS_exp exp2 ,pS_exp exp3 ,pS_statement block)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_for;
	p->att=att;
	p->u.stafor.exp1=exp1;
	p->u.stafor.exp2=exp2;
	p->u.stafor.exp3=exp3;
	p->u.stafor.block=block;
	p->att.name=S_str_psstate;
	
	return p;
}
pS_statement MK_pS_statement_return(Att att)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_return;
	p->att=att;
	p->att.name=S_str_psstate;
	
	return p;
}
pS_statement MK_pS_statement_break(Att att)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_break;
	p->att=att;
	p->att.name=S_str_psstate;
	
	return p;
}
pS_statement MK_pS_statement_continue(Att att)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_continue;
	p->att=att;
	p->att.name=S_str_psstate;
	
	return p;
}
 
//表达式
pS_exp MK_pS_exp_op2(Att att,pS_exp exp1,S_op2 op,pS_exp exp2)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_op2;
	p->att=att;
	p->u.expop2.exp1=exp1;
	p->u.expop2.op=op;
	p->u.expop2.exp2=exp2;
	p->att.name=S_str_psexp;
	
	return p;
}
pS_exp MK_pS_exp_op1(Att att,pS_exp exp1,S_op1 op)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_op1;
	p->att=att;
	p->u.expop1.exp1=exp1;
	p->u.expop1.op=op;
	p->att.name=S_str_psexp;
	
	return p;
}
pS_exp MK_pS_exp_new(Att att,pS_type type,pS_args args)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_new;
	p->att=att;
	p->u.expnew.type=type;
	p->u.expnew.args=args;
	p->att.name=S_str_psexp;
	
	return p;
}
pS_exp MK_pS_exp_call(Att att,pS_exp exp,pS_args args)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_call;
	p->att=att;
	p->u.expcall.exp=exp;
	p->u.expcall.args=args;
	p->att.name=S_str_psexp;
	
	return p;
}
pS_exp MK_pS_exp_arry(Att att,pS_exp exp,int arry)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_arry;
	p->att=att;
	p->u.exparry.exp=exp;
	p->u.exparry.arry=arry;
	p->att.name=S_str_psexp;
	
	return p;
}
pS_exp MK_pS_exp_object(Att att,pS_exp exp1,pS_exp exp2)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_object;
	p->att=att;
	p->u.expobject.exp1=exp1;
	p->u.expobject.exp2=exp2;
	p->att.name=S_str_psexp;
	
	return p;
}
pS_exp MK_pS_exp_sym(Att att,pS_symbol sym)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_sym;
	p->att=att;
	p->u.expsym.sym=sym;
	p->att.name=S_str_psexp;
	
	return p;
}
pS_exp MK_pS_exp_char(Att att,char value)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_char;
	p->att=att;
	p->u.expchar.value=value;
	p->att.name=S_str_psexp;
	
	return p;
}
pS_exp MK_pS_exp_str(Att att,char *value)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_string;
	p->att=att;
	p->u.expstr.value=value;
	p->att.name=S_str_psexp;
	
	return p;
}
pS_exp MK_pS_exp_int(Att att,int  value)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_int;
	p->att=att;
	p->u.expint.value=value;
	p->att.name=S_str_psexp;
	
	return p;
}
pS_exp MK_pS_exp_float(Att att,double  value)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_float;
	p->att=att;
	p->u.expfloat.value=value;
	p->att.name=S_str_psexp;
	
	return p;
}
pS_exp MK_pS_exp_null(Att att)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_null;
	p->att=att;
	p->att.name=S_str_psexp;
	
	return p;
}
pS_exp MK_pS_exp_super(Att att)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_super;
	p->att=att;
	p->att.name=S_str_psexp;
	
	return p;
}
pS_exp MK_pS_exp_this(Att att)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_this;
	p->att=att;
	p->att.name=S_str_psexp;
	
	return p;
}
pS_exp MK_pS_exp_true(Att att)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_true;
	p->att=att;
	p->att.name=S_str_psexp;
	
	return p;
}
pS_exp MK_pS_exp_false(Att att)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_false;
	p->att=att;
	p->att.name=S_str_psexp;
	
	return p;
}

pS_args MK_pS_args(Att att,pS_exp exp,pS_args next)
{
	pS_args p = ckmalloc(sizeof(*p));
	p->kind=S_args;
	p->att=att;
	p->u.fieldlist.exp=exp;
	p->u.fieldlist.next=next;
	p->att.name=S_str_psarg;
	
	return p;
}





//-------------show-------------------

void show_pS_method_declaration(pS_method_declaration p,int dp)
{
	int i=0;
	if(p==NULL)
		return;
	for(i=0;i<dp;i++)
		printf("  ");

	//前序本节点处理
	printf("%d-%s \n",p->att.line,p->att.name);


	int nextdp=++dp;
	//子节点处理
	show_pS_symbol(p->u.decfun.name,nextdp);
	show_pS_fieldList(p->u.decfun.fies,nextdp);
	show_pS_type(p->u.decfun.retype,nextdp);
	show_pS_statement_block(p->u.decfun.body,nextdp);




	//后序本节点处理
}
void show_pS_symbol(pS_symbol p,int dp)
{
	int i=0;
	if(p==NULL)
		return;
	for(i=0;i<dp;i++)
		printf("  ");

	//前序本节点处理
	printf("%d-%s: sym-%s \n",p->att.line,p->att.name,p->u.symbol);


	//无子节点-前中后都一样
}
void show_pS_fieldList(pS_fieldList p,int dp)
{
	int i=0;
	if(p==NULL)
		return;
	for(i=0;i<dp;i++)
		printf("  ");

	//前序本节点处理
	printf("%d-%s \n",p->att.line,p->att.name);


	int nextdp=++dp;
	//子节点处理
	show_pS_field(p->u.fieldlist.field,nextdp);
	show_pS_fieldList(p->u.fieldlist.next,nextdp);

	//后序本节点处理
}
void show_pS_field(pS_field p,int dp)
{
	int i=0;
	if(p==NULL)
		return;
	for(i=0;i<dp;i++)
		printf("  ");

	//前序本节点处理
	printf("%d-%s \n",p->att.line,p->att.name);


	int nextdp=++dp;
	//子节点处理
	show_pS_type(p->u.field.type,nextdp);
	show_pS_symbol(p->u.field.name,nextdp);

	//后序本节点处理
}
void show_pS_type(pS_type p,int dp)
{
	int i=0;
	if(p==NULL)
		return;
	for(i=0;i<dp;i++)
		printf("  ");
	//前序本节点处理
	printf("%d-type(%d): name-%s brackets-%d\n",p->att.line,p->kind,p->att.name,p->u.brackets);

	//无子节点
}
void show_pS_statement_block(pS_statement_block p,int dp)
{
	int i=0;
	if(p==NULL)
		return;
	for(i=0;i<dp;i++)
		printf("  ");

	//前序本节点处理
	


	int nextdp=++dp;
	//子节点处理




	//后序本节点处理
}
void show_pS_statements(pS_statements p,int dp)
{
	int i=0;
	if(p==NULL)
		return;
	for(i=0;i<dp;i++)
		printf("  ");

	//前序本节点处理
	


	int nextdp=++dp;
	//子节点处理




	//后序本节点处理
}
void show_pS_statement(pS_statement p,int dp)
{
	int i=0;
	if(p==NULL)
		return;
	for(i=0;i<dp;i++)
		printf("  ");

	//前序本节点处理
	


	int nextdp=++dp;
	//子节点处理




	//后序本节点处理
}
void show_pS_exp(pS_exp p,int dp)
{
	int i=0;
	if(p==NULL)
		return;
	for(i=0;i<dp;i++)
		printf("  ");

	//前序本节点处理
	


	int nextdp=++dp;
	//子节点处理




	//后序本节点处理
}
void show_pS_args(pS_args p,int dp)
{
	int i=0;
	if(p==NULL)
		return;
	for(i=0;i<dp;i++)
		printf("  ");

	//前序本节点处理
	


	int nextdp=++dp;
	//子节点处理




	//后序本节点处理
}