f_014d90:
	bsr.w	f_01060a
	move.w	#$4000, d3
	move.b	A_DAT_1ACD2, d3
	move.w	#$40ff, d2
	move.w	#$f, s_01a488
	bsr.w	f_014db2
	bra.w	f_0103ae
