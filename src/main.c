/*---------------------------------------------------------------------------------


  Simple console 'hello world' demo
  -- alekmaul


---------------------------------------------------------------------------------*/
#include <snes.h>
#include "core/pallete_sprite.h"
#include "core/storage_sprite.h"
#include "core/background.h"
#include "earth.h"
#include "moon.h"
#include "cursor.h"
#include "fire_ball.h"

extern char gfxbackground, gfxbackground_end;
extern char palbackground, palbackground_end;
extern char mapbackground, mapbackground_end;

extern char gfxallsprites, gfxallsprites_end;
extern char palallsprites, palallsprites_end;

int main() {
  consoleInit();  // Importante para iniciar a VRAM corretamente

  PalleteSprite backgroundPallete = PalleteSprite_create(0, &palbackground, &palbackground_end);
  Background background = Background_create(0, &gfxbackground, &gfxbackground_end, &mapbackground, &mapbackground_end, &backgroundPallete);

  PalleteSprite pallete = PalleteSprite_create(1, &palallsprites, &palallsprites_end);
  StorageSprite storageSprite = StorageSprite_create(&gfxallsprites, &gfxallsprites_end, &pallete);

  Background_init(&background);
  StorageSprite_init(&storageSprite);


  Earth earth = Earth_create(8, (SCREEN_WIDTH / 2) - (32 / 2), (SCREEN_HEIGHT / 2) - (32 / 2));
  Earth_initSprite(&earth);

  Moon moon = Moon_create(12);
  Moon_initSprite(&moon);
  Moon_updatePosition(&moon, &earth);
  

  Cursor cursor = Cursor_create(0);
  Cursor_initSprite(&cursor);
  Cursor_updatePosition(&cursor, &earth);

  FireBall fireBall = FireBall_create(16);
  // FireBall_initSprite(&fireBall);

  setMode(BG_MODE1, 0);
  bgSetEnable(0);
  bgSetDisable(1);
  bgSetDisable(2);
  setScreenOn();

  while (1) {
    Moon_update(&moon, &earth);
    Cursor_update(&cursor, &earth, &fireBall);
    FireBall_update(&fireBall);

    Earth_renderSprite(&earth);
    Moon_renderSprite(&moon);
    Cursor_renderSprite(&cursor);
    FireBall_renderSprite(&fireBall);

    WaitForVBlank();
  }

  return 0;
}