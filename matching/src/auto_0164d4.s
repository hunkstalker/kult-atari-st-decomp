f_0164d4:
	move.b	A_DAT_1ACC7, d0
	cmpi.b	#$0029, d0
	beq.w	f_0121b6
	cmpi.b	#$0016, d0
	bcs.w	f_010768
	cmpi.b	#$0019, d0
	bcc.w	f_010768
	bra.w	f_0121b6
