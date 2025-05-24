#include <iostream>
#include <memory>
#include <algorithm>
#include <random>
#include <limits>
#include "../include/bazaDateJoc.h"
#include "../include/trupa.h"
#include "../include/album.h"
#include "../include/exceptii.h"
#include "../include/gameplay.h"

Trupa::Trupa(): nume("necunoscut"), manager(), producator(){}
Trupa::Trupa(const std::string& nume, const std::shared_ptr<Manager>& manager, const std::shared_ptr<ProducatorMuzical>& producator){
  this->nume = nume;
  this->membri.clear();
  this->manager = manager;
  this->producator = producator;
}
Trupa::Trupa(const std::shared_ptr<Manager>& manager, const std::shared_ptr<ProducatorMuzical>& producator) {
  this->membri.clear();
  this->manager = manager;
  this->producator = producator;
}
Trupa& Trupa::operator=(const Trupa& other) {
  if (this != &other) {
    this->nume = other.nume;
    this->manager = other.manager;
    this->producator = other.producator;
    this->albume = other.albume;
    this->membri.clear();
    for (const auto& membru : other.membri)
      this->membri.push_back(membru);
  }
  return *this;
}
Trupa::~Trupa() = default;

int Trupa::calculeazaSkillLevelTrupa() const {
  /// deschimbat astfel incat calitatea albumului sa fie influentata si de producator
  int medieSkilllevel = 0;
  for (const auto& membru: this->membri) {
    medieSkilllevel+= membru->obtineSkilllevel();
  }
  medieSkilllevel = medieSkilllevel / static_cast<int>(membri.size());
  return medieSkilllevel;
}
std::vector<std::shared_ptr<Persoana>> Trupa::echipa() const {
  std::vector<std::shared_ptr<Persoana>> echipa;
  if (manager)
    echipa.push_back(manager);
  if (producator)
    echipa.push_back(producator);
  for (const auto& membru : membri)
    echipa.push_back(membru);
  return echipa;
}

void Trupa::eliminaMembru(int index){
  if (index >= 0 && index < static_cast<int>(membri.size())) {
    adaugaMembruFost(membri[index]);
    membri[index]->afiseazaNume();
    std::cout << " a parasit trupa" << std::endl;
    membri.erase(membri.begin() + index);
  }
}
std::vector<std::shared_ptr<Muzician>> Trupa::realizeazaIerarhie() {
  std::sort(membri.begin(), membri.end(), [](const std::shared_ptr<Muzician>& m1, const std::shared_ptr<Muzician>& m2) {
    return *m1 > *m2;
  });
  return membri;
}
void Trupa::inregistreazaAlbum(const std::shared_ptr<Album>& a){
  albume.push_back(a);
}

void Trupa::adaugaMembru(std::shared_ptr<Muzician>& m) {
  this->realizeazaIerarhie();
  std::cout << *this->membri[0];
  std::shared_ptr<Muzician> m1 = this->membri.at(0);
  if (*m1 > *m) {
    membri.push_back(m);
    m->afiseazaNume();
    std::cout << " s-a alaturat cu succes trupei."<<std::endl;
  }
  else
    std::cout << "Din pacate artistul selectat este prea avansat pentru trupa si nu a acceptat" << std::endl;
}


std::shared_ptr<Album> Trupa::selecteazaAlbum() const {
  std::cout << "Selecteaza ce album vrei sa fie prezentat in cadrul concertului" << std::endl;
  for (size_t i = 0; i < this->albume.size(); i++)
    std::cout << i+1 <<". "<< *albume.at(i) << std::endl;
  std::cout << "Optiunea ta: ";
  int optiune;
  std::cin >> optiune;
  return albume.at(optiune-1);

}

bool Trupa::verificaTrupa() {
  for (const auto& membru: membri) {
    if (membru->obtineSkilllevel() == 0) {
      membru->afiseazaNume();
      std::cout << " a ramas la skillLevel-ul 0, acesta a parasit trupa." << std::endl;
    }
  }
  membri.erase(
    std::remove_if(membri.begin(), membri.end(),[](const std::shared_ptr<Muzician>& m) {
      return m->obtineSkilllevel() == 0;
    }),
    membri.end()
    );
  if (membri.empty()) {
    return false;
  }
  return true;

}

