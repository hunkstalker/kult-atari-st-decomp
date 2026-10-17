f_016230:
	clr.l	d0
	addq.b	#$1, A_DAT_1A579
	move.b	A_DAT_1A579, d0
	movea.l	#A_TBL_2741E, a0
	adda.l	d0, a0
	move.b	(a0), d0
	lsl.w	#$8, d0
	move.b	$1(a0), d0
	rts	
