f_013f56:
	move.w	d0, A_DAT_1A49E
	move.l	a6, -(a7)
	movea.l	#s_024982, a4
	subq.w	#$1, d1
	bsr.w	f_012950
	move.l	a4, A_DAT_1A4B2
	movea.l	a5, a6
l_013f72:
	bsr.w	f_014138
	addq.l	#$3, a6
	cmpa.l	A_DAT_1A4B2, a6
	bne.w	l_013f72
	movea.l	(a7)+, a6
	rts	
