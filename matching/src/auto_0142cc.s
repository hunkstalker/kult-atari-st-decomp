f_0142cc:
	move.l	#$ff00ff00, s_01a56c
	movea.l	#s_01a7b6, a2
	subq.b	#$1, d0
	andi.l	#$f, d0
	lsl.l	#$2, d0
	adda.l	d0, a2
	movea.l	(a2), a6
	move.w	#$2, d4
	movea.l	#A_SAVE_DESC, a5
	clr.w	d0
	btst.b	#$7, $1(a6)
	beq.w	l_014302
	not.w	d0
l_014302:
	move.w	d0, (a5)+
l_014304:
	move.l	d4, -(a7)
	clr.l	d4
	move.b	(a6), d4
	movea.l	#A_TEXT_TABLE, a1
	bsr.w	f_010f8e
	clr.l	d0
	clr.l	d1
	move.b	$1(a6), d0
	move.b	$2(a6), d1
	clr.l	d2
	clr.l	d3
	move.b	(a1)+, d3
	move.b	(a1)+, d2
	move.b	d0, d6
	btst.b	#$7, d0
	beq.w	l_01433e
	add.b	d2, d0
	subq.b	#$1, d0
	andi.b	#$007f, d0
	andi.b	#$007f, d6
l_01433e:
	clr.l	d5
	move.b	d2, d5
	lsl.w	#$1, d5
	move.l	d5, A_DAT_1A534
	lsl.b	#$1, d1
	cmp.b	s_01a56c, d6
	bcc.w	l_01435c
	move.b	d6, s_01a56c
l_01435c:
	move.b	d6, d4
	add.b	d2, d4
	cmp.b	s_01a56d, d4
	bcs.w	l_014370
	move.b	d4, s_01a56d
l_014370:
	cmp.b	s_01a56e, d1
	bcc.w	l_014380
	move.b	d1, s_01a56e
l_014380:
	move.b	d1, d4
	add.b	d3, d4
	cmp.b	s_01a56f, d4
	bcs.w	l_014394
	move.b	d4, s_01a56f
l_014394:
	bsr.w	f_010fec
	suba.l	#$8000, a0
	move.w	d2, (a5)+
	move.w	d3, (a5)+
	move.l	a1, (a5)+
	move.l	a0, (a5)+
	move.w	d7, (a5)+
	addq.l	#$3, a6
	move.l	(a7)+, d4
	dbra	d4, l_014304
	clr.l	d0
	clr.l	d1
	clr.l	d2
	clr.l	d3
	move.b	s_01a56c, d0
	move.b	s_01a56e, d1
	move.b	s_01a56d, d2
	move.b	s_01a56f, d3
	sub.w	d0, d2
	sub.w	d1, d3
	bsr.w	f_010fec
	move.w	d2, (a5)+
	move.w	d3, (a5)+
	move.l	a0, (a5)+
	move.w	d7, (a5)+
	rts	
