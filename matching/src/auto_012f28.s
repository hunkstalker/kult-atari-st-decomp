f_012f28:
	tst.b	A_SKIP_TRANSITION
	bne.w	f_0134da
	bsr.w	f_0128a4
	lsl.w	#$2, d0
	move.w	d0, A_TEXT_BOX_X
	lsl.w	#$2, d2
	move.w	d2, A_TEXT_BOX_SPAN
	mulu.w	d2, d3
	move.w	d3, A_DAT_1A49E
	move.l	#$11, d2
	clr.l	d3
l_012f56:
	move.l	d3, d6
	movea.l	a1, a2
	move.l	d3, d0
	move.l	d3, d5
	andi.w	#$3, d5
	lsr.l	#$1, d0
	andi.l	#$fffffffe, d0
	adda.l	d0, a1
	move.w	A_TEXT_BOX_X, d0
	move.w	A_TEXT_BOX_Y, d1
	divu.w	A_TEXT_BOX_SPAN, d3
	add.w	d3, d1
	swap	d3
	add.w	d3, d0
	bsr.w	f_010fee
	move.w	(a1), d0
	lsl.w	d5, d0
	bsr.w	f_012fb6
	movea.l	a2, a1
	move.l	d6, d3
	move.w	#$64, d1
l_012f98:
	dbra	d1, l_012f98
	move.w	A_DAT_1A49E, d1
	add.w	d2, d3
	cmp.w	d3, d1
	beq.w	l_012fb4
	bcc.w	l_012f56
	sub.w	d1, d3
	bra.w	l_012f56
l_012fb4:
	rts	
