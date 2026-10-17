f_01816e:
	move.l	a6, -(a7)
	bsr.w	f_018192
	movea.l	(a7)+, a6
	addq.l	#$1, a6
	rts	
