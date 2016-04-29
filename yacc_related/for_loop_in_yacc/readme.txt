Output:
nn@linuxmint ~ $ lex for.l
nn@linuxmint ~ $ yacc for.y
conflicts: 25 shift/reduce, 4 reduce/reduce
nn@linuxmint ~ $ gcc y.tab.c -ll -ly
nn@linuxmint ~ $ ./a.out
Enter the expression:
for(i=0;i<n;i++)
i=i+1;
Input accepted
nn@linuxmint ~ $