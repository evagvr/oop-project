#pragma once
#include <memory>

#include "persoana.h"
#include <string>

class Muzician: public Persoana{

private:
  std::string numeScena;
  std::string tipInstrument;
  int skillLevel;
  int cooperativitate;
  int ego;

  static int totalMuzicieni;
public:
  Muzician();
  Muzician(int skillLevel, int cooperativitate, int ego);
  Muzician(const std::string& nume, const std::string& prenume, int varsta,const std::string& numeScena, const std::string& tipInstrument, int skillLevel, int cooperativitate, int ego);
  Muzician(const Muzician& other);
  Muzician& operator=(const Muzician& other);
  ~Muzician() override;


  void contributieTurneu() const;
  int obtineSkilllevel() const;
  int calculeazaCost() const override;
  void contributieConcert() const;
  void afiseazaNume() const;
  void repetitii();
  void status() const;
  void modificareSkillLevel();
  int contributie() override;
  void afiseaza() const override;

  bool operator==(const Muzician& other) const;

  friend std::istream& operator>>(std::istream& in, Muzician& m);
  friend std::ostream& operator<<(std::ostream& out, const Muzician& m);
};
bool operator>(const Muzician& m1, const Muzician& m2);

