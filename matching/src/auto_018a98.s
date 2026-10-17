f_018a98:
	move.l	a6, -(a7)
	move.b	#$0005, A_DAT_1AD0D
	movea.l	A_SCREEN_PTR_B, a1
	move.w	#$1f3f, d1
l_018aac:
	clr.l	(a1)+
	dbra	d1, l_018aac
	bsr.w	f_0121c6
	movea.l	#s_019714, a6
	bsr.w	f_0128a4
	subq.w	#$1, d3
	move.w	d3, s_01a544
	lsl.w	#$2, d2
	subq.w	#$1, d2
	move.w	d2, s_01a542
	move.w	#$c7, s_01a4a8
	move.w	#$2710, s_1a84e
	addq.l	#$4, a6
	bra.b	l_018aea
l_018ae6:
	move.w	(a6)+, d0
	move.w	(a6)+, d1
l_018aea:
	move.w	(a6)+, s_01a4aa
	move.w	(a6)+, d3
	lsr.w	#$1, d3
	move.w	d3, s_01a4ac
	add.w	d1, d3
	move.w	d3, s_01a4a6
	sub.w	d1, s_01a4a8
	addq.w	#$1, s_01a4a8
	bsr.w	f_010fee
	movea.l	a0, a5
	suba.l	d0, a5
	move.l	a5, s_01a4ba
	move.w	d7, s_01a486
	move.w	s_01a4aa, d3
	move.w	s_01a4ac, d2
	movea.l	a0, a1
	suba.l	#$8000, a1
	bsr.w	f_013bc2
	tst.b	s_01a571
	bne.w	l_018bf8
	move.b	#$0001, s_01a571
	movea.l	s_01a4ba, a0
	suba.l	#$8000, a0
	move.w	#$13, d2
	move.w	#$36, d3
	movea.l	a0, a4
	suba.l	#$a0, a4
l_018b68:
	move.w	d2, d4
	movea.l	a0, a2
	movea.l	a4, a5
l_018b6e:
	move.l	(a2)+, (a5)+
	move.l	(a2)+, (a5)+
	dbra	d4, l_018b6e
	adda.l	#$a0, a0
	suba.l	#$a0, a4
	dbra	d3, l_018b68
	movea.l	#s_01a1d2, a0
	movea.l	A_PALETTE_PTR, a1
	move.w	#$7, d0
l_018b96:
	move.l	(a0)+, (a1)+
	dbra	d0, l_018b96
	bsr.w	f_016300
	movea.l	A_SCREEN_PTR_A, a3
	adda.l	#$7c60, a3
	move.w	#$13, d5
	move.w	#$6b, d7
l_018bb4:
	move.w	d5, d6
	movea.l	a4, a0
	movea.l	a3, a2
l_018bba:
	move.l	(a0)+, (a2)+
	move.l	(a0)+, (a2)+
	dbra	d6, l_018bba
	suba.l	#$a0, a3
	addi.w	#$14, d5
	bsr.w	f_013594
	bsr.w	f_013594
	dbra	d7, l_018bb4
	suba.l	#$8000, a3
	move.w	#$897, d7
l_018be2:
	clr.l	(a3)+
	dbra	d7, l_018be2
	move.w	#$ea60, d7
l_018bec:
	dbra	d7, l_018bec
	move.w	#$f0, d4
	bsr.w	f_018f8e
l_018bf8:
	movea.l	s_01a4ba, a0
	move.w	#$13, d2
	move.w	s_01a4a8, d3
	movea.l	a0, a1
	suba.l	#$8000, a1
	movea.l	a0, a4
	suba.l	#$a0, a4
l_018c18:
	move.w	d2, d4
	movea.l	a0, a2
	movea.l	a1, a3
	movea.l	a4, a5
l_018c20:
	move.l	(a3), (a2)+
	move.l	(a3), (a5)+
	clr.l	(a3)+
	move.l	(a3), (a2)+
	move.l	(a3), (a5)+
	clr.l	(a3)+
	dbra	d4, l_018c20
	adda.l	#$a0, a0
	adda.l	#$a0, a1
	suba.l	#$a0, a4
	dbra	d3, l_018c18
	move.w	s_01a4a6, d0
	move.w	d0, s_01a4a8
	bsr.w	f_013594
	move.w	s_1a84e, d0
l_018c5c:
	subq.w	#$1, d0
	bne.w	l_018c5c
	addi.w	#$1f4, s_1a84e
	cmpa.l	#s_0198c0, a6
	beq.w	l_018c78
	bra.w	l_018ae6
l_018c78:
	movea.l	(a7)+, a6
	addq.l	#$1, a6
	bsr.w	f_0182f0
l_018c80:
	move.l	#$64, d5
	bsr.w	f_01834a
	bra.w	l_018c80
