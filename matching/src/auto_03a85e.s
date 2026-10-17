f_03a85e:
	moveq	#$0, d7
	move.w	#$8, d2
	moveq	#$0, d0
	trap	#$3
	addq.w	#$1, d7
	trap	#$3
	addq.w	#$1, d7
	trap	#$3
	rts	
	move.l	a6, -(a7)
	lea.l	s_03ae8c, a6
	tst.b	$1a(a6)
	beq.w	l_03a92a
	sf.b	$1a(a6)
	movem.l	d0-d7/a0-a5, -(a7)
	subi.b	#$0001, $1b(a6)
	lea.l	s_03b19c, a0
	move.l	a0, $14(a6)
	moveq	#$0, d7
	lea.l	s_03afbc, a3
l_03a8a2:
	trap	#$4
	adda.w	#$50, a3
	addq.w	#$1, d7
	cmpi.w	#$3, d7
	bne.w	l_03a8a2
	moveq	#$0, d7
	lea.l	s_03afbc, a3
l_03a8ba:
	move.l	a3, -(a7)
	btst.b	#$1, $27(a3)
	beq.w	l_03a8cc
	movea.l	$1c(a3), a3
	trap	#$4
l_03a8cc:
	movea.l	(a7)+, a3
	adda.w	#$50, a3
	addq.w	#$1, d7
	cmpi.w	#$3, d7
	bne.w	l_03a8ba
	lea.l	s_03ae7c, a0
	move.w	#$8000, d2
	moveq	#$0, d7
l_03a8e8:
	move.w	(a0)+, d0
	trap	#$3
	addq.w	#$1, d7
	cmpi.w	#$3, d7
	bne.w	l_03a8e8
	lea.l	s_03ae84, a0
	move.w	#$8, d2
	moveq	#$0, d7
l_03a902:
	move.b	(a0)+, d0
	trap	#$3
	addq.w	#$1, d7
	cmpi.w	#$3, d7
	bne.w	l_03a902
	bsr.w	l_03a936
	tst.b	$1b(a6)
	bne.w	l_03a922
	move.b	$1c(a6), $1b(a6)
l_03a922:
	st.b	$1a(a6)
	movem.l	(a7)+, d0-d7/a0-a5
l_03a92a:
	movea.l	(a7)+, a6
	bclr.b	#$5, $fffa0f.l
	rte	
l_03a936:
	movea.l	$14(a6), a0
	move.b	$1(a0), d0
	beq.w	l_03a972
	subi.b	#$0001, $1(a0)
	bne.w	l_03a972
	move.b	$2(a0), $1(a0)
	move.b	$0(a0), d0
	add.b	$5(a0), d0
	move.b	d0, $0(a0)
	move.b	d0, d1
	cmp.b	$3(a0), d0
	beq.b	l_03a96c
	cmp.b	$4(a0), d0
	bne.b	l_03a972
l_03a96c:
	eori.b	#$00fe, $5(a0)
l_03a972:
	move.b	$0(a0), d0
	move.w	#$6, d2
	moveq	#$0, d7
	trap	#$3
	move.b	$6(a0), d0
	and.b	s_03b1a2, d0
	move.w	#$7, d2
	moveq	#$0, d7
	trap	#$3
	rts	
