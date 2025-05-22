
#include "MelodieColaborativa.h"
#include "melodie.h"

MelodieColaborativa::MelodieColaborativa(int skillLevelMuzician): Melodie() {
  this->titlu = "";
  this->genMuzical = "";
  this->artistColaborator = std::make_shared<Muzician>(skillLevelMuzician, 0, 0);
}
MelodieColaborativa::MelodieColaborativa(const std::string& titlu, const std::string& genMuzical, const std::shared_ptr<Muzician>& artistColaborator): Melodie(titlu, genMuzical) {
  this->artistColaborator = artistColaborator;
}
MelodieColaborativa::~MelodieColaborativa() = default;

int MelodieColaborativa::contributieColaborator() const {
  return artistColaborator->obtineSkilllevel();
}
std::shared_ptr<Muzician> MelodieColaborativa::getArtist() const {
  return artistColaborator;
}


std::istream& operator>>(std::istream& in, MelodieColaborativa& melodie) {
  std::cout << "Titlu: ";
  in >> melodie.titlu;
  std::cout << "\nGenMuzical: ";
  in >> melodie.genMuzical;
  std::cout << "\nArtistul cu care doresti sa faci colaborarea: ";
  in >> *melodie.artistColaborator;
  return in;
}
std::ostream& operator<<(std::ostream& out, const MelodieColaborativa& melodie) {
  out << "Titlu: "<< melodie.titlu << "\nGen Muzical: " << melodie.genMuzical << "\nArtistul cu care a fost facuta colaborarea: " << *melodie.artistColaborator;
  return out;
}