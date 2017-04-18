#include <vector>
#include <deque>
#include <time.h>
#include <iostream>
#include "mytimer.h"

class event {
public:
  event(){}
  ~event(){}

  int _data[10000];

};

class fast_event_buffer {
public:

  fast_event_buffer(size_t buffer_size=10)
    : _size(buffer_size)
  {}
  ~fast_event_buffer() {}

  void append(const event& data) {
    _buffer.push_back(data);
    if(_buffer.size() > _size) _buffer.pop_front();
  }

  size_t size() const { return _size; }

protected:

  size_t _size;
  std::deque<event> _buffer;
};

class slow_event_buffer {
public:

  slow_event_buffer(size_t buffer_size=10)
    : _size(buffer_size)
  {}
  ~slow_event_buffer() {}

  void append(const event& data) {
    _buffer.push_back(data);
    if(_buffer.size() > _size) _buffer.erase(_buffer.begin());
  }

  size_t size() const { return _size; }

protected:

  size_t _size;
  std::vector<event> _buffer;
};

int main() {

  Watch my_watch;
  const size_t whole_data_size = 1e4;
  std::cout << "[0] Creating a sample event set (size = " << whole_data_size << ")" << std::endl;
  std::cout << std::endl;
  std::vector<event> whole_data(whole_data_size,event());

  fast_event_buffer fast_buf;
  slow_event_buffer slow_buf;

  // Looping over whole_data using slow buffer
  std::cout << "[1] Looping over the whole event data w/ slow buffer (size=" << fast_buf.size() << ")" << std::endl;
  my_watch.Start();
  for(size_t i=0; i<whole_data.size(); ++i)

    slow_buf.append(whole_data[i]);

  std::cout << "[2] Time took: " << my_watch.WallTime() << " [sec.] " << std::endl;
  std::cout << std::endl;

  // Looping over whole_data using fast buffer
  std::cout << "[3] Looping over the whole event data w/ fast buffer (size=" << fast_buf.size() << ")" << std::endl;
  my_watch.Start();
  for(size_t i=0; i<whole_data.size(); ++i)

    fast_buf.append(whole_data[i]);

  std::cout << "[4] Time took: " << my_watch.WallTime() << " [sec.] " << std::endl;
  std::cout << std::endl;
  
  return 0;
}
