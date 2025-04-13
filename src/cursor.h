#ifndef CURSOR_H
#define CURSOR_H

#include <snes.h>
#include "earth.h"
#include "fire_ball.h"

// Estrutura principal do Cursor
typedef struct Cursor {
  u8 id;
  u16 x, y;

  u8 priority;
  u8 currentFrame;
  u16 angle;
} Cursor;


// Declaração das funções (implementação no .c)
Cursor Cursor_create(u8 id);
void Cursor_initSprite(Cursor* this);
void Cursor_renderSprite(Cursor* this);
void Cursor_update(Cursor *this, Earth *earth, FireBall *fireBall);
void Cursor_updatePosition(Cursor *this, Earth *earth);

#endif // CURSOR_H
