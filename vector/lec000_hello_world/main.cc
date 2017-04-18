
#include <vector>
#include <iostream>

int main()
{
  // Instantiate a vector template class w/ integer type specialization
  std::vector<int> myvec;

  std::cout << "[0] Vector made! size = " << myvec.size() << std::endl;

  // Add elements to this vector
  for(int i=0; i<10; ++i)
    myvec.push_back( i * 2 );

  std::cout << "[1] Vector filled! size = " << myvec.size() << std::endl;

  // Access elements
  std::cout << "[2] Vector element @ 0th index = " << myvec[0] << std::endl;
  std::cout << "[3] Vector element @ 1st index = " << myvec[1] << std::endl;
  std::cout << "[4] Vector element @ 1st index = " << myvec.at(1) 
	    << " ... used \"at\" operator! " << std::endl;

  // Loop over elements and access them
  std::cout << " Accessing elements in a for loop..." << std::endl;
  for(int i=0; i < myvec.size(); ++i) {

    std::cout << myvec[i] << " ";

  }
  std::cout<<std::endl;
  
  // Magic 1: using an iterator
  std::cout << " Accessing elements using an iterator..." << std::endl;
  for( std::vector<int>::iterator iter = myvec.begin();
       iter != myvec.end();
       ++iter) {
    std::cout << (*iter) << " ";
  }
  std::cout<<std::endl;

  // Magic 2: using C++ 11 laziness support
  std::cout << " Accessing elements using std::lazy interface..." << std::endl;
  for( auto const& value : myvec)
    std::cout << value << " ";

  std::cout<<std::endl;
  
  return 0;
}
