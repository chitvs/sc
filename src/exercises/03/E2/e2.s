.globl fib

fib:
    movl $0, %eax
    movl $1, %ecx
    movl 4(%esp), %edx

    cmpl $0, %edx
    jnz E
    ret

    E: 
        cmpl $1, %edx
        jnz L
        movl %ecx, %eax
        ret
    L: 
        cmpl $1, %edx
        jle W
        addl %ecx, %eax
        addl %ecx, %eax
        movl %eax, %edi
        subl %ecx, %edi
        movl %edi, %ecx
        subl %ecx, %eax
        decl %edx
        jmp L
    W:
        movl %ecx, %eax
        ret
