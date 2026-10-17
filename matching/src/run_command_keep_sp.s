f_0103ae:
	clr.l	d1
	move.w	A_THE_COMMAND,d1
	beq.w	f_010768
	move.w	d1,d2
	andi.w	#$f000,d2
	cmpi.w	#0,d2
	beq.w	l_010420
	cmpi.w	#$a000,d2
	beq.w	l_01040a
	cmpi.w	#$b000,d2
	beq.w	l_01040a
	cmpi.w	#$9000,d2
	beq.w	f_010440
	cmpi.w	#$f000,d2
	bne.w	l_0103ee
	movea.l	A_RUN_STACK,a7
l_0103ee:
	andi.w	#$3ff,d1
	subq.l	#1,d1
	movea.l	#A_TEMPL_DATA,a4
	bsr.w	f_012950
	movea.l	a5,a6
	move.l	a4,A_SCRIPT_END
	bra.w	f_010630
l_01040a:
	andi.w	#$3ff,d1
	subq.b	#1,d1
	lsl.w	#2,d1
	movea.l	#cmd_jump_table,a1
	movea.l	(a1,d1.l),a1
	jsr	(a1)
	rts
l_010420:
	movea.l	#A_TEMPL_DATA,a6
	adda.l	d1,a6
	bra.w	f_010630
