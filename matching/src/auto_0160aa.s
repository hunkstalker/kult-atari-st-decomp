f_0160aa:
	addq.l	#$1, a6
	bsr.w	f_01606e
	tst.w	d6
	bne.w	l_0160bc
	subq.l	#$1, a6
	bra.w	f_01350c
l_0160bc:
	addq.l	#$2, a6
	rts	
