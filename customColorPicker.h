#ifndef CUSTOMCOLORPICKER_H
#define CUSTOMCOLORPICKER_H

#include "colorPicker.h"


class customColorPicker : public colorPicker
{
  public:

    customColorPicker(HSLAPixel fillColor);


    virtual HSLAPixel operator()(int x, int y);

  private:
    HSLAPixel color;
    int number = 2;    
};

#endif
