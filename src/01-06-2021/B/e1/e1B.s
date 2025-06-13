.globl adler32_simplified

adler32_simplified:
    pushl %ebx
    pushl %esi
    pushl %edi
    pushl %ebp
    movl 20(%esp), %ebx
    movl 24(%esp), %ecx
    movl $1, %edx
    movl $0, %esi
    movl $0, %edi
L:
    cmpl %ecx, %edi
    jge E
    movzbl (%ebx, %edi), %ebp
    addl %ebp, %edx
    andl $0xFFFF, %edx
    addl %edx, %esi
    andl $0xFFFF, %esi
    incl %edi
    jmp L
E:
    shll $16, %esi
    orl %edx, %esi
    movl %esi, %eax
    popl %ebp
    popl %edi 
    popl %esi 
    popl %ebx
    ret
