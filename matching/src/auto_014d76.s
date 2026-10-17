f_014d76:
	bsr.w	f_01060a
	move.w	#$8000, d2
	move.w	d2, d3
	move.w	#$ff, s_01a488
	bsr.w	f_014db2
	bra.w	f_0103ae
