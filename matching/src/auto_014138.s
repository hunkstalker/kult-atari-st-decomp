f_014138:
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
	beq.w	l_014170
	add.b	d2, d0
	subq.b	#$1, d0
	andi.b	#$007f, d0
	andi.b	#$007f, d6
l_014170:
	clr.l	d5
	move.b	d2, d5
	lsl.w	#$1, d5
	btst.b	#$7, d1
	beq.w	l_01418c
	clr.l	d4
	move.b	d5, d4
	mulu.w	d3, d4
	adda.l	d4, a1
	suba.l	d5, a1
	not.l	d5
	addq.l	#$1, d5
l_01418c:
	move.l	d5, A_DAT_1A534
	lsl.b	#$1, d1
	cmpi.b	#$0053, (a6)
	bne.w	l_0141aa
	lsr.w	A_DAT_1A49E
	bcc.w	l_0141aa
	subi.w	#$8, d1
l_0141aa:
	move.w	d1, d5
	bsr.w	f_010fec
	movem.l	d2-d3/d5-d7/a0/a4, -(a7)
	suba.l	#$8000, a0
	movea.l	A_DAT_1A534, a3
	btst.b	#$7, $1(a6)
	bne.w	l_0141d2
	bsr.w	f_011050
	bra.w	l_0141d6
l_0141d2:
	bsr.w	f_011102
l_0141d6:
	movem.l	(a7)+, d2-d3/d5-d7/a0/a4
	rts	
