#include "../include/gameplay.h"
#include "../include/trupa.h"
#include "../include/tehnicianSunet.h"
#include "../include/bodyguard.h"
#include <iostream>
#include <random>
#include <typeinfo>
#include "../include/concert.h"
#include "../include/turneu.h"
#include "../include/MelodieSimpla.h"
#include "../include/MelodieColaborativa.h"
#include "../include/avion.h"
#include "../include/exceptii.h"
#include "../include/jucator.h"
#include "../include/oras.h"
#include "../include/bazaDateJoc.h"
#include <list>
#include "../include/validation.h"

int Gameplay::costMinimLocatie(const std::shared_ptr<Turneu>& turneu) {
  auto orase = bazaDateLocatii->getItems();
  int costMinim = orase[0]->calculeazaCosturi();
  for (const auto& o : orase) {
    if (o->calculeazaCosturi() < costMinim && turneu->orasNeselectat(o)) {
      costMinim = o->calculeazaCosturi();
    }
  }
  return costMinim;
}

template<typename T>
void Gameplay::afiseazaModalitatiTransport() const {
  for (const auto& mod: modalitatiTransport) {
    if (auto m = std::dynamic_pointer_cast<T>(mod)) {
      std::cout << *m;
    }
  }
}
template<typename T>
std::shared_ptr<T> Gameplay::selecteazaModalitatiTransport() const{
  int opt;
  while (true) {
    std::cin.clear();
    std::cin >> opt;
    if (std::cin.fail() || opt <= 0 || opt > static_cast<int>(modalitatiTransport.size())) {
      std::cout << "Optiunea ta nu exista." << std::endl;
      continue;
    }
    else if (typeid(modalitatiTransport[opt-1])!=typeid(T)) {
      std::cout << "Nu ai selectat o optiune corecta" << std::endl;
    }
    return modalitatiTransport[opt-1];
  }
}

void Gameplay::afiseazaLocatiiDisponibile(const std::shared_ptr<Turneu>& turneu) const{
  //// de adaugat sa nu afiseze locatiile deja selectate
  auto orase = bazaDateLocatii->getItems();
  for (size_t i = 0; i < orase.size(); i++ ) {
    if (jucator->getBuget() >= orase[i]->calculeazaCosturi() && turneu->orasNeselectat(orase[i]))
      std::cout << i+1 << ".) " << orase[i] << std::endl;
  }
  std::cout << "Selecteaza locatia care te intereseaza: ";
}
std::shared_ptr<Oras> Gameplay::selecteazaLocatieDupaId(const std::shared_ptr<Turneu>& turneu) {
  auto orase = bazaDateLocatii->getItems();
  while (true) {
    int optiune;
    std::cin.clear();
    std::cin >> optiune;
    if (std::cin.fail() || optiune <= 0 || optiune > static_cast<int>(orase.size())) {
      std::cout << "Nu ai introdus o optiune corecta, mai incearca: " << std::endl;
      continue;
    }
    if (orase[optiune-1]->calculeazaCosturi() > jucator->getBuget() && turneu->orasNeselectat(orase[optiune-1])) {
      std::cout << "Nu ai introdus o optiune corecta, mai incearca: " << std::endl;
      continue;
    }
    scadeBuget(orase[optiune-1]->calculeazaCosturi());
    return orase[optiune-1];
  }
}

template<typename T>
void Gameplay::afiseazaPersoaneSpecifice() {
  for (size_t i = 0; i < bazaDatePersoane->getItems().size(); i++) {
    auto& ref = *bazaDatePersoane->getItems()[i];
    if (typeid(ref) == typeid(T)) {
      std::cout << i+1 << ") ";
      bazaDatePersoane->getItems()[i]->afiseaza();
      std::cout << std::endl;
    }
  }
}
bool Gameplay::aparDubluri(const std::shared_ptr<Muzician>& m) {
  for (const auto& p: jucator->getTrupa()->echipa()) {
    if (auto membru = std::dynamic_pointer_cast<Muzician>(p)) {
      if (*membru == *m) {
        return true;
      }
    }
  }
  return false;
}

