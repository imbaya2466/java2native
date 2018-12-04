#ifndef TREE_H
#define TREE_H
//�����﷨���������������Ľӿڡ�
//Ӧ��������֤������ļ�ࡣ����ͨ��������ֻ�����ע���﷨------��һ��©��һ��
/*
��ʽ�涨��
1. ���������ķ�����
2. ÿ��typedef��Ӧ�ķ��е�һ������
3. typedef�������ָ��struct��ָ�룬struct���������»��߽�����ֻ����typedef
4. ���ڶ����͵Ľڵ㣺һ��kindһ��u��kind��ʾ�����ͣ�uΪһ�����ϡ�����һ��ͳһ�Ľṹ��att��ʾ�ڵ�����
5. ����Я��ֵ(��ʶ��������)����Ϊ�䱾��������������Ϊ�ӽڵ�
6. untion��ÿ��struct��ʾһ���������ӽڵ��ָ�롣����ֵ��ʶ���͵�ֻ��enum�����Լ��ɣ�����ֵ����untion�к�ֵ(������att�н�ʹ����Ҳ��)
7. ÿ���ڵ��ÿ�����Ͷ����乹�캯��
8. ֮����ṩһ�����õ�ͨ�ü���ʵ��
*/
//���ű�ֻ����Ҫ����ռ�ı������ⲿ����
//������һ�ɴ������


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


struct Att_{
	int line;
	char *name;
};
//��������
struct S_method_declaration_{
	enum {S_fun}kind;//��Խ�һ��ʱ����������
	Att att;
	union{
		struct{pS_symbol name;pS_fieldList fies;pS_type retype;pS_statement_block body;}decfun;
	}u;
};

//��ʶ��ע��ָ����ű�
struct S_symbol_{
	enum {S_sym}kind;
	Att att;
	union{
		int symtab;
	}u;
};

//�����б�
struct S_fieldList_{
	enum {S_fiedlist}kind;
	Att att;
	union{
		struct {pS_field field;pS_fieldList next;}fieldlist;
	}u;
};
//����
struct S_field_{
	enum {S_fied}kind;
	Att att;
	union{
		struct {pS_type type;pS_symbol name;}field;
	}u;
};

//����
struct S_type_{
	enum enStype{type_boolean,type_byte,type_char,type_float,type_double,type_int,type_long,type_short,type_void,type_String,type_class}kind;
	Att att;//type_class���ִ����ݷ���������,��Ϊ���Ͳ����ڷ��ű����ű�ֻ������뺯��
	union{
		//�����������Ϣ[]��ǰ������ÿ���㼶..5�����¡���ʾ��ʽ���±�0-5��
		int brackets[5];
	}u;
};
//������������������
struct S_statement_block_{
	enum {S_statement_block}kind;
	Att att;
	union{
		struct {pS_statements states;}states;
	}u;
};
//�����
struct S_statements_{
	enum {S_statements}kind;
	Att att;
	union{
		struct {pS_statement state;pS_statements next;}states;
	}u;
};
//���  break���������飬continue���ڼ���
struct S_statement_{
	enum {sta_field,sta_exp,sta_block,sta_if,sta_while,sta_for,sta_return,sta_break,sta_continue}kind;
	Att att;
	union{
		struct {pS_field field;}stafield;  //�������뱻��Ϊ���state..��ʼ���ݲ�֧��
		struct {pS_exp exp;}staexp;
		struct {pS_statement_block block;}stablock;
		struct {pS_exp exp ;pS_statement_block trueblock;pS_statement_block falseblock; }staif;//������else if�Ȼ�����flaseʱ�ж���һ���block���ݡ�����������ֶ�����block��block�������
		struct {pS_exp exp ;pS_statement_block block;}stawhile;
		struct {pS_exp exp1  ;pS_exp exp2 ;pS_exp exp3 ;pS_statement_block block;}stafor;
		//��������Ϊenum�ɱ�ʾ�ı�ʶ��
	}u;
};
//���ʽ ע�������д�����  ��������string�����ڳ�������
enum S_op2_{
	//+     -        *     /       %    ==    !=      >         <      >=       <=     &       |     ^      <<    >>      >>>     &&    ||
	S_ADD ,S_SUB ,S_MUL ,S_DIV ,S_MOD ,S_CMP ,S_NCMP ,S_MORE ,S_LESS ,S_MCMP ,S_LCMP ,S_AND ,S_OR ,S_XOR ,S_SHL ,S_SHR ,S_SAR ,S_BAND ,S_BOR
	// =     +=         -=         +=         /=        %=        <<=     >>=        &=        ^=        |=
	,S_MOV ,S_ADDMOV ,S_SUBMOV ,S_MULMOV ,S_DIVMOV ,S_MODMOV ,S_SHLMOV ,S_SHRMOV ,S_ANDMOV ,S_XORMOV ,S_ORMOV
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
		struct {pS_type type;pS_args args ;}expnew;//��Ϊ���Ͳ����ڷ��ű���������type��ʵ�����Զ���Ľṹ����Ӧ��ͬ�������ڷ��ű�ģ���������򻯾Ͳ�����
		struct {pS_exp exp;pS_args args;}expcall;
		struct {pS_exp exp;int arry[5];}exparry;
		struct {pS_exp exp1;pS_exp exp2;}expobject;
		struct {pS_symbol sym;}expsym;
		struct {char value;}expchar;
		struct {int  stringid;}expstr;//ָ�����ִ���
		struct {int  value;}expint;
		struct {float  value;}expfloat;
		//null super this true flase enum����
	}u;
};

