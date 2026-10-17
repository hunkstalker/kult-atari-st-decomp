f_01398e:
	movea.l	#A_SAVE_DESC, a4
	movea.l	#s_01a1f2, a5
	move.w	d3, d5
	lsr.w	#$3, d5
	andi.w	#$7, d3
	bne.w	l_0139a8
	subq.w	#$1, d5
l_0139a8:
	btst.b	#$3, d7
	beq.w	l_0139b2
	addq.l	#$1, a0
l_0139b2:
	btst.b	#$2, d7
	beq.w	l_0139bc
	addq.w	#$1, d2
l_0139bc:
	move.w	d2, d3
	lsr.w	#$1, d3
	bcs.w	l_0139c6
	subq.w	#$1, d3
l_0139c6:
	movea.l	a0, a2
	move.w	d3, d6
l_0139ca:
	movea.l	a2, a3
	move.w	#$7, d4
	move.l	a3, d0
	sub.l	A_SCREEN_PTR_A, d0
	move.w	d0, (a4)+
	clr.w	d0
	move.b	(a5)+, d0
	bne.w	l_0139e6
	move.b	#$0001, d0
l_0139e6:
	move.w	d0, (a4)+
l_0139e8:
	movep.l	$0(a3), d0
	move.l	d0, (a4)+
	adda.l	#$a0, a3
	dbra	d4, l_0139e8
	addq.l	#$1, a2
	move.l	a2, d0
	btst.b	#$0, d0
	bne.w	l_013a06
	addq.l	#$6, a2
l_013a06:
	dbra	d6, l_0139ca
	adda.l	#$500, a0
	dbra	d3, l_0139c6
	clr.l	(a4)
	rts	
