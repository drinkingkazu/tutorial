#include <iostream>
#include "election.h"
#include "bigots.h"

int main() {

  mc victim;

  victim.nominate(new Hilary);
  victim.nominate(new Trump);
  
  std::vector<std::string> question_v;
  question_v.push_back("Should we be concerend about global warming?");
  question_v.push_back("Should we replace or repeal Obama Care?");
  question_v.push_back("JOBS JOBS JOBS");

  for(auto const& question : question_v)
    victim.ask(question);

  std::cout << "Hilary: " << victim.score("Hilary") << std::endl;
  std::cout << "Trump:  " << victim.score("Trump") << std::endl;

  return 1;
}
