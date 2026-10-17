f_018e12:
	tst.w	A_DAT_1A484
	beq.w	l_018f6c
	movem.l	d0-d7/a0-a6, -(a7)
	lea.l	s_019994, a0
	andi.l	#$ff, d1
	subq.b	#$1, d1
	move.b	(a0, d1.l), d1
	beq.w	l_018f68
	move.b	#$0007, d2
	move.b	#$0000, d3
	move.b	#$0029, d4
	subq.b	#$1, d1
	beq.w	l_018eb0
	move.b	#$0005, d3
	subq.b	#$1, d1
	beq.w	l_018eb0
	move.b	#$000a, d3
	move.b	#$0023, d4
	move.b	#$0003, d2
	subq.b	#$1, d1
	beq.w	l_018eb0
	move.b	#$000e, d3
	move.b	#$001d, d4
	subq.b	#$1, d1
	beq.w	l_018eb0
	move.b	#$0005, d3
	move.b	#$0007, d2
	subq.b	#$1, d1
	beq.w	l_018eb0
	move.b	#$0003, d2
	move.b	#$000a, d3
	move.b	#$0029, d4
	subq.b	#$1, d1
	beq.w	l_018eb0
	move.b	#$0007, d2
	move.b	#$0000, d3
	move.b	#$003d, d4
	subq.b	#$1, d1
	beq.w	l_018eb0
	move.b	#$0003, d2
	move.b	#$000e, d3
	move.b	#$0018, d4
l_018eb0:
	lea.l	A_DAT_1D402, a0
	clr.l	d0
	move.w	A_DAT_1A484, d0
	adda.l	d0, a0
	lea.l	A_SAVE_DESC, a1
	move.w	#$9, d7
l_018eca:
	move.b	(a0)+, d0
	andi.b	#$0007, d0
	and.b	d2, d0
	btst.b	#$2, d0
	beq.w	l_018ede
	andi.b	#$0004, d0
l_018ede:
	add.b	d3, d0
	cmp.b	-$2(a1), d0
	beq.w	l_018eca
	move.b	d0, (a1)+
	move.b	d4, (a1)+
	dbra	d7, l_018eca
	addq.b	#$4, -$1(a1)
	addq.b	#$2, -$3(a1)
	lea.l	s_00d8f2, a3
	move.l	#s_055b0a, s_0192be
	move.w	#$8, d7
