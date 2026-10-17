f_03a992:
	moveq	#$0, d3
	move.b	$a(a0), d3
	movea.l	$4(a0), a1
	lea.l	(a1, d3.w), a1
	bclr.b	#$0, $b(a0)
	beq.w	l_03a9b4
	move.b	$1(a1), d3
	ext.w	d3
	add.w	d3, $2(a0)
l_03a9b4:
	add.w	$2(a0), d0
	sub.w	$0(a0), d0
	btst.b	#$f, d0
	beq.w	l_03a9c6
	moveq	#$0, d0
l_03a9c6:
	btst.b	#$2, $b(a0)
	bne.w	l_03aa2e
	addi.b	#$0001, $c(a0)
	move.b	$2(a1), d3
	cmp.b	$c(a0), d3
	bne.w	l_03aa2e
	addi.b	#$0001, $d(a0)
	clr.b	$c(a0)
	move.b	$0(a1), d3
	cmp.b	$d(a0), d3
	bne.w	l_03aa28
	clr.b	$d(a0)
	move.b	$a(a0), d3
	addq.w	#$3, d3
	cmpi.b	#$000c, d3
	bne.w	l_03aa24
	tst.b	$b(a0)
	beq.w	l_03aa30
	clr.b	$d(a0)
	move.b	$8(a0), d3
	ext.w	d3
	add.w	d3, $0(a0)
	move.w	#$3, d3
l_03aa24:
	move.b	d3, $a(a0)
l_03aa28:
	bset.b	#$0, $b(a0)
l_03aa2e:
	rts	
l_03aa30:
	bset.b	#$2, $b(a0)
	rts	
