#include "../include/concert.h"
#include "../include/activitate.h"
#include <iostream>
#include "../include/bodyguard.h"
#include "../include/tehnicianSunet.h"

int Concert::nrConcerte = 0;
Concert::Concert(): Activitate(), locatie(), numarSpectatori(0), album(), echipaTehnica() {
  nrConcerte++;
}

Concert::Concert( int succes, const std::shared_ptr<Oras>& locatie, const std::shared_ptr<Album>& album): Activitate(succes){
  this->locatie = locatie;
  this->album = album;
  this->numarSpectatori = 0;
  nrConcerte++;
}
Concert::~Concert() = default;
void Concert::angajeazaPersonal(const std::shared_ptr<Persoana>& p) {
  const auto& ref = *p;
  if (typeid(ref) == typeid(TehnicianSunet) || typeid(ref) == typeid(Bodyguard)) {
    echipaTehnica.push_back(p);
    std::cout << "Angajatul a fost adaugat in echipa tehnica" << std::endl;
  }
}
float Concert::calculeazaNrSpectatori() {
  auto estimare = locatie->aflaPopularitate() * static_cast<float>(locatie->aflaLocuriDisponibile());
  numarSpectatori = static_cast<int>(estimare);
  return static_cast<float>(numarSpectatori)/static_cast<float>(locatie->aflaLocuriDisponibile());
}
int Concert::calculeazaCosturi(){
    costConcert += locatie->calculeazaCosturi();
    for (const auto& p : echipaTehnica) {
      const auto& ref = *p;
      if (typeid(ref) == typeid(TehnicianSunet)) {
        costConcert+= p->calculeazaCost();
      }
      if (typeid(ref) == typeid(Bodyguard)) {
        costConcert+= p->calculeazaCost();
      }
    }
    return costConcert;
}
void Concert::desfasoaraActivitate() {
  std::cout << "---RAPORT ACTIVITATE---"<<std::endl;
  float raportPrezenta = this->calculeazaNrSpectatori();
  std::cout << "S-au prezentat " << numarSpectatori << " de spectatori la concert"<<std::endl;
  int contributieTehnician = 0;
  int contributieBodyguard = 0;
  for (const auto& p : echipaTehnica) {
    const auto& ref = *p;
    if (typeid(ref) == typeid(TehnicianSunet)) {
      contributieTehnician = p->contributie();
    }
    else if (typeid(ref) == typeid(Bodyguard)) {
      contributieBodyguard = p->contributie();
    }
  }
  this->calculeazaSucces(raportPrezenta, contributieTehnician, contributieBodyguard);
}
void Concert::calculeazaSucces(float raportPrezenta, int contributieTehnician, int contributieBodyguard) {
  float t = static_cast<float>(contributieTehnician)/100.0f;
  float b = static_cast<float>(contributieBodyguard)/100.0f;
  succes = static_cast<int>(((t + b + raportPrezenta)/ 3.0f)*100.0f);
  std::cout << "Succesul final al concertului a fost de " << succes << std::endl;
}
int Concert::profit() const {
  return static_cast<int>(static_cast<float>(PRET_BILET*numarSpectatori)*(static_cast<float>(succes)/100.0f));
}
int Concert::crestePopularitatea(int popularitate) const{
  return static_cast<int>((static_cast<float>(succes)/100.0) * static_cast<float>(popularitate));
}
int Concert::getNrConcerte() {
  return nrConcerte;
}
void Concert::resetContor() {
  nrConcerte = 0;
}


std::ostream& operator<<(std::ostream& out, const Concert& c) {
  std::cout << "Concertul a avut loc in ";
  c.locatie->afiseazaNume();
  std::cout << " cu ";
  out << c.numarSpectatori;
  std::cout << " spectatori.";
  std::cout << std::endl;
  return out;
}