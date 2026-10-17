f_012d96:
	move.w	#$0, d1
	bsr.w	f_012a4a
	move.w	#$10, d0
	bsr.w	f_010fec
	adda.l	#$12, a1
	move.w	#$b, d2
	movea.l	#$28, a3
	bsr.w	f_012510
	move.w	#$1, d1
	bsr.w	f_012a4a
	move.w	#$2d, d0
	bsr.w	f_010fec
	move.w	#$b, d2
	movea.l	#$28, a3
	bra.w	f_012510
