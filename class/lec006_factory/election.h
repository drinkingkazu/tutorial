#ifndef ELECTION_H
#define ELECTION_H

#include <string>
#include <vector>
#include <map>
class candidate {

public:

  candidate(std::string name) : _name(name) {}
  virtual ~candidate() {}

  const std::string& name() const { return _name; }

  // candidate should return a score 0=>1
  float value(std::string question)
  {
    auto res = this->_value_(question); 
    if(res<0.) res = 0.;
    if(res>1.) res = 1.;
    return res;
  }
  
private:
  virtual float _value_(std::string question) = 0;
  std::string _name;
};

class mc {

public:

  mc() {}
  ~mc() {}

  void nominate(candidate* ptr) {
    if(_candidate_loc_m.find(ptr->name()) != _candidate_loc_m.end())
      return;
    _candidate_loc_m[ptr->name()] = _candidate_v.size();
    _candidate_v.push_back(ptr);
    _score_v.push_back(0.);
  }

  void ask(std::string question)
  {
    for(size_t i=0; i<_candidate_v.size(); ++i) {

      _score_v[i] += _candidate_v[i]->value(question);
    }
  }

  float score(std::string name) const
  {
    auto iter = _candidate_loc_m.find(name);
    
    if(iter == _candidate_loc_m.end()) return -1.;
    
    return _score_v[(*iter).second];
  }

private:
  std::map<std::string,size_t> _candidate_loc_m;
  std::vector<candidate*> _candidate_v;
  std::vector<float> _score_v;
};

#endif
