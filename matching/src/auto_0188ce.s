f_0188ce:
	clr.b	A_DAT_1AD1D
	move.b	A_DAT_1AAF9, d0
	cmp.b	A_DAT_1ACD2, d0
	bne.w	l_018942
	move.b	$1(a6), d0
	cmpi.b	#$003b, d0
	bcs.w	l_018942
	cmpi.b	#$003f, d0
	bcc.w	l_018942
	move.b	A_SEL_1ACC9, d1
	movem.l	d1/a6, -(a7)
	move.b	#$ffff, A_DAT_1AD1D
	move.w	#$87, d0
	bsr.w	f_0177bc
	movea.l	#s_019d24, a1
	bsr.w	f_017856
	tst.b	A_DAT_1AB08
	beq.w	l_018938
	move.w	#$96, d0
	bsr.w	f_0177bc
	movea.l	#s_019d2a, a1
	bsr.w	f_017856
l_018938:
	movem.l	(a7)+, d1/a6
	move.b	d1, A_SEL_1ACC9
l_018942:
	rts	
