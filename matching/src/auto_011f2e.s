f_011f2e:
	tst.b	A_SKIP_TRANSITION
	bne.w	f_0134da
	bsr.w	f_0128a4
	bsr.w	f_0126e0
	move.w	A_TEXT_BOX_X, d0
	move.w	A_TEXT_BOX_Y, d1
	add.w	d3, d1
	subq.w	#$1, d1
	bsr.w	f_010fec
	movea.l	#A_SAVE_DESC, a1
	move.w	d3, d1
	subq.w	#$1, d1
	bsr.w	f_011ee8
	rts	
