#include <map>
#include <iostream>

class foo {
public:
  foo()  { _x = _y = _z = 0; }
  ~foo() {}

  void set(int x, int y, int z)
  { _x = x; _y = y; _z = z; }

  inline bool operator <(const foo& rhs) const
  {
    if( _x < rhs._x) return true;
    if( rhs._x < _x) return false;

    if( _y < rhs._y) return true;
    if( rhs._y < _y) return false;

    if( _z < rhs._z) return true;
    if( rhs._z < _z) return false;

    return false;
  }
  int _x,_y,_z;
};

int main() {

  std::map<foo,int> my_map;

  foo my_foo_0;
  my_foo_0.set(0,0,0);

  my_map[my_foo_0] = 0;

  foo my_foo_1;
  my_foo_1.set(-1,-1,-1);

  my_map[my_foo_1] = 1;

  std::cout << "[0] My custom map created with size: " << my_map.size() << std::endl;

  std::cout << "[1] First element's value is: " << (*my_map.begin()).second << std::endl;

  return 0;
}

