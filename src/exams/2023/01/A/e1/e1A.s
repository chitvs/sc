.globl strings_are_upper

strings_are_upper:
    pushl %edi 
    pushl %esi 
    pushl %ebx 
    pushl %ebp
    subl $4, %esp
    cmpl $0, 24(%esp)
    je E1 
    cmpl $0, 28(%esp)
    jle E1
    movl 28(%esp), %eax
    imull $4, %eax
    movl %eax, (%esp)
    call malloc
    movl %eax, %edi 
    xorl %esi, %esi 
    movl 24(%esp), %ebp 
L:
    cmpl 28(%esp), %esi
    jge E2
    movl (%ebp, %esi, 4), %ebx
    movl $1, (%edi, %esi, 4)
L2:
    cmpb $0, (%ebx)
    je NEXT 
    movsbl (%ebx), %eax
    subl $4, %esp
    movl %eax, (%esp)
    call isupper 
    addl $4, %esp
    cmpl $0, %eax
    je L3
    incl %ebx
    jmp L2 
L3:
    movl $0, (%edi, %esi, 4)
    jmp NEXT 
NEXT:
    incl %esi 
    jmp L 
E1:
    movl $0, %eax 
    jmp RET
E2:
    movl %edi, %eax 
    jmp RET
RET:
    addl $4, %esp
    popl %ebp
    popl %ebx
    popl %esi 
    popl %edi
    ret
