f_014f24:
	move.b	A_DAT_1AD20, d2
	cmp.b	d0, d2
	bcs.w	l_014f4a
	move.b	d2, d1
	andi.b	#$00f0, d1
	sub.b	d0, d2
	move.b	d2, A_DAT_1AD20
	andi.b	#$00f0, d2
	cmp.b	d2, d1
	bne.w	l_014f4c
	rts	
l_014f4a:
	addq.l	#$4, a7
l_014f4c:
	move.w	#$4a, d0
	move.w	#$47, d2
	move.w	#$44, d1
	bsr.w	f_0159e2
	rts	
