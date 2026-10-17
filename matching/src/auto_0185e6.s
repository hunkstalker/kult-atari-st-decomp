f_0185e6:
	move.w	#$e1, d4
	bsr.w	f_018f8e
	movea.l	A_SEL_OBJECT, a0
	clr.w	d0
	clr.w	d2
	move.b	(a0), d0
	move.b	$2(a0), d2
	movem.l	d0/d2, -(a7)
	addq.w	#$1, d0
	addq.w	#$6, d2
	move.w	#$2a, d1
	bsr.w	f_0159e2
	clr.w	d4
	move.b	A_DAT_1ACD7, d4
	andi.w	#$3, d4
	cmpi.w	#$e10, A_DAT_1AB60
	bcs.w	l_01862a
	ori.w	#$4, d4
l_01862a:
	addi.w	#$141, d4
	movea.l	#s_03c534, a5
	bsr.w	f_010fb4
	move.w	A_TEXT_INDEX, A_DAT_1A484
	movea.l	#s_019970, a6
	movem.l	(a7)+, d0/d2
	movem.l	d0/d2, -(a7)
	cmpi.b	#$0023, d0
	bcc.w	l_018666
	addi.w	#$8, d0
	move.b	#$00b4, $3(a6)
	bra.w	l_018670
l_018666:
	subi.b	#$0017, d0
	move.b	#$0094, $3(a6)
l_018670:
	subi.w	#$28, d2
	move.b	d2, $2(a6)
	move.b	d0, $1(a6)
	bsr.w	f_010b6c
	move.b	#$0022, d1
	bsr.w	f_018e12
	movem.l	(a7)+, d0/d2
	move.w	#$2b, d1
	movem.l	d0/d2, -(a7)
	bsr.w	f_0159e2
	bsr.w	f_01228a
	bsr.w	f_01232e
	move.w	#$e1, d4
	bsr.w	f_018f8e
	movem.l	(a7)+, d0/d2
	move.w	#$2d, d1
	bsr.w	f_0159e2
	rts	
