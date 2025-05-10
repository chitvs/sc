.globl crc32

crc32:
    pushl %ebx
    pushl %ebp
    pushl %edi 
    pushl %esi
    movl 20(%esp), %ebx
    movl 24(%esp), %ebp
    xorl %edi, %edi
    movl $0xFFFFFFFF, %eax
L1:
    cmpl %ebp, %edi 
    jge E 
    movzbl (%ebx, %edi, 1), %ecx
    xorl %ecx, %eax
    xorl %esi, %esi
L2:
    cmpl $8, %esi
    jge NEXT
    movl $1, %edx
    andl %eax, %edx
    negl %edx
    andl $0xEDB88320, %edx
    sarl $1, %eax
    xorl %edx, %eax
    incl %esi
    jmp L2
NEXT:
    incl %edi 
    jmp L1
E:
    popl %esi
    popl %edi
    popl %ebp
    popl %ebx
    notl %eax
    ret
