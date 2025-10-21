.globl cond_compute

cond_compute:
    pushl %edi 
    pushl %esi 
    pushl %ebp
    pushl %ebx
    subl $4, %esp
    xorl %edi, %edi
    movl 36(%esp), %esi
    movl 24(%esp), %ebp
    movl 28(%esp), %ebx
L:
    cmpl 32(%esp), %edi 
    jge RET 
    movw (%ebp, %edi, 2), %cx
    cmpl $0, (%ebx, %edi, 4)
    je L2 
    movw %cx, (%esp)
    call compute 
    movw %ax, (%esi, %edi, 2)
    incl %edi 
    jmp L 
L2:
    movw %cx, (%esi, %edi, 2)
    incl %edi 
    jmp L 
RET:
    movl %esi, %eax
    addl $4, %esp
    popl %ebx
    popl %ebp
    popl %esi
    popl %edi 
    ret
