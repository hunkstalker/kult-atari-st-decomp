f_0127fa:
	movem.l	d2-d3/d7/a0-a1, -(a7)
	move.l	a0, A_DAT_1A4B2
	move.w	d3, A_SAVE_1A4A4
	movea.l	a0, a1
	movea.l	#A_SAVE_DESC, a0
	move.w	#$626, d6
l_012816:
	clr.l	(a0)+
	dbra	d6, l_012816
	movea.l	#A_SAVE_DESC, a0
	bsr.w	f_012698
	move.w	d1, A_DAT_1A49E
	move.w	d5, A_ANIM_1A4A0
	move.w	d4, A_SAVE_1A4A2
	move.w	d3, d7
	subq.w	#$1, d7
l_01283c:
	movea.l	a1, a3
	bsr.w	f_0123c0
	movea.l	a3, a1
	adda.l	#$40, a0
	adda.l	#$a0, a1
	dbra	d7, l_01283c
	movem.l	(a7)+, d2-d3/d7/a0-a1
	rts	
