f_01200a:
	tst.b	A_SKIP_TRANSITION
	bne.w	f_01222e
	clr.w	d0
	move.b	$1(a6), d0
	bsr.w	f_0120e4
	add.w	d3, d1
	subq.w	#$1, d1
	bsr.w	f_010fec
	move.w	d3, d1
	subq.w	#$1, d1
	bsr.w	f_011dee
	adda.l	#$a0, a0
	movea.l	a0, a1
	suba.l	#$8000, a1
	bsr.w	f_0123c0
	addq.l	#$2, a6
	rts	
