f_0149da:
	cmpi.b	#$003f, A_DAT_1ACEC
	bcc.w	f_010768
	movea.l	A_SCRIPT_END, a5
	movem.l	a5-a6, -(a7)
	move.w	#$ff00, d2
	move.w	#$8000, d3
	move.w	#$f0ff, s_01a488
	bsr.w	f_014db2
	move.b	#$0001, d0
	tst.w	s_01a510
	beq.w	l_014a84
	addq.b	#$1, d0
	tst.w	A_THE_COMMAND
	beq.w	l_014a84
	addq.b	#$1, d0
	cmpi.b	#$0006, A_DAT_1ACE9
	bcs.w	l_014a84
	cmpi.b	#$001b, A_DAT_1ACE9
	bcc.w	l_014a84
	move.w	#$c204, A_THE_COMMAND
	bsr.w	f_0103ae
	movea.l	A_DAT_1A75E, a0
	clr.b	(a0)
	move.w	#$ff00, d2
	move.w	#$1000, d3
	bsr.w	f_014db2
	move.w	#$4, d0
	tst.w	A_THE_COMMAND
	beq.w	l_014a84
	addq.b	#$1, d0
	cmpi.b	#$0080, A_DAT_1ACD7
	bcc.w	l_014a84
	addq.b	#$1, d0
	movea.l	A_DAT_1A75E, a0
	move.b	#$0010, -$6(a0)
	clr.b	(a0)
l_014a84:
	move.b	d0, s_01ad0e
	movem.l	(a7)+, a5-a6
	move.l	a5, A_SCRIPT_END
	addq.l	#$1, a6
	rts	
