f_0134b2:
	tst.b	A_SKIP_TRANSITION
	bne.w	f_01222e
	clr.w	d0
	move.b	$1(a6), d0
	bsr.w	f_0120e4
	move.w	d3, A_ELEM_1A52C
	move.w	d2, A_TEXT_BOX_SPAN
	bsr.w	f_013eae
	addq.l	#$2, a6
	rts	
