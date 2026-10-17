f_011e7a:
	swap	d7
	movea.l	a0, a4
	move.w	a3, d7
	subq.w	#$1, d7
l_011e82:
	movea.l	a0, a1
	suba.l	#$a0, a0
	bsr.w	f_0123c0
	adda.l	#$140, a0
	dbra	d7, l_011e82
	suba.l	#$a0, a0
	movea.l	a0, a1
	suba.l	#$8000, a1
	bsr.w	f_0123c0
	bsr.w	f_013594
	swap	d7
	movea.l	a4, a0
	suba.l	s_1a53e, a3
	tst.l	s_1a53e
	bne.w	l_011ec8
	suba.l	#$a0, a0
f_011ec4:
l_011ec8:
	dbra	d7, f_011e7a
	rts	
