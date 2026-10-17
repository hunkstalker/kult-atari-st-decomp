f_0166ec:
	clr.l	d2
	movea.l	A_SEL_1A7D2, a2
	move.b	A_SEL_1AB4A, d2
	cmpa.l	A_OBJ_END, a2
	bne.w	l_01670c
	movea.l	A_OBJ_BEGIN, a2
	clr.b	d2
l_01670c:
	addq.b	#$1, d2
	move.b	$4(a2), d1
	btst.b	#$6, d1
	beq.w	l_016790
	andi.b	#$00f8, d1
	cmpi.b	#$00d0, d1
	bne.w	l_016790
	move.l	a2, A_SEL_1A7D2
	addi.l	#$8, A_SEL_1A7D2
	move.b	d2, A_SEL_1AB4A
	move.l	a2, d3
	sub.l	A_OBJ_BEGIN, d3
	lsr.l	#$3, d3
	addq.b	#$1, d3
	bsr.w	f_016636
	beq.w	l_01678a
	movem.l	d2-d3/d7/a0, -(a7)
	bsr.w	f_013594
	bsr.w	f_01060a
	movem.l	(a7)+, d2-d3/d7/a0
	adda.l	#$8000, a0
	bsr.w	f_01215e
	bsr.w	f_010526
	clr.l	d2
	move.b	A_SEL_1AB4A, d2
	subq.l	#$1, d2
	lsl.l	#$2, d2
	movea.l	#A_ICON_TBL, a2
	adda.l	d2, a2
	movea.l	(a2), a1
	bsr.w	f_0124f8
	rts	
l_01678a:
	move.b	A_SEL_1AB4A, d2
l_016790:
	addq.l	#$8, a2
	cmpa.l	A_OBJ_END, a2
	bne.w	l_01670c
	move.l	a2, A_SEL_1A7D2
	move.b	d2, A_SEL_1AB4A
	rts	
