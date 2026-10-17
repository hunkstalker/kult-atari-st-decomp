f_016ed8:
	move.b	#$0001, A_DAT_1AD0D
	move.l	#s_01a414, A_CUR_FILENAME
	bsr.w	f_0107b6
	bmi.w	l_016f7c
	move.l	#A_CLEAR_BUF, d0
	move.l	#s_01d06e, d1
	sub.l	d0, d1
	move.l	d1, A_LOAD_LENGTH
	move.l	d0, A_LOAD_BUFFER
	bsr.w	f_0107e8
	bmi.w	l_016f7c
	cmp.l	A_LOAD_LENGTH, d0
	bne.w	l_016f7c
	move.l	A_SCREEN_PTR_B, A_LOAD_BUFFER
	move.l	#$7d00, A_LOAD_LENGTH
	bsr.w	f_0107e8
	bmi.w	l_016f7c
	cmp.l	A_LOAD_LENGTH, d0
	bne.w	l_016f7c
	bsr.w	f_0121c6
	bsr.w	f_0162da
	bsr.w	f_0107e8
	bmi.w	l_016f7c
	cmp.l	A_LOAD_LENGTH, d0
	bne.w	l_016f7c
	bsr.w	f_010828
	bmi.w	l_016f7c
	bsr.w	f_016f90
	bsr.w	f_016460
	clr.b	A_DAT_1AD0D
	clr.b	A_DAT_1A750
	rts	
l_016f7c:
	clr.b	A_DAT_1AD0D
	move.b	#$00ff, A_DAT_1A750
	ori.b	#$0001, ccr
	rts	
