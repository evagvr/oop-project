#ifndef PERSOANA_H
#define PERSOANA_H
#include <iostream>


class Persoana {
protected:
  std::string nume;
  std::string prenume;
  int varsta;

public:
  Persoana();
  Persoana(const std::string& nume, const std::string& prenume, int varsta);
  Persoana(const Persoana& other);
  Persoana& operator=(const Persoana& other);
  virtual ~Persoana();

  virtual int calculeazaCost() const = 0;
  virtual int contributie() = 0;
  virtual void afiseaza() const = 0;

};
#endif
