f_03a6f4:
	movem.l	d0-d7/a0-a6, -(a7)
	pea.l	f_03a712
	move.w	#$26, -(a7)
	trap	#$e
	lea.l	$6(a7), a7
	bsr.w	f_03a85e
	movem.l	(a7)+, d0-d7/a0-a6
	rts	
