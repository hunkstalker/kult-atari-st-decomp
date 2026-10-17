f_012ce4:
	move.w	#$1d, d4
	bsr.w	f_018f8e
	addq.l	#$1, a6
	move.l	a6, -(a7)
	move.b	s_01acca, d0
	addq.b	#$1, d0
	andi.b	#$0003, d0
	move.b	d0, s_01acca
	beq.w	l_012c6e
	cmpi.b	#$0001, d0
	beq.w	l_012b66
	cmpi.b	#$0002, d0
	beq.w	l_012c08
	move.b	#$0009, d1
	cmpi.b	#$005f, A_MODE_FLAG
	beq.w	l_012d2a
	move.b	#$0066, d1
l_012d2a:
	move.b	d1, A_MODE_FLAG
	bsr.w	f_014496
	move.l	#$28, A_DAT_1A534
	move.w	#$24, d0
	move.w	#$20, d1
	bsr.w	f_010fec
	move.w	d7, d0
	move.w	#$14, d2
	move.w	#$9, d1
	move.w	#$3b, d3
	bsr.w	f_0117de
	movea.l	#s_1a84e, a2
	movem.l	d0/d2/a0-a1, -(a2)
	move.w	#$10, d0
	move.w	#$20, d1
	bsr.w	f_010fec
	move.w	d7, d0
	move.w	#$14, d2
	move.w	#$9, d1
	move.w	#$3b, d3
	bsr.w	f_011ada
	movea.l	#s_01a83e, a2
	movem.l	d0/d2/a0-a1, -(a2)
	movea.l	(a7)+, a6
	bsr.w	f_018fa4
	rts	
