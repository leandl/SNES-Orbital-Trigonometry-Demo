#include "palette_sprite.h"

u16 PaletteSprite_getSize( PaletteSprite* this) {
  return (this->content_end - this->content);
}

PaletteSprite PaletteSprite_create(u8 id, u8 *content, u8 *content_end) {
  PaletteSprite palette = {
    .id=id,
    .content=content,
    .content_end=content_end
  };

  return palette;  
};

