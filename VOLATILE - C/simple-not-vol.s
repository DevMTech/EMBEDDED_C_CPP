
    for (i=0;i<77; i++)

        .loc 1 9 0
        xorl    %eax, %eax
        .p2align 2,,3
.L6:

       {x=i+x;}

        .loc 1 10 0
        addl    %eax, %edx
        .loc 1 9 0
        incl    %eax
        cmpl    $76, %eax
        jle     .L6

    printf("x=%d\n",x);

