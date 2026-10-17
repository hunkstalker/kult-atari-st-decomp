f_011ada:
	move.w	#1,d4
	bra.w	l_011ae4
f_011ae2:
	clr.w	d4
l_011ae4:
	move.w	d4,s_1a53e
	lsl.w	#2,d1
	subq.w	#1,d1
	lsl.w	#2,d2
	movea.l	a0,a1
	suba.l	#$8000,a1
	subq.w	#1,d3
