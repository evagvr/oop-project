#include "../include/producator.h"
#include <iostream>
#include <random>

ProducatorMuzical::ProducatorMuzical(): Persoana(){
  this->cost = 0;
  this->experienta = 0;
  this->succese = 0;
}
ProducatorMuzical::ProducatorMuzical(const std::string& nume, const std::string& prenume, int varsta, int cost, int experienta, int succese): Persoana(nume, prenume, varsta){
  this->cost = cost;
  this->experienta = experienta;
  this->succese = succese;
}
ProducatorMuzical :: ProducatorMuzical (const ProducatorMuzical& other): Persoana(other){
  if(this != &other){
    this->cost = other.cost;
    this->experienta = other.experienta;
    this->succese = other.succese;
  }
}
ProducatorMuzical& ProducatorMuzical::operator=(const ProducatorMuzical& other){
  if (this != &other){
    Persoana::operator=(other);
    this->cost = other.cost;
    this->experienta = other.experienta;
    this->succese = other.succese;
  }
  return *this;
}
ProducatorMuzical::~ProducatorMuzical() = default;


int ProducatorMuzical::contributie() {
  return (experienta + succese)/2;
}

void ProducatorMuzical::cresteriAnuale() {
  experienta++;
  succese += experienta/2;
  if (succese + experienta > 15) {
    cost = succese*experienta;
  }
}
int ProducatorMuzical::calculeazaCost() const {
  return cost;
}

void ProducatorMuzical::contributieConcert() {
  succese++;
  std::cout << "Melodiile producatorului au fost apreciate de fani" << std::endl;
}
int ProducatorMuzical::influenteazaJoc() const {
  if (succese + experienta > 15) {
    return 400;
  }
  else {
    return -200;
  }
}


void ProducatorMuzical::afiseaza() const {
  std::cout << "Nume: " << nume << " " << prenume << ", varsta " << varsta
            << " ani (experienta: " << experienta <<", succese: "<< succese << ")"
            << std::endl;
}
void ProducatorMuzical::contributieTurneu() const {
  std::cout << "Piesele producatorului, " << nume << " " << prenume << " au fost apreciate de public." << std::endl;
}

std::istream& operator>>(std::istream& in, ProducatorMuzical& p){
  std::cout<<"\nNume: ";
  in>>p.nume;
  std::cout<<"\nPrenume: ";
  in>>p.prenume;
  std::cout<<"\nVarsta: ";
  in>>p.varsta;
  std::cout<<"\nExperienta: ";
  in>>p.experienta;
  std::cout<<"\nSucces: ";
  in>>p.succese;
  return in;
}
std::ostream& operator<<(std::ostream& out, const ProducatorMuzical& p){
  out <<"Nume: "<<p.nume<<", Prenume: "<<p.prenume<<" (Varsta: "<<p.varsta
      <<", Cost: "<< p.cost <<", Experienta: "<<p.experienta<<", Succese: "
      <<p.succese<<")\n";
  return out;
}