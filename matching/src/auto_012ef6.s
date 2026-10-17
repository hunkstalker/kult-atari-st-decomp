f_012ef6:
	movea.l	a0, a3
	suba.l	#$8000, a3
	ror.w	d7, d4
	move.w	d4, d5
	not.w	d5
	move.w	(a3)+, d7
	and.w	d4, d7
	and.w	d5, (a0)
	or.w	d7, (a0)+
	move.w	(a3)+, d7
	and.w	d4, d7
	and.w	d5, (a0)
	or.w	d7, (a0)+
	move.w	(a3)+, d7
	and.w	d4, d7
	and.w	d5, (a0)
	or.w	d7, (a0)+
	move.w	(a3)+, d7
	and.w	d4, d7
	and.w	d5, (a0)
	or.w	d7, (a0)+
	swap	d7
	rts	
