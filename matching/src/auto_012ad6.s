f_012ad6:
	subq.w	#$1, d2
	subq.w	#$1, d3
l_012ada:
	movea.l	a0, a2
	move.w	d2, d4
l_012ade:
	move.b	(a1)+, d0
	move.b	(a1)+, d1
	move.b	d0, d5
	move.b	d1, d6
	or.b	d1, d0
	move.b	d0, d1
	ror.b	#$4, d1
	or.b	d1, d0
	not.b	d0
	and.b	d0, (a2)
	or.b	d5, (a2)+
	and.b	d0, (a2)
	or.b	d6, (a2)+
	dbra	d4, l_012ade
	adda.l	a3, a0
	dbra	d3, l_012ada
	rts	
