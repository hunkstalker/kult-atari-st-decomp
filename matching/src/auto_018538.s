f_018538:
	move.w	#$7f, d1
	movea.l	#A_ANIM_TBL_27FE2, a4
	bsr.w	f_012950
	move.b	d3, $2(a5)
	cmpi.b	#$0025, d3
	beq.w	l_018562
	cmpi.b	#$003a, d3
	beq.w	l_018562
	cmpi.b	#$0028, d3
	bne.w	l_018578
l_018562:
	cmpi.b	#$0080, d4
	bne.w	l_018572
	addq.b	#$1, A_DAT_1AD2C
	rts	
l_018572:
	subq.b	#$1, A_DAT_1AD2C
l_018578:
	rts	
