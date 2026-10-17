f_013522:
	movea.l	A_CALL_STACK, a1
	clr.l	d0
	move.b	$2(a6), d0
	rol.w	#$8, d0
	move.b	$1(a6), d0
	adda.l	#$3, a6
	move.l	a6, -(a1)
	move.l	A_SCRIPT_END, -(a1)
	move.l	a1, A_CALL_STACK
	movea.l	#A_DAT_1D402, a6
	adda.l	d0, a6
	rts	
