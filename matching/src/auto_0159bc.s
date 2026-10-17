f_0159bc:
	movea.l	a2, a0
l_0159be:
	move.l	(a1)+, (a0)+
	move.l	(a1)+, (a0)+
	move.l	(a1)+, (a0)+
	move.l	(a1)+, (a0)+
	adda.l	#$90, a0
	dbra	d3, l_0159be
	rts	
