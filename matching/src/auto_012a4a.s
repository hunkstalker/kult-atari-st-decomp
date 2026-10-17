f_012a4a:
	movea.l	#A_ELEM_TBL_23E9C, a4
	bsr.w	f_012950
l_012a54:
	clr.l	d4
	move.b	(a5), d4
	andi.b	#$007f, d4
	movea.l	#A_TEXT_TABLE, a1
	bsr.w	f_010f8e
	clr.l	d2
	clr.l	d3
	move.b	(a1)+, d3
	move.b	(a1)+, d2
	clr.l	d0
	move.b	$2(a5), d0
	ror.w	#$8, d0
	move.b	$1(a5), d0
	movea.l	#A_ANIM_BACKUP, a0
	lsl.l	#$1, d0
	adda.l	d0, a0
	movea.l	#$28, a3
	btst.b	#$7, (a5)
	bne.w	l_012a9a
	bsr.w	f_012ad6
	bra.w	l_012a9e
l_012a9a:
	bsr.w	f_012b04
l_012a9e:
	addq.l	#$3, a5
	cmpa.l	a4, a5
	bne.w	l_012a54
	movea.l	#A_ANIM_BACKUP, a1
	move.l	#$28, A_DAT_1A534
	move.w	#$20, d1
	move.w	d1, A_TEXT_BOX_Y
	move.w	#$14, d2
	move.w	d2, A_TEXT_BOX_SPAN
	move.w	#$3b, d3
	move.w	d3, A_ELEM_1A52C
	rts	
