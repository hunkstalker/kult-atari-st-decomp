f_0164f6:
	clr.w	d1
	move.b	A_DAT_1ACC7, d1
	cmpi.b	#$0016, d1
	bcs.w	f_010768
	cmpi.b	#$0019, d1
	bcc.w	f_010768
	bra.w	f_013f56
