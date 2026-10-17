f_018316:
	bsr.w	f_016230
	move.w	d0, $4(a1)
	bsr.w	f_016230
	move.w	d0, $6(a1)
	bsr.w	f_016230
	andi.w	#$fff, d0
	move.w	d0, $8(a1)
	rts	
