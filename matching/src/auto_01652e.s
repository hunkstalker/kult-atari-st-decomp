f_01652e:
	tst.l	(a2)
	beq.w	l_016552
	clr.w	d2
	clr.w	d3
	movea.l	(a2), a1
	move.b	(a1)+, d2
	move.b	(a1)+, d3
	movea.l	(a1)+, a0
	move.w	(a1)+, d7
	movea.l	(a1)+, a3
	adda.l	#$8000, a0
	move.l	a2, -(a7)
	bsr.w	f_012190
	movea.l	(a7)+, a2
l_016552:
	rts	
