#include "cmonth.h"
#include <qdebug.h>

CMonth::CMonth()
{
    miesiac=NULL;
}
void CMonth::wyznaczTabliceMiesiaca()
{
    /*if(miesiac!=NULL)
    {   for(int x=0;x<1;x++)
            delete[] miesiac[x];
        delete[] miesiac;
    }*/
    QDate tempDate;
    tempDate = wybranaData;
    //Wyznaczanie ilosci dni w miesiacu
    iloscDni=0;
    while(tempDate.month() == wybranaData.month())
    {   iloscDni++;
        tempDate = tempDate.addDays(1);
    }
    tempDate = wybranaData;
    double** tempMiesiac = new double*[2];
    for(int x=0;x<2;x++)
    {   tempMiesiac[x] = new double[iloscDni];}
    for(int i=0; i<iloscDni; i++)
    {   tempMiesiac[0][i]=tempDate.dayOfWeek();
        if(tempMiesiac[0][i]==6 || tempMiesiac[0][i]==7)
            tempMiesiac[1][i]=1;
        else
            tempMiesiac[1][i]=0;
        tempDate = tempDate.addDays(1);}
    miesiac=tempMiesiac;
}


double** CMonth::getTabliceMiesiaca()
{   return miesiac;}
int CMonth::getIloscDniMiesiaca()
{   return iloscDni;}
QDate CMonth::getWybranaData()
{   return wybranaData; }
bool CMonth::setMiesiac(int _miesiac)
{   if(_miesiac<1 || _miesiac >12)
        return false;
    wybranaData.setDate(wybranaData.year(),_miesiac,1);
    return true;
}
bool CMonth::setRok(int _rok)
{   if(_rok<1500 ||_rok >2200)
        return false;
    wybranaData.setDate(_rok,wybranaData.month(),1);
    return true;
}
bool CMonth::setMiesiacRok(int _rok, int _miesiac)
{   if(_rok<1500 ||_rok >2200 || _miesiac<1 || _miesiac >12)
        return false;
    wybranaData.setDate(_rok,_miesiac,1);
    return true;
}
