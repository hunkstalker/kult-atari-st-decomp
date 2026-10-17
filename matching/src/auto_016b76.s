f_016b76:
	move.l	d3, -(a7)
	movea.l	a3, a2
l_016b7a:
	move.w	d2, d1
	movea.l	a2, a0
	movea.l	a0, a1
	suba.l	#$8000, a1
l_016b86:
	move.l	(a1)+, (a0)+
	move.l	(a1)+, (a0)+
	dbra	d1, l_016b86
	adda.l	#$a0, a2
	dbra	d3, l_016b7a
	move.l	(a7)+, d3
	rts	
