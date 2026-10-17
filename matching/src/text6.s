f_010f8e:
	clr.l	d5
	tst.w	d4
	beq.w	l_010fa0
	subq.w	#1,d4
l_010f98:
	move.w	(a1),d5
	adda.l	d5,a1
	dbra	d4,l_010f98
l_010fa0:
	movea.l	a1,a2
	move.w	(a2),d5
	adda.l	d5,a2
	move.l	a2,A_CUR_STR_END
	adda.l	#2,a1
	rts
f_010fb4:
	cmpi.w	#4,d4
	bcc.w	f_010fc4
	rol.w	#8,d4
	move.b	1(a6),d4
	addq.l	#1,a6
f_010fc4:
	clr.l	d1
	move.w	d4,A_TEXT_INDEX
	subq.w	#5,d4
	bcs.w	l_010fda
l_010fd2:
	move.b	(a5),d1
	adda.l	d1,a5
	dbra	d4,l_010fd2
l_010fda:
	move.b	(a5),d1
	movea.l	a5,a2
	adda.l	d1,a5
	move.l	a5,A_CUR_STR_END
	movea.l	a2,a5
	addq.l	#1,a5
	rts
