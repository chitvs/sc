.globl list_add_first

list_add_first:
    # PROLOGO
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi

    movl 20(%esp), %ebx
    movw 24(%esp), %bp

    movl (%ebx), %esi

    pushl $8
    call malloc
    addl $4, %esp

    testl %eax, %eax
    je A

    movl %eax, %edi

    movw %bp, (%edi)
    movl %esi, 4(%edi)
    movl %edi, (%ebx)
    

    movl $0, %eax
    jmp E

A:
    movl $-1, %eax

E:
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret
    