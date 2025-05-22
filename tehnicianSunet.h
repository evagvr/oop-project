
#ifndef TEHNICIANSUNET_H
#define TEHNICIANSUNET_H
#include "persoana.h"


class TehnicianSunet: public Persoana {
private:
  int costPeEveniment;
  int eficienta;
public:
  TehnicianSunet();
  TehnicianSunet(const std::string& nume, const std::string& prenume, int varsta, int costPeEveniment, int eficienta);
  ~TehnicianSunet() override;

  int contributie() override;
  int calculeazaCost() const override;
  void afiseaza() const override;
};



#endif
