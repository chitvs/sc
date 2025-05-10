.globl crc32b

crc32b:
    pushl %ebp
    pushl %ebx
    pushl %edi
    pushl %esi
    subl $8, %esp
    movl 28(%esp), %ebp
    movl 32(%esp), %ebx
    movl $0, %edi
    notl %edi
    movl %edi, %esi
L:
    cmpl $0, %ebx
    je E
    movzbl (%ebp), %edx
    incl %ebp
    movl %edx, %ecx
    xorl %esi, %ecx
    andl $0xFF, %ecx
    leal -4(%esp), %eax
    subl $8, %esp
    movl %eax, (%esp)
    movl %ecx, 4(%esp)
    call get_constant
    addl $8, %esp
    movl -4(%esp), %eax
    sarl $8, %esi
    xorl %eax, %esi
    decl %ebx
    jmp L
E:
    movl %edi, %eax
    xorl %esi, %eax
    addl $8, %esp
    popl %esi
    popl %edi
    popl %ebx
    popl %ebp
    ret
