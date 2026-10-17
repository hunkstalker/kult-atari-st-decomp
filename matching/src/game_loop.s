f_0101be:
	bsr.w	f_0166da
	jsr	f_018dc0
	bsr.w	f_017e3c
	jsr	f_018740
	bsr.w	f_01627a
	bsr.w	f_013698
	clr.w	A_THE_COMMAND
	movea.l	#A_DAT_1AB40,a4
	bsr.w	f_01478a
	bcc.w	l_010206
	move.l	#1,d0
	bsr.w	f_014a98
	move.b	#$64,A_TEXT_SEL_B
	bsr.w	f_014832
	bra.b	l_010218
l_010206:
	clr.l	d0
	bsr.w	f_014a98
	move.b	#$75,A_TEXT_SEL_A
	bsr.w	f_0147ce
l_010218:
	move.b	A_TEXT_SEL_A,d0
	cmp.b	A_1AB44,d0
	beq.w	l_01022c
	bsr.w	f_0109fe
l_01022c:
	move.b	A_TEXT_SEL_B,d0
	cmp.b	A_1AB47,d0
	beq.w	l_010240
	bsr.w	f_010a88
l_010240:
	bsr.w	f_01031c
	btst.b	#2,A_INPUT_BUTTONS
	beq.w	l_01025a
	tst.w	A_THE_COMMAND
	bne.w	l_0102da
l_01025a:
	move.b	A_DAT_1ACF2,d0
	cmp.b	A_DAT_1ACE7,d0
	bcc.w	l_010278
	move.w	A_DAT_1ABF8,A_THE_COMMAND
	bne.w	l_0102cc
l_010278:
	tst.b	A_DAT_1AD0B
	bne.w	l_010310
	move.w	A_DAT_1AC06,A_THE_COMMAND
	bne.w	l_0102cc
	move.w	A_DAT_1ACAC,d0
	cmp.w	A_DAT_1AB60,d0
	bcc.w	l_0102ae
	move.w	A_DAT_1ACAA,A_THE_COMMAND
	bne.w	l_0102cc
l_0102ae:
	move.w	A_DAT_1ACB0,d0
	cmp.w	A_DAT_1AB60,d0
	bcc.w	l_010310
	move.w	A_DAT_1ACAE,A_THE_COMMAND
	beq.w	l_010310
l_0102cc:
	bsr.w	f_01060a
	bsr.w	f_016514
	bsr.w	f_0103ae
	bra.b	l_010304
l_0102da:
	bsr.w	f_01060a
	bsr.w	f_016514
	bsr.w	f_0103a8
	addq.b	#1,A_DAT_1ACE7
	tst.b	A_DAT_1ACD3
	beq.w	l_010304
	subq.b	#1,A_DAT_1ACE8
	bne.w	l_010304
	bsr.w	f_015192
l_010304:
	bsr.w	f_016556
	bsr.w	f_010522
	bsr.w	f_0166ec
l_010310:
	tst.w	A_DAT_1A4D2
	beq.w	f_0101be
	rts
