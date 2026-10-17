f_010828:
	move.w	A_FILE_HANDLE,-(a7)
	move.w	#$3e,-(a7)
	trap	#1
	addq.l	#4,a7
	rts
