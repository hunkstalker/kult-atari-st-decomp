f_010440:
	andi.w	#$3ff,d1
	move.w	d1,d4
	movea.l	#DESC_BASE,a5
	bsr.w	f_010fc4
l_010450:
	bsr.w	f_010998
	addq.w	#2,d6
	cmpi.b	#5,d5
	bcs.w	l_010462
	move.w	#$14,d6
l_010462:
	move.w	d6,A_TEXT_BOX_W
	bsr.w	f_0109bc
	move.w	d5,d0
	lsl.w	#2,d0
	add.w	d5,d0
	add.w	d5,d0
	addi.w	#7,d0
	move.w	d0,A_TEXT_BOX_H
	move.w	A_CURSOR_X,d0
	lsr.w	#2,d0
	cmpi.w	#9,d0
	bcc.w	l_010492
	move.w	#9,d0
l_010492:
	move.w	d0,d1
	add.w	A_TEXT_BOX_W,d0
	addq.w	#2,d0
	subi.w	#$49,d0
	bcs.w	l_0104a6
	sub.w	d0,d1
l_0104a6:
	move.w	d1,A_TEXT_BOX_X
	move.w	A_CURSOR_Y,d0
	move.w	d0,d1
	add.w	A_TEXT_BOX_H,d0
	subi.w	#$c8,d0
	bcs.w	l_0104c4
	sub.w	d0,d1
l_0104c4:
	move.w	d1,A_TEXT_BOX_Y
	move.w	A_TEXT_BOX_X,d0
	bsr.w	f_010fec
	move.w	A_TEXT_BOX_W,d2
	addq.w	#2,d2
	move.w	A_TEXT_BOX_H,d3
	bsr.w	f_01258a
	bsr.w	f_010e66
	bsr.w	f_012292
	bsr.w	f_0124f2
	rts
