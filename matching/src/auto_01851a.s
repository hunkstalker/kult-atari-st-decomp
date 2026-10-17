f_01851a:
	clr.l	d0
	move.b	$1(a6), d0
	subq.l	#$1, d0
	mulu.w	#$6, d0
	movea.l	#A_LIST_1A8F0, a0
	adda.l	d0, a0
	move.l	a0, A_DAT_1A75E
	addq.l	#$1, a6
	bra.b	f_0184cc
