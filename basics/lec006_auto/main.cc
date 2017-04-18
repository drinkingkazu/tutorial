#include <iostream>
#include <string>
#include "myfunc.h"

int main()
{
  auto val = score();

  std::cout << "Size of val = " << sizeof(val) << " and its value is " << val << std::endl;
  
  return 0;
}

  
