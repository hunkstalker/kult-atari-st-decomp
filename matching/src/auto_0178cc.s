f_0178cc:
	addq.l	#$1, a6
	clr.l	d0
	movea.l	s_01a812, a0
	move.b	$4(a0), d0
	beq.w	l_017924
	clr.b	$4(a0)
	subq.w	#$1, d0
	mulu.w	#$6, d0
	movea.l	#A_LIST_1A8F0, a2
	adda.l	d0, a2
	move.l	a2, A_DAT_1A75E
	addq.b	#$1, s_01ad01
	lea.l	s_01ad33, a1
	clr.l	d0
	move.b	$3(a0), d0
	lsr.l	#$6, d0
	adda.l	d0, a1
	move.b	$3(a2), (a1)
	move.l	a6, -(a7)
	bsr.w	f_0184cc
	movea.l	(a7)+, a6
	move.w	#$90aa, A_THE_COMMAND
	bra.w	f_0103ae
l_017924:
	move.w	#$9140, A_THE_COMMAND
	bra.w	f_0103ae
