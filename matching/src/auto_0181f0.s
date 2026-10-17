f_0181f0:
	move.w	#$f, d0
	move.l	#$14000c8, d1
	movea.l	#A_ANIM_BACKUP, a0
l_018200:
	move.l	d1, (a0)+
	dbra	d0, l_018200
	clr.l	(a0)
	clr.w	A_DAT_1A49E
	clr.w	A_ANIM_1A4A0
	clr.w	A_SAVE_1A4A2
l_01821a:
	move.w	#$f, d1
	movea.l	#A_ANIM_BACKUP, a2
	movea.l	#s_0198c0, a1
	move.w	A_DAT_1A49E, d2
	move.w	A_ANIM_1A4A0, d4
	addq.w	#$1, d4
	move.w	d4, A_ANIM_1A4A0
	move.w	A_SAVE_1A4A2, d3
	andi.w	#$7, d4
	bne.w	l_018258
	bsr.w	f_016230
	move.w	d0, d3
	move.w	d3, A_SAVE_1A4A2
l_018258:
	lsr.w	#$1, d3
	bcc.w	l_01828a
	move.w	(a2), d0
	add.w	(a1), d0
	cmpi.w	#$258, d0
	bcs.w	l_01826e
	bset.b	d1, d2
	move.w	(a2), d0
l_01826e:
	move.w	d0, (a2)
	move.w	$2(a2), d0
	add.w	$2(a1), d0
	cmpi.w	#$190, d0
	bcs.w	l_018286
	bset.b	d1, d2
	move.w	$2(a2), d0
l_018286:
	move.w	d0, $2(a2)
l_01828a:
	addq.l	#$4, a1
	addq.l	#$4, a2
	dbra	d1, l_018258
	tst.w	d2
	bne.w	l_0182ee
	move.w	d2, A_DAT_1A49E
	movea.l	#A_ANIM_BACKUP, a2
	move.w	#$f, d1
l_0182a8:
	move.l	(a2)+, d0
	lsr.w	#$1, d0
	move.w	d0, s_01a51a
	swap	d0
	lsr.w	#$1, d0
	move.w	d0, s_01a516
	move.l	(a2), d0
	bne.w	l_0182c8
	move.l	A_ANIM_BACKUP, d0
l_0182c8:
	lsr.w	#$1, d0
	move.w	d0, s_01a51c
	swap	d0
	lsr.w	#$1, d0
	move.w	d0, s_01a518
	movem.l	d1/a2, -(a7)
	bsr.w	f_013d0e
	movem.l	(a7)+, d1/a2
	dbra	d1, l_0182a8
	bra.w	l_01821a
l_0182ee:
	rts	
