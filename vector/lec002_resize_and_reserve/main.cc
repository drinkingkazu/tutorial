#include <vector>
#include <iostream>
#include "mytimer.h"

int main() {

  // Instantiate vector template class in integer type
  std::vector<int> my_vec;

  // Instantiate "watch"
  Watch my_watch;

  // # of entries in the vector for this practice
  int n_entries = 1e8;

  std::cout << "[0] # of entries in the vector @ start: " << my_vec.size() << std::endl;
  
  // Famous function: push_back
  my_watch.Start();
  for(int i=0; i<n_entries; ++i)
    my_vec.push_back(i);

  std::cout << "[1] # of entries now: " << my_vec.size()
	    << " ... time to fill: " << my_watch.WallTime() << " [s]"
	    << " using plain push_back"
	    << std::endl;

  // Now try "reserve" before push_back
  my_vec.clear();
  my_vec.reserve(n_entries);
  my_watch.Start();
  for(int i=0; i<n_entries; ++i)
    my_vec.push_back(i);

  std::cout << "[2] # of entries now: " << my_vec.size()
	    << " ... time to fill: " << my_watch.WallTime() << " [s]"
	    << " using reserve + push_back"
	    << std::endl;

  // Another way: "resize" (but then you won't use push_back!)
  my_vec.clear();
  my_vec.resize(n_entries);
  my_watch.Start();
  for(int i=0; i<n_entries; ++i)
    my_vec[i] = i;

  std::cout << "[3] # of entries now: " << my_vec.size()
	    << " ... time to fill: " << my_watch.WallTime() << " [s]"
	    << " using resize + random_access operator"
	    << std::endl;

  // Alternative to "resize": specify @ constructor
  std::vector<int> another_vec(n_entries);
  my_watch.Start();
  for(int i=0; i<n_entries; ++i)
    my_vec[i] = i;

  std::cout << "[4] # of entries now: " << my_vec.size()
	    << " ... time to fill: " << my_watch.WallTime() << " [s]"
	    << " using constructor + random_access operator"
	    << std::endl;

  // Compare "resize" vs. "reserve" time
  std::cout << "[5] Let's compare resize vs. reserve function calls..." << std::endl;

  my_vec.clear();
  my_watch.Start();
  my_vec.reserve(n_entries);
  std::cout << "[6] Time to reserve: " << my_watch.WallTime() << " [s]" << std::endl;
  
  my_vec.clear();
  my_watch.Start();
  my_vec.resize(n_entries);
  std::cout << "[7] Time to resize: " << my_watch.WallTime() << " [s]" << std::endl;

  return 0;
}
