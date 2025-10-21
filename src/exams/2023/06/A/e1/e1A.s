.globl rc4_encrypt

rc4_encrypt:
    pushl %edi
    pushl %ebp
    pushl %esi
    pushl %ebx
    subl $16, %esp
    movl 40(%esp), %ebp
    xorl %esi, %esi 
    xorl %edi, %edi
    xorb %bl, %bl 
L:
    cmpb $0, (%ebp)
    je E
    incl %edi
    andl $255, %edi
    movl 36(%esp), %eax
    movb (%eax, %edi, 1), %cl
    addb %cl, %bl
    movl %eax, (%esp)
    movl %edi, 4(%esp)
    movb %bl, 8(%esp)
    leal 12(%esp), %edx
    movl %edx, 12(%esp)
    call rc4_helper
    movl 44(%esp), %eax 
    movb (%ebp), %cl
    movl 12(%esp), %edx
    xorb %dl, %cl
    movb %cl, (%eax, %esi, 1)
    incl %esi
    incl %ebp   
    jmp L
E:
    addl $16, %esp
    popl %ebx
    popl %esi
    popl %ebp
    popl %edi
    ret
