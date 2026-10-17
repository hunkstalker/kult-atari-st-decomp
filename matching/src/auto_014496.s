f_014496:
	clr.w	d1
	move.b	A_MODE_FLAG, d1
	movea.l	#A_MODE_TABLE, a4
	subq.w	#$1, d1
	bsr.w	f_012950
	cmpi.b	#$0052, A_DAT_D8EB
	bne.w	f_014496
	move.b	(a5)+, A_DAT_1ACD2
	move.b	(a5)+, A_DAT_1ACC7
	move.b	(a5), A_1AB48
	move.b	(a5)+, A_TEXT_SEL_A
	move.b	(a5)+, A_PAL_INDEX_CUR
	move.b	(a5)+, A_DAT_1AB4B
	clr.w	d1
	move.b	A_DAT_1AB4B, d1
	beq.w	l_014544
	subq.w	#$1, d1
	movea.l	#A_DAT_1AB62, a3
	move.w	#$4a, d2
l_0144f2:
	clr.w	(a3)+
	dbra	d2, l_0144f2
	movea.l	#A_DAT_1AB62, a3
l_0144fe:
	move.w	(a5)+, d0
	btst.b	#$4, d0
	beq.w	l_01450a
	move.w	(a5)+, (a3)
l_01450a:
	btst.b	#$3, d0
	beq.w	l_014516
	move.w	(a5)+, $2(a3)
l_014516:
	btst.b	#$2, d0
	beq.w	l_014522
	move.w	(a5)+, $4(a3)
l_014522:
	btst.b	#$1, d0
	beq.w	l_01452e
	move.w	(a5)+, $6(a3)
l_01452e:
	btst.b	#$0, d0
	beq.w	l_01453a
	move.w	(a5)+, $8(a3)
l_01453a:
	adda.l	#$a, a3
	dbra	d1, l_0144fe
l_014544:
	move.l	a5, A_OBJ_BEGIN
	move.l	a5, A_DAT_1A762
	move.l	a4, A_OBJ_END
	move.l	a5, A_SEL_1A7D2
	clr.b	A_SEL_1AB4A
	clr.b	A_DAT_1ACD3
	clr.b	A_DAT_1ACEB
	clr.w	A_DAT_1ABF8
	clr.w	A_DAT_1ACAE
	clr.w	A_W_1ACAA
	clr.b	A_DAT_1ACE7
	rts	
