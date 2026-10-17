f_012950:
	clr.l	d2
	tst.w	d1
	beq.w	l_012962
	subq.w	#$1, d1
l_01295a:
	move.b	(a4), d2
	adda.l	d2, a4
	dbra	d1, l_01295a
l_012962:
	movea.l	a4, a5
	move.b	(a4), d2
	adda.l	d2, a4
	addq.l	#$1, a5
	rts	
