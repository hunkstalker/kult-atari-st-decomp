f_016460:
	movea.l	A_OBJ_BEGIN, a5
	movea.l	#f_03a556, a1
	movea.l	#A_ICON_TBL, a2
	move.w	#$f, d0
l_016476:
	clr.l	(a2)+
	dbra	d0, l_016476
	movea.l	#A_ICON_TBL, a2
l_016482:
	btst.b	#$6, $4(a5)
	beq.w	l_016490
	bsr.w	f_0164a4
l_016490:
	addq.l	#$4, a2
	adda.l	#$8, a5
	cmpa.l	A_OBJ_END, a5
	bne.w	l_016482
	rts	
