#include "moon.h"
#include "math/trigonometry.h"


void Moon_initSprite(Moon* this) {
  Moon_renderSprite(this);
  oamSetEx(this->id, OBJ_SMALL, OBJ_SHOW);
}

void Moon_destroySprite(Moon* this) {
  // Esconde o sprite
  oamSetEx(this->id, OBJ_SMALL, OBJ_HIDE);
}

void Moon_renderSprite( Moon* this) {
  oamSet(this->id, this->x, this->y, this->priority, 0, 0, 4, 0);
}


void Moon_updatePosition(Moon *this, Earth *earth) {
  TrigonometryOrbital_computePositionEx(
    &this->x,
    &this->y,
    earth->x + (32 / 2) - (16 / 2),
    earth->y + (32 / 2) - (16 / 2),
    this->angle,
    60,
    this->xScale,
    this->yScale
  );
}

void Moon_update(Moon *this , Earth *earth) {
  this->angle = (this->angle + 1) % 360;
  
  if (this->angle < 270 && this->angle > 90) {
    if (this->id != 12) {
      Moon_destroySprite(this);

      this->id = 12;
      Moon_initSprite(this);
    }
  } else {
    if (this->id != 4) {
      Moon_destroySprite(this);

      this->id = 4;
      Moon_initSprite(this);
    }
  }


  Moon_updatePosition(this, earth);
} 

struct Moon Moon_create(u8 id) {
  struct Moon moon = {
    .id=id,
    .x=0,
    .y=0,
    .angle=0,
    .priority=3,
    .xScale=100,
    .yScale=16
  };

  return moon;
}


