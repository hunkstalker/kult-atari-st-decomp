f_014748:
	cmpi.b	#$0009, A_MODE_FLAG
	bne.w	l_014758
	bsr.w	f_012d96
l_014758:
	cmpi.b	#$0066, A_MODE_FLAG
	bne.w	l_014768
	bsr.w	f_012d96
l_014768:
	cmpi.b	#$005f, A_MODE_FLAG
	bne.w	l_014778
	bsr.w	f_012dd8
l_014778:
	cmpi.b	#$0067, A_MODE_FLAG
	bne.w	l_014788
	bsr.w	f_012dd8
l_014788:
	rts	
