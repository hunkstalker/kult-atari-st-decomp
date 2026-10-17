f_015530:
	addq.b	#$1, A_DAT_1ACEB
	addi.w	#$12c, A_DAT_1AB60
	move.w	A_W_1ACAA, A_THE_COMMAND
	bsr.w	f_0103ae
	move.w	A_DAT_1ACAE, A_THE_COMMAND
	bsr.w	f_0103ae
	move.b	A_DAT_1ACF2, A_DAT_1ACE7
	move.w	A_DAT_1AB5E, A_THE_COMMAND
	bne.w	l_015022
	tst.w	A_DAT_1ABF8
	bne.w	f_010768
	move.w	#$9005, A_THE_COMMAND
	bra.w	f_0103ae
