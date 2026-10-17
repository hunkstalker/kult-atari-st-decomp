f_014f5e:
	move.b	#$0002, d0
	bsr.w	f_014f24
	bsr.w	f_016310
	move.b	#$00ff, A_CUR_CLASS
	rts	
