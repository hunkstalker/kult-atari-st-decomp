f_013594:
	move.b	A_DAT_1ACD4, d0
l_01359a:
	cmp.b	A_DAT_1ACD4, d0
	beq.w	l_01359a
	rts	
	move.w	#$25, -(a7)
	trap	#$e
	addq.l	#$2, a7
	tst.w	A_DAT_1A4D2
	bne.w	l_01018e
	rts	
