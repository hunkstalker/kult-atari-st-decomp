f_016088:
	addq.l	#$1, a6
	bsr.w	f_015f6c
	movem.l	d0/a0, -(a7)
	bsr.w	f_01606e
	movem.l	(a7)+, d0/a0
	btst.b	#$1f, d0
	bne.w	l_0160a6
	move.b	d6, (a0)
	rts	
l_0160a6:
	move.w	d6, (a0)
	rts	
