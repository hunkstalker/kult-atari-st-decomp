f_016c00:
	move.w	#$77, d4
	move.w	#$20, d0
	move.w	#$8b, d1
	bsr.w	f_016dbc
	move.w	#$14, d3
	move.w	#$3, d2
	movea.l	a0, a3
	suba.l	#$8000, a3
	bsr.w	f_016b2e
	move.w	#$1c, d0
	move.w	#$8b, d1
	move.w	#$12, d2
	move.w	#$28, d3
	move.w	#$1, A_ANIM_1A56A
	move.b	#$0011, A_ANIM_1A577
	bra.w	f_012e2e
