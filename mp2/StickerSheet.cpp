#include "StickerSheet.h"
#include "Image.h"
#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"
using namespace cs225;
StickerSheet::StickerSheet	(	const Image & picture,unsigned 	max )	{
  mx=max;
  count=0;

  pic=new Image(picture);

  sheet=new Image*[max];
  xarr=new int[max];
  yarr=new int[max];
  for(int i=0;i<mx;i++){
    sheet[i]=NULL;
    xarr[i]=0;
    yarr[i]=0;}


  }


StickerSheet::~StickerSheet	(		){
  _clear();

}

void StickerSheet::_clear(){
  if(sheet!=NULL){for (int i=0;i<mx;i++){
    if(sheet[i]!=NULL){
    delete sheet[i];
    sheet[i]=NULL;}
  }
  delete[] sheet;
  sheet=NULL;}
  delete[] xarr;
  xarr=NULL;
  delete[] yarr;
  yarr=NULL;
  delete pic;
  pic=NULL;


}

StickerSheet::StickerSheet	(	const StickerSheet & 	other	){
    mx=other.mx;

    pic=new Image(*(other.pic));
    sheet=new Image*[mx];
    xarr=new int[mx];
    yarr=new int[mx];
    for(int i=0;i<mx;i++){

        if(other.sheet[i]!=NULL){
          sheet[i]=new Image(*(other.sheet[i]));

          xarr[i]=other.xarr[i];

          yarr[i]=other.yarr[i];}
        else{
          sheet[i]=NULL;
          xarr[i]=other.xarr[i];
          yarr[i]=other.yarr[i];
        }}

    count=other.count;


}

const StickerSheet& StickerSheet::operator=	(	const StickerSheet & 	other	){
if(this!=&other){


  mx=other.mx;

  pic=new Image(*(other.pic));
  sheet=new Image*[mx];
  xarr=new int[mx];
  yarr=new int[mx];
  for(int i=0;i<mx;i++){

      if(other.sheet[i]!=NULL){
        sheet[i]=new Image(*(other.sheet[i]));

        xarr[i]=other.xarr[i];

        yarr[i]=other.yarr[i];}
      else{
        sheet[i]=NULL;
        xarr[i]=other.xarr[i];
        yarr[i]=other.yarr[i];
      }}

  count=other.count;

}

  return *this;}

void StickerSheet::changeMaxStickers	(	unsigned 	newmax	)	{
  if (newmax==mx){
    return;
  }
  else if (newmax<mx){

    int *tempx=new int[newmax];
    int *tempy=new int[newmax];
    Image **tempsheet1=new Image*[newmax];
    for (int i=0;i<newmax;i++){
      if(sheet[i]!=NULL){
      tempsheet1[i]=new Image(*sheet[i]);}
      else{
        tempsheet1[i]=NULL;
      }
      tempx[i]=xarr[i];
      tempy[i]=yarr[i];
      }
      delete[] sheet;
      sheet=NULL;
      delete[]  xarr;
      xarr=NULL;
      delete[]  yarr;
      yarr=NULL;
      sheet=new Image*[newmax];
      xarr=new int[newmax];
      yarr=new int[newmax];
      for(int i=0;i<newmax;i++){
        if(tempsheet1[i]!=NULL){
        sheet[i]=new Image(*tempsheet1[i]);}
        else{
          sheet[i]=NULL;        }
        xarr[i]=tempx[i];
        yarr[i]=tempy[i];
      }
      delete[] tempy;
      delete[] tempx;
      delete[] tempsheet1;
    }
  else {

    Image** tempsheet2=new Image*[newmax];

    int * xarr2=new int[newmax];

    int * yarr2=new int[newmax];

    for(int i=0;i<mx;i++){

      if(sheet[i]!=NULL){

      tempsheet2[i]=new Image(*sheet[i]);
    }
      else{

        tempsheet2[i]=NULL;

      }
      xarr2[i]=xarr[i];
      yarr2[i]=yarr[i];

    }
    for(int i=mx;i<newmax;i++){

      tempsheet2[i]=NULL;

    }
    delete[] sheet;
    sheet=NULL;

    delete[] xarr;
    xarr=NULL;

    delete[] yarr;
    yarr=NULL;

    sheet=new Image*[newmax];
    xarr=new int[newmax];
    yarr=new int[newmax];
    for(int i=0;i<newmax;i++){
      if(tempsheet2[i]!=NULL){
      sheet[i]=new Image(*tempsheet2[i]);}
      else{
        sheet[i]=NULL;
      }
      xarr[i]=xarr2[i];
      yarr[i]=yarr2[i];
    }

    delete[] tempsheet2;
    delete[] xarr2;
    delete[] yarr2;
    }
    mx=newmax;

}
int StickerSheet::addSticker	(	Image & 	sticker,unsigned 	x,unsigned 	y ){
  int in;

  if(count<mx){


  for(int i=0;i<mx;i++){

  if(sheet[i]==NULL){
  sheet[i]=new Image(sticker);

  xarr[i]=x;
  yarr[i]=y;
  count++;
  in=i;
  break;}
}


  return in;}

else{
  return -1;
}



}
bool StickerSheet::translate	(	unsigned 	index,unsigned 	x,unsigned 	y )	{
  if(index<mx && sheet[index]!=NULL){
    xarr[index]=x;
    yarr[index]=y;
    return true;
    }
  else{
    return false;
    }

}
void StickerSheet::removeSticker	(	unsigned 	index	)	{
  if(index<mx && sheet[index]!=NULL){


    delete sheet[index];

    sheet[index]=NULL;
    xarr[index]=0;
    yarr[index]=0;
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
  int newWidth=pic->width();
  int newHeight=pic->height();
  for(int i=0;i<mx;i++){
    if(sheet[i]!=NULL){
        if ((sheet[i]->width()+xarr[i])>newWidth){
          newWidth=xarr[i]+sheet[i]->width();
      }

          if((sheet[i]->height()+yarr[i])>newHeight){
          newHeight=yarr[i]+sheet[i]->height();
    }

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




for (int i=0;i<mx;i++){
  if(sheet[i]!=NULL){
  for(int x=0;x<sheet[i]->width();x++){
    for(int y=0;y<sheet[i]->height();y++){
      if(sheet[i]->getPixel(x,y)->a!=0.0){
      *(base.getPixel(xarr[i]+x,yarr[i]+y))=*(sheet[i]->getPixel(x,y));}
    }
  }
}
}

return base;
}
