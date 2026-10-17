f_011f02:
	tst.b	A_SKIP_TRANSITION
	bne.w	f_0134da
	bsr.w	f_0128a4
	bsr.w	f_0126e0
	clr.l	d4
	move.w	d3, d4
	subq.l	#$1, d4
	lsl.l	#$6, d4
	movea.l	#A_SAVE_DESC, a1
	adda.l	d4, a1
	move.w	d3, d1
	subq.w	#$1, d1
	bsr.w	f_011ece
	rts	
