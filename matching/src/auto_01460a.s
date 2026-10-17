f_01460a:
	clr.b	A_DAT_1A572
	move.b	A_CUR_CLASS, d0
	clr.l	d1
	tst.b	A_SKIP_TRANSITION
	bne.w	l_01464e
	andi.b	#$0038, d0
	beq.w	l_014644
	cmpi.b	#$0008, d0
	bne.w	l_01464e
	move.b	A_SEL_1ACC9, d0
	move.b	#$0001, A_DAT_1A572
	bsr.w	f_0141fa
l_014644:
	move.b	A_CUR_CLASS, d1
	andi.b	#$0007, d1
l_01464e:
	move.b	d1, A_DAT_1ACC8
	bsr.w	f_0188ce
	bsr.w	f_01443e
	move.b	A_DAT_1ACD2, A_DAT_1ACFE
	move.b	A_DAT_1ACC8, d1
	beq.w	l_01468a
	ori.b	#$0088, d1
	move.b	#$0001, d2
l_014678:
	cmp.b	$4(a5), d1
	beq.w	l_01468c
	addq.b	#$1, d2
	addq.l	#$8, a5
	cmpa.l	a5, a4
	bne.w	l_014678
l_01468a:
	clr.b	d2
l_01468c:
	move.b	d2, A_SEL_1ACC9
	or.b	d2, A_DAT_1A572
	bsr.w	f_013f86
	clr.w	d1
	move.b	A_DAT_1AD25, d1
	beq.w	l_0146b4
	clr.w	d0
	bsr.w	f_013f56
	clr.b	A_DAT_1AD25
l_0146b4:
	bsr.w	f_016460
	bsr.w	f_017094
	bsr.w	f_0172ca
	bsr.w	f_017480
	bsr.w	f_016582
	clr.b	A_CUR_CLASS
	rts	
