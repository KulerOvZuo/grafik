#ifndef CMONTH_H
#define CMONTH_H

#include <QDate>
/**
 * @brief The CMonth class
 *
 *Model miesiąca. Służy do poprawnego odczytania jak wyglada aktualny miesiąc.
 */
class CMonth
{
protected:
    //2 wymiarowa tablica 1-n określająca dzien tygodnia oraz ilość dni miesiaca;
    double** miesiac;
    int iloscDni;
    QDate wybranaData;
public:
    CMonth();

    void wyznaczTabliceMiesiaca();
    double** getTabliceMiesiaca();
    int getIloscDniMiesiaca();
    QDate getWybranaData();
    bool setMiesiac(int _miesiac);
    bool setRok(int _rok);
    bool setMiesiacRok(int _rok, int _miesiac);
};

#endif // CMONTH_H
