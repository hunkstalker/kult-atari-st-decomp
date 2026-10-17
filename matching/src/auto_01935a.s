f_01935a:
	move.w	sr, -(a7)
	move.w	#$2500, sr
	movea.w	#$8604, a0
	move.b	#$000e, $ff8800.l
	move.b	$ff8800.l, d1
	move.b	d1, s_019314
	andi.b	#$00f8, d1
	ori.b	#$0005, d1
	move.b	d1, $ff8802.l
	move.w	#$80, $2(a0)
	bsr.w	f_019474
	clr.w	(a0)
	bsr.w	f_019462
	move.w	#$4f, d1
	bsr.w	f_019438
	clr.w	d0
	lea.l	s_00d8e8, a1
l_0193a6:
	bsr.w	f_0193e4
	adda.w	#$18, a1
	addq.w	#$1, d0
	cmpi.w	#$45, d0
	bls.w	l_0193a6
	movea.w	#$8604, a0
	move.w	#$80, $2(a0)
l_0193c2:
	bsr.w	f_019474
	move.w	(a0), d1
	tst.b	d1
	bmi.w	l_0193c2
	move.b	#$000e, $ff8800.l
	move.b	s_019314, $ff8802.l
	move.w	(a7)+, sr
	rts	
