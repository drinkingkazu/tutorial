
#include <iostream>

class foo {
public:

  foo()  { _value = 0; }
  ~foo() {}

  double _value;

};

int main() {

  foo obj1;

  std::cout << "[0] obj1._value = " << obj1._value << std::endl;

  std::cout << "[1] (&obj1)->_value = " << (&obj1)->_value << std::endl;

  std::cout << "[2] (&obj1) print out: " << (&obj1) << std::endl;

  foo* obj_ptr = new foo;

  std::cout << "[2] obj_ptr->_value = " << obj_ptr->_value << std::endl;

  std::cout << "[3] (*obj_ptr)._value = " << (*obj_ptr)._value << std::endl;

  std::cout << "[4] obj_ptr print out: " << obj_ptr << std::endl;

  delete obj_ptr;
  
  return 0;
};
