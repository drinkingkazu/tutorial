
#include <vector>
#include <iostream>

class fatboy {
public:
  fatboy(){}
  ~fatboy(){}

  int _fat_data[1000];

};

int main()
{
  // Check the size of fatboy class
  std::cout << "fatboy has a size of " << sizeof(fatboy) << " byte" << std::endl;

  // Check the size of std::vector<fatboy> class
  std::cout << "std::vector<fatboy> class has a size of " << sizeof(std::vector<fatboy>) << " byte" << std::endl;

  // Check the size of fatboy instance
  fatboy var1;
  std::cout << "fatboy instance has a size of " << sizeof(var1) << " byte" << std::endl;

  // Check the size of std::vector<fatboy> instance
  std::vector<fatboy> fat_v;
  std::cout << "std::vector<fatboy> instance has a size of " << sizeof(fat_v) << " byte" << std::endl;

  // Insert fatboy instance to std::vector<fatboy>, check size
  fat_v.push_back(var1);
  std::cout << "std::vector<fatboy> instance with 1 element has a size of " << sizeof(fat_v) << " byte" << std::endl;

  std::cout << std::endl;

  return 0;
}
