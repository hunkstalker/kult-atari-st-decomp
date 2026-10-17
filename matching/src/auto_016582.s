f_016582:
	movea.l	A_OBJ_BEGIN, a2
l_016588:
	move.b	$4(a2), d1
	andi.b	#$0038, d1
	cmpi.b	#$0010, d1
	bne.w	l_01659e
	andi.b	#$007f, $4(a2)
l_01659e:
	addq.l	#$8, a2
	cmpa.l	A_OBJ_END, a2
	bne.w	l_016588
	move.w	#$28, d6
	movea.l	#A_OBJ_TBL, a1
l_0165b4:
	andi.b	#$00f0, $1(a1)
	move.b	A_DAT_1ACD2, d0
	cmp.b	(a1), d0
	bne.w	l_016626
	btst.b	#$6, $1(a1)
	bne.w	l_016626
	movea.l	A_OBJ_BEGIN, a2
	move.b	$3(a1), d1
	andi.b	#$0007, d1
	ori.b	#$0010, d1
	move.b	#$0001, d3
l_0165e6:
	move.b	$4(a2), d2
	andi.b	#$00bf, d2
	cmp.b	d2, d1
	beq.w	l_016608
	adda.l	#$8, a2
	addq.b	#$1, d3
	cmpa.l	A_OBJ_END, a2
	bne.w	l_0165e6
	bra.b	l_016626
l_016608:
	ori.b	#$0080, $4(a2)
	move.b	$2(a1), $5(a2)
	or.b	d3, $1(a1)
	btst.b	#$6, $4(a2)
	beq.w	l_016626
	bsr.w	f_016636
l_016626:
	addq.l	#$5, a1
	dbra	d6, l_0165b4
	rts	
	movea.l	#$0, a4
	bra.b	l_01663c
