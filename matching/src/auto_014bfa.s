f_014bfa:
	movea.l	A_SCRIPT_END, a5
	movem.l	a5-a6, -(a7)
	move.w	#$9099, A_THE_COMMAND
	bsr.w	f_0103ae
l_014c10:
	move.w	#$fe00, d2
	move.w	#$8000, d3
	move.w	#$f0ff, s_01a488
	bsr.w	f_014db2
	tst.w	s_01a510
	beq.w	l_014cda
	tst.w	A_THE_COMMAND
	beq.w	l_014d5c
	movea.l	s_01a812, a0
	move.w	#$9140, A_THE_COMMAND
	clr.l	d0
	move.b	$4(a0), d0
	beq.w	l_014d58
	subq.b	#$1, d0
	mulu.w	#$6, d0
	movea.l	#A_LIST_1A8F0, a1
	movea.l	A_DAT_1A75E, a2
	adda.l	d0, a1
	cmpi.b	#$0081, (a2)
	beq.w	l_014b7e
	cmpi.b	#$0068, $3(a1)
	beq.w	l_014c94
	cmpi.b	#$007a, $3(a1)
	beq.w	l_014c94
	cmpi.b	#$006b, $3(a1)
	beq.w	l_014c94
	cmpi.b	#$0069, $3(a1)
	bne.w	l_014d58
l_014c94:
	move.b	$3(a2), d1
	cmp.b	$3(a1), d1
	beq.w	l_014cc6
	cmpi.b	#$006d, d1
	beq.w	l_014ce6
	cmpi.b	#$006c, d1
	beq.w	l_014ce6
	cmpi.b	#$0084, d1
	beq.w	l_014ce6
	move.b	A_DAT_1ACD7, d0
	cmpi.b	#$009a, d0
	bcs.w	l_014ce6
l_014cc6:
	move.b	#$0081, (a2)
	move.w	#$c1bd, A_THE_COMMAND
	bsr.w	f_0103ae
	bra.w	l_014c10
l_014cda:
	move.w	#$c1c5, A_THE_COMMAND
	bra.w	l_014d58
l_014ce6:
	clr.b	s_01ad04
	movem.l	a0-a2, -(a7)
	move.w	#$c1c6, A_THE_COMMAND
	bsr.w	f_0103ae
	movem.l	(a7)+, a0-a2
	tst.b	s_01ad04
	beq.w	l_014d5c
	move.b	#$0020, (a2)
	move.b	#$0080, (a1)
	move.b	A_DAT_1ACE9, $4(a0)
	move.w	#$c04b, A_THE_COMMAND
	cmpi.b	#$0084, $3(a2)
	beq.w	l_014d6e
	move.w	#$c1ba, A_THE_COMMAND
	cmpi.b	#$0068, $3(a1)
	beq.w	l_014d58
	move.w	#$c1bb, A_THE_COMMAND
	cmpi.b	#$006b, $3(a1)
	beq.w	l_014d58
	move.w	#$c1b9, A_THE_COMMAND
l_014d58:
	bsr.w	f_0103ae
l_014d5c:
	bsr.w	f_014bdc
	movem.l	(a7)+, a5-a6
	move.l	a5, A_SCRIPT_END
	addq.l	#$1, a6
	rts	
l_014d6e:
	subq.b	#$1, A_DAT_1ACF7
	bra.b	l_014d58
