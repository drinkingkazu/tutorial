#include <vector>
#include <iostream>

int main() {

  std::vector<int> my_vec(10,0);

  std::cout << "[0] Vector of length " << my_vec.size() << " filled with 0s." << std::endl;

  for(int i=0; i < my_vec.size(); ++i)
    my_vec[i] = 1;

  // Random access to modify
  std::cout << "[1] Contents after the first loop using [] operator: " << std::endl;
  for(int i=0; i < my_vec.size(); ++i)
    std::cout << my_vec[i] << " ";
  std::cout << std::endl;

  // Iterator to modify
  for(std::vector<int>::iterator iter = my_vec.begin();
      iter != my_vec.end();
      ++iter) 
    (*iter) = 2;
  std::cout << "[2] Contents after the first loop using an iterator: " << std::endl;
  for(int i=0; i < my_vec.size(); ++i)
    std::cout << my_vec[i] << " ";
  std::cout << std::endl;

  // C++11 range loop to modify
  for(auto value : my_vec)
    value = 3;
  std::cout << "[2] Contents after the first loop using C++11 range operator + copy: " << std::endl;
    for(int i=0; i < my_vec.size(); ++i)
    std::cout << my_vec[i] << " ";
  std::cout << std::endl;

  // C++11 range loop to modify
  for(auto& value : my_vec)
    value = 4;
  std::cout << "[2] Contents after the first loop using C++11 range operator + reference: " << std::endl;
    for(int i=0; i < my_vec.size(); ++i)
    std::cout << my_vec[i] << " ";
  std::cout << std::endl;

  return 0;
}
