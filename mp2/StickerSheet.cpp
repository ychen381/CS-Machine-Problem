#include "StickerSheet.h"
#include "Image.h"
#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"
using namespace cs225;
StickerSheet::StickerSheet	(	const Image & picture,unsigned 	max )	{
  mx=max;
  count=0;

  pic=new Image;
  *pic=picture;

  sheet=new Image*[max];
  xarr=new int[max];
  yarr=new int[max];
  for(int i=0;i<mx;i++){
    sheet[i]=NULL;
    xarr[i]=0;
    yarr[i]=0;}
    std::cout << "Stickersheet" << '\n';

  }


StickerSheet::~StickerSheet	(		){
  _clear();
      std::cout << "~Stikersheet" << '\n';
}

void StickerSheet::_clear(){
  if(sheet!=NULL){for (int i=0;i<mx;i++){
    if(sheet[i]!=NULL){
    delete sheet[i];
    sheet[i]=NULL;}
  }
  delete[] sheet;
  sheet=NULL;}
  delete xarr;
  xarr=NULL;
  delete yarr;
  yarr=NULL;


  delete pic;
  pic=NULL;

}

StickerSheet::StickerSheet	(	const StickerSheet & 	other	){
    mx=other.mx;
    sheet=new Image*[other.mx];
    for(int i=0;i<mx;i++){


      if(other.sheet[i]!=NULL){


    *(sheet[i])=*((other.sheet)[i]);}
    else{
      sheet[i]=NULL;

    }}
    for(int i=0;i<count;i++){
    xarr[i]=other.xarr[i];

    yarr[i]=other.yarr[i];}
    pic=new Image;



    *pic=*(other.pic);

    count=other.count;

}

const StickerSheet& StickerSheet::operator=	(	const StickerSheet & 	other	){
if(this!=&other){
  _clear();
  mx=other.mx;
  this->sheet=new Image*[mx];
  for(int i=0;i<mx;i++){
    *(sheet[i])=*(other.sheet[i]);
      xarr[i]=other.xarr[i];
      yarr[i]=other.yarr[i];}

}

  return *this;}

void StickerSheet::changeMaxStickers	(	unsigned 	newmax	)	{
  if (newmax==mx){
    return;
  }
  if (newmax<mx){
    for (int i=newmax;i<mx;i++){
      if(sheet[i]!=NULL){
      delete sheet[i];
      sheet[i]=NULL;}
      xarr[i]=0;
      yarr[i]=0;
    }
  }
  else if(newmax>mx){
    Image** sheet2=new Image*[newmax];
    int * xarr2=new int[newmax];
    int * yarr2=new int[newmax];
    for(int i=0;i<mx;i++){
      *(sheet2[i])=*(sheet[i]);
      xarr2[i]=xarr[i];
      yarr2[i]=yarr[i];

    }
    this->_clear();
    mx=newmax;
    sheet=sheet2;
    xarr=xarr2;
    yarr=yarr2;
    sheet2=NULL;
    xarr2=NULL;
    yarr2=NULL;




  }

}
int StickerSheet::addSticker	(	Image & 	sticker,unsigned 	x,unsigned 	y ){
  int in;
  Image *tempsticker=new Image();
  *tempsticker=sticker;
  if(count<mx){
  for(int i=0;i<mx;i++){

  if(sheet[i]==NULL){
  sheet[i]=&(*tempsticker);

  xarr[i]=x;
  yarr[i]=y;
  count++;
  in=i;
  break;}
}
  std::cout << in << '\n';
  return in;}

else{
  return -1;
}



}
bool StickerSheet::translate	(	unsigned 	index,unsigned 	x,unsigned 	y )	{
  if(index>=mx||index<0||sheet[index]==NULL){
    return false;
    }
  else{
    xarr[index]=x;
    yarr[index]=y ;
    return true;
    }

}
void StickerSheet::removeSticker	(	unsigned 	index	)	{
  if(index<mx&&sheet[index]!=NULL){

    delete sheet[index];

    sheet[index]=NULL;

    count--;

  }
}
Image* StickerSheet::getSticker	(	unsigned 	index	)	const{
  if(index>=mx){
    return NULL;}
    else if(sheet[index]==NULL){

    return NULL;
  }
  else{

    return sheet[index];
  }

}
Image StickerSheet::render	(		)	const{
  int newWidth;
  int newHeight;
  for(int i=0;i<mx;i++){
    if(sheet[i]!=NULL){
        if (sheet[i]->width()+xarr[i]>pic->width()){
          newWidth=xarr[i]+sheet[i]->width();
      }
        else{
        newWidth=pic->width();
      }
          if(sheet[i]->height()+yarr[i]>pic->height()){
          newHeight=yarr[i]+sheet[i]->height();
    }
          else{
            newHeight=pic->height();
        }
    }
    else{
      newWidth=pic->width();
      newHeight=pic->height();
    }

  }


/*put base picture into base*/
    Image base;
    base.resize(newWidth,newHeight);

for (unsigned x=0;x<pic->width();x++){
  for(unsigned y=0;y<pic->height();y++){

    *base.getPixel(x,y)=*(pic->getPixel(x,y));
  }
}


for (int i=0;i<count;i++){
  if(sheet[i]!=NULL){
  for(int x=0;x<sheet[i]->width();x++){
    for(int y=0;y<sheet[i]->height();y++){
      if(base.getPixel(xarr[i],yarr[i])->a!=0){
      *(base.getPixel(xarr[i],yarr[i]))=*(sheet[i]->getPixel(x,y));}
    }
  }
}
}

return base;
}
