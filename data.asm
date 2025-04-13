.include "hdr.asm"

.section ".background1" superfree

gfxbackground:
.incbin "res/gfx/bg.pic"
gfxbackground_end:

.ends

.section ".background2" superfree

mapbackground:
.incbin "res/gfx/bg.map"
mapbackground_end:

palbackground:
.incbin "res/gfx/bg.pal"
palbackground_end:

.ends


.section ".sprites" superfree

gfxallsprites:
.incbin "res/sprite/spr_all.pic"
gfxallsprites_end:

palallsprites:
.incbin "res/sprite/spr_all.pal"
palallsprites_end:


tilfont:
.incbin "res/fonts/pvsneslibfont.pic"

palfont:
.incbin "res/fonts/pvsneslibfont.pal"

.ends
