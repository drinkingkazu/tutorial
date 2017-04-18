#include <iostream>
#include <string>


struct data{
  data() { cleared = false;}
  void clear() { cleared = true; }
  bool cleared;
};

class foo {
public:
  foo()  {}
  ~foo() {}
  virtual void set(data& obj) = 0;
};

class bar {
public:
  bar()  {}
  virtual ~bar() {}
  virtual void set(data& obj) = 0;
};

class poop : public foo{
public:
  poop()  { _ptr = nullptr;         }
  ~poop() { if(_ptr) _ptr->clear(); }
  void set(data& obj) { _ptr = &obj; }
private:
  data* _ptr;
};

class cacca : public bar {
public:
  cacca()  { _ptr = nullptr;         }
  ~cacca() { if(_ptr) _ptr->clear(); }
  void set(data& obj) { _ptr = &obj;  }
private:
  data* _ptr;
};

int main() {

  data obj;

  // case of foo
  std::cout << "[0] data status before foo creation: " << obj.cleared << std::endl;
  foo* foo_ptr = new poop;
  foo_ptr->set(obj);
  delete foo_ptr;
  std::cout << "[1] int pointer after  foo deletion: " << obj.cleared << std::endl;
  
  // case of bar
  std::cout << "[2] int pointer before bar creation: " << obj.cleared << std::endl;
  bar* bar_ptr = new cacca;
  bar_ptr->set(obj);
  delete bar_ptr;
  std::cout << "[3] int pointer after  bar deletion: " << obj.cleared << std::endl;

  return 0;
};
