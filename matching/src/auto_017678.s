f_017678:
	bsr.w	f_012368
	bsr.w	f_012384
	movea.l	s_01a812, a1
	clr.b	(a1)
	clr.w	A_DAT_1ABF8
	btst.b	#$6, $1(a1)
	bne.w	f_010768
	movea.l	s_01a816, a1
	andi.b	#$007f, $4(a1)
	movea.l	#s_019cfa, a1
	clr.b	A_DAT_1ACFF
	move.b	A_DAT_1AD00, d0
	bsr.w	f_0177bc
	bsr.w	f_017856
	rts	
