#include "cperson.h"

CPerson::CPerson()
{
    preferencjeMiesiaca = NULL;
    preferencjeTygodniowe = new double[7];
}
CPerson::~CPerson()
{
    delete[] preferencjeTygodniowe;
}
int& CPerson::getNumer()
{   return numer;}
QString& CPerson::getImie()
{   return imie;}
int& CPerson::getIloscDyzurow()
{   return iloscDyzurow;}
int& CPerson::getIloscDyzurowSwiatecznych()
{   return iloscDyzurowSwiatecznych;}
double* CPerson::getPreferencjeTygodniowe()
{   return preferencjeTygodniowe;}
double* CPerson::getPreferencjeMiesiaca()
{   return preferencjeMiesiaca;}
