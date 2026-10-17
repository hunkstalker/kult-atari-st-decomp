f_0134da:
	bsr.w	f_0128a4
	bsr.w	f_0124da
	rts	
	lsr.w	#$2, d2
	subq.w	#$1, d3
	subq.w	#$1, d2
	bsr.w	f_010fec
	suba.l	#$8000, a0
l_0134f4:
	move.w	d2, d1
	movea.l	a0, a2
l_0134f8:
	move.l	(a1)+, (a2)+
	move.l	(a1)+, (a2)+
	dbra	d1, l_0134f8
	adda.l	#$a0, a0
	dbra	d3, l_0134f4
	rts	
