f_010838:
	clr.w	d4
	move.b	d0,d4
	move.w	A_CURSOR_TEXT_X,d0
	move.w	A_CURSOR_TEXT_Y,d1
	addi.w	#1,A_CURSOR_TEXT_X
	bsr.w	f_010fec
	suba.l	A_SCREEN_DRAW_BASE,a0
	movea.l	#A_FONT_DATA,a1
	movea.l	A_COLOR_TABLE,a4
	mulu.w	#6,d4
	adda.l	d4,a1
	move.w	#$fff,d1
	ror.w	d7,d1
	move.w	d1,d3
	not.w	d3
	move.w	#5,d5
l_01087a:
	clr.l	d2
	move.b	(a1)+,d2
	move.w	(a4,d2.l),d2
	ror.w	d7,d2
	move.w	#3,d4
l_010888:
	and.w	d1,(a0)
	move.w	d2,d0
	and.w	d3,d0
	or.w	d0,(a0)+
	rol.w	#4,d2
	dbra	d4,l_010888
	adda.l	#$98,a0
	dbra	d5,l_01087a
	rts
f_0108a2:
	move.b	(a5),d0
	andi.b	#$3f,d0
	beq.w	l_0108c4
l_0108ac:
	cmpa.l	A_CUR_STR_END,a5
	beq.w	l_0108fe
	move.b	(a5),d0
	andi.b	#$3f,d0
	beq.w	l_0108ee
	bsr.w	f_010838
l_0108c4:
	move.b	(a5)+,d1
	andi.b	#$c0,d1
	beq.w	l_0108ac
	move.b	#$25,d0
	cmpi.b	#$80,d1
	beq.w	l_0108e6
	cmpi.b	#$40,d1
	beq.w	l_0108fa
	move.b	#$21,d0
l_0108e6:
	bsr.w	f_010838
	bra.w	l_0108ac
l_0108ee:
	move.b	(a5),d1
	andi.b	#$c0,d1
	bne.w	l_0108fa
	addq.l	#1,a5
l_0108fa:
	clr.l	d0
	rts
l_0108fe:
	move.b	#$ff,A_TEXT_END_FLAG
	move.w	#1,d0
	tst.w	d0
	rts
