f_013e14:
	lsl.w	#$2, d0
	move.w	d0, s_01a516
	lsl.w	#$2, d2
	add.w	d2, d0
	subq.w	#$1, d0
	move.w	d0, s_01a518
	move.w	d1, s_01a51a
	add.w	d1, d3
	subq.w	#$1, d3
	move.w	d3, s_01a51c
	subq.w	#$1, d2
l_013e3a:
	move.l	d2, -(a7)
	bsr.w	f_013d0e
	bsr.w	f_013594
	move.l	(a7)+, d2
	addq.w	#$1, s_01a516
	subq.w	#$1, s_01a518
	dbra	d2, l_013e3a
	move.w	A_ELEM_1A52C, d2
	move.w	s_01a516, d0
	subq.w	#$1, d0
	move.w	s_01a518, d1
	addq.w	#$1, d1
	move.w	d0, s_01a518
	move.w	d1, s_01a516
	move.w	s_01a51a, d0
	move.w	s_01a51c, s_01a51a
	move.w	d0, s_01a51c
	subq.w	#$1, d2
l_013e90:
	move.w	d2, -(a7)
	bsr.w	f_013d0e
	bsr.w	f_013594
	move.w	(a7)+, d2
	subq.w	#$1, s_01a51a
	addq.w	#$1, s_01a51c
	dbra	d2, l_013e90
	rts	
