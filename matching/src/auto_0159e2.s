f_0159e2:
	clr.w	A_ANIM_1A476
	clr.w	A_ANIM_1A478
	move.w	d0, A_ANIM_1A472
	move.w	d2, A_ANIM_1A474
	move.l	a6, -(a7)
	movea.l	#A_ANIM_TABLE, a4
	subq.w	#$1, d1
	bsr.w	f_012950
	movea.l	a5, a6
	move.l	a4, A_ANIM_END
l_015a10:
	clr.l	d0
	move.b	(a6), d0
	cmpa.l	A_ANIM_END, a6
	beq.w	l_015a4a
	cmpi.b	#$00fe, d0
	beq.w	l_015a4e
	cmpi.b	#$00fd, d0
	beq.w	l_015a6a
	cmpi.b	#$00fc, d0
	beq.w	l_015a86
	lsl.l	#$2, d0
	andi.w	#$1f, d0
	movea.l	#s_019eaa, a1
	movea.l	(a1, d0.l), a1
	jsr	(a1)
	bra.b	l_015a10
l_015a4a:
	movea.l	(a7)+, a6
	rts	
l_015a4e:
	move.b	$1(a6), d0
	move.b	$2(a6), d1
	ext.w	d0
	ext.w	d1
	move.w	d0, A_ANIM_1A47A
	move.w	d1, A_ANIM_1A47C
	addq.l	#$3, a6
	bra.b	l_015a10
l_015a6a:
	clr.w	d4
	move.b	$1(a6), d4
	tst.b	$2(a6)
	beq.w	l_015a7e
	bsr.w	f_018f98
	bra.b	l_015a82
l_015a7e:
	bsr.w	f_018f8e
l_015a82:
	addq.l	#$3, a6
	bra.b	l_015a10
l_015a86:
	bsr.w	f_018fa4
	addq.l	#$1, a6
	bra.w	l_015a10
l_015a90:
	movea.l	#A_SAVE_DESC, a0
	clr.l	d1
	btst.b	#$7, d0
	beq.w	l_015aa6
	move.l	#$c80, d1
l_015aa6:
	btst.b	#$6, d0
	beq.w	l_015ab4
	addi.l	#$640, d1
l_015ab4:
	adda.l	d1, a0
	move.l	a0, A_ANIM_SPR_PTR
	rts	
	move.b	(a6)+, d0
	bsr.w	l_015a90
	clr.w	d0
	move.b	(a6)+, d0
