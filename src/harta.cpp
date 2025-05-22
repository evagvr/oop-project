//

#include "../include/harta.h"
#include "../include/oras.h"
#include <vector>
#include <memory>

Harta::Harta(){
  this->oraseDisponibile.clear();
}
Harta::~Harta()=default;


void Harta::incarcaDate(){
  oraseDisponibile.push_back(std::make_shared<Oras>("Bucuresti", 0.5, 300, 9000, 0));
  oraseDisponibile.push_back(std::make_shared<Oras>("Cluj-Napoca", 0.8, 300, 10000, 0.1));
  oraseDisponibile.push_back(std::make_shared<Oras>("Timisoara", 0.4, 100, 5000, 0));
  oraseDisponibile.push_back(std::make_shared<Oras>("Iasi", 0.6, 200, 8000, 0.1));
  oraseDisponibile.push_back(std::make_shared<Oras>("Brasov", 0.53, 100, 6000, 0.1));
  oraseDisponibile.push_back(std::make_shared<Oras>("Constanta", 0.7, 200, 7000, 0));
  oraseDisponibile.push_back(std::make_shared<Oras>("Sibiu", 0.5, 300, 6000, 0.3));
  oraseDisponibile.push_back(std::make_shared<Oras>("Oradea", 0.7, 200, 5000, 0.1));
  oraseDisponibile.push_back(std::make_shared<Oras>("Londra", 0.3, 600, 12000, 0.6));
  oraseDisponibile.push_back(std::make_shared<Oras>("Paris", 0.3, 700, 11000, 0.4));
  oraseDisponibile.push_back(std::make_shared<Oras>("Berlin", 0.2, 600, 10000, 0.4));
  oraseDisponibile.push_back(std::make_shared<Oras>("Roma", 0.4, 700, 11000, 0.2));
  oraseDisponibile.push_back(std::make_shared<Oras>("Madrid", 0.2, 400, 12000, 0.5));
  oraseDisponibile.push_back(std::make_shared<Oras>("Amsterdam", 0.3, 500, 10000, 0.5));
  oraseDisponibile.push_back(std::make_shared<Oras>("Praga", 0.3, 400, 9000, 0.1));
  oraseDisponibile.push_back(std::make_shared<Oras>("Viena", 0.1, 500, 10000, 0.5));
  oraseDisponibile.push_back(std::make_shared<Oras>("Budapesta", 0.4, 400, 8000, 0.1));
  oraseDisponibile.push_back(std::make_shared<Oras>("Atena", 0.4, 400, 7500, 0.2));
  oraseDisponibile.push_back(std::make_shared<Oras>("Lisabona", 0.3, 300, 8000, 0.3));
  oraseDisponibile.push_back(std::make_shared<Oras>("Stockholm", 0.4, 300, 7000, 0.2));
}
std::vector<std::shared_ptr<Oras>> Harta::getOrase() const {
  return this->oraseDisponibile;
}

