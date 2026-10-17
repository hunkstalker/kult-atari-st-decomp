f_016abe:
	clr.w	d0
	clr.w	d1
	move.w	#$50, d4
	move.b	A_DAT_1AB40, d0
	move.b	A_DAT_1AB42, d1
	bsr.w	f_016dbc
	clr.w	d2
	clr.l	d3
	move.b	A_DAT_1AB41, d2
	move.b	A_DAT_1AB43, d3
	sub.b	A_DAT_1AB40, d2
	sub.b	A_DAT_1AB42, d3
	lsr.w	#$2, d2
	divu.w	#$1e, d3
	movea.l	a0, a3
	subq.w	#$1, d2
	subq.w	#$1, d3
l_016afe:
	movem.l	d2-d3/a3, -(a7)
l_016b02:
	move.l	d2, -(a7)
	move.w	#$1d, d3
	move.l	#$0, d2
	bsr.w	f_016b2e
	move.l	(a7)+, d2
	adda.l	#$8, a3
	dbra	d2, l_016b02
	movem.l	(a7)+, d2-d3/a3
	adda.l	#$12c0, a3
	dbra	d3, l_016afe
	rts	
