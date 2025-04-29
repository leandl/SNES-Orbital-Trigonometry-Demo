#include "storage_sprite.h"

u16 StorageSprite_getSize(StorageSprite* this) {
  return (this->content_end - this->content);
}

void StorageSprite_init(StorageSprite* this) {
  oamInit(); 

  u8 i = 0;
  while (this->palette[i] != NULL) {
    oamInitGfxSet(
      this->content,
      StorageSprite_getSize(this),
      this->palette[i]->content, 
      PaletteSprite_getSize(this->palette[i]),
      this->palette[i]->id,
      0x6000,
      OBJ_SIZE16_L32
    );

    
    i++;
  }
}

StorageSprite StorageSprite_create(u8 *content, u8 *content_end, PaletteSprite *palette, PaletteSprite *palette2) {
  StorageSprite storageSprite = {
    .content=content,
    .content_end=content_end,
    .palette={palette, palette2, NULL, NULL}
  };

  return storageSprite;  
};

