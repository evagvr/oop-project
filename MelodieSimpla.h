
#ifndef MELODIESIMPLA_H
#define MELODIESIMPLA_H
#include "melodie.h"


class MelodieSimpla: public Melodie {
  private:
  public:
    MelodieSimpla();
    MelodieSimpla(const std::string& titlu, const std::string& genMuzical);
    ~MelodieSimpla() override;

    friend std::istream& operator>>(std::istream& in, MelodieSimpla& melodie);
    friend std::ostream& operator<<(std::ostream& out, const MelodieSimpla& melodie);
};



#endif
