#include "AST.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void * ckmalloc(int size)
{
	void *p=malloc(size);

		assert(p);
	return p;
}



pS_method_declaration MK_pS_method_declaration(Att att,pS_symbol name,pS_fieldList fies,pS_type retype,pS_statement_block body)
{
	pS_method_declaration p = ckmalloc(sizeof(*p));
	p->kind=S_fun;
	p->att=att;
	p->u.decfun.name=name;
	p->u.decfun.fies=fies;
	p->u.decfun.retype=retype;
	p->u.decfun.body=body;
	p->att.name=strdup("method_declaration");
	
	return p;
}
pS_symbol MK_pS_symbol(Att att,int symtab)
{
	pS_symbol p = ckmalloc(sizeof(*p));
	p->kind=S_sym;
	p->att=att;//att中有符号名字
	p->u.symtab=symtab;//符号表索引
	
	return p;
}

pS_fieldList MK_pS_fieldList(Att att,pS_field field,pS_fieldList next)
{
	pS_fieldList p = ckmalloc(sizeof(*p));
	p->kind=S_fiedlist;
	p->att=att;
	p->u.fieldlist.field=field;
	p->u.fieldlist.next=next;
	p->att.name=strdup("fieldList");
	
	return p;
}

pS_field MK_pS_field(Att att,pS_type type,pS_symbol name)
{
	pS_field p = ckmalloc(sizeof(*p));
	p->kind=S_fied;
	p->att=att;
	p->u.field.type=type;
	p->u.field.name=name;
	p->att.name=strdup("field");
	
	return p;
}
//这个比较特殊，全是标识类型，因此传enum,type_class的字串内容放在属性里
pS_type MK_pS_type(Att att,enum enStype type,int brackets[5])
{
	pS_type p = ckmalloc(sizeof(*p));
	p->kind=type;
	p->att=att;
	memcpy(p->u.brackets, brackets,5*sizeof(int));
	
	return p;
}

pS_statement_block MK_pS_statementblock(Att att,pS_statements states)
{
	pS_statement_block p = ckmalloc(sizeof(*p));
	p->kind=S_statement_block;
	p->att=att;
	p->u.states.states=states;
	p->att.name=strdup("statement_block");
	
	return p;
}

pS_statements MK_pS_statements(Att att,pS_statement state,pS_statements next)
{
	pS_statements p = ckmalloc(sizeof(*p));
	p->kind=S_statements;
	p->att=att;
	p->u.states.state=state;
	p->u.states.next=next;
	p->att.name=strdup("statements");
	
	return p;
}


