f_0129d6:
	clr.l	d4
	move.b	(a5), d4
	movea.l	#A_ELEM_TBL_31072, a1
	bsr.w	f_010f8e
	clr.l	d2
	clr.l	d3
	move.b	(a1)+, d3
	move.b	(a1)+, d2
	clr.l	d0
	move.b	$2(a5), d0
	ror.w	#$8, d0
	move.b	$1(a5), d0
	andi.w	#$3fff, d0
	movea.l	#s_03b1b0, a0
	lsl.l	#$1, d0
	adda.l	d0, a0
	move.l	A_DAT_1A534, d5
	btst.b	#$7, $2(a5)
	beq.w	l_012a22
	move.l	d5, d4
	mulu.w	d3, d4
	adda.l	d4, a0
	suba.l	d5, a0
	not.l	d5
	addq.l	#$1, d5
l_012a22:
	movea.l	d5, a3
	btst.b	#$6, $2(a5)
	bne.w	l_012a36
	bsr.w	f_012ad6
	bra.w	l_012a3a
l_012a36:
	bsr.w	f_012b04
l_012a3a:
	addq.l	#$3, a5
	cmpa.l	a4, a5
	bne.w	f_0129d6
	movea.l	#A_ANIM_BACKUP, a1
	rts	
