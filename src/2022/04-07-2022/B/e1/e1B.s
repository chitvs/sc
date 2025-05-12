.globl count_matching_vars

count_matching_vars:
    pushl %ebx
    pushl %ebp
    pushl %edi
    movl 16(%esp), %ebx
    movl 20(%esp), %ebp
    cmpl $0, %ebx
    je E1
    cmpl $0, %ebp
    je E1 
    movl $0, %edi
L:
    movl (%ebx), %edx
    cmpl $0, %edx
    je E2
    subl $4, %esp 
    movl %edx, (%esp)
    call getenv
    addl $4, %esp
    cmpl $0, %eax
    je A
    subl $8, %esp
    movl %eax, (%esp)
    movl %ebp, 4(%esp)
    call strstr
    addl $8, %esp
    cmpl $0, %eax
    je A
    incl %edi
    addl $4, %ebx
    jmp L
A:
    addl $4, %ebx
    jmp L 
E1:
    movl $-1, %eax
    jmp RET
E2:
    movl %edi, %eax
    jmp RET
RET:
    popl %edi 
    popl %ebp
    popl %ebx
    ret
