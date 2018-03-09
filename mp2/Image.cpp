#include <iostream>
#include <string>
#include <cmath>
#include "Image.h"

void Image::lighten(){
  PNG * pic = this;
  cs225::HSLAPixel * newImageData = new cs225::HSLAPixel[pic->width() * pic->height()];
  for (unsigned x = 0; x < pic->width(); x++) {
    for (unsigned y = 0; y < pic->height(); y++) {
        cs225::HSLAPixel & pixel = pic->getPixel(x, y);
        if(pixel.l<0.9){
        pixel.l+=0.1;
      }
      else{
        pixel.l=1.0;
      }

      }
    }
  }

void Image::lighten(double amount){
  PNG * pic = this;
  cs225::HSLAPixel * newImageData = new cs225::HSLAPixel[pic->width() * pic->height()];
  for (unsigned x = 0; x < pic->width(); x++) {
    for (unsigned y = 0; y < pic->height(); y++) {
        cs225::HSLAPixel & pixel = pic->getPixel(x, y);
        if(pixel.l<(1-amount)){
        pixel.l+=amount;
      }
      else{
        pixel.l=1.0;
      }

      }
    }
}
void Image::darken(){
  PNG * pic = this;
  cs225::HSLAPixel * newImageData = new cs225::HSLAPixel[pic->width() * pic->height()];
  for (unsigned x = 0; x < pic->width(); x++) {
    for (unsigned y = 0; y < pic->height(); y++) {
        cs225::HSLAPixel & pixel = pic->getPixel(x, y);
        if(pixel.l>0.1){
        pixel.l-=0.1;
      }
      else{
        pixel.l=0.0;
      }

      }
    }
}
void Image::darken(double amount){
  PNG * pic = this;
  cs225::HSLAPixel * newImageData = new cs225::HSLAPixel[pic->width() * pic->height()];
  for (unsigned x = 0; x < pic->width(); x++) {
    for (unsigned y = 0; y < pic->height(); y++) {
        cs225::HSLAPixel & pixel = pic->getPixel(x, y);
        if(pixel.l>(amount)){
        pixel.l-=amount;
      }
      else{
        pixel.l=0.0;
      }

      }
    }
}
void Image::saturate(){
  PNG * pic = this;
  cs225::HSLAPixel * newImageData = new cs225::HSLAPixel[pic->width() * pic->height()];
  for (unsigned x = 0; x < pic->width(); x++) {
    for (unsigned y = 0; y < pic->height(); y++) {
        cs225::HSLAPixel & pixel = pic->getPixel(x, y);
        if(pixel.s<0.9){
        pixel.s+=0.1;
      }
      else{
        pixel.s=1.0;
      }

      }
    }
}
void Image::saturate(double amount){
  PNG * pic = this;
  cs225::HSLAPixel * newImageData = new cs225::HSLAPixel[pic->width() * pic->height()];
  for (unsigned x = 0; x < pic->width(); x++) {
    for (unsigned y = 0; y < pic->height(); y++) {
        cs225::HSLAPixel & pixel = pic->getPixel(x, y);
        if(pixel.s<(1-amount)){
        pixel.s+=amount;
      }
      else{
        pixel.s=1.0;
      }

      }
    }
}
void Image::desaturate(){
  PNG * pic = this;
  cs225::HSLAPixel * newImageData = new cs225::HSLAPixel[pic->width() * pic->height()];
  for (unsigned x = 0; x < pic->width(); x++) {
    for (unsigned y = 0; y < pic->height(); y++) {
        cs225::HSLAPixel & pixel = pic->getPixel(x, y);
        if(pixel.s>0.1){
        pixel.s-=0.1;
      }
      else{
        pixel.s=0.0;
      }

      }
    }
}
void Image::desaturate (double amount){
  PNG * pic = this;
  cs225::HSLAPixel * newImageData = new cs225::HSLAPixel[pic->width() * pic->height()];
  for (unsigned x = 0; x < pic->width(); x++) {
    for (unsigned y = 0; y < pic->height(); y++) {
        cs225::HSLAPixel & pixel = pic->getPixel(x, y);
        if(pixel.s>amount){
        pixel.s-=amount;
      }
      else{
        pixel.s=0.0;
      }

      }
    }
}
void Image::grayscale(){
  PNG * pic = this;
  cs225::HSLAPixel * newImageData = new cs225::HSLAPixel[pic->width() * pic->height()];
  for (unsigned x = 0; x < pic->width(); x++) {
    for (unsigned y = 0; y < pic->height(); y++) {

        cs225::HSLAPixel & pixel = pic->getPixel(x, y);
        pixel.s=0;
      }
    }
}
void Image::rotateColor (double degrees){
  PNG * pic = this;
  cs225::HSLAPixel * newImageData = new cs225::HSLAPixel[pic->width() * pic->height()];
  for (unsigned x = 0; x < pic->width(); x++) {
    for (unsigned y = 0; y < pic->height(); y++) {
        cs225::HSLAPixel & pixel = pic->getPixel(x, y);
        if(degrees>360.0){
          degrees = std::fmod(degrees,360.0);
        }
        else if(degrees<0.0){
          degrees=(360.0)-(std::fmod(std::abs(degrees),360.0));
        }

        pixel.h+=degrees;

        if (pixel.h>360){
          pixel.h-=360;
        }
        else if(pixel.h<0){
          pixel.h+=360;
        }

      }
    }
}
void Image::illinify(){
  PNG * pic = this;
  cs225::HSLAPixel * newImageData = new cs225::HSLAPixel[pic->width() * pic->height()];
  for (unsigned x = 0; x < pic->width(); x++) {
    for (unsigned y = 0; y < pic->height(); y++) {
        cs225::HSLAPixel & pixel = pic->getPixel(x, y);
        if((pixel.h<113.5)||(pixel.h>296.5)){
          pixel.h=11;
        }
        else if((pixel.h>113.5)||(pixel.h<296.5)){
          pixel.h=216;
        }
    }
  }
}
void Image::scale(double factor){
  Image * newImage = new Image;
  newImage->resize(this->width(), this->height());
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & oldPixel = this->getPixel(x,y);
      cs225::HSLAPixel & newPixel = newImage->getPixel(x,y);

      newPixel=oldPixel;
    }
  }

  this->resize(factor*this->width(), factor*this->height());
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & oldPixel = this->getPixel(x,y);
      oldPixel = newImage->getPixel(x/factor,y/factor);
    }
  }
  delete newImage;

  // pic->resize(scaled_width, scaled_height);
  // cs225::HSLAPixel * newImageData = new cs225::HSLAPixel[scaled_width * scaled_height];
  // cs225::HSLAPixel * oldImageData = new cs225::HSLAPixel[pic->width() * pic->height()];
