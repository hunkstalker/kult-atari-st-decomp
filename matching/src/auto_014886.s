f_014886:
	movea.l	A_OBJ_BEGIN, a4
	move.w	A_CURSOR_X, d0
	lsr.w	#$2, d0
	move.w	A_CURSOR_Y, d1
	move.b	#$0001, d4
l_01489e:
	bsr.w	f_014798
	bcs.w	l_0148ce
l_0148a6:
	addq.l	#$8, a4
	addq.b	#$1, d4
	cmpa.l	A_OBJ_END, a4
	bne.w	l_01489e
	move.b	#$0001, A_CURSOR_HOTSPOT
	move.b	A_1AB48, A_TEXT_SEL_A
	clr.b	A_SEL_1ACC9
	rts	
l_0148ce:
	btst.b	#$f, $4(a4)
	beq.w	l_0148a6
	move.b	$4(a4), d0
	and.b	d2, d0
	cmp.b	d3, d0
	bne.w	l_0148a6
	move.b	d4, A_SEL_1ACC9
	andi.l	#$ff, d4
	subq.b	#$1, d4
	lsl.l	#$2, d4
	movea.l	#A_ICON_TBL, a0
	adda.l	d4, a0
	move.l	a0, A_SEL_ICON_PTR
	move.l	a4, A_SEL_OBJECT
	move.b	$4(a4), A_CUR_CLASS
	move.b	$5(a4), A_TEXT_SEL_A
	clr.b	A_CURSOR_HOTSPOT
	move.w	$6(a4), A_THE_COMMAND
