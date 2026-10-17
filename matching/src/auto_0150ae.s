f_0150ae:
	move.b	#$0002, d0
	bsr.w	f_014f24
	tst.b	A_DAT_1AD09
	bne.w	l_0150fe
	bsr.w	f_0164d4
	bsr.w	f_01680c
	tst.b	A_SEL_1ACC9
	beq.w	l_015160
	move.w	#$18, d4
	move.b	#$0032, d1
	bsr.w	f_018f7a
	movea.l	#A_DAT_1AB62, a0
	clr.l	d0
	move.b	A_SEL_1ACC9, d0
	subq.b	#$1, d0
	mulu.w	#$a, d0
	move.w	$2(a0, d0.l), A_THE_COMMAND
	bne.w	l_01513a
l_0150fe:
	cmpi.b	#$0012, A_DAT_1AD09
	beq.w	l_015174
	movea.l	A_ELEM_CLASS, a0
	ori.b	#$0080, $1(a0)
	move.b	A_SEL_1ACC9, A_DAT_1ACD3
	move.b	#$0002, A_DAT_1ACE8
	move.w	#$0, A_THE_COMMAND
	tst.b	A_DAT_1AD09
	bne.w	l_015186
l_01513a:
	clr.w	d0
	clr.w	d2
	movea.l	A_SEL_OBJECT, a0
	move.b	(a0), d0
	move.b	$2(a0), d2
	subi.w	#$a, d2
	addq.w	#$2, d0
	move.w	#$27, d1
	bsr.w	f_0159e2
	bsr.w	f_0164f6
	bra.w	f_0103ae
l_015160:
	move.w	A_DAT_1AB5C, A_THE_COMMAND
	clr.b	A_DAT_1ACD3
	bra.w	f_0103ae
l_015174:
	move.b	#$0001, A_DAT_1ACD3
	move.b	#$0002, A_DAT_1ACE8
	rts	
l_015186:
	move.w	#$90aa, A_THE_COMMAND
	bra.w	f_0103ae
