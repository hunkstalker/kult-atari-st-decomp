f_0147ce:
	movea.l	#s_019b06, a4
	move.w	#$1, d2
l_0147d8:
	bsr.w	f_01478a
	bcs.w	l_01480c
	move.w	#$6, d3
l_0147e4:
	addq.l	#$4, a4
	addq.w	#$1, d2
	bsr.w	f_014798
	dbcs	d3, l_0147e4
	bcs.w	l_01480c
	move.b	#$0064, A_TEXT_SEL_B
	move.b	#$0001, A_CURSOR_HOTSPOT
	clr.w	A_THE_COMMAND
	rts	
l_01480c:
	ori.w	#$a000, d2
	move.w	d2, A_THE_COMMAND
	addq.b	#$2, d2
	cmpi.b	#$0003, d2
	bne.w	l_014824
	move.b	#$0065, d2
l_014824:
	move.b	d2, A_TEXT_SEL_B
	clr.b	A_CURSOR_HOTSPOT
	rts	
