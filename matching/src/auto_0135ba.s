f_0135ba:
	dc.w	$a000
	dc.w	$a00a
	move.w	#$0, -(a7)
	move.l	#$ffffffff, -(a7)
	move.l	#$ffffffff, -(a7)
	move.w	#$5, -(a7)
	trap	#$e
	adda.l	#$c, a7
