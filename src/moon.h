#ifndef MOON_H
#define MOON_H

#include "earth.h" // Caso precise usar referência à Terra

typedef struct Moon {
  u8 id;
  u16 x, y;

  u16 angle;
  u8 priority;

  u8 xScale, yScale;
 
  
} Moon;

Moon Moon_create(u8 id);
void Moon_initSprite(Moon* this);
void Moon_renderSprite(Moon* this);
void Moon_update(Moon* this, Earth* earth);
void Moon_updatePosition(Moon *this, Earth *earth);

#endif