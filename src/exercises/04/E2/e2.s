.globl find

find:
    movl 4(%esp), %ecx
    movl 8(%esp), %eax
    movl 12(%esp), %edx
L:
    cmpl $0, %eax
    jle W
    decl %eax
    cmpl %edx, (%ecx, %eax, 4)
    jne L
    movl $1, %eax
    jmp Z
W:
    movl $0, %eax
    jmp Z
Z:
    ret
