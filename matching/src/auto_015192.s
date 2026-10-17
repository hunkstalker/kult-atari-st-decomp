f_015192:
	movea.l	#A_OBJ_TBL, a0
	move.w	#$28, d0
l_01519c:
	andi.b	#$007f, $1(a0)
	addq.l	#$5, a0
	dbra	d0, l_01519c
	clr.b	A_DAT_1ACD3
	rts	
