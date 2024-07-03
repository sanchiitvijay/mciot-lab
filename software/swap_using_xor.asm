	PRESERVE8	
	THUMB
	area |.text|,CODE,READONLY
	EXPORT __main

__main
	LDR r0,=0xF631024C
	LDR r1,=0x17539ABD
	EORS r0,r0,r1
	EORS r1,r0,r1
	EORS r0,r0,r1
stop B stop
	END
