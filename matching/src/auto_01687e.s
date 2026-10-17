f_01687e:
	addq.l	#$1, a6
	clr.w	d4
	move.b	(a6), d4
	movea.l	#s_03c534, a5
	bsr.w	f_010fb4
	move.l	a6, -(a7)
	movea.l	#s_01996c, a6
	bsr.w	f_010b6c
	movea.l	(a7)+, a6
	addq.l	#$1, a6
	rts	
