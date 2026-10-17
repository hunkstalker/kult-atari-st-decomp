f_0107b6:
	move.w	#2,-(a7)
	move.l	A_CUR_FILENAME,-(a7)
	move.w	#$3d,-(a7)
	trap	#1
	addq.l	#8,a7
	move.w	d0,A_FILE_HANDLE
	rts
f_0107d0:
	clr.w	-(a7)
	move.l	A_CUR_FILENAME,-(a7)
	move.w	#$3c,-(a7)
	trap	#1
	addq.l	#8,a7
	move.w	d0,A_FILE_HANDLE
	rts
f_0107e8:
	move.l	A_LOAD_BUFFER,-(a7)
	move.l	A_LOAD_LENGTH,-(a7)
	move.w	A_FILE_HANDLE,-(a7)
	move.w	#$3f,-(a7)
	trap	#1
	adda.l	#$c,a7
	rts
f_010808:
	move.l	A_LOAD_BUFFER,-(a7)
	move.l	A_LOAD_LENGTH,-(a7)
	move.w	A_FILE_HANDLE,-(a7)
	move.w	#$40,-(a7)
	trap	#1
	adda.l	#$c,a7
	rts
f_010828:
	move.w	A_FILE_HANDLE,-(a7)
	move.w	#$3e,-(a7)
	trap	#1
	addq.l	#4,a7
	rts
