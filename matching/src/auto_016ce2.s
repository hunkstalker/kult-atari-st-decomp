f_016ce2:
	move.w	#$76, d4
	move.w	#$1c, d0
	move.w	#$ae, d1
	bsr.w	f_016dbc
	move.w	#$0, d3
	move.w	#$4, d2
	movea.l	a0, a3
	move.w	#$43, d7
l_016d00:
	move.l	d7, -(a7)
	bsr.w	f_016d1e
	bsr.w	f_016b76
	suba.l	#$a0, a3
	addq.w	#$1, d3
	bsr.w	f_016b2e
	move.l	(a7)+, d7
	dbra	d7, l_016d00
	rts	