template<typename T>
std::shared_ptr<T> Gameplay::selecteazaPersoanaDupaId() {
  int index;
  while (true) {
    std::cin.clear();
    std::cin >> index;
    if (std::cin.fail() || index - 1 < 0 || index - 1 >= static_cast<int>(bazaDatePersoane->getItems().size())) {
      std::cout << "Nu ai introdus un input corect, mai incearca: ";
      continue;
    }
    auto& ref = *bazaDatePersoane->getItems()[index-1];
    if (typeid(ref) != typeid(T)) {
      std::cout << "Persoana de la indexul " << index << " nu este de tipul cerut, mai incearca: ";
      continue;
    }
    if (typeid(T) == typeid(Muzician)) {
      if (aparDubluri(std::dynamic_pointer_cast<Muzician>(bazaDatePersoane->getItems()[index-1]))) {
         std::cout << "Persoana de la indexul " << index << " se afla deja in trupa, mai incearca: ";
        continue;
      }
    }
    return std::dynamic_pointer_cast<T>(bazaDatePersoane->getItems()[index-1]);
  }
}
Gameplay::Gameplay(): contorRepetitii(0), bazaDateLocatii ( BuilderBazaDateJoc<Oras>()
  .adaugaItem(std::make_shared<Oras>("Bucuresti", 0.5, 300, 9000, 0))
  .adaugaItem(std::make_shared<Oras>("Cluj-Napoca", 0.8, 300, 10000, 0.1))
  .adaugaItem(std::make_shared<Oras>("Timisoara", 0.4, 100, 5000, 0))
  .adaugaItem(std::make_shared<Oras>("Iasi", 0.6, 200, 8000, 0.1))
  .adaugaItem(std::make_shared<Oras>("Brasov", 0.53, 100, 6000, 0.1))
  .adaugaItem(std::make_shared<Oras>("Constanta", 0.7, 200, 7000, 0))
  .adaugaItem(std::make_shared<Oras>("Sibiu", 0.5, 300, 6000, 0.3))
  .adaugaItem(std::make_shared<Oras>("Oradea", 0.7, 200, 5000, 0.1))
  .adaugaItem(std::make_shared<Oras>("Londra", 0.3, 600, 12000, 0.6))
  .adaugaItem(std::make_shared<Oras>("Paris", 0.3, 700, 11000, 0.4))
  .adaugaItem(std::make_shared<Oras>("Berlin", 0.2, 600, 10000, 0.4))
  .adaugaItem(std::make_shared<Oras>("Roma", 0.4, 700, 11000, 0.2))
  .adaugaItem(std::make_shared<Oras>("Madrid", 0.2, 400, 12000, 0.5))
  .adaugaItem(std::make_shared<Oras>("Amsterdam", 0.3, 500, 10000, 0.5))
  .adaugaItem(std::make_shared<Oras>("Praga", 0.3, 400, 9000, 0.1))
  .adaugaItem(std::make_shared<Oras>("Viena", 0.1, 500, 10000, 0.5))
  .adaugaItem(std::make_shared<Oras>("Budapesta", 0.4, 400, 8000, 0.1))
  .adaugaItem(std::make_shared<Oras>("Atena", 0.4, 400, 7500, 0.2))
  .adaugaItem(std::make_shared<Oras>("Lisabona", 0.3, 300, 8000, 0.3))
  .adaugaItem(std::make_shared<Oras>("Stockholm", 0.4, 300, 7000, 0.2))
  .build()), bazaDatePersoane ( BuilderBazaDateJoc<Persoana>()
  .adaugaItem(std::make_shared<Manager>("Gheorghe", "Cristian", 25, 150, 3, 10))
  .adaugaItem(std::make_shared<Manager>("Stoinescu", "Valentina", 23,  100, 2, 6))
  .adaugaItem(std::make_shared<Manager>("Neacsu", "Rares", 24, 100, 2, 3))
  .adaugaItem(std::make_shared<ProducatorMuzical>("Muresan", "Larisa - Elena", 26, 170,4, 3))
  .adaugaItem(std::make_shared<ProducatorMuzical>("Iordanescu", "Costin", 23, 140, 2, 1))
  .adaugaItem(std::make_shared<ProducatorMuzical>("Rosu", "Sarina", 22, 100,  1, 1))
  .adaugaItem(std::make_shared<Muzician>("Sorescu", "Simona", 20, "Simi", "chitara", 2, 5, 5))
  .adaugaItem(std::make_shared<Muzician>("Elvira", "Roxana", 21, "Roxana", "chitara", 3, 6, 8))
  .adaugaItem(std::make_shared<Muzician>("Popescu", "Sebastian", 21, "Sebastian", "chitara", 3, 7, 3))
  .adaugaItem(std::make_shared<Muzician>("Marinescu", "Cornelia", 19, "Cornelia", "voce", 3, 8, 4))
  .adaugaItem(std::make_shared<Muzician>("Nedelcu", "Robert", 22, "Robert", "voce", 4, 5,1))
  .adaugaItem(std::make_shared<Muzician>("Ghinescu", "Miruna", 19, "Miruna", "voce", 3, 9,5))
  .adaugaItem(std::make_shared<Muzician>("Marin", "Alexandru", 22, "Alex", "tobe", 4, 3, 2))
  .adaugaItem(std::make_shared<Muzician>("Ilie", "Elena", 21, "Eli", "tobe", 3, 3, 8))
  .adaugaItem(std::make_shared<Muzician>("Coman", "Andrei", 22, "Andrei", "tobe", 3, 4, 3))
  .adaugaItem(std::make_shared<TehnicianSunet>("Sarinescu", "Eliza", 23, 500, 29))
  .adaugaItem(std::make_shared<TehnicianSunet>("Rinescu", "Valeriu", 24, 600, 30))
  .adaugaItem(std::make_shared<TehnicianSunet>("Coman", "Maria", 23, 600, 49))
  .adaugaItem(std::make_shared<Bodyguard>("Marian","Ovidiu", 30, 400, 25))
  .adaugaItem(std::make_shared<Bodyguard>("Gheorghe", "Sergiu", 40, 500, 30))
  .adaugaItem(std::make_shared<Bodyguard>("Simion", "Alin", 41, 500, 29))
  .build()) {}

