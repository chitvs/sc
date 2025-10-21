.globl my_strcmp

my_strcmp:
    movl 4(%esp), %ecx
    movl 8(%esp), %edx

L: 
    movb (%ecx), %al
    cmpb $0, %al
    je W
    cmpb (%edx), %al
    jne W
    incl %ecx   
    incl %edx
    jmp L
W:
    subb (%edx), %al
    ret
