f_019438:
	movea.w	#$8604, a0
	move.w	#$86, $2(a0)
	bsr.w	f_019474
	move.w	#$4f, (a0)
	bsr.w	f_019474
	move.w	#$80, $2(a0)
	bsr.w	f_019474
	move.w	#$14, (a0)
	bsr.w	f_019462
	rts	
