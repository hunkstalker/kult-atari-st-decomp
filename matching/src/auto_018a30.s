f_018a30:
	bsr.w	f_018a10
	move.w	#$4, d5
	movea.l	A_SCREEN_PTR_A, a5
	movea.l	a5, a4
	suba.l	#$500, a4
	move.w	#$13f, d4
	movea.l	a4, a3
l_018a4c:
	clr.l	(a3)+
	dbra	d4, l_018a4c
l_018a52:
	move.w	#$ffff, -(a7)
	move.l	a4, -(a7)
	move.l	a4, -(a7)
	move.w	#$5, -(a7)
	trap	#$e
	adda.l	#$c, a7
	bsr.w	f_013594
	move.w	#$ffff, -(a7)
	move.l	a5, -(a7)
	move.l	a5, -(a7)
	move.w	#$5, -(a7)
	trap	#$e
	adda.l	#$c, a7
	bsr.w	f_013594
	dbra	d5, l_018a52
	adda.l	#$7b00, a5
	move.w	#$7f, d4
l_018a90:
	move.l	(a5)+, (a4)+
	dbra	d4, l_018a90
	rts	
