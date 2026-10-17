f_0168a0:
	move.w	#$18, d4
	move.b	#$00e6, d1
	bsr.w	f_018f7a
	addq.l	#$1, a6
	clr.w	d4
	move.b	(a6), d4
	movea.l	#s_03c534, a5
	bsr.w	f_010fb4
	move.l	a6, -(a7)
	bsr.w	f_01695a
	bsr.w	f_010b6c
	bsr.w	f_01228a
	bsr.w	f_01232e
	movea.l	(a7)+, a6
	addq.l	#$1, a6
	rts	
