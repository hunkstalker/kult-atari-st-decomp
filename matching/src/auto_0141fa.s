f_0141fa:
	move.l	a6, -(a7)
	bsr.w	f_0142cc
	move.w	#$1d, d4
	bsr.w	f_018f8e
	move.w	s_00d902, d6
	lsr.w	#$1, d6
	subq.w	#$1, d6
l_014212:
	move.l	d6, -(a7)
	bsr.w	f_0143e2
	subq.w	#$2, s_00d902
	clr.l	d0
	move.w	s_00d900, d0
	lsl.l	#$1, d0
	add.l	d0, d0
	add.l	d0, s_00d904
	move.l	(a7)+, d6
	dbra	d6, l_014212
	move.w	#$1f, d4
	move.w	#$31, d1
	bsr.w	f_018f7a
	movea.l	(a7)+, a6
	rts	
