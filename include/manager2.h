#ifndef MANAGER2_H
#define MANAGER2_H
#include "persoana.h"
#include <string>

class Manager: public Persoana{
private:
  int cost;
  int experienta;
  int conexiuni;

public:
  Manager();
  Manager(const std::string& nume,const std::string& prenume,int varsta, int cost, int experienta, int conexiuni);
  Manager& operator=(const Manager& other);
  ~Manager() override;

  void contributieTurneu() const;
  int calculeazaCost() const override;
  void contributieConcert() const;
  int contributie() override;
  void cresteExperienta();
  void organizeazaEveniment();
  void interactioneazaCuTrupa();
  void gestioneazaCriza();
  void afiseaza() const override;
  int influenteazaJoc() const;

  friend std::istream& operator>>(std::istream& in, Manager& m);
  friend std::ostream& operator<<(std::ostream& out, const Manager& m);
};
#endif