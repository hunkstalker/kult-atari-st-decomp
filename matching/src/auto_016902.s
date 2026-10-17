f_016902:
	clr.w	d4
	move.b	#$0006, d4
	cmpi.b	#$0055, A_DAT_1ACD7
	bcc.w	l_016926
	addq.b	#$1, d4
	cmpi.b	#$00aa, A_DAT_1ACD7
	bcc.w	l_016926
	move.b	#$0023, d4
l_016926:
	movea.l	#s_03c534, a5
	bsr.w	f_010fb4
	move.w	A_TEXT_INDEX, A_DAT_1A484
	bsr.w	f_01695a
	andi.b	#$00bf, $3(a6)
	bsr.w	f_010b6c
	move.b	#$0023, d1
	bsr.w	f_018e12
	bsr.w	f_01228a
	bsr.w	f_01232e
	rts	