Gameplay::~Gameplay() = default;

void Gameplay::setup() {

  jucator = Jucator::getInstance();

  jucator->construiesteTrupa();

  std::cout << "Asa arata trupa ta acum: " <<std::endl;
  for (const auto& pers: jucator->getTrupa()->echipa()) {
    if (auto mem = std::dynamic_pointer_cast<Muzician>(pers)) {
      std::cout << "Membru al trupei: "<<std::endl;
      std::cout << *mem<< std::endl;
    }
    else if (auto m = std::dynamic_pointer_cast<Manager>(pers)) {
      std::cout << "Manager al trupei: " << std::endl;
      std::cout<< *m << std::endl;
    }
    else if (auto p = std::dynamic_pointer_cast<ProducatorMuzical>(pers)) {
      std::cout << "Producatorul Muzical al trupei: " <<std::endl;
      std::cout << *p << std::endl;
    }
  }
  std::cout <<"Scrie \"c\" pentru a continua: " ;
  validareString({"c"});

}
void Gameplay::start() {
//de schimbat descrierea/tutorialul
  std::cout << "Bine ai venit in jocul MusicLife!" << std::endl;
  std::cout << "MusicLife este un joc care are la baza dezvoltarea unei trupe in lumea muzicala. Tu vei lua rolul unui manager de trupe si va trebui sa dai ce ai mai bun pentru a-ti aduce trupa la succes." << std::endl;
  std::cout << "---------------------------------------" << std::endl;
  std::cout << "Pentru a castiga jocul va trebui sa aduci trupa la succes international(popularitate 100), poti trece la anul urmator inserand \"n\" in cadrul optiunii din meniu ceea ce poate duce la evenimente neasteptate, fie pozitive fie negative, dar ai grija deoarece membrii pot ajunge sa paraseasca trupa, iar in cazul in care ramai fara membri vei pierde jocul, ai la dispozitie 20 de ani." << std::endl;
  std::cout << "Scrie \"start\" pentru a incepe: ";
  validareString({"start"});
  std::cout<< std::endl;
  jucator = Jucator::getInstance();
  afisareDate();
}
void Gameplay::afisareDate() const{
  jucator->afiseazaStatistici();
}

