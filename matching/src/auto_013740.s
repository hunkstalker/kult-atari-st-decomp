f_013740:
	tst.b	A_SKIP_TRANSITION
	bne.w	f_0134da
	bsr.w	f_0128a4
	movem.l	d0-d7/a0-a1, -(a7)
	movea.l	a0, a2
	move.w	d3, d4
	subq.w	#$1, d4
	move.w	d4, s_01a544
	lsl.w	#$1, d2
	move.w	d2, d4
	lsl.w	#$1, d4
	subq.w	#$1, d4
	move.w	d4, s_01a542
	subq.w	#$1, d2
	lsl.w	#$2, d0
	add.w	d2, d0
	lsr.w	#$1, d3
	add.w	d3, d1
	bsr.w	f_010fee
	move.w	d7, s_01a486
	move.w	A_TEXT_BOX_SPAN, d0
	lsl.w	#$2, d0
	move.w	d0, d2
	move.w	d0, d4
	cmp.w	A_ELEM_1A52C, d0
	bcc.w	l_01379c
	move.w	A_ELEM_1A52C, d4
l_01379c:
	move.w	d4, d3
	lsr.w	#$1, d4
	clr.l	d0
	move.w	A_ELEM_1A52C, d0
	lsl.l	#$1, d0
	divu.w	d3, d0
	move.w	d0, s_01a54a
	clr.w	d0
	divu.w	d3, d0
	move.w	d0, s_01a54c
	clr.l	d0
	move.w	d2, d0
	lsl.l	#$1, d0
	divu.w	d3, d0
	move.w	d0, s_01a552
	clr.w	d0
	divu.w	d3, d0
	move.w	d0, s_01a554
	move.l	#$2, s_01a546
	move.l	#$2, s_01a54e
	move.w	#$2, d2
	move.w	#$2, d3
	subq.w	#$3, d4
	movea.l	a0, a2
l_0137f4:
	movem.l	d4/a2, -(a7)
	bsr.w	f_013a18
	movem.l	(a7)+, d4/a2
	move.l	s_01a546, d0
	add.w	s_01a54a, d0
	swap	d0
	add.w	s_01a54c, d0
	bcc.w	l_01382a
	addi.w	#$0, d0
	swap	d0
	move.l	d0, s_01a546
	move.w	d0, d2
	bra.w	l_01383c
l_01382a:
	swap	d0
	move.l	d0, s_01a546
	move.w	d0, d2
	btst.b	#$0, d0
	bne.w	l_013842
l_01383c:
	suba.l	#$a0, a2
l_013842:
	move.l	s_01a54e, d0
	add.w	s_01a552, d0
	swap	d0
	add.w	s_01a554, d0
	bcc.w	l_01386a
	swap	d0
	addq.w	#$1, d0
	move.l	d0, s_01a54e
	move.w	d0, d3
	bra.w	l_01387c
l_01386a:
	swap	d0
	move.l	d0, s_01a54e
	move.w	d0, d3
	btst.b	#$0, d0
	bne.w	l_013898
l_01387c:
	move.w	s_01a486, d0
	bne.w	l_013890
	suba.l	#$8, a2
	move.w	#$10, d0
l_013890:
	subq.w	#$1, d0
	move.w	d0, s_01a486
l_013898:
	dbra	d4, l_0137f4
	movem.l	(a7)+, d0-d7/a0-a1
	bsr.w	f_0124da
	rts	
