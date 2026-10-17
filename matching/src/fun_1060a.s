f_01060a:
	movea.l	A_CURSOR_SAVE_DEST,a0
	movea.l	#A_CURSOR_SAVE_BUF,a1
	move.w	#$f,d1
l_01061a:
	move.w	#3,d2
l_01061e:
	move.l	(a1)+,(a0)+
	dbra	d2,l_01061e
	adda.l	#$90,a0
	dbra	d1,l_01061a
	rts
