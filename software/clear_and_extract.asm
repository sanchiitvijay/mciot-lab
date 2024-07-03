   	PRESERVE8
	THUMB
	AREA |.text|, CODE, READONLY
	EXPORT __main
	
__main
	;extraction
    ldr r0,=0x35968039
	lsls r0,r0,#(32-16-8)
	lsrs r0,r0,#(32-8)
	
	;clearing
	ldr r0,=0x04844634
	movs r1,#16
	movs r2,#8
	movs r3,#8
	
	rors r0,r0,r1
	lsrs r0,r0,r2
	rors r0,r0,r3
stop b stop
	END
	
	
