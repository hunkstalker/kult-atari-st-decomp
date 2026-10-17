f_018cfc:
	move.l	a6, -(a7)
	bsr.w	f_016556
	movea.l	A_OBJ_BEGIN, a0
	subi.b	#$0005, $32(a0)
	subi.b	#$0005, $33(a0)
	bsr.w	f_016460
	bsr.w	f_016582
	bsr.w	f_0121c6
	movea.l	(a7)+, a6
	addq.l	#$1, a6
	rts	
