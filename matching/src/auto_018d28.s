f_018d28:
	movea.l	A_SEL_ICON_PTR, a2
	tst.l	(a2)
	beq.w	l_018dbe
	move.l	A_SEL_OBJECT, A_SEL_1A7D2
	move.b	A_SEL_1ACC9, A_SEL_1AB4A
	subq.b	#$1, A_SEL_1AB4A
	move.l	a2, -(a7)
	movea.l	(a2), a1
	clr.w	d2
	clr.w	d3
	move.b	(a1)+, d2
	move.b	(a1)+, d3
	move.l	(a1)+, d0
	sub.l	A_SCREEN_PTR_B, d0
	divu.w	#$a0, d0
	move.w	d0, d1
	swap	d0
	lsl.w	#$1, d0
	andi.w	#$fff0, d0
	or.w	(a1), d0
	lsl.w	#$2, d2
	subq.w	#$1, d2
	subq.w	#$1, d3
	movem.l	d0-d3, -(a7)
	move.w	#$0, d2
	bsr.w	f_013216
	movem.l	(a7)+, d0-d3
	movem.l	d0-d3, -(a7)
	move.w	d2, d3
	move.w	#$0, d2
	bsr.w	f_012ffa
	movem.l	(a7)+, d0-d3
	movem.l	d0-d3, -(a7)
	add.w	d2, d0
	move.w	#$0, d2
	bsr.w	f_013216
	movem.l	(a7)+, d0-d3
	add.w	d3, d1
	move.w	d2, d3
	move.w	#$0, d2
	bsr.w	f_012ffa
	movea.l	(a7)+, a2
	bra.w	f_01652e
l_018dbe:
	rts	
