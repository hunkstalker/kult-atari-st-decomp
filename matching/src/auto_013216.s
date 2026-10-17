f_013216:
	clr.l	A_SCREEN_DRAW_BASE
l_01321c:
	swap	d6
	swap	d7
	move.w	d0, d6
	move.w	d1, -(a7)
	bsr.w	f_010fee
	suba.l	A_SCREEN_DRAW_BASE, a0
	move.w	d7, d0
	move.w	#$f, d1
	subi.w	#$1, d3
	sub.w	d0, d1
l_01323a:
	move.w	(a0), d0
	btst.b	#$0, d2
	beq.w	l_01324a
	bset.b	d1, d0
	bra.w	l_01324c
l_01324a:
	bclr.b	d1, d0
l_01324c:
	move.w	d0, (a0)
	move.w	$2(a0), d0
	btst.b	#$1, d2
	beq.w	l_013260
	bset.b	d1, d0
	bra.w	l_013262
l_013260:
	bclr.b	d1, d0
l_013262:
	move.w	d0, $2(a0)
	move.w	$4(a0), d0
	btst.b	#$2, d2
	beq.w	l_013278
	bset.b	d1, d0
	bra.w	l_01327a
l_013278:
	bclr.b	d1, d0
l_01327a:
	move.w	d0, $4(a0)
	move.w	$6(a0), d0
	btst.b	#$3, d2
	beq.w	l_013290
	bset.b	d1, d0
	bra.w	l_013292
l_013290:
	bclr.b	d1, d0
l_013292:
	move.w	d0, $6(a0)
	adda.l	#$a0, a0
	dbra	d3, l_01323a
	move.w	d6, d0
	move.w	(a7)+, d1
	swap	d6
	swap	d7
	rts	
