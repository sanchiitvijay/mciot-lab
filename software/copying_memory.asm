   	PRESERVE8
	THUMB
	AREA |.text|, CODE, READONLY
	EXPORT __main
	
__main 	
	LDR r0,=0x20000000
	LDR r1,=0x20000040
	LDR r2,=10

copy_loop
	LDRB r3, [r0]
	LDRB r4, [r1]
	STRB r3, [r1]
	STRB r4, [r0]

	ADDS r0, r0, #1
	ADDS r1, r1, #1
	SUBS r2, r2, #1
	BNE copy_loop
stop B stop
	END
