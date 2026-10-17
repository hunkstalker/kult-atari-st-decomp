f_016514:
	move.w	#$f, d0
	movea.l	#A_ICON_TBL, a2
l_01651e:
	move.l	d0, -(a7)
	bsr.w	f_01652e
	move.l	(a7)+, d0
	addq.l	#$4, a2
	dbra	d0, l_01651e
	rts	
