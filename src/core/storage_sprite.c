#include "storage_sprite.h"

u16 StorageSprite_getSize(StorageSprite* this) {
  return (this->content_end - this->content);
}

void StorageSprite_init(StorageSprite* this) {
  oamInit(); 
  oamInitGfxSet(
    this->content,
    StorageSprite_getSize(this),
    this->pallete->content, 
    PalleteSprite_getSize(this->pallete),
    this->pallete->id,
    0x6000,
    OBJ_SIZE16_L32
  );
}

StorageSprite StorageSprite_create(u8 *content, u8 *content_end, PalleteSprite *pallete) {
  StorageSprite storageSprite = {
    .content=content,
    .content_end=content_end,
    .pallete=pallete
  };

  return storageSprite;  
};

