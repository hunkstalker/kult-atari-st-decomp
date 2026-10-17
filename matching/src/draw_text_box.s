f_01042c:
	clr.w	d4
	addq.l	#1,a6
	move.b	(a6),d4
	movea.l	#DESC_BASE,a5
	bsr.w	f_010fb4
	addq.l	#1,a6
	bra.b	l_010450
