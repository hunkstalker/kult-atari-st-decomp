f_014e66:
	clr.w	A_THE_COMMAND
	move.w	#$46, d0
	move.w	#$28, d1
	bsr.w	f_010fec
	move.w	#$4, d2
	move.w	#$80, d3
	bsr.w	f_01258a
	move.w	#$3, d4
	move.w	#$46, d0
	move.w	#$28, d1
	bsr.w	f_011020
	bsr.w	f_010522
l_014e98:
	bsr.w	f_013698
	clr.l	d0
	bsr.w	f_014a98
	bsr.w	f_0147c2
	move.b	A_TEXT_SEL_B, d0
	cmpi.b	#$0064, d0
	beq.w	l_014ebe
	addi.b	#$006d, d0
	move.b	d0, A_TEXT_SEL_B
l_014ebe:
	cmp.b	A_1AB47, d0
	beq.w	l_014ecc
	bsr.w	f_010a88
l_014ecc:
	bsr.w	f_01031c
	btst.b	#$2, A_INPUT_BUTTONS
	beq.w	l_014e98
	bsr.w	f_01060a
	bsr.w	f_0124f2
	bra.w	f_0103ae
