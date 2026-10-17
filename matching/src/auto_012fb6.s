f_012fb6:
	move.w	#$8000, d4
	ror.w	d7, d4
	move.w	d4, d5
	not.w	d5
	ror.w	d7, d0
	move.w	d0, d1
	and.w	d4, d1
	and.w	d5, (a0)
	or.w	d1, (a0)+
	rol.w	#$4, d0
	move.w	d0, d1
	and.w	d4, d1
	and.w	d5, (a0)
	or.w	d1, (a0)+
	rol.w	#$4, d0
	move.w	d0, d1
	and.w	d4, d1
	and.w	d5, (a0)
	or.w	d1, (a0)+
	rol.w	#$4, d0
	move.w	d0, d1
	and.w	d4, d1
	and.w	d5, (a0)
	or.w	d1, (a0)+
	rts	
