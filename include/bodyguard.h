
#ifndef BODYGUARD_H
#define BODYGUARD_H
#include <string>

class Bodyguard: public Persoana {
private:
  int costPeEveniment;
  int eficienta;
public:
  Bodyguard();
  Bodyguard(const std::string& nume, const std::string& prenume, int varsta, int costPeEveniment, int eficienta);
  ~Bodyguard() override;

  void afiseaza() const override;
  int contributie() override;
  int calculeazaCost() const override;
};



#endif
