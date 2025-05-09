.globl suffix

suffix:
    pushl %ebx
    pushl %ebp
    pushl %esi 
    pushl %edi
    subl $4, %esp
    movl 24(%esp), %ebx
    movl 28(%esp), %ebp
    movl %ebx, (%esp)
    call strlen
    movl %eax, %esi
    movl %ebp, (%esp)
    call strlen
    movl %eax, %edi
    cmpl %esi, %edi
    jg E1
    movl %esi, %ecx 
    subl %edi, %ecx
L:
    cmpl %esi, %ecx 
    jge E2
    movb (%ebp), %dl
    cmpb (%ebx, %ecx), %dl
    jne E1
    incl %ebp
    incl %ecx 
    jmp L
E1:
    movl $0, %eax
    jmp E3
E2:
    movl $1, %eax
    jmp E3
E3:
    addl $4, %esp
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret
