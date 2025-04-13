#ifndef PALLETE_SPRITE_H
#define PALLETE_SPRITE_H

#include <snes.h>

// Estrutura para armazenar informações da Paleta
typedef struct PalleteSprite {
  u8 id;
  u8 *content;
  u8 *content_end;
} PalleteSprite;


PalleteSprite PalleteSprite_create(u8 id, u8 *content, u8 *content_end);
u16 PalleteSprite_getSize(PalleteSprite* this);
#endif // PALLETE_SPRITE_H
