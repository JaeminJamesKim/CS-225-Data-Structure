#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace cs225;

PNG* setupOutput(unsigned w, unsigned h) {
    PNG * image = new PNG(w, h);
    return image;
}

void rotate(std::string inputFile, std::string outputFile) {
  // Part 2

  PNG * original = new PNG();
  original -> readFromFile(inputFile);
  unsigned width = original -> width();
  unsigned height = original -> height();

// Q1
  PNG * output;
  output= setupOutput(width, height);

  for (unsigned y =0; y < height; y++){
    for (unsigned x=0; x< width; x++){

      //HSLAPixel * prev=&original->getPixel(x-1,y-1);
      HSLAPixel * inPixel= original->getPixel(x,y);
      HSLAPixel * outPixel=output->getPixel(original->width()-1-x, original->height()-1-y);
      *outPixel=*inPixel;



    }
  }
  output->writeToFile(outputFile);

}

HSLAPixel * frameColor(double saturation) {
  HSLAPixel * pixel = new HSLAPixel(20,saturation, 0.2);
  return pixel;
}


PNG myArt(unsigned int width, unsigned int height) {
  PNG png(width, height);
  // Part 3

  //bottom frame
  for (unsigned y =0; y < height/10; y++){
    for (unsigned x=0; x< width; x++){

      HSLAPixel * framePixel= png.getPixel(x,y);
      //HSLAPixel * outPixel=png.getPixel(original->width()-1-x, original->height()-1-y);
      //*outPixel=*inPixel;

      HSLAPixel * myPixel=frameColor(x/100);
      *framePixel=*myPixel;


    }
  }

  //top frame
  for (unsigned y =(height-(height/10)); y < height; y++){
    for (unsigned x=0; x< width; x++){
      HSLAPixel * framePixel= png.getPixel(x,y);
      //HSLAPixel * outPixel=png.getPixel(original->width()-1-x, original->height()-1-y);
      //*outPixel=*inPixel;

      HSLAPixel * myPixel=frameColor(x/100);
      *framePixel=*myPixel;

    }
  }

  //left frame
  for (unsigned y =0; y < height; y++){
    for (unsigned x=0; x< width/10; x++){
      HSLAPixel * framePixel= png.getPixel(x,y);
      //HSLAPixel * outPixel=png.getPixel(original->width()-1-x, original->height()-1-y);
      //*outPixel=*inPixel;

      HSLAPixel * myPixel=frameColor(y/100);
      *framePixel=*myPixel;

    }
  }

  //right frame
  for (unsigned y =0; y < height; y++){
    for (unsigned x=(width-(width/10)); x< width; x++){
      HSLAPixel * framePixel= png.getPixel(x,y);
      //HSLAPixel * outPixel=png.getPixel(original->width()-1-x, original->height()-1-y);
      //*outPixel=*inPixel;

      HSLAPixel * myPixel=frameColor(y/100);
      *framePixel=*myPixel;

    }
  }


  return png;
}
