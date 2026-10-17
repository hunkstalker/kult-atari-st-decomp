f_013572:
	movea.l	A_SCREEN_PTR_B, a1
	suba.l	#$22, a1
	move.l	a1, A_LOAD_BUFFER
	move.l	#$7d22, A_LOAD_LENGTH
	bsr.w	f_01076a
	rts	
