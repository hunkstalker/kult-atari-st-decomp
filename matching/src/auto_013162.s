f_013162:
	movem.w	d0-d3, -(a7)
	swap	d6
	swap	d7
	movea.l	#$0, a0
	bsr.w	f_010ff4
	move.w	d7, d0
	movea.l	a0, a1
	adda.l	A_SCREEN_PTR_A, a0
	adda.l	A_SCREEN_PTR_B, a1
	move.w	#$f, d1
	subi.w	#$1, d3
	sub.w	d0, d1
l_01318e:
	move.w	(a0), d0
	move.w	(a1), d2
	btst.l	d1, d2
	beq.w	l_01319e
	bset.b	d1, d0
	bra.w	l_0131a0
l_01319e:
	bclr.b	d1, d0
l_0131a0:
	move.w	d0, (a0)
	move.w	$2(a0), d0
	move.w	$2(a1), d2
	btst.l	d1, d2
	beq.w	l_0131b6
	bset.b	d1, d0
	bra.w	l_0131b8
l_0131b6:
	bclr.b	d1, d0
l_0131b8:
	move.w	d0, $2(a0)
	move.w	$4(a0), d0
	move.w	$4(a1), d2
	btst.l	d1, d2
	beq.w	l_0131d0
	bset.b	d1, d0
	bra.w	l_0131d2
l_0131d0:
	bclr.b	d1, d0
l_0131d2:
	move.w	d0, $4(a0)
	move.w	$6(a0), d0
	move.w	$6(a1), d2
	btst.l	d1, d2
	beq.w	l_0131ea
	bset.b	d1, d0
	bra.w	l_0131ec
l_0131ea:
	bclr.b	d1, d0
l_0131ec:
	move.w	d0, $6(a0)
	adda.l	#$a0, a0
	adda.l	#$a0, a1
	dbra	d3, l_01318e
	swap	d6
	swap	d7
	movem.w	(a7)+, d0-d3
	rts	
