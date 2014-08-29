#ifndef CPERSON_H
#define CPERSON_H

#include <QString>

class CPerson
{
protected:
    int numer;
    QString imie;
    int iloscDyzurow;
    int iloscDyzurowSwiatecznych;
    double* preferencjeTygodniowe;
    double* preferencjeMiesiaca;
public:
    CPerson();
    virtual~CPerson();

    int& getNumer();
    QString& getImie();
    int& getIloscDyzurow();
    int& getIloscDyzurowSwiatecznych();
    double* getPreferencjeTygodniowe();
    double* getPreferencjeMiesiaca();
};

#endif // CPERSON_H
