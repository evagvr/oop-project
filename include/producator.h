#ifndef PRODUCATOR_H
#define PRODUCATOR_H
#include "persoana.h"
#include <string>

class ProducatorMuzical: public Persoana {
private:
  int cost;
  int experienta;
  int succese;
public:
  ProducatorMuzical();
  ProducatorMuzical(const std::string& nume, const std::string& prenume, int varsta, int cost, int experienta, int succes);
  ProducatorMuzical(const ProducatorMuzical& other);
  ProducatorMuzical& operator=(const ProducatorMuzical& other);
  ~ProducatorMuzical() override;

  void contributieTurneu() const;
  int calculeazaCost() const override;
  int contributie() override;
  void contributieConcert();
  void cresteriAnuale();
  void afiseaza() const override;
  int influenteazaJoc() const;

  friend std::istream& operator>>(std::istream& in, ProducatorMuzical& p);
  friend std::ostream& operator<<(std::ostream& out, const ProducatorMuzical& p);
};
#endif