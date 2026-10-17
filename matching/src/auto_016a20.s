f_016a20:
	move.b	#$0001, s_01ad30
	move.l	a6, -(a7)
	move.w	#$0, d0
	bsr.w	f_01066e
	lea.l	s_01998a, a3
	lea.l	A_SAVE_DESC, a2
	move.w	(a3)+, (a2)
	move.w	#$2, d7
	move.w	#$0, s_0192e4
	move.l	#s_064c8e, s_0192be
	bsr.w	f_016ab6
	move.w	#$a, d6
l_016a5e:
	move.l	d6, -(a7)
	lea.l	s_01997e, a6
	bsr.w	f_014138
	bsr.w	f_013594
	bsr.w	f_0121c6
	move.w	#$ffff, d0
l_016a76:
	dbra	d0, l_016a76
	movea.l	#s_019981, a6
	bsr.w	f_014138
	bsr.w	f_013594
	bsr.w	f_0121c6
	move.w	#$ffff, d0
l_016a90:
	dbra	d0, l_016a90
	move.l	(a7)+, d6
	dbra	d6, l_016a5e
	movea.l	#s_019984, a6
	bsr.w	f_014138
	addq.l	#$3, a6
	bsr.w	f_014138
	bsr.w	f_0121c6
	bsr.w	f_018fa4
	movea.l	(a7)+, a6
	rts	
