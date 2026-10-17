f_01090e:
	movem.w	d0-d1,-(a7)
	move.w	A_TEXT_BOX_W,d6
l_010918:
	bsr.w	f_010946
	cmp.w	d0,d6
	bcs.w	l_010940
	sub.w	d0,d6
	bsr.w	f_0108a2
	bne.w	l_010940
	tst.w	d6
	beq.w	l_010940
	subi.w	#1,d6
	clr.w	d0
	bsr.w	f_010838
	bra.w	l_010918
l_010940:
	movem.w	(a7)+,d0-d1
	rts
f_010946:
	movea.l	a5,a4
	clr.l	d0
	move.b	(a4),d1
	andi.b	#$3f,d1
	bne.w	l_010964
	addi.w	#1,d0
	addq.l	#1,a4
	cmpa.l	A_CUR_STR_END,a4
	beq.w	l_010996
l_010964:
	move.b	(a4),d1
	andi.b	#$3f,d1
	beq.w	l_010996
	addi.w	#1,d0
	move.b	(a4),d1
	andi.b	#$c0,d1
	beq.w	l_010986
	cmpi.b	#$40,d1
	beq.w	l_010994
	addq.w	#1,d0
l_010986:
	addq.l	#1,a4
	cmpa.l	A_CUR_STR_END,a4
	bne.w	l_010964
	rts
l_010994:
	addq.l	#1,a4
l_010996:
	rts
f_010998:
	movea.l	a5,a3
	clr.w	d6
	clr.w	d5
l_01099e:
	bsr.w	f_010946
	addq.w	#1,d5
	cmp.w	d0,d6
	bcc.w	l_0109ac
	move.w	d0,d6
l_0109ac:
	movea.l	a4,a5
	cmpa.l	A_CUR_STR_END,a4
	bne.w	l_01099e
	movea.l	a3,a5
	rts
f_0109bc:
	movea.l	a5,a3
	movea.l	a5,a4
	move.w	#1,d5
	move.w	A_TEXT_BOX_W,d6
l_0109ca:
	movea.l	a4,a5
	cmpa.l	A_CUR_STR_END,a5
	beq.w	l_0109fa
	bsr.w	f_010946
	cmp.w	d0,d6
	bcs.w	l_0109ec
	sub.w	d0,d6
	tst.w	d6
	beq.w	l_0109ec
	subq.w	#1,d6
	bra.b	l_0109ca
l_0109ec:
	addq.w	#1,d5
	move.w	A_TEXT_BOX_W,d6
	sub.w	d0,d6
	subq.w	#1,d6
	bra.b	l_0109ca
l_0109fa:
	movea.l	a3,a5
	rts
f_0109fe:
	cmpi.b	#$87,A_MODE_FLAG
	beq.w	f_010768
	move.b	A_TEXT_COL,A_TEXT_ROW
	move.l	#$8000,A_SCREEN_DRAW_BASE
	move.w	A_OVERLAY_X,A_CURSOR_TEXT_X
	move.w	A_OVERLAY_Y,A_CURSOR_TEXT_Y
	move.l	#s_1d3c2,A_COLOR_TABLE
	clr.w	d4
	move.b	A_TEXT_SEL_A,d4
	movea.l	#OVERLAY_B_TBL,a5
	bsr.w	f_010fb4
	bsr.w	f_010aee
	rts
