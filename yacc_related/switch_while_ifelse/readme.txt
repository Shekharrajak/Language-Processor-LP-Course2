nn@linuxmint ~ $ lex pars.l
nn@linuxmint ~ $ yacc pars.y
conflicts: 5 shift/reduce
nn@linuxmint ~ $ gcc y.tab.c -ll -ly
nn@linuxmint ~ $ ./a.out

Enter the expression: switch(s)
{
case 1:a=b+c;break;
case 2:    if(a<10)
    then a=b*c;
    break;
case 3:    while(a<5)
    b=b+a;
    break;
}

Input accepted.
nn@linuxmint ~ $ 