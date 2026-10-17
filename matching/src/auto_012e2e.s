f_012e2e:
	lsl.w	#$2, d0
	lsl.w	#$2, d2
	move.w	d0, A_TEXT_BOX_X
	move.w	d1, A_TEXT_BOX_Y
	move.w	d2, A_TEXT_BOX_SPAN
	mulu.w	d2, d3
	move.w	d3, A_REV_TOTAL
	clr.l	d2
	move.b	A_ANIM_1A577, d2
	clr.l	d3
l_012e56:
	move.l	d3, d6
	move.w	A_TEXT_BOX_X, d0
	move.w	A_TEXT_BOX_Y, d1
	divu.w	A_TEXT_BOX_SPAN, d3
	add.w	d3, d1
	swap	d3
	add.w	d3, d0
	bsr.w	f_010fee
	move.w	#$8000, d4
	bsr.w	f_012ef6
	move.l	d6, d3
	move.w	A_ANIM_1A56A, d1
l_012e84:
	dbra	d1, l_012e84
	move.w	A_REV_TOTAL, d1
	add.w	d2, d3
	cmp.w	d3, d1
	beq.w	l_012ea0
	bcc.w	l_012e56
	sub.w	d1, d3
	bra.w	l_012e56
l_012ea0:
	rts	
