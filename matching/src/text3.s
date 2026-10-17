f_010a54:
	cmpi.b	#$87,A_MODE_FLAG
	beq.w	f_010768
	move.w	A_OVERLAY_X,d0
	move.w	A_OVERLAY_Y,d1
	subq.w	#1,d0
	subq.w	#2,d1
	bsr.w	f_010fec
	clr.w	d2
	move.b	A_TEXT_COL,d2
	addq.w	#2,d2
	move.w	#9,d3
	bsr.w	f_01215e
	rts
f_010a88:
	move.b	#$20,A_TEXT_ROW
	move.l	#$8000,A_SCREEN_DRAW_BASE
	move.w	#$2f,A_CURSOR_TEXT_X
	move.w	#$c1,A_CURSOR_TEXT_Y
	move.l	#s_1d3c2,A_COLOR_TABLE
	clr.w	d4
	move.b	A_TEXT_SEL_B,d4
	movea.l	#OVERLAY_A_TBL,a5
	bsr.w	f_010fb4
	bsr.w	f_010aee
	rts
f_010acc:
	move.w	#$2f,d0
	move.w	#$c1,d1
	subq.w	#1,d0
	subq.w	#2,d1
	bsr.w	f_010fec
	clr.w	d2
	move.b	#$20,d2
	addq.w	#2,d2
	move.w	#9,d3
	bsr.w	f_01215e
	rts
f_010aee:
	move.l	a5,-(a7)
	clr.w	d6
l_010af2:
	bsr.w	f_010946
	add.w	d0,d6
	movea.l	a4,a5
	cmpa.l	A_CUR_STR_END,a4
	bne.w	l_010af2
	move.w	A_TEXT_BOX_W,d7
	sub.w	d6,d7
	lsr.w	#1,d7
	move.w	d7,d6
	movea.l	(a7)+,a5
	subi.w	#1,d6
	bcs.w	l_010b24
	sub.w	d7,A_TEXT_BOX_W
	bsr.w	f_010b46
l_010b24:
	bsr.w	f_010998
	addq.w	#2,d6
	cmp.w	A_TEXT_BOX_W,d6
	bcs.w	l_010b3a
	move.w	d6,A_TEXT_BOX_W
l_010b3a:
	bsr.w	f_01090e
	tst.w	d6
	beq.w	l_010b50
	subq.w	#1,d6
f_010b46:
	clr.w	d0
	bsr.w	f_010838
	dbra	d6,f_010b46
l_010b50:
	rts
