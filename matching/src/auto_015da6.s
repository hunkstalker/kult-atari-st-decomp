f_015da6:
	movem.l	d0-d3, -(a7)
	movem.l	d0-d3, -(a7)
	bsr.w	f_010fec
	suba.l	#$8000, a0
	lsl.w	#$1, d5
	movea.l	d5, a3
	movea.l	#A_BLIT_SCRATCH, a5
	subq.w	#$1, d3
	movem.l	d2-d3/a0, -(a7)
	lsr.w	#$2, d2
	addq.w	#$2, d2
	move.l	a0, A_DAT_1A4B2
	move.w	d2, A_DAT_1A49E
	move.w	d3, A_ANIM_1A4A0
	movea.l	#A_ANIM_BACKUP, a2
l_015de4:
	move.w	d2, d5
	movea.l	a0, a4
l_015de8:
	move.l	(a4)+, (a2)+
	move.l	(a4)+, (a2)+
	dbra	d5, l_015de8
	adda.l	#$a0, a0
	dbra	d3, l_015de4
	movem.l	(a7)+, d2-d3/a0
	subq.w	#$1, d2
l_015e00:
	swap	d2
	move.w	d3, d2
	movea.l	a0, a2
	movea.l	a1, a4
	clr.w	d5
	btst.b	#$3, d7
	beq.w	l_015e14
	addq.l	#$1, a2
l_015e14:
	btst.b	#$2, d7
	beq.w	l_015e20
	move.w	#$4, d5
l_015e20:
	move.w	(a4), d6
	movep.w	d6, $0(a5)
	rol.w	#$4, d6
	movep.w	d6, $1(a5)
	move.l	(a5), d6
	ror.l	d5, d6
	move.l	d6, d4
	move.l	d6, d1
	swap	d1
	or.l	d1, d4
	rol.l	#$8, d1
	or.l	d1, d4
	swap	d1
	or.l	d1, d4
	andi.l	#$f0f0f0f0, d4
	ror.l	d5, d4
	move.l	d4, d1
	not.l	d1
	and.l	d4, d6
	movep.l	$0(a2), d0
	and.l	d1, d0
	or.l	d6, d0
	movep.l	d0, $0(a2)
	adda.l	#$a0, a2
	adda.l	a3, a4
	dbra	d2, l_015e20
	addq.l	#$2, a1
	addq.w	#$4, d7
	andi.w	#$f, d7
	bne.w	l_015e78
	adda.l	#$8, a0
l_015e78:
	swap	d2
	dbra	d2, l_015e00
	movem.l	(a7)+, d0-d3
	add.w	d1, d3
	add.w	d0, d2
	move.w	A_ANIM_1A478, d4
	beq.w	l_015ed2
	add.w	A_ANIM_1A474, d4
	cmp.w	d3, d4
	bcs.w	l_015e9e
	move.w	d4, d3
l_015e9e:
	move.w	A_ANIM_1A476, d4
	add.w	A_ANIM_1A472, d4
	cmp.w	d2, d4
	bcs.w	l_015eb2
	move.w	d4, d2
l_015eb2:
	cmp.w	A_ANIM_1A472, d0
	bcs.w	l_015ec2
	move.w	A_ANIM_1A472, d0
l_015ec2:
	cmp.w	A_ANIM_1A474, d1
	bcs.w	l_015ed2
	move.w	A_ANIM_1A474, d1
l_015ed2:
	sub.w	d0, d2
	sub.w	d1, d3
	movem.l	d0-d1, -(a7)
	bsr.w	f_010fec
	move.l	a0, -(a7)
	move.w	A_ANIM_1A470, d0
	beq.w	l_015ef6
l_015eea:
	move.w	#$bb8, d1
l_015eee:
	dbra	d1, l_015eee
	dbra	d0, l_015eea
l_015ef6:
	bsr.w	f_013594
	movea.l	(a7)+, a0
	movem.l	(a7)+, d0-d1
	tst.b	A_ANIM_1A578
	beq.w	l_015f10
	bsr.w	f_012e2e
	bra.b	l_015f14
l_015f10:
	bsr.w	f_01215e
l_015f14:
	movea.l	A_DAT_1A4B2, a0
	move.w	A_DAT_1A49E, d2
	move.w	A_ANIM_1A4A0, d3
	movea.l	#A_ANIM_BACKUP, a2
l_015f2c:
	move.w	d2, d5
	movea.l	a0, a4
l_015f30:
	move.l	(a2)+, (a4)+
	move.l	(a2)+, (a4)+
	dbra	d5, l_015f30
	adda.l	#$a0, a0
	dbra	d3, l_015f2c
	movem.l	(a7)+, d0-d3
	move.w	d0, A_ANIM_1A472
	move.w	d1, A_ANIM_1A474
	move.w	d2, A_ANIM_1A476
	move.w	d3, A_ANIM_1A478
	clr.w	A_ANIM_1A47C
	clr.w	A_ANIM_1A47A
	rts	
