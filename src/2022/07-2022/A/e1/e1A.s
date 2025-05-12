.globl count_vars

count_vars:
    pushl %ebx
    pushl %edi 
    pushl %esi 
    pushl %ebp
    movl 20(%esp), %esi
    movl 24(%esp), %edi 
    cmpl $0, %esi
    jz E1 
    cmpl $0, %edi 
    jle E1 
    subl $4, %esp 
    movl %edi, %ecx
    imul $4, %ecx 
    movl %ecx, (%esp)
    call malloc 
    addl $4, %esp
    movl %eax, %ebp
    movl $0, %ebx
L:
    cmpl %edi, %ebx
    jge E2 
    movl (%esi, %ebx, 4), %edx
    subl $4, %esp
    movl %edx, (%esp)
    call getenv
    addl $4, %esp
    cmpl $0, %eax
    jne A
    movl $0, (%ebp, %ebx, 4)
    incl %ebx
    jmp L
A:
    movl $1, (%ebp, %ebx, 4)
    incl %ebx
    jmp L
E1:
    xorl %eax, %eax
    jmp E3 
E2:
    movl %ebp, %eax 
    jmp E3 
E3:
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
