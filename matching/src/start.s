f_010000:
	movea.l	a7,a5
	movea.l	#STACK,a7
	movea.l	4(a5),a5
	move.l	$c(a5),d0
	add.l	$14(a5),d0
	add.l	$1c(a5),d0
	addi.l	#$100,d0
	move.l	d0,-(a7)
	move.l	a5,-(a7)
	move.w	d0,-(a7)
	move.w	#$4a,-(a7)
	trap	#1
	adda.l	#$c,a7
	movea.l	#STACK,a7
	bsr.w	f_0135e2
	jsr	f_03a556
	move.l	#s_1a427,A_CUR_FILENAME
	bsr.w	f_013572
	bmi.w	l_01018e
	bsr.w	f_0135ba
	bsr.w	f_0121c6
	jsr	f_019316
	tst.w	s_1947e
l_010066:
	bne.w	l_010066
	move.l	#s_1a430,A_CUR_FILENAME
	bsr.w	f_013572
	bmi.w	l_01018e
	bsr.w	f_012292
	bsr.w	f_0135da
	bsr.w	f_0121de
l_010088:
	move.w	#$b,-(a7)
	trap	#1
	addq.l	#$2,a7
	tst.w	d0
	beq.w	l_01009e
	bsr.w	f_012324
	bra.w	l_010088
l_01009e:
	bsr.w	f_012324
	cmpi.b	#$47,d0
	bcs.w	l_0100ae
	subi.b	#$20,d0
l_0100ae:
	cmpi.b	#$44,d0
	bcs.w	l_01009e
	cmpi.b	#$47,d0
	bcc.w	l_01009e
	movea.l	#s_1a3aa,a0
	move.b	d0,4(a0)
	move.b	d0,$12(a0)
	move.b	d0,$20(a0)
	move.b	d0,$2e(a0)
	bsr.w	f_0121c6
	bsr.w	f_0106e2
	bmi.w	l_01018e
l_0100e0:
	move.w	#$918e,A_THE_COMMAND
	bsr.w	f_0103ae
l_0100ec:
	bsr.w	f_013568
	bmi.w	l_0100e0
	bsr.w	f_0106ea
	bmi.w	l_0100e0
	cmpi.l	#$78001,A_SCREEN_PTR_A
	bcs.w	l_010140
	move.w	#$7,d2
	movea.l	#s_1a4e8,a0
	move.l	#RAM54C8E,d1
l_01011a:
	movem.l	d0-d2/a0,-(a7)
	move.w	#$7,d0
	sub.w	d2,d0
	bsr.w	f_010682
	movem.l	(a7)+,d0-d2/a0
	move.l	d1,(a0)+
	add.l	A_LOAD_LENGTH,d1
	dbra	d2,l_01011a
	move.b	#$ff,s_1a57c
l_010140:
	bsr.w	f_0135da
	bsr.w	f_0121c6
	bsr.w	f_01077e
	jsr	f_03a6f4
	jsr	f_018f84
l_010158:
	bsr.w	f_013698
	btst.b	#$2,A_INPUT_BUTTONS
	bne.w	l_010158
	move.b	#$7,A_MODE_FLAG
	clr.b	A_DAT_1AD0D
	move.w	#$c001,A_THE_COMMAND
	bsr.w	f_0103ae
	bsr.w	f_016556
	bsr.w	f_010522
	bsr.w	f_0101be
l_01018e:
	bsr.w	f_0135e0
	move.l	#$0,-(a7)
	trap	#1
l_01019a:
	movem.l	d0-d7/a0-a6,-(a7)
	bsr.w	f_012324
	movem.l	(a7)+,d0-d7/a0-a6
	rts
l_0101a8:
	bsr.w	f_0106f2
	movea.l	#STACK,a7
	bsr.w	f_0135e2
	bsr.w	f_0106e2
	bra.w	l_0100ec
