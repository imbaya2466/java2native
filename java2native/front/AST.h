#ifndef AST_H
#define AST_H
//这是语法分析与语义分析间的接口。注意生成抽象树时不要带语义分析的产物
//应当尽力保证这个树的简洁。并且通过抽象树只处理关注的语法------像一个漏斗一样
/*
格式规定：
1. 树可以用文法描述
2. 每个typedef对应文法中的一个符号
3. typedef定义的是指向struct的指针，struct的名字以下划线结束，只用于typedef
4. 对于多类型的节点：一个kind一个u，kind表示其类型，u为一个联合。还有一个统一的结构体att表示节点属性
5. 对于携带值(标识符、常数)。因为其本身有属性所以作为子节点
6. untion中每个struct表示一种类型下子节点的指针。对于值标识类型的只有enum与属性即可，对于值类型untion中含值(若放在att中将使其它也带)
7. 每个节点的每个类型都有其构造函数
8. 之后会提供一个我用的通用简单树实现
*/
//符号表只放需要分配空间的变量和外部变量
//类型名一律存进树中


typedef struct Att_ Att;
typedef struct S_method_declaration_ *pS_method_declaration;
typedef struct S_symbol_ *pS_symbol;
typedef struct S_fieldList_ *pS_fieldList;
typedef struct S_field_ *pS_field;
typedef struct S_type_ *pS_type;
typedef struct S_statement_block_ *pS_statement_block;
typedef struct S_statements_ *pS_statements;
typedef struct S_statement_ *pS_statement;
typedef struct S_exp_ *pS_exp;
typedef struct S_args_ *pS_args;
typedef enum S_op2_ S_op2;
typedef enum S_op1_ S_op1;

//AST属性
struct Att_{
	int line;
	char *name;
};
//函数定义
struct S_method_declaration_{
	enum {S_fun}kind;//针对仅一种时此项暂无用
	Att att;
	union{
		struct{pS_symbol name;pS_fieldList fies;pS_type retype;pS_statement_block body;}decfun;
	}u;
};

//标识符注意抽象语法树中还是存标识符本体，符号表是在语义分析时生成的
struct S_symbol_{
	enum {S_sym}kind;
	Att att;
	union{
		char *symbol;
	}u;
};

//参数列表  当最后一个参数时next为null
struct S_fieldList_{
	enum {S_fiedlist}kind;
	Att att;
	union{
		struct {pS_field field;pS_fieldList next;}fieldlist;
	}u;
};
//参数
struct S_field_{
	enum {S_fied}kind;
	Att att;
	union{
		struct {pS_type type;pS_symbol name;}field;
	}u;
};

//类型
struct S_type_{
	enum enStype{type_boolean,type_byte,type_char,type_float,type_double,type_int,type_long,type_short,type_void,type_String,type_class}kind;
	Att att;//type_class的字串内容放在属性里,因为类型不属于符号表，符号表只存变量与函数
	union{
		//java类型只需要知道数组几层就行了，只有在new时才能确定具体每层大小，是运行时确定的
		int brackets;
	}u;
};
//语句块用于区分作用域
struct S_statement_block_{
	enum {S_statement_block}kind;
	Att att;
	union{
		struct {pS_statements states;}states;
	}u;
};
//语句链
struct S_statements_{
	enum {S_statements}kind;
	Att att;
	union{
		struct {pS_statement state;pS_statements next;}states;
	}u;
};
//语句  break用于跳出块，continue用于加速
struct S_statement_{
	enum {sta_field,sta_exp,sta_block,sta_if,sta_while,sta_for,sta_return,sta_break,sta_continue}kind;
	Att att;
	union{
		struct {pS_field field;pS_exp exp;pS_statements next;}stafield;  //连续申请被化为多个state..初始化可以化为多一条exp语句
		struct {pS_exp exp;}staexp;
		struct {pS_statement_block block;}stablock;
		struct {pS_exp exp ;pS_statement trueblock;pS_statement falseblock; }staif;//本质上else if等还是在flase时判断下一句的block内容。所有域的区分都丢给block。block可用外的
		struct {pS_exp exp ;pS_statement block;}stawhile;
		struct {pS_exp exp1  ;pS_exp exp2 ;pS_exp exp3 ;pS_statement block;}stafor;//暂不支持exp1中声明。
		//其他三个为enum可表示的标识符
	}u;
};
//表达式 注意属性中带类型  常数除了string都留在抽象树中
enum S_op2_{
	//+     -        *     /       %    ==    !=      >         <      >=       <=     &       |     ^      <<    >>      >>>     &&    ||
	S_ADD ,S_SUB ,S_MUL ,S_DIV ,S_MOD ,S_CMP ,S_NCMP ,S_MORE ,S_LESS ,S_MCMP ,S_LCMP ,S_AND ,S_OR ,S_XOR ,S_SHL ,S_SHR ,S_SAR ,S_BAND ,S_BOR
	// =     +=         -=         +=         /=        %=        <<=     >>=        &=        ^=        |=     ,
	,S_MOV ,S_ADDMOV ,S_SUBMOV ,S_MULMOV ,S_DIVMOV ,S_MODMOV ,S_SHLMOV ,S_SHRMOV ,S_ANDMOV ,S_XORMOV ,S_ORMOV ,S_COMMA
};
enum S_op1_{
	//++      --      ~     -        !
	S_ADD2 ,S_SUB2 ,S_NOT ,S_SUB1 ,S_BNOT
};
struct S_exp_{
	enum {exp_op2,exp_op1,exp_new,exp_call,exp_arry,exp_object,exp_sym,exp_char,exp_string,exp_int,exp_float,exp_null,exp_super,exp_this,exp_true,exp_false}kind;
	Att att;
	union{
		struct {pS_exp exp1;S_op2 op;pS_exp exp2;}expop2;
		struct {pS_exp exp1;S_op1 op;}expop1;
		struct {pS_type type;pS_args args ;}expnew;//new数组时数组信息由args提供，因为exp可以表示数组维度。同时new的含义本身就为type为类型，args为信息。吻合
		struct {pS_exp exp;pS_args args;}expcall;
		struct {pS_exp exp;int arry;}exparry;//arry这里访问需要数组坐标，多维度通过嵌套表示
		struct {pS_exp exp1;pS_exp exp2;}expobject;
		struct {pS_symbol sym;}expsym;
		struct {char value;}expchar;
		struct {char  *value;}expstr;//常量表在构造AST时统计，构造AST后统一分配
		struct {int  value;}expint;
		struct {double  value;}expfloat;
		//null super this true flase enum足以
	}u;
};

