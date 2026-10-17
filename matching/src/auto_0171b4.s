f_0171b4:
	movea.l	s_01a80a, a1
	addq.l	#$1, a1
	move.b	A_DAT_1ACD2, A_OBJ_TBL
	clr.b	d0
	bsr.w	f_0177bc
	bsr.w	f_017856
	bsr.w	f_018fa4
	move.w	#$a015, A_W_1ACAA
	move.w	A_DAT_1AB60, d0
	addi.w	#$5, d0
	move.w	d0, A_DAT_1ACAC
	bsr.w	f_016556
	bsr.w	f_016582
	bsr.w	f_0121c6
	rts	
