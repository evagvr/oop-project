#include "../include/album.h"
#include "../include/melodie.h"
#include <iostream>
#include <memory>
#include "../include/MelodieColaborativa.h"
#include "../include/MelodieSimpla.h"

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

void Album::calculeazaCalitateAlbum(int medieSkillLevel, int contributieProducator) {
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
    calitateAlbum = static_cast<int>(calitateAlbum + (contributieProducator * 0.1));

    if (calitateAlbum > 10)
        calitateAlbum = 10;
}
int Album::stabilesteCresterePopularitate(int contributieManager) const {
    int baza;
    if (calitateAlbum > 7)
        baza = 8;
    else if (calitateAlbum > 4)
        baza = 6;
    else
        baza = 4;
    int bonus = contributieManager / 5;
    return baza + bonus;
}

int Album::stabilesteProfit(int buget,int contributieManager) const {
    int castig = (CASTIG_MINIM_PER_MELODIE*nrMelodii + calitateAlbum*(buget/RATA_INFLUENTA_BUGET)) * dataLansare;

    return static_cast<int>(castig + contributieManager*0.1);
}
void Album::schimbaTitlu(const std::string& titluNou) {
    titlu = titluNou;
}

int Album::getNrAlbume() {
    return nrAlbume;
}
void Album::resetContor() {
    nrAlbume = 0;
}

bool Album::operator==(const Album &other) const {
    return titlu == other.titlu;
}


std::ostream& operator<<(std::ostream& out, const Album& a) {
    out << "\nNume album: " << a.titlu <<"\n An lansare: " << a.dataLansare << "\n Numar de melodii: " << a.nrMelodii
    <<"\n Calitatea albumului: "<< a.calitateAlbum << "\n";
    for (const auto& mel: a.melodii) {
            out << *mel << "\n";
    }
    return out;
}

