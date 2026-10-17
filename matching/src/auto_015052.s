f_015052:
	move.b	#$0001, d0
	bsr.w	f_014f24
	tst.b	A_DAT_1AD09
	bne.w	l_0150a0
	bsr.w	f_01680c
	tst.b	A_SEL_1ACC9
	beq.w	l_015092
	movea.l	#A_DAT_1AB62, a0
	clr.l	d0
	move.b	A_SEL_1ACC9, d0
	subq.b	#$1, d0
	mulu.w	#$a, d0
	move.w	$4(a0, d0.l), A_THE_COMMAND
	bne.w	f_0103ae
l_015092:
	move.w	A_DAT_1AB52, A_THE_COMMAND
	bra.w	f_0103ae
l_0150a0:
	move.w	s_01abfe, A_THE_COMMAND
	bra.w	f_0103ae
