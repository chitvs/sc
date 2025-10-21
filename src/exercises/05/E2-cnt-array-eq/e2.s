.globl counteq

counteq:
    pushl %edi
    pushl %esi
    pushl %ebx
    movl 16(%esp), %edi
    movl 20(%esp), %esi
    movl 24(%esp), %ecx
    movl $0, %eax
    decl %ecx

L:
    cmpl $0, %ecx
    jl E
    movw (%edi, %ecx, 2), %bx
    movw (%esi, %ecx, 2), %dx
    cmpw %bx, %dx
    sete %dl
    movsbl %dl, %edx
    addl %edx, %eax
    decl %ecx
    jmp L

E:
    popl %ebx
    popl %esi
    popl %edi
    ret
