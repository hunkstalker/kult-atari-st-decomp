f_01285a:
	movea.l	A_ELEM_CLASS, a0
	move.b	$3(a0), d2
	andi.b	#$00f8, d2
	movea.l	#A_ELEM_TBL_19E19, a0
l_01286e:
	cmp.b	(a0), d2
	beq.w	l_012882
	addq.l	#$6, a0
	cmpa.l	#A_ELEM_TBL_19EA9, a0
	beq.w	f_010768
	bra.b	l_01286e
l_012882:
	move.b	$1(a0), d1
	move.b	$2(a0), d0
	move.b	$3(a0), d3
	move.b	$4(a0), A_ELEM_1AB4C
	move.b	$5(a0), A_ELEM_1AB4D
	move.b	#$ffff, d2
	rts	
