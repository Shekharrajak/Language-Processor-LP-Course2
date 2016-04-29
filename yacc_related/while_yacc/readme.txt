Output:

students@ccflab-desktop:~$ lex wh.l
students@ccflab-desktop:~$ yacc wh.y
conflicts: 2 shift/reduce
students@ccflab-desktop:~$ gcc y.tab.c -ll -ly
students@ccflab-desktop:~$ ./a.out
Enter the exp: while(a>1){ b=1;}
Input accepted.