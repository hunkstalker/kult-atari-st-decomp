f_016b9c:
	move.w	#$3, d4
	move.w	#$23, d0
	move.w	#$ad, d1
	bsr.w	f_016dbc
	subq.l	#$1, a6
	move.w	#$7, d3
	move.w	#$2, d2
	movea.l	a0, a3
	bsr.w	f_016b2e
	move.w	#$77, d4
	move.w	#$20, d0
	move.w	#$5e, d1
	bsr.w	f_016dbc
	move.w	#$47, d3
	move.w	#$3, d2
	movea.l	a0, a3
	bsr.w	f_016b2e
	bsr.w	f_012292
l_016bde:
	bsr.w	f_016d1e
	addq.w	#$1, d3
	bsr.w	f_016b76
	subq.w	#$1, d3
	adda.l	#$a0, a3
	bsr.w	f_016b2e
	dbra	d3, l_016bde
	addq.w	#$1, d3
	bsr.w	f_016b76
	rts	
