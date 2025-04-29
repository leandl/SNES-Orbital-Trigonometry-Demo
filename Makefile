ifeq ($(strip $(PVSNESLIB_HOME)),)
$(error "Please create an environment variable PVSNESLIB_HOME by following this guide: https://github.com/alekmaul/pvsneslib/wiki/Installation")
endif

include ${PVSNESLIB_HOME}/devkitsnes/snes_rules

.PHONY: bitmaps all

#---------------------------------------------------------------------------------
# ROMNAME is used in snes_rules file
export ROMNAME := $(PVSNESLIB_NAME_ROOM)

all: bitmaps $(ROMNAME).sfc

clean: cleanBuildRes cleanRom cleanGfx
	
#---------------------------------------------------------------------------------
./res/gfx/bg.pic: ./res/gfx/bg.png
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -s 8 -o 16 -u 16 -e 0 -p -m -i $<

bitmaps : ./res/gfx/bg.pic


./res/sprite/spr_all_palette1.pic: ./res/sprite/spr_all_palette1.png
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -s 32 -o 16 -u 16 -t png -i $<

bitmaps : ./res/sprite/spr_all_palette1.pic


./res/sprite/spr_all_palette2.pic: ./res/sprite/spr_all_palette2.png
	@echo convert bitmap ... $(notdir $@)
	$(GFXCONV) -s 32 -o 16 -u 16 -t png -i $<

bitmaps : ./res/sprite/spr_all_palette2.pic



./res/fonts/pvsneslibfont.pic: ./res/fonts/pvsneslibfont.png
	@echo convert font with no tile reduction ... $(notdir $@)
	$(GFXCONV) -s 8 -o 16 -u 16 -p -e 0 -i $<

bitmaps : ./res/fonts/pvsneslibfont.pic