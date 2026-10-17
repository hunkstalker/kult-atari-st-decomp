f_011f98:
	tst.b	A_SKIP_TRANSITION
	bne.w	f_0134da
	bsr.w	f_0128a4
	move.l	a6, -(a7)
	add.w	d2, d0
	subq.w	#$1, d0
	bsr.w	f_010fec
	move.w	#$1, d2
	bsr.w	f_0124da
	subq.w	#$1, d7
	bcc.w	l_011fc4
	move.w	#$f, d7
	subq.l	#$8, a0
l_011fc4:
	addq.l	#$2, a1
	move.w	A_TEXT_BOX_SPAN, d1
	subq.w	#$1, d1
	move.w	d7, d0
	bsr.w	f_0114b0
	movea.l	(a7)+, a6
	rts	
