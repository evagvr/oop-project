#include "album.h"
#include "melodie.h"
#include <iostream>
#include <memory>
#include "MelodieColaborativa.h"
#include "MelodieSimpla.h"

int Album::nrAlbume = 0;
Album::Album() : titlu("Album Necunoscut"), dataLansare(0),nrMelodii(0), melodii{}, calitateAlbum(0) {
    nrAlbume++;
}

Album::Album(const std::string& titlu, int dataLansare, int nrMelodii
    , const std::list<std::shared_ptr<Melodie>>& melodii)
    : titlu(titlu), dataLansare(dataLansare),  nrMelodii(nrMelodii), melodii(melodii), calitateAlbum(0) {
    nrAlbume++;
}

Album::Album(const Album& other)
    : titlu(other.titlu), dataLansare(other.dataLansare), nrMelodii(other.nrMelodii)
    , melodii(other.melodii), calitateAlbum(other.calitateAlbum) {}

Album& Album::operator=(const Album& other) {
    if (this != &other) {
        titlu = other.titlu;
        dataLansare = other.dataLansare;
        nrMelodii = other.nrMelodii;
        melodii = other.melodii;
        calitateAlbum = other.calitateAlbum;
    }
    return *this;
}

Album::~Album() = default;

void Album::calculeazaCalitateAlbum(int medieSkillLevel) {
    int contribuireSkilllevelColab = 0;
    int nrColaborari = 0;
    for (const auto& melodie : melodii) {
        if (auto mel = std::dynamic_pointer_cast<MelodieColaborativa>(melodie)) {
            contribuireSkilllevelColab += mel->contributieColaborator();
            nrColaborari++;
        }
    }
    if (nrColaborari > 0) {
        contribuireSkilllevelColab /= nrColaborari;
        calitateAlbum = (medieSkillLevel + contribuireSkilllevelColab)/2;
    }
    else
        calitateAlbum = medieSkillLevel;
}
int Album::stabilesteCresterePopularitate() const {
    if (calitateAlbum > 7)
        return 8;
    else if (calitateAlbum > 4)
        return 6;
    else
        return 4;
}

int Album::stabilesteProfit(int buget) const {
    int castig = (CASTIG_MINIM_PER_MELODIE*nrMelodii + calitateAlbum*static_cast<int>(buget/RATA_INFLUENTA_BUGET)) * dataLansare;
    return castig;
}
int Album::getNrAlbume() {
    return nrAlbume;
}


std::ostream& operator<<(std::ostream& out, const Album& a) {
    out << "\nNume album: " << a.titlu <<"\n An lansare: " << a.dataLansare << "\n Numar de melodii: " << a.nrMelodii
    <<"\n Calitatea albumului: "<< a.calitateAlbum << "\n";
    for (const auto& melodie: a.melodii) {
        if (auto melS = std::dynamic_pointer_cast<MelodieSimpla>(melodie)) {
            out << *melS << "\n";
        }
        else if (auto melC = std::dynamic_pointer_cast<MelodieColaborativa>(melodie)) {
            out << *melC << "\n";
        }
    }
    return out;
}

