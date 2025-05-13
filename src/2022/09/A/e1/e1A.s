.globl div_vectors

div_vectors:
    pushl %ebx
    pushl %ebp
    pushl %esi 
    pushl %edi
    movl 20(%esp), %ebx
    movl 24(%esp), %ebp
    movl 28(%esp), %esi
    testl %ebx, %ebx
    je E1
    testl %ebp, %ebp
    je E1
    testl %esi, %esi
    je E1
    movl %esi, %edi 
    imul $4, %edi
    subl $4, %esp
    movl %edi, (%esp)
    call malloc
    addl $4, %esp
    movl $0, %ecx
    movl %eax, %edi
L:
    cmpl %esi, %ecx
    jge E2 

    movl (%ebx, %ecx, 4), %eax
    movl %eax, %edx
    sarl $31, %edx
    idivl (%ebp, %ecx, 4)
    movl %eax, (%edi, %ecx, 4)
    incl %ecx
    jmp L
E1:
    movl $0, %eax
    jmp E3
E2:
    movl %edi, %eax
    jmp E3
E3:
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret
