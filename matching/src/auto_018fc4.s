f_018fc4:
	clr.b	d1
l_018fc6:
	movea.l	#s_055b0a, a1
	btst.b	#$7, d4
	beq.w	l_01900a
	clr.l	d0
	move.b	d4, d0
	andi.b	#$000f, d4
	andi.b	#$0070, d0
	lsr.b	#$2, d0
	lea.l	s_1a4e8, a1
	movea.l	(a1, d0.l), a1
	lsr.b	#$2, d0
	cmpi.b	#$00ff, s_1a57c
	beq.w	l_01900a
	move.l	d4, -(a7)
	jsr	f_01066e
	move.l	(a7)+, d4
	lea.l	s_064c8e, a1
l_01900a:
	jsr	f_010f8e
	move.l	a2, s_0192ca
	move.b	(a1)+, s_0192ce
	lea.l	$fffffa00.l, a0
	clr.b	$19(a0)
	move.b	#$0020, $13(a0)
	move.b	#$0020, $7(a0)
	move.b	#$0002, $19(a0)
	tst.b	d1
	beq.w	l_019040
	move.b	d1, (a1)
l_019040:
	move.b	(a1)+, $1f(a0)
	move.l	a1, s_0192c6
	move.l	a1, s_0192c2
	move.l	#s_01910e, $134.l
	rts	
	bsr.w	f_018fc4
l_019060:
	tst.b	$fa19.w
	bne.w	l_019060
	rts	
