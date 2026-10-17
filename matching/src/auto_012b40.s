f_012b40:
	ror.b	#$1, d1
	move.b	d1, d6
	andi.b	#$0022, d6
	ror.b	#$2, d1
	move.b	d1, d7
	andi.b	#$0011, d7
	or.b	d7, d6
	ror.b	#$2, d1
	move.b	d1, d7
	andi.b	#$0088, d7
	or.b	d7, d6
	ror.b	#$2, d1
	andi.b	#$0044, d1
	or.b	d1, d6
	rts	
l_012b66:
	move.b	#$0009, d1
	cmpi.b	#$0018, A_MODE_FLAG
	beq.w	l_012b7a
	move.b	#$0066, d1
l_012b7a:
	move.b	d1, A_MODE_FLAG
	bsr.w	f_014496
	move.w	#$0, d1
	bsr.w	f_012a4a
	adda.l	A_DAT_1A534, a1
	subq.l	#$2, a1
	move.w	#$10, d0
	move.w	d0, A_TEXT_BOX_X
	bsr.w	f_010fec
	move.w	#$1, d2
	bsr.w	f_0124da
	subq.l	#$2, a1
	move.w	#$a, d1
	move.w	d7, d0
	bsr.w	f_0111ac
	movea.l	#s_01a83e, a2
	movem.l	d0/d2/a0-a1, -(a2)
	move.w	#$1, d1
	bsr.w	f_012a4a
	move.w	#$37, d0
	move.w	d0, A_TEXT_BOX_X
	bsr.w	f_010fec
	move.w	#$1, d2
	bsr.w	f_0124da
	subq.w	#$1, d7
	bcc.w	l_012bea
	move.w	#$f, d7
	subq.l	#$8, a0
l_012bea:
	addq.l	#$2, a1
	move.w	#$a, d1
	move.w	d7, d0
	bsr.w	f_0114b0
	movea.l	#s_1a84e, a2
	movem.l	d0/d2/a0-a1, -(a2)
	movea.l	(a7)+, a6
	bsr.w	f_018fa4
	rts	
l_012c08:
	move.b	#$005f, d1
	cmpi.b	#$0009, A_MODE_FLAG
	beq.w	l_012c1c
	move.b	#$0067, d1
l_012c1c:
	move.b	d1, A_MODE_FLAG
	bsr.w	f_014496
	move.w	#$0, d1
	bsr.w	f_012a4a
	movea.l	#s_01a82e, a2
	movem.l	(a2)+, d0/d2/a0-a1
	move.w	#$23, d1
	move.w	#$3b, d3
	bsr.w	f_0111b6
	move.w	#$1, d1
	bsr.w	f_012a4a
	movea.l	#s_01a83e, a2
	movem.l	(a2)+, d0/d2/a0-a1
	move.w	#$23, d1
	move.w	#$3b, d3
	bsr.w	f_0114ba
	movea.l	(a7)+, a6
	move.w	#$1e, d4
	bsr.w	f_018f8e
	rts	
l_012c6e:
	move.b	#$0018, d1
	cmpi.b	#$0009, A_MODE_FLAG
	beq.w	l_012c82
	move.b	#$001e, d1
l_012c82:
	move.b	d1, A_MODE_FLAG
	bsr.w	f_014496
	movea.l	#s_01a83e, a2
	movem.l	(a2)+, d0/d2/a0-a1
	move.w	#$2b, d1
	move.w	#$3b, d3
	movem.l	d0-d3/a0, -(a7)
	bsr.w	f_0117fe
	movem.l	(a7)+, d0-d3/a0
	move.w	#$14, d2
	move.w	d0, d7
	bsr.w	f_01215e
	movea.l	#s_01a82e, a2
	movem.l	(a2)+, d0/d2/a0-a1
	move.w	#$2b, d1
	move.w	#$3b, d3
	movem.l	d0-d3/a0, -(a7)
	bsr.w	f_011afa
	movem.l	(a7)+, d0-d3/a0
	move.w	#$14, d2
	move.w	d0, d7
	bsr.w	f_01215e
	movea.l	(a7)+, a6
	bsr.w	f_018fa4
	rts	
