f_01606e:
	bsr.w	f_015f6c
	move.w	d0, d6
l_016074:
	move.b	(a6)+, d7
	btst.b	#$7, d7
	bne.w	f_010768
	bsr.w	f_015f6c
	bsr.w	f_015fd4
	bra.b	l_016074
