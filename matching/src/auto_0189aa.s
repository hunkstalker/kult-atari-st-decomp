f_0189aa:
	bsr.w	f_012368
	bsr.w	f_01232e
	movea.l	#s_019704, a6
	move.b	#$0028, d1
	move.b	A_DAT_1AD20, d0
	beq.w	l_0189cc
	lsr.b	#$4, d0
	add.b	d0, d1
	addq.b	#$1, d1
l_0189cc:
	move.b	d1, $6(a6)
	addi.b	#$000e, d1
	move.b	d1, $a(a6)
	bsr.w	f_0134da
l_0189dc:
	move.w	#$1c, d4
	bsr.w	f_018f8e
	movea.l	#s_019708, a6
	bsr.w	f_016dec
	move.w	#$1c, d4
	bsr.w	f_018f98
	bsr.w	f_016dec
	bsr.w	f_013698
	btst.b	#$2, A_INPUT_BUTTONS
	beq.w	l_0189dc
	bsr.w	f_012368
	rts	