//参数链
struct S_args_{
	enum {S_args}kind;
	Att att;
	union{
		struct {pS_exp exp;pS_args next;}fieldlist;
	}u;
};

//构造函数

pS_method_declaration MK_pS_method_declaration(Att att,pS_symbol name,pS_fieldList fies,pS_type retype,pS_statement_block body);

pS_symbol MK_pS_symbol(Att att,char* symbol);

pS_fieldList MK_pS_fieldList(Att att,pS_field field,pS_fieldList next);

pS_field MK_pS_field(Att att,pS_type type,pS_symbol name);
//这个比较特殊，全是标识类型，因此传enum且注意自定义类型名置于att名中
pS_type MK_pS_type(Att att,enum enStype type,int brackets);

pS_statement_block MK_pS_statementblock(Att att,pS_statements states);

pS_statements MK_pS_statements(Att att,pS_statement state,pS_statements next);

pS_statement MK_pS_statement_field(Att att,pS_field field,pS_exp exp,pS_statements next);
pS_statement MK_pS_statement_exp(Att att,pS_exp exp);
pS_statement MK_pS_statement_block(Att att,pS_statement_block block);
pS_statement MK_pS_statement_if(Att att,pS_exp exp ,pS_statement trueblock,pS_statement falseblock);
pS_statement MK_pS_statement_while(Att att,pS_exp exp ,pS_statement block);
pS_statement MK_pS_statement_for(Att att,pS_exp exp1  ,pS_exp exp2 ,pS_exp exp3 ,pS_statement block);
pS_statement MK_pS_statement_return(Att att);
pS_statement MK_pS_statement_break(Att att);
pS_statement MK_pS_statement_continue(Att att);
 
pS_exp MK_pS_exp_op2(Att att,pS_exp exp1,S_op2 op,pS_exp exp2);
pS_exp MK_pS_exp_op1(Att att,pS_exp exp1,S_op1 op);
pS_exp MK_pS_exp_new(Att att,pS_type type,pS_args args);
pS_exp MK_pS_exp_call(Att att,pS_exp exp,pS_args args);
pS_exp MK_pS_exp_arry(Att att,pS_exp exp,int arry);
pS_exp MK_pS_exp_object(Att att,pS_exp exp1,pS_exp exp2);
pS_exp MK_pS_exp_sym(Att att,pS_symbol sym);
pS_exp MK_pS_exp_char(Att att,char value);
pS_exp MK_pS_exp_str(Att att,char *value);
pS_exp MK_pS_exp_int(Att att,int  value);
pS_exp MK_pS_exp_float(Att att,double value);
pS_exp MK_pS_exp_null(Att att);
pS_exp MK_pS_exp_super(Att att);
pS_exp MK_pS_exp_this(Att att);
pS_exp MK_pS_exp_true(Att att);
pS_exp MK_pS_exp_false(Att att);

pS_args MK_pS_args(Att att,pS_exp exp,pS_args next);


//show函数-因为每个节点都不一样因此拆分函数分别处理

void show_pS_method_declaration(pS_method_declaration p,int dp);
void show_pS_symbol(pS_symbol p,int dp);
void show_pS_fieldList(pS_fieldList p,int dp);
void show_pS_field(pS_field p,int dp);
void show_pS_type(pS_type p,int dp);
void show_pS_statement_block(pS_statement_block p,int dp);
void show_pS_statements(pS_statements p,int dp);
void show_pS_statement(pS_statement p,int dp);
void show_pS_exp(pS_exp p,int dp);
void show_pS_args(pS_args p,int dp);



#endif