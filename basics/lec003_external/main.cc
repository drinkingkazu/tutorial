#include <TStopwatch.h>
#include "unistd.h"
#include <iostream>
int main()
{
  // Instantiate "watch"
  TStopwatch my_watch;

  // Start "watch"
  my_watch.Start();

  // Wait for 1 second 
  usleep(1000000);

  // Report time elapse
  std::cout << "Wall time: " << my_watch.RealTime()
	    << std::endl
	    << "CPU  time: " << my_watch.CpuTime()
	    << std::endl;


  return 1;

}
