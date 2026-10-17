f_019474:
	move.w	#$22, d7
l_019478:
	dbra	d7, l_019478
	rts	
s_1947e:
	ori.b	#$0000, d0
	ori.b	#$5354, d0
	dc.b	$41,$52,$54,$45,$52,$2e,$f0,$f1,$f2,$f3,$f4,$f5,$f6,$f7,$f8,$f9
	dc.b	$fa,$fb,$fc,$fd,$fe,$ff
