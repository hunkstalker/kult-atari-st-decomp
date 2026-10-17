f_014966:
	movea.l	#A_TBL_1A6AE, a4
	bsr.w	f_01478a
	bcs.w	l_0149a4
	subq.w	#$2, d3
	bcs.w	l_01498c
l_01497a:
	adda.l	#$a, a4
	bsr.w	f_014798
	dbcs	d3, l_01497a
	bcs.w	l_0149a4
l_01498c:
	move.b	#$0064, A_TEXT_SEL_B
	move.b	#$0001, A_CURSOR_HOTSPOT
	clr.w	A_THE_COMMAND
	rts	
l_0149a4:
	move.w	$6(a4), A_THE_COMMAND
	move.b	$4(a4), A_TEXT_SEL_B
	clr.b	A_CURSOR_HOTSPOT
	clr.l	d0
	move.b	$8(a4), d0
	move.b	d0, A_DAT_1ACE9
	subq.b	#$1, d0
	mulu.w	#$6, d0
	addi.l	#A_LIST_1A8F0, d0
	move.l	d0, A_DAT_1A75E
	rts	
