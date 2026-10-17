f_015594:
	bsr.w	f_018fa4
	bsr.w	f_016ed8
	bcc.w	l_0155ac
	move.w	#$918f, A_THE_COMMAND
	bra.w	f_0103ae
l_0155ac:
	move.w	#$90aa, A_THE_COMMAND
	bra.w	f_0103ae
