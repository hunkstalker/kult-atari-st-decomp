f_0193e4:
	move.l	a1, d1
	move.b	d1, $ff860d.l
	ror.w	#$8, d1
	move.b	d1, $ff860b.l
	swap	d1
	move.b	d1, $ff8609.l
	move.w	#$84, $2(a0)
	bsr.w	f_019474
	move.w	d0, (a0)
	bsr.w	f_019474
	move.w	#$90, $2(a0)
	move.w	#$190, $2(a0)
	move.w	#$90, $2(a0)
	move.w	#$1, (a0)
	bsr.w	f_019474
	move.w	#$80, $2(a0)
	bsr.w	f_019474
	move.w	#$80, (a0)
	bra.w	f_019462
