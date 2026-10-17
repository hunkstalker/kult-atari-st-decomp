f_03ad5a:
	movea.l	$8(a3), a0
	move.b	(a0)+, $2a(a3)
	move.l	a0, $8(a3)
	bra.w	l_03ab3a
