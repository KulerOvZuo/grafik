#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QScrollArea>
#include "cperson.h"
#include "cmonth.h"
#include "cmodel.h"
#include "cgraphicmonth.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    CMonth* miesiac;
    CGraphicMonth* kalendarzWidget;

    QMenu* menuProgramu;
    QMenu* menuOsob;
        QAction* addPersonAct;
        QAction* removePersonAct;
        QAction* changePersonAct;
    QMenu* menuOpcji;
        QAction* daysIndicatorsAct;
        QAction* othersAct;

    QScrollArea* peopleScrollArea;
    QScrollArea* monthPreferencesScrollArea;
    QScrollArea* chartScrollArea;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createMenus();
private slots:
    void addPerson();
    void removePerson();
    void changePerson();
    void daysIndicators();
    void others();
};

#endif // MAINWINDOW_H
