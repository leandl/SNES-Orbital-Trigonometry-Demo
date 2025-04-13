#include "background.h"

u16 Background_getSpriteSize( Background* this) {
  return (this->sprite_content_end - this->sprite_content);
}

u16 Background_getMapSize( Background* this) {
  return (this->map_content_end - this->map_content);
}

void Background_init( Background* this) {
  bgInitTileSet(
    this->id,
    this->sprite_content,
    this->pallete->content,
    this->pallete->id, 
    Background_getSpriteSize(this), 
    PalleteSprite_getSize(this->pallete), 
    BG_16COLORS,
    0x1000
  );

  bgInitMapSet(this->id, this->map_content, Background_getMapSize(this), SC_32x32, 0x0000);
}

Background Background_create(
  u8 id,
  u8 *sprite_content,
  u8 *sprite_content_end,
  u8 *map_content,
  u8 *map_content_end,
  PalleteSprite  *pallete
) {
  Background storageSprite = {
    .id=id,
    .sprite_content=sprite_content,
    .sprite_content_end=sprite_content_end,
    .map_content=map_content,
    .map_content_end=map_content_end,
    .pallete=pallete
  };

  return storageSprite;  
};

