f_016210:
	clr.l	d0
	addq.b	#$1, A_DAT_1A579
	move.b	A_DAT_1A579, d0
	movea.l	#A_TBL_2741E, a0
	move.b	(a0, d0.l), d0
	move.b	d0, A_DAT_1ACD7
	rts	
