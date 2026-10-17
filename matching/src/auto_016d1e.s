f_016d1e:
	move.b	A_DAT_1ACD4, d0
l_016d24:
	cmp.b	A_DAT_1ACD4, d0
	beq.w	l_016d24
	btst.b	#$0, A_DAT_1ACD4
	bne.w	f_016d1e
	rts	
