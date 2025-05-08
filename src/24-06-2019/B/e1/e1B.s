.globl has_duplicates

has_duplicates:
    pushl %ebx
    pushl %esi
    movl 12(%esp), %ecx
    movl 16(%esp), %eax
    movl $0, %edx
L1:
    cmpl %eax, %edx
    jae E1
    movl %edx, %ebx
    incl %ebx
L2:
    cmpl %eax, %ebx
    jae NEXT
    movw (%ecx, %edx, 2), %si
    cmpw (%ecx, %ebx, 2), %si
    je E2
    incl %ebx
    jmp L2
NEXT:
    incl %edx
    jmp L1
E1:
    xorl %eax, %eax
    jmp E3
E2:
    movl $1, %eax
    jmp E3
E3:
    popl %esi
    popl %ebx
    ret
