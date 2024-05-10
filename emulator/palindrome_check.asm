data segment
   msg1 db 10,13,'NOT PALINDROME$'
   msg2 db 10,13,'PALINDROME$'
   msg3 db 10,13,'ENTER A STRING: $' 
   str db dup(0) 
   
data ends

code segment  
    
    assume code:cs,data:ds   
    start:
        mov ax,data
        mov ds,ax  
        lea dx,msg3
        mov ah,09h
        int 21h   
        lea si,str
        lea di,str
        mov ah,01h

    step1:
        int 21h
        cmp al,0dh
        je step2
        mov [di],al
        inc di
        jmp step1
    
    step2:
        mov al,'$' 
        mov [di],al
        dec di
    
    step3:       
        mov al,[si]
        cmp al,[di]
        jnz notpal
        inc si
        dec di
        cmp si,di
        jnz step3

    pal:
        lea dx,msg2
        mov ah,09h
        int 21h
        jmp exit    
        
    notpal:       
        lea dx,msg1
        mov ah,09h
        int 21h
    
    exit:
        mov ah,04ch
        int 21h

code ends
end start
        
    
        
        
        
        
    