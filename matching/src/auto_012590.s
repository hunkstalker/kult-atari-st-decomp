f_012590:
	move.b	d2, (a1)+
	move.b	d3, (a1)+
	move.l	a0, (a1)+
	move.w	d7, (a1)+
	move.l	a5, -(a7)
	movea.l	#A_BLIT_SCRATCH, a5
	clr.l	d5
	move.w	d2, d5
	lsl.l	#$1, d5
	movea.l	d5, a3
	move.l	a3, (a1)+
	subq.w	#$1, d2
	subq.w	#$1, d3
l_0125ae:
	move.l	#$f0f0f0f0, d1
	swap	d2
	move.w	d3, d2
	movea.l	a0, a2
	movea.l	a1, a4
	clr.l	d5
	btst.b	#$3, d7
	beq.w	l_0125c8
	addq.l	#$1, a2
l_0125c8:
	btst.b	#$2, d7
	beq.w	l_0125d4
	move.w	#$4, d5
l_0125d4:
	movep.l	$0(a2), d0
	rol.l	d5, d0
	and.l	d1, d0
	move.l	d0, (a5)
	movep.w	$1(a5), d0
	ror.w	#$4, d0
	movep.w	$0(a5), d4
	or.w	d4, d0
	move.w	d0, (a4)
	adda.l	#$a0, a2
	adda.l	a3, a4
	dbra	d2, l_0125d4
	addq.l	#$2, a1
	addq.w	#$4, d7
	andi.w	#$f, d7
	bne.w	l_01260a
	adda.l	#$8, a0
l_01260a:
	swap	d2
	dbra	d2, l_0125ae
	suba.l	a3, a4
	addq.l	#$2, a4
	movea.l	a4, a1
	movea.l	(a7)+, a5
	rts	
	movea.l	#A_BLIT_SCRATCH, a5
	subq.w	#$1, d2
	subq.w	#$1, d3
l_012624:
	move.l	#$f0f0f0f0, d6
	swap	d2
	move.w	d3, d1
	movea.l	a0, a2
	movea.l	a1, a4
	clr.l	d5
	btst.b	#$3, d7
	beq.w	l_01263e
	addq.l	#$1, a2
l_01263e:
	btst.b	#$2, d7
	beq.w	l_012648
	ror.l	#$4, d6
l_012648:
	move.l	d6, d4
	not.l	d6
l_01264c:
	swap	d1
	move.w	(a4), d0
	bsr.w	f_011196
	movep.w	d0, $0(a5)
	rol.w	#$4, d0
	movep.w	d0, $1(a5)
	move.l	(a5), d0
	ror.l	#$4, d0
	and.l	d4, d0
	movep.l	$0(a2), d5
	and.l	d6, d5
	or.l	d0, d5
	movep.l	d5, $0(a2)
	adda.l	#$a0, a2
	adda.l	a3, a4
	swap	d1
	dbra	d1, l_01264c
	addq.l	#$2, a1
	subq.w	#$4, d7
	bcc.w	l_012690
	suba.l	#$8, a0
	move.w	#$c, d7
l_012690:
	swap	d2
	dbra	d2, l_012624
	rts	
