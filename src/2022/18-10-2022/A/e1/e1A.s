.globl str_to_upper 
str_to_upper:
    pushl %ebx
    pushl %esi
    subl $4, %esp
    xorl %esi, %esi         
    movl 16(%esp), %ebx
    testl %ebx, %ebx       
    je E                    
    movl %ebx, (%esp)
    call strdup             
    movl %eax, %esi
    movl %eax, %ebx         
L:
    cmpb $0, (%ebx)         
    je E                    
    movsbl (%ebx), %eax
    movl %eax, (%esp)    
    call toupper            
    movb %al, (%ebx)        
    incl %ebx               
    jmp L                  
E:
    movl %esi, %eax
    addl $4, %esp
    popl %esi
    popl %ebx
    ret                     
