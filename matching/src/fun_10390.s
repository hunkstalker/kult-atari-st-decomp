f_010390:
	clr.l	d1
	move.b	2(a6),d1
	lsl.w	#8,d1
	move.b	1(a6),d1
	ori.w	#$f000,d1
	move.w	d1,A_THE_COMMAND
	bra.b	f_0103ae