void Gameplay::incrementeazaAn(){
  jucator->cresteAn();
  contorRepetitii = 0;
  if (jucator->getAnCurent() > 1) {
    for (const auto& persoana : jucator->getTrupa()->echipa()) {
      if (auto m = std::dynamic_pointer_cast<Manager>(persoana)) {
        m->cresteExperienta();
        jucator->schimbaBuget(-m->calculeazaCost());
        std::cout << "-" << m->calculeazaCost() << "$ (plata Manager)" << std::endl;
        jucator->schimbaPopularitate(m->influenteazaJoc());
        std::cout << "+" << m->influenteazaJoc() << " popularitate"<< std::endl;
      } else if (auto p = std::dynamic_pointer_cast<ProducatorMuzical>(persoana)) {
        p->cresteExperienta();
        p->cresteSuccesAnual();
        jucator->schimbaBuget(-p->calculeazaCost());
        std::cout << "-" << p->calculeazaCost() << "$ (plata Producator Muzical)" << std::endl;
        if (p->influenteazaJoc() > 0) {
          jucator->schimbaBuget(p->influenteazaJoc());
          std::cout << "+" << p->influenteazaJoc() << "$"<< std::endl;
        }
        else {
          jucator->schimbaBuget(p->influenteazaJoc());
          std::cout << p->influenteazaJoc() << "$" << std::endl;
        }
      } else if (auto mem = std::dynamic_pointer_cast<Muzician>(persoana)) {
        mem->modificareSkillLevel();
        if (mem->obtineSkilllevel() == 0) {
          std::cout << "Ai grija! ";
          mem->afiseazaNume();
          std::cout <<" are skillLevel-ul 0 in acest moment, daca nu ii cresti skillLevel-ul va fi nevoit sa paraseasca trupa!" << std::endl;
        }
      }
    }
  }
}
void Gameplay::cresteBuget(int crestere){
  jucator->schimbaBuget(crestere);
  std::cout<<"+ $"<< crestere<<std::endl;
}
void Gameplay::scadeBuget(int scadere){
  jucator->schimbaBuget(-scadere);
  std::cout<<"- $" << scadere<<std::endl;
}
void Gameplay::crestePopularitate(int crestere){
  jucator->schimbaPopularitate(crestere);
  std::cout << "+ " << crestere << " popularitate"<<std::endl;
}

void Gameplay::meniu() const{
  std::cout << "1. Repetitii cu trupa" << std::endl;
  std::cout << "2. Inregistreaza album" << std::endl;
  std::cout << "3. Modifica statusul trupei (recruteaza membru nou, elimina membru)" << std::endl;
  std::cout << "4. Afiseaza statusul trupei" << std::endl;
  std::cout << "5. Help" << std::endl;
  if (jucator->getPopularitate() > 10){
    std::cout << "6. Organizeaza concert" << std::endl;
    if (jucator->getPopularitate() > 50)
      std::cout << "7. Organizeaza turneu" << std::endl;
  }
  std::cout << "Optiunea ta: ";
}
bool Gameplay::terminareJoc() const{
  try {
    jucator->verificaStatus();
    jucator->getTrupa()->verificaTrupa();
    return false;
  } catch (const ExceptionNoMembersLeft& e) {
    std::cout << "===== Ai pierdut jocul :((( =====" << std::endl;
    std::cout << e.what() << std::endl;
    return true;
  }catch (const ExceptionVictory& e) {
    std::cout << "===== Ai castigat! :)))) =====" << std::endl;
    std::cout << e.what() << std::endl;
    return true;
  } catch (const ExceptionGameOver& e) {
    std::cout << "===== Ai pierdut jocul :((( =====" << std::endl;
    std::cout << e.what() << std::endl;
    return true;
  }
}

