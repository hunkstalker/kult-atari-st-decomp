f_016556:
	move.w	#$f, d0
	movea.l	#A_ICON_TBL, a2
l_016560:
	move.l	d0, -(a7)
	movea.l	(a2), a1
	move.l	a2, -(a7)
	bsr.w	f_0124f8
	movea.l	(a7)+, a2
	move.l	(a7)+, d0
	addq.l	#$4, a2
	dbra	d0, l_016560
	rts	
