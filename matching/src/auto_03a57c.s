f_03a57c:
	move.w	(a0)+, d3
	beq.w	l_03a596
	cmp.w	d3, d1
	beq.w	l_03a590
	lea.l	$4(a0), a0
	bra.w	f_03a57c
l_03a590:
	movea.l	(a0), a0
	move.l	a0, -(a7)
	rts	
l_03a596:
	ori.b	#$0001, ccr
	rts	
	move.b	d5, $1c(a6)
	move.b	d5, $1b(a6)
	andi.b	#$00fe, ccr
	rts	
	andi.b	#$000f, d5
	move.b	d5, $1d(a6)
	dc.b	$02,$3c,$ff,$fe,$4e,$75,$1d,$45,$00,$1e,$02,$3c,$ff,$fe,$4e,$75
