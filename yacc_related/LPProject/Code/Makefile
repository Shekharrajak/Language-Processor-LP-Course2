project:	lexfile.l yaccfile.y
		bison -d yaccfile.y
		flex lexfile.l
		gcc -o $@ yaccfile.tab.c lex.yy.c -lfl