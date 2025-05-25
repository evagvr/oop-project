
#ifndef MELODIESIMPLA_H
#define MELODIESIMPLA_H
#include "melodie.h"


class MelodieSimpla: public Melodie {
  private:
  public:
    MelodieSimpla();
    MelodieSimpla(const std::string& titlu, const std::string& genMuzical);
    ~MelodieSimpla() override;

    void afiseaza(std::ostream& out) const override;
    bool equals(const Melodie& other) const override;
    friend std::istream& operator>>(std::istream& in, MelodieSimpla& melodie);
};



#endif
