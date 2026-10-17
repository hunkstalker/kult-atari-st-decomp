f_017e3c:
	tst.b	A_DAT_1AD0B
	bne.w	f_010768
	cmpi.b	#$003f, A_DAT_1ACEC
	bcc.w	f_010768
	clr.w	A_DAT_1AC06
	btst.b	#$6, A_1AAB4
	beq.w	l_017e7c
	move.b	#$0038, A_1AAB3
	andi.b	#$000f, A_1AAB4
	move.b	#$0034, A_1AAB6
l_017e7c:
	btst.b	#$5, A_1AAE1
	beq.w	l_017e90
	ori.b	#$0004, A_DAT_1ACF6
l_017e90:
	move.w	A_DAT_1ACB2, d0
	cmp.w	A_DAT_1AB60, d0
	bcc.w	f_010768
	move.w	A_DAT_1AB60, d0
	addi.w	#$1e, d0
	move.w	d0, A_DAT_1ACB2
	movea.l	A_SCRIPT_PTR, a0
	movea.l	#A_OVL_ENTRY, a1
	move.b	(a0)+, A_DAT_1AD05
	cmpa.l	#s_019d0f, a0
	bne.w	l_017ed2
	movea.l	#s_019d03, a0
l_017ed2:
	move.b	(a0), A_DAT_1AD06
	move.l	a0, A_SCRIPT_PTR
	cmpi.b	#$0038, A_DAT_1AD05
	bne.w	l_017f1a
	andi.b	#$00fb, A_DAT_1ACF6
	andi.b	#$001f, $1(a1)
	move.b	#$0037, $3(a1)
	cmpi.b	#$0038, A_1AAB3
	bne.w	l_017f1a
	andi.b	#$001f, A_1AAB4
	move.b	#$0001, A_DAT_1AD07
l_017f1a:
	cmpi.b	#$000c, A_DAT_1AD05
	bne.w	l_017f56
	cmpi.b	#$000a, A_DAT_1AD06
	bne.w	l_017f56
	clr.b	A_DAT_1AD07
	cmpi.b	#$0038, A_1AAB3
	bne.w	l_017f56
	move.b	#$002c, A_DAT_1AD06
	move.l	#s_019d07, A_SCRIPT_PTR
l_017f56:
	move.b	A_DAT_1AD06, (a1)
	tst.b	A_DAT_1AD07
	beq.w	l_01803c
	move.b	A_DAT_1AD06, d0
	move.b	d0, A_1AAB3
	move.b	d0, A_1AAD6
	move.b	d0, A_1AADB
	move.b	A_DAT_1ACD2, d0
	cmp.b	A_DAT_1AD05, d0
	beq.w	l_0180aa
	cmp.b	A_DAT_1AD06, d0
	bne.w	f_010768
	bsr.w	f_01060a
	bsr.w	f_016514
	movea.l	#s_019d12, a1
	move.b	#$006e, d0
	bsr.w	f_0177bc
	bsr.w	f_017856
	movea.l	#s_019d15, a1
	move.b	#$0064, d0
	bsr.w	f_0177bc
	bne.w	l_017fec
	bsr.w	f_017856
	movea.l	#s_019d15, a1
	move.b	#$0041, d0
	bsr.w	f_0177bc
	bsr.w	f_017856
	movea.l	#s_019d15, a1
	move.b	#$0069, d0
	bsr.w	f_0177bc
l_017fe8:
	bsr.w	f_017856
l_017fec:
	bsr.w	f_016582
	bsr.w	f_0121c6
	bsr.w	f_016556
	bsr.w	f_010526
	tst.b	A_DAT_1ACF7
	beq.w	l_018010
	move.w	#$c1fd, A_DAT_1AC06
	rts	
l_018010:
	btst.b	#$5, A_1AAE1
	beq.w	l_018026
	move.w	#$c1e5, A_DAT_1AC06
	rts	
l_018026:
	cmpi.b	#$002c, A_DAT_1ACD2
	bne.w	f_010768
	move.w	#$c060, A_DAT_1AC06
	rts	
l_01803c:
	btst.b	#$6, $1(a1)
	bne.w	f_010768
	move.b	A_DAT_1ACD2, d0
	cmp.b	A_DAT_1AD05, d0
	beq.w	l_01807a
	cmp.b	A_DAT_1AD06, d0
	bne.w	f_010768
	bsr.w	f_01060a
	bsr.w	f_016514
	move.b	#$006e, d0
	bsr.w	f_0177bc
	movea.l	#s_019d0f, a1
	bra.w	l_017fe8
l_01807a:
	bsr.w	f_01060a
	bsr.w	f_016514
	move.b	#$006e, d0
	bsr.w	f_0177bc
	movea.l	A_SEL_OBJECT, a1
	andi.b	#$007f, $4(a1)
	movea.l	#s_019d18, a1
	bsr.w	f_017856
	bsr.w	f_016556
	bsr.w	f_010526
	rts	
l_0180aa:
	bsr.w	f_01060a
	bsr.w	f_016514
	move.b	#$006e, d0
	bsr.w	f_0177bc
	movea.l	A_SEL_OBJECT, a1
	andi.b	#$007f, $4(a1)
	movea.l	#s_019d1b, a1
	move.b	#$0041, d0
	bsr.w	f_0177bc
	movea.l	A_SEL_OBJECT, a1
	andi.b	#$007f, $4(a1)
	movea.l	#s_019d1e, a1
	move.b	#$0064, d0
	bsr.w	f_0177bc
	movea.l	A_SEL_OBJECT, a1
	andi.b	#$007f, $4(a1)
	movea.l	#s_019d1e, a1
	move.b	#$0069, d0
	bsr.w	f_0177bc
	movea.l	A_SEL_OBJECT, a1
	andi.b	#$007f, $4(a1)
	movea.l	#s_019d1e, a1
	bsr.w	f_017856
	bsr.w	f_016556
	bsr.w	f_010526
	rts	
