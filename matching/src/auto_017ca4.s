f_017ca4:
	addq.l	#$1, a6
	cmpi.b	#$0012, A_DAT_1AD09
	beq.w	f_010768
	move.l	a6, -(a7)
	movea.l	A_ELEM_CLASS, a0
	move.l	a0, d0
	subi.l	#A_OBJ_TBL, d0
	move.w	d0, s_01aa70
	movea.l	A_SEL_OBJECT, a3
	ori.b	#$0040, $1(a0)
	clr.b	(a0)
	andi.b	#$007f, $4(a3)
	move.b	$3(a0), d0
	cmpi.b	#$0010, d0
	beq.w	l_017dea
	cmpi.b	#$0008, d0
	beq.w	l_017e22
	tst.b	s_01a57a
	bne.w	l_017d24
	tst.b	s_01ad26
	bne.w	l_017d24
	tst.b	A_DAT_1ACF7
	beq.w	l_017d24
	tst.b	s_01a57b
	bne.w	l_017d24
	andi.b	#$00fe, s_01ad02
	bra.w	l_017de6
l_017d24:
	clr.b	s_01a57a
	move.b	#$002f, d0
	cmpi.b	#$0038, $2(a0)
	beq.w	l_017d4c
	move.b	#$0042, d0
	cmpi.b	#$0033, $2(a0)
	bne.w	l_017d5a
	clr.w	A_DAT_1ACAE
l_017d4c:
	movea.l	#s_019d2d, a6
	movea.l	#s_019d55, a5
	bra.b	l_017d68
l_017d5a:
	clr.b	d0
	movea.l	#s_019dbd, a5
	movea.l	#s_019d55, a6
l_017d68:
	move.b	A_DAT_1ACC7, d1
l_017d6e:
	cmp.b	(a6), d1
	beq.w	l_017d7e
	addq.l	#$4, a6
	cmpa.l	a5, a6
	beq.w	l_017de6
	bra.b	l_017d6e
l_017d7e:
	tst.b	d0
	beq.w	l_017d88
	move.b	d0, $1(a6)
l_017d88:
	cmpi.b	#$0018, $1(a6)
	beq.w	l_017d9c
	cmpi.b	#$001c, $1(a6)
	bne.w	l_017dae
l_017d9c:
	move.b	#$0001, s_0192d0
	move.w	#$96, d4
	bsr.w	f_018f8e
	bra.b	l_017dd4
l_017dae:
	cmpi.b	#$0037, $1(a6)
	bne.w	l_017dc2
	move.w	#$97, d4
	bsr.w	f_018f8e
	bra.b	l_017dd4
l_017dc2:
	cmpi.b	#$0043, $1(a6)
	bne.w	l_017dd4
	move.w	#$b1, d4
	bsr.w	f_018f8e
l_017dd4:
	bsr.w	f_0159d2
	tst.b	s_0192d0
	bne.w	l_017de6
	bsr.w	f_018fa4
l_017de6:
	movea.l	(a7)+, a6
	rts	
l_017dea:
	move.b	A_DAT_1ACD2, s_01ab1c
	movea.l	#s_019cfd, a1
	move.b	$1(a0), s_01ab1d
l_017e02:
	tst.b	A_DAT_1ACF7
	bne.w	l_017e12
	clr.w	d0
	bsr.w	f_017856
l_017e12:
	move.w	A_W_1ACAA, A_THE_COMMAND
	bsr.w	f_0103ae
	bra.b	l_017de6
l_017e22:
	movea.l	#s_019d00, a1
	move.b	A_DAT_1ACD2, s_01ab21
	move.b	$1(a0), s_01ab22
	bra.b	l_017e02
