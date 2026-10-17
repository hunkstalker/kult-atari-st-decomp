f_01680c:
	move.l	#$6, d0
	bsr.w	f_014a98
	move.b	#$00b8, d2
	move.b	#$0090, d3
	bsr.w	f_0167be
	movea.l	A_ELEM_CLASS, a0
	rts	
