f_01842c:
	clr.b	A_FRAME_1AB4F
	move.w	#$a0, d4
	bsr.w	f_018f8e
	move.b	#$0001, A_DAT_1AD0D
	movea.l	A_SCREEN_PTR_B, a0
	move.l	#$f9f, d0
	move.l	#$ffffffff, d1
	move.l	#$ffff0000, d2
l_01845a:
	move.l	d1, (a0)+
	move.l	d2, (a0)+
	dbra	d0, l_01845a
	bsr.w	f_0181f0
	movea.l	A_SCREEN_PTR_B, a0
	move.w	#$f9f, d0
l_018470:
	clr.l	(a0)+
	clr.l	(a0)+
	dbra	d0, l_018470
	bsr.w	f_0121c6
	bsr.w	f_0182f0
	bsr.w	f_018334
	move.w	#$a1, d4
	bsr.w	f_018f8e
	move.w	#$27, d0
	move.w	#$5f, d2
	move.w	#$2c, d1
	bsr.w	f_0159e2
	move.b	#$0087, A_MODE_FLAG
l_0184a4:
	bsr.w	f_013568
	bpl.w	l_0184bc
	move.w	#$918e, A_THE_COMMAND
	jsr	f_0103ae
	bra.b	l_0184a4
l_0184bc:
	bsr.w	f_0135da
	bsr.w	f_0181f0
	bsr.w	f_0121c6
	bra.w	f_01682a
