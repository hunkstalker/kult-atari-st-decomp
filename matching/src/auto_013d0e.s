f_013d0e:
	movea.l	#A_BLIT_SCRATCH, a5
	clr.w	(a5)
	move.w	s_01a518, d0
	move.w	s_01a516, d1
	sub.w	d1, d0
	bcc.w	l_013d2e
	not.w	d0
	move.b	#$0001, (a5)
l_013d2e:
	move.w	d0, d6
	lsl.w	#$1, d0
	not.w	d0
	move.w	d0, d4
	move.w	s_01a51c, d0
	move.w	s_01a51a, d3
	sub.w	d3, d0
	bcc.w	l_013d50
	not.w	d0
	move.b	#$0001, $1(a5)
l_013d50:
	add.w	d0, d6
	addq.w	#$1, d6
	lsl.w	#$1, d0
	move.w	d0, d5
	move.w	d1, d0
	move.w	d3, d1
	bsr.w	f_010fee
	btst.b	#$3, d7
	beq.w	l_013d6a
	addq.l	#$1, a0
l_013d6a:
	movea.l	a0, a1
	suba.l	#$8000, a1
	andi.w	#$7, d7
	move.l	#$80808080, d3
	ror.l	d7, d3
	move.w	d5, d7
	add.w	d4, d7
	bra.w	l_013dc8
l_013d86:
	cmpi.b	#$0001, (a5)
	beq.w	l_013daa
	ror.l	#$1, d3
	bcc.w	l_013dc2
	addq.l	#$1, a0
	addq.l	#$1, a1
	move.l	a0, d0
	btst.b	#$0, d0
	bne.w	l_013dc2
	addq.l	#$6, a0
	addq.l	#$6, a1
	bra.w	l_013dc2
l_013daa:
	rol.l	#$1, d3
	bcc.w	l_013dc2
	subq.l	#$1, a0
	subq.l	#$1, a1
	move.l	a0, d0
	btst.b	#$0, d0
	beq.w	l_013dc2
	subq.l	#$6, a0
	subq.l	#$6, a1
l_013dc2:
	add.w	d5, d7
	bgt.w	l_013dde
l_013dc8:
	movep.l	$0(a0), d2
	movep.l	$0(a1), d0
	and.l	d3, d0
	not.l	d3
	and.l	d3, d2
	or.l	d2, d0
	movep.l	d0, $0(a0)
	not.l	d3
l_013dde:
	subq.w	#$1, d6
	beq.w	l_013e12
	tst.w	d7
	ble.w	l_013d86
	cmpi.b	#$0001, $1(a5)
	beq.w	l_013e02
	adda.l	#$a0, a0
	adda.l	#$a0, a1
	bra.b	l_013e0e
l_013e02:
	suba.l	#$a0, a0
	suba.l	#$a0, a1
l_013e0e:
	add.w	d4, d7
	bra.b	l_013dc8
l_013e12:
	rts	
