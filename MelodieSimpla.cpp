
#include "MelodieSimpla.h"
#include "melodie.h"

MelodieSimpla::MelodieSimpla(): Melodie() {}
MelodieSimpla::MelodieSimpla(const std::string& titlu, const std::string& genMuzical): Melodie(titlu, genMuzical) {

}
MelodieSimpla::~MelodieSimpla() = default;

std::istream& operator>>(std::istream& in, MelodieSimpla& melodie){
  std::cout << "Titlu: ";
  in >> melodie.titlu;
  std::cout << "Gen Muzical: ";
  in >> melodie.genMuzical;
  return in;
}
std::ostream& operator<<(std::ostream& out, const MelodieSimpla& melodie){
  out << "Titlu: " << melodie.titlu << "\nGen Muzical: " << melodie.genMuzical;
  return out;
}