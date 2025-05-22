
#include "transport.h"

Transport::Transport(){
  costPeRunda = 0;
  fiabilitate = 0;
}
Transport::Transport(int costPeRunda, float fiabilitate){
  this->costPeRunda = costPeRunda;
  this->fiabilitate = fiabilitate;
}
std::ostream& operator<<(std::ostream& out, const Transport& t) {
  t.afisare(out);
  return out;
}