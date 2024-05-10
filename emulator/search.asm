data segment
    array DW 1234h,5678h,3924h,2413h,2432h
    
    array_size equ 5              
    
    msg1 db 10,13,"found$"
    msg2 db 10,13,"not found$" 

data ends
    
code segment
    assume cs:code, ds:data 
    start:
        mov ax,data
        mov ds,ax
        mov cx,array_size 
        lea si,array
        mov ax,2432h
    
    next:
        cmp ax,[si]
        jz found
        inc si
        inc si
        dec cx
        jnz next  
        
    notfound:  
        lea dx,msg2 
        mov ah,09h
        int 21h
        jmp exit 
         
    found:   
        lea dx,msg1
        mov ah,09h
        int 21h
        
    
    exit:
        mov ah,04ch
        int 21h
        
code ends

end start
        
        