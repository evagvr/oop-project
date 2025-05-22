//
//

#ifndef HARTA_H
#define HARTA_H
#include <vector>
#include <memory>
#include "oras.h"


class Harta {
private:
  std::vector<std::shared_ptr<Oras>> oraseDisponibile;
public:
  Harta();
  ~Harta();

  void incarcaDate();
  std::vector<std::shared_ptr<Oras>> getOrase() const;
};



#endif //HARTA_H
