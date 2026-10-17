f_017c42:
	bsr.w	f_016556
	move.w	#$be, d0
	bsr.w	f_0177bc
	move.b	#$0001, s_01ad26
	bsr.w	f_0176c0
	clr.b	s_01ad26
	clr.b	s_01ab30
	move.w	s_01aa70, d0
	bsr.w	f_0177bc
	movea.l	A_OBJ_BEGIN, a0
	move.b	#$0053, $2c(a0)
	movea.l	A_SEL_OBJECT, a0
	ori.b	#$0080, $4(a0)
	movea.l	A_ELEM_CLASS, a0
	andi.b	#$00bf, $1(a0)
	move.b	A_DAT_1ACD2, (a0)
	bsr.w	f_016582
	bsr.w	f_0121c6
	rts	
