#include <map>
#include <string>
#include <iostream>
#include "mytimer.h"
int main() {

  std::map<std::string,int> my_map;

  std::cout << "[0] std::map practice @ start ... size = " << my_map.size() << std::endl;

  my_map["a"] = 0;
  my_map["b"] = 1;
  my_map["c"] = 2;
  my_map["a"] = 3;

  std::cout << "[1] Assigned 4 times with 1 duplicate key. Size is " << my_map.size() << std::endl;

  std::cout << "[2] std::map is ordered. Here is the first key   : " << (*my_map.begin()).first << std::endl;

  std::cout << "[3] std::map is ordered. Here is the first value : " << (*my_map.begin()).second << std::endl;

  std::cout << "[4] Let us use a handy range-loop in C++11..." << std::endl;
  for(auto const& key_value : my_map) 

    std::cout << "  key: " << key_value.first << " ... value: " << key_value.second << std::endl;

  // Fill timing
  Watch my_watch;
  int n_entries = 1e7;
  std::cout << "[5] Fill std::map<int,int> with " << n_entries << " entries... " << std::endl;
  std::map<int,int> another_map;
  my_watch.Start();
  for(int i=0; i<n_entries; ++i)
    another_map[i] = i%10;
  
  std::cout << "[6] Fill with " << n_entries << " took " << my_watch.WallTime() << " [s]" << std::endl;

  // Search timing
  my_watch.Start();
  int key_to_find = 1000;
  auto& value = (*(another_map.find(key_to_find))).second;
  std::cout << "[7] Found a key: " << key_to_find
	    << " with a corresponding value " << value
	    << " which took " << my_watch.WallTime()
	    << " [s]"
	    << std::endl;

  return 0;
}
