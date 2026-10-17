f_0172ca:
	cmpi.b	#$003b, A_DAT_1ACD2
	bne.w	l_0172ea
	tst.b	A_DAT_1AD14
	bne.w	l_0172ea
	move.b	#$003b, s_01aa8b
	rts	
l_0172ea:
	movea.l	A_OBJ_BEGIN, a2
	movea.l	#A_OBJ_TBL, a1
	andi.b	#$00bf, $1a(a1)
l_0172fc:
	move.b	$4(a2), d0
	andi.b	#$007f, d0
	cmpi.b	#$0051, d0
	beq.w	l_01731e
	addq.l	#$8, a2
	cmpa.l	A_OBJ_END, a2
	bne.w	l_0172fc
l_017318:
	clr.b	$19(a1)
	rts	
l_01731e:
	movea.l	#s_019c8b, a2
	move.b	A_DAT_1ACC7, d0
l_01732a:
	cmp.b	(a2), d0
	beq.w	l_017342
	adda.l	#$7, a2
	cmpa.l	#s_019cd1, a2
	bne.w	l_01732a
	bra.b	l_017318
l_017342:
	move.l	a2, s_01a80e
	move.b	A_DAT_1ACD2, d0
	cmp.b	$19(a1), d0
	beq.w	l_017394
	clr.b	$19(a1)
	cmpi.b	#$00d9, A_DAT_1ACD7
	bcc.w	l_01738c
	cmpi.b	#$00b2, A_DAT_1ACD7
	bcs.w	f_010768
	move.w	#$a01e, A_DAT_1ACAE
	move.w	A_DAT_1AB60, d0
	addi.w	#$5, d0
	move.w	d0, A_DAT_1ACB0
	rts	
l_01738c:
	move.b	A_DAT_1ACD2, $19(a1)
l_017394:
	move.w	#$a01f, A_DAT_1ACAE
	move.w	A_DAT_1AB60, d0
	addi.w	#$5, d0
	move.w	d0, A_DAT_1ACB0
	rts	
