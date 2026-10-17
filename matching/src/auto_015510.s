f_015510:
	clr.w	d0
	clr.w	d1
	move.b	(a2), d0
	move.b	$2(a2), d1
	movem.l	d2-d3/d5-d6/a1-a2, -(a7)
	bsr.w	f_011020
	movem.l	(a7)+, d2-d3/d5-d6/a1-a2
	adda.l	#$a, a2
	addq.w	#$1, d6
	rts	
