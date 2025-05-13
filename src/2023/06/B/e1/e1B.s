.globl rc4_encrypt_rev

rc4_encrypt_rev:
    pushl %esi
    pushl %ebx
    pushl %edi 
    pushl %ebp
    subl $12, %esp
    xorl %esi, %esi
    xorb %bl, %bl
    movl 36(%esp), %ebp
    movl 40(%esp), %edi
    movl %ebp, (%esp)
    call strlen
    addl %eax, %ebp
    decl %ebp
L:
    cmpl 36(%esp), %ebp
    jl E
    incl %esi
    andl $255, %esi
    movl 32(%esp), %eax
    addb (%eax, %esi, 1), %bl 
    movl %eax, (%esp)
    movl %esi, 4(%esp)
    movb %bl, 8(%esp)
    call rc4_helper
    movb (%ebp), %ah
    movb %al, (%edi)
    xorb %ah, (%edi)
    incl %edi
    decl %ebp
    jmp L
E:
    addl $12, %esp
    popl %ebp
    popl %edi
    popl %ebx
    popl %esi
    ret
