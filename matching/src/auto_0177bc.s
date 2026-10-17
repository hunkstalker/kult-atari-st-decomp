f_0177bc:
	andi.l	#$ff, d0
	movea.l	#A_OBJ_TBL, a0
	adda.l	d0, a0
	move.l	a0, A_ELEM_CLASS
	move.b	$3(a0), d0
	andi.b	#$0007, d0
	ori.b	#$0010, d0
	bsr.w	f_01778e
	bne.w	f_010768
