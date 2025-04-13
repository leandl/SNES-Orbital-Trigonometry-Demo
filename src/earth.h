#ifndef EARTH_H
#define EARTH_H

#include <snes.h>

// Estrutura principal da Terra
typedef struct Earth {
  u8 id;
  u16 x, y;
  u8 priority;
} Earth;


// Declaração das funções (implementação no .c)
Earth Earth_create(u8 id, u16 x, u16 y);
void Earth_initSprite(Earth* this);
void Earth_renderSprite(Earth* this);

#endif // EARTH_H
