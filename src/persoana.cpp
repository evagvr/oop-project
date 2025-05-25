#include "../include/persoana.h"

Persoana::Persoana(){
    this->nume = "necunoscut";
    this->prenume = "necunoscut";
    this->varsta = 0;
}
Persoana::Persoana(const std::string& nume, const std::string& prenume, int varsta){
    this->nume = nume;
    this->prenume = prenume;
    this->varsta = varsta;
}
Persoana::Persoana(const Persoana &other) {
    if (this!= &other) {
        this->nume = other.nume;
        this->prenume = other.prenume;
        this->varsta = other.varsta;
    }
}

Persoana& Persoana:: operator=(const Persoana& other){
  if(this != &other){
    this->nume = other.nume;
    this->prenume = other.prenume;
    this->varsta = other.varsta;
  }
  return *this;
}
Persoana::~Persoana() = default;
