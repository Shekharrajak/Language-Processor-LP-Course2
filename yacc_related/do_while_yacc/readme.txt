Output:

students@ccflab-desktop:~$ lex dowh.l
students@ccflab-desktop:~$ yacc dowh.y
conflicts: 2 shift/reduce
students@ccflab-desktop:~$ gcc y.tab.c -ll -ly
students@ccflab-desktop:~$ ./a.out
Enter the exp: do{a=b+1;}while(a<10);
Input accepted.
students@ccflab-desktop:~$