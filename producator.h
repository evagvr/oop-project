#pragma once
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
  int produceMelodie() const;
  int contributie() override;
  void contributieConcert();
  void colaboreaza();
  void devineIndisponibil();
  void devineDisponibil();
  bool esteDisponibil();
  void cresteSucces();
  void cresteSuccesAnual();
  void cresteExperienta();
  void afiseaza() const override;
  int influenteazaJoc() const;

  friend std::istream& operator>>(std::istream& in, ProducatorMuzical& p);
  friend std::ostream& operator<<(std::ostream& out, const ProducatorMuzical& p);
};