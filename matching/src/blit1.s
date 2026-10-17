f_011196:
	ror.b	#4,d0
	ror.w	#8,d0
	ror.b	#4,d0
	move.w	#$f,d2
l_0111a0:
	roxr.w	#1,d0
	roxl.w	#1,d1
	dbra	d2,l_0111a0
	move.w	d1,d0
	rts
f_0111ac:
	subq.w	#1,d3
	move.w	#5,d2
	lsl.w	#2,d1
	subq.w	#1,d1
