f_0162e2:
	mulu.w	#$a, d0
	movea.l	#A_PAL_TABLE, a0
	adda.l	d0, a0
	movea.l	A_PALETTE_PTR, a1
	addq.l	#$2, a1
	move.w	#$4, d0
l_0162fa:
	move.w	(a0)+, (a1)+
	dbra	d0, l_0162fa
