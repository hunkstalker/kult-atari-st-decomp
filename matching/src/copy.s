f_01215e:
	bsr.w	f_012698
	cmpi.b	#$41,A_BLIT_D8EA
	beq.w	l_012174
	clr.b	A_DAT_1D402
l_012174:
	move.w	d3,d7
	subq.w	#1,d7
l_012178:
	movea.l	a0,a1
	suba.l	#$8000,a1
	bsr.w	f_0123c0
	adda.l	#$a0,a0
	dbra	d7,l_012178
	rts
f_012190:
	bsr.w	f_012698
	move.w	d3,d7
	subq.w	#1,d7
	suba.l	#$8000,a0
l_01219e:
	movea.l	a0,a1
	adda.l	#$8000,a1
	bsr.w	f_0123c0
	adda.l	#$a0,a0
	dbra	d7,l_01219e
	rts
f_0121b6:
	movea.l	A_SCREEN_PTR_B,a1
	movea.l	A_SCREEN_PTR_A,a0
	bra.b	l_0121d2
f_0121c4:
	addq.l	#1,a6
f_0121c6:
	movea.l	A_SCREEN_PTR_B,a0
	movea.l	A_SCREEN_PTR_A,a1
l_0121d2:
	move.w	#$1f3f,d0
l_0121d6:
	move.l	(a0)+,(a1)+
	dbra	d0,l_0121d6
	rts
f_0121de:
	movea.l	A_SCREEN_PTR_A,a0
	movea.l	A_SCREEN_PTR_B,a1
	move.w	#$1f3f,d0
l_0121ee:
	move.l	(a0),d1
	move.l	(a1),(a0)+
	move.l	d1,(a1)+
	dbra	d0,l_0121ee
	rts
