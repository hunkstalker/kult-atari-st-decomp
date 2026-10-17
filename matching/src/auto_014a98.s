f_014a98:
	move.l	a0, -(a7)
	lsl.l	#$2, d0
	movea.l	#s_0196dc, a0
	adda.l	d0, a0
	move.w	(a0), A_CLIP_X
	move.w	$2(a0), A_CLIP_Y
	lsl.l	#$4, d0
	movea.l	#s_01949c, a0
	adda.l	d0, a0
	move.l	a0, A_CURSOR_SPRITE_PTR
	movea.l	(a7)+, a0
	rts	
