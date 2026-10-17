f_0152ee:
	move.b	#$0003, d0
	bsr.w	f_014f24
	tst.b	A_DAT_1AD09
	bne.w	l_015374
	move.l	#$4, d0
	bsr.w	f_014a98
	move.b	#$0000, d2
	move.b	#$0000, d3
	bsr.w	f_0167be
	bsr.w	f_0164d4
	move.w	#$19, d4
	bsr.w	f_018f8e
	move.w	A_CURSOR_X, d0
	move.w	A_CURSOR_Y, d2
	lsr.w	#$2, d0
	move.w	#$27, d1
	bsr.w	f_0159e2
	bsr.w	f_0164f6
	tst.b	A_SEL_1ACC9
	beq.w	l_015366
	movea.l	#A_DAT_1AB62, a0
	clr.l	d0
	move.b	A_SEL_1ACC9, d0
	subq.b	#$1, d0
	mulu.w	#$a, d0
	move.w	$6(a0, d0.l), A_THE_COMMAND
	bne.w	f_0103ae
l_015366:
	move.w	A_DAT_1AB5A, A_THE_COMMAND
	bra.w	f_0103ae
l_015374:
	move.w	s_01ac00, A_THE_COMMAND
	bra.w	f_0103ae
