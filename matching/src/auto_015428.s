f_015428:
	move.b	#$0004, d0
	bsr.w	f_014f24
	move.w	s_01ac04, d4
	tst.b	A_DAT_1AD09
	bne.w	l_015462
	move.w	A_DAT_1AB56, d4
	cmpi.b	#$003f, A_DAT_1ACEC
	bcs.w	l_015462
	cmpi.b	#$0016, A_DAT_1ACD2
	bcc.w	l_015462
	move.w	#$113, d4
l_015462:
	btst.b	#$f, d4
	bne.w	l_015488
	movea.l	#s_03c534, a5
	bsr.w	f_010fb4
	movea.l	#s_01996c, a6
	bsr.w	f_010b6c
	bsr.w	f_01228a
	bsr.w	f_01232e
	rts	
l_015488:
	move.w	d4, A_THE_COMMAND
	bra.w	f_0103ae
