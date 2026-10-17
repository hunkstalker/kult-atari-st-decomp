f_01566a:
	move.b	A_TEXT_SEL_A, A_1AB44
	addq.l	#$1, a6
	movea.l	a6, a5
	clr.w	d0
	clr.w	d1
	cmpi.b	#$00ff, s_01a575
	bne.w	l_0156d0
	move.w	A_CURSOR_X, d0
	lsr.w	#$2, d0
	move.w	d0, d1
	addi.w	#$c, d0
	subi.w	#$4a, d0
	bcs.w	l_0156a0
	sub.w	d0, d1
l_0156a0:
	cmpi.b	#$0008, d1
	bcc.w	l_0156ac
	move.b	#$0008, d1
l_0156ac:
	move.b	d1, s_01a575
	move.w	d1, d0
	move.w	A_CURSOR_Y, d1
	move.w	d1, d2
	addi.w	#$2d, d2
	subi.w	#$b4, d2
	bcs.w	l_0156ca
	sub.w	d2, d1
l_0156ca:
	move.b	d1, s_01a576
l_0156d0:
	move.b	s_01a576, d1
	move.b	s_01a575, d0
	move.l	a5, -(a7)
	movea.l	#s_028ad4, a1
	clr.w	d2
	clr.w	d3
	move.b	(a1)+, d3
	move.b	(a1)+, d2
	clr.l	d5
	move.b	d2, d5
	lsl.l	#$1, d5
	move.l	d5, A_DAT_1A534
	bsr.w	f_010fec
	bsr.w	f_0127f0
	move.w	#$12, d4
	bsr.w	f_018f8e
	movea.l	(a7)+, a5
	movea.l	#s_019ad6, a4
	movea.l	#s_019af6, a1
	move.b	s_01a575, d2
	move.b	s_01a576, d3
	move.b	(a5)+, d5
	move.w	#$ffff, d4
	move.w	#$7, d6
l_01572c:
	lsr.b	#$1, d5
	bcc.w	l_015752
	move.b	(a1), d0
	add.b	d2, d0
	move.b	d0, (a4)
	addq.b	#$2, d0
	move.b	d0, $1(a4)
	move.b	$1(a1), d1
	add.b	d3, d1
	move.b	d1, $2(a4)
	addq.b	#$8, d1
	move.b	d1, $3(a4)
	addq.w	#$1, d4
	addq.l	#$4, a4
l_015752:
	addq.l	#$2, a1
	dbra	d6, l_01572c
	move.l	d4, -(a7)
	movea.l	#s_019ad6, a4
l_015760:
	movem.l	d4/a4-a5, -(a7)
	clr.w	d0
	clr.w	d1
	move.b	(a4), d0
	move.b	$2(a4), d1
	move.w	#$1, d4
	bsr.w	f_011020
	movem.l	(a7)+, d4/a4-a5
	addq.l	#$4, a4
	dbra	d4, l_015760
	clr.l	d0
	bsr.w	f_014a98
	bsr.w	f_010522
	move.l	(a7)+, d4
l_01578c:
	move.l	d4, -(a7)
	bsr.w	f_013698
	movea.l	#s_019ad2, a4
	move.l	(a7)+, d4
	move.w	d4, d3
	movea.l	a5, a2
	subq.l	#$3, a2
l_0157a0:
	addq.l	#$4, a4
	addq.l	#$3, a2
	bsr.w	f_01478a
	dbcs	d3, l_0157a0
	move.b	#$0064, d0
	move.b	#$0001, A_CURSOR_HOTSPOT
	move.w	#$ffff, d1
	cmpi.w	#$ffff, d3
	beq.w	l_0157d6
	clr.b	A_CURSOR_HOTSPOT
	move.b	(a2), d0
	move.b	$1(a2), d1
	lsl.w	#$8, d1
	move.b	$2(a2), d1
l_0157d6:
	move.b	d0, A_TEXT_SEL_B
	move.w	d1, A_THE_COMMAND
	movem.l	d4/a4-a5, -(a7)
	cmp.b	A_1AB47, d0
	beq.w	l_0157f4
	bsr.w	f_010a88
l_0157f4:
	bsr.w	f_01031c
	movem.l	(a7)+, d4/a4-a5
	btst.b	#$2, A_INPUT_BUTTONS
	beq.w	l_01578c
	move.l	d4, -(a7)
	bsr.w	f_01060a
	cmpi.w	#$ffff, A_THE_COMMAND
	beq.w	l_015870
	bsr.w	f_013594
	move.w	#$13, d4
	bsr.w	f_018f8e
	clr.w	d0
	clr.w	d1
	move.b	(a4), d0
	move.b	$2(a4), d1
	move.b	#$0018, d4
	movem.l	d0-d1, -(a7)
	bsr.w	f_011020
	move.w	#$ffff, d0
l_015840:
	dbra	d0, l_015840
	movem.l	(a7)+, d0-d1
	movem.l	d0-d1, -(a7)
	move.w	#$2, d4
	bsr.w	f_011020
	move.w	#$ffff, d0
l_015858:
	dbra	d0, l_015858
	movem.l	(a7)+, d0-d1
	move.w	#$19, d4
	bsr.w	f_011020
	move.w	#$ffff, d0
l_01586c:
	dbra	d0, l_01586c
l_015870:
	bsr.w	f_012436
	move.l	(a7)+, d4
	andi.l	#$ffff, d4
	addq.l	#$1, d4
	addq.l	#$1, a6
	adda.l	d4, a6
	adda.l	d4, a6
	adda.l	d4, a6
	rts	
