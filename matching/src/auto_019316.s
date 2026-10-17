f_019316:
	move.l	#f_01935a, -(a7)
	move.w	#$26, -(a7)
	trap	#$e
	addq.w	#$6, a7
	movea.l	#s_00d900, a0
	move.l	#$44, d2
l_019330:
	movea.l	#s_019484, a1
	move.w	#$17, d1
l_01933a:
	cmpm.b	(a0)+, (a1)+
	bne.w	l_019350
	dbra	d1, l_01933a
	dbra	d2, l_019330
	clr.w	s_1947e
	rts	
l_019350:
	move.w	#$ffff, s_1947e
	rts	
