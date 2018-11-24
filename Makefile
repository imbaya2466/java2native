

COMPILER_BUILD = lex.yy.c java.tab.c 
COMPILER_CLEAN = lex.yy.c java.tab.c java2native java.tab.h

LEX_SRC = java.l
YACC_SRC = java.y


java2native: $(COMPILER_BUILD)
	gcc -o $@ $(COMPILER_BUILD)
	
lex.yy.c: $(LEX_SRC)
	flex $(LEX_SRC)
	
java.tab.c: $(YACC_SRC)
	bison -d $(YACC_SRC)

clean:
	rm -f $(COMPILER_CLEAN)
