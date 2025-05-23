#include "../include/turneu.h"
#include "../include/activitate.h"
#include <iostream>
#include <vector>
#include <memory>
#include "../include/bodyguard.h"
#include "../include/tehnicianSunet.h"
#include "../include/avion.h"
#include "../include/autocar.h"
#include <list>
int Turneu::nrTurnee = 0;
const int Turneu::COST_MINIM = 10900;

Turneu::Turneu(): Activitate(){
  durata = 0;
  this->bileteVandute = 0;
  orase.clear();
  echipaTurneu.clear();
  track.clear();
  nrTurnee++;
}
Turneu::Turneu(int succes, int durata, const std::vector<std::shared_ptr<Oras>>& orase, const std::list<std::shared_ptr<Melodie>>& track): Activitate(succes) {
  this->durata = durata;
  this->bileteVandute = 0;
  this->orase = orase;
  this->track = track;
  nrTurnee++;
}
Turneu::~Turneu() = default;
const std::vector<std::shared_ptr<Transport>> Turneu::modalitatiTransport = {
  std::make_shared<Avion>(10000, 10),
  std::make_shared<Avion>(9000, 8),
  std::make_shared<Autocar>(7000, 5),
  std::make_shared<Autocar>(7500, 6)
};
void Turneu::afiseazaModalitatiTransport(){
  for (const auto& mod: modalitatiTransport) {
    if (auto m = std::dynamic_pointer_cast<Transport>(mod)) {
      std::cout << *m;
    }
  }
}
std::shared_ptr<Transport> Turneu::selecteazaModalitatiTransport(){
  int opt;
  while (true) {
    std::cin.clear();
    std::cin >> opt;
    if (std::cin.fail() || opt <= 0 || opt > static_cast<int>(modalitatiTransport.size())) {
      std::cout << "Optiunea ta nu exista." << std::endl;
      continue;
    }
    return modalitatiTransport[opt-1];
  }
}
int Turneu::calculeazaProfit() const {
  return static_cast<int>(static_cast<float>(PRET_BILET*bileteVandute)*(static_cast<float>(succes)/100.0));
}
int Turneu::calculeazaPopularitate(int popularitate) const{
  return static_cast<int>((static_cast<float>(succes)/100.0) * static_cast<float>(popularitate));
}
void Turneu::angajeazaPersonal(const std::shared_ptr<Persoana>& p) {
  if (typeid(*p)  == typeid(TehnicianSunet) || typeid(*p) == typeid(Bodyguard)) {
    echipaTurneu.push_back(p);
    std::cout << "Angajatul a fost adaugat cu succes" <<std::endl;
  }
}
float Turneu::calculeazaNrSpectatori(int nrRunda, int& nrSpectatori) const {
  auto estimare = orase[nrRunda]->aflaPopularitate() * static_cast<float>(orase[nrRunda]->aflaLocuriDisponibile());
  nrSpectatori = static_cast<int>(estimare);
  return static_cast<float>(nrSpectatori)/static_cast<float>(orase[nrRunda]->aflaLocuriDisponibile());
}

void Turneu::selecteazaTransport() {
  std::cout << "Selecteaza modalitatea de transport" <<std::endl;
  afiseazaModalitatiTransport();
  modalitateTransport = selecteazaModalitatiTransport();
}
int Turneu::calculeazaCosturi() {
  return durata * 10000;
}
void Turneu::adaugaLocatie(const std::shared_ptr<Oras> &o) {
  orase.push_back(o);
}

bool Turneu::orasNeselectat(const std::shared_ptr<Oras>& o) const {
  if (static_cast<int>(orase.size()) != 0) {
    for (const auto& oras: orase) {
      if (*oras == *o) {
        return false;
      }
    }
  }
  return true;
}

int Turneu::costRunda() const {
  int costTotal = 0;
  costTotal += modalitateTransport->calculeazaCost();

  for (const auto& p: echipaTurneu) {
    if (auto b = std::dynamic_pointer_cast<Bodyguard>(p)) {
      costTotal += b->calculeazaCost();
    }
    else if(auto t = std::dynamic_pointer_cast<TehnicianSunet>(p)) {
      costTotal += t->calculeazaCost();
    }
  }
  return costTotal;
}
void Turneu::stabilesteNrRunde(int nrRunde) {
  durata = nrRunde;
}

void Turneu::desfasoaraActivitate(){

  std::cout << "---RAPORT ACTIVITATE---"<<std::endl;
  for (int i = 0; i < durata; i++) {
    std::cout << "Locatia nr." << i+1 <<" a turneului";
    int nrSpectatori;
    float raportPrezenta = calculeazaNrSpectatori(i,nrSpectatori);
    std::cout << "S-au prezentat " << nrSpectatori << " de spectatori"<<std::endl;
    int contributieTehnician = 0;
    int contributieBodyguard = 0;
    for (const auto& p : echipaTurneu) {
      if (typeid(*p) == typeid(TehnicianSunet)) {
        contributieTehnician = p->contributie();
      }
      else if (typeid(*p) == typeid(Bodyguard)) {
        contributieBodyguard = p->contributie();
      }
    }
    calculeazaSuccesRunda(i, raportPrezenta, contributieTehnician, contributieBodyguard);
  }
}
void Turneu::calculeazaSuccesRunda(int nrRunda, float raportPrezenta, int contributieTehnician, int contributieBodyguard) {
  auto t = static_cast<float>(contributieTehnician)/100.0;
  auto b = static_cast<float>(contributieBodyguard)/100.0;
  succes += static_cast<int>(((t + b + raportPrezenta)/ 3.0)*100.0);
  std::cout << "Succesul final al rundei "<< nrRunda + 1<<" a fost de " << succes << std::endl;
}
std::istream& operator>>(std::istream& in, Turneu& turneu){
  std::cout << "Cate locatii vrei sa contina turneul" << std::endl;
  in >> turneu.durata;
  return in;
}
int Turneu::getNrTurnee() {
  return nrTurnee;
}
