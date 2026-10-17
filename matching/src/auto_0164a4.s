f_0164a4:
	clr.w	d0
	clr.w	d1
	clr.w	d2
	clr.w	d3
	move.l	a1, (a2)
	move.b	(a5), d0
	move.b	$2(a5), d1
	move.b	$1(a5), d2
	move.b	$3(a5), d3
	sub.b	d0, d2
	sub.b	d1, d3
	bsr.w	f_010fec
	suba.l	#$8000, a0
	move.l	a2, -(a7)
	bsr.w	f_012590
	movea.l	(a7)+, a2
	rts	
