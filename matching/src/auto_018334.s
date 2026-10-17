f_018334:
	move.w	#$64, d5
l_018338:
	bsr.w	f_01834a
	dbra	d5, l_018338
	rts	
	movea.l	#$8000, a5
	bra.b	l_018350
