f_03a734:
	link.w	a6, #$0
	movem.l	d1-d7/a0-a6, -(a7)
	move.l	#$ffff, d0
	move.w	$a(a6), d1
	move.w	$8(a6), d5
	lea.l	s_03afa8, a0
	lea.l	s_03ae8c, a6
	bsr.w	f_03a57c
	bcc.w	l_03a856
	move.w	d1, d2
	andi.l	#$f, d2
	bne.w	l_03a76e
	ori.w	#$f, d2
l_03a76e:
	lea.l	s_03afbc, a0
	moveq	#$0, d7
l_03a776:
	lsr.w	#$1, d2
	bcc.w	l_03a842
	btst.b	#$f, d1
	beq.w	l_03a78c
	andi.b	#$000f, d5
	move.b	d5, $2f(a0)
l_03a78c:
	btst.b	#$d, d1
	beq.w	l_03a7a0
	andi.b	#$000f, d5
	move.b	d5, $2b(a0)
	move.b	d5, $2f(a0)
l_03a7a0:
	btst.b	#$8, d1
	beq.w	l_03a7b4
	clr.b	$2b(a0)
	move.b	$1d(a6), d0
	move.b	d0, $2f(a0)
l_03a7b4:
	btst.b	#$9, d1
	beq.w	l_03a7c0
	clr.b	$2f(a0)
l_03a7c0:
	btst.b	#$6, d1
	beq.w	l_03a7e4
	lea.l	s_03aec0, a2
	move.b	(a2, d7.w), d4
	lsl.w	#$3, d4
	or.b	(a2, d7.w), d4
	or.b	d4, s_03b1a2
	ori.w	#$40, $26(a0)
l_03a7e4:
	btst.b	#$7, d1
	beq.w	l_03a812
	clr.w	$26(a0)
	ori.w	#$80, $26(a0)
	ori.w	#$1, $26(a0)
	st.b	$1a(a6)
	lea.l	s_03aec0, a2
	move.b	(a2, d7.w), d4
	not.w	d4
	and.b	d4, s_03b1a2
l_03a812:
	btst.b	#$5, d1
	beq.w	l_03a820
	ori.w	#$20, $26(a0)
l_03a820:
	btst.b	#$4, d1
	beq.w	l_03a842
	btst.b	#$6, $27(a0)
	bne.w	l_03a842
	moveq	#$0, d6
	move.w	$24(a0), d6
	cmp.l	d6, d0
	bcs.w	l_03a842
	move.w	$24(a0), d0
l_03a842:
	adda.l	#$50, a0
	addq.w	#$1, d7
	cmpi.w	#$3, d7
	bne.w	l_03a776
	move.l	d0, -(a7)
	move.l	(a7)+, d0
l_03a856:
	movem.l	(a7)+, d1-d7/a0-a6
	unlk	a6
	rts	
