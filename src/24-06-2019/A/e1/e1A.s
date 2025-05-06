.globl init_matrix

init_matrix:
    pushl %esi
    pushl %edi
    pushl %ebx
    pushl %ebp
    subl $8, %esp
    movl 28(%esp), %esi
    movl 32(%esp), %edi
    movl $0, %ebx
F1:
    cmpl %edi, %ebx
    jae E
    movl $0, %ebp
F2:
    cmpl %edi, %ebp
    jae NEXT
    movl %ebx, (%esp)
    movl %ebp, 4(%esp)
    call value
    movl (%esi,%ebx,4), %ecx
    movw %ax, (%ecx,%ebp,2)
    incl %ebp
    jmp F2      
NEXT:
    incl %ebx
    jmp F1
E:
    addl $8, %esp
    popl %ebp
    popl %ebx
    popl %edi 
    popl %esi 
    ret
