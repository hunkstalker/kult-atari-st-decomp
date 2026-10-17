f_011ece:
	move.w	#$1, d3
l_011ed2:
	move.w	d1, -(a7)
	bsr.w	f_012466
	addq.w	#$1, d3
	suba.l	#$40, a1
	move.w	(a7)+, d1
	dbra	d1, l_011ed2
	rts	
