#include "evenimente.h"
#include <iostream>
#include <string>
Eveniment::Eveniment(): descriere("necunoscuta"), modificareBuget(0)
                         , modificarePopularitate(0), modificareTrupa(0) {}
Eveniment::Eveniment(const std::string& descriere, int modificareBuget
                     , int modificarePopularitate, bool modificareTrupa):descriere(descriere)
                     , modificareBuget(modificareBuget),modificarePopularitate(modificarePopularitate)
                     ,modificareTrupa(modificareTrupa) {}
Eveniment::~Eveniment(){}
void Eveniment::areLoc() const {
    std::cout << descriere << std :: endl;
}
int Eveniment::modificaBuget() const {
  return modificareBuget;
}
int Eveniment::modificaPopularitate() const {
  return modificarePopularitate;
}
bool Eveniment::modificaTrupa() const {
  return modificareTrupa;
}