f_018a10:
	bsr.w	f_016210
	clr.w	d4
	move.b	d0, d4
	lsr.b	#$3, d4
	andi.b	#$0003, d4
	addi.b	#$0090, d4
	move.b	d0, d1
	andi.b	#$0007, d1
	addi.b	#$0023, d1
	bra.w	f_018f7a
