
#include "../include/persoana.h"
#include "../include/bodyguard.h"
#include <string>
#include <iostream>

Bodyguard::Bodyguard(): Persoana(){
  costPeEveniment = 0;
  eficienta = 0;
}
Bodyguard::Bodyguard(const std::string& nume, const std::string& prenume, int varsta, int costPeEveniment, int eficienta): Persoana(nume, prenume, varsta){
  this->costPeEveniment = costPeEveniment;
  this->eficienta = eficienta;
}
Bodyguard::~Bodyguard() = default;
void Bodyguard::afiseaza() const {
  std::cout << "Nume: " << nume << " " << prenume << ", varsta " << varsta
            << " ani (cost pe eveniment: " << costPeEveniment <<", eficienta: "
            << eficienta << ")" << std::endl;
}

int Bodyguard::calculeazaCost() const {
  return costPeEveniment;
}
int Bodyguard::contributie(){
  eficienta++;
  if(eficienta >= 70){
    std::cout << "Bodyguard-ul a avut grija sa nu existe probleme" << std::endl;
    return eficienta;
  }
  else if (eficienta >= 30){
    std::cout << "Au aparut anumite probleme, insa bodyguard-ul le-a rezolvat in timp" << std::endl;
    return eficienta;
  }
  else {
    std::cout << "Au fost destule probleme in ceea ce priveste siguranta, bodyguard-ul a facut tot ce a putut, dar vor exista consecinte in legatura cu succesul concertului" << std::endl;
    return eficienta;
  }
}