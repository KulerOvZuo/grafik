#ifndef CMODEL_H
#define CMODEL_H

#include "constants.h"
#include "cperson.h"
#include <QVector>
#include "cmonth.h"

class CModel
{ 
protected:
    QVector<CPerson*> listaOsob;
    CMonth* miesiac;
    int iloscDni;
    double** tablicaMiesiaca;
public:
    CModel();


    void generujGrafik();
    bool dodajOsobe(CPerson* _osoba);
    bool usunOsobe(CPerson*_osoba);
    bool usunOsobe(int _osoba);
    void edytujOsobe(CPerson*_osoba);
    void edytujOsobe(int _osoba);
};

#endif // CMODEL_H
