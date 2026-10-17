f_0123c0:
	move.l	a0,-(a7)
	move.w	A_BLIT_MASK_FIRST,d4
	move.w	A_BLIT_GROUPS,d6
	subq.w	#1,d6
	bne.w	l_0123da
	or.w	A_BLIT_MASK_LAST,d4
l_0123da:
	move.w	d4,d5
	not.w	d5
l_0123de:
	movem.w	(a1)+,d0-d3
	and.w	d4,(a0)
	and.w	d5,d0
	or.w	d0,(a0)+
	and.w	d4,(a0)
	and.w	d5,d1
	or.w	d1,(a0)+
	and.w	d4,(a0)
	and.w	d5,d2
	or.w	d2,(a0)+
	and.w	d4,(a0)
	and.w	d5,d3
	or.w	d3,(a0)+
l_0123fa:
	subq.w	#1,d6
	bcs.w	l_012432
	beq.w	l_01240c
	move.l	(a1)+,(a0)+
	move.l	(a1)+,(a0)+
	bra.w	l_0123fa
l_01240c:
	move.w	A_BLIT_MASK_LAST,d4
	move.w	d4,d5
	not.w	d5
	movem.w	(a1)+,d0-d3
	and.w	d4,(a0)
	and.w	d5,d0
	or.w	d0,(a0)+
	and.w	d4,(a0)
	and.w	d5,d1
	or.w	d1,(a0)+
	and.w	d4,(a0)
	and.w	d5,d2
	or.w	d2,(a0)+
	and.w	d4,(a0)
	and.w	d5,d3
	or.w	d3,(a0)+
l_012432:
	movea.l	(a7)+,a0
	rts
f_012436:
	move.w	A_DAT_1A49E,A_BLIT_MASK_FIRST
	move.w	A_ANIM_1A4A0,A_BLIT_MASK_LAST
	move.w	A_SAVE_1A4A2,A_BLIT_GROUPS
	move.w	A_SAVE_1A4A4,d3
	movea.l	A_DAT_1A4B2,a0
	movea.l	#A_SAVE_DESC,a1
f_012466:
	movem.l	d3/a0-a1,-(a7)
	subq.w	#1,d3
	move.w	d3,d7
	move.w	A_BLIT_MASK_FIRST,d4
	move.w	A_BLIT_MASK_LAST,d5
l_01247a:
	movea.l	a0,a2
	movea.l	a1,a3
	move.w	A_BLIT_GROUPS,d6
	subq.w	#1,d6
	movem.w	(a1)+,d0-d3
	and.w	d4,(a0)
	or.w	d0,(a0)+
	and.w	d4,(a0)
	or.w	d1,(a0)+
	and.w	d4,(a0)
	or.w	d2,(a0)+
	and.w	d4,(a0)
	or.w	d3,(a0)+
l_01249a:
	subq.w	#1,d6
	beq.w	l_0124a8
	move.l	(a1)+,(a0)+
	move.l	(a1)+,(a0)+
	bra.w	l_01249a
l_0124a8:
	movem.w	(a1)+,d0-d3
	and.w	d5,(a0)
	or.w	d0,(a0)+
	and.w	d5,(a0)
	or.w	d1,(a0)+
	and.w	d5,(a0)
	or.w	d2,(a0)+
	and.w	d5,(a0)
	or.w	d3,(a0)+
	movea.l	a2,a0
	movea.l	a3,a1
	adda.l	#$a0,a0
	adda.l	#$40,a1
	dbra	d7,l_01247a
	bsr.w	f_013594
	movem.l	(a7)+,d3/a0-a1
	rts
