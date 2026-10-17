f_016576:
	move.l	a6, -(a7)
	bsr.w	f_016582
	movea.l	(a7)+, a6
	addq.l	#$1, a6
	rts	
