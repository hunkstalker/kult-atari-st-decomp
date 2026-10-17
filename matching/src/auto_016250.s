f_016250:
	bsr.w	f_018a10
	move.w	#$777, -(a7)
	move.w	#$0, -(a7)
	move.w	#$7, -(a7)
	trap	#$e
	addq.l	#$6, a7
	bsr.w	f_013594
	move.w	#$0, -(a7)
	move.w	#$0, -(a7)
	move.w	#$7, -(a7)
	trap	#$e
	addq.l	#$6, a7
	rts	
