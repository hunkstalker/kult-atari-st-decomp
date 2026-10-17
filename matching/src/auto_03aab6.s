f_03aab6:
	bclr.b	#$0, $484.l
	bclr.b	#$2, $484.l
	btst.b	#$6, $27(a3)
	bne.w	l_03ad58
	move.l	$18(a3), d0
	move.l	d0, $14(a6)
	move.b	$2f(a3), d0
	cmp.b	$2b(a3), d0
	beq.w	l_03ab16
	addi.b	#$0001, $2c(a3)
	move.b	$2c(a3), d0
	cmp.b	$1e(a6), d0
	bls.w	l_03ab16
	clr.b	$2c(a3)
	move.b	$2f(a3), d0
	cmp.b	$2b(a3), d0
	bls.w	l_03ab10
	addi.b	#$0001, $2b(a3)
	bra.w	l_03ab16
l_03ab10:
	subi.b	#$0001, $2b(a3)
l_03ab16:
	bclr.b	#$0, $27(a3)
	bne.w	l_03abb4
	tst.b	$1b(a6)
	bne.b	l_03ab2c
	subi.b	#$0001, $28(a3)
l_03ab2c:
	tst.b	$28(a3)
	bne.w	l_03ad14
	move.b	$29(a3), $28(a3)
l_03ab3a:
	movea.l	$8(a3), a0
	move.b	(a0)+, d0
	cmpi.b	#$00ff, d0
	bne.w	l_03abe2
l_03ab48:
	movea.l	$c(a3), a0
	move.b	(a0)+, d0
	cmpi.b	#$00ff, d0
	bne.w	l_03abc0
	btst.b	#$5, $27(a3)
	bne.w	l_03abb4
	movea.l	$4(a3), a1
	btst.b	#$1, $27(a1)
	beq.w	l_03ab82
	btst.b	#$1, $26(a3)
	beq.w	l_03ab82
	ori.w	#$100, $26(a1)
	clr.b	$2b(a1)
l_03ab82:
	bclr.b	#$1, $27(a1)
	ori.w	#$40, $26(a3)
	move.w	#$8, d2
	moveq	#$0, d0
	bsr.w	f_03aa8a
	lea.l	s_03aec0, a0
	move.b	(a0, d7.w), d4
	lsl.w	#$3, d4
	or.b	(a0, d7.w), d4
	movea.l	$18(a3), a0
	or.b	d4, $6(a0)
	bra.w	l_03ad58
l_03abb4:
	move.l	$0(a3), $c(a3)
	clr.w	$24(a3)
	bra.b	l_03ab48
l_03abc0:
	move.l	a0, $c(a3)
	addq.w	#$1, $24(a3)
	andi.w	#$ff, d0
	lsl.w	#$1, d0
	movea.l	$10(a6), a0
	movea.w	(a0, d0.w), a0
	adda.l	$c(a6), a0
	move.l	a0, $8(a3)
	bra.w	l_03ab3a
l_03abe2:
	move.l	a0, $8(a3)
	andi.l	#$ff, d0
	btst.b	#$7, d0
	bne.w	l_03ac5c
	lea.l	s_03aec4, a0
	tst.b	d0
	beq.b	l_03ac02
	add.b	$2a(a3), d0
l_03ac02:
	lsl.w	#$1, d0
	move.w	(a0, d0.w), $22(a3)
	move.w	(a0, d0.w), $20(a3)
	movea.l	$10(a3), a0
	clr.b	$a(a0)
	clr.w	$2(a0)
	clr.w	$0(a0)
	clr.b	$d(a0)
	clr.b	$c(a0)
	bset.b	#$0, $b(a0)
	bclr.b	#$2, $b(a0)
	movea.l	$14(a3), a0
	clr.b	$a(a0)
	clr.w	$2(a0)
	clr.w	$0(a0)
	clr.b	$d(a0)
	clr.b	$c(a0)
	bset.b	#$0, $b(a0)
	bclr.b	#$2, $b(a0)
	bra.w	l_03ad14
l_03ac5c:
	btst.b	#$6, d0
	bne.b	l_03acb2
	btst.b	#$5, d0
	beq.b	l_03ac98
	lea.l	s_03aec0, a0
	move.b	(a0, d7.w), d4
	lsl.w	#$3, d4
	movea.l	$18(a3), a0
	andi.b	#$001f, d0
	bne.w	l_03ac86
	or.b	d4, $6(a0)
	bra.b	l_03ac8c
l_03ac86:
	not.w	d4
	and.b	d4, $6(a0)
l_03ac8c:
	clr.b	$1(a0)
	move.b	d0, $0(a0)
	bra.w	l_03ab3a
l_03ac98:
	andi.b	#$000f, d0
	lea.l	s_03af9c, a0
	move.b	(a0, d0.w), $29(a3)
	move.b	(a0, d0.w), $28(a3)
	bra.w	l_03ab3a
l_03acb2:
	btst.b	#$5, d0
	bne.b	l_03ad02
	movea.l	$4(a6), a0
	andi.w	#$1f, d0
	mulu.w	#$d, d0
	lea.l	(a0, d0.w), a0
	movea.l	$10(a3), a2
	move.b	(a0), d0
	andi.b	#$0080, d0
	move.b	d0, $b(a2)
	move.b	(a0)+, d0
	andi.w	#$7f, d0
	move.b	d0, $8(a2)
	clr.b	$a(a2)
	clr.w	$2(a2)
	clr.w	$0(a2)
	clr.b	$d(a2)
	clr.b	$c(a2)
	bset.b	#$0, $b(a2)
	move.l	a0, $4(a2)
	bra.w	l_03ab3a
l_03ad02:
	lea.l	s_03aeac, a0
	andi.w	#$7, d0
	lsl.w	#$2, d0
	move.l	(a0, d0.w), -(a7)
	rts	
l_03ad14:
	moveq	#$0, d0
	movea.l	$10(a3), a0
	bsr.w	f_03a992
	moveq	#$0, d1
	move.b	$2b(a3), d1
	cmp.b	$1d(a6), d1
	ble.w	l_03ad30
	move.b	$1d(a6), d1
l_03ad30:
	moveq	#$f, d2
	sub.w	d1, d2
	sub.w	d2, d0
	bcc.w	l_03ad3c
	moveq	#$0, d0
l_03ad3c:
	move.w	#$8, d2
	bsr.w	f_03aa8a
	movea.l	$14(a3), a0
	move.w	$20(a3), d0
	bsr.w	f_03a992
	move.w	#$8000, d2
	bsr.w	f_03aa8a
l_03ad58:
	rte	
