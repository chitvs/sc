.globl most_freq_char
most_freq_char:
    pushl %esi
    pushl %edi
    pushl %ebx
    pushl %ebp
    subl $8, %esp
    xorl %esi, %esi         
    xorl %edi, %edi         
    movl 32(%esp), %ebx
    movl %ebx, (%esp)
    movl $256, 4(%esp)
    call clear
    movl 28(%esp), %edx
L:
    cmpb $0, (%edx)
    je L2
    movb (%edx), %cl     
    movzbl %cl, %ecx   
    incl %edx               
    incl (%ebx, %ecx, 4)    
    jmp L
L2:
    cmpl $256, %esi
    jge RET
    movl (%ebx, %edi, 4), %ebp
    cmpl %ebp, (%ebx, %esi, 4)
    jle NEXT
    movl %esi, %edi
NEXT:
    incl %esi
    jmp L2
RET:
    movl %edi, %eax
    addl $8, %esp
    popl %ebp
    popl %ebx
    popl %edi
    popl %esi
    ret
