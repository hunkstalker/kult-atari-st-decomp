f_011fd8:
	tst.b	A_SKIP_TRANSITION
	bne.w	f_01222e
	clr.w	d0
	move.b	$1(a6), d0
	bsr.w	f_0120e4
	move.w	d3, d1
	subq.w	#$1, d1
	bsr.w	f_011e5e
	suba.l	#$a0, a0
	movea.l	a0, a1
	suba.l	#$8000, a1
	bsr.w	f_0123c0
	addq.l	#$2, a6
	rts	
