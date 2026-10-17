f_01695a:
	movea.l	#s_019970, a6
	movea.l	A_SEL_OBJECT, a0
	cmpi.b	#$0023, (a0)
	bcc.w	l_01697c
	move.b	$1(a0), d0
	move.b	#$00f4, $3(a6)
	bra.w	l_016988
l_01697c:
	move.b	(a0), d0
	subi.b	#$0014, d0
	move.b	#$00d4, $3(a6)
l_016988:
	move.b	$2(a0), d1
	subi.l	#$28, d1
	move.b	d1, $2(a6)
	move.b	d0, $1(a6)
	rts	
