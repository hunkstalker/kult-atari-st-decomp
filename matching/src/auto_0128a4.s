f_0128a4:
	clr.w	d1
	clr.w	d0
	clr.w	d3
	move.b	$1(a6), d1
	cmpi.b	#$00ff, d1
	bne.w	l_0128d8
	addq.l	#$2, a6
	tst.b	A_DAT_1AD0A
	bne.w	l_01294c
	movem.l	d0-d3, -(a7)
	bsr.w	f_018d28
	movem.l	(a7)+, d0-d3
	bsr.w	f_01285a
	beq.w	l_01294c
	bra.b	l_0128e2
l_0128d8:
	move.b	$2(a6), d0
	move.b	$3(a6), d3
	addq.l	#$4, a6
l_0128e2:
	move.w	d0, A_TEXT_BOX_X
	move.w	d3, A_TEXT_BOX_Y
	move.b	d1, A_ELEM_1AB4E
	subq.w	#$1, d1
	bsr.w	f_0129c8
	clr.w	d2
	addq.l	#$2, a1
	move.b	(a1)+, d2
	move.w	d2, A_ELEM_1A52C
	move.b	(a1)+, d2
	move.w	d2, A_TEXT_BOX_SPAN
	move.l	a1, A_ELEM_1A528
	move.w	A_TEXT_BOX_X, d0
	move.w	A_TEXT_BOX_Y, d1
	bsr.w	f_010fec
	move.w	A_ELEM_1A52C, d3
	move.w	A_TEXT_BOX_SPAN, d2
	move.w	A_TEXT_BOX_X, d0
	move.w	A_TEXT_BOX_Y, d1
	movea.l	A_ELEM_1A528, a1
	move.w	#$2, d4
	bsr.w	f_0120a8
	rts	
l_01294c:
	addq.l	#$4, a7
	rts	
