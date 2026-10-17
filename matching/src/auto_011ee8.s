f_011ee8:
	move.w	#$1, d3
l_011eec:
	move.w	d1, -(a7)
	bsr.w	f_012466
	suba.l	#$a0, a0
	addq.w	#$1, d3
	move.w	(a7)+, d1
	dbra	d1, l_011eec
	rts	
