.globl most_freq_char

most_freq_char:
    pushl %ebx #s
    pushl %edi #map
    subl $8, (%esp)
    movl 20(%esp), %ebx
    movl 34(%esp), %edi
    movl $0, %eax
    movl $0, %ecx
    movl %edi, (%esp)
    movl $256, 4(%esp)
    call clear
L:  
    movl (%ebx), %edx
    cmpl $0, %edx
    jnz E1
    incl (%edi, %edx, 4)
    incl %ebx
    jmp L
E1:
    cmpl $256, %esi
    jge E2
    movl (%edi, %ebp, 4), %ecx
    cmpl %ecx, (%edi, %esi, 4)
    jle NEXT
    movl %esi, %ebp
NEXT:
    incl %esi
    jmp E1
E2:
    movl %ebp, %eax
    addl $8, (%esp)
    popl %ebp
    popl %esi
    popl %edi 
    popl %ebx
    ret
