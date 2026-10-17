f_01929a:
	move.w	#$2700, sr
	move.b	d0, $8800.w
	cmpi.b	#$0007, d0
	bne.b	l_0192b8
	move.w	d0, -(a7)
	move.b	$8802.w, d0
	eor.b	d0, d1
	andi.b	#$003f, d1
	eor.b	d0, d1
	move.w	(a7)+, d0
l_0192b8:
	move.b	d1, $8802.w
	rts	
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
	ori.b	#$0000, d0
