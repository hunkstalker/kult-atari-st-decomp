f_018fa4:
	movem.l	a0-a2, -(a7)
	pea.l	$da(pc)
l_018fac:
	move.w	#$26, -(a7)
	tst.b	A_FRAME_1AB4F
	bne.w	l_018fbc
	trap	#$e
l_018fbc:
	addq.w	#$6, a7
	movem.l	(a7)+, a0-a2
	rts	
