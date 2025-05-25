#ifndef ALBUM_H
#define ALBUM_H
#include <string>
#include <iostream>
#include "melodie.h"
#include <memory>
#include <list>
class Album {
private:
    static int nrAlbume;
    static const int COEFICIENT_CALITATE = 2;
    static const int RATA_INFLUENTA_BUGET = 10;
    static const int CASTIG_MINIM_PER_MELODIE = 50;
    static constexpr int RANDOM_BANI_MIN = 1;
    static constexpr int RANDOM_BANI_MAX = 3;
    std::string titlu;
    int dataLansare;
    int nrMelodii;
    std::list<std::shared_ptr<Melodie>> melodii;
    int calitateAlbum;

public:
    Album();
    Album(const std::string& titlu, int dataLansare, int nrMelodii, const std::list<std::shared_ptr<Melodie>>& melodii);
    Album(const Album& other);
    Album& operator=(const Album& other);
    ~Album();
    int stabilesteCresterePopularitate(int contributieManager) const;
    int stabilesteProfit(int buget, int contributieManager) const;
    void calculeazaCalitateAlbum(int medieSkillLevel, int contributieProducator);
    void schimbaTitlu(const std::string& titluNou);
    static int getNrAlbume();
    static void resetContor();
    bool operator==(const Album& other) const;
    friend std::ostream& operator<<(std::ostream& out, const Album& a);
};
#endif