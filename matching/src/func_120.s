f_0120a8:
	movea.l	#s_1a850,a2
	move.w	#9,d6
l_0120b2:
	tst.w	(a2)
	beq.w	l_0120c2
	adda.l	#$10,a2
	dbra	d6,l_0120b2
l_0120c2:
	move.w	d4,(a2)+
	move.l	a0,(a2)+
	move.w	d7,(a2)+
	move.w	d0,(a2)+
	move.w	d1,(a2)+
	move.w	d2,(a2)+
	move.w	d3,(a2)
	move.b	s_1a851,A_DAT_1AD0A
	rts
f_0120dc:
	move.w	#2,d1
	bra.w	l_0120e6
f_0120e4:
	clr.w	d1
l_0120e6:
	movea.l	#s_1a850,a1
	subq.w	#1,d0
	lsl.w	#4,d0
	andi.l	#$ffff,d0
	adda.l	d0,a1
l_0120f8:
	move.w	(a1),d4
	move.w	d1,(a1)
	move.l	2(a1),d7
	move.l	A_SCREEN_PTR_A,d0
	andi.l	#$ffff0000,d0
	andi.l	#$ffff,d7
	or.l	d7,d0
	movea.l	d0,a0
	move.w	6(a1),d7
	move.w	8(a1),d0
	move.w	$a(a1),d1
	move.w	$c(a1),d2
	move.w	$e(a1),d3
	move.b	s_1a851,A_DAT_1AD0A
	clr.w	d5
	tst.w	d5
	rts
f_01213a:
	movea.l	#s_1a850,a1
	move.w	#9,d6
	clr.w	d1
l_012146:
	cmp.w	(a1),d0
	beq.w	l_0120f8
	adda.l	#$10,a1
	dbra	d6,l_012146
	move.w	#1,d5
	tst.w	d5
	rts
