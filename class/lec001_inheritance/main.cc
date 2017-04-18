
#include <iostream>
#include "polygon.h"

int main() {

  Rectangle obj1;
  Triangle  obj2;

  obj1.SetParams(2,2);
  obj2.SetParams(2,2);

  std::cout 
    << std::endl
    << "Area of (w,h) = (2,2) Rectangle : " << obj1.area() << std::endl
    << "Area of (w,h) = (2,2) Triangle  : " << obj2.area() << std::endl
    << std::endl;

  return 0;
}


