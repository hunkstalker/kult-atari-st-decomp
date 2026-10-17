f_010fec:
	lsl.w	#2,d0
f_010fee:
	movea.l	A_SCREEN_PTR_A,a0
f_010ff4:
	andi.l	#$ffff,d0
	andi.l	#$ffff,d1
	move.w	d0,d7
	andi.w	#$f,d7
	andi.w	#$fff0,d0
	lsr.w	#1,d0
	adda.l	d0,a0
	mulu.w	#$a0,d1
	adda.l	d1,a0
f_011014:
	rts
f_011016:
	movea.l	#$8000,a4
	bra.w	f_011026
f_011020:
	movea.l	#0,a4
f_011026:
	movea.l	#A_ANIM_TBL_28AD2,a1
	bsr.w	f_010f8e
f_011030:
	bsr.w	f_010fec
	suba.l	a4,a0
	clr.w	d2
	clr.w	d3
	move.b	(a1)+,d3
	move.b	(a1)+,d2
f_01103e:
	clr.l	d5
	move.w	d2,d5
	lsl.w	#1,d5
	move.l	d5,A_DAT_1A534
f_01104a:
	movea.l	A_DAT_1A534,a3
f_011050:
	movea.l	#A_BLIT_SCRATCH,a5
	subq.w	#1,d2
	subq.w	#1,d3
l_01105a:
	swap	d2
	move.w	d3,d2
	movea.l	a0,a2
	movea.l	a1,a4
	clr.w	d5
	btst.b	#3,d7
	beq.w	l_01106e
	addq.l	#1,a2
l_01106e:
	btst.b	#2,d7
	beq.w	l_01107a
	move.w	#4,d5
l_01107a:
	move.w	(a4),d6
	movep.w	d6,0(a5)
	rol.w	#4,d6
	movep.w	d6,1(a5)
	move.l	(a5),d6
	ror.l	d5,d6
	move.l	d6,d4
	move.l	d6,d1
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
	and.l	d4,d6
	movep.l	0(a2),d0
	and.l	d1,d0
	or.l	d6,d0
	movep.l	d0,0(a2)
	adda.l	#$a0,a2
	adda.l	a3,a4
	dbra	d2,l_01107a
	addq.l	#2,a1
	addq.w	#4,d7
	andi.w	#$f,d7
	bne.w	l_0110d2
	adda.l	#8,a0
l_0110d2:
	swap	d2
	dbra	d2,l_01105a
	rts
