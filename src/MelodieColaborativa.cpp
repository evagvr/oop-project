
#include "../include/MelodieColaborativa.h"

#include "../include/inputHandler.h"
#include "../include/melodie.h"

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
  InputHandler verifInput;
  std::cout << "Titlu: ";
  in >> melodie.titlu;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "Gen Muzical: 1) Pop 2) Rock 3) Electronic 4) Clasic" <<std::endl;
  std::cout << "Optiunea ta: ";
  int opt = verifInput.getIntInput(1,4);
  if (opt == 1) {
    melodie.genMuzical = "Pop";
  }
  else if (opt == 2) {
    melodie.genMuzical = "Rock";
  }
  else if (opt == 3) {
    melodie.genMuzical = "Electronic";
  }
  else if (opt == 4) {
    melodie.genMuzical = "Clasic";
  }
  std::cout << "\nArtistul cu care doresti sa faci colaborarea: ";
  in >> *melodie.artistColaborator;
  return in;
}
std::ostream& operator<<(std::ostream& out, const MelodieColaborativa& melodie) {
  out << "Titlu: "<< melodie.titlu << "\nGen Muzical: " << melodie.genMuzical << "\nArtistul cu care a fost facuta colaborarea: " << *melodie.artistColaborator;
  return out;
}