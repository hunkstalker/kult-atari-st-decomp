f_014db2:
	movem.l	d2-d3, -(a7)
	clr.w	A_THE_COMMAND
	move.w	#$3a, d0
	move.w	#$38, d1
	bsr.w	f_010fec
	move.w	#$10, d2
	move.w	#$40, d3
	bsr.w	f_01258a
	movem.l	(a7)+, d2-d3
	bsr.w	f_015492
	tst.w	s_01a510
	beq.w	l_014e26
	bsr.w	f_010522
l_014dea:
	bsr.w	f_013698
	move.w	s_01a510, d3
	clr.l	d0
	bsr.w	f_014a98
	bsr.w	f_014966
	move.b	A_TEXT_SEL_B, d0
	cmp.b	A_1AB47, d0
	beq.w	l_014e12
	bsr.w	f_010a88
l_014e12:
	bsr.w	f_01031c
	btst.b	#$2, A_INPUT_BUTTONS
	beq.w	l_014dea
	bsr.w	f_01060a
l_014e26:
	bsr.w	f_0124f2
	move.w	#$14, d4
	bsr.w	f_018f98
	move.b	#$0001, s_01ad29
	movea.l	A_DAT_1A75E, a0
	cmpi.b	#$006c, $3(a0)
	beq.w	l_014e64
	cmpi.b	#$0073, $3(a0)
	beq.w	l_014e64
	cmpi.b	#$0075, $3(a0)
	beq.w	l_014e64
	clr.b	s_01ad29
l_014e64:
	rts	
