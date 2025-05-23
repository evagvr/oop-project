#ifndef TRUPA_H
#define TRUPA_H
#include "album.h"
#include "concert.h"
#include <string>
#include <vector>
#include <memory>
#include "persoana.h"
#include "muzician.h"
#include "manager2.h"
#include "producator.h"

#include "melodie.h"

class Trupa{
private:
  std::string nume;
  std::vector<std::shared_ptr<Muzician>> membri;
  std::vector<std::shared_ptr<Muzician>> membriFosti;
  std::shared_ptr<Manager> manager;
  std::shared_ptr<ProducatorMuzical> producator;
  std::vector<std::shared_ptr<Album>> albume;
public:
  Trupa();
  Trupa(const std::string& nume, const std::shared_ptr<Manager>& manager, const std::shared_ptr<ProducatorMuzical>& producator);
  Trupa(const std::shared_ptr<Manager>& manager, const std::shared_ptr<ProducatorMuzical>& producator);
  Trupa& operator=(const Trupa& trupa);
  ~Trupa();

  std::vector<std::shared_ptr<Persoana>> echipa() const;
  bool areMembriFosti() const;
  void adaugaMembruFost(const std::shared_ptr<Muzician>& m);
  const std::vector<std::shared_ptr<Muzician>>& getMembriFosti() const;
  void restaurareMembruFost(int index);

  int calculeazaSkillLevelTrupa() const;
  std::shared_ptr<Melodie> creeazaMelodie();
  void inregistreazaAlbum(const std::shared_ptr<Album>& a);
  std::vector<std::shared_ptr<Muzician>> realizeazaIerarhie();
  void eliminaMembru(int index);
  void adaugaMembru(std::shared_ptr<Muzician>& m);
  void selecteazaMembru();
  std::shared_ptr<Album> selecteazaAlbum() const;
  void verificaTrupa();

  void organizeazaConcert(Concert &c);

  friend std::istream& operator>>(std::istream& in, Trupa& t);
  friend std::ostream& operator<<(std::ostream& out, const Trupa& t);
};
#endif