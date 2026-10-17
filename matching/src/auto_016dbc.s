f_016dbc:
	addq.l	#$1, a6
	movea.l	#A_TEXT_TABLE, a1
	bsr.w	f_010fec
	bsr.w	f_010f8e
	clr.w	d2
	clr.w	d3
	move.b	(a1)+, d3
	move.b	(a1)+, d2
	clr.l	d4
	move.w	d2, d4
	lsl.l	#$1, d4
	move.l	d4, A_DAT_1A534
	bsr.w	f_0126e0
	movea.l	#$0, a5
	rts	
