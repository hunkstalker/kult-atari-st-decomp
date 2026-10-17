f_017a1a:
	movea.l	A_SCRIPT_END, a5
	movem.l	a5-a6, -(a7)
	move.b	#$0023, d2
	move.b	#$0014, d3
	movea.l	A_ELEM_CLASS, a0
	move.b	#$0001, s_01a57b
	cmpi.b	#$002c, $2(a0)
	beq.w	l_017aae
	move.w	A_W_1ACAA, d0
	cmpi.w	#$a015, d0
	bne.w	l_017a6a
	move.w	d0, A_THE_COMMAND
	suba.l	#A_OBJ_TBL, a0
	move.l	a0, -(a7)
	bsr.w	f_0103ae
	move.l	(a7)+, d0
	bsr.w	f_0177bc
l_017a6a:
	cmpi.w	#$c357, A_DAT_1ABF8
	bne.w	l_017a84
	move.w	A_DAT_1ABF8, A_THE_COMMAND
	bsr.w	f_0103ae
l_017a84:
	cmpi.b	#$0038, $2(a0)
	beq.w	l_017aae
	cmpi.b	#$0033, $2(a0)
	beq.w	l_017aae
	move.w	s_01a858, d2
	addi.b	#$0010, d2
	move.w	s_01a85a, d3
	clr.b	s_01a57b
l_017aae:
	movea.l	#s_019968, a6
	move.b	d2, $2(a6)
	move.b	d3, $3(a6)
	bsr.w	f_011f98
	bsr.w	f_018a30
	movea.l	A_ELEM_CLASS, a0
	cmpi.b	#$002c, $2(a0)
	beq.w	l_017afa
	cmpi.b	#$0038, $2(a0)
	beq.w	l_017afa
	cmpi.b	#$0033, $2(a0)
	beq.w	l_017afa
	move.w	#$1, d0
	bsr.w	f_0120e4
	bsr.w	f_01215e
	movea.l	A_ELEM_CLASS, a0
l_017afa:
	movea.l	#s_01a69d, a1
	clr.b	d1
	clr.b	s_01ad02
	tst.b	s_01ad03
	bne.w	l_017b4a
	clr.l	d0
	move.b	$2(a0), d0
	subi.b	#$002a, d0
	move.b	(a1, d0.l), d1
	cmpi.b	#$0001, d1
	beq.w	l_017b34
	btst.b	#$7, $1(a0)
	beq.w	l_017b34
	subq.b	#$1, d1
l_017b34:
	tst.b	A_DAT_1ACF7
	bne.w	l_017b48
	tst.b	A_DAT_1AD2C
	beq.w	l_017b4a
l_017b48:
	subq.b	#$1, d1
l_017b4a:
	cmpi.b	#$0005, d1
	beq.w	l_017b98
	move.b	$4(a0), d2
	cmpi.b	#$0013, d2
	bcs.w	l_017b66
	cmpi.b	#$0017, d2
	bcs.w	l_017b96
l_017b66:
	cmpi.b	#$0027, d2
	bcs.w	l_017b76
	cmpi.b	#$0034, d2
	bcs.w	l_017b96
l_017b76:
	cmpi.b	#$0038, d2
	beq.w	l_017b96
	cmpi.b	#$0039, d2
	beq.w	l_017b96
	move.b	$3(a0), d2
	andi.b	#$00f8, d2
	cmpi.b	#$0030, d2
	bne.w	l_017b98
l_017b96:
	addq.b	#$1, d1
l_017b98:
	move.b	#$0001, d2
	move.b	A_DAT_1ACD7, d3
	tst.b	d1
	beq.w	l_017c28
	cmpi.b	#$0001, d1
	beq.w	l_017c28
	cmpi.b	#$0002, d1
	bne.w	l_017bd8
	cmpi.b	#$00cd, d3
	bcs.w	l_017c28
l_017bc0:
	move.b	#$0051, d2
	bsr.w	f_016210
	cmpi.b	#$0080, d0
	bcs.w	l_017c28
	move.b	#$0052, d2
	bra.w	l_017c28
l_017bd8:
	cmpi.b	#$0004, d1
	bne.w	l_017be8
	cmpi.b	#$0064, d3
	bcs.w	l_017bc0
l_017be8:
	move.b	#$0002, d2
	cmpi.b	#$0003, d1
	bne.w	l_017c28
	cmpi.b	#$0080, d3
	bcs.w	l_017c14
	move.b	#$0031, d2
	bsr.w	f_016210
	cmpi.b	#$00cd, d0
	bcs.w	l_017c28
	move.b	#$0032, d2
	bra.w	l_017c28
l_017c14:
	move.b	#$0091, d2
	bsr.w	f_016210
	cmpi.b	#$0033, d0
	bcs.w	l_017c28
	move.b	#$0092, d2
l_017c28:
	move.b	d2, s_01ad02
	move.b	d1, d0
	bsr.w	f_0160c0
	movem.l	(a7)+, a5-a6
	move.l	a5, A_SCRIPT_END
	addq.l	#$1, a6
	rts	
