
#include "../include/MelodieSimpla.h"
#include "../include/melodie.h"
#include "../include/inputHandler.h"
MelodieSimpla::MelodieSimpla(): Melodie() {}
MelodieSimpla::MelodieSimpla(const std::string& titlu, const std::string& genMuzical): Melodie(titlu, genMuzical) {

}
MelodieSimpla::~MelodieSimpla() = default;

std::istream& operator>>(std::istream& in, MelodieSimpla& melodie){
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
  return in;
}
std::ostream& operator<<(std::ostream& out, const MelodieSimpla& melodie){
  out << "Titlu: " << melodie.titlu << "\nGen Muzical: " << melodie.genMuzical;
  return out;
}