void Gameplay::repetitii(){
  if (contorRepetitii < 3) {
    contorRepetitii++;
    for (const auto& persoana: jucator->getTrupa()->echipa()) {
      if (auto m = std::dynamic_pointer_cast<Muzician>(persoana)) {
        m->repetitii();
      }
    }
  }
  else {
    std::cout << "Membrii au obosit, ai facut destule repetitii in decursul acestui an" << std::endl;
  }
  std::cout << "Scrie \"c\" pentru a continua: ";
  validareString({"c"});
}
void Gameplay::inregistreazaAlbum() {
  if (jucator->getBuget() < 500) {
    std::cout << "Ne pare rau! Nu ai suficienti bani pentru a inregistra un album" << std::endl;
  }
  else {
    std::cout<<"--Trupa inregistreaza un album acum--"<<std::endl;
    std::cout<<"Care este bugetul pe care vrei sa il folosesti pentru album(minimul este 500)?"<<std::endl;
    std::cout << "Nu poti folosi mai mult de " << jucator->getBuget() << " (bugetul tau disponibil)"<< std::endl;
    std::cout<<"Raspunsul tau: ";
    int bugetulInvestit;
    bugetulInvestit = verifInput.getIntInput(500, jucator->getBuget());
    std::cout<<std::endl;
    scadeBuget(bugetulInvestit);
    std::cout << "Cate melodii vrei sa aibe albumul?" <<std::endl;
    std::cout << "Raspunsul tau (intre 2 si 6): ";
    int nrMelodii = citesteInt(2,6);
    std::cout<<std::endl;
    std::list<std::shared_ptr<Melodie>> melodii;
    for (int i = 0; i < nrMelodii; i++){
      std::cout << "Melodia nr. " << i+1 << ": " << std::endl;
      std::cout << "Vrei ca trupa sa inregistreze o melodie normala sau impreuna cu un alt artist?" << std::endl;
      std::cout << "Raspunsul tau (1 pentru prima varianta, 2 pentru a doua): ";
      int optiune = citesteInt(1, 2);
      if (optiune == 1) {
        std::shared_ptr<MelodieSimpla> mS= std::make_shared<MelodieSimpla>();
        std::cin >> *mS;
        melodii.push_back(mS);
      }
      else if (optiune == 2) {
        std::shared_ptr<MelodieColaborativa> mC = std::make_shared<MelodieColaborativa>(jucator->getTrupa()->calculeazaSkillLevelTrupa());
        std::cin >> *mC;
        melodii.push_back(mC);

        auto artistNou = mC->getArtist();
        BazaDateJoc<Persoana>::getInstance()->adaugaItem(artistNou);
        std::cout << "\nMuzicianul a fost adaugat cu succes in baza de date.\n";
      }
    }
    std::cout << "Ai creat melodiile, acum sa finalizam ultimele detalii pentru album" <<std::endl;
    std::cout << "Denumirea albumului: ";
    std::string titlu;
    std::cin >> titlu;
    std::shared_ptr<Album> a = std::make_shared<Album>(titlu, jucator->getAnCurent(), nrMelodii, melodii);
    jucator->getTrupa()->inregistreazaAlbum(a);
    a->calculeazaCalitateAlbum(jucator->getTrupa()->calculeazaSkillLevelTrupa());
    crestePopularitate(a->stabilesteCresterePopularitate());
    cresteBuget(a->stabilesteProfit(bugetulInvestit));
    std::cout << *a;
  }
  std::cout << "Scrie \"c\" pentru a continua: ";
  validareString({"c"});
}
void Gameplay::modificaTrupa() {
  std::cout << "Acesta este statusul actual al trupei: " <<std::endl;
  for (const auto& persoana: jucator->getTrupa()->echipa()) {
    if (auto m = std::dynamic_pointer_cast<Muzician>(persoana)) {
      m->status();
    }
  }
  std::cout << "Scrie \"c\" pentru a continua: ";
  validareString({"c"});
  std::cout << "1. Vrei sa elimini un membru"<<std::endl;
  std::cout << "2. Vrei sa recrutezi un membru nou" << std::endl;
  if (jucator->getTrupa()->areMembriFosti()) {
    std::cout << "3. Vrei sa readuci un membru fost" << std::endl;
  }
  std::cout << "Raspunsul tau: ";
  int rasp = citesteInt(1, jucator->getTrupa()->areMembriFosti() ? 3 : 2);
  if (rasp == 1) {
    std::cout << "Membrii vor fi afisati de la cel mai priceput la cel mai putin priceput: " <<std::endl;
    std::vector<std::shared_ptr<Muzician>> top = jucator->getTrupa()->realizeazaIerarhie();
    for (size_t i = 0; i < top.size(); i++) {
      std::cout <<i+1<<". "<< *top.at(i) <<std::endl;
    }
    std::cout << "Numarul membrului pe care vrei sa il elimini: ";
    int opt = verifInput.getIntInput(1,static_cast<int>(top.size()));
    jucator->getTrupa()->eliminaMembru(opt-1);
    std::cout << "Scrie \"c\" pentru a continua: ";
    validareString({"c"});
  }
  else if (rasp == 2) {
    afiseazaPersoaneSpecifice<Muzician>();
    std::cout << "Alege din aceasta lista pe cine doresti sa adaugi: ";
    auto m = selecteazaPersoanaDupaId<Muzician>();
    jucator->getTrupa()->adaugaMembru(m);
    std::cout << "Scrie \"c\" pentru a continua: ";
    validareString({"c"});
  }
  else if (rasp == 3 && jucator->getTrupa()->areMembriFosti()) {
    std::cout << "Membrii fosti disponibili: " << std::endl;
    auto membriFosti = jucator->getTrupa()->getMembriFosti();
    for (size_t i = 0; i < membriFosti.size(); i++) {
      std::cout << i+1 << ". " << *membriFosti[i] << std::endl;
    }
    std::cout << "Alege numarul membrului pe care vrei sa il readuci: ";
    int opt = citesteInt(1, static_cast<int>(membriFosti.size()));
    jucator->getTrupa()->restaurareMembruFost(opt-1);
    std::cout << "Membrul a fost readus in trupa cu succes!" << std::endl;
    std::cout << "Scrie \"c\" pentru a continua: ";
    validareString({"c"});
  }
}
void Gameplay::afiseazaStatusTrupa() const {
  std::cout << *jucator->getTrupa() << std::endl;
}
void Gameplay::help() const {
  std::cout << "Sugestii si strategii: " << std::endl;
}

