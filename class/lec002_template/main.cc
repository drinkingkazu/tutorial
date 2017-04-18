
#include <iostream>
#include "polygon.h"

int main() {

  Rectangle<float> obj1;
  Triangle<float>  obj2;

  obj1.SetParams(5,5);
  obj2.SetParams(5,5);

  std::cout 
    << std::endl
    << "Area of (w,h) = (5,5) Rectangle : " << obj1.area() << std::endl
    << "Area of (w,h) = (5,5) Triangle  : " << obj2.area() << std::endl
    << std::endl;

  return 0;
}


