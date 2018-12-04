
FRONT = front/
TOOL = tool/
HEARD = .
#注意用-I指定编译要包含头文件的位置

COMPILER_CLEAN = $(FRONT)lex.yy.c $(FRONT)java.tab.c $(FRONT)java.tab.h java2native

#注意编译顺序，需要先java.tab.c定义好宏
FRONT_BUILD =  $(FRONT)java.tab.c $(FRONT)lex.yy.c
TOOL_BUILD = $(TOOL)tree.c  main.c $(FRONT)AST.c
ALL_NEED = $(TOOL_BUILD) $(FRONT_BUILD)

LEX_SRC = $(FRONT)java.l
YACC_SRC = $(FRONT)java.y


java2native: $(ALL_NEED) 
	gcc -o $@  $(ALL_NEED)  -I $(HEARD)
	
$(FRONT)lex.yy.c: $(LEX_SRC)
	flex -o $@ $(LEX_SRC)
	
$(FRONT)java.tab.c: $(YACC_SRC)
	bison -o $@ -d -v $(YACC_SRC)

clean:
	rm -f $(COMPILER_CLEAN)
