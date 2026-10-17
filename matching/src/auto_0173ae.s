f_0173ae:
	movea.l	s_01a80e, a1
	addq.l	#$1, a1
	move.b	A_DAT_1ACD2, s_01aa8b
	move.w	#$19, d0
	bsr.w	f_0177bc
	bsr.w	f_017856
	move.w	#$a01f, A_DAT_1ACAE
	move.w	A_DAT_1AB60, d0
	addi.w	#$5, d0
	move.w	d0, A_DAT_1ACB0
	bsr.w	f_016556
	bsr.w	f_016582
	bsr.w	f_0121c6
	rts	
