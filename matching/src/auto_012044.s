f_012044:
	tst.b	A_SKIP_TRANSITION
	bne.w	f_01222e
	clr.w	d0
	move.b	$1(a6), d0
	move.l	a6, -(a7)
	bsr.w	f_0120e4
	move.w	d7, d0
	movem.l	d0-d3/a0, -(a7)
	move.w	d2, d1
	bsr.w	f_0117de
	movem.l	(a7)+, d0-d3/a0
	move.w	d0, d7
	bsr.w	f_01215e
	movea.l	(a7)+, a6
	addq.l	#$2, a6
	rts	
