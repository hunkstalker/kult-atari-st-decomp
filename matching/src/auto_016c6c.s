f_016c6c:
	movea.l	a0, a3
	move.w	#$3, d7
	tst.b	(a6)
	beq.w	l_016c7c
	subq.w	#$4, d3
	subq.w	#$1, d7
l_016c7c:
	move.l	d7, -(a7)
	bsr.w	f_016d1e
	bsr.w	f_016b76
	adda.l	#$a0, a3
	subq.w	#$1, d3
	bsr.w	f_016b2e
	move.l	(a7)+, d7
	dbra	d7, l_016c7c
	tst.b	(a6)
	beq.w	l_016ca2
	bsr.w	f_016b76
l_016ca2:
	addq.l	#$1, a6
	rts	
