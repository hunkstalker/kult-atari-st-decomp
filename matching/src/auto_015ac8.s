f_015ac8:
	movea.l	A_ANIM_SPR_PTR, a1
	move.w	#$18f, d1
l_015ad2:
	clr.l	(a1)+
	dbra	d1, l_015ad2
	movea.l	#A_ANIM_TBL_27FE2, a4
	clr.l	d2
	tst.w	d0
	beq.w	l_015af0
	subq.w	#$1, d0
l_015ae8:
	move.b	(a4), d2
	adda.l	d2, a4
	dbra	d0, l_015ae8
l_015af0:
	movea.l	a4, a5
	move.b	(a4), d2
	adda.l	d2, a4
	addq.l	#$1, a5
	movea.l	A_ANIM_SPR_PTR, a1
	move.b	(a5)+, (a1)+
	move.b	(a5)+, (a1)+
l_015b02:
	clr.l	d4
	move.b	(a5), d4
	cmpi.b	#$009f, d4
	bne.w	l_015b0e
l_015b0e:
	movea.l	#A_ANIM_TBL_28AD2, a1
	bsr.w	f_010f8e
	clr.l	d2
	clr.l	d3
	move.b	(a1)+, d3
	move.b	(a1)+, d2
	clr.l	d0
	move.b	$2(a5), d0
	andi.b	#$007f, d0
	ror.w	#$8, d0
	move.b	$1(a5), d0
	movea.l	A_ANIM_SPR_PTR, a0
	clr.l	d4
	move.b	(a0), d4
	lsl.l	#$1, d4
	movea.l	d4, a3
	addq.l	#$2, a0
	lsl.l	#$1, d0
	adda.l	d0, a0
	btst.b	#$7, $2(a5)
	bne.w	l_015b56
	bsr.w	f_012ad6
	bra.w	l_015b5a
l_015b56:
	bsr.w	f_012b04
l_015b5a:
	addq.l	#$3, a5
	cmpa.l	a4, a5
	bne.w	l_015b02
	rts	
	lea.l	s_015b83, a0
	move.b	#$000a, d0
