.globl adler32

adler32:
    pushl %ebx
    pushl %ebp
    pushl %edi 
    pushl %esi
    subl $4, %esp
    movl 24(%esp), %ebx
    testl %ebx, %ebx
    je E1
    cmpl $0, 28(%esp)
    je E1
    movl $1, %edi 
    movl $0, %esi 
    leal (%esp), %ebp
    movl %ebp, (%esp)
    call get_adler_constant
    movl (%esp), %ebp
    movl $0, %ecx
L:
    cmpl 28(%esp), %ecx
    jge E2
    movl %edi, %eax
    movzbl (%ebx, %ecx, 1), %edx
    addl %edx, %eax
    xorl %edx, %edx
    divl %ebp
    movl %edx, %edi 
    movl %esi, %eax 
    addl %edi, %eax 
    xorl %edx, %edx
    divl %ebp
    movl %edx, %esi 
    incl %ecx
    jmp L
E1:
    movl $0, %eax
    jmp RET
E2:
    sall $16, %esi 
    orl %edi, %esi 
    movl %esi, %eax 
    jmp RET
RET:
    addl $4, %esp
    popl %esi
    popl %edi 
    popl %ebp
    popl %ebx
    ret
