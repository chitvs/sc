.globl f
f: 
    movl 4(%esp), %eax
    movl 8(%esp), %ecx
    addl %ecx, %eax
    movl 4(%esp), %edx
    subl %ecx, %edx
    imull %edx, %eax
    ret
