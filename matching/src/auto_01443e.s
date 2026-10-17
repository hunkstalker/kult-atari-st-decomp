f_01443e:
	clr.l	d0
	move.b	$1(a6), d0
	move.b	A_MODE_FLAG, d1
	move.b	d1, A_DAT_1ACCB
	move.b	d0, A_MODE_FLAG
	move.b	#$00e5, d1
	tst.b	A_DAT_1AD32
	bne.w	l_01447c
	move.b	#$00dd, d1
	cmpi.b	#$0081, d0
	beq.w	l_01447c
	move.b	#$00de, d1
	cmpi.b	#$0082, d0
	bne.w	l_01448c
l_01447c:
	movea.l	#A_DAT_1A695, a0
	move.w	#$7, d0
l_014486:
	move.b	d1, (a0)+
	dbra	d0, l_014486
l_01448c:
	addq.l	#$2, a6
	bsr.w	f_014496
	bra.w	f_014588
