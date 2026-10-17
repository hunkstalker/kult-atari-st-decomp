f_018192:
	cmpi.b	#$0008, A_DAT_1ACC7
	bne.w	l_0181a6
	move.w	#$5, d0
	bsr.w	f_01066e
l_0181a6:
	move.b	#$00be, d0
	bsr.w	f_0177bc
	bne.w	l_0181ca
	movea.l	A_SEL_OBJECT, a0
	andi.b	#$007f, $4(a0)
	movea.l	A_SEL_ICON_PTR, a2
	movea.l	(a2), a1
	bsr.w	f_0124f8
l_0181ca:
	movea.l	#s_019dbd, a6
	move.b	A_DAT_1ACC7, d1
l_0181d6:
	cmp.b	(a6), d1
	beq.w	l_0181ea
	addq.l	#$4, a6
	cmpa.l	#A_ELEM_TBL_19E19, a6
	beq.w	f_010768
	bra.b	l_0181d6
l_0181ea:
	bsr.w	f_0159d2
	rts	
