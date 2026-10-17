f_011e5e:
	move.l	#$1, d4
	bra.w	l_011e6a
	clr.l	d4
l_011e6a:
	move.l	d4, s_1a53e
	move.w	d1, -(a7)
	bsr.w	f_012698
	move.w	(a7)+, d7
	movea.w	d3, a3