//  unsigned int new_width= (int)(factor*100)/100 * pic->width();
//  unsigned int new_height = (int)(factor*100)/100 * pic->height();
//
//   cs225::HSLAPixel * newImageData = new cs225::HSLAPixel[new_width * new_height];
//
// pic->resize(new_width, new_height);
//   for (unsigned x = 0; x < new_width; x++) {
//     for (unsigned y = 0; y < new_height; y++) {
//       // int sourceImageX = (int)(x * 1.0 /factor);
      // int sourceImageY = (int)(y * 1.0 / factor);
      // // newImageData[y * scaled_width + x] = pic[sourceImageY * pic->width() + sourceImageX];
      //
      // cs225::HSLAPixel & oldPixel = oldImageData[sourceImageY * pic->width() + sourceImageX];
      // cs225::HSLAPixel & newPixel = newImageData[y * scaled_width + x];
      // newPixel=oldPixel;

        // // cs225::HSLAPixel & oldPixel = pic->getPixel(scaleWidth, scaleHeight);
        // cs225::HSLAPixel & oldPixel = pic->getPixel(x/factor, y/factor);
        // cs225::HSLAPixel & newPixel = pic->getPixel();
        //
        // newPixel=oldPixel;
        //




  // for (unsigned x = 0; x < pic->width(); x++) {
  //   for (unsigned y = 0; y < pic->height(); y++) {
  //     // if (x < pic->width() && y < pic->height()){
  //       // cs225::HSLAPixel & oldPixel = pic->getPixel(x, y);
  //       // cs225::HSLAPixel & newPixel = pic->getPixel(x*((unsigned int)(factor*100)/100),y*((unsigned int)(factor*100)/100));
  //       // newPixel=oldPixel;
  //       // newImageData[ (x + (y * newWidth)) ]
  //       // pic->resize(x*(unsigned int)(factor*100)/100, y*(unsigned int)(factor*100)/100);
  //       //HMMMMMMM
  //     // }

    // }
  // }
}
//
void Image::scale(unsigned w, unsigned h){
  Image * newImage = new Image;
  newImage->resize(this->width(), this->height());
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & oldPixel = this->getPixel(x,y);
      cs225::HSLAPixel & newPixel = newImage->getPixel(x,y);

      newPixel=oldPixel;
    }
  }

  this->resize(w, h);
  for (unsigned x = 0; x < w; x++) {
    for (unsigned y = 0; y < h; y++) {
      if(x < w && y < h){
      cs225::HSLAPixel & oldPixel = this->getPixel(x,y);
      oldPixel = newImage->getPixel(x/w,y/h);
      }
    }
  }
  delete newImage;



  // this->resize(w,h);
}
