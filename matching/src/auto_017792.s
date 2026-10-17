f_017792:
	movea.l	A_OBJ_BEGIN, a0
	move.b	#$0001, d2
l_01779c:
	move.b	$4(a0), d1
	and.b	d3, d1
	cmp.b	d0, d1
	beq.w	l_0177ba
	addq.l	#$8, a0
	addq.b	#$1, d2
	cmpa.l	A_OBJ_END, a0
	bne.w	l_01779c
	move.b	#$ffff, d1
l_0177ba:
	rts	
