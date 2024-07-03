   	PRESERVE8
	THUMB
	AREA |.text|, CODE, READONLY
	EXPORT __main
	
__main
	movs r2,#1
	movs r1,#5
loop   
	muls r2,r1,r2
	subs r1,r1,#1
	cmp r1,#0
	bgt loop
result b result
       END
	
	