//������
struct S_args_{
	enum {S_args}kind;
	Att att;
	union{
		struct {pS_exp exp;pS_args next;}fieldlist;
	}u;
};

//���캯��

pS_method_declaration MK_pS_method_declaration(Att att,pS_symbol name,pS_fieldList fies,pS_type retype,pS_statement_block body);

pS_symbol MK_pS_symbol(Att att,int symtab);

pS_fieldList MK_pS_fieldList(Att att,pS_field field,pS_fieldList next);

pS_field MK_pS_field(Att att,pS_type type,pS_symbol name);
//����Ƚ����⣬ȫ�Ǳ�ʶ���ͣ���˴�enum��ע���Զ�������������att����
pS_type MK_pS_type(Att att,enum enStype type,int brackets[5]);

pS_statement_block MK_pS_statementblock(Att att,pS_statements states);

pS_statements MK_pS_statements(Att att,pS_statement state,pS_statements next);

pS_statement MK_pS_statement_field(Att att,pS_field field);
pS_statement MK_pS_statement_exp(Att att,pS_exp exp);
pS_statement MK_pS_statement_block(Att att,pS_statement_block block);
pS_statement MK_pS_statement_if(Att att,pS_exp exp ,pS_statement_block trueblock,pS_statement_block falseblock;);
pS_statement MK_pS_statement_while(Att att,pS_exp exp ,pS_statement_block block);
pS_statement MK_pS_statement_for(Att att,pS_exp exp1  ,pS_exp exp2 ,pS_exp exp3 ,pS_statement_block block);
pS_statement MK_pS_statement_return(Att att);
pS_statement MK_pS_statement_break(Att att);
pS_statement MK_pS_statement_continue(Att att);
 
pS_exp MK_pS_exp_op2(Att att,pS_exp exp1,S_op2 op,pS_exp exp2);
pS_exp MK_pS_exp_op1(Att att,pS_exp exp1,S_op1 op);
pS_exp MK_pS_exp_new(Att att,pS_type type,pS_args args);
pS_exp MK_pS_exp_call(Att att,pS_exp exp,pS_args args);
pS_exp MK_pS_exp_arry(Att att,pS_exp exp,int arry[5]);
pS_exp MK_pS_exp_object(Att att,pS_exp exp1,pS_exp exp2);
pS_exp MK_pS_exp_sym(Att att,pS_symbol sym);
pS_exp MK_pS_exp_char(Att att,char value);
pS_exp MK_pS_exp_str(Att att,int stringid);
pS_exp MK_pS_exp_int(Att att,int  value);
pS_exp MK_pS_exp_float(Att att,float  value);
pS_exp MK_pS_exp_null(Att att);
pS_exp MK_pS_exp_super(Att att);
pS_exp MK_pS_exp_this(Att att);
pS_exp MK_pS_exp_true(Att att);
pS_exp MK_pS_exp_false(Att att);

pS_args MK_pS_args(Att att,pS_exp exp,pS_args next);


#endif