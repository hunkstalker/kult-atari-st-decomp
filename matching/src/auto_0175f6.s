f_0175f6:
	bsr.w	f_012368
	movea.l	s_01a812, a1
	move.b	A_DAT_1ACD2, (a1)
	move.w	#$a018, A_DAT_1ABF8
	move.b	#$0003, A_DAT_1ACF2
	clr.b	A_DAT_1ACE7
	movea.l	#s_019cf7, a1
	move.b	A_DAT_1AD00, d0
	bsr.w	f_0177bc
	bsr.w	f_017856
	bsr.w	f_016556
	bsr.w	f_016582
	bsr.w	f_0121c6
	cmpi.b	#$0005, A_DAT_1ACFF
	bne.w	l_01765a
	move.w	#$c029, A_THE_COMMAND
	clr.b	A_DAT_1ACFF
	bra.w	f_0103ae
l_01765a:
	cmpi.b	#$0006, A_DAT_1ACFF
	bne.w	f_010768
	move.w	#$c165, A_THE_COMMAND
	clr.b	A_DAT_1ACFF
	bra.w	f_0103ae
