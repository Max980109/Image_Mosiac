#include "borderColorPicker.h"

borderColorPicker::borderColorPicker(HSLAPixel fillColor, PNG & img, double tolerance,HSLAPixel center)
{
  color = fillColor;
  im = img;
  tol = tolerance;
  ctr = center;


}

HSLAPixel borderColorPicker::operator()(int x, int y)
{
  if(x - 3 < 0 || ctr.dist(*im.getPixel(x-3, y)) >= tol ){
    return color;
  }

  if(x + 3 > (int)im.width()-1 || ctr.dist(*im.getPixel(x+3,y)) >= tol){
    return color;
  }

  if(y-3 < 0 || ctr.dist(*im.getPixel(x, y-3))>= tol){
    return color;
  }

  if(y+3 > (int)im.height()-1 || ctr.dist(*im.getPixel(x, y+3))>= tol){
    return color;
  }



for (int i = x - 2 ; i <= x + 2; i ++)
{
  for (int j = y - 2; j <= y +2; j ++) {
    if ( i < 0 || i >= (int)im.width()-1 || j < 0 || j >= (int)im.height() -1) {
      return color;
    }
    else if ( ctr.dist(*(im.getPixel(i,j))) > tol && *(im.getPixel(i,j)) != color) {
      return color;
    }
  }
 }
  return *(im.getPixel(x,y));
}
