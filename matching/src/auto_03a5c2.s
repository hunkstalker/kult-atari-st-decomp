f_03a5c2:
	movem.l	d0-d7/a0-a6, -(a7)
	pea.l	f_03a604
	move.w	#$26, -(a7)
	trap	#$e
	lea.l	$6(a7), a7
	pea.l	f_03aa38
	move.w	#$23, -(a7)
	move.w	#$5, -(a7)
	trap	#$d
	lea.l	$8(a7), a7
	pea.l	f_03aab6
	move.w	#$24, -(a7)
	move.w	#$5, -(a7)
	trap	#$d
	lea.l	$8(a7), a7
	movem.l	(a7)+, d0-d7/a0-a6
	rts	
