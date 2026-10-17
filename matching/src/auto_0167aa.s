f_0167aa:
	clr.l	d0
	move.b	$1(a6), d0
	bsr.w	f_014a98
	move.b	$2(a6), d2
	move.b	$3(a6), d3
	addq.l	#$4, a6
