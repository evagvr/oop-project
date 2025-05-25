
#include "../include/jucator.h"

std::shared_ptr<Jucator> Jucator::instance = nullptr;
Jucator::Jucator(): an(0), buget(5000), popularitate(0), trupa(nullptr) {}

std::shared_ptr<Jucator> Jucator::getInstance() {
  if(instance == nullptr){
    instance = std::shared_ptr<Jucator>(new Jucator());
  }
  return instance;
}
int Jucator::getBuget() const { return buget; }
void Jucator::schimbaBuget(int b) {
 buget = buget + b;
}

int Jucator::getPopularitate() const { return popularitate; }
void Jucator::schimbaPopularitate(int p) {
  popularitate = popularitate + p;
}

int Jucator::getAnCurent() const { return an; }
void Jucator::cresteAn() {
  an++;
}

std::shared_ptr<Trupa> Jucator::getTrupa() const { return trupa; }
void Jucator::construiesteTrupa() {
  trupa = std::make_shared<Trupa>();
  std::cin >> *trupa;
}



void Jucator::afiseazaStatistici() const {
  std::cout << "---Anul: " << an << "---\n";
  std::cout << "Buget: " << buget << " RON\n";
  std::cout << "Popularitate: " << popularitate << "\n";
  if (!trupa)
    std::cout << "Trupa nu a fost inca setata.\n";
}


void Jucator::reset() {
  buget = 5000;
  popularitate = 0;
  an = 0;
  trupa = nullptr;
}