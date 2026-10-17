f_018f0c:
	move.b	#$0001, s_0192cf
	lea.l	s_0192d2, a0
	move.l	a0, s_01930e
l_018f20:
	clr.w	d4
	move.b	(a3), d4
	move.b	$1(a3), $1(a0)
	lea.l	s_055b0a, a1
	jsr	f_010f8e
	move.l	a1, d0
	sub.l	s_0192be, d0
	addq.l	#$2, d0
	move.w	d0, $2(a0)
	move.l	a2, d0
	sub.l	s_0192be, d0
	move.w	d0, $4(a0)
	addq.l	#$2, a3
	addq.l	#$6, a0
	dbra	d7, l_018f20
	clr.w	d4
	lea.l	A_SAVE_DESC, a0
	move.b	(a0)+, d4
	move.b	(a0)+, d1
	bsr.w	f_018f7a
l_018f68:
	movem.l	(a7)+, d0-d7/a0-a6
l_018f6c:
	rts	
