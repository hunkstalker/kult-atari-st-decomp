f_0132ec:
	tst.b	A_SKIP_TRANSITION
	bne.w	f_0134da
	bsr.w	f_0128a4
	bsr.w	f_0127e0
	move.w	A_TEXT_BOX_X, d0
	move.w	A_TEXT_BOX_Y, d1
	move.w	A_TEXT_BOX_SPAN, d2
	move.w	A_ELEM_1A52C, d3
	movem.l	d3/a0, -(a7)
	bsr.w	f_013e14
	movem.l	(a7)+, d3/a0
	movea.l	#A_SAVE_DESC, a1
	bsr.w	f_012466
	rts	
