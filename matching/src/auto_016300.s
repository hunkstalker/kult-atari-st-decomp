f_016300:
	move.l	A_PALETTE_PTR, -(a7)
	move.w	#$6, -(a7)
	trap	#$e
	addq.l	#$6, a7
	rts	
