f_03adb4:
	movea.l	$8(a3), a0
	move.b	(a0)+, d0
	move.l	a0, $8(a3)
	movea.l	$8(a6), a0
	andi.w	#$ff, d0
	mulu.w	#$d, d0
	lea.l	(a0, d0.w), a0
	movea.l	$14(a3), a2
	move.b	(a0)+, d0
	move.b	#$0080, $b(a2)
	clr.b	$8(a2)
	clr.b	$a(a2)
	clr.w	$2(a2)
	clr.w	$0(a2)
	clr.b	$d(a2)
	clr.b	$c(a2)
	bset.b	#$0, $b(a2)
	move.l	a0, $4(a2)
	bra.w	l_03ab3a
