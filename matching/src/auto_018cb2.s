f_018cb2:
	addq.l	#$1, a6
	movea.l	#s_01a95c, a0
	move.w	#$3, d0
	bsr.w	f_018ce0
	movea.l	#s_01a9d4, a0
	clr.b	A_DAT_1ACF7
	move.w	#$d, d0
	bsr.w	f_018ce0
	movea.l	#s_01aa3a, a0
	move.w	#$1, d0
