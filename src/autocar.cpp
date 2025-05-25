#include <iostream>
#include "../include/autocar.h"


Autocar::Autocar(): Transport(){}
Autocar::Autocar(int costPeRunda, float fiabilitate): Transport(costPeRunda, fiabilitate){}
Autocar::~Autocar() = default;

void Autocar::afisare(std::ostream &out) const {
    out << "Autocar - costul pentru deplasare per locatie: " << costPeRunda << ", fiabilitate: " << fiabilitate << std::endl;
}
int Autocar::calculeazaCost() const {
    return costPeRunda;
}
float Autocar::getFiabilitate() const {
    return fiabilitate;
}
