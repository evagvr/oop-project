
#include "../include/persoana.h"
#include "../include/tehnicianSunet.h"
#include <iostream>
#include <string>

TehnicianSunet::TehnicianSunet(): Persoana(){
  costPeEveniment = 0;
  eficienta = 0;
}
TehnicianSunet::TehnicianSunet(const std::string& nume, const std::string& prenume, int varsta, int costPeEveniment, int eficienta): Persoana(nume, prenume, varsta){
  this->costPeEveniment = costPeEveniment;
  this->eficienta = eficienta;
}
TehnicianSunet::~TehnicianSunet() = default;
void TehnicianSunet::afiseaza() const {
  std::cout << "Nume: " << nume << " " << prenume << ", varsta " << varsta
            << " ani (cost pe eveniment: " << costPeEveniment <<", eficienta: "
            << eficienta << ")" << std::endl;
}

int TehnicianSunet::calculeazaCost() const {
  return costPeEveniment;
}
int TehnicianSunet::contributie(){
  eficienta++;
  if (eficienta >= 70){
    std::cout << "Tehnicianul de sunet a gestionat perfect concertul" << std::endl;
    return eficienta;
  }
  else if (eficienta >= 30){
    std::cout << "Au fost cateva probleme tehnice, dar acestea au fost rezolvate de tehnician" << std::endl;
    return eficienta;
  }
  else{
    std::cout << "Au fost destule probleme tehnice in cadrul concertului si nu toate au fost rezolvate de tehnician, vor exista consecinte ale succesului" << std::endl;
    return eficienta;
  }
}