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


const u8 NUM_FIRE_BALL_FRAMES = 4;
u8 stpFireBallFrames[4] = { 38, 40, 8, 10 };

void FireBall_renderSprite(FireBall* this) {
  if (!this->isVisible) {
    return;
  }

  oamSet(this->id, this->x, this->y, this->priority, 0, 0, stpFireBallFrames[this->currentFrame], 1);
}


void FireBall_disable(FireBall* this) {
  if (this->isVisible) {
    this->isVisible = false;
    this->distance = 0;
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

void FireBall_update(FireBall *this, Earth* earth) {
  if (!this->isVisible) {
    return;
  }

  if (snes_vblank_count % 10 == 0) {
    this->currentFrame = (this->currentFrame + 1) % NUM_FIRE_BALL_FRAMES;
  }

  TrigonometryOrbital_computePositionEx(
    &this->x,
    &this->y,
    earth->x + (32 / 2) - (16 / 2),
    earth->y + (32 / 2) - (16 / 2),
    this->angle,
    100,
    this->distance,
    this->distance
  );

  this->distance += this->speed;
  if (
    this->x >= SCREEN_WIDTH ||
    this->y >= SCREEN_HEIGHT ||
    this->x <= 0 ||
    this->y <= 0 ||
    this->distance > 200 
  ) {
    FireBall_disable(this);
  }

} 

void FireBall_addOneInSpeed(FireBall* this) {
  if (this->speed < 20) {
    this->speed += 1;
  }
}

void FireBall_removeOneInSpeed(FireBall* this) {
  if (this->speed > 1) {
    this->speed -= 1;
  }
}

struct FireBall FireBall_create(u8 id) {
  struct FireBall fireBall = {
    .id=id,
    .x=50,
    .y=50,
    .angle=0,
    .priority=3,
    .distance=0,
    .speed=1,
    .isVisible=false
  };

  return fireBall;
}


