#include "../include/oras.h"
#include <iostream>

Oras::Oras() : nume("necunoscut"){
  popularitateTrupa = 0;
  capacitatePublic = 0;
  costuriLogistice = 0;
  riscuri = 0;
}
Oras::Oras(const std::string& nume, float popularitateTrupa, int capacitatePublic, int costuriLogistice, float riscuri) {
  this->nume = nume;
  this->popularitateTrupa = popularitateTrupa;
  this->capacitatePublic = capacitatePublic;
  this->costuriLogistice = costuriLogistice;
  this->riscuri = riscuri;
}
Oras::~Oras() = default;

bool Oras::operator==(const Oras& other) const {
  if (this->nume == other.nume) {
    return true;
  }
  return false;
}
bool Oras::operator<(const Oras& other) const {
  return this->costuriLogistice < other.costuriLogistice;
}

void Oras::afiseazaNume(){
  std::cout << nume;
}
void Oras::afiseazaInfo(){
  std::cout << nume << ": Popularitatea trupei: " << popularitateTrupa
            << ", capacitate public: " << capacitatePublic << ", costuri logistice: "
            << costuriLogistice << "  !!risc: " << riscuri << std::endl;
}
int Oras::calculeazaCosturi() const {
  return costuriLogistice;
}
float Oras::aflaPopularitate() const {
  return popularitateTrupa;
}
int Oras::aflaLocuriDisponibile() const {
  return capacitatePublic;
}