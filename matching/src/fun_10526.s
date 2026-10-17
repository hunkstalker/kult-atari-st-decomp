f_010526:
	movea.l	A_CURSOR_SPRITE_PTR,a1
	movea.l	#s_199d6,a2
	move.w	A_CURSOR_X,d0
	move.w	A_CURSOR_Y,d1
	sub.w	A_CLIP_X,d0
	bcc.w	l_01054a
	clr.w	d0
l_01054a:
	sub.w	A_CLIP_Y,d1
	bcc.w	l_010556
	clr.w	d1
l_010556:
	bsr.w	f_010fee
	move.l	a0,A_CURSOR_SAVE_DEST
	addq.l	#8,a0
	move.w	#$f,d4
l_010566:
	move.w	(a1)+,d1
	swap	d1
	move.w	#$ffff,d1
	ror.l	d7,d1
	move.w	(a1)+,d2
	swap	d2
	clr.w	d2
	ror.l	d7,d2
	move.w	(a0),(a2)
	and.w	d1,(a0)
	or.w	d2,(a0)
	move.w	2(a0),2(a2)
	and.w	d1,2(a0)
	or.w	d2,2(a0)
	move.w	4(a0),4(a2)
	and.w	d1,4(a0)
	or.w	d2,4(a0)
	move.w	6(a0),6(a2)
	and.w	d1,6(a0)
	tst.b	A_CURSOR_HOTSPOT
	beq.w	l_0105b2
	or.w	d2,6(a0)
l_0105b2:
	swap	d1
	swap	d2
	move.w	-8(a0),-8(a2)
	and.w	d1,-8(a0)
	or.w	d2,-8(a0)
	move.w	-6(a0),-6(a2)
	and.w	d1,-6(a0)
	or.w	d2,-6(a0)
	move.w	-4(a0),-4(a2)
	and.w	d1,-4(a0)
	or.w	d2,-4(a0)
	move.w	-2(a0),-2(a2)
	and.w	d1,-2(a0)
	tst.b	A_CURSOR_HOTSPOT
	beq.w	l_0105f8
	or.w	d2,-2(a0)
l_0105f8:
	adda.l	#$a0,a0
	adda.l	#$10,a2
	dbra	d4,l_010566
	rts
