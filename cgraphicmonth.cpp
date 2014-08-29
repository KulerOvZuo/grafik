#include "cgraphicmonth.h"
#include <qdebug.h>
#include <QFont>
#include <QPalette>
#include <QMenuBar>
#include <QDialog>
#include "constants.h"

CGraphicMonth::CGraphicMonth(CMonth* _miesiac, QWidget *parent) :
    QWidget(parent)
{    
    miesiacComboBOx = new QComboBox;
    kalendarzWidget = NULL;
    miesiac=_miesiac;

    pomoc = new QAction(QString("Pomoc"),this);
    connect(pomoc,SIGNAL(triggered()),this,SLOT(pokazPomoc()));
    QMenuBar* menu = new QMenuBar;
    menu->addAction(pomoc);
    menu->setFixedHeight(30);

    QFont font;
    font.setPointSize(mainFontSize);
    QLabel* miesiacLabel = new QLabel(QString("Miesiąc: "));
    miesiacLabel->setFont(font);
    for(int i=0; i<12;i++)
    {   miesiacComboBOx->addItem(QDate::longMonthName(i+1));
        miesiacComboBOx->setFont(font);
    }

    QLabel* rokLabel = new QLabel(QString("Rok: "));
    rokLabel->setFont(font);
    yearEdit = new QDateTimeEdit;
    yearEdit->setDisplayFormat("yyyy");
    yearEdit->setDateRange(QDate(1900,1,1),QDate(2200,1,1));
    yearEdit->setFont(font);

    miesiacComboBOx->setCurrentIndex(miesiac->getWybranaData().month()-1);
    yearEdit->setDate(miesiac->getWybranaData());

    connect(miesiacComboBOx,SIGNAL(activated(int)),this,SLOT(setMiesiac(int)));
    connect(yearEdit,SIGNAL(dateChanged(QDate)),this,SLOT(setRok(QDate)));

    QHBoxLayout *controlLayout = new QHBoxLayout;
    controlLayout->addWidget(miesiacLabel);
    controlLayout->addWidget(miesiacComboBOx);
    controlLayout->addSpacing(15);
    controlLayout->addWidget(rokLabel);
    controlLayout->addWidget(yearEdit);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(menu);
    mainLayout->addLayout(controlLayout);
    wstawKalendarz();
    this->setLayout(mainLayout);
    this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::Dialog);
    this->setWindowTitle(QString("Kalendarz."));
}

void CGraphicMonth::wstawKalendarz()
{
    //mainLayout->removeWidget(kalendarzWidget);
    QGridLayout* kalendarz = new QGridLayout;
    kalendarz->setColumnStretch(7,1);
    for(int i=0;i<7;i++)
    {   QLabel* label = new QLabel(QString("%1").arg(QDate::shortDayName(i+1),1,1));
        QFont font;
        font.setPointSize(mainFontSize);
        font.setBold(true);
        label->setAlignment(Qt::AlignCenter);
        label->setFont(font);
        label->setFixedHeight(30);
        if(i==5 || i==6)
            label->setStyleSheet("*{background-color: rgb(253,95,9,220)}");
        kalendarz->addWidget(label,0,i);
    }
    int row =1;
    QDate tempData = miesiac->getWybranaData();
    for(int i=0;i<miesiac->getIloscDniMiesiaca();i++)
    {   CGraphicButton* cell = new CGraphicButton;
        connect(cell,SIGNAL(dzienZmieniony(int,bool)),this,SLOT(dzienZmieniony(int, bool)));
        cell->setText(QString("%1").arg(i+1,1));
        cell->setFixedSize(50,30);
        QFont font;
        font.setPointSize(mainFontSize);
       // font.setBold(true);
        cell->setFont(font);
        if((miesiac->getTabliceMiesiaca())[1][i]==1)
            cell->getSwiateczny()=true;
        kalendarz->addWidget(cell,row,tempData.dayOfWeek()-1);
        if(tempData.dayOfWeek()==7)
            row++;
        tempData = tempData.addDays(1);
    }
    if(kalendarzWidget!=NULL)
        delete kalendarzWidget;
    kalendarzWidget = new QWidget;
    kalendarzWidget->setLayout(kalendarz);
    QPalette pal(palette());
    pal.setColor(QPalette::Background,mainColor);
    kalendarzWidget->setPalette(pal);
    kalendarzWidget->setAutoFillBackground(true);
    mainLayout->addWidget(kalendarzWidget);
}
void CGraphicMonth::setMiesiac(int _miesiac)
{   miesiac->setMiesiac(_miesiac+1);
    miesiac->wyznaczTabliceMiesiaca();
    this->wstawKalendarz();
}
void CGraphicMonth::setRok(QDate _rok)
{   miesiac->setRok(_rok.year());
    miesiac->wyznaczTabliceMiesiaca();
    this->wstawKalendarz();
}
void CGraphicMonth::dzienZmieniony(int _dzien, bool _swieto)
{   if(_dzien>=1 && _dzien<=miesiac->getIloscDniMiesiaca())
        (miesiac->getTabliceMiesiaca())[1][_dzien-1]=_swieto;
}
void CGraphicMonth::pokazPomoc()
{   QFont font;
    font.setPointSize(mainFontSize+1);
    QLabel* pomocLabel = new QLabel(QString("Kalendarz pozwala na wyswietlanie oraz zmianę aktualnego miesiaca.\nPozwala również na dodawanie/usuwanie dni świątecznych poprzez kliknięcie w dany dzień."),this);
    pomocLabel->setFont(font);
    pomocLabel->setWindowTitle(QString("Pomoc kalendarza."));
    pomocLabel->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::Dialog);
    pomocLabel->show();
}
