f_016d78:
	move.w	#$60, d4
	move.w	#$23, d0
	move.w	#$12, d1
	bsr.w	f_016dbc
	move.w	#$0, d3
	move.w	#$1, d2
	movea.l	a0, a3
	move.w	#$e, d7
	movea.l	#$3c0, a5
l_016d9c:
	move.l	d7, -(a7)
	bsr.w	f_016d1e
	bsr.w	f_016b76
	addq.w	#$1, d3
	suba.l	#$40, a5
	bsr.w	f_016b2e
	move.l	(a7)+, d7
	dbra	d7, l_016d9c
	rts	
