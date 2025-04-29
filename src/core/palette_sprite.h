#ifndef PALETTE_SPRITE_H
#define PALETTE_SPRITE_H

#include <snes.h>

// Estrutura para armazenar informações da Paleta
typedef struct PaletteSprite {
  u8 id;
  u8 *content;
  u8 *content_end;
} PaletteSprite;


PaletteSprite PaletteSprite_create(u8 id, u8 *content, u8 *content_end);
u16 PaletteSprite_getSize(PaletteSprite* this);
#endif // PALETTE_SPRITE_H
