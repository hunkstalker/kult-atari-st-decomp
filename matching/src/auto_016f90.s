f_016f90:
	movea.l	#A_CLEAR_BUF, a0
	movea.l	#s_01a82e, a1
l_016f9c:
	tst.l	(a0)
	beq.w	l_016faa
	move.l	a0, d0
	addi.l	#s_0101a8, (a0)
l_016faa:
	addq.l	#$4, a0
	cmpa.l	a0, a1
	bne.w	l_016f9c
	rts	
