#include <vector>
#include <iostream>
#include "mytimer.h"

class fatboy {
public:
  fatboy()
  {
    _fat_data.resize(10000,1);
  }
  ~fatboy() {}

private:
  std::vector<int> _fat_data;
};

// mother class has a fatboy instance
class mother {
public:
  mother() : _data(1000,fatboy())
  {}
  ~mother(){}

  void reset()
  { _data.clear(); _data.resize(1000,fatboy()); }

  std::vector<fatboy> _data;
};

// father is nasty and complicated
class father {
public:
  father() {}
  ~father(){}

  void reset()
  { _data.clear(); _hidden_kid.clear(); }

  // Takes in a child, copy to his hidden kid
  void copy_child(const std::vector<fatboy>& kid_v)
  { _hidden_kid = kid_v; }

  // Append children
  void append_child(const std::vector<fatboy>& kid_v)
  {
    _hidden_kid.reserve(_hidden_kid.size() + kid_v.size());
    for(auto const& kid : kid_v) _hidden_kid.push_back(kid);
  }

  // Swaps a child to his hidden kid
  void move_child(std::vector<fatboy>&& kid_v)
  { _hidden_kid = std::move(kid_v); }

  // Size of hidden child
  size_t hidden_size() const { return _hidden_kid.size(); }

  std::vector<fatboy> _data;
  
protected:
  std::vector<fatboy> _hidden_kid;
};

int main() {

  Watch my_watch;

  my_watch.Start();
  mother mom;
  std::cout << "[0] Creation time for mother: " << my_watch.WallTime() << std::endl;

  my_watch.Start();
  father dad;
  std::cout << "[1] Creation time for father: " << my_watch.WallTime() << std::endl;

  std::cout << "[2] Current size of mother's data: " << mom._data.size() << std::endl;
  std::cout << "[3] Current size of father's data: " << dad._data.size() << std::endl;

  std::cout << std::endl;

  //
  // Copy vs. swap for accessible variables
  //
  my_watch.Start();
  dad._data = mom._data;
  std::cout << "[4] Copy time for mother's data to fathers': " << my_watch.WallTime() << std::endl;
  std::cout << "[5] Current size of mother's data: " << mom._data.size() << std::endl;
  std::cout << "[6] Current size of father's data: " << dad._data.size() << std::endl;
  std::cout << std::endl;
  
  dad._data.clear();

  my_watch.Start();
  std::swap(dad._data,mom._data);
  std::cout << "[7] Swap time for mother's data to fathers': " << my_watch.WallTime() << std::endl;
  std::cout << "[8] Current size of mother's data: " << mom._data.size() << std::endl;
  std::cout << "[9] Current size of father's data: " << dad._data.size() << std::endl;
  std::cout << std::endl;
  
  my_watch.Start();
  std::swap(dad._data,mom._data);
  std::cout << "[10] ANOTHER! Swap time for mother's data to fathers': " << my_watch.WallTime() << std::endl;
  std::cout << "[11] Current size of mother's data: " << mom._data.size() << std::endl;
  std::cout << "[12] Current size of father's data: " << dad._data.size() << std::endl;
  std::cout << std::endl;

  std::cout << "[13] Resetting mom & dad ... " << std::endl;
  dad.reset();
  mom.reset();
  std::cout << std::endl;
  
  //
  // Handing over data instance
  //
  my_watch.Start();
  dad.copy_child(mom._data);
  std::cout << "[14] Copy time for father's hidden child: " << my_watch.WallTime() << std::endl;
  std::cout << "[15] Current size of mother's data: " << mom._data.size() << std::endl;
  std::cout << "[16] Current size of father's hidden data: " << dad.hidden_size() << std::endl;
  std::cout << std::endl;

  std::cout << "[17] Resetting mom & dad ... " << std::endl;
  dad.reset();
  mom.reset();
  std::cout << std::endl;
  
  my_watch.Start();
  dad.append_child(mom._data);
  std::cout << "[18] Append time for father's hidden child: " << my_watch.WallTime() << std::endl;
  std::cout << "[19] Current size of mother's data: " << mom._data.size() << std::endl;
  std::cout << "[20] Current size of father's hidden data: " << dad.hidden_size() << std::endl;

  std::cout << "[21] Resetting mom & dad ... " << std::endl;
  dad.reset();
  mom.reset();
  std::cout << std::endl;

  my_watch.Start();
  dad.move_child(std::move(mom._data));
  std::cout << "[22] Adopt time for father's hidden child: " << my_watch.WallTime() << std::endl;
  std::cout << "[23] Current size of mother's data: " << mom._data.size() << std::endl;
  std::cout << "[24] Current size of father's hidden data: " << dad.hidden_size() << std::endl;

  std::cout << "[15] Resetting mom & dad ... " << std::endl;
  dad.reset();
  mom.reset();
  std::cout << std::endl;

  return 0;
}
