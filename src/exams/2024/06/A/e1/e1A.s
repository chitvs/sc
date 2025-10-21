.globl deleetify

deleetify:
    pushl %esi
    pushl %ebx
    pushl %edi
    subl $4, %esp
    movl 24(%esp), %eax
    movl %eax, (%esp)
    call malloc
    movl 20(%esp), %ebx
    xorl %esi, %esi
    movl %eax, %edi
L:
    cmpl 24(%esp), %esi
    jae RET
    cmpb $57, (%ebx, %esi, 1) 
    ja L2
    movb (%ebx, %esi, 1), %al
    movb %al, (%esp)
    call deleetify_helper
    movb %al, (%edi, %esi, 1)
    incl %esi 
    jmp L
L2:
    movb (%ebx, %esi, 1), %al 
    movb %al, (%edi, %esi, 1)
    incl %esi
    jmp L
RET:
    movl %edi, %eax
    addl $4, %esp
    popl %edi
    popl %ebx
    popl %esi
    ret
