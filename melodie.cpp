#include "melodie.h"
#include "trupa.h"
#include <iostream>

Melodie::Melodie(){
  this->titlu = "necunoscut";
  this->genMuzical = "";
}
Melodie::Melodie(const std::string& titlu, const std::string& genMuzical){
  this->titlu = titlu;
  this->genMuzical = genMuzical;
}
Melodie::~Melodie() = default;