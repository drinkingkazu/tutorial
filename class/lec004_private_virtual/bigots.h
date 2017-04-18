#ifndef BIGOTS_H
#define BIGOTS_H

#include "election.h"

class Hilary : public candidate {
public:
  Hilary() : candidate("Hilary")
  {}
  ~Hilary() {}

private:
  float _value_(std::string question)
  { return 1./((float)(question.size())); }
};

class Trump : public candidate {
public:
  Trump() : candidate("Trump")
  {}
  ~Trump() {}

private:
  float _value_(std::string question)
  { return (float)(question.size()); }
};

#endif
