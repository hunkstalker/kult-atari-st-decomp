f_016dec:
	bsr.w	f_01285a
	clr.w	d1
	clr.w	d4
	move.b	$1(a6), d2
	move.b	$3(a6), d4
	move.b	$2(a6), d1
	cmpi.b	#$00ff, d1
	bne.w	l_016e0e
	move.b	A_ELEM_1AB4C, d1
l_016e0e:
	cmpi.b	#$00fe, d1
	bne.w	l_016e1c
	move.b	A_ELEM_1AB4D, d1
l_016e1c:
	bsr.w	f_018e12
	subq.w	#$1, d1
	move.l	a6, -(a7)
	movea.l	#s_01a2ac, a6
	move.b	d2, $2(a6)
	move.w	d4, s_01aa6e
	movea.l	#s_0246e6, a4
	bsr.w	f_012950
l_016e3e:
	movea.l	#s_01a2ac, a6
	move.b	(a5)+, $1(a6)
	movem.l	a4-a5, -(a7)
	clr.w	d1
	move.b	$1(a6), d1
	subq.w	#$1, d1
	bsr.w	f_0129c8
	movem.l	(a7)+, a4-a5
	cmpi.b	#$00ff, (a5)
	bne.w	l_016e72
	addq.l	#$1, a5
	move.l	a4, -(a7)
	movea.l	a5, a4
	addq.l	#$3, a4
	bsr.w	f_0129d6
	movea.l	(a7)+, a4
l_016e72:
	addq.l	#$4, a1
	movem.l	a4-a5, -(a7)
	move.l	a1, -(a7)
	clr.w	d0
	move.b	$2(a6), d0
	bsr.w	f_0120dc
	movea.l	(a7)+, a1
	bsr.w	f_0124da
	movem.l	(a7)+, a4-a5
	clr.l	d1
	move.w	s_01aa6e, d1
	beq.w	l_016ecc
	cmpi.b	#$0025, -$1(a5)
	bne.w	l_016ec2
	movem.l	d1-d7/a0-a5, -(a7)
	tst.b	s_01ad03
	beq.w	l_016eb8
	bsr.w	f_016250
	bra.b	l_016ebc
l_016eb8:
	bsr.w	f_018a30
l_016ebc:
	movem.l	(a7)+, d1-d7/a0-a5
	bra.b	l_016ecc
l_016ec2:
	swap	d1
	lsr.l	#$4, d1
l_016ec6:
	subq.l	#$1, d1
	bne.w	l_016ec6
l_016ecc:
	cmpa.l	a5, a4
	bne.w	l_016e3e
	movea.l	(a7)+, a6
	addq.l	#$4, a6
	rts	
