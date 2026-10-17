f_016636:
	movea.l	#$8000, a4
l_01663c:
	movem.l	d6/a1-a2, -(a7)
	movea.l	#A_OBJ_TBL, a3
	move.w	#$28, d2
l_01664a:
	move.b	$1(a3), d0
	andi.b	#$000f, d0
	cmp.b	d0, d3
	beq.w	l_016668
	adda.l	#$5, a3
	dbra	d2, l_01664a
	clr.b	d0
	bra.w	l_0166d4
l_016668:
	move.b	$3(a3), d1
	andi.l	#$f8, d1
	move.l	d1, d2
	lsr.l	#$3, d2
	movea.l	#s_01a57d, a3
	adda.l	d1, a3
	adda.l	d2, a3
	clr.l	d0
	move.b	(a3), d0
	addq.b	#$1, (a3)
	andi.b	#$0007, (a3)
	adda.l	d0, a3
	addq.l	#$1, a3
	move.b	(a3), d0
	movem.l	a2/a4, -(a7)
	move.l	#A_SAVE_DESC, A_ANIM_SPR_PTR
	bsr.w	f_015ac8
	movem.l	(a7)+, a2/a4
	clr.w	d0
	clr.w	d1
	move.b	(a2), d0
	move.b	$2(a2), d1
	bsr.w	f_010fec
	suba.l	a4, a0
	movea.l	#A_SAVE_DESC, a1
	clr.w	d2
	clr.w	d3
	move.b	(a1)+, d2
	move.b	(a1)+, d3
	movem.l	d2-d3/d7/a0, -(a7)
	bsr.w	f_01103e
	movem.l	(a7)+, d2-d3/d7/a0
	move.b	#$ffff, d0
l_0166d4:
	movem.l	(a7)+, d6/a1-a2
	rts	
