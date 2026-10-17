f_014926:
	move.w	#$28, d0
	movea.l	#A_OBJ_TBL, a0
	move.b	#$0001, d2
	move.b	A_SEL_1ACC9, d4
l_01493a:
	move.b	$1(a0), d1
	andi.b	#$000f, d1
	cmp.b	d4, d1
	beq.w	l_014958
	addq.l	#$5, a0
	addq.b	#$1, d2
	dbra	d0, l_01493a
	clr.b	A_CLASS_IDX
	rts	
l_014958:
	move.l	a0, A_ELEM_CLASS
	move.b	d2, A_CLASS_IDX
	rts	
