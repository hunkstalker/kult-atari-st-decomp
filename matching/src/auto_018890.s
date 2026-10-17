f_018890:
	movea.l	#$0, a4
l_018896:
	move.l	a4, -(a7)
	move.l	#A_SAVE_DESC, A_ANIM_SPR_PTR
	clr.w	d0
	move.b	$1(a6), d0
	bsr.w	f_015ac8
	movea.l	(a7)+, a4
	clr.w	d0
	clr.w	d1
	move.b	$2(a6), d0
	move.b	$3(a6), d1
	movea.l	#A_SAVE_DESC, a1
	move.w	(a1), d2
	ror.w	#$8, d2
	move.w	d2, (a1)
	bsr.w	f_011030
	addq.l	#$4, a6
	rts	
