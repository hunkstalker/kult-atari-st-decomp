f_016ca6:
	move.w	#$76, d4
	move.w	#$1c, d0
	move.w	#$6a, d1
	bsr.w	f_016dbc
	move.w	#$43, d3
	move.w	#$4, d2
	movea.l	a0, a3
	move.w	#$21, d7
l_016cc4:
	move.l	d7, -(a7)
	bsr.w	f_016d1e
	bsr.w	f_016b76
	adda.l	#$a0, a3
	subq.w	#$1, d3
	bsr.w	f_016b2e
	move.l	(a7)+, d7
	dbra	d7, l_016cc4
	rts	
