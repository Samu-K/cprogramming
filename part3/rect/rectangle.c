#include "rectangle.h"
#include <stdlib.h>

Rectangle* createRectangle(void) {
  Rectangle* ret = malloc(sizeof *ret);
  Point org;

  org.x = 0;
  org.y = 0;


  ret->width = 0;
  ret->height = 0;
  ret->origin = org;

  return ret;
}

Rectangle* createRectangle2(Point P) {
  Rectangle* ret = malloc(sizeof *ret);

  ret->width = 0;
  ret->height = 0;
  ret->origin = P;

  return ret;
}

Rectangle* createRectangle3(int w, int h) {
  Rectangle* ret = malloc(sizeof *ret);
  
  Point org;

  org.x = 0;
  org.y = 0;
  
  ret->width = w;
  ret->height = h;
  ret->origin = org;

  return ret;
}

Rectangle* createRectangle4(Point P, int w, int h) {
  Rectangle* ret = malloc(sizeof *ret);
   
  ret->width = w;
  ret->height = h;
  ret->origin = P;

  return ret;
}

void move(Rectangle* r, int x, int y) {
  
  r->origin.x = x;
  r->origin.y = y;
}

int getArea(const Rectangle* r)  {
  return r->width * r->height;
}
