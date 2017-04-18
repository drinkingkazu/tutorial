#include <iostream>
#include "election.h"
#include "bigots.h"
#include <set>

int main(int argc, char** argv) {

  mc victim;
  std::set<std::string> name_s;
  for(int i=1; i<argc; ++i) {
    auto ptr = factory::create(argv[i]);
    if(ptr){
      victim.nominate(ptr);
      std::cout << "Registered a candidate " << argv[i] << std::endl;
      name_s.insert(argv[i]);
    }else
      std::cout << "Ignoring an invalid candidate " << argv[i] << std::endl;
  }
  
  std::vector<std::string> question_v;
  question_v.push_back("Should we be concerend about global warming?");
  question_v.push_back("Should we replace or repeal Obama Care?");
  question_v.push_back("JOBS JOBS JOBS");

  for(auto const& question : question_v)
    victim.ask(question);

  for(auto const& name : name_s)
    std::cout << "Candidate " << name << " scored " << victim.score(name) << std::endl;

  return 1;
}
