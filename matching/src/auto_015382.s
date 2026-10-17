f_015382:
	move.b	#$0008, d0
	bsr.w	f_014f24
	move.b	#$0001, s_01ad03
	movea.l	A_PALETTE_PTR, a0
	tst.w	$2(a0)
	beq.w	l_0153a8
	move.w	#$11, d0
	bsr.w	f_0162e2
l_0153a8:
	tst.b	A_DAT_1AD09
	bne.w	l_01541a
	bsr.w	f_01680c
	tst.b	A_SEL_1ACC9
	beq.w	l_0153f4
	movea.l	#A_DAT_1AB62, a0
	clr.l	d0
	move.b	A_SEL_1ACC9, d0
	subq.b	#$1, d0
	mulu.w	#$a, d0
	move.w	$8(a0, d0.l), d1
	move.w	d1, A_THE_COMMAND
	andi.w	#$f000, d1
	cmpi.w	#$9000, d1
	beq.w	l_0153fe
	tst.w	A_THE_COMMAND
	bne.w	f_0103ae
l_0153f4:
	move.w	A_DAT_1AB58, A_THE_COMMAND
l_0153fe:
	movea.l	A_PALETTE_PTR, a0
	tst.w	$2(a0)
	beq.w	l_015410
	bsr.w	f_0162da
l_015410:
	clr.b	s_01ad03
	bra.w	f_0103ae
l_01541a:
	move.w	s_01ac02, A_THE_COMMAND
	bra.w	f_0103ae
