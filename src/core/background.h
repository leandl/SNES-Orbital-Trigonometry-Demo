#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <snes.h>
#include "palette_sprite.h"

// Estrutura para armazenar informações do sprite
typedef struct Background {
  u8 id;

  u8 *sprite_content;
  u8 *sprite_content_end;

  u8 *map_content;
  u8 *map_content_end;

  PaletteSprite *palette;
} Background;


Background Background_create(
  u8 id,
  u8 *sprite_content,
  u8 *sprite_content_end,
  u8 *map_content,
  u8 *map_content_end,
  PaletteSprite *palette
);


void Background_init(Background* this);
u16 Background_getSpriteSize( Background* this);
u16 Background_getMapSize(Background* this);
#endif // BACKGROUND_H
