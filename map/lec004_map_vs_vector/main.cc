#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "mytimer.h"

class map_container {
public:
  map_container()  {}
  ~map_container() {}

  void set(size_t key, float val) { _data[key] = val; }

  float get(size_t key) {
    auto iter = _data.find(key);
    if(iter == _data.end()) return -1;
    return (*iter).second;
  }

private:
  std::map<size_t,float> _data;
};

class vec_container {
public:
  vec_container()  {}
  ~vec_container() {}

  void set(size_t key, float val) {
    if(_data.size() <= key) _data.resize(key+1,-1);
    _data[key] = val;
  }

  float get(size_t key) {
    if(_data.size() <= key) return -1;
    return _data[key];
  }

private:
  std::vector<float> _data;
};

int main() {

  Watch my_timer;

  for(size_t counter=0; counter<10; ++counter) {
    
    size_t key_max   = ( counter + 1 ) * 1000;
    size_t key_count = ( counter + 1 ) * 100;

    std::cout << "[0] Counter @ " << counter
	      << " ... generating " << key_count
	      << " in the range 0 => " << key_max
	      << std::endl;
    
    // Generate random keys
    std::vector<size_t> key_v(key_count);
    for(size_t entry=0; entry<key_count; ++entry)
      key_v[entry] = rand() % key_max;

    map_container data_m;
    vec_container data_v;

    my_timer.Start();
    for(auto const& key : key_v)
      data_m.set(key,0.);
    std::cout << "[1] Time to fill map_container: " << my_timer.WallTime() << " [s]" << std::endl;

    my_timer.Start();
    for(auto const& key : key_v)
      data_v.set(key,0.);
    std::cout << "[2] Time to fill vec_container: " << my_timer.WallTime() << " [s]" << std::endl;
    
    // Access keys
    float sum;

    sum = 0;
    my_timer.Start();
    for(auto const& key : key_v)
      sum += data_m.get(key);
    std::cout << "[3] Time to access map_container with valid keys:   " << my_timer.WallTime() * 1.e6 << " [us]" << std::endl;
    
    sum = 0;
    my_timer.Start();
    for(auto const& key : key_v)
      sum += data_v.get(key);
    std::cout << "[4] Time to access vec_container with valid keys:   " << my_timer.WallTime() * 1.e6 << " [us]" << std::endl;
    
    // Generate non-valid keys (mostly if not completely)
    for(size_t entry=0; entry<key_count; ++entry)
      key_v[entry] = rand() % key_max;

    // Access (mostly if not completely) invalid keys
    sum = 0;
    my_timer.Start();
    for(auto const& key : key_v)
      sum += data_m.get(key);
    std::cout << "[5] Time to access map_container with invalid keys: " << my_timer.WallTime() * 1.e6 << " [us]" << std::endl;
    
    sum = 0;
    my_timer.Start();
    for(auto const& key : key_v)
      sum += data_v.get(key);
    std::cout << "[6] Time to access vec_container with invalid keys: " << my_timer.WallTime() * 1.e6 << " [us]" << std::endl;

    std::cout << std::endl;
  }
  
  return 0;
}
