f_018c8e:
	movea.l	#A_LIST_1A8F0, a0
	move.w	#$3e, d0
l_018c98:
	cmpi.b	#$0080, (a0)
	bne.w	l_018ca2
	clr.b	(a0)
l_018ca2:
	addq.l	#$6, a0
	dbra	d0, l_018c98
	addq.l	#$1, a6
	clr.b	A_DAT_1ACF7
	rts	
