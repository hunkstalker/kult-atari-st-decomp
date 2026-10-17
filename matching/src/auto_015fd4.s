f_015fd4:
	btst.b	#$6, d7
	bne.w	l_016010
	btst.b	#$5, d7
	beq.w	l_015fe6
	add.w	d0, d6
l_015fe6:
	btst.b	#$4, d7
	beq.w	l_015ff0
	sub.w	d0, d6
l_015ff0:
	btst.b	#$3, d7
	beq.w	l_015ffa
	and.w	d0, d6
l_015ffa:
	btst.b	#$2, d7
	beq.w	l_016004
	or.w	d0, d6
l_016004:
	btst.b	#$1, d7
	beq.w	l_01600e
	eor.w	d0, d6
l_01600e:
	rts	
l_016010:
	btst.b	#$5, d7
	beq.w	l_01601e
	cmp.w	d0, d6
	beq.w	l_016068
l_01601e:
	btst.b	#$4, d7
	beq.w	l_01602c
	cmp.w	d0, d6
	bcs.w	l_016068
l_01602c:
	btst.b	#$3, d7
	beq.w	l_01603a
	cmp.w	d0, d6
	bhi.w	l_016068
l_01603a:
	btst.b	#$2, d7
	beq.w	l_016048
	cmp.w	d0, d6
	bne.w	l_016068
l_016048:
	btst.b	#$1, d7
	beq.w	l_016056
	cmp.w	d0, d6
	ble.w	l_016068
l_016056:
	btst.b	#$0, d7
	beq.w	l_016064
	cmp.w	d0, d6
	bge.w	l_016068
l_016064:
	clr.w	d6
	rts	
l_016068:
	move.w	#$ffff, d6
	rts	
