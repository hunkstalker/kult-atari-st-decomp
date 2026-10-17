f_018dc0:
	cmpi.b	#$0008, A_DAT_1ACD2
	beq.w	l_018dd8
	cmpi.b	#$0032, A_DAT_1ACD2
	bne.w	l_018e04
l_018dd8:
	cmpi.b	#$0032, A_DAT_1ACD7
	bcc.w	l_018e04
	bsr.w	f_016210
	move.w	#$d0, d4
	btst.b	#$7, d0
	beq.w	l_018df6
	addq.w	#$1, d4
l_018df6:
	move.b	#$0034, d1
	andi.b	#$000f, d0
	add.b	d0, d1
	bsr.w	f_018f7a
l_018e04:
	rts	
