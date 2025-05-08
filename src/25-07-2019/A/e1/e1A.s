.globl most_freq_char

most_freq_char:
    pushl %esi
    pushl %edi
    subl $8, %esp
    movl 20(%esp), %esi
    movl 24(%esp), %edi
    movl %edi, (%esp)
    movl $256, 4(%esp)
    call clear
    xorl %eax, %eax
L1:
    movb (%esi), %dl
    movsbl %dl, %edx
    testl %edx, %edx
    je E1
    incl (%edi,%edx,4)
    incl %esi
    jmp L1
E1:
    xorl %ecx, %ecx
L2:
    cmpl $256, %ecx
    jge E2
    movl (%edi,%ecx,4), %edx
    cmpl (%edi,%eax,4), %edx
    cmovgl %ecx, %eax
    incl %ecx
    jmp L2
E2:
    addl $8, %esp
    popl %edi
    popl %esi
    ret
