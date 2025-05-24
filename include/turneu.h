#ifndef TURNEU_H
#define TURNEU_H
#include "activitate.h"
#include <vector>
#include <string>
#include "oras.h"
#include "transport.h"
#include "melodie.h"
#include "persoana.h"
#include <memory>
#include <list>


class Turneu: public Activitate{
private:
    ///de regandit pentru mijloace de transport + modificare costuri locatie
    static int nrTurnee;
    static const int COST_MINIM;
    static const int PRET_BILET = 50;
    int durata;
    int bileteVandute;
    std:: vector<std::shared_ptr<Oras>> orase;
    std::shared_ptr<Transport> modalitateTransport;
    std::list<std::shared_ptr<Melodie>> track;
    std::list<std::shared_ptr<Persoana>> echipaTurneu;
    static const std::vector<std::shared_ptr<Transport>> modalitatiTransport;

public:
    Turneu();
    Turneu(int succes, int durata, const std::vector<std::shared_ptr<Oras>>& orase, const std::list<std::shared_ptr<Melodie>>& track);
    ~Turneu() override;


    int calculeazaPopularitate(int popularitate) const;
    int calculeazaProfit() const;
    void calculeazaSuccesRunda(int nrRunda, float raportPrezenta, int contributieTehnician, int contributieBodyguard);
    void stabilesteNrRunde(int nrRunde);
    bool orasNeselectat(const std::shared_ptr<Oras>& o) const;
    void adaugaLocatie(const std::shared_ptr<Oras>& o);
    int costRunda() const;
    static void afiseazaModalitatiTransport();
    static std::shared_ptr<Transport> selecteazaModalitatiTransport();
    void selecteazaTransport();
    void angajeazaPersonal(const std::shared_ptr<Persoana>& p);
    float calculeazaNrSpectatori(int nrRunda, int& nrSpectatori);
    int calculeazaCosturi() override;
    void desfasoaraActivitate() override;
    static int getNrTurnee();
    friend std::istream& operator>>(std::istream& in, Turneu& turneu);
};

#endif