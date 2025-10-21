.globl min

min:
    movl 4(%esp), %eax
    movl 8(%esp), %ecx
    movl 12(%esp), %edx

    cmpl %ecx, %eax
    jge E

    cmpl %edx, %eax
    jge D

    ret

    E: 
        cmpl %edx, %ecx
        jge D
        movl %ecx, %eax
        ret
    D:
        movl %edx, %eax
        ret
