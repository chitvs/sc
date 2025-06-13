.globl count_tokens

count_tokens:
    pushl %ebx
    pushl %esi
    subl $8, %esp
    movl 20(%esp), %ecx
    movl 24(%esp), %esi
    movl $0, %ebx
    movl %ecx, (%esp)
    movl %esi, 4(%esp)
    call strtok
L:
    cmpl $0, %eax
    je E
    incl %ebx
    movl $0, (%esp)
    movl %esi, 4(%esp)
    call strtok
    jmp L
E:
    movl %ebx, %eax
    addl $8, %esp
    popl %esi
    popl %ebx
    ret
