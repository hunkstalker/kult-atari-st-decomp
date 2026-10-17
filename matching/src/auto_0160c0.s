f_0160c0:
	rts	
f_0160c2:
	addq.b	#$1, A_DAT_1ACD4
	tst.b	A_DAT_1AD0D
	beq.w	l_01610e
	cmpi.b	#$0005, A_DAT_1AD0D
	bne.w	f_010768
	move.b	A_DAT_1ACD4, d0
	andi.b	#$0003, d0
	bne.w	f_010768
	movea.l	#$ff8258, a0
	movea.l	#$ff825a, a1
	move.w	(a0), d0
	move.w	(a1), (a0)
	move.w	$2(a1), $2(a0)
	move.w	$4(a1), $4(a0)
	move.w	d0, $6(a0)
	rts	
l_01610e:
	move.b	A_DAT_1ACD4, d0
	andi.b	#$003f, d0
	bne.w	l_01618a
	addq.w	#$1, A_DAT_1AB60
	clr.l	d0
	bsr.w	f_016210
	movea.l	A_SCREEN_PTR_A, a0
	adda.l	#$140, a0
	movea.l	#s_0268de, a1
	andi.w	#$3, d0
	cmp.b	s_01acd5, d0
	bne.w	l_01614e
	addq.b	#$1, d0
	andi.b	#$0003, d0
l_01614e:
	move.b	d0, s_01acd5
	mulu.w	#$1e0, d0
	adda.l	d0, a1
	move.w	#$1d, d1
	move.l	#$90, d2
	movea.l	A_SCREEN_PTR_B, a2
	adda.l	#$140, a2
l_016170:
	move.l	(a1), (a2)+
	move.l	(a1)+, (a0)+
	move.l	(a1), (a2)+
	move.l	(a1)+, (a0)+
	move.l	(a1), (a2)+
	move.l	(a1)+, (a0)+
	move.l	(a1), (a2)+
	move.l	(a1)+, (a0)+
	adda.l	d2, a0
	adda.l	d2, a2
	dbra	d1, l_016170
	rts	
l_01618a:
	btst.b	#$0, d0
	beq.w	f_010768
	tst.b	A_FRAME_1AB4F
	beq.w	f_010768
	movea.l	A_SCREEN_PTR_A, a1
	movea.l	s_01a82a, a2
	adda.l	#$5f10, a1
	move.w	#$1c, d5
l_0161b2:
	move.w	#$f, d4
	movea.l	a1, a0
l_0161b8:
	move.w	(a0), d0
	or.w	$2(a0), d0
	move.w	(a0), d1
	and.w	$2(a0), d1
	and.w	$6(a0), d1
	not.w	d1
	and.w	d1, d0
	and.w	d0, (a0)
	and.w	d0, $2(a0)
	and.w	d0, $6(a0)
	not.w	d0
	move.w	(a2), d1
	and.w	d0, d1
	or.w	d1, (a0)
	or.w	d1, $2(a0)
	or.w	d1, $6(a0)
	addq.l	#$8, a0
	addq.l	#$2, a2
	cmpa.l	#A_ELEM_TBL_23E9C, a2
	bne.w	l_0161fa
	movea.l	#A_DAT_1D402, a2
l_0161fa:
	dbra	d4, l_0161b8
	adda.l	#$a0, a1
	dbra	d5, l_0161b2
	move.l	a2, s_01a82a
	rts	
