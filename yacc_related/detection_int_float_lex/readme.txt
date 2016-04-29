nn@linuxmint ~ $ lex frn.l
nn@linuxmint ~ $ gcc lex.yy.c -ll
nn@linuxmint ~ $ ./a.out<test1.txt
1 Integer
500 Integer
10.1 Float 
.1 Float 
1.0 Float 

nn@linuxmint ~ $

// input : test1.txt

1
500
10.1
.1
1.0