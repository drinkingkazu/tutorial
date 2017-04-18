
#include <iostream>

// Define a class
class HelloWorldClass {

public:
  /// Default constructor
  HelloWorldClass(){}
  /// Default destructor
  virtual ~HelloWorldClass(){}
  /// Greeting function
  void Hello() const
  { std::cout << "Hello world from class-func!" << std::endl; }
};