//语句
pS_statement MK_pS_statement_field(Att att,pS_field field)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_field;
	p->att=att;
	p->u.stafield.field=field;
	p->att.name=strdup("statement_field");
	
	return p;
}
pS_statement MK_pS_statement_exp(Att att,pS_exp exp)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_exp;
	p->att=att;
	p->u.staexp.exp=exp;
	p->att.name=strdup("statement_exp");
	
	return p;
}
pS_statement MK_pS_statement_block(Att att,pS_statement_block block)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_block;
	p->att=att;
	p->u.stablock.block=block;
	p->att.name=strdup("statement_bloc");
	
	return p;
}
pS_statement MK_pS_statement_if(Att att,pS_exp exp ,pS_statement_block trueblock,pS_statement_block falseblock)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_if;
	p->att=att;
	p->u.staif.exp=exp;
	p->u.staif.trueblock=trueblock;
	p->u.staif.falseblock=falseblock;
	p->att.name=strdup("statement_if");
	
	return p;
}
pS_statement MK_pS_statement_while(Att att,pS_exp exp ,pS_statement_block block)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_while;
	p->att=att;
	p->u.stawhile.exp=exp;
	p->u.stawhile.block=block;
	p->att.name=strdup("statement_while");
	
	return p;
}
pS_statement MK_pS_statement_for(Att att,pS_exp exp1  ,pS_exp exp2 ,pS_exp exp3 ,pS_statement_block block)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_for;
	p->att=att;
	p->u.stafor.exp1=exp1;
	p->u.stafor.exp2=exp2;
	p->u.stafor.exp3=exp3;
	p->u.stafor.block=block;
	p->att.name=strdup("statement_for");
	
	return p;
}
pS_statement MK_pS_statement_return(Att att)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_return;
	p->att=att;
	p->att.name=strdup("return");
	
	return p;
}
pS_statement MK_pS_statement_break(Att att)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_break;
	p->att=att;
	p->att.name=strdup("break");
	
	return p;
}
pS_statement MK_pS_statement_continue(Att att)
{
	pS_statement p = ckmalloc(sizeof(*p));
	p->kind=sta_continue;
	p->att=att;
	p->att.name=strdup("continue");
	
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
	p->att.name=strdup("exp_op2");
	
	return p;
}
pS_exp MK_pS_exp_op1(Att att,pS_exp exp1,S_op1 op)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_op1;
	p->att=att;
	p->u.expop1.exp1=exp1;
	p->u.expop1.op=op;
	p->att.name=strdup("exp_op1");
	
	return p;
}
pS_exp MK_pS_exp_new(Att att,pS_type type,pS_args args)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_new;
	p->att=att;
	p->u.expnew.type=type;
	p->u.expnew.args=args;
	p->att.name=strdup("exp_new");
	
	return p;
}
pS_exp MK_pS_exp_call(Att att,pS_exp exp,pS_args args)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_call;
	p->att=att;
	p->u.expcall.exp=exp;
	p->u.expcall.args=args;
	p->att.name=strdup("exp_call");
	
	return p;
}
pS_exp MK_pS_exp_arry(Att att,pS_exp exp,int arry[5])
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_arry;
	p->att=att;
	p->u.exparry.exp=exp;
	memcpy(p->u.exparry.arry, arry,5*sizeof(int));
	p->att.name=strdup("exp_arry");
	
	return p;
}
pS_exp MK_pS_exp_object(Att att,pS_exp exp1,pS_exp exp2)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_object;
	p->att=att;
	p->u.expobject.exp1=exp1;
	p->u.expobject.exp2=exp2;
	p->att.name=strdup("exp_object");
	
	return p;
}
pS_exp MK_pS_exp_sym(Att att,pS_symbol sym)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_sym;
	p->att=att;
	p->u.expsym.sym=sym;
	p->att.name=strdup("exp_sym");
	
	return p;
}
pS_exp MK_pS_exp_char(Att att,char value)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_char;
	p->att=att;
	p->u.expchar.value=value;
	p->att.name=strdup("exp_char");
	
	return p;
}
pS_exp MK_pS_exp_str(Att att,int stringid)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_string;
	p->att=att;
	p->u.expstr.stringid=stringid;
	p->att.name=strdup("exp_str");
	
	return p;
}
pS_exp MK_pS_exp_int(Att att,int  value)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_int;
	p->att=att;
	p->u.expint.value=value;
	p->att.name=strdup("exp_int");
	
	return p;
}
pS_exp MK_pS_exp_float(Att att,float  value)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_float;
	p->att=att;
	p->u.expfloat.value=value;
	p->att.name=strdup("exp_float");
	
	return p;
}
pS_exp MK_pS_exp_null(Att att)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_null;
	p->att=att;
	p->att.name=strdup("exp_null");
	
	return p;
}
pS_exp MK_pS_exp_super(Att att)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_super;
	p->att=att;
	p->att.name=strdup("exp_super");
	
	return p;
}
pS_exp MK_pS_exp_this(Att att)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_this;
	p->att=att;
	p->att.name=strdup("exp_this");
	
	return p;
}
pS_exp MK_pS_exp_true(Att att)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_true;
	p->att=att;
	p->att.name=strdup("exp_true");
	
	return p;
}
pS_exp MK_pS_exp_false(Att att)
{
	pS_exp p = ckmalloc(sizeof(*p));
	p->kind=exp_false;
	p->att=att;
	p->att.name=strdup("exp_false");
	
	return p;
}

pS_args MK_pS_args(Att att,pS_exp exp,pS_args next)
{
	pS_args p = ckmalloc(sizeof(*p));
	p->kind=S_args;
	p->att=att;
	p->u.fieldlist.exp=exp;
	p->u.fieldlist.next=next;
	p->att.name=strdup("S_args");
	
	return p;
}