f_016fb4:
	move.b	#$0001, A_DAT_1AD0D
	bsr.w	f_016556
	movea.l	#A_CLEAR_BUF, a0
	movea.l	#s_01a82e, a1
l_016fcc:
	tst.l	(a0)
	beq.w	l_016fda
	move.l	a0, d0
	subi.l	#s_0101a8, (a0)
l_016fda:
	addq.l	#$4, a0
	cmpa.l	a0, a1
	bne.w	l_016fcc
	move.l	#s_01a414, A_CUR_FILENAME
	bsr.w	f_0107d0
	bmi.w	l_01707c
	move.l	#A_CLEAR_BUF, d0
	move.l	#s_01d06e, d1
	sub.l	d0, d1
	move.l	d1, A_LOAD_LENGTH
	move.l	d0, A_LOAD_BUFFER
	bsr.w	f_010808
	bmi.w	l_01707c
	cmp.l	A_LOAD_LENGTH, d0
	bne.w	l_01707c
	move.l	A_SCREEN_PTR_A, A_LOAD_BUFFER
	move.l	#$7d00, A_LOAD_LENGTH
	bsr.w	f_010808
	bmi.w	l_01707c
	cmp.l	A_LOAD_LENGTH, d0
	bne.w	l_01707c
	move.l	A_SCREEN_PTR_B, A_LOAD_BUFFER
	bsr.w	f_010808
	bmi.w	l_01707c
	cmp.l	A_LOAD_LENGTH, d0
	bne.w	l_01707c
	bsr.w	f_010828
	bmi.w	l_01707c
	bsr.w	f_016f90
	clr.b	A_DAT_1AD0D
	clr.b	A_DAT_1A750
	rts	
l_01707c:
	bsr.w	f_016f90
	clr.b	A_DAT_1AD0D
	move.b	#$00ff, A_DAT_1A750
	ori.b	#$0001, ccr
	rts	
