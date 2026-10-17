f_013702:
	bsr.w	f_0128a4
	move.w	d3, d4
	subq.w	#$1, d4
	move.w	d4, s_01a544
	lsl.w	#$1, d2
	move.w	d2, d4
	lsl.w	#$1, d4
	subq.w	#$1, d4
	move.w	d4, s_01a542
	move.w	d7, s_01a486
	clr.l	d2
	clr.l	d3
	move.b	(a6)+, d3
	move.b	(a6)+, d2
	move.w	d2, (a2)
	move.w	d3, -$2(a2)
	lsl.w	#$2, d3
	subq.w	#$2, d2
	subq.w	#$2, d3
	movea.l	a0, a2
	bsr.w	f_013a18
	rts	
