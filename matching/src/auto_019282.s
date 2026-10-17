f_019282:
	move.w	sr, -(a7)
	moveq	#$d, d0
	moveq	#$0, d1
l_019288:
	bsr.b	f_01929a
	dbra	d0, l_019288
	moveq	#$18, d1
	moveq	#$7, d0
	bsr.w	f_01929a
	move.w	(a7)+, sr
	rts	
