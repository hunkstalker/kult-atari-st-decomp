f_01296c:
	clr.l	d4
	move.b	(a5)+, d4
	mulu.w	#$a, d4
	movea.l	#A_ELEM_TBL_1A252, a2
	adda.l	d4, a2
	movea.l	#A_ELEM_BUILD, a1
	clr.w	d2
	clr.w	d3
	move.b	(a2)+, d2
	move.b	(a2)+, d3
	clr.l	d4
	move.b	d2, d4
	lsl.l	#$1, d4
	move.l	d4, A_DAT_1A534
	move.b	d3, (a1)+
	move.b	d2, (a1)+
	move.w	(a2)+, d4
	subq.w	#$1, d2
	move.w	d2, d5
l_0129a0:
	move.w	d4, (a1)+
	dbra	d5, l_0129a0
	move.w	(a2)+, d6
	subq.w	#$2, d2
	subq.w	#$3, d3
l_0129ac:
	move.w	(a2), (a1)+
	move.w	d2, d5
l_0129b0:
	move.w	d6, (a1)+
	dbra	d5, l_0129b0
	move.w	$2(a2), (a1)+
	dbra	d3, l_0129ac
	addq.w	#$2, d2
l_0129c0:
	move.w	d4, (a1)+
	dbra	d2, l_0129c0
	rts	
