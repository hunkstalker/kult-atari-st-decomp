f_015944:
	movea.l	A_SCREEN_PTR_B, a3
	clr.b	s_01a573
l_015950:
	adda.l	#$150, a3
	movea.l	#s_019900, a4
	movea.l	a3, a2
	move.l	#$1e0, d7
	move.w	#$34, d6
l_015968:
	clr.l	d4
	movea.l	#s_02705e, a1
	move.w	d7, d4
	adda.l	d4, a1
	swap	d7
	move.w	#$1d, d3
	bsr.w	f_0159bc
	tst.b	s_01a573
	beq.w	l_01598c
	bsr.w	f_013594
l_01598c:
	move.l	a2, d0
	add.w	(a4)+, d0
	movea.l	d0, a2
	dbra	d6, l_015968
	movea.l	a3, a2
	adda.l	#$7070, a2
	move.w	#$8, d6
l_0159a2:
	move.w	#$8, d3
	movea.l	#s_02705e, a1
	bsr.w	f_0159bc
	adda.l	#$10, a2
	dbra	d6, l_0159a2
	rts	
