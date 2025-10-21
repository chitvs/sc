.globl binsearch

binsearch:
    pushl %ebx
    pushl %esi
    pushl %edi
    movl 16(%esp), %ebx
    movl 20(%esp), %ecx
    movl 24(%esp), %edx
    movl $0, %eax
    xorl %esi, %esi
L:
    cmpl %ecx, %esi
    jge E
    movl %esi, %edi
    addl %ecx, %edi
    sarl $1, %edi 
    cmpl %edx, (%ebx, %edi, 4)
    jne  L1                   
    movl $1, %eax
    jmp E
L1:
    cmpl %edx, (%ebx, %edi, 4)
    jle L2
    movl %edi, %ecx          
    jmp L
L2:
    movl %edi, %esi
    incl %esi
    jmp L
E:
    popl %edi
    popl %esi
    popl %ebx
    ret
