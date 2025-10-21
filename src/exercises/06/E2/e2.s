.globl list_equal

list_equal:
    movl 4(%esp), %eax
    movl 8(%esp), %ecx
L:
    testl %eax, %eax
    jz E
    testl %ecx, %ecx
    jz E
    movw (%ecx), %dx
    cmpw %dx, (%eax)
    je F
    movl $0, %eax
    ret
F:
    movl 4(%eax), %eax
    movl 4(%ecx), %ecx
    jmp L
E:
    testl %eax, %eax
    setz %al
    testl %ecx, %ecx
    setz %ah
    andb %ah, %al
    movsbl %al, %eax
    ret
