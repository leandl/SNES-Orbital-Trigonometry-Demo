#include "cursor.h"
#include "math/trigonometry.h"

void Cursor_initSprite(Cursor* this) {
  Cursor_renderSprite(this);
  
  // Opcional: Definir visibilidade (não é estritamente necessário)
  oamSetEx(this->id, OBJ_SMALL, OBJ_SHOW);
}

const u8 NUM_CURSOR_FRAMES = 2;
u8 stpCursorFrames[] = { 6, 36 };

void Cursor_renderSprite(Cursor* this) {
  oamSet(this->id, this->x, this->y, this->priority, 0, 0, stpCursorFrames[this->currentFrame], 0);
}


void Cursor_updatePosition(Cursor *this, Earth *earth) {
  TrigonometryOrbital_computePositionEx(
    &this->x,
    &this->y,
    earth->x + (32 / 2) - (16 / 2),
    earth->y + (32 / 2) - (16 / 2),
    this->angle,
    30,
    100,
    100
  );
}

unsigned short pad0;
const u8 step = 3; 

u8 debounceUpPress = 0;
const u8 debounceUpPressTime = 30;

u8 debounceDownPress = 0;
const u8 debounceDownPressTime = 30;

void Cursor_update(Cursor *this, Earth *earth, FireBall *fireBall) {
  pad0 = padsCurrent(0);

  if (snes_vblank_count % 10 == 0) {
    this->currentFrame = (this->currentFrame + 1) % NUM_CURSOR_FRAMES;
  }

  if (!pad0) {
    return;
  }


  // FireBall
  if (pad0 & KEY_A) {
    FireBall_enableForAngle(fireBall, this->angle);
  }

  // FireBall
  if ((pad0 & KEY_UP) || (pad0 & KEY_DOWN)) {
    if ((pad0 & KEY_UP) && debounceUpPress == 0) {
      FireBall_addOneInSpeed(fireBall);
      debounceUpPress = debounceUpPressTime;
    } 
    
    if ((pad0 & KEY_DOWN) && debounceDownPress == 0) {
      FireBall_removeOneInSpeed(fireBall);
      debounceDownPress = debounceDownPressTime;
    }  
  }

  if (debounceUpPress > 0) {
    debounceUpPress--;
  }

  if (debounceDownPress > 0) {
    debounceDownPress--;
  }


  if ((pad0 & KEY_L) || (pad0 & KEY_R)) {
    if (pad0 & KEY_L) {
      this->angle = (this->angle + step) % 360;
    } 
    
    if (pad0 & KEY_R) {
      if (this->angle == 0) {
        this->angle = 360;
      }
      this->angle -= step;
    }
  }


  Cursor_updatePosition(this, earth);
} 

Cursor Cursor_create(u8 id) {
  Cursor cursor = {
    .id=id,
    .x=0,
    .y=0,
    .priority=2,
    .angle=0,
    .currentFrame=0
  };

  return cursor;  
}


