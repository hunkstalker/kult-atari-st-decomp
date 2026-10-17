f_03a712:
	move.w	#$2700, sr
	clr.b	$fffffa19.l
	tst.b	$fffffa19.l
	bne.w	f_03a712
	clr.b	$fffffa13.l
	clr.b	$fffffa07.l
	rts	
