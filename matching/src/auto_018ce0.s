f_018ce0:
	cmpi.b	#$0080, (a0)
	bne.w	l_018cf4
	move.b	#$0040, (a0)
	move.b	A_DAT_1ACD2, $1(a0)
l_018cf4:
	addq.l	#$6, a0
	dbra	d0, f_018ce0
	rts	
