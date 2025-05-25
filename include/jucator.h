
#ifndef JUCATOR_H
#define JUCATOR_H
#include <memory>
#include "trupa.h"

class Jucator {
  private:
    int an;
    int buget;
    int popularitate;
    std::shared_ptr<Trupa> trupa;

    Jucator();
    static std::shared_ptr<Jucator> instance;

  public:
    Jucator(const Jucator& j) = delete;
    Jucator& operator=(Jucator& j) = delete;
    static std::shared_ptr<Jucator> getInstance();

  int getBuget() const;
  void schimbaBuget(int b);
  int getPopularitate() const;
  void schimbaPopularitate(int p);
  int getAnCurent() const;
  void cresteAn();

  std::shared_ptr<Trupa> getTrupa() const;
  void construiesteTrupa();

  void afiseazaStatistici() const;
  void reset();

};



#endif
