;swapping of one memory to another memory (copying)      


		PRESERVE8 ; Indicate the code here preserve  
; 8 byte stack alignment         
                     THUMB     ; Indicate THUMB code is used       
                 AREA    |.text|, CODE, READONLY
			   
              EXPORT __main			 
; Start of CODE area 

 
__main 	
	LDR r0,=0x20000000 ; Source address
	LDR r1,=0x20000040 ; Destination address
	LDR r2,=10; number of bytes to copy
copy_loop
	LDRB r3, [r0] ; read 1 byte
	LDRB r4, [r1]
	STRB r3, [r1]
	STRB r4, [r0]
	ADDS r0, r0, #1 ; increment source pointer
	ADDS r1, r1, #1 ; increment destination pointer
	SUBS r2, r2, #1 ; decrement loop counter
	BNE copy_loop ; loop until all data copied
stop B stop
	          END
