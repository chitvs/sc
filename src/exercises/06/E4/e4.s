.globl lcm

lcm:
   pushl %esi
   pushl %edi 
   pushl %ebx

   movl 16(%esp), %esi
   movl 20(%esp), %edi
   movl %edi, %ecx

   cmpl %edi, %esi
   cmovg %esi, %ecx

L:
    movl %ecx, %eax
    movl %eax, %edx
    sarl $31, %edx
    idivl %esi
    testl %edx, %edx
    setzb %bl
    movl %ecx, %eax
    movl %eax, %edx
    sarl $31, %edx
    idiv %edi
    testl %edx, %edx
    setzb %bh
    andb %bh, %bl
    jz F
    movl %ecx, %eax
    popl %ebx
    popl %edi
    popl %esi
    ret
F:
    incl %ecx
    jmp L
    