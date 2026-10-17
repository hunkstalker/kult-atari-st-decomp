f_0138a6:
	tst.b	A_SKIP_TRANSITION
	bne.w	f_01222e
	clr.w	d0
	move.b	$1(a6), d0
	bsr.w	f_0120e4
	bsr.w	f_01398e
	movea.l	#A_SAVE_DESC, a4
	move.w	#$1, d6
l_0138c8:
	clr.w	d5
l_0138ca:
	move.w	$2(a4), d0
	lsr.w	#$2, d0
	cmp.w	d6, d0
	bcc.w	l_013968
	clr.l	d0
	move.w	(a4), d0
	movea.l	A_SCREEN_PTR_A, a0
	movea.l	A_SCREEN_PTR_B, a1
	adda.l	d0, a0
	adda.l	d0, a1
	movea.l	a0, a2
	movea.l	a1, a3
	movea.l	a4, a5
	addq.l	#$4, a5
	move.w	#$7, d3
l_0138f6:
	movep.l	$0(a2), d1
	cmp.l	(a5), d1
	bne.w	l_013908
	movep.l	$0(a3), d1
	movep.l	d1, $0(a2)
l_013908:
	adda.l	#$a0, a2
	adda.l	#$a0, a3
	addq.l	#$4, a5
	dbra	d3, l_0138f6
	move.w	$2(a4), d0
	beq.w	l_01396c
	andi.w	#$7, d0
	addq.w	#$1, d0
	move.l	#$a0, d1
	mulu.w	d0, d1
	adda.l	d1, a0
	movea.l	a0, a2
	suba.l	A_SCREEN_PTR_A, a0
	move.l	a0, d0
	move.w	d0, (a4)
	cmpa.l	#$7800, a0
	bcs.w	l_01394e
	clr.w	$2(a4)
	bra.b	l_01396c
l_01394e:
	movea.l	a4, a5
	addq.l	#$4, a5
	move.w	#$7, d3
l_013956:
	move.l	(a5), d0
	movep.l	d0, $0(a2)
	adda.l	#$a0, a2
	addq.l	#$4, a5
	dbra	d3, l_013956
l_013968:
	move.w	#$1, d5
l_01396c:
	adda.l	#$24, a4
	tst.w	(a4)
	bne.w	l_0138ca
	bsr.w	f_013594
	movea.l	#A_SAVE_DESC, a4
	addq.w	#$1, d6
	tst.w	d5
	bne.w	l_0138c8
	addq.l	#$2, a6
	rts	
