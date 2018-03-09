#include "Image.h"
#include "StickerSheet.h"
#include "cs225/PNG.h"
#include <iostream>
#include <string>

int main() {
  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

Image alma;
Image illini;
Image wade;
Image i;

alma.readFromFile("alma.png");
StickerSheet base_img(alma,5);

illini.readFromFile("illini.png");
illini.scale(0.8);
base_img.addSticker(illini, 0, 0);

wade.readFromFile("wade.png");
wade.scale(0.8);
base_img.addSticker(wade, 0, 0);

i.readFromFile("i.png");
i.scale(0.6);
base_img.addSticker(i, 0, 0);



// StickerSheet base_img= new StickerSheet(stare_dad, 7);

Image result = base_img.render();
result.writeToFile("myImage.png");

  return 0;
}
