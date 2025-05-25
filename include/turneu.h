#ifndef TURNEU_H
#define TURNEU_H
#include "activitate.h"
#include <vector>
#include "oras.h"
#include "transport.h"
#include "melodie.h"
#include "persoana.h"
#include <memory>
#include <list>


class Turneu: public Activitate{
private:
    static int nrTurnee;
    static const int COST_MINIM;
    static constexpr int PRET_BILET = 50;
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

    int calculeazaCosturi() override;
    void desfasoaraActivitate() override;
    int calculeazaPopularitate(int popularitate) const;
    int calculeazaProfit() const;
    void calculeazaSuccesRunda(int nrRunda, float raportPrezenta, int contributieTehnician, int contributieBodyguard);
    void stabilesteNrRunde(int nrRunde);
    bool orasNeselectat(const std::shared_ptr<Oras>& o) const;
    void adaugaLocatie(const std::shared_ptr<Oras>& o);
    void selecteazaTransport();
    void angajeazaPersonal(const std::shared_ptr<Persoana>& p);
    float calculeazaNrSpectatori(int nrRunda, int& nrSpectatori);
    static void afiseazaModalitatiTransport();
    static std::shared_ptr<Transport> selecteazaModalitatiTransport();
    static int getNrTurnee();
    static void resetContor();
};

#endif