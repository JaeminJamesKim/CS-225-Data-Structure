#include <iostream>
#include <string>
#include "StickerSheet.h"
#include "Image.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

StickerSheet::StickerSheet(const Image & picture, unsigned max){
  maxnum=max;
  base = new Image(picture);
  stickers= new Image *[maxnum];
  x_=new int[maxnum];
  y_=new int[maxnum];
  for(unsigned i = 0; i<maxnum; i++){
    stickers[i]=NULL;
    x_[i]=0;
    y_[i]=0;
  }

}

StickerSheet::~StickerSheet (){
  clear_();
}

void StickerSheet::clear_(){
  for(unsigned i = 0; i<maxnum; i++){
    delete stickers[i];
  }
  delete [] stickers;
  delete [] x_;
  delete [] y_;
}

void StickerSheet::copy_(const StickerSheet & other){
  maxnum=other.maxnum;
  stickers = new Image *[maxnum];
  x_=new int[maxnum];
  y_=new int[maxnum];

  for(unsigned i = 0; i<maxnum; i++){
    if(other.stickers[i] !=NULL){
      stickers[i] = new Image;
      *stickers[i] = *(other.stickers[i]);
      x_[i]=other.x_[i];
      y_[i]=other.y_[i];
    }
    else{
      stickers[i] = NULL;
      x_[i]=0;
      y_[i]=0;
    }
  }
}

StickerSheet::StickerSheet (const StickerSheet &other){
  copy_(other);
}

const StickerSheet & 	StickerSheet::operator= (const StickerSheet &other){
  if(this != &other){
    clear_();
    copy_(other);
  }
  return *this;
}

void 	StickerSheet::changeMaxStickers (unsigned max){

  if(max>=maxnum){
  Image **new_stickers=new Image *[max];
  int *new_x_=new int[max];
  int *new_y_=new int[max];

  for(unsigned i = 0; i<max; i++){
    new_stickers[i]=stickers[i];
    new_x_[i]=x_[i];
    new_y_[i]=y_[i];
  }
clear_();
stickers=new_stickers;
x_=new_x_;
y_=new_y_;
maxnum=max;
}

else {
  Image **new_stickers=new Image *[max];
  int *new_x_=new int[max];
  int *new_y_=new int[max];
  for(unsigned i = 0; i<max; i++){
    new_stickers[i]=stickers[i];
    new_x_[i]=x_[i];
    new_y_[i]=y_[i];
  }

  for(unsigned i = max-1; i<maxnum; i++){
    stickers[i]=NULL;
    x_[i]=0;
    y_[i]=0;
  }
  clear_();
  stickers=new_stickers;
  x_=new_x_;
  y_=new_y_;
  maxnum=max;
}
}



//SHIIIIIIIIITTTTT
int 	StickerSheet::addSticker (Image &sticker, unsigned x, unsigned y){

  // bool isNull= false;
  // unsigned count = 0;
  // while(isNull==false && count<maxnum){
  //   if(stickers[count]==NULL){
  //     stickers[count]=&sticker;
  //     x_[count]=x;
  //     y_[count]=y;
  //
  //     isNull=true;
  //   }
  //
  //   count++;
  //   }
  //
  // if(count >= maxnum){
  //   return -1;
  // }
  // return count;


  Image *tempImage = new Image();
  *tempImage=sticker;

  for(unsigned i = 0; i<maxnum; i++){
    if (stickers[i]==NULL)
    {
      stickers[i] = tempImage;
      x_[i] = x;
      y_[i] = y;
      return i;
    }


		}

    return -1;
    delete tempImage;
}

bool 	StickerSheet::translate (unsigned index, unsigned x, unsigned y){
  if((index<maxnum)&&(stickers[index]!=NULL)){
    x_[index]= x;
    y_[index]= y;
    return true;
  }
  else{
    return false;
  }
}

void 	StickerSheet::removeSticker (unsigned index){
  if((index<maxnum)&&(stickers[index]!=NULL)){
    delete stickers[index];
    stickers[index]=NULL;
    x_[index]= 0;
    y_[index]= 0;
  }
}

Image * StickerSheet::getSticker (unsigned index) const{
  if((index <maxnum)){
    return stickers[index];
  }
  else{
    return NULL;
  }
}

//SHIIIIIIIIITTTTT
Image StickerSheet::render () const{
  unsigned need_width= base->width();
  unsigned need_height= base->height();
  for(unsigned i = 0; i < maxnum; i++)
		{
			if (stickers[i] != NULL)
			{
				unsigned single_width =  stickers[i]->width() + (unsigned )x_[i];
				unsigned single_height =  stickers[i]->height() + (unsigned )y_[i];
				if (single_width > need_width)
					need_width = single_width;
				if (single_height > need_height)
					need_height = single_height;
			}
		}

    base->resize(need_width,need_height);
		cs225::HSLAPixel * image_pixel;
		for(unsigned i = 0; i < maxnum; i++)
		{
			if (stickers[i] != NULL)
			{
				// unsigned temp_width = stickers[i]->width();
				// unsigned temp_height = stickers[i]->height();
				// unsigned x_coord = unsigned(x_[i]);
				// unsigned y_coord = unsigned(y_[i]);
				for(unsigned  j = 0; j < stickers[i]->width(); j++)
					{
						for(unsigned int k = 0; k < stickers[i]->height(); k++)
							{
                image_pixel=&stickers[i]->getPixel(j,k);
                if(image_pixel->a!=0){
								// image_pixel = wholeImage(j + x_coord, k + y_coord);
								// *image_pixel = *(*stickers[i])(j,k);

                // base->getPixel(x_[i]+j, y_[i]+k)= stickers[i]->getPixel(j,k);
                base->getPixel(j, k)= stickers[i]->getPixel(j,k);
              }
							}
					}
			}
		}
		return *base;

}
