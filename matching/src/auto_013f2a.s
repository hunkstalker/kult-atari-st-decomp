f_013f2a:
	move.b	A_DAT_1ACF1, d0
	addq.l	#$1, a6
	move.l	#$5c, d1
	bsr.w	f_013f56
	move.w	#$1f, d4
	move.w	#$1d, d1
	bsr.w	f_018f7a
	bra.w	f_0121c6
