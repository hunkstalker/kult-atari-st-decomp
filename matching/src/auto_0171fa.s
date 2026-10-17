f_0171fa:
	movea.l	s_01a80a, a1
	addq.l	#$4, a1
	movea.l	#A_OBJ_TBL, a2
	tst.b	(a2)
	bne.w	l_01723c
	addq.l	#$3, a1
	adda.l	#$aa, a2
	tst.b	(a2)
	bne.w	l_01723c
	addq.l	#$3, a1
	adda.l	#$5, a2
	clr.b	(a2)
	ori.b	#$0080, A_DAT_1ACFC
	move.b	$1(a2), d0
	movea.l	#A_OBJ_TBL, a2
	move.b	d0, $1(a2)
l_01723c:
	movea.l	#s_019cd1, a3
	move.b	A_MODE_FLAG, d0
l_017248:
	cmp.b	(a3), d0
	beq.w	l_017264
	addq.l	#$2, a3
	cmpa.l	#s_019cf7, a3
	bne.w	l_017248
	clr.b	(a2)
	clr.w	A_W_1ACAA
	bra.b	l_017280
l_017264:
	move.w	#$a016, A_W_1ACAA
	move.w	A_DAT_1AB60, d0
	addi.w	#$5, d0
	move.w	d0, A_DAT_1ACAC
	move.b	$1(a3), (a2)
l_017280:
	clr.l	d0
	move.b	$1(a2), d0
	andi.b	#$000f, d0
	subq.l	#$1, d0
	lsl.l	#$3, d0
	movea.l	A_OBJ_BEGIN, a0
	adda.l	d0, a0
	andi.b	#$007f, $4(a0)
	move.l	a2, A_PTR_1A806
	clr.b	d0
	bsr.w	f_0177bc
	bsr.w	f_017856
	bsr.w	f_018fa4
	andi.b	#$0080, A_DAT_1ACFC
	rts	
