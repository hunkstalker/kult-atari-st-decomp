f_0179a2:
	move.l	a6, -(a7)
	move.w	#$9148, A_THE_COMMAND
	movea.l	A_ELEM_CLASS, a0
	move.b	$3(a0), d0
	andi.b	#$00f8, d0
	cmpi.b	#$0030, d0
	bne.w	l_017a10
	move.b	$3(a0), d0
	andi.b	#$00e7, $3(a0)
	clr.l	d0
	move.b	A_CLASS_IDX, d0
	subi.b	#$000a, d0
	mulu.w	#$6, d0
	movea.l	#s_01a9d4, a0
	adda.l	d0, a0
	move.l	a0, A_DAT_1A75E
	addq.b	#$1, s_01ad01
	bsr.w	f_0184cc
	move.w	#$9147, A_THE_COMMAND
	bsr.w	f_0103ae
	move.b	#$0001, s_01ad2e
	move.w	#$9032, A_THE_COMMAND
l_017a10:
	bsr.w	f_0103ae
	movea.l	(a7)+, a6
	addq.l	#$1, a6
	rts	
