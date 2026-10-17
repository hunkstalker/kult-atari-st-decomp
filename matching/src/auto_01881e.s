f_01881e:
	move.w	#$f2, d4
	bsr.w	f_018f8e
	clr.w	d0
	move.w	#$62, d1
	bsr.w	f_013f56
	move.l	#$5500, d0
	movea.l	A_SCREEN_PTR_A, a2
	movea.l	A_SCREEN_PTR_B, a3
	adda.l	d0, a2
	adda.l	d0, a3
	move.w	#$3b, d3
l_01884a:
	move.w	#$27, d2
l_01884e:
	move.l	(a3)+, (a2)+
	dbra	d2, l_01884e
	bsr.w	f_013594
	suba.l	#$140, a3
	suba.l	#$140, a2
	dbra	d3, l_01884a
	movea.l	#s_01a782, a2
	movea.l	(a2), a1
	movea.l	A_OBJ_BEGIN, a5
	adda.l	#$18, a5
	bsr.w	f_0164a4
	addq.l	#$1, a6
	bsr.w	f_018fa4
	rts	
