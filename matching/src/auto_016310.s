f_016310:
	move.w	#$17, d4
	bsr.w	f_018f98
	movea.l	A_PALETTE_PTR, a0
	movea.l	#A_SAVE_DESC, a1
	move.w	#$f, d0
l_016328:
	move.w	(a0)+, (a1)+
	dbra	d0, l_016328
l_01632e:
	movea.l	A_PALETTE_PTR, a0
	addq.l	#$2, a0
	clr.w	d5
	move.w	#$4, d3
l_01633c:
	move.w	(a0), d0
	move.w	d0, d1
	move.w	d0, d2
	cmpi.w	#$777, d0
	beq.w	l_016382
	move.w	#$ffff, d5
	andi.w	#$f, d0
	cmpi.w	#$7, d0
	beq.w	l_01635e
	addi.w	#$1, d0
l_01635e:
	andi.w	#$f0, d1
	cmpi.w	#$70, d1
	beq.w	l_01636e
	addi.w	#$10, d1
l_01636e:
	andi.w	#$f00, d2
	cmpi.w	#$700, d2
	beq.w	l_01637e
	addi.w	#$100, d2
l_01637e:
	or.w	d1, d0
	or.w	d2, d0
l_016382:
	move.w	d0, (a0)+
	dbra	d3, l_01633c
	tst.w	d5
	beq.w	l_0163a0
	bsr.w	f_013594
	move.w	#$ffff, d0
l_016396:
	dbra	d0, l_016396
	bsr.w	f_016300
	bra.b	l_01632e
l_0163a0:
	move.w	#$17, d4
	bsr.w	f_018f8e
	move.w	A_DAT_1ABFA, A_THE_COMMAND
	bsr.w	f_0103ae
	clr.w	d0
	move.b	A_PAL_INDEX_CUR, d0
	mulu.w	#$a, d0
	movea.l	#A_PAL_TABLE, a0
	adda.l	d0, a0
	movea.l	#s_00d8f2, a1
	move.w	#$4, d0
l_0163d4:
	move.w	(a0)+, (a1)+
	dbra	d0, l_0163d4
l_0163da:
	movea.l	A_PALETTE_PTR, a0
	movea.l	#s_00d8f2, a1
	addq.l	#$2, a0
	clr.w	d5
	move.w	#$4, d3
l_0163ee:
	move.w	(a0), d0
	move.w	d0, d1
	move.w	d0, d2
	cmp.w	(a1), d0
	beq.w	l_01643e
	move.w	#$ffff, d5
	andi.w	#$f, d0
	move.w	(a1), d4
	andi.w	#$f, d4
	cmp.w	d4, d0
	beq.w	l_016412
	subi.w	#$1, d0
l_016412:
	andi.w	#$f0, d1
	move.w	(a1), d4
	andi.w	#$f0, d4
	cmp.w	d4, d1
	beq.w	l_016426
	subi.w	#$10, d1
l_016426:
	andi.w	#$f00, d2
	move.w	(a1), d4
	andi.w	#$f00, d4
	cmp.w	d4, d2
	beq.w	l_01643a
	subi.w	#$100, d2
l_01643a:
	or.w	d1, d0
	or.w	d2, d0
l_01643e:
	move.w	d0, (a0)+
	addq.l	#$2, a1
	dbra	d3, l_0163ee
	tst.w	d5
	beq.w	f_010768
	bsr.w	f_013594
	move.w	#$ffff, d0
l_016454:
	dbra	d0, l_016454
	bsr.w	f_016300
	bra.w	l_0163da
