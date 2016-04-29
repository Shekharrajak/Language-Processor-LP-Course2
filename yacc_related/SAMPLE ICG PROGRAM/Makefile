ts:lexrule.l yaccrule.y codegener.cpp 
	bison -o rule.c  -d  yaccrule.y -Wno
	lex -o lex.c  lexrule.l 
	g++ -o ts rule.c lex.c -lfl -lm  -w
.PHONY: clean    
clean:
	rm rule.c lex.c rule.h ts