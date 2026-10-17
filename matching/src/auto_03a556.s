f_03a556:
	bsr.w	f_03a5c2
	move.l	#A_ANIM_BACKUP, -(a7)
	move.w	#$0, -(a7)
	bsr.w	f_03a62e
	addq.l	#$6, a7
	move.l	#$a700a7, -(a7)
	move.w	#$0, -(a7)
	bsr.w	f_03a734
	addq.l	#$6, a7
	rts	
