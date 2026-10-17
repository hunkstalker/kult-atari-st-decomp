f_012e08:
	tst.b	A_SKIP_TRANSITION
	bne.w	f_01222e
	clr.w	d0
	move.b	$1(a6), d0
	bsr.w	f_0120e4
	move.b	#$0011, A_ANIM_1A577
	addq.l	#$2, a6
	move.w	#$64, A_ANIM_1A56A