void Gameplay::concert() {
  if (jucator->getPopularitate() <= 10) {
    std::cout << "Inputul nu este valid!" << std::endl;
    return;
  }
  auto orase = bazaDateLocatii->getItems();
  std::cout<<"--Organizeaza concert pentru trupa--"<<std::endl;
  std::cout << "Scrie (c) daca locatia nu te intereseaza, sau (s) daca este cea pe care vrei sa o selectezi"<<std::endl;
  std::shared_ptr<Oras>orasSelectat = nullptr;
  for (const auto& oras: orase) {
    oras->afiseazaInfo();
    std::string rasp = validareString({"s","c"});
    if (rasp == "s") {
      orasSelectat = oras;
      break;
    }
  }
  if (orasSelectat) {
    std::cout << "Acum trebuie sa alegem personalul necesar: "<< std::endl;
    afiseazaPersoaneSpecifice<TehnicianSunet>();
    std::cout << "Selecteaza un tehnician pentru sunet: ";
    auto tS = selecteazaPersoanaDupaId<TehnicianSunet>();
    afiseazaPersoaneSpecifice<Bodyguard>();
    std::cout << "Selecteaza un bodyguard: ";
    auto bdg = selecteazaPersoanaDupaId<Bodyguard>();
    std::shared_ptr<Album> albumSelectat = jucator->getTrupa()->selecteazaAlbum();
    std::shared_ptr<Concert> c = std::make_shared<Concert>(0, orasSelectat, albumSelectat);
    c->angajeazaPersonal(tS);
    c->angajeazaPersonal(bdg);
    if (c->calculeazaCosturi() < jucator->getBuget()) {
      scadeBuget(c->calculeazaCosturi());
      c->desfasoaraActivitate();
      for (const auto& p: jucator->getTrupa()->echipa()) {
        if (auto m = std::dynamic_pointer_cast<Muzician>(p)) {
          m->contributieConcert();
        }
        else if (auto man = std::dynamic_pointer_cast<Manager>(p)){
          man->contributieConcert();
        }
        else if (auto prod = std::dynamic_pointer_cast<ProducatorMuzical>(p)) {
          prod->contributieConcert();
        }
      }
      cresteBuget(c->profit());
      crestePopularitate(c->crestePopularitatea(jucator->getPopularitate()));
      std::cout << "Scrie \"c\" pentru a continua: ";
      validareString({"c"});
    }
    else {
      std::cout<<"Nu ai fonduri suficiente pentru a organiza un concert" <<std::endl;
      std::cout << "Scrie \"c\" pentru a continua: ";
      validareString({"c"});
    }
  }
  else {
    std::cout << "Nu a fost selectat niciun oras" << std::endl;
    std::cout << "Scrie \"c\" pentru a te intoarce in meniul principal: ";
    validareString({"c"});

  }
}
void Gameplay::turneu() {
  if (jucator->getPopularitate() <= 50) {
    std::cout << "Inputul nu este valid!" << std::endl;
    return;
  }
    std::shared_ptr<Turneu> turneu = std::make_shared<Turneu>();
    std::cout<<"--Organizeaza turneu--"<<std::endl;
    afiseazaPersoaneSpecifice<TehnicianSunet>();
    std::cout << "Selecteaza un Tehnician pentru sunet: "<<std::endl;
    turneu->angajeazaPersonal(selecteazaPersoanaDupaId<TehnicianSunet>());
    afiseazaPersoaneSpecifice<Bodyguard>();
    std::cout << "Selecteaza un Bodyguard: "<<std::endl;
    turneu->angajeazaPersonal(selecteazaPersoanaDupaId<Bodyguard>());
    turneu->selecteazaTransport();
    if (jucator->getBuget() >= turneu->costRunda() + costMinimLocatie(turneu)) {
      ///// de scazut pentru cost per runda pt persoane si transport
      int nrLocatii = 0;
      while (true) {
        std::cout << "Vrei sa setezi o locatie? " << std::endl;
        std::cout << "(1) pentru da, (0) pentru nu: ";
        int optiune = citesteInt(0,1);
        if (optiune == 1){
          scadeBuget(turneu->costRunda());
          afiseazaLocatiiDisponibile(turneu);
          turneu->adaugaLocatie(selecteazaLocatieDupaId(turneu));
          nrLocatii++;
        }
        else {
          std::cout << "Super! Ai terminat de organizat turneul" << std::endl;
          std::cout << "Scrie \"c\" pentru a continua: ";
          validareString({"c"});
          break;
        }
        if (jucator->getBuget() >= turneu->costRunda() + costMinimLocatie(turneu)) {
          std::cout << "Nu mai ai fonduri pentru a organiza o alta runda"<< std::endl;
          std::cout << "Scrie \"c\" pentru a continua: ";
          validareString({"c"});
          break;
        }
      }

      turneu->stabilesteNrRunde(nrLocatii);
      turneu->desfasoaraActivitate();

      for (const auto& p: jucator->getTrupa()->echipa()) {
        if (auto m = std::dynamic_pointer_cast<Muzician>(p)) {
          m->contributieTurneu();
        }
        else if (auto man = std::dynamic_pointer_cast<Manager>(p)){
          man->contributieTurneu();
        }
        else if (auto prod = std::dynamic_pointer_cast<ProducatorMuzical>(p)) {
          prod->contributieTurneu();
        }
      }
      this->cresteBuget(turneu->calculeazaProfit());
      this->crestePopularitate(turneu->calculeazaPopularitate(jucator->getPopularitate()));
    }
    else {
      std::cout << "Din pacate nu ai fonduri suficiente pentru a organiza un turneu" <<std::endl;
      std::cout << "Scrie \"c\" pentru a continua: ";
      validareString({"c"});
    }

  std::cout << "Scrie \"c\" pentru a continua: ";
  validareString({"c"});
}
bool Gameplay::reset() {
  std::cout << "Esti sigur? Asta va sterge totul si nu se va putea recupera!" << std::endl;
  std::cout << "Scrie \"da/nu\": " << std::endl;
  std::string opt = validareString({"da", "nu"});
  if (opt == "da") {
    jucator->reset();
    return true;
  }
  return false;
}
void Gameplay::raportFinal() const {
  std:: cout << "Vrei sa vezi raportul final al activitatii tale? \"da\" sau \"nu\"): ";
  std::string optiune = validareString({"da", "nu"});
  if (optiune == "nu") {
    std::cout << "Ai parasit jocul." << std::endl;
  }
  else {
    std::cout << "===== RAPORT FINAL =====" << std::endl;
    std::cout << "\n\n Totalul albumelor inregistrate de trupa: "<< Album::getNrAlbume() <<std::endl;
    std::cout << " Totalul concertelor organizate: " << Concert::getNrConcerte() << std::endl;
    std::cout << " Totalul turneelor organizate: " << Turneu::getNrTurnee() <<std::endl;
  }
}
int Gameplay::citesteInt(int minim, int maxim) {
  int nr;
  while (true) {
    try {
      nr = Validation::validatingInt(minim,maxim);
      return nr;
    } catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }
}

std::string Gameplay::validareString(const std::vector<std::string>& inputOptions) {
  std::string input;
  while (true) {
    try {
      input = Validation::validatingString(inputOptions);
      return input;
    } catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }
}
