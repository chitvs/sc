.globl deleetify

deleetify:
    pushl %edi 
    pushl %ebx
    pushl %esi
    subl $8, %esp
    xorl %esi, %esi
    movl 24(%esp), %ebx
    movl 32(%esp), %edi
L:
    cmpl 28(%esp), %esi
    jae RET
    cmpb $57, (%ebx, %esi, 1)
    ja L2
    movb (%ebx, %esi, 1), %cl
    movb %cl, (%esp)
    leal 4(%esp), %eax
    movl %eax, 4(%esp)
    call deleetify_helper
    movb 4(%esp), %al
    movb %al, (%edi, %esi, 1)
    incl %esi
    jmp L
L2:
    movb (%ebx, %esi, 1), %cl
    movb %cl, (%edi, %esi, 1)
    incl %esi
    jmp L
RET:
    addl $8, %esp
    popl %esi
    popl %ebx
    popl %edi
    ret
