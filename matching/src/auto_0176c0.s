f_0176c0:
	tst.b	s_01a57b
	beq.w	l_0176d4
	move.w	#$4, d0
	bsr.w	f_01066e
	bra.b	l_0176e8
l_0176d4:
	cmpi.b	#$003d, A_DAT_1ACC7
	bne.w	l_0176e8
	move.w	#$3, d0
	bsr.w	f_01066e
l_0176e8:
	clr.b	s_01ad2d
	cmpi.b	#$0012, A_DAT_1AD09
	beq.w	l_01777a
	bsr.w	f_0162da
	movea.l	A_SEL_ICON_PTR, a2
	tst.l	(a2)
	beq.w	l_01777a
	movea.l	(a2), a1
	move.l	a1, -(a7)
	bsr.w	f_0124f8
	movea.l	(a7)+, a1
	clr.w	d2
	clr.w	d3
	move.b	(a1)+, d2
	move.b	(a1)+, d3
	movea.l	(a1)+, a0
	move.w	(a1), d7
	adda.l	#$8000, a0
	bsr.w	f_01215e
	tst.b	s_01ad03
	bne.w	l_01777a
	tst.b	s_01ad26
	bne.w	l_01777a
	tst.b	A_DAT_1ACF7
	beq.w	l_01777a
	tst.b	s_01a57b
	bne.w	l_01777a
	move.b	#$0001, s_01ad2d
	move.w	#$95, d4
	bsr.w	f_018f8e
	movea.l	A_SEL_OBJECT, a0
	clr.w	d0
	clr.w	d2
	move.b	(a0), d0
	move.b	$2(a0), d2
	move.w	#$28, d1
	bsr.w	f_0159e2
l_01777a:
	addq.l	#$1, a6
	move.b	s_01ad03, s_01a57a
	clr.b	s_01ad03
	rts	