l_015b6e:
	addq.b	#$5, d0
	add.b	d0, (a0)+
	cmpi.b	#$0024, (a0)
	bne.w	l_015b6e
	rts	
	move.l	$242a(a2), d2
	move.l	$2452(a2), d2
	dc.b	$4f,$47,$45,$20,$4c,$45,$20,$31,$39,$2f,$30,$34,$2f,$38,$39,$24
	dc.b	$33,$fc,$ff,$ff
	dc.l	A_ANIM_1A46E
	dc.b	$13,$fc,$00,$01
	dc.l	A_ANIM_1A578
	dc.b	$60,$34,$33,$f9
	dc.l	A_ANIM_1A478
	dc.l	A_ANIM_1A46E
	dc.b	$60,$22,$33,$fc,$00,$01
	dc.l	A_ANIM_1A46E
	dc.b	$60,$18,$30,$39
	dc.l	A_ANIM_1A476
	dc.b	$53,$40,$33,$c0
	dc.l	A_ANIM_1A46E
	dc.b	$60,$08,$33,$fc,$ff,$ff
	dc.l	A_ANIM_1A46E
	dc.b	$42,$39
	dc.l	A_ANIM_1A578
	dc.b	$42,$86,$1c,$1e,$13,$c6
	dc.l	A_ANIM_1A574
	dc.b	$02,$39,$00,$07
	dc.l	A_ANIM_1A574
	dc.b	$e6,$8e,$53,$46,$48,$e7,$02,$02,$42,$86,$1c,$1e,$30,$06,$02,$40
	dc.b	$ff,$f8,$e4,$48,$33,$c0
	dc.l	A_ANIM_1A470
	dc.b	$e2,$48,$13,$c0
	dc.l	A_ANIM_1A577
	dc.b	$33,$fc,$01,$f4
	dc.l	A_ANIM_1A56A
	dc.b	$02,$46,$00,$07,$53,$46,$2f,$06,$10,$1e,$61,$00,$fe,$6e,$1a,$00
	dc.b	$32,$39
	dc.l	A_ANIM_1A474
	dc.b	$02,$45,$00,$07,$08,$85,$00,$00,$67,$00,$00,$06,$46,$45,$52,$45
	dc.b	$d2,$45,$d2,$79
	dc.l	A_ANIM_1A47C
	dc.b	$18,$00,$30,$39
	dc.l	A_ANIM_1A472
	dc.b	$02,$44,$00,$38,$e8,$4c,$64,$00,$00,$06,$46,$44,$52,$44,$d0,$44
	dc.b	$d0,$79
	dc.l	A_ANIM_1A47A
	dc.b	$22,$79
	dc.l	A_ANIM_SPR_PTR
	dc.b	$42,$82,$42,$83,$14,$19,$16,$19,$2f,$02,$61,$00,$00,$64,$2a,$1f
	dc.b	$61,$00,$01,$2c,$2c,$1f,$08,$39,$00,$02
	dc.l	A_ANIM_1A574
	dc.b	$66,$00,$00,$1a,$08,$39,$00,$01
	dc.l	A_ANIM_1A574
	dc.b	$67,$00,$00,$18,$4a,$79
	dc.l	A_ANIM_1A46E
	dc.b	$67,$00,$00,$2a,$60,$0a,$4a,$79
	dc.l	A_ANIM_1A46E
	dc.b	$67,$00,$00,$1a,$51,$ce,$ff,$6e,$4c,$df,$40,$40,$51,$ce,$ff,$3a
	dc.b	$42,$86,$1c,$1e,$02,$06,$00,$07,$dd,$c6,$4e,$75,$61,$00,$00,$b8
	dc.b	$4c,$df,$40,$40,$42,$86,$1c,$1e,$02,$06,$00,$07,$dd,$c6,$4e,$75
	dc.b	$0c,$39,$00,$07
	dc.l	A_ANIM_1A574
	dc.b	$67,$00,$aa,$86,$3c,$39
	dc.l	A_ANIM_1A46E
	dc.b	$08,$39,$00,$02
	dc.l	A_ANIM_1A574
	dc.b	$66,$00,$00,$40,$08,$39,$00,$01
	dc.l	A_ANIM_1A574
	dc.b	$67,$00,$00,$68,$b4,$46,$67,$00,$00,$26,$08,$39,$00,$00
	dc.l	A_ANIM_1A574
	dc.b	$66,$00,$00,$10,$90,$44,$94,$46,$e3,$4a,$02,$82,$00,$00,$ff,$ff
	dc.b	$d3,$c2,$34,$06,$52,$79
	dc.l	A_ANIM_1A46E
	dc.b	$4e,$75,$42,$79
	dc.l	A_ANIM_1A46E
	dc.b	$4e,$75,$4a,$46,$67,$00,$00,$30,$08,$39,$00,$01
	dc.l	A_ANIM_1A574
	dc.b	$66,$00,$00,$26,$08,$39,$00,$00
	dc.l	A_ANIM_1A574
	dc.b	$66,$00,$00,$10,$90,$44,$94,$46,$e3,$4a,$02,$82,$00,$00,$ff,$ff
	dc.b	$d3,$c2,$34,$06,$53,$79
	dc.l	A_ANIM_1A46E
	dc.b	$4e,$75,$36,$06,$9b,$79
	dc.l	A_ANIM_1A46E
	dc.b	$64,$00,$ff,$f4,$42,$79
	dc.l	A_ANIM_1A46E
	dc.b	$4e,$75,$34,$39
	dc.l	A_ANIM_1A476
	dc.b	$36,$39
	dc.l	A_ANIM_1A478
	dc.b	$30,$39
	dc.l	A_ANIM_1A472
	dc.b	$32,$39
	dc.l	A_ANIM_1A474
	dc.b	$61,$00,$b2,$54,$61,$00,$c3,$c2,$42,$79
	dc.l	A_ANIM_1A478
	dc.b	$4e,$75
