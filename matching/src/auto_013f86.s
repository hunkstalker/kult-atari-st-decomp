f_013f86:
	bsr.w	f_015944
	move.b	A_DAT_1ACF1, d1
	move.w	d1, A_DAT_1A49E
	move.l	a6, -(a7)
	movea.l	#s_024982, a4
	clr.l	d1
	move.b	A_DAT_1ACC7, d1
	subq.w	#$1, d1
	bsr.w	f_012950
	move.l	a4, A_DAT_1A4B2
	movea.l	a5, a6
	move.l	#$ff00ff00, A_DAT_1AB40
	movea.l	#s_01a7b6, a4
	clr.b	s_01a751
l_013fca:
	clr.l	d4
	move.b	(a6), d4
	cmpi.b	#$0032, d4
	bcs.w	l_01401e
	cmpi.b	#$003d, d4
	bcc.w	l_01401e
	subq.l	#$3, a6
	move.l	a6, (a4)+
	addq.l	#$3, a6
	addq.b	#$1, s_01a751
	move.b	s_01a751, d0
	cmp.b	A_SEL_1ACC9, d0
	beq.w	l_01401a
	cmpi.b	#$0020, A_DAT_1ACC7
	bne.w	l_01401e
	cmpi.b	#$003b, d4
	bne.w	l_01401e
	btst.b	#$3, s_01aced
	beq.w	l_01401e
l_01401a:
	addq.l	#$3, a6
	bra.b	l_013fca
l_01401e:
	bsr.w	f_014138
	cmp.b	A_DAT_1AB40, d6
	bcc.w	l_014032
	move.b	d6, A_DAT_1AB40
l_014032:
	move.b	d6, d4
	add.b	d2, d4
	cmp.b	A_DAT_1AB41, d4
	bcs.w	l_014046
	move.b	d4, A_DAT_1AB41
l_014046:
	cmp.b	A_DAT_1AB42, d5
	bcc.w	l_014056
	move.b	d5, A_DAT_1AB42
l_014056:
	move.b	d5, d4
	add.b	d3, d4
	cmp.b	A_DAT_1AB43, d4
	bcs.w	l_01406a
	move.b	d4, A_DAT_1AB43
l_01406a:
	addq.l	#$3, a6
	cmpa.l	A_DAT_1A4B2, a6
	bne.w	l_013fca
	clr.w	d1
	clr.w	d0
	move.b	A_DAT_1AB41, d1
	move.b	A_DAT_1AB40, d0
	sub.b	d0, d1
	subq.b	#$2, d1
	move.b	d1, A_TEXT_COL
	move.w	d0, A_CURSOR_TEXT_X
	move.w	d0, A_OVERLAY_X
	addq.w	#$1, A_OVERLAY_X
	move.b	A_DAT_1AB43, d1
	addq.b	#$2, d1
	move.w	d1, A_OVERLAY_Y
	move.w	d1, A_CURSOR_TEXT_Y
	move.b	#$003b, d0
	move.l	#$8000, A_SCREEN_DRAW_BASE
	move.l	#s_1d3c2, A_COLOR_TABLE
	bsr.w	f_010838
	bsr.w	f_0109fe
	move.b	#$003c, d0
	bsr.w	f_010838
	move.w	A_OVERLAY_X, d0
	move.w	A_OVERLAY_Y, d1
	subq.w	#$1, d0
	lsl.w	#$2, d0
	subq.w	#$2, d1
	clr.w	d6
	move.b	A_TEXT_COL, d6
	addq.w	#$2, d6
	lsl.w	#$2, d6
	move.w	d6, d3
	move.w	#$7, d2
	bsr.w	f_012fee
	move.w	d6, d3
	addq.w	#$1, d1
	move.w	#$6, d2
	bsr.w	f_012fee
	move.w	d6, d3
	addq.w	#$7, d1
	move.w	#$7, d2
	bsr.w	f_012fee
	subq.w	#$8, d1
	move.w	#$9, d3
	bsr.w	f_01320a
	add.w	d6, d0
	subq.w	#$1, d0
	move.w	#$9, d3
	bsr.w	f_01320a
	movea.l	(a7)+, a6
	rts	
