f_015888:
	move.l	A_SCRIPT_END, s_01a4be
	move.l	a6, s_01a4c2
	move.b	#$00ff, s_01a575
l_0158a0:
	bsr.w	f_01566a
	cmpi.w	#$ffff, A_THE_COMMAND
	beq.w	l_015922
	move.w	A_THE_COMMAND, d0
	andi.w	#$f000, d0
	cmpi.w	#$c000, d0
	beq.w	l_01592e
	cmpi.w	#$a000, d0
	beq.w	l_01592e
	bsr.w	f_0103ae
	addq.b	#$1, A_DAT_1ACE7
	move.w	f_019316, d0
	cmpi.w	#$2f3c, d0
	bne.w	l_0158a0
	tst.b	A_DAT_1AD09
	bne.w	l_01590a
	move.b	A_DAT_1ACF2, d0
	cmp.b	A_DAT_1ACE7, d0
	bcc.w	l_01590a
	move.w	A_DAT_1ABF8, A_THE_COMMAND
	bne.w	l_01592e
l_01590a:
	movea.l	s_01a4c2, a6
	subq.b	#$1, A_DAT_1ACE8
	bne.w	l_0158a0
	bsr.w	f_015192
	bra.w	l_0158a0
l_015922:
	move.l	s_01a4be, A_SCRIPT_END
	rts	
l_01592e:
	addq.l	#$4, a7
	bra.w	f_0103ae
