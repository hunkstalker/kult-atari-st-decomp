f_015492:
	move.w	#$3e, d5
	movea.l	#A_LIST_1A8F0, a1
	movea.l	#A_TBL_1A6AE, a2
	clr.w	d6
l_0154a4:
	move.w	(a1), d0
	and.w	d2, d0
	cmp.w	d3, d0
	bne.w	l_015502
	tst.w	d6
	bne.w	l_0154e2
	movem.l	d2-d3/d5-d6/a1-a2, -(a7)
	move.w	#$3a, d0
	move.w	#$38, d1
	move.w	s_01a488, d6
	bsr.w	f_010fec
	move.w	#$10, d2
	move.w	#$40, d3
	bsr.w	f_01276c
	move.w	#$14, d4
	bsr.w	f_018f8e
	movem.l	(a7)+, d2-d3/d5-d6/a1-a2
l_0154e2:
	move.b	$3(a1), $4(a2)
	move.w	$4(a1), $6(a2)
	move.b	#$003f, d0
	sub.b	d5, d0
	move.b	d0, $8(a2)
	clr.w	d4
	move.b	$2(a1), d4
	bsr.w	f_015510
l_015502:
	addq.l	#$6, a1
	dbra	d5, l_0154a4
	move.w	d6, s_01a510
	rts	
