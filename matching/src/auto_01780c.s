f_01780c:
	move.b	$2(a6), d0
	move.b	$1(a6), d3
	bne.w	l_01782e
	move.b	d0, d2
	andi.l	#$ff, d0
	subq.b	#$1, d0
	lsl.l	#$3, d0
	movea.l	A_OBJ_BEGIN, a0
	adda.l	d0, a0
	bra.b	l_017836
l_01782e:
	bsr.w	f_017792
	bne.w	l_01018e
l_017836:
	bsr.w	f_0177e4
	bsr.w	f_014926
	tst.b	A_CLASS_IDX
	bne.w	l_017852
	move.l	#A_1AAD6, A_ELEM_CLASS
l_017852:
	addq.l	#$3, a6
	rts	
