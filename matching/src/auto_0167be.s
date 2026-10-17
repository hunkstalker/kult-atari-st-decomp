f_0167be:
	move.b	d2, A_DAT_1A74E
	move.b	d3, A_DAT_1A74F
	bsr.w	f_010522
l_0167ce:
	bsr.w	f_013698
	move.b	A_DAT_1A74E, d2
	move.b	A_DAT_1A74F, d3
	bsr.w	f_014886
	move.b	A_TEXT_SEL_A, d0
	cmp.b	A_1AB44, d0
	beq.w	l_0167f6
	bsr.w	f_0109fe
l_0167f6:
	bsr.w	f_01031c
	btst.b	#$2, A_INPUT_BUTTONS
	beq.w	l_0167ce
	bsr.w	f_01060a
	rts	
