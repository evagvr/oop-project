#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "trupa.h"
#include "turneu.h"
#include "bazaDateJoc.h"
#include <vector>
#include <string>
#include "jucator.h"
#include "../include/inputHandler.h"
class Gameplay{
private:
    int contorRepetitii;
    InputHandler verifInput;
    std::shared_ptr<Jucator> jucator;
    std::shared_ptr<BazaDateJoc<Oras>> bazaDateLocatii;
    std::shared_ptr<BazaDateJoc<Persoana>> bazaDatePersoane;

    static const std::vector<std::shared_ptr<Transport>> modalitatiTransport;
public:
    Gameplay();
    ~Gameplay();

    int costMinimLocatie(const std::shared_ptr<Turneu>& t) const;
    std::shared_ptr<Oras> selecteazaLocatie(const std::shared_ptr<Turneu>& turneu) const;
    void afiseazaLocatiiDisponibile(const std::shared_ptr<Turneu>& turneu) const;

    template<typename T>
    void afiseazaPersoaneSpecifice() const;
    template<typename T>
    std::shared_ptr<T> selecteazaPersoanaDupaId() const;
    void setup();
    void start();
    void afisareDate() const;
    void meniu() const;
    void incrementeazaAn();
    void cresteBuget(int crestere) const;
    void scadeBuget(int scadere) const;
    void crestePopularitate(int crestere) const;
    bool terminareJoc() const;
    void repetitii();
    void inregistreazaAlbum() const;
    void modificaTrupa() const ;
    void afiseazaStatusTrupa() const;
    void help() const;
    void concert() const;
    void turneu() const;
    bool reset() const;
    void raportFinal() const;
    bool retry() const;
    bool aparDubluri(const std::shared_ptr<Muzician>& m) const;
    int citesteInt(int min, int max) const;
    std::string validareString(const std::vector<std::string>& inputOptions) const;

};

#endif