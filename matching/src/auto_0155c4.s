f_0155c4:
	bsr.w	f_018fa4
	bsr.w	f_016fb4
	bcc.w	l_0155ac
	move.w	#$9190, A_THE_COMMAND
	bra.w	f_0103ae
