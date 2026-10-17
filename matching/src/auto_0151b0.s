f_0151b0:
	move.b	#$0001, d0
	bsr.w	f_014f24
	move.w	s_01ac08, A_THE_COMMAND
	tst.b	A_DAT_1AD09
	bne.w	f_0103ae
	bsr.w	f_0164d4
	movea.l	A_PALETTE_PTR, a0
	tst.w	$2(a0)
	beq.w	l_0151e6
	move.w	#$13, d0
	bsr.w	f_0162e2
l_0151e6:
	move.w	#$1a, d4
	bsr.w	f_018f8e
	clr.w	d0
	clr.w	d1
	move.b	A_DAT_1AB40, d0
	move.b	A_DAT_1AB42, d1
	move.b	d1, d4
	bsr.w	f_010fec
	clr.w	d2
	move.b	A_DAT_1AB41, d2
	sub.b	A_DAT_1AB40, d2
	lsr.w	#$2, d2
	subq.w	#$1, d2
	clr.w	d3
	move.b	A_DAT_1AB43, d3
	sub.b	A_DAT_1AB42, d3
	subq.w	#$1, d3
	movea.l	a0, a3
l_015228:
	movem.l	d2-d4/a3, -(a7)
	move.w	d2, d5
	movea.l	a3, a4
l_015230:
	move.l	(a4), d0
	move.l	$4(a4), (a4)
	move.l	d0, $4(a4)
	adda.l	#$8, a4
	dbra	d5, l_015230
	bsr.w	f_013594
	move.w	d2, d5
	movea.l	a3, a4
l_01524c:
	move.l	(a4), d0
	move.l	$4(a4), (a4)
	move.l	d0, $4(a4)
	adda.l	#$8, a4
	dbra	d5, l_01524c
	movea.l	A_OBJ_BEGIN, a0
	movea.l	A_OBJ_END, a1
l_01526c:
	move.b	$4(a0), d0
	andi.b	#$00b8, d0
	cmpi.b	#$0028, d0
	bne.w	l_015284
	cmp.b	$2(a0), d4
	beq.w	l_0152c4
l_015284:
	addq.l	#$8, a0
	cmpa.l	a0, a1
	bne.w	l_01526c
l_01528c:
	movem.l	(a7)+, d2-d4/a3
	adda.l	#$a0, a3
	addq.b	#$1, d4
	dbra	d3, l_015228
	bsr.w	f_0164f6
	bsr.w	f_018fa4
	movea.l	A_PALETTE_PTR, a0
	tst.w	$2(a0)
	beq.w	l_0152b6
	bsr.w	f_0162da
l_0152b6:
	move.w	A_DAT_1AB54, A_THE_COMMAND
	bra.w	f_0103ae
l_0152c4:
	ori.b	#$0080, $4(a0)
	move.w	#$1b, d4
	bsr.w	f_018f8e
	clr.w	d0
	clr.w	d2
	move.b	(a0), d0
	move.b	$2(a0), d2
	move.w	#$26, d1
	bsr.w	f_0159e2
	move.w	#$1a, d4
	bsr.w	f_018f8e
	bra.b	l_01528c
