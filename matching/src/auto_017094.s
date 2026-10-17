f_017094:
	cmpi.b	#$0008, A_DAT_1ACD2
	bne.w	l_0170ac
	btst.b	#$7, A_DAT_1ACFC
	bne.w	l_0170e6
l_0170ac:
	movea.l	A_OBJ_BEGIN, a2
	movea.l	#A_OBJ_TBL, a1
	andi.b	#$00bf, $1(a1)
	andi.b	#$00bf, $ab(a1)
	andi.b	#$00bf, $b0(a1)
l_0170ca:
	move.b	$4(a2), d0
	andi.b	#$007f, d0
	cmpi.b	#$0050, d0
	beq.w	l_0170fa
	addq.l	#$8, a2
	cmpa.l	A_OBJ_END, a2
	bne.w	l_0170ca
l_0170e6:
	clr.b	$aa(a1)
	clr.b	(a1)
	clr.b	$af(a1)
	andi.b	#$0080, A_DAT_1ACFC
	rts	
l_0170fa:
	movea.l	#s_019b46, a2
	move.b	A_DAT_1ACC7, d0
l_017106:
	cmp.b	(a2), d0
	beq.w	l_01711e
	adda.l	#$d, a2
	cmpa.l	#s_019c8b, a2
	bne.w	l_017106
	bra.b	l_0170e6
l_01711e:
	move.l	a2, s_01a80a
	move.b	A_DAT_1ACD2, d0
	cmp.b	(a1), d0
	beq.w	l_017192
	cmp.b	$aa(a1), d0
	beq.w	l_017192
	cmp.b	$af(a1), d0
	beq.w	l_017192
	clr.b	$aa(a1)
	clr.b	(a1)
	clr.b	$af(a1)
	andi.b	#$0080, A_DAT_1ACFC
	cmpi.b	#$0027, A_DAT_1ACD7
	bcs.w	l_01718c
	cmpi.b	#$004e, A_DAT_1ACD7
	bcc.w	f_010768
	move.w	#$a014, A_W_1ACAA
	move.w	A_DAT_1AB60, d0
	addi.w	#$5, d0
	move.w	d0, A_DAT_1ACAC
	ori.b	#$0001, A_DAT_1ACFC
	rts	
l_01718c:
	move.b	A_DAT_1ACD2, (a1)
l_017192:
	move.w	#$a015, A_W_1ACAA
	move.w	A_DAT_1AB60, d0
	addi.w	#$5, d0
	move.w	d0, A_DAT_1ACAC
	ori.b	#$0001, A_DAT_1ACFC
	rts	
