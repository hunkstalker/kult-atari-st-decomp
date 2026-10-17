f_0173f2:
	movea.l	s_01a80e, a1
	addq.l	#$4, a1
	movea.l	#A_OBJ_TBL, a2
	movea.l	#s_019cd1, a3
	move.b	A_MODE_FLAG, d0
l_01740c:
	cmp.b	(a3), d0
	beq.w	l_01742a
	addq.l	#$2, a3
	cmpa.l	#s_019cf7, a3
	bne.w	l_01740c
	clr.b	$19(a2)
	clr.w	A_DAT_1ACAE
	bra.b	l_017448
l_01742a:
	move.w	#$a020, A_DAT_1ACAE
	move.w	A_DAT_1AB60, d0
	addi.w	#$5, d0
	move.w	d0, A_DAT_1ACB0
	move.b	$1(a3), $19(a2)
l_017448:
	clr.l	d0
	move.b	$1a(a2), d0
	andi.b	#$000f, d0
	subq.l	#$1, d0
	lsl.l	#$3, d0
	movea.l	A_OBJ_BEGIN, a0
	adda.l	d0, a0
	andi.b	#$007f, $4(a0)
	move.w	#$19, d0
	bsr.w	f_0177bc
	bsr.w	f_017856
	rts	
