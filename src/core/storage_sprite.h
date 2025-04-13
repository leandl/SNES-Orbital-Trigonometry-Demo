#ifndef STORAGE_SPRITE_H
#define STORAGE_SPRITE_H

#include <snes.h>
#include "pallete_sprite.h"

// Estrutura para armazenar informações do sprite
typedef struct StorageSprite {
  u8 *content;
  u8 *content_end;
  PalleteSprite *pallete;
} StorageSprite;


StorageSprite StorageSprite_create(u8 *content, u8 *content_end, PalleteSprite *pallete);

void StorageSprite_init(StorageSprite* this);
u16 StorageSprite_getSize(StorageSprite* this);
#endif // STORAGE_SPRITE_H
