.globl slice

slice:
    pushl %ebx
    pushl %edi 
    pushl %esi 
    subl $12, %esp
    movl 28(%esp), %ebx
    xorl %esi, %esi 
    movl 32(%esp), %ecx
    movl 36(%esp), %edi
    subl %ecx, %edi
    subl $1, %edi
L:
    cmpb $0, (%ebx)
    je E1
    cmpl 32(%esp), %esi
    je E0
    incl %esi 
    incl %ebx
    jmp L
E0:
    incl %esi 
    movl %ebx, (%esp)
    movl %edi, 4(%esp)
    movl 40(%esp), %edx
    movl %edx, 8(%esp)
    call slice_helper
    incl %ebx
    jmp L
E1:
    cmpl 32(%esp), %esi
    jl E2
    jmp RET
E2:
    movl $0, %edi 
RET:
    movl %edi, %eax 
    addl $12, %esp
    popl %esi 
    popl %edi 
    popl %ebx
    ret
