f_010630:
	clr.l	d0
	move.b	(a6),d0
	cmpa.l	A_SCRIPT_END,a6
	beq.w	l_010666
	cmpi.b	#$6b,d0
	bcc.w	l_010666
	cmpi.b	#0,d0
	beq.w	l_010666
	clr.l	d0
	move.b	(a6),d0
	subq.b	#1,d0
	lsl.w	#2,d0
	movea.l	#byte_handler_table,a1
	movea.l	(a1,d0.l),a1
	jsr	(a1)
	bra.w	f_010630
l_010666:
	rts
f_010668:
	addq.l	#2,a6
	move.b	-1(a6),d0
f_01066e:
	movem.l	d0-d1/a0/a5,-(a7)
	move.l	#RAM54C8E,d1
	bsr.w	f_010682
	movem.l	(a7)+,d0-d1/a0/a5
	rts
