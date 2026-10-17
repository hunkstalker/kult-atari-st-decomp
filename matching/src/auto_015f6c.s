f_015f6c:
	clr.l	d0
	move.b	(a6)+, d1
	btst.b	#$7, d1
	bne.w	l_015f92
	move.b	(a6)+, d0
	btst.b	#$5, d1
	beq.w	l_015f8a
	lsl.w	#$8, d0
	move.b	(a6)+, d0
	bset.b	#$1f, d0
l_015f8a:
	movea.l	#$0, a0
	rts	
l_015f92:
	clr.l	d2
	move.b	d1, d2
	andi.b	#$001f, d2
	lsl.l	#$2, d2
	movea.l	#A_CLEAR_BUF, a1
	movea.l	(a1, d2.l), a1
	btst.b	#$6, d1
	beq.w	l_015fb6
	clr.l	d4
	move.b	(a6)+, d4
	bsr.w	f_010f8e
l_015fb6:
	clr.l	d2
	move.b	(a6)+, d2
	adda.l	d2, a1
	move.b	(a1), d0
	btst.b	#$5, d1
	beq.w	l_015fd0
	lsl.w	#$8, d0
	move.b	$1(a1), d0
	bset.b	#$1f, d0
l_015fd0:
	movea.l	a1, a0
	rts	
