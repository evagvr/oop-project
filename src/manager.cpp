#include <iostream>
#include "../include/manager.h"


Manager::Manager(): Persoana(){
  this->cost = 0;
  this->experienta = 0;
  this->conexiuni = 0;
}
Manager::Manager(const std::string& nume, const std::string& prenume, int varsta, int cost, int experienta, int conexiuni):Persoana(nume,prenume,varsta){
  this->cost = cost;
  this->experienta = experienta;
  this->conexiuni = conexiuni;
}
Manager& Manager:: operator=(const Manager& other){
  if(this != &other){
    Persoana::operator=(other);
    this->cost = other.cost;
    this->experienta = other.experienta;
    this->conexiuni = other.conexiuni;
  }
  return *this;
}
Manager::~Manager() = default;

void Manager::contributieTurneu(){
  if (conexiuni > 80 && experienta > 10) {
    std::cout << nume << " " << prenume << ", managerul trupei, a ajutat enorm la promovarea turneului" << std::endl;
  }
  else if (conexiuni > 50 && experienta > 5) {
    std::cout << nume << " " << prenume << ", managerul trupei, a contribuit putin la aducerea fanilor la turneu" << std::endl;
  }
  else {
    std::cout << nume << " " << prenume << ", managerul trupei, nu a ajutat prea tare cu promovarea turneului" << std::endl;
  }
  experienta++;
}

void Manager::cresteriAnuale() {
  experienta++;
  conexiuni+= static_cast<int>(experienta*0.3);
  if (experienta*conexiuni > cost) {
    cost = experienta * conexiuni;
  }
}
int Manager::calculeazaCost() const {
  return cost;
}

int Manager::contributie() {
  experienta++;
  return (experienta+conexiuni)/3;
}
void Manager::contributieConcert(){
  experienta++;
  std::cout << "Managerul s-a ocupat de promovarea concertului cu succes" << std::endl;
}

void Manager::afiseaza() const {
  std::cout << "Nume: " << nume << " " << prenume << ", varsta " << varsta
            << " ani , (cost: "<< cost <<", experienta: " << experienta <<", conexiuni: "
            << conexiuni << ")" << std::endl;
}
int Manager::influenteazaJoc() const {
  if ( conexiuni + experienta > 20)
    return 3;
  else
    return 0;
}

std::ostream& operator<<(std::ostream& out, const Manager& m){
  out << "Nume: " << m.nume<<", Prenume: "<<m.prenume<<" (Varsta: "<<m.varsta
      << ", Cost: "<< m.cost <<", Experienta: "<< m.experienta<<", Conexiuni: "<<m.conexiuni << ")\n";
  return out;
}
