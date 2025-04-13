#include "pallete_sprite.h"

u16 PalleteSprite_getSize( PalleteSprite* this) {
  return (this->content_end - this->content);
}

PalleteSprite PalleteSprite_create(u8 id, u8 *content, u8 *content_end) {
  PalleteSprite pallete = {
    .id=id,
    .content=content,
    .content_end=content_end
  };

  return pallete;  
};

