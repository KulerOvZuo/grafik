#ifndef CGRAPHICMONTH_H
#define CGRAPHICMONTH_H

#include <QWidget>
#include <QSpinBox>
#include <QComboBox>
#include <QLabel>
#include <QDateTimeEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include "cgraphicbutton.h"
#include "cmonth.h"

class CGraphicMonth : public QWidget
{
    Q_OBJECT
protected:
    QVBoxLayout* mainLayout;
    QWidget* kalendarzWidget;
    QDateTimeEdit *yearEdit;
    QComboBox* miesiacComboBOx;
    CMonth* miesiac;
    QAction* pomoc;
public:
    explicit CGraphicMonth(CMonth* _miesiac, QWidget *parent = 0);
    void wstawKalendarz();

signals:
    void changed(int,int);

public slots:
    void setMiesiac(int);
    void setRok(QDate);
    void dzienZmieniony(int, bool);
    void pokazPomoc();
};
#endif // CGRAPHICMONTH_H
