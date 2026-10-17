f_011dee:
	move.l	#$1, d4
	bra.w	l_011dfa
	clr.l	d4
l_011dfa:
	move.l	d4, s_1a53e
	move.w	d1, -(a7)
	bsr.w	f_012698
	move.w	(a7)+, d7
	movea.w	d3, a3
l_011e0a:
	swap	d7
	movea.l	a0, a4
	move.w	a3, d7
	subq.w	#$1, d7
l_011e12:
	movea.l	a0, a1
	suba.l	#$a0, a1
	bsr.w	f_0123c0
	suba.l	#$a0, a0
	dbra	d7, l_011e12
	adda.l	#$a0, a0
	movea.l	a0, a1
	suba.l	#$8000, a1
	bsr.w	f_0123c0
	bsr.w	f_013594
	swap	d7
	movea.l	a4, a0
	suba.l	s_1a53e, a3
	tst.l	s_1a53e
	bne.w	l_011e58
	adda.l	#$a0, a0
l_011e58:
	dbra	d7, l_011e0a
	rts	
