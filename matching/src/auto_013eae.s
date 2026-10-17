f_013eae:
	lsl.w	#$2, d0
	move.w	d0, s_01a516
	lsl.w	#$1, d2
	add.w	d2, d0
	subq.w	#$1, d0
	move.w	d0, s_01a518
	move.w	d3, d2
	add.w	d1, d3
	subq.w	#$1, d3
	move.w	d3, s_01a51c
	move.w	d3, s_01a51a
	subq.w	#$1, d2
l_013ed6:
	move.l	d2, -(a7)
	bsr.w	f_013d0e
	bsr.w	f_013594
	move.l	(a7)+, d2
	subq.w	#$1, s_01a51a
	dbra	d2, l_013ed6
	move.w	A_TEXT_BOX_SPAN, d2
	lsl.w	#$2, d2
	subq.w	#$1, d2
l_013ef6:
	move.w	d2, -(a7)
	bsr.w	f_013d0e
	bsr.w	f_013594
	move.w	(a7)+, d2
	addq.w	#$1, s_01a516
	dbra	d2, l_013ef6
	move.w	A_ELEM_1A52C, d2
l_013f12:
	move.w	d2, -(a7)
	bsr.w	f_013d0e
	bsr.w	f_013594
	move.w	(a7)+, d2
	addq.w	#$1, s_01a51a
	dbra	d2, l_013f12
	rts	
