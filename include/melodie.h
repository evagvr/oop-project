#ifndef MELODIE_H
#define MELODIE_H
#include <string>
#include <iostream>




class Melodie{
protected:
  std::string titlu;
  std::string genMuzical;
public:
  Melodie();
  Melodie(const std::string& titlu, const std::string& genMuzical);
  virtual ~Melodie();
};
#endif