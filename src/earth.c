#include "earth.h"

void Earth_initSprite(Earth* this) {
  Earth_renderSprite(this);
  
  // Opcional: Definir visibilidade (não é estritamente necessário)
  oamSetEx(this->id, OBJ_LARGE, OBJ_SHOW);
}

void Earth_renderSprite(Earth* this) {
  oamSet(this->id, this->x, this->y, this->priority, 0, 0, 0, 1);
}

Earth Earth_create(u8 id, u16 x, u16 y) {
  Earth earth = {
    .id=id,
    .x=x,
    .y=y,
    .priority=2
  };

  return earth;  
}