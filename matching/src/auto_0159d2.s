f_0159d2:
	clr.l	d1
	move.b	$1(a6), d1
	addq.l	#$2, a6
	clr.w	d0
	clr.w	d2
	move.b	(a6)+, d0
	move.b	(a6)+, d2
