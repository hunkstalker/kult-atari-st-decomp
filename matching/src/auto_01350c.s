f_01350c:
	clr.l	d0
	move.b	$2(a6), d0
	rol.w	#$8, d0
	move.b	$1(a6), d0
	movea.l	#A_DAT_1D402, a6
	adda.l	d0, a6
	rts	
