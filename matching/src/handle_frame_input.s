f_01031c:
	bsr.w	f_013594
	tst.b	A_FRAME_1AB4F
	beq.w	l_01034a
	cmpi.w	#$96,A_CURSOR_Y
	bcs.w	l_01034a
	cmpi.w	#$b4,A_CURSOR_Y
	btst.b	#0,A_DAT_1ACD4
	bne.w	f_01031c
l_01034a:
	bsr.w	f_01060a
	move.b	A_TEXT_SEL_A,d0
	cmp.b	A_1AB44,d0
	beq.w	l_01036c
	bsr.w	f_010a54
	move.b	A_TEXT_SEL_A,A_1AB44
l_01036c:
	move.b	A_TEXT_SEL_B,d0
	cmp.b	A_1AB47,d0
	beq.w	l_01038a
	bsr.w	f_010acc
	move.b	A_TEXT_SEL_B,A_1AB47
l_01038a:
	bsr.w	f_010526
	rts
