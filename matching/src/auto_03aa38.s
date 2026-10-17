f_03aa38:
	move.w	#$2700, sr
	move.l	d0, -(a7)
	lea.l	$ff8800.l, a5
	btst.b	#$f, d2
	bne.w	l_03aa68
	move.l	d2, d6
	add.b	d7, d6
	cmpi.b	#$0007, d2
	bne.w	l_03aa76
	move.b	d6, (a5)
	move.b	(a5), d5
	andi.b	#$003f, d0
	andi.b	#$00c0, d5
	or.b	d5, d0
	bra.b	l_03aa76
l_03aa68:
	move.l	d7, d6
	lsl.w	#$1, d6
	add.b	d2, d6
	bsr.b	f_03aa7c
	lsr.w	#$8, d0
	addq.w	#$1, d6
	move.b	d6, (a5)
l_03aa76:
	bsr.b	f_03aa7c
	move.l	(a7)+, d0
	rte	
