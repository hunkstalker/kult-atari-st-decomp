f_01857c:
	movea.l	#A_LIST_1A8F0, a0
	move.w	#$3e, d0
	move.w	#$ad, d4
	move.b	A_DAT_1ACD2, d1
l_018590:
	cmpi.b	#$0040, (a0)
	bne.w	l_0185a0
	cmp.b	$1(a0), d1
	beq.w	l_0185a8
l_0185a0:
	addq.l	#$6, a0
	dbra	d0, l_018590
	subq.w	#$1, d4
l_0185a8:
	move.w	#$4a, d0
	move.w	#$e, d1
	movem.l	d0-d1/d4, -(a7)
	bsr.w	f_011020
	movem.l	(a7)+, d0-d1/d4
	bsr.w	f_011016
	movea.l	#s_01a9d4, a0
	move.w	#$d, d0
	clr.b	A_DAT_1ACF7
l_0185d0:
	cmpi.b	#$0080, (a0)
	bne.w	l_0185de
	addq.b	#$1, A_DAT_1ACF7
l_0185de:
	addq.l	#$6, a0
	dbra	d0, l_0185d0
	rts	
