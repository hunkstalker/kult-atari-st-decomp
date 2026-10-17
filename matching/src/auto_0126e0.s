f_0126e0:
	movem.l	d3/d7/a0-a1, -(a7)
	movea.l	A_DAT_1A534, a3
	movea.l	#A_SAVE_DESC, a0
	move.w	#$626, d6
	clr.l	d5
l_0126f6:
	move.l	d5, (a0)+
	dbra	d6, l_0126f6
	bsr.w	f_012698
	movea.l	#A_SAVE_DESC, a0
	subq.w	#$1, d2
	subq.w	#$1, d3
l_01270a:
	move.w	#$f000, d4
	ror.w	d7, d4
	move.w	d3, d5
	swap	d2
	movea.l	a0, a2
	movea.l	a1, a4
l_012718:
	move.w	(a1), d2
	ror.w	d7, d2
	move.w	d2, d0
	and.w	d4, d0
	or.w	d0, (a0)+
	rol.w	#$4, d2
	move.w	d2, d0
	and.w	d4, d0
	or.w	d0, (a0)+
	rol.w	#$4, d2
	move.w	d2, d0
	and.w	d4, d0
	or.w	d0, (a0)+
	rol.w	#$4, d2
	move.w	d2, d0
	and.w	d4, d0
	or.w	d0, (a0)+
	adda.l	#$38, a0
	adda.l	a3, a1
	dbra	d5, l_012718
	movea.l	a2, a0
	movea.l	a4, a1
	adda.l	#$2, a1
	addq.w	#$4, d7
	andi.w	#$f, d7
	bne.w	l_012760
	adda.l	#$8, a0
l_012760:
	swap	d2
	dbra	d2, l_01270a
	movem.l	(a7)+, d3/d7/a0-a1
	rts	
