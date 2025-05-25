#ifndef MELODIE_H
#define MELODIE_H
#include <string>
#include <iostream>




class Melodie{
protected:
  std::string titlu;
  std::string genMuzical;
public:
  Melodie();
  Melodie(const std::string& titlu, const std::string& genMuzical);
  virtual ~Melodie();
  virtual void afiseaza(std::ostream& out) const = 0;
  virtual bool equals(const Melodie& other) const = 0;
  virtual const std::type_info& type() const { return typeid(*this); }
  friend std::ostream& operator<<(std::ostream& out, const Melodie& m);
};
inline bool operator==(const Melodie& m1, const Melodie& m2) {
  if (m1.type() != m2.type()) return false;
  return m1.equals(m2);
}
#endif