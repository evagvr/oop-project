#ifndef EVENIMENTE_H
#define EVENIMENTE_H
#include <string>
class Eveniment{
private:
  std::string descriere;
  int modificareBuget;
  int modificarePopularitate;
  bool modificareTrupa;
public:
  Eveniment();
  Eveniment(const std::string& descriere, int modificareBuget, int modificarePopularitate, bool modificareTrupa);
  ~Eveniment();

  void areLoc() const;
  int modificaBuget() const;
  int modificaPopularitate() const;
  bool modificaTrupa() const;
};
#endif