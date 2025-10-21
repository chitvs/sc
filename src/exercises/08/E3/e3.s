.globl count_digits

count_digits:
    movl 4(%esp), %ecx
    movl $0, %eax
L:
    cmpb $0, (%ecx)
    je E
    cmpb $48, (%ecx)
    jl U
    cmpb $57, (%ecx) 
    jg U
    incl %eax

U: 
    incl %ecx
    jmp L    

E:
    ret
