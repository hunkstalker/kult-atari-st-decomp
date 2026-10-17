f_01682a:
	move.l	#A_CLEAR_BUF, A_LOAD_BUFFER
	move.l	#$291c, A_LOAD_LENGTH
	move.l	#A_CLEAR_NAME, A_CUR_FILENAME
	bsr.w	f_01076a
	bmi.w	l_01686e
	movea.l	#STACK, a7
	move.b	#$00ff, A_CUR_CLASS
	bsr.w	f_016210
	move.b	#$0002, A_DAT_1ACD8
	bra.w	l_010158
l_01686e:
	move.w	#$918e, A_THE_COMMAND
	bsr.w	f_0103ae
	bra.w	f_01682a
