f_03aa8a:
	move.l	d0, -(a7)
	lea.l	s_03ae7c, a5
	btst.b	#$f, d2
	bne.w	l_03aaa0
	move.l	d2, d6
	add.b	d7, d6
	bra.b	l_03aaae
l_03aaa0:
	move.l	d7, d6
	lsl.w	#$1, d6
	add.b	d2, d6
	move.w	d0, (a5, d6.w)
	move.l	(a7)+, d0
	rts	
l_03aaae:
	move.b	d0, (a5, d6.w)
	move.l	(a7)+, d0
	rts	
