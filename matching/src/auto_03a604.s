f_03a604:
	lea.l	$fffffa00.l, a0
	move.b	#$0020, $13(a0)
	move.b	#$0020, $7(a0)
	move.b	#$0004, $19(a0)
	move.b	#$00aa, $1f(a0)
	move.l	#s_03a872, $134.l
	rts	
