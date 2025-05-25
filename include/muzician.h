#ifndef MUZICIAN_H
#define MUZICIAN_H
#include <memory>
#include <string>
#include "persoana.h"

class Muzician: public Persoana{

private:
  std::string numeScena;
  std::string tipInstrument;
  int skillLevel;
  int cooperativitate;
  int ego;

public:
  Muzician();
  Muzician(int skillLevel, int cooperativitate, int ego);
  Muzician(const std::string& nume, const std::string& prenume, int varsta,const std::string& numeScena, const std::string& tipInstrument, int skillLevel, int cooperativitate, int ego);
  Muzician(const Muzician& other);
  Muzician& operator=(const Muzician& other);
  ~Muzician() override;


  void status() const;
  int obtineSkilllevel() const;
  void modificareSkillLevel();
  void repetitii();
  int calculeazaCost() const override;
  int contributie() override;
  void afiseaza() const override;
  void contributieConcert() const;
  void contributieTurneu() const;
  void afiseazaNume() const;

  bool operator==(const Muzician& other) const;

  friend std::istream& operator>>(std::istream& in, Muzician& m);
  friend std::ostream& operator<<(std::ostream& out, const Muzician& m);
};
bool operator>(const Muzician& m1, const Muzician& m2);

#endif