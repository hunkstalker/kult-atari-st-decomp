f_014ee8:
	movea.l	#A_DAT_1AB62, a0
	clr.l	d0
	move.b	A_SEL_1ACC9, d0
	subq.b	#$1, d0
	mulu.w	#$a, d0
	clr.l	d1
	move.b	$1(a6), d1
	lsl.l	#$1, d1
	add.l	d1, d0
	move.w	(a0, d0.l), A_THE_COMMAND
	bne.w	f_0103ae
	movea.l	#A_DAT_1AB50, a0
	adda.l	d1, a0
	move.w	(a0), A_THE_COMMAND
	bra.w	f_0103ae
