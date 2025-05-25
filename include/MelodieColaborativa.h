
#ifndef MELODIECOLABORATIVA_H
#define MELODIECOLABORATIVA_H
#include "muzician.h"
#include "melodie.h"


class MelodieColaborativa: public Melodie {
private:
  std::shared_ptr<Muzician> artistColaborator;
public:
  explicit MelodieColaborativa(int skillLevelMuzician);
  MelodieColaborativa(const std::string& titlu, const std::string& genMuzical, const std::shared_ptr<Muzician>& artistColaborator);
  ~MelodieColaborativa() override;

  int contributieColaborator() const;
  std::shared_ptr<Muzician> getArtist() const;
  void afiseaza(std::ostream& out) const override;
  bool equals(const Melodie& other) const override;
  friend std::istream& operator>>(std::istream& in, MelodieColaborativa& melodie);

};



#endif
