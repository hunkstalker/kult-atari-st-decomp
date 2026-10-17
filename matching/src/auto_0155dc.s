f_0155dc:
	movea.l	#s_019710, a6
	bsr.w	f_0134da
l_0155e6:
	move.w	#$41, A_CURSOR_TEXT_X
	move.w	#$78, A_CURSOR_TEXT_Y
	clr.l	A_SCREEN_DRAW_BASE
	clr.l	d6
	bsr.w	f_013594
	move.w	A_DAT_1AB60, d6
	divu.w	#$e10, d6
	move.b	d6, d0
	addi.b	#$0010, d0
	bsr.w	f_010838
	swap	d6
	andi.l	#$ffff, d6
	clr.b	d0
	btst.b	#$0, d6
	beq.w	l_01562c
	move.b	#$001a, d0
l_01562c:
	bsr.w	f_010838
	divu.w	#$258, d6
	move.b	d6, d0
	addi.b	#$0010, d0
	bsr.w	f_010838
	swap	d6
	andi.l	#$ffff, d6
	divu.w	#$3c, d6
	move.b	d6, d0
	addi.b	#$0010, d0
	bsr.w	f_010838
	bsr.w	f_013698
	btst.b	#$2, A_INPUT_BUTTONS
	beq.w	l_0155e6
	bsr.w	f_012368
	rts	
