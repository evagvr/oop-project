#ifndef CONCERT_H
#define CONCERT_H
#include "activitate.h"
#include <memory>
#include "oras.h"
#include "album.h"
#include "persoana.h"
#include <vector>

class Concert : public Activitate{
private:
    static int nrConcerte;

    std::shared_ptr<Oras> locatie;
    int numarSpectatori;
    std::shared_ptr<Album> album;
    std::vector<std::shared_ptr<Persoana>> echipaTehnica;
    int costConcert = 0;
    static const int PRET_BILET = 100;
public:
    Concert();
    Concert(int succes, const std::shared_ptr<Oras>& locatie, const std::shared_ptr<Album>& album);
    ~Concert() override;

    int crestePopularitatea(int popularitate) const;
    void calculeazaSucces(float raportPrezenta, int contributieTehnician, int contributieBodyguard);
    float calculeazaNrSpectatori();
    void angajeazaPersonal(const std::shared_ptr<Persoana>& p);
    int calculeazaCosturi() override;
    void desfasoaraActivitate() override;
    int profit() const ;
    static int getNrConcerte();

    friend std::ostream& operator<<(std::ostream& out, const Concert& c);
};

#endif