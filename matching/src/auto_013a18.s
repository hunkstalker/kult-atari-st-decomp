f_013a18:
	movea.l	#A_SAVE_DESC, a1
	clr.l	d0
	move.w	s_01a542, d0
	move.w	d2, d7
	addq.w	#$2, d7
	move.l	d7, -(a7)
	movea.l	a2, a5
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
l_013a6e:
	mulu.w	A_TEXT_BOX_SPAN, d0
	movea.l	A_ELEM_1A528, a0
	adda.l	d0, a0
	adda.l	d0, a0
	move.w	s_01a480, d7
	move.w	s_01a486, d5
	movea.l	a2, a3
	move.w	#$10, d4
	sub.w	d5, d4
	move.l	(a3), d0
	move.l	$4(a3), d1
	lsr.l	d4, d0
	lsr.l	d4, d1
	move.l	d0, (a1)
	move.l	d1, $4(a1)
	clr.l	d0
	move.l	d0, s_01a48c
	clr.w	s_01a556
l_013ab0:
	andi.l	#$ff, d0
	move.l	d0, d1
	andi.b	#$00fc, d0
	lsr.b	#$1, d0
	move.w	(a0, d0.l), d0
	andi.b	#$0003, d1
	lsl.w	d1, d0
	lsl.w	#$1, d0
	roxl.w	(a1)
	lsl.w	#$4, d0
	roxl.w	$2(a1)
	lsl.w	#$4, d0
	roxl.w	$4(a1)
	lsl.w	#$4, d0
	roxl.w	$6(a1)
	subq.w	#$1, d4
	bne.w	l_013afa
	adda.l	#$8, a1
	adda.l	#$8, a3
	addq.w	#$2, s_01a556
	move.w	#$10, d4
l_013afa:
	move.l	s_01a48c, d0
	add.w	s_01a490, d0
	swap	d0
	add.w	s_01a492, d0
	bcc.w	l_013b18
	addi.l	#$10000, d0
l_013b18:
	swap	d0
	move.l	d0, s_01a48c
	tst.w	d7
	beq.w	l_013b36
	subq.w	#$1, d7
	bne.w	l_013ab0
	move.w	s_01a542, d0
	bra.w	l_013ab0
l_013b36:
	move.l	(a1), d0
	move.l	$4(a1), d1
	lsl.l	d4, d0
	lsl.l	d4, d1
	move.w	#$ffff, d2
	lsl.w	d4, d2
	clr.l	d3
	move.w	d2, d3
	swap	d3
	move.w	d2, d3
	and.l	d3, d0
	and.l	d3, d1
	not.l	d3
	move.l	(a3), d2
	move.l	$4(a3), d4
	and.l	d3, d2
	and.l	d3, d4
	or.l	d2, d0
	or.l	d4, d1
	move.l	d0, (a1)+
	move.l	d1, (a1)+
	addq.w	#$2, s_01a556
	adda.l	#$a0, a2
	move.l	s_01a494, d0
	add.w	s_01a498, d0
	swap	d0
	add.w	s_01a49a, d0
	bcc.w	l_013b90
	addi.l	#$10000, d0
l_013b90:
	swap	d0
	move.l	d0, s_01a494
	tst.w	d6
	beq.w	l_013bb0
	subq.w	#$1, d6
	bne.w	l_013a6e
	clr.l	d0
	move.w	s_01a544, d0
	bra.w	l_013a6e
l_013bb0:
	move.l	(a7)+, d5
	movea.l	a5, a0
	move.w	s_01a556, d4
	subq.w	#$1, d4
	subq.w	#$1, d5
	bra.w	f_0123a0
