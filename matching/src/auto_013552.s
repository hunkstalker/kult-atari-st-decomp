f_013552:
	movea.l	A_CALL_STACK, a1
	move.l	(a1)+, A_SCRIPT_END
	movea.l	(a1)+, a6
	move.l	a1, A_CALL_STACK
	rts	
