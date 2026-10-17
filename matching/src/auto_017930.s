f_017930:
	addq.l	#$2, a6
	move.l	a6, -(a7)
	tst.b	-$1(a6)
	beq.w	l_017944
	movea.l	A_DAT_1A75E, a1
	bra.b	l_01795e
l_017944:
	movea.l	s_01a812, a0
	clr.l	d3
	move.b	$4(a0), d3
	subq.b	#$1, d3
	mulu.w	#$6, d3
	movea.l	#A_LIST_1A8F0, a1
	adda.l	d3, a1
l_01795e:
	movea.l	#s_019978, a6
	move.w	s_01a858, d0
	move.w	s_01a85a, d1
	addi.b	#$0046, d1
	move.b	d0, $3(a6)
	move.b	d1, $4(a6)
	move.b	$3(a1), d2
	addi.b	#$0012, d2
	move.b	d2, $2(a6)
	movem.l	d0-d1/a1, -(a7)
	bsr.w	f_010dfa
	movem.l	(a7)+, d0-d1/a1
	clr.w	d4
	addq.w	#$1, d1
	move.b	$2(a1), d4
	movea.l	(a7)+, a6
	bra.w	f_011020
