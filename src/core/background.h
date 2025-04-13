#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <snes.h>
#include "pallete_sprite.h"

// Estrutura para armazenar informações do sprite
typedef struct Background {
  u8 id;

  u8 *sprite_content;
  u8 *sprite_content_end;

  u8 *map_content;
  u8 *map_content_end;

  PalleteSprite *pallete;
} Background;


Background Background_create(
  u8 id,
  u8 *sprite_content,
  u8 *sprite_content_end,
  u8 *map_content,
  u8 *map_content_end,
  PalleteSprite *pallete
);


void Background_init(Background* this);
u16 Background_getSpriteSize( Background* this);
u16 Background_getMapSize(Background* this);
#endif // BACKGROUND_H
