#include "../include/muzician.h"
#include <iostream>
#include <random>

#include "../include/exceptii.h"
#include "../include/gameplay.h"
int Muzician:: totalMuzicieni = 0;
Muzician::Muzician(): Persoana(){
    this->numeScena = "necunoscut";
    this->tipInstrument = "necunoscut";
    this->skillLevel = 0;
    this->cooperativitate = 0;
    this->ego = 0;
    totalMuzicieni++;
}
Muzician::Muzician(int skillLevel, int cooperativitate, int ego): Persoana() {
  this->numeScena = "necunoscut";
  this->tipInstrument = "necunoscut";
  this->skillLevel = skillLevel;
  this->cooperativitate = cooperativitate;
  this->ego = ego;
}
Muzician::Muzician(const std::string& nume, const std::string& prenume, int varsta, const std::string& numeScena, const std::string& tipInstrument, int skillLevel, int cooperativitate, int ego): Persoana(nume, prenume, varsta){
  this->numeScena = numeScena;
  this->tipInstrument = tipInstrument;
  this->skillLevel = skillLevel;
  this->cooperativitate = cooperativitate;
  this->ego = ego;
}
Muzician::Muzician(const Muzician &other): Persoana(other),numeScena(other.numeScena), tipInstrument(other.tipInstrument), skillLevel(other.skillLevel), cooperativitate(other.cooperativitate), ego(other.ego) {}

Muzician& Muzician::operator=(const Muzician& other) {
  if (this!= &other) {
    Persoana::operator=(other);
    this->numeScena = other.numeScena;
    this->tipInstrument = other.tipInstrument;
    this->skillLevel = other.skillLevel;
    this->cooperativitate = other.cooperativitate;
    this->ego = other.ego;
  }
  return *this;
}
Muzician::~Muzician() = default;

int Muzician::obtineSkilllevel() const {
  return skillLevel;
}
void Muzician::contributieTurneu() const{
  if (skillLevel > 8) {
    std::cout << numeScena << " a cantat excelent" << std::endl;
  }
  else if (skillLevel > 3){
    std::cout << numeScena << " a cantat bine, dar s-a vazut ca nu era prea bine pregatit" << std::endl;
  }
  else {
    std::cout << numeScena << " s-a chinuit destul de tare sa tina pasul." << std::endl;
  }
}
void Muzician::repetitii(){
  try {
    skillLevel++;
    if (skillLevel >= 10) {
      skillLevel = 10;
      throw ExceptieSkillLevel();
    }
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << this->numeScena << " si-a crescut skillLevel-ul la "<< skillLevel <<std::endl;
}
void Muzician::status() const{
  std::cout << "Muzician: " << this->numeScena << std::endl;
  std::cout << "Tip: " << this->tipInstrument << std::endl;
  std::cout << "SkillLevel: " << this->skillLevel << std::endl;
}
void Muzician::modificareSkillLevel() {
  skillLevel--;
}
int Muzician::contributie() {
  return static_cast<int>((cooperativitate-ego)/2);
}
void Muzician::contributieConcert() const {
  std::cout << numeScena << " a cantat" <<std::endl;
}
int Muzician::calculeazaCost() const {
  return 0;
}

void Muzician::afiseazaNume() const {
  std::cout << nume;
}
void Muzician::afiseaza() const {
  std::cout << "Nume: " << nume << " " << prenume << ", varsta " << varsta
            << " ani (skill: " << skillLevel <<", cooperativitate: "
            << cooperativitate << ", ego: " << ego << ")" << std::endl;
}

bool Muzician::operator==(const Muzician& other) const {
  if (this->nume == other.nume && this->prenume == other.prenume)
    return true;
  else
    return false;
}

std::istream& operator>>(std::istream& in, Muzician& m){
  bool valid = false;
  while (!valid) {
    std::cout << "Nume: ";
    in >> m.nume;
    std::cout << "\nPrenume: ";
    in >> m.prenume;
    std::cout << "\nVarsta (numar intre 18 - 60): ";
    m.varsta = Gameplay::citesteInt(18, 60);
    std::cout << "\nNume de Scena: ";
    in >> m.numeScena;
    std::cout << "\nTip Instrument: ";
    std::cout << "\n1. Voce  2. Chitara  3. Tobe" <<std::endl;
    int optiune = Gameplay::citesteInt(1,3);
    if (optiune == 1) {
      m.tipInstrument = "voce";
    }
    else if (optiune == 2) {
      m.tipInstrument = "chitara";
    }
    else if (optiune == 3) {
      m.tipInstrument = "tobe";
    }
    auto persoane = BazaDateJoc<Persoana>::getInstance()->getItems();
    bool exista = false;
    for (const auto& p : persoane) {
      if (auto muz = std::dynamic_pointer_cast<Muzician>(p)) {
        if (*muz == m) {
          exista = true;
          break;
        }
      }
    }
    if (exista) {
      std::cout << "\nUn muzician cu aceste date exista deja in baza de date. Reintrodu datele.\n";
    } else {
      valid = true;
    }
  }
  return in;
}
std::ostream& operator<<(std::ostream& out, const Muzician& m){
  std::cout << "Nume: ";
  out << m.nume;
  std::cout << ", Prenume: ";
  out << m.prenume;
  std::cout << " (Varsta: ";
  out << m.varsta;
  std::cout << ", Nume de Scena: ";
  out << m.numeScena;
  std::cout << ", Tip Instrument: ";
  out << m.tipInstrument;
  std::cout << ", Skill Level: ";
  out << m.skillLevel;
  std::cout << ", Cooperativitate: ";
  out << m.cooperativitate;
  std::cout << ", Ego: ";
  out << m.ego;
  out << ")" << std::endl;
  return out;
}
bool operator>(const Muzician& m1, const Muzician& m2) {
  if (m1.obtineSkilllevel() > m2.obtineSkilllevel())
    return true;
  else
    return false;
}

