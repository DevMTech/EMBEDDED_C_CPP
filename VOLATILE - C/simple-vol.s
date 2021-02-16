
    for (i=0;i<77; i++)

        .loc 1 9 0
.LBB2:
        movl    $0, -4(%ebp)

        movl    -4(%ebp), %eax
        .loc 1 6 0
        andl    $-16, %esp
        .loc 1 8 0
        xorl    %edx, %edx
        .loc 1 9 0
        cmpl    $76, %eax
        jg      .L8
        .p2align 2,,3
.L6:

       {x=i+x;}

        .loc 1 10 0
        movl    -4(%ebp), %eax
        addl    %eax, %edx
        .loc 1 9 0
        movl    -4(%ebp), %eax
        incl    %eax
        movl    %eax, -4(%ebp)
        movl    -4(%ebp), %eax
        cmpl    $76, %eax
        jle     .L6
.L8:

    printf("x=%d\n",x);

