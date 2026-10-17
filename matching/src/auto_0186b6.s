f_0186b6:
	clr.l	d0
	move.b	$1(a6), d0
	subq.l	#$1, d0
	mulu.w	#$6, d0
	move.b	$3(a6), d1
	clr.w	d2
	move.b	$2(a6), d2
	movea.l	#A_LIST_1A8F0, a0
	adda.l	d0, a0
	subq.w	#$1, d2
l_0186d6:
	cmp.b	(a0), d1
	beq.w	l_0186e4
	addq.l	#$6, a0
	dbra	d2, l_0186d6
	subq.l	#$6, a0
l_0186e4:
	move.l	a0, A_DAT_1A75E
	addq.l	#$4, a6
	rts	
