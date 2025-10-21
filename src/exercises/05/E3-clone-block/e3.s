.globl clone

clone:
    pushl %ebx
    pushl %edi
    pushl %esi
    subl $12, %esp
    movl 28(%esp), %esi
    movl 32(%esp), %ebx
    movl %ebx, (%esp)
    call malloc
    movl %eax, %edi
    movl $0, %eax
    cmp $0, %edi
    je A
    movl %edi, (%esp)
    movl %esi, 4(%esp)
    movl %ebx, 8(%esp)
    call memcpy
    movl %edi, %eax
A:
    addl $12, %esp
    popl %esi
    popl %edi
    popl %ebx
    ret
