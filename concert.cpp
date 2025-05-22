#include "concert.h"
#include "activitate.h"
#include <string>
#include <iostream>

#include "bodyguard.h"
#include "tehnicianSunet.h"

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
  if (typeid(*p) == typeid(TehnicianSunet) || typeid(*p) == typeid(Bodyguard)) {
    echipaTehnica.push_back(p);
    std::cout << "Angajatul a fost adaugat in echipa tehnica" << std::endl;
  }
}
float Concert::calculeazaNrSpectatori() {
  float estimare = locatie->aflaPopularitate() * locatie->aflaLocuriDisponibile();
  numarSpectatori = static_cast<int>(estimare);
  return static_cast<float>(numarSpectatori)/static_cast<float>(locatie->aflaLocuriDisponibile());
}
int Concert::calculeazaCosturi(){
    costConcert += locatie->calculeazaCosturi();
    for (const auto& p : echipaTehnica) {
      if (typeid(*p) == typeid(TehnicianSunet)) {
        costConcert+= p->calculeazaCost();
      }
      if (typeid(*p) == typeid(Bodyguard)) {
        costConcert+= p->calculeazaCost();
      }
    }
    return costConcert;
}
void Concert::desfasoaraActivitate() {
  std::cout << "---RAPORT ACTIVITATE---"<<std::endl;
  float raportPrezenta = calculeazaNrSpectatori();
  std::cout << "S-au prezentat " << numarSpectatori << " de spectatori la concert"<<std::endl;
  int contributieTehnician = 0;
  int contributieBodyguard = 0;
  for (const auto& p : echipaTehnica) {
    if (typeid(*p) == typeid(TehnicianSunet)) {
      contributieTehnician = p->contributie();
    }
    else if (typeid(*p) == typeid(Bodyguard)) {
      contributieBodyguard = p->contributie();
    }
  }
  calculeazaSucces(raportPrezenta, contributieTehnician, contributieBodyguard);
}
void Concert::calculeazaSucces(float raportPrezenta, int contributieTehnician, int contributieBodyguard) {
  float t = contributieTehnician/100.0f;
  float b = contributieBodyguard/100.0f;
  succes = static_cast<int>(((t + b + raportPrezenta)/ 3.0f)*100.0f);
  std::cout << "Succesul final al concertului a fost de " << succes << std::endl;
}
void Concert::setareAlbum(const std::shared_ptr<Album> &a) {
  this->album = a;
}
int Concert::profit() const {
  return static_cast<int>(PRET_BILET*numarSpectatori*(succes/100.0f));
}
int Concert::crestePopularitatea(int popularitate) const{
  return static_cast<int>((succes/100.0f) * popularitate);
}
int Concert::getNrConcerte() {
  return nrConcerte;
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