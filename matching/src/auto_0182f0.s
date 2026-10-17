f_0182f0:
	movea.l	#A_SAVE_DESC, a1
	move.w	#$ff, d1
	move.w	#$12c, d5
l_0182fe:
	clr.l	(a1)
	bsr.w	f_018316
	adda.l	#$a, a1
	dbra	d1, l_0182fe
	movea.l	#A_SAVE_DESC, a1
	rts	
