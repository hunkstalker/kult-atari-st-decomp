f_013370:
	lsl.w	#$2, d0
	lsl.w	#$2, d2
	move.w	d0, s_01a516
	move.w	d1, s_01a51e
	move.w	d0, d4
	add.w	d2, d0
	subq.w	#$1, d0
	move.w	d0, s_01a518
	move.w	d1, s_01a520
	add.w	d3, d1
	subq.w	#$1, d1
	move.w	d0, s_01a51a
	move.w	d1, s_01a522
	move.w	d4, d0
	move.w	d0, s_01a51c
	move.w	d1, s_01a524
	move.w	d3, d7
	lsr.w	#$1, d7
	addq.w	#$1, d7
	move.w	#$0, d2
	move.w	#$1, d3
l_0133be:
	move.w	d7, -(a7)
	move.w	s_01a516, d0
	move.w	s_01a51e, d1
	sub.w	d2, d1
	bsr.w	f_013162
	add.w	d2, d1
	sub.w	d2, d0
	bsr.w	f_0130a4
	add.w	d2, d0
	addq.w	#$1, d0
	addq.w	#$1, d1
	move.w	d0, s_01a516
	move.w	d1, s_01a51e
	move.w	s_01a518, d0
	move.w	s_01a520, d1
	bsr.w	f_0130a4
	sub.w	d2, d1
	bsr.w	f_013162
	add.w	d2, d1
	addq.w	#$1, d1
	subq.w	#$1, d0
	move.w	d0, s_01a518
	move.w	d1, s_01a520
	move.w	s_01a51a, d0
	move.w	s_01a522, d1
	bsr.w	f_013162
	bsr.w	f_0130a4
	subq.w	#$1, d0
	subq.w	#$1, d1
	move.w	d0, s_01a51a
	move.w	d1, s_01a522
	move.w	s_01a51c, d0
	move.w	s_01a524, d1
	bsr.w	f_013162
	sub.w	d2, d0
	bsr.w	f_0130a4
	add.w	d2, d0
	subq.w	#$1, d1
	addq.w	#$1, d0
	move.w	d0, s_01a51c
	move.w	d1, s_01a524
	addq.w	#$1, d3
	addq.w	#$1, d2
	move.w	#$3e8, d6
l_013468:
	dbra	d6, l_013468
	move.w	(a7)+, d7
	dbra	d7, l_0133be
	rts	
