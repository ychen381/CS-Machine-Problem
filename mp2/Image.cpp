#include "Image.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using namespace cs225;
#include <cmath>


void Image::lighten(){

  for(unsigned x=0;x<this->width();x++){
    for(unsigned y=0;y<this->height();y++){
      HSLAPixel *pixel=this->getPixel(x,y);
      if (pixel->l<=0.9){
        pixel->l=pixel->l+0.1;
      }
      else{
        pixel->l=1.0;
      }
    }
  }
}

void Image::lighten(double amount){
  for(unsigned x=0;x<this->width();x++){
    for(unsigned y=0;y<this->height();y++){
      HSLAPixel *pixel=this->getPixel(x,y);
      if (pixel->l<=(1-amount)){
        pixel->l=pixel->l+amount;
      }
      else{
        pixel->l=1.0;
      }
    }
  }
}

void Image::darken(){
  for(unsigned x=0;x<this->width();x++){
    for(unsigned y=0;y<this->height();y++){
      HSLAPixel *pixel=this->getPixel(x,y);
      if (pixel->l>=0.1){
        pixel->l=pixel->l-0.1;
      }
      else{
        pixel->l=0.0;
      }
    }
  }
}


void Image::darken(double amount){
  for(unsigned x=0;x<this->width();x++){
    for(unsigned y=0;y<this->height();y++){
      HSLAPixel *pixel=this->getPixel(x,y);
      if (pixel->l>=amount){
        pixel->l=pixel->l-amount;
      }
      else{
        pixel->l=0.0;
      }
    }
  }
}


void Image::saturate(){
  for(unsigned x=0;x<this->width();x++){
    for(unsigned y=0;y<this->height();y++){
        HSLAPixel *pixel=this->getPixel(x,y);
        if (pixel->s<=0.9){
          pixel->s=pixel->s+0.1;
        }
        else{
          pixel->s=1.0;
        }
      }
    }
  }

  void Image::saturate(double amount){
    for(unsigned x=0;x<this->width();x++){
      for(unsigned y=0;y<this->height();y++){
          HSLAPixel *pixel=this->getPixel(x,y);
          if (pixel->s<=(1-amount)){
            pixel->s=pixel->s+amount;
          }
          else{
            pixel->s=1.0;
          }
        }
      }
    }

  void Image::desaturate(){
    for(unsigned x=0;x<this->width();x++){
      for(unsigned y=0;y<this->height();y++){
        HSLAPixel *pixel=this->getPixel(x,y);
        if (pixel->s>=0.1){
          pixel->s=pixel->s-0.1;
        }
        else{
          pixel->s=0.0;
        }
      }
    }
  }

  void Image::desaturate(double amount){
    for(unsigned x=0;x<this->width();x++){
      for(unsigned y=0;y<this->height();y++){
        HSLAPixel *pixel=this->getPixel(x,y);
        if (pixel->s>=amount){
          pixel->s=pixel->s-amount;
        }
        else{
          pixel->s=0.0;
        }
      }
    }
  }

  void Image::grayscale(){
    for(unsigned x=0;x<this->width();x++){
      for(unsigned y=0;y<this->height();y++){
        HSLAPixel* pixel=this->getPixel(x,y);
        pixel->s=0.0;

        }
      }
    }

  void Image::rotateColor(double degrees){
    for(unsigned x=0;x<this->width();x++){
      for(unsigned y=0;y<this->height();y++){
        HSLAPixel* pixel=this->getPixel(x,y);
        if (degrees>=0.0){
        if(pixel->h+degrees>360){
          pixel->h=(pixel->h+degrees)-360;
        }
        else{
          pixel->h=pixel->h+degrees;
        }
  }
        else{
          if(pixel->h+degrees<0){
            pixel->h=360+(pixel->h+degrees);
          }
          else{
            pixel->h=pixel->h+degrees;
          }
        }
      }
  }
}


  void Image::illinify(){
    for (unsigned x = 0; x < this->width(); x++) {
      for (unsigned y = 0; y < this->height(); y++) {
        HSLAPixel* pixel=this->getPixel(x,y);
        if((pixel->h>216) & (360-pixel->h+11<pixel->h-216)){
          pixel->h=11;}
        else
        {if(abs(pixel->h-11) <abs(pixel->h-216)){
          pixel->h=11;
        }
        else{
          pixel->h=216;
        }
      }
      }
    }
  }



void Image::scale(double factor) {
    Image copy(*this);


    this->resize(factor*this->width(),factor*this->height());

    factor=factor/1.0;
    if(factor>=1.0){
      for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
          this->getPixel(x,y)->h=copy.getPixel(int(x/factor),int(y/factor))->h;
          this->getPixel(x,y)->l=copy.getPixel(int(x/factor),int(y/factor))->l;
          this->getPixel(x,y)->s=copy.getPixel(int(x/factor),int(y/factor))->s;
          this->getPixel(x,y)->a=copy.getPixel(int(x/factor),int(y/factor))->a;
        }
        }
      }
      if((factor<1.0)&(factor>0)){
        for (unsigned x=0;x<this->width();x++){
          for(unsigned y=0;y<this->height();y++){
            this->getPixel(x,y)->h=0;
            this->getPixel(x,y)->l=0;
            this->getPixel(x,y)->s=0;
            this->getPixel(x,y)->a=0;
          }
        }
        for(unsigned i=0;i<copy.width();i++){
          for(unsigned j=0;j<copy.height();j++){
            this->getPixel(int(i*factor),int(j*factor))->h=copy.getPixel(i,j)->h;
            this->getPixel(int(i*factor),int(j*factor))->l=copy.getPixel(i,j)->l;
            this->getPixel(int(i*factor),int(j*factor))->a=copy.getPixel(i,j)->a;
            this->getPixel(int(i*factor),int(j*factor))->s=copy.getPixel(i,j)->s;
          }
        }

      }
    }
void Image::scale(unsigned w, unsigned h){
  double factor;
  if(double(w)/this->width()>double(h)/this->height()){
    factor=double(h)/this->height();
  }
  else{
    factor=double(w)/this->width();
  }
  this->scale(factor);
  this->resize(w,h);


}
