#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createMenus();

    miesiac = new CMonth;
    QDate date;
    miesiac->setMiesiacRok(date.currentDate().year(),(date.currentDate().month())%11+1);
    miesiac->wyznaczTabliceMiesiaca();

    kalendarzWidget = new CGraphicMonth(miesiac,this);
    kalendarzWidget->show();

    statusBar()->showMessage(QString("Witaj."));
}
MainWindow::~MainWindow()
{}
void MainWindow::createMenus()
{
    addPersonAct = new QAction(QString("Dodaj osobę."),this);
    addPersonAct->setStatusTip(QString("Dodaje nową osobę do listy osób."));
    connect(addPersonAct,SIGNAL(triggered()),this,SLOT(addPerson()));

    removePersonAct = new QAction(QString("Usuń osobę."),this);
    removePersonAct->setStatusTip(QString("Usuwa daną osobę z listy."));
    connect(removePersonAct,SIGNAL(triggered()),this,SLOT(removePerson()));

    changePersonAct = new QAction(QString("Zmień preferencje osoby."),this);
    changePersonAct->setStatusTip(QString("Pozwala na zmianę preferencji stałych danej osoby."));
    connect(changePersonAct,SIGNAL(triggered()),this,SLOT(changePerson()));

    daysIndicatorsAct = new QAction(QString("Zmień współczynniki."),this);
    daysIndicatorsAct->setStatusTip(QString("Pozwala na zmianę wielkości współczynników, z których korzysta program."));
    connect(daysIndicatorsAct,SIGNAL(triggered()),this,SLOT(daysIndicators()));

    othersAct = new QAction(QString("Ogólne."),this);
    othersAct->setStatusTip(QString("Ogólne opcje."));
    connect(othersAct,SIGNAL(triggered()),this,SLOT(others()));

    menuProgramu = menuBar()->addMenu(QString("Program"));
    menuOsob = menuBar()->addMenu(QString("Edytor osób"));
        menuOsob->addAction(addPersonAct);
        menuOsob->addAction(removePersonAct);
        menuOsob->addAction(changePersonAct);
    menuOpcji = menuBar()->addMenu(QString("Opcje"));
        menuOpcji->addAction(othersAct);
        menuOpcji->addSeparator();
        menuOpcji->addAction(daysIndicatorsAct);
}
void MainWindow::addPerson()
{}
void MainWindow::removePerson()
{}
void MainWindow::changePerson()
{}
void MainWindow::daysIndicators()
{}
void MainWindow::others()
{}
