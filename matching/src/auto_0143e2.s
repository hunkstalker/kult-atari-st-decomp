f_0143e2:
	movea.l	#s_00d8f2, a6
	move.w	#$2, d6
l_0143ec:
	move.l	d6, -(a7)
	move.w	(a6)+, d2
	move.w	(a6)+, d3
	movea.l	(a6)+, a1
	movea.l	(a6)+, a0
	move.w	(a6)+, d7
	clr.l	d5
	move.w	d2, d5
	lsl.l	#$1, d5
	movea.l	d5, a3
	tst.w	A_SAVE_DESC
	bne.w	l_014410
	bsr.w	f_011050
	bra.b	l_014414
l_014410:
	bsr.w	f_011102
l_014414:
	bsr.w	f_013594
	move.l	(a7)+, d6
	dbra	d6, l_0143ec
	move.w	(a6)+, d2
	move.w	(a6)+, d3
	movea.l	(a6)+, a0
	move.w	(a6)+, d7
	bsr.w	f_01215e
	rts	
