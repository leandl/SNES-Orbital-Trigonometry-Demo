#ifndef STORAGE_SPRITE_H
#define STORAGE_SPRITE_H

#include <snes.h>
#include "palette_sprite.h"

// Estrutura para armazenar informações do sprite
typedef struct StorageSprite {
  u8 *content;
  u8 *content_end;
  PaletteSprite *palette[4];
} StorageSprite;


StorageSprite StorageSprite_create(u8 *content, u8 *content_end, PaletteSprite *palette, PaletteSprite *palette2);

void StorageSprite_init(StorageSprite* this);
u16 StorageSprite_getSize(StorageSprite* this);
#endif // STORAGE_SPRITE_H
