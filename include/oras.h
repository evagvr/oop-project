#ifndef ORAS_H
#define ORAS_H
#include <string>

class Oras {
private:
  std::string nume;
  float popularitateTrupa;
  int capacitatePublic;
  int costuriLogistice;
  float riscuri;
public:
  Oras();
  Oras(const std::string& nume, float popularitateTrupa, int capacitatePublic, int costuriLogistice, float riscuri);
  ~Oras();

  bool operator==(const Oras& other) const;
  bool operator<(const Oras& other) const;
  float aflaPopularitate() const;
  int aflaLocuriDisponibile() const;
  void afiseazaNume();
  int calculeazaCosturi() const;
  void afiseazaInfo();
};



#endif
