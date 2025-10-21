.globl check_quiz

check_quiz:
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi
    subl $4, %esp
    cmpl $0, 24(%esp)
    je E1
    cmpl $0, 28(%esp)
    je E1
    cmpl $0, 32(%esp)
    jle E1
    movl 32(%esp), %edi
    imul $4, %edi 
    movl %edi, (%esp)
    call malloc 
    movl $0, %esi 
    movl $0, %edi 
    movl 24(%esp), %edx
    movl 28(%esp), %ebp
L1:
    cmpl 32(%esp), %edi 
    jge RET 
    movl $0, (%eax, %edi, 4)
    movl $0, %esi 
    jmp L2
L2:
    cmpl $4, %esi
    jge NEXT
    movl (%edx, %edi, 4), %ecx
    movb (%ebp, %esi, 1), %bl
    cmpb (%ecx, %esi, 1), %bl
    je L3
    incl %esi
    jmp L2
L3:
    incl (%eax, %edi, 4)
    incl %esi
    jmp L2
NEXT:
    incl %edi 
    jmp L1
E1:
    movl $0, %eax
    jmp RET
RET:
    addl $4, %esp
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret
