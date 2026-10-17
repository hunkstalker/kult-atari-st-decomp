f_018740:
	cmpi.w	#$e10, A_DAT_1AB60
	bcs.w	l_01881c
	cmpi.b	#$003f, A_DAT_1ACEC
	bcc.w	l_0187c6
	move.b	#$0003, A_DAT_1ACFD
	move.b	#$003f, d0
	cmpi.b	#$002c, A_DAT_1ACD2
	bcc.w	l_018774
	move.b	#$00ff, d0
l_018774:
	move.b	d0, A_DAT_1ACEC
	movea.l	#A_OBJ_TBL, a0
	clr.b	$41(a0)
	clr.b	$46(a0)
	clr.b	$4b(a0)
	clr.b	$50(a0)
	clr.b	$55(a0)
	clr.b	$5a(a0)
	move.b	#$0038, $5f(a0)
	move.b	#$0038, $64(a0)
	move.b	#$0038, $69(a0)
	move.b	#$0038, $6e(a0)
	cmpi.b	#$0016, A_DAT_1ACD2
	bcc.w	l_01881c
l_0187bc:
	move.w	#$c012, A_DAT_1AC06
	rts	
l_0187c6:
	cmpi.w	#$189c, A_DAT_1AB60
	bcs.w	l_01881c
	cmpi.w	#$1c20, A_DAT_1AB60
	bcc.w	l_018814
	move.b	#$0002, A_DAT_1ACFD
	move.b	#$0001, A_DAT_1AD14
	cmpi.b	#$003d, A_DAT_1ACD2
	beq.w	l_01881c
	cmpi.b	#$003b, A_DAT_1ACD2
	bcs.w	l_01881c
	cmpi.b	#$004b, A_DAT_1ACD2
	bcs.w	l_0187bc
	rts	
l_018814:
	move.w	#$c318, A_DAT_1AC06
l_01881c:
	rts	
