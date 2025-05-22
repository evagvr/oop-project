#ifndef ACTIVITATE_H
#define ACTIVITATE_H

class Activitate{
protected:
    int succes;
public:
    Activitate();
    Activitate(int succes);
    virtual ~Activitate();

    virtual int calculeazaCosturi() = 0;
    virtual void desfasoaraActivitate() = 0;
};

#endif