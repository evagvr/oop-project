
#ifndef AVION_H
#define AVION_H
#include <ostream>

#include "transport.h"


class Avion: public Transport{
public:
    Avion();
    Avion(int costPeRunda, float fiabilitate);
    ~Avion() override;

    void afisare(std::ostream& out) const override;
    int calculeazaCost() const override;
    float getFiabilitate() const override;
};



#endif //AVION_H
