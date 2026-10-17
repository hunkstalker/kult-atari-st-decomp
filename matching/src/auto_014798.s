f_014798:
	cmp.b	(a4), d0
	bcs.w	l_0147bc
	cmp.b	$1(a4), d0
	bcc.w	l_0147bc
	cmp.b	$2(a4), d1
	bcs.w	l_0147bc
	cmp.b	$3(a4), d1
	bcc.w	l_0147bc
	ori.b	#$0001, ccr
	rts	
l_0147bc:
	andi.b	#$00fe, ccr
	rts	
