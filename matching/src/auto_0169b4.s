f_0169b4:
	movea.l	#s_01ac0a, a1
l_0169ba:
	move.l	a1, -(a7)
	bsr.w	f_01680c
	movea.l	(a7)+, a1
	move.w	#$9183, A_THE_COMMAND
	tst.b	A_SEL_1ACC9
	beq.w	f_0103ae
	tst.b	A_CLASS_IDX
	beq.w	f_0103ae
	clr.l	d0
	move.b	$2(a0), d0
	cmpi.b	#$005d, d0
	bne.w	l_0169f0
	subi.b	#$0020, d0
l_0169f0:
	cmpi.b	#$0085, d0
	bne.w	l_0169fc
	subi.b	#$0049, d0
l_0169fc:
	subi.b	#$002a, d0
	lsl.w	#$1, d0
	move.w	(a1, d0.l), A_THE_COMMAND
	cmpa.l	#s_01ac32, a1
	bne.w	f_0103ae
	move.w	#$16, d4
	bsr.w	f_018f8e
	bra.w	f_0103ae
