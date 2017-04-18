#include <set>
#include <iostream>

class event_key {
public:
  event_key(int run=0,
	    int subrun=0,
	    int event=0)
    : _run    ( run    )
    , _subrun ( subrun )
    , _event  ( event  )
  {}
  ~event_key() {}

  void set(int run, int subrun, int event)
  { _run = run; _subrun = subrun; _event = event; }

  inline bool operator <(const event_key& rhs) const
  {
    if( _run < rhs._run) return true;
    if( rhs._run < _run) return false;

    if( _subrun < rhs._subrun) return true;
    if( rhs._subrun < _subrun) return false;

    if( _event < rhs._event) return true;
    if( rhs._event < _event) return false;

    return false;
  }
  int _run,_subrun,_event;
};

int main() {

  std::set<event_key> my_set;

  my_set.emplace(0,0,0);
  my_set.emplace(0,0,1);
  my_set.emplace(0,0,2);
  my_set.emplace(0,0,3);

  event_key key0(0,0,4);
  event_key key1(0,0,1);

  std::cout << "[0] My custom set created with size: " << my_set.size() << std::endl;

  std::cout << "[1] My custom set contains key0 ? " << (my_set.find(key0) != my_set.end()) << std::endl;

  std::cout << "[2] My custom set containskey01 ? " << (my_set.find(key1) != my_set.end()) << std::endl;

  std::cout << std::endl;
  
  return 0;
}

