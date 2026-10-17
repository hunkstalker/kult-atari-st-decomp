f_0117de:
	move.w	#1,d4
	bra.w	l_0117e8
f_0117e6:
	clr.w	d4
l_0117e8:
	move.w	d4,s_1a53e
	lsl.w	#2,d1
	subq.w	#1,d1
	lsl.w	#2,d2
	movea.l	a0,a1
	suba.l	#$8000,a1
	subq.w	#1,d3
