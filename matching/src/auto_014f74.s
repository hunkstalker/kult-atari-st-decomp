f_014f74:
	move.b	#$0003, d0
	bsr.w	f_014f24
	tst.b	A_DAT_1AD09
	bne.w	l_015014
	bsr.w	f_0164d4
	bsr.w	f_016abe
	movea.l	A_PALETTE_PTR, a0
	tst.w	$2(a0)
	beq.w	l_014fa4
	move.w	#$f, d0
	bsr.w	f_0162e2
l_014fa4:
	move.l	#$2, d0
	bsr.w	f_014a98
	move.b	#$0000, d2
	move.b	#$0000, d3
	bsr.w	f_0167be
	move.w	#$e0, d4
	bsr.w	f_018f8e
	bsr.w	f_0121c6
	movea.l	A_PALETTE_PTR, a0
	tst.w	$2(a0)
	beq.w	l_014fd8
	bsr.w	f_0162da
l_014fd8:
	bsr.w	f_0164f6
	tst.b	A_SEL_1ACC9
	beq.w	l_015006
	movea.l	#A_DAT_1AB62, a0
	clr.l	d0
	move.b	A_SEL_1ACC9, d0
	subq.b	#$1, d0
	mulu.w	#$a, d0
	move.w	(a0, d0.l), A_THE_COMMAND
	bne.w	l_015022
l_015006:
	move.w	A_DAT_1AB50, A_THE_COMMAND
	bra.w	l_015022
l_015014:
	move.w	s_01abfc, A_THE_COMMAND
	bra.w	f_0103ae
l_015022:
	cmpi.b	#$003f, A_DAT_1ACEC
	bcs.w	f_0103ae
	cmpi.b	#$0016, A_DAT_1ACD2
	bcc.w	f_0103ae
	cmpi.b	#$0001, A_DAT_1ACD2
	beq.w	f_0103ae
	move.w	#$9005, A_THE_COMMAND
	bra.w	f_0103ae
