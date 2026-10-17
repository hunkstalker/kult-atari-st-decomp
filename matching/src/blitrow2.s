f_0124da:
	movem.l	d3/d7/a0-a1,-(a7)
	movea.l	A_DAT_1A534,a3
	bsr.w	f_012510
	bsr.w	f_013594
	movem.l	(a7)+,d3/d7/a0-a1
	rts
f_0124f2:
	movea.l	#A_SAVE_DESC,a1
f_0124f8:
	cmpa.l	#0,a1
	beq.w	l_012588
	clr.w	d2
	clr.w	d3
	move.b	(a1)+,d2
	move.b	(a1)+,d3
	movea.l	(a1)+,a0
	move.w	(a1)+,d7
	movea.l	(a1)+,a3
f_012510:
	movea.l	#A_BLIT_SCRATCH,a5
	subq.w	#1,d2
	subq.w	#1,d3
l_01251a:
	move.l	#$f0f0f0f0,d1
	swap	d2
	move.w	d3,d2
	movea.l	a0,a2
	movea.l	a1,a4
	clr.l	d5
	btst.b	#3,d7
	beq.w	l_012534
	addq.l	#1,a2
l_012534:
	btst.b	#2,d7
	beq.w	l_012542
	ror.l	#4,d1
	move.w	#4,d5
l_012542:
	move.l	d1,d4
	not.l	d1
l_012546:
	move.w	(a4),d6
	movep.w	d6,0(a5)
	rol.w	#4,d6
	movep.w	d6,1(a5)
	move.l	(a5),d6
	ror.l	d5,d6
	and.l	d4,d6
	movep.l	0(a2),d0
	and.l	d1,d0
	or.l	d6,d0
	movep.l	d0,0(a2)
	adda.l	#$a0,a2
	adda.l	a3,a4
	dbra	d2,l_012546
	addq.l	#2,a1
	addq.w	#4,d7
	andi.w	#$f,d7
	bne.w	l_012582
	adda.l	#8,a0
l_012582:
	swap	d2
	dbra	d2,l_01251a
l_012588:
	rts
