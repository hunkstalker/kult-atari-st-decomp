f_018944:
	tst.b	A_DAT_1AD1D
	beq.w	l_018942
	move.b	A_SEL_1ACC9, d1
	movem.l	d1/a6, -(a7)
	move.w	#$87, d0
	bsr.w	f_0177bc
	movea.l	#s_019d21, a1
	bsr.w	f_017856
	move.b	A_DAT_1ACD2, A_DAT_1AAF9
	tst.b	A_DAT_1AB08
	beq.w	l_01899a
	move.b	A_DAT_1ACD2, A_DAT_1AB08
	move.w	#$96, d0
	bsr.w	f_0177bc
	movea.l	#s_019d27, a1
	bsr.w	f_017856
l_01899a:
	movem.l	(a7)+, d1/a6
	move.b	d1, A_SEL_1ACC9
	bsr.w	f_016582
	rts	
