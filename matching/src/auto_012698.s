f_012698:
	move.w	d7, d0
	move.w	#$ffff, d1
	lsr.w	d0, d1
	not.w	d1
	lsr.w	#$2, d0
	move.w	#$4, d5
	sub.w	d0, d5
	move.w	d2, d6
	move.w	#$1, d4
	sub.w	d5, d6
	bls.w	l_0126c0
l_0126b6:
	addq.l	#$1, d4
	subi.w	#$4, d6
	bhi.w	l_0126b6
l_0126c0:
	neg.w	d6
	lsl.w	#$2, d6
	move.w	#$ffff, d5
	asl.w	d6, d5
	not.w	d5
	move.w	d1, A_BLIT_MASK_FIRST
	move.w	d5, A_BLIT_MASK_LAST
	move.w	d4, A_BLIT_GROUPS
	rts	
