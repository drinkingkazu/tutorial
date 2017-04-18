#include <iostream>
#include <string>
#include "mytimer.h"

class fatboy {
public:
  fatboy() {}
  ~fatboy() {}
  int data[1000000];
};

int sum_copy(fatboy input)
{
  int sum=0;
  for(size_t i=0; i<100; ++i) sum += input.data[i];
  return sum;
}

int sum_ref(fatboy& input)
{
  int sum=0;
  for(size_t i=0; i<100; ++i) sum += input.data[i];
  return sum;
}

int main() {

  Watch my_watch;

  std::cout << "[0] Will make a fatboy (size = " << sizeof(fatboy)
	    << " bytes)" << std::endl;

  fatboy my_fatboy;

  std::cout << "[1] Calling sum_copy " << std::flush;
  my_watch.Start();
  sum_copy(my_fatboy);
  std::cout << " took " << my_watch.WallTime() << " [s]" << std::endl;

  std::cout << "[2] Calling sum_ref " << std::flush;
  my_watch.Start();
  sum_ref(my_fatboy);
  std::cout << " took " << my_watch.WallTime() << " [s]" << std::endl;
  
  return 1;
}
