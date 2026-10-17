f_0184d6:
	move.b	#$0040, d4
	move.w	#$2b, d5
l_0184de:
	addq.l	#$1, a6
	move.l	d4, -(a7)
	move.l	(a7)+, d4
	movea.l	A_DAT_1A75E, a0
	move.b	$2(a0), d3
	bsr.w	f_018538
	move.b	d4, (a0)
	move.b	A_DAT_1ACD2, $1(a0)
	move.l	d5, -(a7)
	bsr.w	f_0164d4
	move.l	(a7)+, d2
	move.w	#$2c, d0
	move.w	#$29, d1
	bsr.w	f_0159e2
	bsr.w	f_01857c
	bsr.w	f_0164f6
	rts	
