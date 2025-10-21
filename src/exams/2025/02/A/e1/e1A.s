.globl count_tokens

count_tokens:
    pushl %edi 
    pushl %ebx 
    pushl %esi 
    subl $8, %esp
    xorl %edi, %edi 
    movl 28(%esp), %esi
    movl 24(%esp), %eax
    movl %eax, (%esp)
    movl %esi, 4(%esp)
    call strtok
    movl %eax, %ebx
L:
    cmpl $0, %ebx
    je RET
    incl %edi 
    movl $0, (%esp)
    movl %esi, 4(%esp)
    call strtok
    movl %eax, %ebx
    jmp L
RET:
    movl %edi, %eax
    addl $8, %esp
    popl %esi 
    popl %ebx 
    popl %edi 
    ret
