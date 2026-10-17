f_013686:
	move.w	#4,d0
	lea.l	A_IKBD_PACKET,a1
l_013690:
	move.b	(a0)+,(a1)+
	dbra	d0,l_013690
	rts
