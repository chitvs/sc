.globl hextodec_sum

hextodec_sum:
    pushl %edi 
    pushl %esi 
    pushl %ebp 
    pushl %ebx 
    subl $8, %esp
    xorl %edi, %edi 
    xorl %esi, %esi
    movl 28(%esp), %ebx
L:
    cmpb $0, (%ebx)
    je RET 
    movl %ebx, (%esp)
    leal 4(%esp), %eax
    movl %eax, 4(%esp)
    call hextodec_helper
    movl 4(%esp), %ebp
    movl 32(%esp), %ecx
    cmpl $0, %ebp
    jg L2 
    movl %ebp, (%ecx, %esi, 4)
    incl %esi
    incl %ebx
    incl %ebx
    jmp L
L2:
    addl %ebp, %edi 
    movl %ebp, (%ecx, %esi, 4)
    incl %esi
    incl %ebx
    incl %ebx
    jmp L
RET:
    movl %edi, %eax
    addl $8, %esp
    popl %ebx
    popl %ebp
    popl %esi
    popl %edi
    ret
