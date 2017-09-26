#ifndef STICKERSHEET_H
#define STICKERSHEET_H
#include "Image.h"
using namespace cs225;
class StickerSheet{
public:
  StickerSheet(const Image& picture,unsigned max);
  ~StickerSheet();
  StickerSheet(const StickerSheet & other);
  const StickerSheet& operator=(const StickerSheet & other);
  void changeMaxStickers(unsigned newmax);
  int addSticker(Image & sticker,unsigned x,unsigned y);
  bool translate(unsigned index,unsigned x, unsigned y);
  void removeSticker(unsigned index);
  Image* getSticker(unsigned index)const;
  Image render()const;
  void _clear();
private:
  int mx;
  Image **sheet;
  Image *pic;
  int *xarr;
  int *yarr;
  int count;



};

#endif
