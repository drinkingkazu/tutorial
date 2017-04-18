#include <map>
#include <string>
#include <iostream>

int main() {

  std::multimap<std::string,int> my_multi_map;

  my_multi_map.emplace("a",0);
  my_multi_map.emplace("b",1);
  my_multi_map.emplace("c",2);
  my_multi_map.emplace("d",3);
  my_multi_map.emplace("a",4);
  
  std::map<std::string,int> my_map;

  my_map.emplace("a",0);
  my_map.emplace("b",1);
  my_map.emplace("c",2);
  my_map.emplace("d",3);

  std::cout << "[0] std::map contents:" << std::endl;
  for(auto& key_value : my_map)
    std::cout << key_value.first << " => " << key_value.second << std::endl;

  std::cout << std::endl;

  std::cout << "[1] std::multi_map contents:" << std::endl;
  for(auto& key_value : my_multi_map)
    std::cout << key_value.first << " => " << key_value.second << std::endl;

  std::cout << std::endl;
  
  return 0;
};
