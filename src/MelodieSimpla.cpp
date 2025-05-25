
#include "../include/MelodieSimpla.h"

#include <memory>

#include "../include/melodie.h"
#include "../include/inputHandler.h"
MelodieSimpla::MelodieSimpla(): Melodie() {}
MelodieSimpla::MelodieSimpla(const std::string& titlu, const std::string& genMuzical): Melodie(titlu, genMuzical) {

}
MelodieSimpla::~MelodieSimpla() = default;

std::istream& operator>>(std::istream& in, MelodieSimpla& melodie){
  InputHandler verifInput;
  std::cout << "Titlu: ";
  std::getline(std::cin, melodie.titlu);
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
void MelodieSimpla::afiseaza(std::ostream &out) const {
  out << "Melodie Simpla: Titlu: " << titlu << "\nGen Muzical: " << genMuzical;
}
bool MelodieSimpla::equals(const Melodie& other) const {
  const auto* o = dynamic_cast<const MelodieSimpla*>(&other);
  if (!o) return false;
  return titlu == o->titlu && genMuzical == o->genMuzical;
}