.globl is_suffix

is_suffix:
    pushl %ebx
    pushl %esi
    pushl %edi 
    pushl %ebp
    movl 20(%esp), %ecx
    movl 24(%esp), %edx
L:
    cmpb $0, %cl
    je L2
    incl %ecx
    jmp L
L2:
    cmpb $0, %dl
    je L3
    incl %edx
    jmp L2
L3:
    cmpl %ecx, 20(%esp)
    je E1 
    cmpl %edx, 24(%esp)
    je E1 
    movb (%edx), %bl 
    cmpb (%ecx), %bl
    jne E1 
    decl %ecx
    decl %edx 
    jmp L3
E1:
    xorl %eax, %eax
    cmpl %ecx, 20(%esp)
    jne RET
    movb (%ecx), %bl 
    cmpb %bl, (%edx)
    jne RET
    movl $1, %eax
    jmp RET
RET:
    popl %ebp
    popl %edi 
    popl %esi 
    popl %ebx
    ret
