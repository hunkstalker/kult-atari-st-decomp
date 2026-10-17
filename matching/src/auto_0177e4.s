f_0177e4:
	move.l	a0, A_SEL_OBJECT
	move.b	d2, A_SEL_1ACC9
	andi.l	#$ff, d2
	subq.b	#$1, d2
	lsl.l	#$2, d2
	movea.l	#A_ICON_TBL, a0
	adda.l	d2, a0
	move.l	a0, A_SEL_ICON_PTR
	clr.b	d0
	rts	
