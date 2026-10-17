f_014832:
	move.b	A_HIT_MASK, d2
	move.b	A_HIT_VALUE, d3
	bsr.w	f_014886
	movea.l	#s_0194dc, a0
	tst.b	A_CURSOR_HOTSPOT
	bne.w	l_01487e
	move.b	A_CUR_CLASS, d0
	andi.b	#$0038, d0
	movea.l	#s_01961c, a0
	cmpi.b	#$0010, d0
	beq.w	l_01487e
	movea.l	#s_01965c, a0
	btst.b	#$5, d0
	beq.w	l_01487e
	movea.l	#s_01969c, a0
l_01487e:
	move.l	a0, A_CURSOR_SPRITE_PTR
	rts	
