f_01627a:
	move.w	A_DAT_1AB60, d0
	sub.w	A_DAT_1A526, d0
	cmpi.b	#$00b4, d0
	bcs.w	f_010768
	move.w	A_DAT_1AB60, A_DAT_1A526
	movea.l	#A_LIST_1A8F0, a0
	move.w	#$3e, d0
	move.b	A_DAT_1ACD2, d1
l_0162a8:
	btst.b	#$6, (a0)
	beq.w	l_0162c6
	cmp.b	$1(a0), d1
	beq.w	l_0162c6
	cmpi.b	#$0034, $1(a0)
	bcc.w	l_0162c6
	andi.b	#$00bf, (a0)
l_0162c6:
	addq.l	#$6, a0
	dbra	d0, l_0162a8
	rts	
