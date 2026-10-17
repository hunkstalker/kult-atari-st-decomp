f_01424c:
	move.l	a6, -(a7)
	bsr.w	f_0142cc
	move.w	#$1d, d4
	bsr.w	f_018f8e
	move.w	s_00d902, d6
	clr.l	d0
	move.w	s_00d900, d0
	lsl.l	#$1, d0
	movea.l	s_00d904, a0
	movem.l	d6/a0, -(a7)
	move.l	d0, d5
	mulu.w	d6, d0
	adda.l	d0, a0
	suba.l	d5, a0
	move.l	a0, s_00d904
	lsr.w	#$1, d6
	subq.w	#$1, d6
	lsl.w	#$1, d5
	move.w	#$1, s_00d902
l_014290:
	movem.l	d5-d6, -(a7)
	bsr.w	f_0143e2
	addq.w	#$2, s_00d902
	movem.l	(a7)+, d5-d6
	sub.l	d5, s_00d904
	dbra	d6, l_014290
	movem.l	(a7)+, d6/a0
	move.l	a0, s_00d904
	move.w	d6, s_00d902
	bsr.w	f_0143e2
	move.w	#$1e, d4
	bsr.w	f_018f8e
	movea.l	(a7)+, a6
	rts	
