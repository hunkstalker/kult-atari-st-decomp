f_010682:
	cmpi.b	#$ff,s_1a57c
	beq.w	l_0106e0
	addi.b	#$30,d0
	cmp.b	s_1a57c,d0
	beq.w	l_0106e0
	movea.l	A_SCRIPT_END,a5
	movem.l	a5-a6,-(a7)
	lea.l	s_1a404,a5
	move.l	d1,10(a5)
	move.b	d0,4(a5)
	move.b	d0,s_1a57c
l_0106ba:
	lea.l	s_1a404,a5
	bsr.w	f_0106f8
	bpl.w	l_0106d6
	move.w	#$918e,A_THE_COMMAND
	bsr.w	f_0103ae
	bra.b	l_0106ba
l_0106d6:
	movem.l	(a7)+,a5-a6
	move.l	a5,A_SCRIPT_END
l_0106e0:
	rts
f_0106e2:
	movea.l	#s_1a3aa,a5
	bra.b	f_0106f8
f_0106ea:
	movea.l	#s_1a3e4,a5
	bra.b	f_0106f8
f_0106f2:
	movea.l	#s_1a2c8,a5
f_0106f8:
	move.l	#DTA,-(a7)
	move.w	#$1a,-(a7)
	trap	#1
	addq.l	#6,a7
l_010706:
	cmpi.b	#$24,(a5)
	beq.w	l_01074c
	move.l	a5,A_CUR_FILENAME
	clr.w	-(a7)
	move.l	a5,-(a7)
	move.w	#$4e,-(a7)
	trap	#1
	adda.l	#8,a7
	tst.w	d0
	bne.w	l_010764
	move.l	10(a5),A_LOAD_BUFFER
	move.l	DTA_LEN,A_LOAD_LENGTH
	bsr.w	f_01076a
	bmi.w	l_010764
	adda.l	#14,a5
	bra.b	l_010706
l_01074c:
	movea.l	#s_1567d,a0
l_010752:
	suba.l	#s_15623,a0
	cmpi.w	#$4eb9,(a0)
	bne.w	l_010752
	clr.w	d0
	rts
l_010764:
	move.w	#$ffff,d0
f_010768:
	rts
f_01076a:
	bsr.w	f_0107b6
	tst.w	d0
	bmi.w	l_01077c
	bsr.w	f_0107e8
	bsr.w	f_010828
l_01077c:
	rts
f_01077e:
	move.l	#A_CLEAR_BUF,A_LOAD_BUFFER
	move.l	#$291c,A_LOAD_LENGTH
	move.l	#A_CLEAR_NAME,A_CUR_FILENAME
	bsr.w	f_0107a2
	rts
f_0107a2:
	bsr.w	f_0107d0
	tst.w	d0
	bmi.w	f_010768
	bsr.w	f_010808
	bsr.w	f_010828
	rts
