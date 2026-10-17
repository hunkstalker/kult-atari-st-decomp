f_012ea2:
	clr.w	d0
	clr.w	d1
	clr.w	d2
	clr.w	d3
	move.b	A_DAT_1AB40, d0
	move.b	A_DAT_1AB42, d1
	move.b	A_DAT_1AB41, d2
	move.b	A_DAT_1AB43, d3
	sub.w	d0, d2
	sub.w	d1, d3
	move.w	#$1, A_ANIM_1A56A
	move.b	#$0011, A_ANIM_1A577
	addq.l	#$1, a6
	bra.w	f_012e2e
	move.w	#$8000, d4
	movem.w	d0-d1, -(a7)
	swap	d7
	bsr.w	f_010fee
	movem.w	(a7)+, d0-d1
	bra.w	f_012ef6
	move.w	#$f000, d4
