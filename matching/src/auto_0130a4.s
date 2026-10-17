f_0130a4:
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
l_0130d0:
	move.w	(a0), d0
	move.w	(a1), d2
	btst.l	d1, d2
	beq.w	l_0130e0
	bset.b	d1, d0
	bra.w	l_0130e2
l_0130e0:
	bclr.b	d1, d0
l_0130e2:
	move.w	d0, (a0)
	move.w	$2(a0), d0
	move.w	$2(a1), d2
	btst.l	d1, d2
	beq.w	l_0130f8
	bset.b	d1, d0
	bra.w	l_0130fa
l_0130f8:
	bclr.b	d1, d0
l_0130fa:
	move.w	d0, $2(a0)
	move.w	$4(a0), d0
	move.w	$4(a1), d2
	btst.l	d1, d2
	beq.w	l_013112
	bset.b	d1, d0
	bra.w	l_013114
l_013112:
	bclr.b	d1, d0
l_013114:
	move.w	d0, $4(a0)
	move.w	$6(a0), d0
	move.w	$6(a1), d2
	btst.l	d1, d2
	beq.w	l_01312c
	bset.b	d1, d0
	bra.w	l_01312e
l_01312c:
	bclr.b	d1, d0
l_01312e:
	move.w	d0, $6(a0)
	tst.w	d1
	beq.w	l_013144
	subi.w	#$1, d1
	dbra	d3, l_0130d0
	bra.w	l_013158
l_013144:
	adda.l	#$8, a0
	adda.l	#$8, a1
	move.w	#$f, d1
	dbra	d3, l_0130d0
l_013158:
	swap	d6
	swap	d7
	movem.w	(a7)+, d0-d3
	rts	