bool Trupa::areMembriFosti() const {
  return !membriFosti.empty();
}

void Trupa::adaugaMembruFost(const std::shared_ptr<Muzician>& m) {
  membriFosti.push_back(m);
}

const std::vector<std::shared_ptr<Muzician>>& Trupa::getMembriFosti() const {
  return membriFosti;
}

void Trupa::restaurareMembruFost(int index) {
  if (index >= 0 && index < static_cast<int>(membriFosti.size())) {
    membri.push_back(membriFosti[index]);
    membriFosti.erase(membriFosti.begin() + index);
  }
}

std::istream& operator>>(std::istream& in, Trupa& t){
  InputHandler verifInput;
  auto persoane = BazaDateJoc<Persoana>::getInstance()->getItems();
  std::vector<std::shared_ptr<Manager>> manageriDisponibili;
  std::vector<std::shared_ptr<ProducatorMuzical>> producatoriDisponibili;
  std::vector<std::shared_ptr<Muzician>> muzicieniDisponibili;
  for (const auto& pers: persoane) {
    if (auto m = std::dynamic_pointer_cast<Manager>(pers)) {
      manageriDisponibili.push_back(m);
    }
    else if (auto p = std::dynamic_pointer_cast<ProducatorMuzical>(pers)) {
      producatoriDisponibili.push_back(p);
    }
    else if (auto muz = std::dynamic_pointer_cast<Muzician>(pers)) {
      muzicieniDisponibili.push_back(muz);
    }
  }
  std::cout << "Nume trupa: ";
  in >> t.nume;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "Pentru inceput vom infiinta trupa" << std:: endl;
  std::cout << "Alege un manager: " << std:: endl;
  for (size_t i = 0; i < manageriDisponibili.size(); i++) {
    std::cout << i+1 << ") "<< *manageriDisponibili[i];
  }

  std::cout << "Optiunea ta: ";
  int optiune;
  optiune = verifInput.getIntInput(1, static_cast<int>(manageriDisponibili.size()));
  t.manager = manageriDisponibili[optiune-1];
  std::cout << "Alege un producator: " << std:: endl;
  for (size_t i = 0; i < producatoriDisponibili.size(); i++) {
    std::cout << i+1 << ") "<< *producatoriDisponibili[i];
  }
  std::cout << "Optiunea ta: ";
  optiune = verifInput.getIntInput(1, static_cast<int>(producatoriDisponibili.size()));
  t.producator = producatoriDisponibili[optiune-1];
  std::vector<std::shared_ptr<Muzician>> membriiAlesi;
  std::cout << "Acum vei avea de ales 3 membrii ai trupei" << std::endl;
  std::cout << "Scrie \"c\" pentru a contiuna:";

  for (size_t i = 0; i < muzicieniDisponibili.size(); i++) {
    std::cout << i+1 << ") "<< *muzicieniDisponibili[i];
  }
  for (int i = 1; i < 4; i++) {
    std::cout << "Alege Membrul nr." << i << ": ";
    bool valid = false;
    while (!valid) {
      try{
        optiune = verifInput.getIntInput(1, static_cast<int>(muzicieniDisponibili.size()));
      auto selectat = muzicieniDisponibili[optiune - 1];

      auto exista = std::find_if(
          t.membri.begin(), t.membri.end(),
          [&selectat](const std::shared_ptr<Muzician>& m) {
              return *m == *selectat;
          }
      );

      if (exista != t.membri.end()) {
        throw ExceptieMembruDuplicat();
      }
      t.membri.push_back(selectat);
      valid = true;
      } catch (const ExceptieMembruDuplicat& ) {
        std::cout << "Membru deja in trupa. Reincearca: ";
      } catch(const std::exception& ){
        std::cout << "Eroare la citirea optiunii. Reincearca: ";
      }
    }
  }
  return in;
}
std::ostream& operator<<(std::ostream& out, const Trupa& t){
  out<<"Nume trupa: "<<t.nume<<"\nManager: "<<*t.manager<<"\nProducator: "<<*t.producator;
  out << "Membrii: ";
  for (size_t i = 0; i < t.membri.size(); i++) {
    out << i+1 << ") "<< *t.membri[i] << std::endl;
  }

  return out;
}