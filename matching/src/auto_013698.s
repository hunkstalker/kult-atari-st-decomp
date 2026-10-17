f_013698:
	move.b	#$00ff, A_IKBD_PACKET
	move.l	#s_01a44e, -(a7)
	clr.w	-(a7)
	move.w	#$19, -(a7)
	trap	#$e
	addq.l	#$8, a7
l_0136b0:
	cmpi.b	#$00ff, A_IKBD_PACKET
	beq.w	l_0136b0
	move.b	A_IKBD_PACKET, A_INPUT_BUTTONS
	clr.b	d0
	btst.b	#$0, A_INPUT_BUTTONS
	beq.w	l_0136e0
	ori.b	#$0004, A_INPUT_BUTTONS
	move.b	#$ffff, d0
l_0136e0:
	move.b	d0, A_SKIP_TRANSITION
	move.w	#$ff, -(a7)
	move.w	#$6, -(a7)
	trap	#$1
	addq.l	#$4, a7
	tst.w	d0
	beq.w	l_013700
	ori.b	#$0004, A_INPUT_BUTTONS
l_013700:
	rts	
