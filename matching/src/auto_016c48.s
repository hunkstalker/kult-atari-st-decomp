f_016c48:
	move.w	#$3, d4
	move.w	#$23, d0
	move.w	#$ad, d1
	tst.b	$1(a6)
	beq.w	l_016c60
	addi.w	#$4, d1
l_016c60:
	bsr.w	f_016dbc
	move.w	#$8, d3
	move.w	#$2, d2
