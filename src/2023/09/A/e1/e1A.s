.globl base64lessless

base64lessless:
    pushl %ebx
    pushl %edi
    pushl %esi
    pushl %ebp
    subl $4, %esp
    cmpl $0, 24(%esp)
    je E
    cmpl $0, 28(%esp)
    je E
    movl 24(%esp), %esi
    movl 28(%esp), %eax
    movl %eax, (%esp)
    call malloc
    xorb %dl, %dl
    xorb %dh, %dh
    xorl %edi, %edi
L:
    cmpl 28(%esp), %edi
    jge E
    movb $6, %cl
    subb %dl, %cl
    movb %dh, %bl
    shlb %cl, %bl
    movb %dl, %cl
    movb (%esi), %ch
    shrb %cl, %ch
    shrb $2, %ch
    orb %ch, %bl
    movb $8, %cl
    subb $6, %cl
    addb %dl, %cl
    andb $7, %cl
    movb %cl, %dl
    movb $8, %cl
    subb %dl, %cl
    movb (%esi), %dh
    shlb %cl, %dh
    shrb %cl, %dh
    cmpb $6, %dl
    jae L2
    incl %esi
L2:
    movl 32(%esp), %ecx
    movzbl %bl, %ebx
    movb (%ecx, %ebx), %cl
    movb %cl, (%eax, %edi)
    incl %edi
    jmp L
E:
    addl $4, %esp
    popl %ebp
    popl %esi
    popl %edi
    popl %ebx
    ret
