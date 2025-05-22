
#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <ostream>


class Transport {
protected:
  int costPeRunda;
  float fiabilitate;
public:
  Transport();
  Transport(int costPeRunda, float fiablilitate);
  virtual ~Transport() = default;

  virtual void afisare(std::ostream& out) const = 0;
  virtual int calculeazaCost() const = 0;

  friend std::ostream& operator<<(std::ostream& out, const Transport& t);
};



#endif
