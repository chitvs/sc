.globl init_matrix

init_matrix:
    pushl %esi
    pushl %ebx
    pushl %ebp
    subl $8, %esp
    movl 24(%esp), %esi
    movl $0, %ebx
F1:
    cmpl 28(%esp), %ebx
    jae E
    movl $0, %ebp
F2:
    cmpl 28(%esp), %ebp
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
    popl %esi 
    ret
