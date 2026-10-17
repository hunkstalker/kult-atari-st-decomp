f_016b2e:
	movea.l	#A_SAVE_DESC, a1
	move.l	d3, -(a7)
	adda.l	a5, a1
	movea.l	a3, a2
l_016b3a:
	move.w	d2, d1
	movea.l	a2, a0
	movea.l	a1, a4
l_016b40:
	movem.w	(a4)+, d4-d7
	move.w	d4, d0
	or.w	d5, d0
	or.w	d6, d0
	or.w	d7, d0
	not.w	d0
	and.w	d0, (a0)
	or.w	d4, (a0)+
	and.w	d0, (a0)
	or.w	d5, (a0)+
	and.w	d0, (a0)
	or.w	d6, (a0)+
	and.w	d0, (a0)
	or.w	d7, (a0)+
	dbra	d1, l_016b40
	adda.l	#$a0, a2
	adda.l	#$40, a1
	dbra	d3, l_016b3a
	move.l	(a7)+, d3
	rts	
