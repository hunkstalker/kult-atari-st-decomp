f_012b04:
	adda.l	d2, a0
	adda.l	d2, a0
	subq.w	#$1, d2
	subq.w	#$1, d3
l_012b0c:
	movea.l	a0, a2
	move.w	d2, d4
l_012b10:
	move.b	(a1)+, d1
	bsr.w	f_012b40
	move.b	d6, d5
	move.b	(a1)+, d1
	bsr.w	f_012b40
	move.b	d5, d0
	move.b	d6, d1
	or.b	d1, d0
	move.b	d0, d1
	ror.b	#$4, d1
	or.b	d1, d0
	not.b	d0
	and.b	d0, -(a2)
	or.b	d6, (a2)
	and.b	d0, -(a2)
	or.b	d5, (a2)
	dbra	d4, l_012b10
	adda.l	a3, a0
	dbra	d3, l_012b0c
	rts	
