DRAWRECT MACRO  x,y,width,height,color
	local label3
	local label4
	pusha
	mov al,color
	mov ah,0ch
    	mov dx,y
	mov di,x
	add di,width
	mov bx,y
	add bx,height 
    label3:
        mov cx,x
        label4:
            int 10h
            inc cx
            cmp cx,di
            jnz label4
        inc dx
        cmp dx,bx
        jnz label3 
	popa
ENDM DRAWRECT   

check MACRO x,y,state,color  ;check if the given pixel has the given color
    
	local  exit
	pusha
	mov state, 0
	mov bh,0
        mov ah,0dh 
        mov dx,y
        mov cx,x
        int 10h
        cmp al,color
	jnz exit
	inc state 
	exit:
	popa     
ENDM  check 

DisplayMessage MACRO position,message
	pusha
	mov ah,2
        mov dx,position
        int 10h
	    
	mov ah,9
	mov dx,offset message
	int 21h
	popa
ENDM DisplayMessage
Receivem Macro
		pusha
		;Check that Data Ready
		mov dx , 3FDH		; Line Status Register
    	in al , dx 
  		AND al , 1
  		JZ cont 
        ;If Ready read the VALUE in Receive data register
  		mov dx , 03F8H
  		in al , dx 
  		mov VALUEr , al 
		popa
ENDM Receivem