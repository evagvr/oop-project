#include <iostream>
#include "../include/transport.h"
#include "../include/avion.h"

Avion::Avion(): Transport(){}
Avion::Avion(int costPeRunda, float fiabilitate): Transport(costPeRunda, fiabilitate){}
Avion::~Avion() = default;

void Avion::afisare(std::ostream& out) const {
    out << "Avion - costul pentru deplasare per locatie: " << costPeRunda << ", fiabilitate: " << fiabilitate<< std::endl;
}
int Avion::calculeazaCost() const {
    return costPeRunda;
}
float Avion::getFiabilitate() const {
    return fiabilitate;
}
