f_011f64:
	tst.b	A_SKIP_TRANSITION
	bne.w	f_0134da
	bsr.w	f_0128a4
	move.l	a6, -(a7)
	adda.l	A_DAT_1A534, a1
	subq.l	#$2, a1
	move.w	#$1, d2
	bsr.w	f_0124da
	subq.l	#$2, a1
	move.w	A_TEXT_BOX_SPAN, d1
	subq.w	#$1, d1
	move.w	d7, d0
	bsr.w	f_0111ac
	movea.l	(a7)+, a6
	rts	
