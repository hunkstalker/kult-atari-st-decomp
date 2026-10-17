f_0110da:
	movea.l	#A_ANIM_TBL_28AD2,a1
	bsr.w	f_010f8e
	clr.w	d2
	clr.w	d3
	move.b	(a1)+,d3
	move.b	(a1)+,d2
	bsr.w	f_010fec
	clr.l	d5
	move.w	d2,d5
	lsl.w	#1,d5
	move.l	d5,A_DAT_1A534
	movea.l	A_DAT_1A534,a3
f_011102:
	movea.l	#A_BLIT_SCRATCH,a5
	subq.w	#1,d2
	move.w	d2,d6
	subq.w	#1,d3
l_01110e:
	swap	d6
	move.w	d3,d6
	movea.l	a0,a2
	movea.l	a1,a4
	clr.w	d5
	btst.b	#3,d7
	beq.w	l_011122
	addq.l	#1,a2
l_011122:
	btst.b	#2,d7
	beq.w	l_01112e
	move.w	#4,d5
l_01112e:
	move.w	(a4),d0
	bsr.w	f_011196
	movep.w	d0,0(a5)
	rol.w	#4,d0
	movep.w	d0,1(a5)
	move.l	(a5),d2
	ror.l	d5,d2
	move.l	d2,d4
	move.l	d2,d1
	swap	d1
	or.l	d1,d4
	rol.l	#8,d1
	or.l	d1,d4
	swap	d1
	or.l	d1,d4
	andi.l	#$f0f0f0f0,d4
	ror.l	d5,d4
	move.l	d4,d1
	not.l	d1
	and.l	d4,d2
	movep.l	0(a2),d0
	and.l	d1,d0
	or.l	d2,d0
	movep.l	d0,0(a2)
	adda.l	#$a0,a2
	adda.l	a3,a4
	dbra	d6,l_01112e
	adda.l	#2,a1
	subq.w	#4,d7
	bcc.w	l_01118e
	suba.l	#8,a0
	move.w	#$c,d7
l_01118e:
	swap	d6
	dbra	d6,l_01110e
	rts
