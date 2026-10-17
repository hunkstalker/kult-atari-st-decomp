f_013490:
	tst.b	A_SKIP_TRANSITION
	bne.w	f_01222e
	clr.w	d0
	move.b	$1(a6), d0
	bsr.w	f_0120e4
	move.w	d3, A_ELEM_1A52C
	bsr.w	f_013e14
	addq.l	#$2, a6
	rts	
