f_014bdc:
	movea.l	#A_LIST_1A8F0, a0
	move.w	#$3e, d0
l_014be6:
	cmpi.b	#$0081, (a0)
	bne.w	l_014bf2
	move.b	#$0080, (a0)
l_014bf2:
	addq.l	#$6, a0
	dbra	d0, l_014be6
	rts	
