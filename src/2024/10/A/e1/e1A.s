.globl cond_compute

cond_compute:
    pushl %esi 
    pushl %ebx
    pushl %edi 
    subl $8, %esp
    movl 36(%esp), %edi
    movl 24(%esp), %ebx
L:
    cmpl 32(%esp), %esi
    jge RET 
    movb (%ebx, %esi, 1), %cl 
    movb %cl, (%edi, %esi, 1)
    movl 28(%esp), %edx
    cmpl $0, (%edx, %esi, 4)
    je NEXT 
    movb %cl, (%esp)
    leal 4(%esp), %eax
    movl %eax, 4(%esp)
    call compute
    movb 4(%esp), %al
    movb %al, (%edi, %esi, 1)
    incl %esi
    jmp L  
NEXT:
    incl %esi
    jmp L    
RET:
    movl %edi, %eax
    addl $8, %esp
    popl %edi 
    popl %ebx
    popl %esi
    ret
