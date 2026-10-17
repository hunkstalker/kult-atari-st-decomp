f_018128:
	movea.l	A_ELEM_CLASS, a1
	move.b	$3(a1), d0
	andi.b	#$0038, d0
	cmpi.b	#$0030, d0
	bne.w	l_01816a
	andi.b	#$00e7, $3(a1)
	clr.l	d0
	move.b	A_CLASS_IDX, d0
	subi.b	#$000a, d0
	mulu.w	#$6, d0
	movea.l	#s_01a9d4, a0
	adda.l	d0, a0
	move.l	a0, A_DAT_1A75E
	move.l	a6, -(a7)
	bsr.w	f_0184d6
	movea.l	(a7)+, a6
l_01816a:
	addq.l	#$1, a6
	rts	
