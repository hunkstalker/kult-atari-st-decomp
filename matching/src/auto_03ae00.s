f_03ae00:
	movea.l	$8(a3), a0
	move.b	(a0)+, d0
	move.b	(a0)+, d1
	move.l	a0, $8(a3)
	movea.l	$18(a3), a0
	move.w	d0, d2
	andi.w	#$3f, d2
	move.b	d2, $3(a0)
	move.b	d2, $0(a0)
	move.w	d1, d2
	andi.w	#$3f, d2
	move.b	d2, $4(a0)
	rol.b	#$4, d0
	andi.w	#$c, d0
	rol.b	#$2, d1
	andi.w	#$3, d1
	or.w	d1, d0
	move.b	d0, $1(a0)
	move.b	d0, $2(a0)
	st.b	$5(a0)
	move.b	$3(a0), d0
	cmp.b	$4(a0), d0
	bcc.b	l_03ae52
	move.b	#$0001, $5(a0)
l_03ae52:
	lea.l	s_03aec0, a2
	move.b	(a2, d7.w), d4
	lsl.w	#$3, d4
	not.w	d4
	and.b	d4, $6(a0)
	bra.w	l_03ab3a
