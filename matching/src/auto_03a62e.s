f_03a62e:
	link.w	a6, #$0
	movem.l	d0-d7/a0-a6, -(a7)
	movea.l	$a(a6), a0
	move.w	$8(a6), d0
	lea.l	s_03ae8c, a6
	sf.b	$1a(a6)
	lsl.w	#$1, d0
	move.w	(a0, d0.w), d0
	lea.l	(a0, d0.w), a0
	move.l	a0, $c(a6)
	movea.l	a0, a1
	move.w	(a0)+, d0
	move.b	d0, $1b(a6)
	move.b	d0, $1c(a6)
	move.w	(a0)+, d0
	lea.l	(a1, d0.w), a2
	move.l	a2, $4(a6)
	move.w	(a0)+, d0
	lea.l	(a1, d0.w), a2
	move.l	a2, $8(a6)
	move.w	(a0)+, d0
	lea.l	(a1, d0.w), a3
	lea.l	s_03afbc, a2
	move.l	a3, $0(a2)
	move.w	(a0)+, d0
	lea.l	(a1, d0.w), a3
	lea.l	s_03b00c, a2
	move.l	a3, $0(a2)
	move.w	(a0)+, d0
	lea.l	(a1, d0.w), a3
	lea.l	s_03b05c, a2
	move.l	a3, $0(a2)
	move.l	a0, $10(a6)
	move.b	#$000f, $1d(a6)
	move.b	#$003f, s_03b1a2
	move.b	#$003f, s_03b1aa
	move.w	#$2, d3
	lea.l	s_03afbc, a2
l_03a6ca:
	ori.w	#$40, $26(a2)
	move.b	#$000f, $2b(a2)
	move.b	#$000f, $2f(a2)
	adda.w	#$50, a2
	dbra	d3, l_03a6ca
	bsr.w	f_03a85e
	clr.w	$18(a6)
	movem.l	(a7)+, d0-d7/a0-a6
	unlk	a6
	rts	
