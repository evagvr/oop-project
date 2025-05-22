
#ifndef AUTOCAR_H
#define AUTOCAR_H
#include "transport.h"


class Autocar: public Transport {
private:
public:
  Autocar();
  Autocar(int costPeRunda, float fiabilitate);
  ~Autocar() override;

  void afisare(std::ostream& out) const override;
  int calculeazaCost() const override;
};



#endif
