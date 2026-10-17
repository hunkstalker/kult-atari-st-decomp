f_013bc2:
	clr.l	d0
	move.w	s_01a542, d0
	move.w	d2, d7
	addq.w	#$2, d7
	addq.w	#$1, d3
	move.w	d3, s_01a480
	divu.w	d3, d0
	move.w	d0, s_01a490
	clr.w	d0
	divu.w	d3, d0
	move.w	d0, s_01a492
	clr.l	d0
	move.w	s_01a544, d0
	addq.w	#$1, d2
	move.w	d2, d6
	divu.w	d2, d0
	move.w	d0, s_01a498
	clr.w	d0
	divu.w	d2, d0
	move.w	d0, s_01a49a
	clr.l	d0
	move.l	d0, s_01a494
l_013c0e:
	mulu.w	A_TEXT_BOX_SPAN, d0
	movea.l	A_ELEM_1A528, a0
	adda.l	d0, a0
	adda.l	d0, a0
	move.w	s_01a480, d7
	move.w	s_01a486, d5
	movea.l	a1, a4
	move.w	#$10, d4
	sub.w	d5, d4
	clr.l	(a4)
	clr.l	$4(a4)
	clr.l	d0
	move.l	d0, s_01a48c
l_013c40:
	andi.l	#$ff, d0
	move.l	d0, d1
	andi.b	#$00fc, d0
	lsr.b	#$1, d0
	move.w	(a0, d0.l), d0
	andi.b	#$0003, d1
	lsl.w	d1, d0
	lsl.w	#$1, d0
	roxl.w	(a4)
	lsl.w	#$4, d0
	roxl.w	$2(a4)
	lsl.w	#$4, d0
	roxl.w	$4(a4)
	lsl.w	#$4, d0
	roxl.w	$6(a4)
	subq.w	#$1, d4
	bne.w	l_013c7e
	adda.l	#$8, a4
	move.w	#$10, d4
l_013c7e:
	move.l	s_01a48c, d0
	add.w	s_01a490, d0
	swap	d0
	add.w	s_01a492, d0
	bcc.w	l_013c9c
	addi.l	#$10000, d0
l_013c9c:
	swap	d0
	move.l	d0, s_01a48c
	tst.w	d7
	beq.w	l_013cba
	subq.w	#$1, d7
	bne.w	l_013c40
	move.w	s_01a542, d0
	bra.w	l_013c40
l_013cba:
	move.l	(a4), d0
	move.l	$4(a4), d1
	lsl.l	d4, d0
	lsl.l	d4, d1
	move.l	d0, (a4)+
	move.l	d1, (a4)
	adda.l	#$a0, a1
	move.l	s_01a494, d0
	add.w	s_01a498, d0
	swap	d0
	add.w	s_01a49a, d0
	bcc.w	l_013cec
	addi.l	#$10000, d0
l_013cec:
	swap	d0
	move.l	d0, s_01a494
	tst.w	d6
	beq.w	l_013d0c
	subq.w	#$1, d6
	bne.w	l_013c0e
	clr.l	d0
	move.w	s_01a544, d0
	bra.w	l_013c0e
l_013d0c:
	rts	
