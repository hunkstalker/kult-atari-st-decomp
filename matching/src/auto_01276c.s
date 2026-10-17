f_01276c:
	movem.l	d3/d7/a0, -(a7)
	subq.w	#$1, d2
	subq.w	#$1, d3
l_012774:
	move.w	#$fff, d1
	ror.w	d7, d1
	move.w	d1, d4
	not.w	d4
	move.w	d3, d5
	swap	d2
	movea.l	a0, a2
l_012784:
	move.w	d6, d2
	ror.w	d7, d2
	and.w	d1, (a0)
	move.w	d2, d0
	and.w	d4, d0
	or.w	d0, (a0)+
	rol.w	#$4, d2
	and.w	d1, (a0)
	move.w	d2, d0
	and.w	d4, d0
	or.w	d0, (a0)+
	rol.w	#$4, d2
	and.w	d1, (a0)
	move.w	d2, d0
	and.w	d4, d0
	or.w	d0, (a0)+
	rol.w	#$4, d2
	and.w	d1, (a0)
	move.w	d2, d0
	and.w	d4, d0
	or.w	d0, (a0)+
	adda.l	#$98, a0
	dbra	d5, l_012784
	movea.l	a2, a0
	adda.l	#$2, a1
	addq.w	#$4, d7
	andi.w	#$f, d7
	bne.w	l_0127d0
	adda.l	#$8, a0
l_0127d0:
	swap	d2
	dbra	d2, l_012774
	bsr.w	f_013594
	movem.l	(a7)+, d3/d7/a0
	rts	
