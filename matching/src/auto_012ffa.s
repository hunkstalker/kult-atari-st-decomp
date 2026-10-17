f_012ffa:
	clr.l	A_SCREEN_DRAW_BASE
l_013000:
	swap	d6
	swap	d7
	move.w	d0, d6
	move.w	d1, -(a7)
	bsr.w	f_010fee
	suba.l	A_SCREEN_DRAW_BASE, a0
	move.w	d7, d0
	move.w	#$f, d1
	subi.w	#$1, d3
	sub.w	d0, d1
l_01301e:
	move.w	(a0), d0
	btst.b	#$0, d2
	beq.w	l_01302e
	bset.b	d1, d0
	bra.w	l_013030
l_01302e:
	bclr.b	d1, d0
l_013030:
	move.w	d0, (a0)
	move.w	$2(a0), d0
	btst.b	#$1, d2
	beq.w	l_013044
	bset.b	d1, d0
	bra.w	l_013046
l_013044:
	bclr.b	d1, d0
l_013046:
	move.w	d0, $2(a0)
	move.w	$4(a0), d0
	btst.b	#$2, d2
	beq.w	l_01305c
	bset.b	d1, d0
	bra.w	l_01305e
l_01305c:
	bclr.b	d1, d0
l_01305e:
	move.w	d0, $4(a0)
	move.w	$6(a0), d0
	btst.b	#$3, d2
	beq.w	l_013074
	bset.b	d1, d0
	bra.w	l_013076
l_013074:
	bclr.b	d1, d0
l_013076:
	move.w	d0, $6(a0)
	tst.w	d1
	beq.w	l_01308c
	subi.w	#$1, d1
	dbra	d3, l_01301e
	bra.w	l_01309a
l_01308c:
	adda.l	#$8, a0
	move.w	#$f, d1
	dbra	d3, l_01301e
l_01309a:
	move.w	d6, d0
	move.w	(a7)+, d1
	swap	d6
	swap	d7
	rts	
