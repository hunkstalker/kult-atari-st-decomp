f_017480:
	movea.l	#A_OBJ_TBL, a1
	cmpi.b	#$0037, A_DAT_1ACD2
	bne.w	l_0174b8
	move.b	#$0037, $5(a1)
	move.b	#$0037, $a(a1)
	move.b	#$0037, $f(a1)
	move.b	#$0032, $7(a1)
	move.b	#$0032, $c(a1)
	move.b	#$0032, $11(a1)
	rts	
l_0174b8:
	clr.b	$5(a1)
	clr.b	$a(a1)
	clr.b	$f(a1)
	clr.b	$14(a1)
	cmpi.b	#$003f, A_DAT_1ACEC
	bcc.w	f_010768
	cmpi.b	#$002c, A_DAT_1ACD2
	bcc.w	f_010768
	move.b	#$0011, d0
	bsr.w	f_01778e
	bne.w	f_010768
	move.l	a0, s_01a816
	clr.l	d1
	move.b	A_DAT_1AD00, d1
	addq.b	#$5, d1
	cmpi.b	#$0019, d1
	bcs.w	l_017508
	move.b	#$0005, d1
l_017508:
	move.b	d1, A_DAT_1AD00
	adda.l	d1, a1
	move.l	a1, s_01a812
	btst.b	#$6, $1(a1)
	bne.w	f_010768
	move.b	A_DAT_1ACD7, d1
	bsr.w	f_016210
	clr.b	d2
	cmpi.b	#$0006, A_DAT_1ACD2
	bcc.w	l_01758c
	cmpi.b	#$005a, d1
	bcc.w	l_017574
	tst.b	$4(a1)
	beq.w	l_017574
	cmpi.b	#$0006, $4(a1)
	bcs.w	l_017574
	cmpi.b	#$001b, $4(a1)
	bcc.w	l_017574
	cmpi.b	#$0013, $4(a1)
	bcs.w	l_017570
	cmpi.b	#$0017, $4(a1)
	bcs.w	l_017574
l_017570:
	move.b	#$0001, d2
l_017574:
	cmpi.b	#$0017, d0
	bcs.w	l_0175c4
	cmpi.b	#$0034, d0
	bcs.w	l_0175e8
	clr.b	A_DAT_1ACFF
	rts	
l_01758c:
	cmpi.b	#$0027, d1
	bcc.w	l_0175a0
	tst.b	$4(a1)
	beq.w	l_0175a0
	move.b	#$0001, d2
l_0175a0:
	cmpi.b	#$00a6, d1
	bcs.w	l_0175ac
	move.b	#$0002, d2
l_0175ac:
	cmpi.b	#$001a, d0
	bcs.w	l_0175c4
	cmpi.b	#$0034, d0
	bcs.w	l_0175e8
	clr.b	A_DAT_1ACFF
	rts	
l_0175c4:
	move.b	A_DAT_1ACD2, (a1)
	move.w	#$a018, A_DAT_1ABF8
l_0175d2:
	move.b	#$0003, A_DAT_1ACF2
	move.b	d2, A_DAT_1ACFF
	move.l	a1, A_ELEM_CLASS
	rts	
l_0175e8:
	move.w	#$a019, A_DAT_1ABF8
	ori.b	#$0004, d2
	bra.b	l_0175d2
