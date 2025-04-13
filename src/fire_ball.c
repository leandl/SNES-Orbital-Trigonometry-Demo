#include "fire_ball.h"
#include "math/trigonometry.h"


void FireBall_initSprite(FireBall* this) {
  FireBall_renderSprite(this);
  oamSetEx(this->id, OBJ_SMALL, OBJ_SHOW);
}

void FireBall_destroySprite(FireBall* this) {
  // Esconde o sprite
  oamSetEx(this->id, OBJ_SMALL, OBJ_HIDE);
}

void FireBall_renderSprite(FireBall* this) {
  if (!this->isVisible) {
    return;
  }

  oamSet(this->id, this->x, this->y, this->priority, 0, 0, 4, 1);
}


void FireBall_disable(FireBall* this) {
  if (this->isVisible) {
    this->isVisible = false;
    FireBall_destroySprite(this);
  }
}


void FireBall_enableForAngle(FireBall* this, u16 angle) {
  if (!this->isVisible) {
    this->isVisible = true;
    this->x = (SCREEN_WIDTH / 2) - (16 / 2); // X
    this->y = (SCREEN_HEIGHT / 2) - (16 / 2);  // y
    this->angle = angle;
    FireBall_initSprite(this);
  }
}

void FireBall_update(FireBall *this) {
  if (!this->isVisible) {
    return;
  }

  if (snes_vblank_count % 20) {
    TrigonometryOrbital_computePosition(
      &this->x,
      &this->y,
      this->x,
      this->y,
      this->angle,
      10
    );
  }

  if (
    (this->x > SCREEN_WIDTH - 1) ||
    (this->y > SCREEN_HEIGHT - 1)
  ) {
    FireBall_disable(this);
  }
} 

struct FireBall FireBall_create(u8 id) {
  struct FireBall fireBall = {
    .id=id,
    .x=50,
    .y=50,
    .angle=0,
    .priority=3,
    .isVisible=false
  };

  return fireBall;
}


