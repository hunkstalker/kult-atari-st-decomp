f_01870a:
	bsr.w	f_016210
	clr.w	d4
	move.b	d0, d4
	andi.b	#$0007, d4
	addi.w	#$149, d4
	cmpi.w	#$14f, d4
	bcc.w	f_01870a
	movea.l	#s_03c534, a5
	bsr.w	f_010fb4
	movea.l	#s_019974, a6
	bsr.w	f_010b6c
	bsr.w	f_01228a
	bsr.w	f_01232e
	rts	
