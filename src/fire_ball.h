#ifndef FIRE_BALL_H
#define FIRE_BALL_H

#include <snes.h> 

typedef struct FireBall {
  u8 id;
  u16 x, y;

  u16 angle;
  u8 priority;

  bool isVisible;
} FireBall;

FireBall FireBall_create(u8 id);
void FireBall_initSprite(FireBall* this);
void FireBall_renderSprite(FireBall* this);
void FireBall_update(FireBall* this);
void FireBall_enableForAngle(FireBall* this, u16 angle);

#endif