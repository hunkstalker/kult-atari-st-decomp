f_017856:
	move.l	a1, -(a7)
	movea.l	A_SEL_ICON_PTR, a2
	movea.l	(a2)+, a1
	move.l	a1, -(a7)
	bsr.w	f_0124f8
	movea.l	(a7)+, a1
	movea.l	(a7)+, a6
	movea.l	A_SEL_OBJECT, a0
	btst.b	#$7, (a6)
	beq.w	l_0178c4
	clr.w	d0
	clr.w	d1
	move.b	(a0), d0
	lsl.w	#$2, d0
	move.b	$2(a0), d1
	move.w	d0, A_CURSOR_X
	move.w	d1, A_CURSOR_Y
	tst.b	$1(a6)
	bne.w	l_0178a0
	tst.b	$2(a6)
	beq.w	l_0178ac
l_0178a0:
	movem.l	a0-a1/a6, -(a7)
	bsr.w	f_01042c
	movem.l	(a7)+, a0-a1/a6
l_0178ac:
	move.b	(a6), d0
	andi.b	#$007f, d0
	movea.l	#A_BLIT_SCRATCH, a6
	move.b	d0, (a6)
	move.b	(a0), $1(a6)
	move.b	$2(a0), $2(a6)
l_0178c4:
	subq.l	#$1, a6
	bsr.w	f_0159d2
	rts	
