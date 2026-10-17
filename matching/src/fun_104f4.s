f_0104f4:
	clr.l	d1
	move.b	2(a6),d1
	lsl.w	#8,d1
	move.b	1(a6),d1
	move.w	d1,A_THE_COMMAND
	move.w	A_THE_COMMAND,d1
	subq.l	#1,d1
	movea.l	#A_TEMPL_DATA,a4
	bsr.w	f_012950
	movea.l	a5,a6
	move.l	a4,A_SCRIPT_END
	rts
