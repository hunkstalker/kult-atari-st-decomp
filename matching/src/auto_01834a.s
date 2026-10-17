f_01834a:
	movea.l	#$0, a5
l_018350:
	movea.l	#A_SAVE_DESC, a1
	move.w	#$ff, d6
l_01835a:
	move.l	A_SCREEN_PTR_A, d0
	add.w	(a1), d0
	movea.l	d0, a0
	move.w	$2(a1), d0
	move.l	#$7fff7fff, d1
	ror.l	d0, d1
	and.l	d1, (a0)+
	and.l	d1, (a0)
	move.w	$8(a1), d4
	subi.w	#$148, d4
	bcc.w	l_018396
	cmpi.w	#$1e, d5
	bcs.w	l_018416
	bsr.w	f_018316
	ori.w	#$1800, $8(a1)
	bra.w	l_018416
l_018396:
	move.w	d4, $8(a1)
	addi.w	#$10, d4
	move.l	#$cffff, d3
	divu.w	d4, d3
	move.w	d3, d4
	muls.w	$4(a1), d3
	swap	d3
	move.w	d3, d0
	move.w	$6(a1), d3
	muls.w	d4, d3
	swap	d3
	move.w	d3, d1
	addi.w	#$a0, d0
	bmi.w	l_018426
	cmpi.w	#$140, d0
	bcc.w	l_018426
	addi.w	#$64, d1
	bmi.w	l_018426
	cmpi.w	#$c8, d1
	bcc.w	l_018426
	bsr.w	f_010fee
	move.l	a0, d0
	sub.l	A_SCREEN_PTR_A, d0
	suba.l	a5, a0
	move.w	d0, (a1)
	move.w	d7, $2(a1)
	move.w	#$8000, d1
	ror.w	d7, d1
	move.w	$8(a1), d0
	cmpi.w	#$c00, d0
	bcc.w	l_01840a
	cmpi.w	#$600, d0
	bcc.w	l_018412
	or.w	d1, (a0)
l_01840a:
	or.w	d1, $2(a0)
	or.w	d1, $6(a0)
l_018412:
	or.w	d1, $4(a0)
l_018416:
	adda.l	#$a, a1
	dbra	d6, l_01835a
	bsr.w	f_013594
	rts	
l_018426:
	clr.w	$8(a1)
	bra.b	l_018416
