f_0146d0:
	addq.l	#$1, a6
l_0146d2:
	move.l	a6, -(a7)
	bsr.w	f_012368
	bsr.w	f_01232e
	bsr.w	f_012384
	movea.l	(a7)+, a6
	tst.b	A_DAT_1A572
	bne.w	l_0146fa
	tst.b	A_SKIP_TRANSITION
	bne.w	l_0146fa
	bsr.w	f_015934
l_0146fa:
	bsr.w	f_0121c6
	clr.b	A_FRAME_1AB4F
	bsr.w	f_018fa4
	cmpi.b	#$0016, A_DAT_1ACD2
	bne.w	l_014724
	move.w	#$83, d4
	bsr.w	f_018f8e
	move.b	#$0001, A_FRAME_1AB4F
l_014724:
	bsr.w	f_014748
	bsr.w	f_0162da
	bsr.w	f_01857c
	bsr.w	f_018944
	move.b	A_SEL_1ACC9, d0
	beq.w	l_014742
	bsr.w	f_01424c
l_014742:
	bsr.w	f_016556
	rts	
