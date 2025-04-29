#ifndef FIRE_BALL_H
#define FIRE_BALL_H

#include <snes.h> 
#include "earth.h"

typedef struct FireBall {
  u8 id;
  u16 x, y;

  u16 angle;
  u8 currentFrame;
  u8 distance;
  u8 speed;

  u8 priority;

  bool isVisible;
} FireBall;

FireBall FireBall_create(u8 id);
void FireBall_initSprite(FireBall* this);
void FireBall_renderSprite(FireBall* this);
void FireBall_update(FireBall* this, Earth* earth);
void FireBall_enableForAngle(FireBall* this, u16 angle);

void FireBall_addOneInSpeed(FireBall* this);
void FireBall_removeOneInSpeed(FireBall* this);
#endif