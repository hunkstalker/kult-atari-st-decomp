f_0121fa:
	clr.w	d0
	move.b	1(a6),d0
	bsr.w	f_0120e4
	movem.w	d0-d1,-(a7)
	bsr.w	f_01215e
	movem.w	(a7)+,d0-d1
	bsr.w	f_010fec
	move.w	#2,d2
	move.w	#$f,d3
	bsr.w	f_01215e
	adda.l	#2,a6
	clr.w	A_DAT_1A484
	rts
f_01222e:
	clr.w	d0
	move.b	1(a6),d0
	bsr.w	f_0120e4
	bsr.w	f_01215e
	addq.l	#2,a6
	rts
f_012240:
	adda.l	#1,a6
	clr.w	d5
	move.b	(a6),d5
	bra.w	l_012252
f_01224e:
	move.w	#4,d5
l_012252:
	clr.w	d6
	move.w	s_1a84e,d6
	add.w	d6,d5
	btst.b	#$f,d5
	bne.w	l_012286
	subq.w	#1,d5
	bcs.w	l_012286
l_01226a:
	move.w	#$32,d6
l_01226e:
	bsr.w	f_013698
	btst.b	#2,A_INPUT_BUTTONS
	bne.w	l_012286
	dbra	d6,l_01226e
	dbra	d5,l_01226a
l_012286:
	addq.l	#1,a6
	rts
f_01228a:
	bsr.w	f_012292
	addq.l	#1,a6
	rts
f_012292:
	cmpi.b	#$87,A_MODE_FLAG
	beq.w	f_012324
	movem.l	d0-d7/a0-a6,-(a7)
	clr.b	A_DAT_1A74E
l_0122a8:
	bsr.w	f_013698
	btst.b	#2,A_INPUT_BUTTONS
	bne.w	l_0122a8
l_0122b8:
	move.b	A_DAT_1ACD4,d0
	andi.b	#$f,d0
	bne.w	l_0122ca
	bsr.w	f_0122ee
l_0122ca:
	bsr.w	f_013698
	btst.b	#2,A_INPUT_BUTTONS
	beq.w	l_0122b8
	tst.b	A_DAT_1A74E
	beq.w	l_0122e8
	bsr.w	f_0122ee
l_0122e8:
	movem.l	(a7)+,d0-d7/a0-a6
	rts
f_0122ee:
	cmpi.b	#$87,A_MODE_FLAG
	beq.w	f_010768
	bsr.w	f_013594
	move.w	#$4b,d0
	move.w	#$9b,d1
	move.w	#$16,d4
	tst.b	A_DAT_1A74E
	beq.w	l_012318
	move.w	#$17,d4
l_012318:
	bsr.w	f_011020
	not.b	A_DAT_1A74E
	rts
f_012324:
	move.w	#8,-(a7)
	trap	#1
	addq.l	#2,a7
	rts
f_01232e:
	adda.l	#1,a6
	clr.w	A_DAT_1A484
l_01233a:
	move.w	#1,d0
	bsr.w	f_01213a
	bne.w	l_012366
	movem.w	d0-d1,-(a7)
	bsr.w	f_01215e
	movem.w	(a7)+,d0-d1
	bsr.w	f_010fec
	move.w	#2,d2
	move.w	#$f,d3
	bsr.w	f_01215e
	bra.w	l_01233a
l_012366:
	rts
f_012368:
	adda.l	#1,a6
l_012372:
	move.w	#2,d0
	bsr.w	f_01213a
	bne.w	l_012382
	bsr.w	f_01215e
	bra.w	l_012372
l_012382:
	rts
f_012384:
	adda.l	#1,a6
l_01238e:
	move.w	#3,d0
	bsr.w	f_01213a
	bne.w	l_01239e
	bsr.w	f_01215e
	bra.w	l_01238e
l_01239e:
	rts
f_0123a0:
	move.l	a0,-(a7)
	movea.l	#A_SAVE_DESC,a2
l_0123a8:
	movea.l	a0,a3
	move.w	d4,d6
l_0123ac:
	move.l	(a2)+,(a3)+
	dbra	d6,l_0123ac
	adda.l	#$a0,a0
	dbra	d5,l_0123a8
	movea.l	(a7)+,a0
	rts
