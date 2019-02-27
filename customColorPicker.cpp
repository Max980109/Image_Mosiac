#include "customColorPicker.h"

customColorPicker::customColorPicker(HSLAPixel fillColor)
{
  color = fillColor;

}

HSLAPixel customColorPicker::operator()(int x, int y)
{
   if( x % number == 0 || y % number == 0){
     return color;
   }
   return HSLAPixel();
}
