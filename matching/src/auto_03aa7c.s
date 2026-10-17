f_03aa7c:
	move.b	d6, (a5)
	move.b	d0, $2(a5)
	cmp.b	(a5), d0
	bne.w	f_03aa7c
	rts	
